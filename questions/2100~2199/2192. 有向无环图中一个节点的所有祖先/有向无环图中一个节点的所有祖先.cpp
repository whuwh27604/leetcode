/* 有向无环图中一个节点的所有祖先.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 n ，它表示一个 有向无环图 中节点的数目，节点编号为 0 到 n - 1 （包括两者）。

给你一个二维整数数组 edges ，其中 edges[i] = [fromi, toi] 表示图中一条从 fromi 到 toi 的单向边。

请你返回一个数组 answer，其中 answer[i]是第 i 个节点的所有 祖先 ，这些祖先节点 升序 排序。

如果 u 通过一系列边，能够到达 v ，那么我们称节点 u 是节点 v 的 祖先 节点。

 

示例 1：



输入：n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
输出：[[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
解释：
上图为输入所对应的图。
- 节点 0 ，1 和 2 没有任何祖先。
- 节点 3 有 2 个祖先 0 和 1 。
- 节点 4 有 2 个祖先 0 和 2 。
- 节点 5 有 3 个祖先 0 ，1 和 3 。
- 节点 6 有 5 个祖先 0 ，1 ，2 ，3 和 4 。
- 节点 7 有 4 个祖先 0 ，1 ，2 和 3 。
示例 2：



输入：n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
输出：[[],[0],[0,1],[0,1,2],[0,1,2,3]]
解释：
上图为输入所对应的图。
- 节点 0 没有任何祖先。
- 节点 1 有 1 个祖先 0 。
- 节点 2 有 2 个祖先 0 和 1 。
- 节点 3 有 3 个祖先 0 ，1 和 2 。
- 节点 4 有 4 个祖先 0 ，1 ，2 和 3 。
 

提示：

1 <= n <= 1000
0 <= edges.length <= min(2000, n * (n - 1) / 2)
edges[i].length == 2
0 <= fromi, toi <= n - 1
fromi != toi
图中不会有重边。
图是 有向 且 无环 的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> inDegrees(n, 0);
        vector<vector<int>> adjs(n);
        queue<int> zeroInDegrees;
        vector<set<int>> ancestors(n);

        getAdjsAndInDegrees(edges, adjs, inDegrees);
        init(n, inDegrees, zeroInDegrees);
        topSort(inDegrees, zeroInDegrees, adjs, ancestors);
        
        return getAncestors(n, ancestors);
    }

    void getAdjsAndInDegrees(vector<vector<int>>& edges, vector<vector<int>>& adjs, vector<int>& inDegrees) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            ++inDegrees[edge[1]];
        }
    }

    void init(int n, vector<int>& inDegrees, queue<int>& zeroInDegrees) {
        for (int node = 0; node < n; ++node) {
            if (inDegrees[node] == 0) {
                zeroInDegrees.push(node);
            }
        }
    }

    void topSort(vector<int>& inDegrees, queue<int>& zeroInDegrees, vector<vector<int>>& adjs, vector<set<int>>& ancestors) {
        while (!zeroInDegrees.empty()) {
            int node = zeroInDegrees.front();
            zeroInDegrees.pop();

            for (int next : adjs[node]) {
                ancestors[next].insert(node);

                for (int ancestor : ancestors[node]) {
                    ancestors[next].insert(ancestor);
                }

                if (--inDegrees[next] == 0) {
                    zeroInDegrees.push(next);
                }
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<set<int>>& ancestors) {
        vector<vector<int>> sortedAncestors(n);

        for (int i = 0; i < n; ++i) {
            for (int ancestor : ancestors[i]) {
                sortedAncestors[i].push_back(ancestor);
            }
        }

        return sortedAncestors;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6} };
    vector<vector<int>> actual = o.getAncestors(8, edges);
    vector<vector<int>> expected = { {},{},{},{0,1},{0,2},{0,1,3},{0,1,2,3,4},{0,1,2,3} };
    check.checkIntVectorVector(expected, actual);

    edges = { {0,1},{0,2},{0,3},{0,4},{1,2},{1,3},{1,4},{2,3},{2,4},{3,4} };
    actual = o.getAncestors(5, edges);
    expected = { {},{0},{0,1},{0,1,2},{0,1,2,3} };
    check.checkIntVectorVector(expected, actual);

    edges = getIntVectorVector("./testcase1.txt");
    actual = o.getAncestors(52, edges);
    expected = { {},{0},{0,1},{0,1,2},{0,1,2,3} };
    check.checkIntVectorVector(expected, actual);
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
