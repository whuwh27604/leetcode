/* 尽量减少恶意软件的传播 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
(这个问题与 尽量减少恶意软件的传播 是一样的，不同之处用粗体表示。)

在节点网络中，只有当 graph[i][j] = 1 时，每个节点 i 能够直接连接到另一个节点 j。

一些节点 initial 最初被恶意软件感染。只要两个节点直接连接，且其中至少一个节点受到恶意软件的感染，那么两个节点都将被恶意软件感染。这种恶意软件的传播将继续，直到没有更多的节点可以被这种方式感染。

假设 M(initial) 是在恶意软件停止传播之后，整个网络中感染恶意软件的最终节点数。

我们可以从初始列表中删除一个节点，并完全移除该节点以及从该节点到任何其他节点的任何连接。如果移除这一节点将最小化 M(initial)， 则返回该节点。如果有多个节点满足条件，就返回索引最小的节点。

 

示例 1：

输出：graph = [[1,1,0],[1,1,0],[0,0,1]], initial = [0,1]
输入：0
示例 2：

输入：graph = [[1,1,0],[1,1,1],[0,1,1]], initial = [0,1]
输出：1
示例 3：

输入：graph = [[1,1,0,0],[1,1,1,0],[0,1,1,1],[0,0,1,1]], initial = [0,1]
输出：1
 

提示：

1 < graph.length = graph[0].length <= 300
0 <= graph[i][j] == graph[j][i] <= 1
graph[i][i] = 1
1 <= initial.length < graph.length
0 <= initial[i] < graph.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimize-malware-spread-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int node, size = graph.size();
        vector<bool> visited(size, false), malwares(size, false);
        vector<int> avoids(size, 0);

        getMalwares(initial, malwares);

        for (node = 0; node < size; ++node) {
            if (visited[node] || malwares[node]) {
                continue;
            }

            int setSize = 0;
            unordered_set<int> malwaresInSet;

            DFS(graph, malwares, visited, node, setSize, malwaresInSet);
            if (malwaresInSet.size() == 1) {
                avoids[*malwaresInSet.begin()] += setSize;
            }
        }

        int minMalwareNode = getMinMalwareNode(avoids);
        return minMalwareNode == size ? *min_element(initial.begin(), initial.end()) : minMalwareNode;
    }

    void getMalwares(vector<int>& initial, vector<bool>& malwares) {
        for (int malware : initial) {
            malwares[malware] = true;
        }
    }

    void DFS(vector<vector<int>>& graph, vector<bool>& malwares, vector<bool>& visited, int node, int& setSize, unordered_set<int>& malwaresInSet) {
        ++setSize;
        visited[node] = true;

        for (int next = 0; next < (int)graph.size(); ++next) {
            if (next == node || graph[node][next] == 0 || visited[next]) {
                continue;
            }

            if (malwares[next]) {
                malwaresInSet.insert(next);
                continue;
            }

            DFS(graph, malwares, visited, next, setSize, malwaresInSet);
        }
    }

    int getMinMalwareNode(vector<int>& avoids) {
        int node, size = avoids.size(), maxAvoid = 1, MinMalwareNode = size;

        for (node = 0; node < size; ++node) {
            if (avoids[node] > maxAvoid) {
                maxAvoid = avoids[node];
                MinMalwareNode = node;
            }
            else if (avoids[node] == maxAvoid) {
                MinMalwareNode = min(MinMalwareNode, node);
            }
        }

        return MinMalwareNode;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> graph = { {1,1,0},{1,1,0},{0,0,1} };
    vector<int> initial = { 0,1 };
    check.checkInt(0, o.minMalwareSpread(graph, initial));

    graph = { {1,1,0},{1,1,1},{0,1,1} };
    initial = { 0,1 };
    check.checkInt(1, o.minMalwareSpread(graph, initial));

    graph = { {1,1,0,0},{1,1,1,0},{0,1,1,1},{0,0,1,1} };
    initial = { 0,1 };
    check.checkInt(1, o.minMalwareSpread(graph, initial));

    graph = { {1,0,0},{0,1,0},{0,0,1} };
    initial = { 0,2 };
    check.checkInt(0, o.minMalwareSpread(graph, initial));

    graph = { {1,1,1},{1,1,1},{1,1,1} };
    initial = { 1,2 };
    check.checkInt(1, o.minMalwareSpread(graph, initial));

    graph = { {1,0,0,0},{0,1,0,0},{0,0,1,1},{0,0,1,1} };
    initial = { 3,1 };
    check.checkInt(3, o.minMalwareSpread(graph, initial));

    graph = { {1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,1,0},{0,0,0,1,1,0},{0,0,0,0,0,1} };
    initial = { 5,0 };
    check.checkInt(0, o.minMalwareSpread(graph, initial));

    graph = { {1,0,0,0,1,0,0,0},{0,1,1,0,0,1,0,0},{0,1,1,0,1,0,0,0},{0,0,0,1,1,0,0,0},{1,0,1,1,1,0,0,1},{0,1,0,0,0,1,0,0},{0,0,0,0,0,0,1,1},{0,0,0,0,1,0,1,1} };
    initial = { 7,2 };
    check.checkInt(2, o.minMalwareSpread(graph, initial));

    graph = { {1,0,0,0,0,0,0,0,1} ,{0,1,0,1,0,0,0,0,0},{0,0,1,1,0,1,0,0,0},{0,1,1,1,1,0,1,0,0},{0,0,0,1,1,1,0,0,0},{0,0,1,0,1,1,0,0,0},{0,0,0,1,0,0,1,1,0},{0,0,0,0,0,0,1,1,1},{1,0,0,0,0,0,0,1,1} };
    initial = { 3,7 };
    check.checkInt(3, o.minMalwareSpread(graph, initial));
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
