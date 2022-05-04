/* 查找集群内的「关键连接」.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
力扣数据中心有 n 台服务器，分别按从 0 到 n-1 的方式进行了编号。它们之间以「服务器到服务器」点对点的形式相互连接组成了一个内部集群，其中连接 connections 是无向的。从形式上讲，connections[i] = [a, b] 表示服务器 a 和 b 之间形成连接。任何服务器都可以直接或者间接地通过网络到达任何其他服务器。

「关键连接」 是在该集群中的重要连接，也就是说，假如我们将它移除，便会导致某些服务器无法访问其他服务器。

请你以任意顺序返回该集群内的所有 「关键连接」。

 

示例 1：



输入：n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
输出：[[1,3]]
解释：[[3,1]] 也是正确的。
示例 2:

输入：n = 2, connections = [[0,1]]
输出：[[0,1]]
 

提示：

1 <= n <= 10^5
n-1 <= connections.length <= 10^5
connections[i][0] != connections[i][1]
不存在重复的连接

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/critical-connections-in-a-network
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Tarjan {
public:
    Tarjan(int n_, const vector<vector<int>>& adjs_) : \
        n(n_), adjs(adjs_), low(n_, -1), dfn(n_, -1), ts(-1), connected(0) {}

    void getAllCuttingEdges(vector<vector<int>>& cuttingEdges) {
        for (int i = 0; i < n; ++i) {
            if (dfn[i] == -1) {
                ++connected;
                getCuttingEdges(i, -1, cuttingEdges);
            }
        }
    }

    void getCuttingEdges(int vertex, int parentId, vector<vector<int>>& cuttingEdges) {
        low[vertex] = dfn[vertex] = ++ts;

        for (int peer : adjs[vertex]) {
            if (peer == parentId) {
                continue;
            }

            if (dfn[peer] == -1) {
                getCuttingEdges(peer, vertex, cuttingEdges);
                low[vertex] = min(low[vertex], low[peer]);

                if (dfn[vertex] < low[peer]) {
                    cuttingEdges.push_back({ vertex, peer });
                }
            }
            else {
                low[vertex] = min(low[vertex], dfn[peer]);
            }
        }
    }

    int getConnectedComponent() {
        return connected;
    }

private:
    const vector<vector<int>>& adjs;
    vector<int> low;
    vector<int> dfn;
    int n;
    int ts;
    int connected;
};

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjs(n);
        getAdjs(connections, adjs);

        Tarjan tarjan(n, adjs);

        vector<vector<int>> cuttingEdges;
        tarjan.getAllCuttingEdges(cuttingEdges);

        return cuttingEdges;
    }

    void getAdjs(vector<vector<int>>& connections, vector<vector<int>>& adjs) {
        for (auto& connection : connections) {
            adjs[connection[0]].push_back(connection[1]);
            adjs[connection[1]].push_back(connection[0]);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> actual = o.criticalConnections(4,connections);
    vector<vector<int>> expected = {{1,3}};
    check.checkIntVectorRandomVectorRandomOrder(expected,actual);

    connections = {{0,1}};
    actual = o.criticalConnections(2,connections);
    expected = {{0,1}};
    check.checkIntVectorRandomVectorRandomOrder(expected,actual);

    connections = {{1,0},{2,0},{3,2},{4,2},{4,3},{3,0},{4,0}};
    actual = o.criticalConnections(5,connections);
    expected = {{0,1}};
    check.checkIntVectorRandomVectorRandomOrder(expected, actual);
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
