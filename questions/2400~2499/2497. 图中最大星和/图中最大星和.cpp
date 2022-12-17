/* 图中最大星和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 n 个点的无向图，节点从 0 到 n - 1 编号。给你一个长度为 n 下标从 0 开始的整数数组 vals ，其中 vals[i] 表示第 i 个节点的值。

同时给你一个二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示节点 ai 和 bi 之间有一条双向边。

星图 是给定图中的一个子图，它包含一个中心节点和 0 个或更多个邻居。换言之，星图是给定图中一个边的子集，且这些边都有一个公共节点。

下图分别展示了有 3 个和 4 个邻居的星图，蓝色节点为中心节点。



星和 定义为星图中所有节点值的和。

给你一个整数 k ，请你返回 至多 包含 k 条边的星图中的 最大星和 。



示例 1：



输入：vals = [1,2,3,4,10,-10,-20], edges = [[0,1],[1,2],[1,3],[3,4],[3,5],[3,6]], k = 2
输出：16
解释：上图展示了输入示例。
最大星和对应的星图在上图中用蓝色标出。中心节点是 3 ，星图中还包含邻居 1 和 4 。
无法得到一个和大于 16 且边数不超过 2 的星图。
示例 2：

输入：vals = [-5], edges = [], k = 0
输出：-5
解释：只有一个星图，就是节点 0 自己。
所以我们返回 -5 。


提示：

n == vals.length
1 <= n <= 105
-104 <= vals[i] <= 104
0 <= edges.length <= min(n * (n - 1) / 2, 105)
edges[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
0 <= k <= n - 1
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size(), maxSum = INT_MIN;
        vector<vector<int>> adjs(n);

        getAdjs(vals, edges, adjs);

        for (int i = 0; i < n; ++i) {
            maxSum = max(maxSum, vals[i] + getSum(adjs[i], k));
        }

        return maxSum;
    }

    void getAdjs(vector<int>& vals, vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            if (vals[node1] > 0) {
                adjs[node2].push_back(vals[node1]);
            }
            if (vals[node2] > 0) {
                adjs[node1].push_back(vals[node2]);
            }
        }
    }

    int getSum(vector<int>& vals, int k) {
        int sum = 0;

        sort(vals.begin(), vals.end(), greater<int>());

        for (int i = 0; i < k && i < (int)vals.size(); ++i) {
            sum += vals[i];
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> vals = { 1,2,3,4,10,-10,-20 };
    vector<vector<int>> edges = { {0,1},{1,2},{1,3},{3,4},{3,5},{3,6} };
    check.checkInt(16, o.maxStarSum(vals, edges, 2));

    vals = { -5 };
    edges = {};
    check.checkInt(-5, o.maxStarSum(vals, edges, 0));
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
