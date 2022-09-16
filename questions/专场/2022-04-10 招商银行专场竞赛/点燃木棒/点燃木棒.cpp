// 点燃木棒.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> lightSticks(int height, int width, vector<int>& indices) {
        int sticks = (width * 2 + 1) * height + width, nodes = (width + 1) * (height + 1), minTime = nodes;
        vector<bool> exists(sticks, true);
        vector<vector<int>> adjs(nodes);
        vector<bool> visited(nodes, false);
        vector<int> ans;

        isExist(indices, exists);
        getAdjs(height, width, nodes, exists, adjs);
        int connected = getConnected(nodes, adjs, visited);
        DFS(connected, adjs, visited);  // 随便找一个连通的点跑DFS

        for (bool visit : visited) {
            if (!visit) {  // 如果没有访问到所有点，说明火柴不能燃尽
                return ans;
            }
        }

        for (int node = 0; node < nodes; ++node) {
            if (!adjs[node].empty()) {
                int time = BFS(node, nodes, adjs);

                if (time == minTime) {
                    ans.push_back(node);
                }
                else if (time < minTime) {
                    minTime = time;
                    ans = { node };
                }
            }
        }

        return ans;
    }

    void isExist(vector<int>& indices, vector<bool>& exists) {
        for (int index : indices) {
            exists[index] = false;
        }
    }

    void getAdjs(int height, int width, int nodes, vector<bool>& exists, vector<vector<int>>& adjs) {
        int peer, stick;

        for (int node = 0; node < nodes; ++node) {
            if (node % (width + 1) != 0) {
                peer = node - 1;
                stick = node / (width + 1) * (width * 2 + 1) + node % (width + 1) - 1;

                if (exists[stick]) {
                    adjs[node].push_back(peer);
                    adjs[peer].push_back(node);
                }
            }

            if (node % (width + 1) != width) {
                peer = node + 1;
                stick = node / (width + 1) * (width * 2 + 1) + node % (width + 1);

                if (exists[stick]) {
                    adjs[node].push_back(peer);
                    adjs[peer].push_back(node);
                }
            }

            if (node > width) {
                peer = node - width - 1;
                stick = (node / (width + 1) - 1) * (width * 2 + 1) + width + node % (width + 1);

                if (exists[stick]) {
                    adjs[node].push_back(peer);
                    adjs[peer].push_back(node);
                }
            }

            if (node < (width + 1) * height) {
                peer = node + width + 1;
                stick = node / (width + 1) * (width * 2 + 1) + width + node % (width + 1);

                if (exists[stick]) {
                    adjs[node].push_back(peer);
                    adjs[peer].push_back(node);
                }
            }
        }
    }

    int getConnected(int nodes, vector<vector<int>>& adjs, vector<bool>& visited) {
        int connected = -1;

        for (int node = 0; node < nodes; ++node) {
            if (adjs[node].empty()) {
                visited[node] = true;
            }
            else {
                connected = node;
            }
        }

        return connected;
    }

    void DFS(int node, vector<vector<int>>& adjs, vector<bool>& visited) {
        for (int next : adjs[node]) {
            if (!visited[next]) {
                visited[next] = true;
                DFS(next, adjs, visited);
            }
        }
    }

    int BFS(int root, int nodes, vector<vector<int>>& adjs) {
        int time = 0;
        queue<int> q;
        q.push(root);
        vector<bool> visited(nodes, false);
        visited[root] = true;

        while (!q.empty()) {
            ++time;
            int i, size = q.size();

            for (i = 0; i < size; ++i) {
                int node = q.front();
                q.pop();

                for (int next : adjs[node]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }

        return time;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> indices = { 3 };
    vector<int> actual = o.lightSticks(1, 2, indices);
    vector<int> expected = { 0,1,2,3,4,5 };
    check.checkIntVector(expected, actual);

    indices = { 2,5,6,7,8,10,11 };
    actual = o.lightSticks(2, 2, indices);
    expected = { 2 };
    check.checkIntVector(expected, actual);

    indices = { 0,3 };
    actual = o.lightSticks(1, 1, indices);
    expected = {  };
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
