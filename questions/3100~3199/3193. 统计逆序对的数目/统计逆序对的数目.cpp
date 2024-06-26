/* 统计逆序对的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n 和一个二维数组 requirements ，其中 requirements[i] = [endi, cnti] 表示这个要求中的末尾下标和 逆序对 的数目。

整数数组 nums 中一个下标对 (i, j) 如果满足以下条件，那么它们被称为一个 逆序对 ：

i < j 且 nums[i] > nums[j]
请你返回 [0, 1, 2, ..., n - 1] 的
排列
 perm 的数目，满足对 所有 的 requirements[i] 都有 perm[0..endi] 恰好有 cnti 个逆序对。

由于答案可能会很大，将它对 109 + 7 取余 后返回。



示例 1：

输入：n = 3, requirements = [[2,2],[0,0]]

输出：2

解释：

两个排列为：

[2, 0, 1]
前缀 [2, 0, 1] 的逆序对为 (0, 1) 和 (0, 2) 。
前缀 [2] 的逆序对数目为 0 个。
[1, 2, 0]
前缀 [1, 2, 0] 的逆序对为 (0, 2) 和 (1, 2) 。
前缀 [1] 的逆序对数目为 0 个。
示例 2：

输入：n = 3, requirements = [[2,2],[1,1],[0,0]]

输出：1

解释：

唯一满足要求的排列是 [2, 0, 1] ：

前缀 [2, 0, 1] 的逆序对为 (0, 1) 和 (0, 2) 。
前缀 [2, 0] 的逆序对为 (0, 1) 。
前缀 [2] 的逆序对数目为 0 。
示例 3：

输入：n = 2, requirements = [[0,0],[1,0]]

输出：1

解释：

唯一满足要求的排列为 [0, 1] ：

前缀 [0] 的逆序对数目为 0 。
前缀 [0, 1] 的逆序对为 (0, 1) 。



提示：

2 <= n <= 300
1 <= requirements.length <= n
requirements[i] = [endi, cnti]
0 <= endi <= n - 1
0 <= cnti <= 400
输入保证至少有一个 i 满足 endi == n - 1 。
输入保证所有的 endi 互不相同。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        int maxCnt = 0, mod = 1000000007;
        vector<int> count(n, -1);

        for (auto& req : requirements) {  // 记录指定req的位置和逆序个数
            count[req[0]] = req[1];
            maxCnt = max(maxCnt, req[1]);
        }

        vector<int> dpPrev(maxCnt + 1, 0), dpSumPrev(maxCnt + 2, 1);
        dpPrev[0] = 1, dpSumPrev[0] = 0;

        for (int idx = 0; idx < n; ++idx) {  // 枚举数组nums[0, idx]
            vector<int> dp(maxCnt + 1, 0), dpSum(maxCnt + 2, 0);

            for (int cnt = 0; cnt <= maxCnt; ++cnt) {  // 枚举逆序的个数
                // 通过枚举最后一个数产生的逆序个数c∈[0, idx]，dp[cnt] = sum(dpPrev[cnt - c]) = dpSumPrev[cnt + 1] - dpSumPrev[cnt - idx]
                if (count[idx] == -1 || cnt == count[idx]) {
                    dp[cnt] = (dpSumPrev[cnt + 1] + mod - dpSumPrev[cnt - min(cnt, idx)]) % mod;
                }
                else {  // 如果指定了逆序的个数，其它cnt的数组个数都是0
                    dp[cnt] = 0;
                }

                dpSum[cnt + 1] = (dpSum[cnt] + dp[cnt]) % mod;  // 记录dp的前缀和，供下一个idx使用
            }

            dpPrev = dp;
            dpSumPrev = dpSum;
        }

        return dpPrev.back();
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> requirements = { {2,2},{0,0} };
    check.checkInt(2, o.numberOfPermutations(3, requirements));

    requirements = { {2,2},{1,1},{0,0} };
    check.checkInt(1, o.numberOfPermutations(3, requirements));

    requirements = { {0,0},{1,0} };
    check.checkInt(1, o.numberOfPermutations(2, requirements));

    requirements = { {4,5},{6,10},{14,53},{0,0} };
    check.checkInt(393161917, o.numberOfPermutations(15, requirements));
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
