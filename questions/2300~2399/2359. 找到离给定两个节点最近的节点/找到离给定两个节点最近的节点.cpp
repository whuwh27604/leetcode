/* 找到离给定两个节点最近的节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 n 个节点的 有向图 ，节点编号为 0 到 n - 1 ，每个节点 至多 有一条出边。

有向图用大小为 n 下标从 0 开始的数组 edges 表示，表示节点 i 有一条有向边指向 edges[i] 。如果节点 i 没有出边，那么 edges[i] == -1 。

同时给你两个节点 node1 和 node2 。

请你返回一个从 node1 和 node2 都能到达节点的编号，使节点 node1 和节点 node2 到这个节点的距离 较大值最小化。如果有多个答案，请返回 最小 的节点编号。如果答案不存在，返回 -1 。

注意 edges 可能包含环。

 

示例 1：



输入：edges = [2,2,3,-1], node1 = 0, node2 = 1
输出：2
解释：从节点 0 到节点 2 的距离为 1 ，从节点 1 到节点 2 的距离为 1 。
两个距离的较大值为 1 。我们无法得到一个比 1 更小的较大值，所以我们返回节点 2 。
示例 2：



输入：edges = [1,2,-1], node1 = 0, node2 = 2
输出：2
解释：节点 0 到节点 2 的距离为 2 ，节点 2 到它自己的距离为 0 。
两个距离的较大值为 2 。我们无法得到一个比 2 更小的较大值，所以我们返回节点 2 。
 

提示：

n == edges.length
2 <= n <= 105
-1 <= edges[i] < n
edges[i] != i
0 <= node1, node2 < n

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-closest-node-to-given-two-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> distance1(n, -1), distance2(n, -1);

        getDistance(n, node1, edges, distance1);
        getDistance(n, node2, edges, distance2);

        return getClosestMeetingNode(n, distance1, distance2);
    }

    void getDistance(int n, int node, vector<int>& edges, vector<int>& distance) {
        int dist = 1, next = edges[node];
        vector<int> visited(n, false);
        visited[node] = true;
        distance[node] = 0;

        while (next != -1 && !visited[next]) {
            distance[next] = dist++;
            visited[next] = true;
            next = edges[next];
        }
    }

    int getClosestMeetingNode(int n, vector<int>& distance1, vector<int>& distance2) {
        int minNode = -1, minDist = n;

        for (int node = 0; node < n; ++node) {
            if (distance1[node] == -1 || distance2[node] == -1) {
                continue;
            }

            int dist = max(distance1[node], distance2[node]);
            if (dist < minDist) {
                minDist = dist;
                minNode = node;
            }
        }

        return minNode;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> edges = { 2,2,3,-1 };
    check.checkInt(2, o.closestMeetingNode(edges, 0, 1));

    edges = { 1,2,-1 };
    check.checkInt(2, o.closestMeetingNode(edges, 0, 2));
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
