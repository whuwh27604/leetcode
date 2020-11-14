/* 两个数组的交集 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
说明：

输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
我们可以不考虑输出结果的顺序。
进阶:

如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小很多，哪种方法更优？
如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-arrays-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty()) {
            vector<int> tmp;
            return tmp;
        }

        vector<int> sortedTmp1(nums1.size(), 0);
        merge_sort(nums1, 0, (nums1.size() - 1), sortedTmp1);
        vector<int> sortedTmp2(nums2.size(), 0);
        merge_sort(nums2, 0, (nums2.size() - 1), sortedTmp2);

        return intersectionNums(nums1, nums2);
    }

    void merge_sort(vector<int>& nums, int left, int right, vector<int>& sortedTmp) {
        if (left < right) {
            int middle = ((left + right) / 2);
            // 左右分别排序
            merge_sort(nums, left, middle, sortedTmp);
            merge_sort(nums, middle + 1, right, sortedTmp);
            // 将已排序的左右合并
            merge(nums, left, middle, right, sortedTmp);
        }
    }

    void merge(vector<int>& nums, int left, int middle, int right, vector<int>& sortedTmp) {
        int leftIndex = left;
        int rightIndex = (middle + 1);
        int sortedIndex = 0;
        // 按顺序取小的数放入sortedTmp
        while ((leftIndex <= middle) && (rightIndex <= right)) {
            if (nums[leftIndex] <= nums[rightIndex]) {
                sortedTmp[sortedIndex++] = nums[leftIndex++];
            }
            else {
                sortedTmp[sortedIndex++] = nums[rightIndex++];
            }
        }

        // 剩下的数放入sortedTmp
        while (leftIndex <= middle) {
            sortedTmp[sortedIndex++] = nums[leftIndex++];
        }

        while (rightIndex <= right) {
            sortedTmp[sortedIndex++] = nums[rightIndex++];
        }

        // 本次排序结果写入nums
        sortedIndex = 0;
        leftIndex = left;
        rightIndex = right;
        while (leftIndex <= rightIndex) {
            nums[leftIndex++] = sortedTmp[sortedIndex++];
        }
    }

    vector<int> intersectionNums(vector<int>& sorted_nums1, vector<int>& sorted_nums2) {
        vector<int> nums;
        unsigned int index1 = 0, index2 = 0;
        while ((index1 < sorted_nums1.size()) && (index2 < sorted_nums2.size())) {
            int num1 = sorted_nums1[index1];
            int num2 = sorted_nums2[index2];
            if (num1 == num2) {
                nums.push_back(num1);
                index1++;
                index2++;
            }
            else if (num1 < num2) {
                index1++;
            }
            else {
                index2++;
            }
        }
        return nums;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums1 = { 4,9,5 };
    vector<int> nums2 = { 9,4,9,8,4 };
    vector<int> actual = o.intersect(nums1, nums2);
    vector<int> expected = { 4,9 };
    check.checkIntVector(expected, actual);

    nums1 = { 1,2,2,1 };
    nums2 = { 2,2 };
    actual = o.intersect(nums1, nums2);
    expected = { 2,2 };
    check.checkIntVector(expected, actual);

    nums1 = {  };
    nums2 = { 2,2 };
    actual = o.intersect(nums1, nums2);
    expected = {  };
    check.checkIntVector(expected, actual);

    nums1 = { 1 };
    nums2 = { 2 };
    actual = o.intersect(nums1, nums2);
    expected = {  };
    check.checkIntVector(expected, actual);

    nums1 = { 1 };
    nums2 = { 1,1,1 };
    actual = o.intersect(nums1, nums2);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    nums1 = { 1,1,1,1 };
    nums2 = { 1,1,1 };
    actual = o.intersect(nums1, nums2);
    expected = { 1,1,1 };
    check.checkIntVector(expected, actual);

    nums1 = { 1,2,3,4,5 };
    nums2 = { 1,2,3,4,5 };
    actual = o.intersect(nums1, nums2);
    expected = { 1,2,3,4,5 };
    check.checkIntVector(expected, actual);

    nums1 = { 6,6,6,5,5,5,4,4,4,3,3,3,2,2,2,1,1,1 };
    nums2 = { 1,1,2,2,2,2,3,3,4,4,4,4,5,5,6,6,6,6 };
    actual = o.intersect(nums1, nums2);
    expected = { 1,1,2,2,2,3,3,4,4,4,5,5,6,6,6 };
    check.checkIntVector(expected, actual);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
