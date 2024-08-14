/* 统计好节点的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
现有一棵 无向 树，树中包含 n 个节点，按从 0 到 n - 1 标记。树的根节点是节点 0 。给你一个长度为 n - 1 的二维整数数组 edges，其中 edges[i] = [ai, bi] 表示树中节点 ai 与节点 bi 之间存在一条边。

如果一个节点的所有子节点为根的
子树
 包含的节点数相同，则认为该节点是一个 好节点。

返回给定树中 好节点 的数量。

子树 指的是一个节点以及它所有后代节点构成的一棵树。





示例 1：

输入：edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]

输出：7

说明：


树的所有节点都是好节点。

示例 2：

输入：edges = [[0,1],[1,2],[2,3],[3,4],[0,5],[1,6],[2,7],[3,8]]

输出：6

说明：


树中有 6 个好节点。上图中已将这些节点着色。

示例 3：

输入：edges = [[0,1],[1,2],[1,3],[1,4],[0,5],[5,6],[6,7],[7,8],[0,9],[9,10],[9,12],[10,11]]

输出：12

解释：


除了节点 9 以外其他所有节点都是好节点。



提示：

2 <= n <= 105
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
输入确保 edges 总表示一棵有效的树。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = (int)edges.size() + 1, good = 0;
        vector<vector<int>> adjs(n);

        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }

        (void)DFS(adjs, 0, -1, good);

        return good;
    }

    int DFS(vector<vector<int>>& adjs, int node, int parent, int& good) {
        int count = 1, child = 0;
        bool isGood = true;

        for (int next : adjs[node]) {
            if (next != parent) {
                int cnt = DFS(adjs, next, node, good);
                count += cnt;

                if (child == 0) {
                    child = cnt;
                }
                else if (child != cnt) {
                    isGood = false;
                }
            }
        }

        if (isGood) {
            ++good;
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> edges = { {0,1},{0,2},{1,3},{1,4},{2,5},{2,6} };
    check.checkInt(7, o.countGoodNodes(edges));

    edges = { {0,1},{1,2},{2,3},{3,4},{0,5},{1,6},{2,7},{3,8} };
    check.checkInt(6, o.countGoodNodes(edges));

    edges = { {0,1},{1,2},{1,3},{1,4},{0,5},{5,6},{6,7},{7,8},{0,9},{9,10},{9,12},{10,11} };
    check.checkInt(12, o.countGoodNodes(edges));
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
