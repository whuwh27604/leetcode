/* 标记所有节点需要的时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵 无向 树，树中节点从 0 到 n - 1 编号。同时给你一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ui, vi] 表示节点 ui 和 vi 在树中有一条边。

一开始，所有 节点都 未标记 。对于节点 i ：

当 i 是奇数时，如果时刻 x - 1 该节点有 至少 一个相邻节点已经被标记了，那么节点 i 会在时刻 x 被标记。
当 i 是偶数时，如果时刻 x - 2 该节点有 至少 一个相邻节点已经被标记了，那么节点 i 会在时刻 x 被标记。
请你返回一个数组 times ，表示如果你在时刻 t = 0 标记节点 i ，那么时刻 times[i] 时，树中所有节点都会被标记。

请注意，每个 times[i] 的答案都是独立的，即当你标记节点 i 时，所有其他节点都未标记。



示例 1：

输入：edges = [[0,1],[0,2]]

输出：[2,4,3]

解释：



对于 i = 0 ：
节点 1 在时刻 t = 1 被标记，节点 2 在时刻 t = 2 被标记。
对于 i = 1 ：
节点 0 在时刻 t = 2 被标记，节点 2 在时刻 t = 4 被标记。
对于 i = 2 ：
节点 0 在时刻 t = 2 被标记，节点 1 在时刻 t = 3 被标记。
示例 2：

输入：edges = [[0,1]]

输出：[1,2]

解释：



对于 i = 0 ：
节点 1 在时刻 t = 1 被标记。
对于 i = 1 ：
节点 0 在时刻 t = 2 被标记。
示例 3：

输入：edges = [[2,4],[0,1],[2,3],[0,2]]

输出：[4,6,3,5,5]

解释：





提示：

2 <= n <= 105
edges.length == n - 1
edges[i].length == 2
0 <= edges[i][0], edges[i][1] <= n - 1
输入保证 edges 表示一棵合法的树。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n = (int)edges.size() + 1;
        vector<vector<int>> adjs(n);
        vector<int> maxTime1(n, 0), maxTime2(n, 0), maxChild(n, 0);
        vector<int> ans(n);

        getAdjs(edges, adjs);
        DFS(0, -1, adjs, maxTime1, maxTime2, maxChild);  // 先DFS求以node为根节点的子树，最大时间、次大时间、最大时间对应的子节点
        getMaxTime(0, -1, 0, adjs, maxTime1, maxTime2, maxChild, ans);  // 然后换根DP

        return ans;
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
    }

    void DFS(int node, int parent, vector<vector<int>>& adjs, vector<int>& maxTime1, vector<int>& maxTime2, vector<int>& maxChild) {
        for (int next : adjs[node]) {
            if (next != parent) {
                DFS(next, node, adjs, maxTime1, maxTime2, maxChild);
                int time = maxTime1[next] + ((next & 1) == 1 ? 1 : 2);  // 从node->next方向
                if (time > maxTime1[node]) {
                    maxTime2[node] = maxTime1[node];
                    maxTime1[node] = time;
                    maxChild[node] = next;
                }
                else if (time > maxTime2[node]) {
                    maxTime2[node] = time;
                }
            }
        }
    }

    void getMaxTime(int node, int parent, int upMax, vector<vector<int>>& adjs,
        vector<int>& maxTime1, vector<int>& maxTime2, vector<int>& maxChild, vector<int>& ans) {
        ans[node] = max(upMax, maxTime1[node]);  // 从node往下，最大时间保存在maxTime1；从node往上，最大时间记录在upMax

        for (int next : adjs[node]) {
            if (next != parent) {
                // 对next来说，upMax可能出现在同层子树中，也可能出现在更上层的upMax中；接下来是求ans[next]，所以是next->node方向
                int nextUpMax = max(next == maxChild[node] ? maxTime2[node] : maxTime1[node], upMax) + ((node & 1) == 1 ? 1 : 2);
                getMaxTime(next, node, nextUpMax, adjs, maxTime1, maxTime2, maxChild, ans);
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> edges = { {0,1},{0,2} };
    vector<int> actual = o.timeTaken(edges);
    vector<int> expected = { 2,4,3 };
    check.checkIntVector(expected, actual);

    edges = { {0,1} };
    actual = o.timeTaken(edges);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    edges = { {2,4},{0,1},{2,3},{0,2} };
    actual = o.timeTaken(edges);
    expected = { 4,6,3,5,5 };
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
