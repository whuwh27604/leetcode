/* 图中的最长环.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 n 个节点的 有向图 ，节点编号为 0 到 n - 1 ，其中每个节点 至多 有一条出边。

图用一个大小为 n 下标从 0 开始的数组 edges 表示，节点 i 到节点 edges[i] 之间有一条有向边。如果节点 i 没有出边，那么 edges[i] == -1 。

请你返回图中的 最长 环，如果没有任何环，请返回 -1 。

一个环指的是起点和终点是 同一个 节点的路径。

 

示例 1：



输入：edges = [3,3,4,2,3]
输出去：3
解释：图中的最长环是：2 -> 4 -> 3 -> 2 。
这个环的长度为 3 ，所以返回 3 。
示例 2：



输入：edges = [2,-1,3,1]
输出：-1
解释：图中没有任何环。
 

提示：

n == edges.length
2 <= n <= 105
-1 <= edges[i] < n
edges[i] != i

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-cycle-in-a-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), hop = 1, maxCycle = -1;
        vector<int> hops(n, 0);

        for (int node = 0; node < n; ++node) {
            if (hops[node] == 0) {
                maxCycle = max(maxCycle, getCycle(n, node, hop, edges, hops));
            }
        }

        return maxCycle;
    }

    int getCycle(int n, int node, int& hop, vector<int>& edges, vector<int>& hops) {
        int start = hop;

        while (node != -1) {
            if (hops[node] == 0) {  // 第一次访问
                hops[node] = hop++;
                node = edges[node];
            }
            else {  // 比start大，说明是一个环；比start小，说明是其它路径已经访问过这个点
                return hops[node] >= start ? hop - hops[node] : -1;
            }
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> edges = { 3,3,4,2,3 };
    check.checkInt(3, o.longestCycle(edges));

    edges = { 2,-1,3,1 };
    check.checkInt(-1, o.longestCycle(edges));

    edges = { 23,39,13,19,27,32,48,54,24,36,4,31,55,17,59,49,60,58,57,53,47,30,38,1,41,61,15,29,34,62,18,50,28,44,51,-1,46,6,9,25,8,20,5,44,2,29,42,55,10,11,33,0,29,56,16,22,7,3,63,40,26,37,21,14 };
    check.checkInt(59, o.longestCycle(edges));
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
