/* 尽量减少恶意软件的传播.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在节点网络中，只有当 graph[i][j] = 1 时，每个节点 i 能够直接连接到另一个节点 j。

一些节点 initial 最初被恶意软件感染。只要两个节点直接连接，且其中至少一个节点受到恶意软件的感染，那么两个节点都将被恶意软件感染。这种恶意软件的传播将继续，直到没有更多的节点可以被这种方式感染。

假设 M(initial) 是在恶意软件停止传播之后，整个网络中感染恶意软件的最终节点数。

我们可以从初始列表中删除一个节点。如果移除这一节点将最小化 M(initial)， 则返回该节点。如果有多个节点满足条件，就返回索引最小的节点。

请注意，如果某个节点已从受感染节点的列表 initial 中删除，它以后可能仍然因恶意软件传播而受到感染。

 

示例 1：

输入：graph = [[1,1,0],[1,1,0],[0,0,1]], initial = [0,1]
输出：0
示例 2：

输入：graph = [[1,0,0],[0,1,0],[0,0,1]], initial = [0,2]
输出：0
示例 3：

输入：graph = [[1,1,1],[1,1,1],[1,1,1]], initial = [1,2]
输出：1
 

提示：

1 < graph.length = graph[0].length <= 300
0 <= graph[i][j] == graph[j][i] <= 1
graph[i][i] == 1
1 <= initial.length < graph.length
0 <= initial[i] < graph.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimize-malware-spread
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class DSU {
public:
    DSU(int size) {
        parents.resize(size);

        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    void merge(int x, int y) {
        parents[find(x)] = find(y);
    }

private:
    vector<int> parents;
};

class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int size = graph.size();

        DSU dsu(size);
        merge(graph, dsu, size);

        vector<int> setIds(size);
        vector<int> setCaps(size, 0);
        getSetIdCaps(dsu, setIds, setCaps, size);

        unordered_map<int, vector<int>> malwares;
        getMalwaresEachSet(initial, setIds, malwares);

        int minMalware = getMinMalware(malwares, setCaps, size);
        return minMalware < size ? minMalware : *min_element(initial.begin(), initial.end());
    }

    void merge(vector<vector<int>>& graph, DSU& dsu, int size) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (i != j && graph[i][j] == 1) {
                    dsu.merge(i, j);
                }
            }
        }
    }

    void getSetIdCaps(DSU& dsu, vector<int>& setIds, vector<int>& setCaps, int size) {
        for (int node = 0; node < size; ++node) {
            int setId = dsu.find(node);
            setIds[node] = setId;
            ++setCaps[setId];
        }
    }

    void getMalwaresEachSet(vector<int>& initial, vector<int>& setIds, unordered_map<int, vector<int>>& malwares) {
        for (int malware : initial) {
            malwares[setIds[malware]].push_back(malware);
        }
    }

    int getMinMalware(unordered_map<int, vector<int>>& malwares, vector<int>& setCaps, int size) {
        int minMalware = size, spread = 0;

        for (auto iter = malwares.begin(); iter != malwares.end(); ++iter) {
            if (iter->second.size() == 1) {  // 一个集合里面只有一个病毒，去掉它才有意义，多于一个病毒，去掉后还是会全部被感染
                if (spread < setCaps[iter->first]) {
                    spread = setCaps[iter->first];
                    minMalware = iter->second[0];
                }
                else if (spread == setCaps[iter->first]) {
                    minMalware = min(minMalware, iter->second[0]);
                }
            }
        }

        return minMalware;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> graph = { {1,1,0},{1,1,0},{0,0,1} };
    vector<int> initial = { 0,1 };
    check.checkInt(0, o.minMalwareSpread(graph, initial));

    graph = { {1,0,0},{0,1,0},{0,0,1} };
    initial = { 0,2 };
    check.checkInt(0, o.minMalwareSpread(graph, initial));

    graph = { {1,1,1},{1,1,1},{1,1,1} };
    initial = { 1,2 };
    check.checkInt(1, o.minMalwareSpread(graph, initial));

    graph = { {1,1,0},{1,1,0},{0,0,1} };
    initial = { 0,1,2 };
    check.checkInt(2, o.minMalwareSpread(graph, initial));

    graph = { {1,0,0,0},{0,1,0,0},{0,0,1,1},{0,0,1,1} };
    initial = { 3,1 };
    check.checkInt(3, o.minMalwareSpread(graph, initial));

    graph = { {1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,1,0},{0,0,0,1,1,0},{0,0,0,0,0,1} };
    initial = { 5,0 };
    check.checkInt(0, o.minMalwareSpread(graph, initial));

    graph = { {1,0,0,0,1,0,0,0},{0,1,1,0,0,1,0,0},{0,1,1,0,1,0,0,0},{0,0,0,1,1,0,0,0},{1,0,1,1,1,0,0,1},{0,1,0,0,0,1,0,0},{0,0,0,0,0,0,1,1},{0,0,0,0,1,0,1,1} };
    initial = { 7,2 };
    check.checkInt(2, o.minMalwareSpread(graph, initial));

    graph = { {1} };
    initial = { 0 };
    check.checkInt(0, o.minMalwareSpread(graph, initial));
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
