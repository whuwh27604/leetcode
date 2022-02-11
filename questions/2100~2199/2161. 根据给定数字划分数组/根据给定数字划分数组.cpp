/* 根据给定数字划分数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 和一个整数 pivot 。请你将 nums 重新排列，使得以下条件均成立：

所有小于 pivot 的元素都出现在所有大于 pivot 的元素 之前 。
所有等于 pivot 的元素都出现在小于和大于 pivot 的元素 中间 。
小于 pivot 的元素之间和大于 pivot 的元素之间的 相对顺序 不发生改变。
更正式的，考虑每一对 pi，pj ，pi 是初始时位置 i 元素的新位置，pj 是初始时位置 j 元素的新位置。对于小于 pivot 的元素，如果 i < j 且 nums[i] < pivot 和 nums[j] < pivot 都成立，那么 pi < pj 也成立。类似的，对于大于 pivot 的元素，如果 i < j 且 nums[i] > pivot 和 nums[j] > pivot 都成立，那么 pi < pj 。
请你返回重新排列 nums 数组后的结果数组。

 

示例 1：

输入：nums = [9,12,5,10,14,3,10], pivot = 10
输出：[9,5,3,10,10,12,14]
解释：
元素 9 ，5 和 3 小于 pivot ，所以它们在数组的最左边。
元素 12 和 14 大于 pivot ，所以它们在数组的最右边。
小于 pivot 的元素的相对位置和大于 pivot 的元素的相对位置分别为 [9, 5, 3] 和 [12, 14] ，它们在结果数组中的相对顺序需要保留。
示例 2：

输入：nums = [-3,4,3,2], pivot = 2
输出：[-3,2,4,3]
解释：
元素 -3 小于 pivot ，所以在数组的最左边。
元素 4 和 3 大于 pivot ，所以它们在数组的最右边。
小于 pivot 的元素的相对位置和大于 pivot 的元素的相对位置分别为 [-3] 和 [4, 3] ，它们在结果数组中的相对顺序需要保留。
 

提示：

1 <= nums.length <= 105
-106 <= nums[i] <= 106
pivot 等于 nums 中的一个元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-array-according-to-given-pivot
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int i = 0, size = nums.size(), count = 0;
        vector<int> arr(size);

        for (int num : nums) {
            if (num < pivot) {
                arr[i++] = num;
            }
            else if (num == pivot) {
                ++count;
            }
        }

        for (int j = 0; j < count; ++j) {
            arr[i++] = pivot;
        }

        for (int num : nums) {
            if (num > pivot) {
                arr[i++] = num;
            }
        }

        return arr;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 9,12,5,10,14,3,10 };
    vector<int> actual = o.pivotArray(nums, 10);
    vector<int> expected = { 9,5,3,10,10,12,14 };
    check.checkIntVector(expected, actual);

    nums = { -3,4,3,2 };
    actual = o.pivotArray(nums, 2);
    expected = { -3,2,4,3 };
    check.checkIntVector(expected, actual);

    nums = { 2 };
    actual = o.pivotArray(nums, 2);
    expected = { 2 };
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
