﻿/* 切棍子的最小成本.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一根长度为 n 个单位的木棍，棍上从 0 到 n 标记了若干位置。例如，长度为 6 的棍子可以标记如下：



给你一个整数数组 cuts ，其中 cuts[i] 表示你需要将棍子切开的位置。

你可以按顺序完成切割，也可以根据需要更改切割的顺序。

每次切割的成本都是当前要切割的棍子的长度，切棍子的总成本是历次切割成本的总和。对棍子进行切割将会把一根木棍分成两根较小的木棍（这两根木棍的长度和就是切割前木棍的长度）。请参阅第一个示例以获得更直观的解释。

返回切棍子的 最小总成本 。

 

示例 1：



输入：n = 7, cuts = [1,3,4,5]
输出：16
解释：按 [1, 3, 4, 5] 的顺序切割的情况如下所示：

第一次切割长度为 7 的棍子，成本为 7 。第二次切割长度为 6 的棍子（即第一次切割得到的第二根棍子），第三次切割为长度 4 的棍子，最后切割长度为 3 的棍子。总成本为 7 + 6 + 4 + 3 = 20 。
而将切割顺序重新排列为 [3, 5, 1, 4] 后，总成本 = 16（如示例图中 7 + 4 + 3 + 2 = 16）。
示例 2：

输入：n = 9, cuts = [5,6,1,4,2]
输出：22
解释：如果按给定的顺序切割，则总成本为 25 。总成本 <= 25 的切割顺序很多，例如，[4, 6, 5, 2, 1] 的总成本 = 22，是所有可能方案中成本最小的。
 

提示：

2 <= n <= 10^6
1 <= cuts.length <= min(n - 1, 100)
1 <= cuts[i] <= n - 1
cuts 数组中的所有整数都 互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-cost-to-cut-a-stick
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int size = cuts.size();
        vector<vector<int>> dp(size + 2, vector<int>(size + 2, 0));

        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());

        for (int cut = 1; cut <= size; ++cut) {
            for (int start = 1, end = start + cut - 1; end <= size; ++start, ++end) {
                dp[cut][start] = INT_MAX;

                for (int first = start; first <= end; ++first) {
                    dp[cut][start] = min(dp[cut][start], dp[first - start][start] + dp[end - first][first + 1]);
                }

                dp[cut][start] += (cuts[end + 1] - cuts[start - 1]);
            }
        }

        return dp[size][1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> cuts = { 1,3,4,5 };
    check.checkInt(16, o.minCost(7, cuts));

    cuts = { 5,6,1,4,2 };
    check.checkInt(22, o.minCost(9, cuts));

    cuts = { 5 };
    check.checkInt(9, o.minCost(9, cuts));
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
