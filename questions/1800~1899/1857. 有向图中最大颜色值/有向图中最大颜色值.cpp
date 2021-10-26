/* 有向图中最大颜色值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 有向图 ，它含有 n 个节点和 m 条边。节点编号从 0 到 n - 1 。

给你一个字符串 colors ，其中 colors[i] 是小写英文字母，表示图中第 i 个节点的 颜色 （下标从 0 开始）。同时给你一个二维数组 edges ，其中 edges[j] = [aj, bj] 表示从节点 aj 到节点 bj 有一条 有向边 。

图中一条有效 路径 是一个点序列 x1 -> x2 -> x3 -> ... -> xk ，对于所有 1 <= i < k ，从 xi 到 xi+1 在图中有一条有向边。路径的 颜色值 是路径中 出现次数最多 颜色的节点数目。

请你返回给定图中有效路径里面的 最大颜色值 。如果图中含有环，请返回 -1 。

 

示例 1：



输入：colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
输出：3
解释：路径 0 -> 2 -> 3 -> 4 含有 3 个颜色为 "a" 的节点（上图中的红色节点）。
示例 2：



输入：colors = "a", edges = [[0,0]]
输出：-1
解释：从 0 到 0 有一个环。
 

提示：

n == colors.length
m == edges.length
1 <= n <= 105
0 <= m <= 105
colors 只含有小写英文字母。
0 <= aj, bj < n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-color-value-in-a-directed-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size(), totalIngrees = 0, maxValue = 0;
        vector<vector<int>> afters(n), dp(n, vector<int>(26, 0));  // dp[i][j]表示以节点i为结尾的路径中，字符j的最大次数
        vector<int> ingrees(n, 0);
        queue<int> nodes;

        for (auto& edge : edges) {
            afters[edge[0]].push_back(edge[1]);
            ++ingrees[edge[1]];
            ++totalIngrees;
        }

        for (int node = 0; node < n; ++node) {
            if (ingrees[node] == 0) {
                nodes.push(node);
                dp[node][colors[node] - 'a'] = 1;
            }
        }

        while (!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();

            if (afters[node].empty()) {
                maxValue = max(maxValue, *max_element(dp[node].begin(), dp[node].end()));
                continue;
            }

            for (int after : afters[node]) {
                --totalIngrees;

                if (--ingrees[after] == 0) {
                    nodes.push(after);
                }

                for (int j = 0; j < 26; ++j) {
                    dp[after][j] = max(dp[after][j], dp[node][j] + (colors[after] - 'a' == j ? 1 : 0));
                }
            }
        }

        return totalIngrees == 0 ? maxValue : -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {1,2},{2,1} };
    check.checkInt(-1, o.largestPathValue("aaa", edges));

    edges = { {0,1},{0,2},{2,3},{3,4} };
    check.checkInt(3, o.largestPathValue("abaca", edges));

    edges = { {0,0} };
    check.checkInt(-1, o.largestPathValue("a", edges));

    edges = {  };
    check.checkInt(1, o.largestPathValue("z", edges));
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
