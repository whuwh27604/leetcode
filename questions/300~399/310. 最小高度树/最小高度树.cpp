/* 最小高度树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。

给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1 条无向边的 edges 列表（每一个边都是一对标签），其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。

可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h 。在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度树 。

请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。

树的 高度 是指根节点和叶子节点之间最长向下路径上边的数量。
 

示例 1：


输入：n = 4, edges = [[1,0],[1,2],[1,3]]
输出：[1]
解释：如图所示，当根是标签为 1 的节点时，树的高度是 1 ，这是唯一的最小高度树。
示例 2：


输入：n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
输出：[3,4]
示例 3：

输入：n = 1, edges = []
输出：[0]
示例 4：

输入：n = 2, edges = [[0,1]]
输出：[0,1]
 

提示：

1 <= n <= 2 * 104
edges.length == n - 1
0 <= ai, bi < n
ai != bi
所有 (ai, bi) 互不相同
给定的输入 保证 是一棵树，并且 不会有重复的边

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-height-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return { 0 };
        }

        unordered_map<int, unordered_set<int>> adjs;
        getAdjs(edges, adjs);

        while (adjs.size() > 2) {  // root只可能是1个或者2个，从最外围往中间搜
            vector<int> leaves;
            getLeaves(adjs, leaves);
            removeLeaves(adjs, leaves);
        }

        return getRoots(adjs);
    }

    void getAdjs(vector<vector<int>>& edges, unordered_map<int, unordered_set<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].insert(edge[1]);
            adjs[edge[1]].insert(edge[0]);
        }
    }

    void getLeaves(unordered_map<int, unordered_set<int>>& adjs, vector<int>& leaves) {
        for (auto iter = adjs.begin(); iter != adjs.end(); ++iter) {
            if (iter->second.size() == 1) {
                leaves.push_back(iter->first);
            }
        }
    }

    void removeLeaves(unordered_map<int, unordered_set<int>>& adjs, vector<int>& leaves) {
        for (int leaf : leaves) {
            for (auto iter = adjs[leaf].begin(); iter != adjs[leaf].end(); ++iter) {
                adjs[*iter].erase(leaf);  // 先从对端的链接表里面删除自己
            }

            adjs.erase(leaf);
        }
    }

    vector<int> getRoots(unordered_map<int, unordered_set<int>>& adjs) {
        vector<int> roots;

        for (auto iter = adjs.begin(); iter != adjs.end(); ++iter) {
            roots.push_back(iter->first);
        }

        return roots;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {1,0},{1,2},{1,3} };
    vector<int> actual = o.findMinHeightTrees(4, edges);
    vector<int> expected = { 1 };
    check.checkIntVector(expected, actual);

    edges = { {3,0},{3,1},{3,2},{3,4},{5,4} };
    actual = o.findMinHeightTrees(6, edges);
    expected = { 3,4 };
    check.checkIntVector(expected, actual);

    edges = {};
    actual = o.findMinHeightTrees(1, edges);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    edges = { {0,1} };
    actual = o.findMinHeightTrees(2, edges);
    expected = { 0,1 };
    check.checkIntVector(expected, actual);

    edges = { {0,1},{0,2} };
    actual = o.findMinHeightTrees(3, edges);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    edges = { {0,1},{1,2},{1,3},{2,4},{3,5},{4,6} };
    actual = o.findMinHeightTrees(7, edges);
    expected = { 1,2 };
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
