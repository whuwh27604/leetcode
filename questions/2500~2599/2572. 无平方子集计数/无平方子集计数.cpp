﻿/* 无平方子集计数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数数组 nums 。

如果数组 nums 的子集中的元素乘积是一个 无平方因子数 ，则认为该子集是一个 无平方 子集。

无平方因子数 是无法被除 1 之外任何平方数整除的数字。

返回数组 nums 中 无平方 且 非空 的子集数目。因为答案可能很大，返回对 109 + 7 取余的结果。

nums 的 非空子集 是可以由删除 nums 中一些元素（可以不删除，但不能全部删除）得到的一个数组。如果构成两个子集时选择删除的下标不同，则认为这两个子集不同。



示例 1：

输入：nums = [3,4,4,5]
输出：3
解释：示例中有 3 个无平方子集：
- 由第 0 个元素 [3] 组成的子集。其元素的乘积是 3 ，这是一个无平方因子数。
- 由第 3 个元素 [5] 组成的子集。其元素的乘积是 5 ，这是一个无平方因子数。
- 由第 0 个和第 3 个元素 [3,5] 组成的子集。其元素的乘积是 15 ，这是一个无平方因子数。
可以证明给定数组中不存在超过 3 个无平方子集。
示例 2：

输入：nums = [1]
输出：1
解释：示例中有 1 个无平方子集：
- 由第 0 个元素 [1] 组成的子集。其元素的乘积是 1 ，这是一个无平方因子数。
可以证明给定数组中不存在超过 1 个无平方子集。


提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 30
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        vector<int> primes = { 2,3,5,7,11,13,17,19,23,29 };
        int size = primes.size(), maxSet = 1 << size, mod = 1000000007, oneSets = 1, ans = 0;
        vector<int> indexSets(31, -1);
        vector<int> dp(maxSet, 0);
        dp[0] = 1;

        getIndexSets(primes, indexSets);

        for (int num : nums) {
            if (num == 1) {
                oneSets = oneSets * 2 % mod;  // 只由1构成的集合个数，包含空集
            }
            else {
                int indexSet = indexSets[num];
                if (indexSet != -1) {
                    for (int set = maxSet - 1; set >= 0; --set) {
                        if ((set & indexSet) == 0) {  // 没有交集，那么它们合并可以构成一个合法集合
                            dp[set | indexSet] = (dp[set | indexSet] + dp[set]) % mod;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < maxSet; ++i) {
            ans = (ans + (long long)dp[i] * oneSets) % mod;  // 每一个质数集合都可以和所有的纯1集合构成一个合法集合
        }

        return (ans + mod - 1) % mod;  // 最后要减去纯1空集
    }

    void getIndexSets(vector<int>& primes, vector<int>& indexSets) {
        int size = primes.size();

        for (int num = 2; num <= 30; ++num) {
            int set = 0, n = num;

            for (int i = 0, bit = 1; i < size; ++i, bit <<= 1) {
                if (n % primes[i] == 0) {
                    n /= primes[i];
                    set |= bit;
                }
            }

            if (n == 1) {
                indexSets[num] = set;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,4,4,5 };
    check.checkInt(3, o.squareFreeSubsets(nums));

    nums = { 1 };
    check.checkInt(1, o.squareFreeSubsets(nums));

    nums = { 1,1,1 };
    check.checkInt(7, o.squareFreeSubsets(nums));

    nums = { 2,1,1 };
    check.checkInt(7, o.squareFreeSubsets(nums));

    nums = { 1,2,3,1,2,3 };
    check.checkInt(35, o.squareFreeSubsets(nums));

    nums = { 1,1,3,4,4,5,30,29,28,27,26,25,24,23,23,22,21,20,19,19,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,1,1,3,4,4,5,30,29,28,27,26,25,24,23,23,22,21,20,19,19,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,1,1,3,4,4,5,30,29,28,27,26,25,24,23,23,22,21,20,19,19,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5 };
    check.checkInt(697876479, o.squareFreeSubsets(nums));

    nums = { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,14,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,19,21,21,21,21,21,21,21,21,21,21,21,22,22,22,22,22,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,26,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,29,30,30,30,30,30,30,30 };
    check.checkInt(1000000006, o.squareFreeSubsets(nums));
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
