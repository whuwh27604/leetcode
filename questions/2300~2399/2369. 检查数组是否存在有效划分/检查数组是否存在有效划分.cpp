/* 检查数组是否存在有效划分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums ，你必须将数组划分为一个或多个 连续 子数组。

如果获得的这些子数组中每个都能满足下述条件 之一 ，则可以称其为数组的一种 有效 划分：

子数组 恰 由 2 个相等元素组成，例如，子数组 [2,2] 。
子数组 恰 由 3 个相等元素组成，例如，子数组 [4,4,4] 。
子数组 恰 由 3 个连续递增元素组成，并且相邻元素之间的差值为 1 。例如，子数组 [3,4,5] ，但是子数组 [1,3,5] 不符合要求。
如果数组 至少 存在一种有效划分，返回 true ，否则，返回 false 。

 

示例 1：

输入：nums = [4,4,4,5,6]
输出：true
解释：数组可以划分成子数组 [4,4] 和 [4,5,6] 。
这是一种有效划分，所以返回 true 。
示例 2：

输入：nums = [1,1,1,2]
输出：false
解释：该数组不存在有效划分。
 

提示：

2 <= nums.length <= 105
1 <= nums[i] <= 106

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/check-if-there-is-a-valid-partition-for-the-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int size = nums.size();
        vector<bool> valids(size + 1, false);
        valids[size] = true;

        for (int i = size - 2; i >= 0; --i) {
            if (nums[i] == nums[i + 1]) {
                valids[i] = valids[i + 2];
            }

            if (i < size - 2 && nums[i] == nums[i + 1] && nums[i] == nums[i + 2]) {
                valids[i] = (valids[i] || valids[i + 3]);
            }

            if (i < size - 2 && nums[i] == nums[i + 1] - 1 && nums[i] == nums[i + 2] - 2) {
                valids[i] = (valids[i] || valids[i + 3]);
            }
        }

        return valids[0];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 4,4,4,5,6 };
    check.checkBool(true, o.validPartition(nums));

    nums = { 1,1,1,2,3,4 };
    check.checkBool(true, o.validPartition(nums));

    nums = { 1,1,1,2,3,4,5,5 };
    check.checkBool(true, o.validPartition(nums));

    nums = { 6,6,6,6,7,8,9,9,10,11 };
    check.checkBool(true, o.validPartition(nums));

    nums = { 26,1,2,3 };
    check.checkBool(false, o.validPartition(nums));

    nums = { 22,22,22,23,24,25,1,2,3,4,5,6,7 };
    check.checkBool(false, o.validPartition(nums));

    nums = { 1,2,3,4 };
    check.checkBool(false, o.validPartition(nums));

    nums = { 1,1,1,2 };
    check.checkBool(false, o.validPartition(nums));
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
