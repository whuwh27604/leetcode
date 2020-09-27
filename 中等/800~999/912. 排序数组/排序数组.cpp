/* 排序数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums，请你将该数组升序排列。

 

示例 1：

输入：nums = [5,2,3,1]
输出：[1,2,3,5]
示例 2：

输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]
 

提示：

1 <= nums.length <= 50000
-50000 <= nums[i] <= 50000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);

        return nums;
    }

    void quickSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int position = partition(nums, left, right);
            quickSort(nums, left, position - 1);
            quickSort(nums, position + 1, right);
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        int i = left, j = left, pivot = nums[right];  // 在[left,right]之间随机选取一个pivot，这里固定选right

        for (; j < right; ++j) {
            if (nums[j] <= pivot) {
                swap(nums[i++], nums[j]);  // 所有小于pivot的数换到前面，大于pivot的数换到后面
            }
        }

        swap(nums[i], nums[right]);  // 把pivot换回中间的位置

        return i;  // 返回pivot的位置
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 5,2,3,1 };
    vector<int> actual = o.sortArray(nums);
    vector<int> expected = { 1,2,3,5 };
    check.checkIntVector(expected, actual);

    nums = { 5,1,1,2,0,0 };
    actual = o.sortArray(nums);
    expected = { 0,0,1,1,2,5 };
    check.checkIntVector(expected, actual);

    nums = { 5 };
    actual = o.sortArray(nums);
    expected = { 5 };
    check.checkIntVector(expected, actual);

    nums = { 5,0 };
    actual = o.sortArray(nums);
    expected = { 0,5 };
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
