/* 合并两个有序数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 num1 成为一个有序数组。

 

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 

示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> mergeNums(m + n);
        int i = 0;
        int j = 0;
        int mergeIndex = 0;
        while ((i < m) && (j < n)) {
            if (nums1[i] < nums2[j]) {
                mergeNums[mergeIndex++] = nums1[i++];
            }
            else if (nums1[i] == nums2[j]) {
                mergeNums[mergeIndex++] = nums1[i++];
                mergeNums[mergeIndex++] = nums2[j++];
            }
            else {
                mergeNums[mergeIndex++] = nums2[j++];
            }
        }

        if (i == m) {
            while (j < n) {
                mergeNums[mergeIndex++] = nums2[j++];
            }
        }

        if (j == n) {
            while (i < m) {
                mergeNums[mergeIndex++] = nums1[i++];
            }
        }

        nums1 = mergeNums;
    }
};

int main()
{
    Solution o;
    CheckResult result;

    vector<int> nums1 = { 1,2,3,0,0,0 };
    vector<int> nums2 = { 2,5,6 };
    vector<int> expected = { 1,2,2,3,5,6 };
    o.merge(nums1, 3, nums2, 3);
    result.checkIntVector(expected, nums1);

    nums1 = { 1,2,3,0,0,0 };
    nums2 = { 2,5 };
    expected = { 1,2,2,3,5 };
    o.merge(nums1, 3, nums2, 2);
    result.checkIntVector(expected, nums1);

    nums1 = { 1,2,7,0,0,0,0,0 };
    nums2 = { 2,3,5,6,7 };
    expected = { 1,2,2,3,5,6,7,7 };
    o.merge(nums1, 3, nums2, 5);
    result.checkIntVector(expected, nums1);

    nums1 = { 0,0,0 };
    nums2 = { 0 };
    expected = { 0,0 };
    o.merge(nums1, 1, nums2, 1);
    result.checkIntVector(expected, nums1);

    nums1 = { 0,0,0 };
    nums2 = { 1 };
    expected = { 0,1 };
    o.merge(nums1, 1, nums2, 1);
    result.checkIntVector(expected, nums1);

    nums1 = { 1,0 };
    nums2 = { 0 };
    expected = { 0,1 };
    o.merge(nums1, 1, nums2, 1);
    result.checkIntVector(expected, nums1);

    nums1 = {  };
    nums2 = {  };
    expected = {  };
    o.merge(nums1, 0, nums2, 0);
    result.checkIntVector(expected, nums1);
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
