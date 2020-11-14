/* 判断二分图.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个无向图graph，当这个图为二分图时返回true。

如果我们能将一个图的节点集合分割成两个独立的子集A和B，并使图中的每一条边的两个节点一个来自A集合，一个来自B集合，我们就将这个图称为二分图。

graph将会以邻接表方式给出，graph[i]表示图中与节点i相连的所有节点。每个节点都是一个在0到graph.length-1之间的整数。这图中没有自环和平行边： graph[i] 中不存在i，并且graph[i]中没有重复的值。


示例 1:
输入: [[1,3], [0,2], [1,3], [0,2]]
输出: true
解释:
无向图如下:
0----1
|    |
|    |
3----2
我们可以将节点分成两组: {0, 2} 和 {1, 3}。

示例 2:
输入: [[1,2,3], [0,2], [0,1,3], [0,2]]
输出: false
解释:
无向图如下:
0----1
| \  |
|  \ |
3----2
我们不能将节点分割成两个独立的子集。
注意:

graph 的长度范围为 [1, 100]。
graph[i] 中的元素的范围为 [0, graph.length - 1]。
graph[i] 不会包含 i 或者有重复的值。
图是无向的: 如果j 在 graph[i]里边, 那么 i 也会在 graph[j]里边。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/is-graph-bipartite
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set<int> remainingPoints;
        for (int i = 0; i < (int)graph.size(); i++) {
            remainingPoints.insert(i);
        }

        unordered_map<int, int> pointGroups;
        while (!remainingPoints.empty()) {  // 处理多组不连通的图
            int point = *(remainingPoints.begin());
            if (!canSplit(graph, pointGroups, point, remainingPoints)) {
                return false;
            }
        }

        return true;
    }

    bool canSplit(vector<vector<int>>& graph, unordered_map<int, int>& pointGroups, int originalPoint, unordered_set<int>& remainingPoints) {
        int group = 0;
        list<int> points;  // BFS遍历图
        points.push_back(originalPoint);

        while (!points.empty()) {
            group ^= 1;  // group在0，1之间交替
            int size = points.size();

            for (int i = 0; i < size; i++) {
                int point = points.front();
                points.pop_front();
                remainingPoints.erase(point);
                auto iter = pointGroups.find(point);
                if (iter != pointGroups.end()) {
                    if (iter->second != group) {  // point已经被分到另外一组，冲突
                        return false;
                    }
                    else {
                        continue;
                    }
                }
                pointGroups[point] = group;  // 当前深度的节点分到一组

                for (int peerPoint : graph[point]) {
                    points.push_back(peerPoint);  // 当前节点的对端分到另一组
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> graph = { {1,3},{0,2},{1,3},{0,2} };
    check.checkBool(true, o.isBipartite(graph));

    graph = { {1,2,3},{0,2},{0,1,3},{0,2} };
    check.checkBool(false, o.isBipartite(graph));

    graph = { {} };
    check.checkBool(true, o.isBipartite(graph));

    graph = { {},{} };
    check.checkBool(true, o.isBipartite(graph));

    graph = { {1},{0} };
    check.checkBool(true, o.isBipartite(graph));

    graph = { {1},{0,2},{1} };
    check.checkBool(true, o.isBipartite(graph));

    graph = { {1,2},{0,2},{0,1} };
    check.checkBool(false, o.isBipartite(graph));

    graph = { {1,2,3,4,5},{0},{0},{0},{0},{0} };
    check.checkBool(true, o.isBipartite(graph));

    graph = { {1,2,3,4,5},{0},{0},{0},{0},{0},{},{},{9},{8} };
    check.checkBool(true, o.isBipartite(graph));

    graph = { {1,2,3,4,5},{0},{0},{0},{0},{0},{},{},{9},{8},{11,12},{10,12},{10,11} };
    check.checkBool(false, o.isBipartite(graph));

    graph = { {1,2},{0,3,4},{0,5},{1},{1},{2} };
    check.checkBool(true, o.isBipartite(graph));

    graph = { {1,2,4},{0,3,4},{0,5},{1},{0,1},{2} };
    check.checkBool(false, o.isBipartite(graph));
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
