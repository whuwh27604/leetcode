/* 最大合金数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
假设你是一家合金制造公司的老板，你的公司使用多种金属来制造合金。现在共有 n 种不同类型的金属可以使用，并且你可以使用 k 台机器来制造合金。每台机器都需要特定数量的每种金属来创建合金。

对于第 i 台机器而言，创建合金需要 composition[i][j] 份 j 类型金属。最初，你拥有 stock[i] 份 i 类型金属，而每购入一份 i 类型金属需要花费 cost[i] 的金钱。

给你整数 n、k、budget，下标从 1 开始的二维数组 composition，两个下标从 1 开始的数组 stock 和 cost，请你在预算不超过 budget 金钱的前提下，最大化 公司制造合金的数量。

所有合金都需要由同一台机器制造。

返回公司可以制造的最大合金数。



示例 1：

输入：n = 3, k = 2, budget = 15, composition = [[1,1,1],[1,1,10]], stock = [0,0,0], cost = [1,2,3]
输出：2
解释：最优的方法是使用第 1 台机器来制造合金。
要想制造 2 份合金，我们需要购买：
- 2 份第 1 类金属。
- 2 份第 2 类金属。
- 2 份第 3 类金属。
总共需要 2 * 1 + 2 * 2 + 2 * 3 = 12 的金钱，小于等于预算 15 。
注意，我们最开始时候没有任何一类金属，所以必须买齐所有需要的金属。
可以证明在示例条件下最多可以制造 2 份合金。
示例 2：

输入：n = 3, k = 2, budget = 15, composition = [[1,1,1],[1,1,10]], stock = [0,0,100], cost = [1,2,3]
输出：5
解释：最优的方法是使用第 2 台机器来制造合金。
要想制造 5 份合金，我们需要购买：
- 5 份第 1 类金属。
- 5 份第 2 类金属。
- 0 份第 3 类金属。
总共需要 5 * 1 + 5 * 2 + 0 * 3 = 15 的金钱，小于等于预算 15 。
可以证明在示例条件下最多可以制造 5 份合金。
示例 3：

输入：n = 2, k = 3, budget = 10, composition = [[2,1],[1,2],[1,1]], stock = [1,1], cost = [5,5]
输出：2
解释：最优的方法是使用第 3 台机器来制造合金。
要想制造 2 份合金，我们需要购买：
- 1 份第 1 类金属。
- 1 份第 2 类金属。
总共需要 1 * 5 + 1 * 5 = 10 的金钱，小于等于预算 10 。
可以证明在示例条件下最多可以制造 2 份合金。


提示：

1 <= n, k <= 100
0 <= budget <= 108
composition.length == k
composition[i].length == n
1 <= composition[i][j] <= 100
stock.length == cost.length == n
0 <= stock[i] <= 108
1 <= cost[i] <= 100
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int maxAlloys = 0;

        for (int i = 0; i < k; ++i) {
            maxAlloys = max(maxAlloys, getAlloys(n, budget, composition[i], stock, cost));
        }

        return maxAlloys;
    }

    int getAlloys(int n, int budget, vector<int>& composition, vector<int>& stock, vector<int>& cost) {
        long long low = 0, high = INT_MAX, alloys = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;
            if (check(mid, n, budget, composition, stock, cost)) {
                alloys = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return (int)alloys;
    }

    bool check(long long alloys, int n, int budget, vector<int>& composition, vector<int>& stock, vector<int>& cost) {
        long long sum = 0;

        for (int i = 0; i < n; ++i) {
            if (composition[i] * alloys > stock[i]) {
                sum += (composition[i] * alloys - stock[i]) * cost[i];
            }
        }

        return sum <= budget;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> composition = { {1,1,1},{1,1,10} };
    vector<int> stock = { 0,0,0 };
    vector<int> cost = { 1,2,3 };
    check.checkInt(2, o.maxNumberOfAlloys(3, 2, 15, composition, stock, cost));

    composition = { {1,1,1},{1,1,10} };
    stock = { 0,0,100 };
    cost = { 1,2,3 };
    check.checkInt(5, o.maxNumberOfAlloys(3, 2, 15, composition, stock, cost));

    composition = { {2,1},{1,2},{1,1} };
    stock = { 1,1 };
    cost = { 5,5 };
    check.checkInt(2, o.maxNumberOfAlloys(2, 3, 10, composition, stock, cost));
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
