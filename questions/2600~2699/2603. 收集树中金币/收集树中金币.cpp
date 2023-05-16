/* 收集树中金币.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 n 个节点的无向无根树，节点编号从 0 到 n - 1 。给你整数 n 和一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间有一条边。再给你一个长度为 n 的数组 coins ，其中 coins[i] 可能为 0 也可能为 1 ，1 表示节点 i 处有一个金币。

一开始，你需要选择树中任意一个节点出发。你可以执行下述操作任意次：

收集距离当前节点距离为 2 以内的所有金币，或者
移动到树中一个相邻节点。
你需要收集树中所有的金币，并且回到出发节点，请你返回最少经过的边数。

如果你多次经过一条边，每一次经过都会给答案加一。



示例 1：



输入：coins = [1,0,0,0,0,1], edges = [[0,1],[1,2],[2,3],[3,4],[4,5]]
输出：2
解释：从节点 2 出发，收集节点 0 处的金币，移动到节点 3 ，收集节点 5 处的金币，然后移动回节点 2 。
示例 2：



输入：coins = [0,0,0,1,1,0,0,1], edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[5,6],[5,7]]
输出：2
解释：从节点 0 出发，收集节点 4 和 3 处的金币，移动到节点 2 处，收集节点 7 处的金币，移动回节点 0 。


提示：

n == coins.length
1 <= n <= 3 * 104
0 <= coins[i] <= 1
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges 表示一棵合法的树。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<int> degrees(n, 0), flags(n, 0);
        vector<vector<int>> adjs(n);

        getAdjs(edges, adjs, degrees);
        cutNoCoinLeafs(n, coins, degrees, adjs);
        topSort(n, degrees, adjs, flags);

        return getSteps(edges, flags);
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs, vector<int>& degrees) {
        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            adjs[a].push_back(b);
            adjs[b].push_back(a);
            ++degrees[a];
            ++degrees[b];
        }
    }

    void cutNoCoinLeafs(int n, vector<int>& coins, vector<int>& degrees, vector<vector<int>>& adjs) {
        queue<int> nodes;

        for (int i = 0; i < n; ++i) {
            if (coins[i] == 0 && degrees[i] == 1) {
                degrees[i] = 0;
                nodes.push(i);
            }
        }

        while (!nodes.empty()) {
            int node = nodes.front();
            nodes.pop();

            for (int next : adjs[node]) {
                --degrees[next];
                if (coins[next] == 0 && degrees[next] == 1) {
                    degrees[next] = 0;
                    nodes.push(next);
                }
            }
        }
    }

    void topSort(int n, vector<int>& degrees, vector<vector<int>>& adjs, vector<int>& flags) {
        queue<int> nodes;
        int flag = 0;

        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 1) {
                nodes.push(i);
            }
        }

        while (!nodes.empty()) {
            int size = nodes.size();
            ++flag;

            for (int i = 0; i < size; ++i) {
                int node = nodes.front();
                nodes.pop();

                for (int next : adjs[node]) {
                    if (--degrees[next] == 1) {
                        flags[next] = flag;
                        nodes.push(next);
                    }
                }
            }
        }
    }

    int getSteps(vector<vector<int>>& edges, vector<int>& flags) {
        int steps = 0;

        for (auto& edge : edges) {
            if (flags[edge[0]] > 1 && flags[edge[1]] > 1) {
                steps += 2;
            }
        }

        return steps;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> coins = { 1,0,0,0,0,1 };
    vector<vector<int>> edges = { {0,1},{1,2},{2,3},{3,4},{4,5} };
    check.checkInt(2, o.collectTheCoins(coins, edges));

    coins = { 0,0,0,1,1,0,0,1 };
    edges = { {0,1},{0,2},{1,3},{1,4},{2,5},{5,6},{5,7} };
    check.checkInt(2, o.collectTheCoins(coins, edges));

    coins = { 1,1,1,0,0,0,0,0,1,0,0,1,1,0,1,1,0,0,1 };
    edges = { {0,1},{1,2},{2,3},{1,4},{4,5},{5,6},{6,7},{3,8},{6,9},{7,10},{10,11},{10,12},{7,13},{12,14},{13,15},{14,16},{15,17},{10,18} };
    check.checkInt(12, o.collectTheCoins(coins, edges));
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
