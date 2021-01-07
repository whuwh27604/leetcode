/* 可以到达所有点的最少点数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 有向无环图 ， n 个节点编号为 0 到 n-1 ，以及一个边数组 edges ，其中 edges[i] = [fromi, toi] 表示一条从点  fromi 到点 toi 的有向边。

找到最小的点集使得从这些点出发能到达图中所有点。题目保证解存在且唯一。

你可以以任意顺序返回这些节点编号。

 

示例 1：



输入：n = 6, edges = [[0,1],[0,2],[2,5],[3,4],[4,2]]
输出：[0,3]
解释：从单个节点出发无法到达所有节点。从 0 出发我们可以到达 [0,1,2,5] 。从 3 出发我们可以到达 [3,4,2,5] 。所以我们输出 [0,3] 。
示例 2：



输入：n = 5, edges = [[0,1],[2,1],[3,1],[1,4],[2,4]]
输出：[0,2,3]
解释：注意到节点 0，3 和 2 无法从其他节点到达，所以我们必须将它们包含在结果点集中，这些点都能到达节点 1 和 4 。
 

提示：

2 <= n <= 10^5
1 <= edges.length <= min(10^5, n * (n - 1) / 2)
edges[i].length == 2
0 <= fromi, toi < n
所有点对 (fromi, toi) 互不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-vertices-to-reach-all-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> nodes(n, 0), zeroIndegrees;

        for (auto& edge : edges) {
            nodes[edge[1]] = 1;
        }

        for (int i = 0; i < n; ++i) {
            if (nodes[i] == 0) {
                zeroIndegrees.push_back(i);
            }
        }

        return zeroIndegrees;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {0,1},{0,2},{2,5},{3,4},{4,2} };
    vector<int> actual = o.findSmallestSetOfVertices(6, edges);
    vector<int> expected = { 0,3 };
    check.checkIntVector(expected, actual);
    
    edges = { {0,1},{2,1},{3,1},{1,4},{2,4} };
    actual = o.findSmallestSetOfVertices(5, edges);
    expected = { 0,2,3 };
    check.checkIntVector(expected, actual);

    edges = { {1,0} };
    actual = o.findSmallestSetOfVertices(2, edges);
    expected = { 1 };
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
