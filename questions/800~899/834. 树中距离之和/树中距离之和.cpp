/* 树中距离之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个无向、连通的树。树中有 N 个标记为 0...N-1 的节点以及 N-1 条边 。

第 i 条边连接节点 edges[i][0] 和 edges[i][1] 。

返回一个表示节点 i 与其他所有节点距离之和的列表 ans。

示例 1:

输入: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
输出: [8,12,6,10,10,10]
解释:
如下为给定的树的示意图：
  0
 / \
1   2
   /|\
  3 4 5

我们可以计算出 dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
也就是 1 + 1 + 2 + 2 + 2 = 8。 因此，answer[0] = 8，以此类推。
说明: 1 <= N <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-distances-in-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<int> distanceSums(N, 0);
        if (N == 1) {
            return distanceSums;
        }

        vector<vector<int>> peers(N, vector<int>{});
        buildPeerTable(edges, peers);

        vector<int> childrens(N, 0);
        (void)getChildrens(0, -1, 0, peers, distanceSums[0], childrens);

        allNodesDistanceSums(N, 0, -1, peers, childrens, distanceSums);

        return distanceSums;
    }

    void buildPeerTable(vector<vector<int>>& edges, vector<vector<int>>& peers) {
        for (vector<int>& edge : edges) {
            peers[edge[0]].push_back(edge[1]);
            peers[edge[1]].push_back(edge[0]);
        }
    }

    int getChildrens(int node, int parent, int distance, vector<vector<int>>& peers, int& sum, vector<int>& childrens) {
        sum += distance;  // 顺带求出node0的距离和
        int children = 0;

        for (int peer : peers[node]) {  // DFS求所有节点的children数
            if (peer != parent) {  // 不走回头路
                children += (getChildrens(peer, node, distance + 1, peers, sum, childrens) + 1);
            }
        }

        childrens[node] = children;
        return children;
    }

    void allNodesDistanceSums(int N, int node, int parent, vector<vector<int>>& peers, vector<int>& childrens, vector<int>& distanceSums) {
        int children = childrens[node];

        for (int peer : peers[node]) {  // DFS求每个节点的距离和
            if (peer != parent) {
                if (parent != -1) {
                    int otherChildren = N - children - 2;  // 关键是要想明白node的距离和、children个数、父节点的距离和、父节点另外一半children个数之间的关系
                    distanceSums[node] = distanceSums[parent] - children + otherChildren;
                }

                allNodesDistanceSums(N, peer, node, peers, childrens, distanceSums);
            }
        }

        if (distanceSums[node] == 0) {  // 没有下一跳，是个叶子节点
            distanceSums[node] = distanceSums[parent] + N - 2;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {0,1},{0,2},{2,3},{2,4},{2,5} };
    vector<int> actual = o.sumOfDistancesInTree(6, edges);
    vector<int> expected = { 8,12,6,10,10,10 };
    check.checkIntVector(expected, actual);

    edges = {  };
    actual = o.sumOfDistancesInTree(1, edges);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    edges = { {0,1} };
    actual = o.sumOfDistancesInTree(2, edges);
    expected = { 1,1 };
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
