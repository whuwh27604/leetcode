/* 得到要求路径的最小带权子图.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n ，它表示一个 带权有向 图的节点数，节点编号为 0 到 n - 1 。

同时给你一个二维整数数组 edges ，其中 edges[i] = [fromi, toi, weighti] ，表示从 fromi 到 toi 有一条边权为 weighti 的 有向 边。

最后，给你三个 互不相同 的整数 src1 ，src2 和 dest ，表示图中三个不同的点。

请你从图中选出一个 边权和最小 的子图，使得从 src1 和 src2 出发，在这个子图中，都 可以 到达 dest 。如果这样的子图不存在，请返回 -1 。

子图 中的点和边都应该属于原图的一部分。子图的边权和定义为它所包含的所有边的权值之和。

 

示例 1：



输入：n = 6, edges = [[0,2,2],[0,5,6],[1,0,3],[1,4,5],[2,1,1],[2,3,3],[2,3,4],[3,4,2],[4,5,1]], src1 = 0, src2 = 1, dest = 5
输出：9
解释：
上图为输入的图。
蓝色边为最优子图之一。
注意，子图 [[1,0,3],[0,5,6]] 也能得到最优解，但无法在满足所有限制的前提下，得到更优解。
示例 2：



输入：n = 3, edges = [[0,1,1],[2,1,1]], src1 = 0, src2 = 1, dest = 2
输出：-1
解释：
上图为输入的图。
可以看到，不存在从节点 1 到节点 2 的路径，所以不存在任何子图满足所有限制。
 

提示：

3 <= n <= 105
0 <= edges.length <= 105
edges[i].length == 3
0 <= fromi, toi, src1, src2, dest <= n - 1
fromi != toi
src1 ，src2 和 dest 两两不同。
1 <= weight[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-weighted-subgraph-with-the-required-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

struct pairCompare {
    bool operator()(const pair<int, long long>& p1, const pair<int, long long>& p2) const {
        return p1.second > p2.second;  // 每次选出weight最小的
    }
};

class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, long long>>> adjs(n), reverseAdjs(n);
        long long inf = LLONG_MAX / 10;
        vector<long long> src1MinWeights(n, inf), src2MinWeights(n, inf), destMinWeights(n, inf);

        getAdjs(edges, adjs, reverseAdjs);
        dijkstra(adjs, src1, src1MinWeights);
        dijkstra(adjs, src2, src2MinWeights);
        dijkstra(reverseAdjs, dest, destMinWeights);

        return getMinWeight(n, src1MinWeights, src2MinWeights, destMinWeights);
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<pair<int, long long>>>& adjs, vector<vector<pair<int, long long>>>& reverseAdjs) {
        for (auto& edge : edges) {
            int from = edge[0], to = edge[1], weight = edge[2];
            adjs[from].push_back({ to, weight });
            reverseAdjs[to].push_back({ from, weight });
        }
    }

    void dijkstra(vector<vector<pair<int, long long>>>& adjs, int root, vector<long long>& minWeights) {
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, pairCompare> nodes;
        nodes.push({ root, 0 });
        minWeights[root] = 0;

        while (!nodes.empty()) {
            int node = nodes.top().first;
            long long weight = nodes.top().second;
            nodes.pop();

            if (weight > minWeights[node]) {  // 在同一轮次，可能按照weight从大到小的顺序放入了多个node，只有最小的一个是有效的
                continue;
            }

            for (auto& next : adjs[node]) {
                long long nextWeight = weight + next.second;

                if (nextWeight < minWeights[next.first]) {
                    nodes.push({ next.first, nextWeight });
                    minWeights[next.first] = nextWeight;
                }
            }
        }
    }

    long long getMinWeight(int n, vector<long long>& src1MinWeights, vector<long long>& src2MinWeights, vector<long long>& destMinWeights) {
        long long inf = LLONG_MAX / 10, minWeight = inf;

        for (int i = 0; i < n; ++i) {  // 枚举每一个分叉点，找路径之和的最小值
            minWeight = min(minWeight, src1MinWeights[i] + src2MinWeights[i] + destMinWeights[i]);
        }

        return minWeight >= inf ? -1 : minWeight;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {0,2,2},{0,5,6},{1,0,3},{1,4,5},{2,1,1},{2,3,3},{2,3,4},{3,4,2},{4,5,1} };
    check.checkLongLong(9, o.minimumWeight(6, edges, 0, 1, 5));

    edges = { {0,1,1},{2,1,1} };
    check.checkLongLong(-1, o.minimumWeight(3, edges, 0, 1, 2));

    edges = { {4,2,20},{4,3,46},{0,1,15},{0,1,43},{0,1,32},{3,1,13} };
    check.checkLongLong(74, o.minimumWeight(5, edges, 0, 4, 1));

    edges = getIntVectorVector("./testcase1.txt");
    check.checkLongLong(50003, o.minimumWeight(50000, edges, 8060, 44777, 39592));
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
