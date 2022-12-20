/* 添加边使所有节点度数都为偶数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个有 n 个节点的 无向 图，节点编号为 1 到 n 。再给你整数 n 和一个二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示节点 ai 和 bi 之间有一条边。图不一定连通。

你可以给图中添加 至多 两条额外的边（也可以一条边都不添加），使得图中没有重边也没有自环。

如果添加额外的边后，可以使得图中所有点的度数都是偶数，返回 true ，否则返回 false 。

点的度数是连接一个点的边的数目。



示例 1：



输入：n = 5, edges = [[1,2],[2,3],[3,4],[4,2],[1,4],[2,5]]
输出：true
解释：上图展示了添加一条边的合法方案。
最终图中每个节点都连接偶数条边。
示例 2：



输入：n = 4, edges = [[1,2],[3,4]]
输出：true
解释：上图展示了添加两条边的合法方案。
示例 3：



输入：n = 4, edges = [[1,2],[1,3],[1,4]]
输出：false
解释：无法添加至多 2 条边得到一个符合要求的图。


提示：

3 <= n <= 105
2 <= edges.length <= 105
edges[i].length == 2
1 <= ai, bi <= n
ai != bi
图中不会有重边
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> adjs(n + 1);
        vector<int> degrees(n + 1, 0), odds;

        getDegrees(edges, adjs, degrees);
        getOddDegrees(n, degrees, odds);
        int size = odds.size();
        if (size == 0) {
            return true;
        }

        if (size == 1 || size == 3 || size > 4) {
            return false;
        }

        if (size == 2) {
            return twoOdds(n, odds[0], odds[1], adjs);
        }

        return fourOdds(odds[0], odds[1], odds[2], odds[3], adjs);
    }

    void getDegrees(vector<vector<int>>& edges, vector<unordered_set<int>>& adjs, vector<int>& degrees) {
        for (auto& edge : edges) {
            int node0 = edge[0], node1 = edge[1];
            adjs[node0].insert(node1);
            adjs[node1].insert(node0);
            ++degrees[node0];
            ++degrees[node1];
        }
    }

    void getOddDegrees(int n, vector<int>& degrees, vector<int>& odds) {
        for (int i = 1; i <= n; ++i) {
            if ((degrees[i] & 1) == 1) {
                odds.push_back(i);
            }
        }
    }

    bool twoOdds(int n, int a, int b, vector<unordered_set<int>>& adjs) {
        if (adjs[a].count(b) == 0) {  // 如果a、b不相连，则连接a、b后满足条件
            return true;
        }

        for (int node = 1; node <= n; ++node) {  // a、b已经相连，则需要找到一个节点node，node和a，node和b都不相连，这样连接node和a、node和b后满足条件
            if (node == a || node == b) {
                continue;
            }

            if (adjs[node].count(a) == 0 && adjs[node].count(b) == 0) {
                return true;
            }
        }

        return false;
    }

    bool fourOdds(int a, int b, int c, int d, vector<unordered_set<int>>& adjs) {
        return (adjs[a].count(b) == 0 && adjs[c].count(d) == 0)  // 只能a连接b、c连接d
            || (adjs[a].count(c) == 0 && adjs[b].count(d) == 0)  // 或者a连接c、b连接d
            || (adjs[a].count(d) == 0 && adjs[b].count(c) == 0);  // 或者a连接d、b连接c
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {1,2},{2,3},{3,4},{4,2},{1,4},{2,5} };
    check.checkBool(true, o.isPossible(5, edges));

    edges = { {1,2},{3,4} };
    check.checkBool(true, o.isPossible(4, edges));

    edges = { {1,2},{1,3},{1,4} };
    check.checkBool(false, o.isPossible(4, edges));

    edges = {  };
    check.checkBool(true, o.isPossible(4, edges));

    edges = { {1,2},{3,4},{5,6} };
    check.checkBool(false, o.isPossible(6, edges));

    edges = { {1,2} };
    check.checkBool(true, o.isPossible(3, edges));

    edges = getIntVectorVector("./testcase1.txt");
    check.checkBool(true, o.isPossible(100000, edges));
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
