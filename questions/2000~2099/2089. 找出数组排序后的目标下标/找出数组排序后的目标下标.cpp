/* 找出数组排序后的目标下标.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 以及一个目标元素 target 。

目标下标 是一个满足 nums[i] == target 的下标 i 。

将 nums 按 非递减 顺序排序后，返回由 nums 中目标下标组成的列表。如果不存在目标下标，返回一个 空 列表。返回的列表必须按 递增 顺序排列。

 

示例 1：

输入：nums = [1,2,5,2,3], target = 2
输出：[1,2]
解释：排序后，nums 变为 [1,2,2,3,5] 。
满足 nums[i] == 2 的下标是 1 和 2 。
示例 2：

输入：nums = [1,2,5,2,3], target = 3
输出：[3]
解释：排序后，nums 变为 [1,2,2,3,5] 。
满足 nums[i] == 3 的下标是 3 。
示例 3：

输入：nums = [1,2,5,2,3], target = 5
输出：[4]
解释：排序后，nums 变为 [1,2,2,3,5] 。
满足 nums[i] == 5 的下标是 4 。
示例 4：

输入：nums = [1,2,5,2,3], target = 4
输出：[]
解释：nums 中不含值为 4 的元素。
 

提示：

1 <= nums.length <= 100
1 <= nums[i], target <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-target-indices-after-sorting-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int first = 0, count = 0;

        for (int num : nums) {
            if (num < target) {
                ++first;
            }
            else if (num == target) {
                ++count;
            }
        }

        vector<int> indices(count);

        for (int& index : indices) {
            index = first++;
        }

        return indices;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,5,2,3 };
    vector<int> actual = o.targetIndices(nums, 2);
    vector<int> expected = { 1,2 };
    check.checkIntVector(expected, actual);

    nums = { 1,2,5,2,3 };
    actual = o.targetIndices(nums, 3);
    expected = { 3 };
    check.checkIntVector(expected, actual);

    nums = { 1,2,5,2,3 };
    actual = o.targetIndices(nums, 5);
    expected = { 4 };
    check.checkIntVector(expected, actual);

    nums = { 1,2,5,2,3 };
    actual = o.targetIndices(nums, 4);
    expected = {  };
    check.checkIntVector(expected, actual);

    nums = { 1 };
    actual = o.targetIndices(nums, 4);
    expected = {  };
    check.checkIntVector(expected, actual);

    nums = { 1 };
    actual = o.targetIndices(nums, 1);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    nums = { 1,1,1,1,1 };
    actual = o.targetIndices(nums, 1);
    expected = { 0,1,2,3,4 };
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
