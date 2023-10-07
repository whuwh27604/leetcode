/* 有向图访问计数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
现有一个有向图，其中包含 n 个节点，节点编号从 0 到 n - 1 。此外，该图还包含了 n 条有向边。

给你一个下标从 0 开始的数组 edges ，其中 edges[i] 表示存在一条从节点 i 到节点 edges[i] 的边。

想象在图上发生以下过程：

你从节点 x 开始，通过边访问其他节点，直到你在 此过程 中再次访问到之前已经访问过的节点。
返回数组 answer 作为答案，其中 answer[i] 表示如果从节点 i 开始执行该过程，你可以访问到的不同节点数。



示例 1：


输入：edges = [1,2,0,0]
输出：[3,3,3,4]
解释：从每个节点开始执行该过程，记录如下：
- 从节点 0 开始，访问节点 0 -> 1 -> 2 -> 0 。访问的不同节点数是 3 。
- 从节点 1 开始，访问节点 1 -> 2 -> 0 -> 1 。访问的不同节点数是 3 。
- 从节点 2 开始，访问节点 2 -> 0 -> 1 -> 2 。访问的不同节点数是 3 。
- 从节点 3 开始，访问节点 3 -> 0 -> 1 -> 2 -> 0 。访问的不同节点数是 4 。
示例 2：


输入：edges = [1,2,3,4,0]
输出：[5,5,5,5,5]
解释：无论从哪个节点开始，在这个过程中，都可以访问到图中的每一个节点。


提示：

n == edges.length
2 <= n <= 105
0 <= edges[i] <= n - 1
edges[i] != i
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int n = edges.size();
        vector<int> degrees(n, 0);
        vector<bool> isOnRing(n, true);
        vector<vector<int>> parents(n);
        vector<int> ans(n, 0);

        for (int i = 0; i < n; ++i) {
            ++degrees[edges[i]];
            parents[edges[i]].push_back(i);
        }

        topSort(n, edges, degrees, isOnRing);
        count(n, edges, isOnRing, parents, ans);

        return ans;
    }

    void topSort(int n, vector<int>& edges, vector<int>& degrees, vector<bool>& isOnRing) {
        queue<int> nodes;

        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 0) {
                nodes.push(i);
                isOnRing[i] = false;
            }
        }

        while (!nodes.empty()) {
            int from = nodes.front(), to = edges[from];
            nodes.pop();

            if (--degrees[to] == 0) {
                nodes.push(to);
                isOnRing[to] = false;
            }
        }
    }

    void count(int n, vector<int>& edges, vector<bool>& isOnRing, vector<vector<int>>& parents, vector<int>& ans) {
        for (int i = 0; i < n; ++i) {
            if (isOnRing[i] && ans[i] == 0) {
                int len = getRingLen(i, edges);
                int node = i;

                do {
                    if (parents[node].size() != 1) {
                        for (int parent : parents[node]) {
                            if (!isOnRing[parent]) {
                                countTree(len + 1, parent, parents, ans);
                            }
                        }
                    }

                    ans[node] = len;
                    node = edges[node];
                } while (node != i);
            }
        }
    }

    int getRingLen(int start, vector<int>& edges) {
        int node = edges[start], len = 1;

        while (node != start) {
            ++len;
            node = edges[node];
        }

        return len;
    }

    void countTree(int cnt, int node, vector<vector<int>>& parents, vector<int>& ans) {
        ans[node] = cnt++;

        for (int parent : parents[node]) {
            countTree(cnt, parent, parents, ans);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> edges = { 1,2,0,0 };
    vector<int> actual = o.countVisitedNodes(edges);
    vector<int> expected = { 3,3,3,4 };
    check.checkIntVector(expected, actual);

    edges = { 1,2,3,4,0 };
    actual = o.countVisitedNodes(edges);
    expected = { 5,5,5,5,5 };
    check.checkIntVector(expected, actual);

    edges = { 3,6,1,0,5,7,4,3 };
    actual = o.countVisitedNodes(edges);
    expected = { 2,7,8,2,5,4,6,3 };
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
