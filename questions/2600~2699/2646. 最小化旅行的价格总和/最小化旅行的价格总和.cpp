/* 最小化旅行的价格总和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
现有一棵无向、无根的树，树中有 n 个节点，按从 0 到 n - 1 编号。给你一个整数 n 和一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条边。

每个节点都关联一个价格。给你一个整数数组 price ，其中 price[i] 是第 i 个节点的价格。

给定路径的 价格总和 是该路径上所有节点的价格之和。

另给你一个二维整数数组 trips ，其中 trips[i] = [starti, endi] 表示您从节点 starti 开始第 i 次旅行，并通过任何你喜欢的路径前往节点 endi 。

在执行第一次旅行之前，你可以选择一些 非相邻节点 并将价格减半。

返回执行所有旅行的最小价格总和。



示例 1：


输入：n = 4, edges = [[0,1],[1,2],[1,3]], price = [2,2,10,6], trips = [[0,3],[2,1],[2,3]]
输出：23
解释：
上图表示将节点 2 视为根之后的树结构。第一个图表示初始树，第二个图表示选择节点 0 、2 和 3 并使其价格减半后的树。
第 1 次旅行，选择路径 [0,1,3] 。路径的价格总和为 1 + 2 + 3 = 6 。
第 2 次旅行，选择路径 [2,1] 。路径的价格总和为 2 + 5 = 7 。
第 3 次旅行，选择路径 [2,1,3] 。路径的价格总和为 5 + 2 + 3 = 10 。
所有旅行的价格总和为 6 + 7 + 10 = 23 。可以证明，23 是可以实现的最小答案。
示例 2：


输入：n = 2, edges = [[0,1]], price = [2,2], trips = [[0,0]]
输出：1
解释：
上图表示将节点 0 视为根之后的树结构。第一个图表示初始树，第二个图表示选择节点 0 并使其价格减半后的树。
第 1 次旅行，选择路径 [0] 。路径的价格总和为 1 。
所有旅行的价格总和为 1 。可以证明，1 是可以实现的最小答案。


提示：

1 <= n <= 50
edges.length == n - 1
0 <= ai, bi <= n - 1
edges 表示一棵有效的树
price.length == n
price[i] 是一个偶数
1 <= price[i] <= 1000
1 <= trips.length <= 100
0 <= starti, endi <= n - 1
*/

#include <iostream>
#include <algorithm>
#include <numeric>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<int> totalPrice(n, 0);
        vector<vector<int>> adjs(n);

        getAdjs(edges, adjs);

        for (auto& trip : trips) {
            if (trip[0] == trip[1]) {
                totalPrice[trip[0]] += price[trip[0]];
            }
            else {
                vector<int> path;
                getPath(trip[0], -1, trip[1], adjs, path);

                for (int node : path) {
                    totalPrice[node] += price[node];
                }
            }
        }

        pair<int, int> maxPrice = getMaxPrice(0, -1, totalPrice, adjs);

        return accumulate(totalPrice.begin(), totalPrice.end(), 0) - max(maxPrice.first, maxPrice.second) / 2;
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
    }

    bool getPath(int node, int parent, int end, vector<vector<int>>& adjs, vector<int>& path) {
        path.push_back(node);

        if (node == end) {
            return true;
        }

        for (int next : adjs[node]) {
            if (next != parent) {
                if (getPath(next, node, end, adjs, path)) {
                    return true;
                }
            }
        }

        path.pop_back();

        return false;
    }

    pair<int, int> getMaxPrice(int node, int parent, vector<int>& totalPrice, vector<vector<int>>& adjs) {
        int chosenPrice = totalPrice[node], nonChosenPrice = 0;

        for (int next : adjs[node]) {
            if (next != parent) {
                pair<int, int> price = getMaxPrice(next, node, totalPrice, adjs);
                chosenPrice += price.second;
                nonChosenPrice += max(price.first, price.second);
            }
        }

        return { chosenPrice, nonChosenPrice };
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {0,1},{1,2},{1,3} };
    vector<int> price = { 2,2,10,6 };
    vector<vector<int>> trips = { {0,3},{2,1},{2,3} };
    check.checkInt(23, o.minimumTotalPrice(4, edges, price, trips));

    edges = { {0,1} };
    price = { 2,2 };
    trips = { {0,0} };
    check.checkInt(1, o.minimumTotalPrice(2, edges, price, trips));
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
