/* 美丽子集的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由正整数组成的数组 nums 和一个 正 整数 k 。

如果 nums 的子集中，任意两个整数的绝对差均不等于 k ，则认为该子数组是一个 美丽 子集。

返回数组 nums 中 非空 且 美丽 的子集数目。

nums 的子集定义为：可以经由 nums 删除某些元素（也可能不删除）得到的一个数组。只有在删除元素时选择的索引不同的情况下，两个子集才会被视作是不同的子集。



示例 1：

输入：nums = [2,4,6], k = 2
输出：4
解释：数组 nums 中的美丽子集有：[2], [4], [6], [2, 6] 。
可以证明数组 [2,4,6] 中只存在 4 个美丽子集。
示例 2：

输入：nums = [1], k = 1
输出：1
解释：数组 nums 中的美丽数组有：[1] 。
可以证明数组 [1] 中只存在 1 个美丽子集。


提示：

1 <= nums.length <= 20
1 <= nums[i], k <= 1000
*/

#include <iostream>
#include <unordered_map>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int beauties = 1;
        unordered_map<int, map<int, int>> groups;

        divide(nums, k, groups);

        for (auto& kv : groups) {
            beauties *= getbeauties(kv.second, k);
        }

        return beauties - 1;  // 最后要减去空集
    }

    void divide(vector<int>& nums, int k, unordered_map<int, map<int, int>>& groups) {
        for (int num : nums) {
            ++groups[num % k][num];
        }
    }

    int getbeauties(map<int, int>& numsCount, int k) {
        vector<pair<int, int>> nums = { {-2 * k, 0} };  // 放一个前缀
        for (auto& kv : numsCount) {
            nums.push_back({ kv.first,kv.second });
        }

        int size = nums.size();
        vector<int> dp0(size, 0), dp1(size, 0);
        dp1[0] = 1;  // 空集先算上

        for (int i = 1; i < size; ++i) {
            dp0[i] = dp0[i - 1] + dp1[i - 1];  // 不选nums[i]，那么前面所有方案都可以选
            dp1[i] = (nums[i].first - nums[i - 1].first == k ? dp0[i - 1] : dp0[i - 1] + dp1[i - 1]);  // 选择nums[i]，如果差为k，那么不能选包含nums[i - 1]的方案
            dp1[i] *= ((int)pow(2, nums[i].second) - 1);  // 选择nums[i]的情况下，根据nums[i]的个数计算总的方案数
        }

        return dp0[size - 1] + dp1[size - 1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1 };
    check.checkInt(1, o.beautifulSubsets(nums, 1));

    nums = { 2,4,6 };
    check.checkInt(4, o.beautifulSubsets(nums, 2));

    nums = { 10,4,5,7,2,1 };
    check.checkInt(23, o.beautifulSubsets(nums, 3));

    nums = { 20,14,22,1,4,11,21,19,29,25,12,18,9,15,23,6,27,16,26,5 };
    check.checkInt(155519, o.beautifulSubsets(nums, 13));

    nums = { 2,4,6,1,1,1 };
    check.checkInt(39, o.beautifulSubsets(nums, 2));

    nums = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
    check.checkInt(1048575, o.beautifulSubsets(nums, 2));

    nums = { 1,2,3,3 };
    check.checkInt(8, o.beautifulSubsets(nums, 1));

    nums = { 1,1,2,2,3,3 };
    check.checkInt(18, o.beautifulSubsets(nums, 1));

    nums = { 1,1,2,2,3,3,1,1,2,2,3,3,1,1,2,2,3,3,1,2 };
    check.checkInt(24447, o.beautifulSubsets(nums, 2));
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
