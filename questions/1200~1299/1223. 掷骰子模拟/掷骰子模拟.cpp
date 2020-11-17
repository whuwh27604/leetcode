/* 掷骰子模拟.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个骰子模拟器会每次投掷的时候生成一个 1 到 6 的随机数。

不过我们在使用它时有个约束，就是使得投掷骰子时，连续 掷出数字 i 的次数不能超过 rollMax[i]（i 从 1 开始编号）。

现在，给你一个整数数组 rollMax 和一个整数 n，请你来计算掷 n 次骰子可得到的不同点数序列的数量。

假如两个序列中至少存在一个元素不同，就认为这两个序列是不同的。由于答案可能很大，所以请返回 模 10^9 + 7 之后的结果。

 

示例 1：

输入：n = 2, rollMax = [1,1,2,2,2,3]
输出：34
解释：我们掷 2 次骰子，如果没有约束的话，共有 6 * 6 = 36 种可能的组合。但是根据 rollMax 数组，数字 1 和 2 最多连续出现一次，所以不会出现序列 (1,1) 和 (2,2)。因此，最终答案是 36-2 = 34。
示例 2：

输入：n = 2, rollMax = [1,1,1,1,1,1]
输出：30
示例 3：

输入：n = 3, rollMax = [1,1,1,2,2,3]
输出：181
 

提示：

1 <= n <= 5000
rollMax.length == 6
1 <= rollMax[i] <= 15

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/dice-roll-simulation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        // 令dp[point][consecutive]表示在某一轮数字point[1,6]连续出现consecutive[1,15]次的次数，需要递推n轮得到最终的结果
        vector<vector<long long>> dp(6, vector<long long>(15, 0));
        init(dp);

        int point, consecutive, round, mod = 1000000007;

        for (round = 1; round < n; ++round) {
            long long allSum = getDpSum(dp);
            vector<vector<long long>> tmp(6, vector<long long>(15, 0));

            for (point = 0; point < 6; ++point) {
                long long sum = dp[point][0];

                for (consecutive = 1; consecutive < rollMax[point]; ++consecutive) {
                    // 本轮，连续consecutive个point的次数等于上一轮连续consecutive-1个point的次数。如果已经到达最大值，则不可能再投出point，所以次数是0
                    tmp[point][consecutive] = dp[point][consecutive - 1];
                    sum += dp[point][consecutive];
                }

                tmp[point][0] = (allSum - sum) % mod;  // 连续1个point的次数等于上一轮所有不是point结尾的序列次数
            }

            dp = tmp;
        }

        return (int)(getDpSum(dp) % mod);
    }

    void init(vector<vector<long long>>& dp) {
        for (int point = 0; point < 6; ++point) {
            dp[point][0] = 1;  // 第一轮，可能投出1~6各一个
        }
    }

    long long getDpSum(vector<vector<long long>>& dp) {
        long long allSum = 0;

        for (vector<long long>& points : dp) {
            for (long long num : points) {
                allSum += num;
            }
        }

        return allSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> rollMax = { 1,1,2,2,2,3 };
    check.checkInt(34, o.dieSimulator(2, rollMax));

    rollMax = { 1,1,1,1,1,1 };
    check.checkInt(30, o.dieSimulator(2, rollMax));

    rollMax = { 1,1,1,2,2,3 };
    check.checkInt(181, o.dieSimulator(3, rollMax));

    rollMax = { 1,1,1,2,2,3 };
    check.checkInt(6, o.dieSimulator(1, rollMax));
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
