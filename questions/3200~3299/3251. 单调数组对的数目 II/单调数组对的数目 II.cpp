/* 单调数组对的数目 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的 正 整数数组 nums 。

如果两个 非负 整数数组 (arr1, arr2) 满足以下条件，我们称它们是 单调 数组对：

两个数组的长度都是 n 。
arr1 是单调 非递减 的，换句话说 arr1[0] <= arr1[1] <= ... <= arr1[n - 1] 。
arr2 是单调 非递增 的，换句话说 arr2[0] >= arr2[1] >= ... >= arr2[n - 1] 。
对于所有的 0 <= i <= n - 1 都有 arr1[i] + arr2[i] == nums[i] 。
请你返回所有 单调 数组对的数目。

由于答案可能很大，请你将它对 109 + 7 取余 后返回。



示例 1：

输入：nums = [2,3,2]

输出：4

解释：

单调数组对包括：

([0, 1, 1], [2, 2, 1])
([0, 1, 2], [2, 2, 0])
([0, 2, 2], [2, 1, 0])
([1, 2, 2], [1, 1, 0])
示例 2：

输入：nums = [5,5,5,5]

输出：126



提示：

1 <= n == nums.length <= 2000
1 <= nums[i] <= 1000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int size = (int)nums.size(), pairs = 0, mod = 1000000007;
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> dp(maxNum + 1, 0);  // dp[i][n]表示nums[0, i]，arr1[i] = n的方法数

        for (int n = 0; n <= nums[0]; ++n) {
            dp[n] = 1;
        }

        for (int i = 1; i < size; ++i) {
            int num = nums[i], diff = nums[i - 1] - num, prev = 0, dpSum = 0;
            vector<int> tmp(maxNum + 1, 0);

            for (int n = 0; n <= num; ++n) {
                while (prev <= min(diff + n, n)) {
                    dpSum = (dpSum + dp[prev++]) % mod;
                }
                tmp[n] = dpSum;
            }

            dp = tmp;
        }

        for (int n = 0; n <= nums.back(); ++n) {
            pairs = (pairs + dp[n]) % mod;
        }

        return pairs;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 2,3,2 };
    check.checkInt(4, o.countOfPairs(nums));

    nums = { 5,5,5,5 };
    check.checkInt(126, o.countOfPairs(nums));
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
