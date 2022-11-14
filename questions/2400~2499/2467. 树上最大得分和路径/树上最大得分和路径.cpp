/* 树上最大得分和路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个 n 个节点的无向树，节点编号为 0 到 n - 1 ，树的根结点是 0 号节点。给你一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ai, bi] ，表示节点 ai 和 bi 在树中有一条边。

在每一个节点 i 处有一扇门。同时给你一个都是偶数的数组 amount ，其中 amount[i] 表示：

如果 amount[i] 的值是负数，那么它表示打开节点 i 处门扣除的分数。
如果 amount[i] 的值是正数，那么它表示打开节点 i 处门加上的分数。
游戏按照如下规则进行：

一开始，Alice 在节点 0 处，Bob 在节点 bob 处。
每一秒钟，Alice 和 Bob 分别 移动到相邻的节点。Alice 朝着某个 叶子结点 移动，Bob 朝着节点 0 移动。
对于他们之间路径上的 每一个 节点，Alice 和 Bob 要么打开门并扣分，要么打开门并加分。注意：
如果门 已经打开 （被另一个人打开），不会有额外加分也不会扣分。
如果 Alice 和 Bob 同时 到达一个节点，他们会共享这个节点的加分或者扣分。换言之，如果打开这扇门扣 c 分，那么 Alice 和 Bob 分别扣 c / 2 分。如果这扇门的加分为 c ，那么他们分别加 c / 2 分。
如果 Alice 到达了一个叶子结点，她会停止移动。类似的，如果 Bob 到达了节点 0 ，他也会停止移动。注意这些事件互相 独立 ，不会影响另一方移动。
请你返回 Alice 朝最优叶子结点移动的 最大 净得分。



示例 1：



输入：edges = [[0,1],[1,2],[1,3],[3,4]], bob = 3, amount = [-2,4,2,-4,6]
输出：6
解释：
上图展示了输入给出的一棵树。游戏进行如下：
- Alice 一开始在节点 0 处，Bob 在节点 3 处。他们分别打开所在节点的门。
  Alice 得分为 -2 。
- Alice 和 Bob 都移动到节点 1 。
  因为他们同时到达这个节点，他们一起打开门并平分得分。
  Alice 的得分变为 -2 + (4 / 2) = 0 。
- Alice 移动到节点 3 。因为 Bob 已经打开了这扇门，Alice 得分不变。
  Bob 移动到节点 0 ，并停止移动。
- Alice 移动到节点 4 并打开这个节点的门，她得分变为 0 + 6 = 6 。
现在，Alice 和 Bob 都不能进行任何移动了，所以游戏结束。
Alice 无法得到更高分数。
示例 2：



输入：edges = [[0,1]], bob = 1, amount = [-7280,2350]
输出：-7280
解释：
Alice 按照路径 0->1 移动，同时 Bob 按照路径 1->0 移动。
所以 Alice 只打开节点 0 处的门，她的得分为 -7280 。


提示：

2 <= n <= 105
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges 表示一棵有效的树。
1 <= bob < n
amount.length == n
amount[i] 是范围 [-104, 104] 之间的一个 偶数 。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size(), maxScore = INT_MIN;
        vector<vector<int>> adjs(n);
        vector<int> parents(n, -1);
        vector<int> path;

        getAdjs(edges, adjs);
        getParents(0, -1, adjs, parents);
        getBobPath(bob, parents, path);
        adjustAmount(amount, path);
        getMaxScore(0, -1, 0, maxScore, amount, adjs);

        return maxScore;
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
    }

    void getParents(int node, int parent, vector<vector<int>>& adjs, vector<int>& parents) {
        for (int next : adjs[node]) {
            if (next != parent) {
                parents[next] = node;
                getParents(next, node, adjs, parents);
            }
        }
    }

    void getBobPath(int bob, vector<int>& parents, vector<int>& path) {
        while (bob != -1) {
            path.push_back(bob);
            bob = parents[bob];
        }
    }

    void adjustAmount(vector<int>& amount, vector<int>& path) {
        int i = 0, j = path.size() - 1;

        for (; i < j; ++i, --j) {
            amount[path[i]] = 0;
        }

        if (i == j) {
            amount[path[i]] /= 2;
        }
    }

    void getMaxScore(int node, int parent, int score, int& maxScore, vector<int>& amount, vector<vector<int>>& adjs) {
        score += amount[node];

        if (node != 0 && adjs[node].size() == 1) {
            maxScore = max(maxScore, score);
        }

        for (int next : adjs[node]) {
            if (next != parent) {
                getMaxScore(next, node, score, maxScore, amount, adjs);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {0,1},{1,2},{1,3},{3,4} };
    vector<int> amount = { -2,4,2,-4,6 };
    check.checkInt(6, o.mostProfitablePath(edges, 3, amount));

    edges = { {0,1} };
    amount = { -7280,2350 };
    check.checkInt(-7280, o.mostProfitablePath(edges, 1, amount));
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
