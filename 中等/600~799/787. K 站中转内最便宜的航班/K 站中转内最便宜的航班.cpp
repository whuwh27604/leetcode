/* K 站中转内最便宜的航班.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 n 个城市通过 m 个航班连接。每个航班都从城市 u 开始，以价格 w 抵达 v。

现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，你的任务是找到从 src 到 dst 最多经过 k 站中转的最便宜的价格。 如果没有这样的路线，则输出 -1。

 

示例 1：

输入:
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
输出: 200
解释:
城市航班图如下


从城市 0 到城市 2 在 1 站中转以内的最便宜价格是 200，如图中红色所示。
示例 2：

输入:
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
输出: 500
解释:
城市航班图如下


从城市 0 到城市 2 在 0 站中转以内的最便宜价格是 500，如图中蓝色所示。
 

提示：

n 范围是 [1, 100]，城市标签从 0 到 n - 1.
航班数量范围是 [0, n * (n - 1) / 2].
每个航班的格式 (src, dst, price).
每个航班的价格范围是 [1, 10000].
k 范围是 [0, n - 1].
航班没有重复，且不存在环路

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cheapest-flights-within-k-stops
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int dst;
    int price;
    int hops;
    Node() : dst(0), price(0), hops(0) {};
    Node(int _dst, int _price, int _hops) : dst(_dst), price(_price), hops(_hops) {};
    bool operator<(const Node& o) const {
        return price > o.price;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // Dijkstra算法，从价格最低的开始遍历，超过跳数的分支裁剪掉，第一次找到dst就是最优解
        unordered_map<int, vector<pair<int, int>>> fromTosPrice;
        hashFlights(flights, fromTosPrice);

        vector<list<pair<int, int>>> minPriceHops(n, { {INT_MAX,INT_MAX} });  // 从src到各个站点的相对最低价格跳数
        minPriceHops[src] = { {0,0} };

        priority_queue<Node> dijkstra;  // 使用优先队列，每次选出价格最低的站点拓展下一个
        Node node(src, 0, -1);
        dijkstra.push(node);

        while (!dijkstra.empty()) {
            Node from = dijkstra.top();  // 每次取出队列首部，即price最低的开始遍历
            dijkstra.pop();

            if (from.hops > K) {
                continue;  // 中转次数超过K，跳过
            }

            if (from.dst == dst) {
                return from.price;
            }

            auto iter = fromTosPrice.find(from.dst);
            if (iter == fromTosPrice.end()) {
                continue;
            }

            for (pair<int, int>& toPrice : iter->second) {
                Node to(toPrice.first, from.price + toPrice.second, from.hops + 1);
                if (updateMinPrice(to, minPriceHops)) {
                    minPriceHops[to.dst].push_back({ to.price, to.hops });
                    dijkstra.push(to);
                }
            }
        }

        return -1;
    }

    bool updateMinPrice(Node to, vector<list<pair<int, int>>>& minPriceHops) {
        bool need = true;
        auto iter = minPriceHops[to.dst].begin();
        while (iter != minPriceHops[to.dst].end()) {
            if ((to.price >= (*iter).first) && (to.hops >= (*iter).second)) {
                need = false;  // 已经存在一个price和hops都较小的，当前路径不需要再拓展
                break;
            }

            if ((to.price <= (*iter).first) && (to.hops <= (*iter).second)) {
                iter = minPriceHops[to.dst].erase(iter);  // 把price和hops都更大的路径删掉
            }
            else {
                iter++;
            }
        }

        return need;
    }

    void hashFlights(vector<vector<int>>& flights, unordered_map<int, vector<pair<int, int>>>& fromTosPrice) {
        for (vector<int>& flight : flights) {
            auto iter = fromTosPrice.find(flight[0]);
            if (iter == fromTosPrice.end()) {
                fromTosPrice[flight[0]] = { {flight[1], flight[2]} };
            }
            else {
                iter->second.push_back({ flight[1], flight[2] });
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> flights = { {0,1,100},{1,2,100},{0,2,500} };
    check.checkInt(200, o.findCheapestPrice(3, flights, 0, 2, 1));

    flights = { {0,1,100},{1,2,100},{0,2,500} };
    check.checkInt(500, o.findCheapestPrice(3, flights, 0, 2, 0));

    flights = { {0,1,100},{1,2,100},{0,2,500} };
    check.checkInt(0, o.findCheapestPrice(3, flights, 0, 0, 0));

    flights = { {0,1,2},{1,2,1},{2,0,10} };
    check.checkInt(1, o.findCheapestPrice(3, flights, 1, 2, 1));

    flights = { {0,1,5},{1,2,5},{0,3,2},{3,1,2},{1,4,1},{4,2,1} };
    check.checkInt(7, o.findCheapestPrice(5, flights, 0, 2, 2));
    check.checkInt(6, o.findCheapestPrice(5, flights, 0, 2, 3));

    flights = { {0,1,1},{0,2,5},{1,2,1},{2,3,1} };
    check.checkInt(6, o.findCheapestPrice(4, flights, 0, 3, 1));
    check.checkInt(-1, o.findCheapestPrice(4, flights, 0, 3, 0));
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
