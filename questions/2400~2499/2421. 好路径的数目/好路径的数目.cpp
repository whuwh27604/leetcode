// 好路径的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <unordered_map>
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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size(), goodPaths = n;
        int maxValue = *max_element(vals.begin(), vals.end());
        vector<vector<int>> valueNodes(maxValue + 1), adjs(n);
        DSU dsu(n);

        getValueNodes(n, vals, valueNodes);
        getAdjs(vals, edges, adjs);

        for (auto& valNodes : valueNodes) {  // 按从小到大的顺序遍历value，这样只用考虑当前value，比当前value小的节点之间不可能构成goodPath
            if (!valNodes.empty()) {
                for (int node : valNodes) {
                    for (int adj : adjs[node]) {
                        dsu.merge(node, adj);  // 将value比自己小的node连通
                    }
                }

                unordered_map<int, int> setNodeCount;

                for (int node : valNodes) {
                    ++setNodeCount[dsu.find(node)];  // 节点所在集合的节点个数计数
                }

                for (auto& count : setNodeCount) {
                    goodPaths += (count.second - 1) * count.second / 2;  // 在同一集合内的相同value节点之间构成一个goodPath
                }
            }
        }

        return goodPaths;
    }

    void getValueNodes(int n, vector<int>& vals, vector<vector<int>>& valueNodes) {
        for (int node = 0; node < n; ++node) {
            valueNodes[vals[node]].push_back(node);
        }
    }

    void getAdjs(vector<int>& vals, vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            if (vals[edge[0]] >= vals[edge[1]]) {  // 节点value从大到小的方向可达
                adjs[edge[0]].push_back(edge[1]);
            }
            else {
                adjs[edge[1]].push_back(edge[0]);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> vals = { 1,3,2,1,3 };
    vector<vector<int>> edges = { {0,1},{0,2},{2,3},{2,4} };
    check.checkInt(6, o.numberOfGoodPaths(vals, edges));

    vals = { 1,1,2,2,3 };
    edges = { {0,1},{1,2},{2,3},{2,4} };
    check.checkInt(7, o.numberOfGoodPaths(vals, edges));

    vals = { 1 };
    edges = {};
    check.checkInt(1, o.numberOfGoodPaths(vals, edges));
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
