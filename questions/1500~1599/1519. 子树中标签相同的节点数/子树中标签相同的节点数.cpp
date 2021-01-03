/* 子树中标签相同的节点数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵树（即，一个连通的无环无向图），这棵树由编号从 0  到 n - 1 的 n 个节点组成，且恰好有 n - 1 条 edges 。树的根节点为节点 0 ，树上的每一个节点都有一个标签，也就是字符串 labels 中的一个小写字符（编号为 i 的 节点的标签就是 labels[i] ）

边数组 edges 以 edges[i] = [ai, bi] 的形式给出，该格式表示节点 ai 和 bi 之间存在一条边。

返回一个大小为 n 的数组，其中 ans[i] 表示第 i 个节点的子树中与节点 i 标签相同的节点数。

树 T 中的子树是由 T 中的某个节点及其所有后代节点组成的树。

 

示例 1：



输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], labels = "abaedcd"
输出：[2,1,1,1,1,1,1]
解释：节点 0 的标签为 'a' ，以 'a' 为根节点的子树中，节点 2 的标签也是 'a' ，因此答案为 2 。注意树中的每个节点都是这棵子树的一部分。
节点 1 的标签为 'b' ，节点 1 的子树包含节点 1、4 和 5，但是节点 4、5 的标签与节点 1 不同，故而答案为 1（即，该节点本身）。
示例 2：



输入：n = 4, edges = [[0,1],[1,2],[0,3]], labels = "bbbb"
输出：[4,2,1,1]
解释：节点 2 的子树中只有节点 2 ，所以答案为 1 。
节点 3 的子树中只有节点 3 ，所以答案为 1 。
节点 1 的子树中包含节点 1 和 2 ，标签都是 'b' ，因此答案为 2 。
节点 0 的子树中包含节点 0、1、2 和 3，标签都是 'b'，因此答案为 4 。
示例 3：



输入：n = 5, edges = [[0,1],[0,2],[1,3],[0,4]], labels = "aabab"
输出：[3,2,1,1,1]
示例 4：

输入：n = 6, edges = [[0,1],[0,2],[1,3],[3,4],[4,5]], labels = "cbabaa"
输出：[1,2,1,1,2,1]
示例 5：

输入：n = 7, edges = [[0,1],[1,2],[2,3],[3,4],[4,5],[5,6]], labels = "aaabaaa"
输出：[6,5,4,1,3,2,1]
 

提示：

1 <= n <= 10^5
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
labels.length == n
labels 仅由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adjacencies(n);
        getAdjacencies(edges, adjacencies);

        vector<int> ans(n);
        (void)DFS(0, -1, adjacencies, labels, ans);

        return ans;
    }

    void getAdjacencies(vector<vector<int>>& edges, vector<vector<int>>& adjacencies) {
        for (auto& edge : edges) {
            adjacencies[edge[0]].push_back(edge[1]);
            adjacencies[edge[1]].push_back(edge[0]);
        }
    }

    vector<int> DFS(int root, int parent, vector<vector<int>>& adjacencies, string& labels, vector<int>& ans) {
        vector<int> labelCount(26, 0);

        for (int node : adjacencies[root]) {
            if (node != parent) {
                vector<int> childrenLabelCount = DFS(node, root, adjacencies, labels, ans);

                for (int i = 0; i < 26; ++i) {
                    labelCount[i] += childrenLabelCount[i];
                }
            }
        }

        int index = labels[root] - 'a';
        labelCount[index] += 1;
        ans[root] = labelCount[index];

        return labelCount;
    }
};

int main()
{
    CheckResult check;
    Solution o;
    
    vector<vector<int>> edges = { {0,1},{0,2},{1,4},{1,5},{2,3},{2,6} };
    vector<int> actual = o.countSubTrees(7, edges, "abaedcd");
    vector<int> expected = { 2,1,1,1,1,1,1 };
    check.checkIntVector(expected, actual);

    edges = { {0,1},{1,2},{0,3} };
    actual = o.countSubTrees(4, edges, "bbbb");
    expected = { 4,2,1,1 };
    check.checkIntVector(expected, actual);

    edges = { {0,1},{0,2},{1,3},{0,4} };
    actual = o.countSubTrees(5, edges, "aabab");
    expected = { 3,2,1,1,1 };
    check.checkIntVector(expected, actual);

    edges = { {0,1},{0,2},{1,3},{3,4},{4,5} };
    actual = o.countSubTrees(6, edges, "cbabaa");
    expected = { 1,2,1,1,2,1 };
    check.checkIntVector(expected, actual);

    edges = { {0,1},{1,2},{2,3},{3,4},{4,5},{5,6} };
    actual = o.countSubTrees(7, edges, "aaabaaa");
    expected = { 6,5,4,1,3,2,1 };
    check.checkIntVector(expected, actual);

    edges = { {0,2},{0,3},{1,2} };
    actual = o.countSubTrees(4, edges, "aeed");
    expected = { 1,1,2,1 };
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
