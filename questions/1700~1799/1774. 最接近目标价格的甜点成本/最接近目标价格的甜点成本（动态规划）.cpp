// 最接近目标价格的甜点成本.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int maxCost = 20000;  // 可以精确一些，baseCosts、toppingCosts、target里面最大数的两倍就够了
        vector<bool> dp(maxCost + 1, 0);  // dp[i]表示cost=i是否可达

        getAllCosts(baseCosts, toppingCosts, dp, maxCost);

        return getClosestCost(dp, target, maxCost);
    }

    void getAllCosts(vector<int>& baseCosts, vector<int>& toppingCosts, vector<bool>& dp, int maxCost) {
        for (int baseCost : baseCosts) {
            dp[baseCost] = true;
        }

        for (int toppingCost : toppingCosts) {
            for (int cost = maxCost; cost > 0; --cost) {
                if (dp[cost]) {
                    if (cost + toppingCost <= maxCost) {
                        dp[cost + toppingCost] = true;
                    }
                    if (cost + toppingCost * 2 <= maxCost) {
                        dp[cost + toppingCost * 2] = true;
                    }
                }
            }
        }
    }

    int getClosestCost(vector<bool>& dp, int target, int maxCost) {
        int cost1 = target, cost2 = target;

        while (!dp[cost1] && !dp[cost2]) {
            if (cost1 > 0) {
                --cost1;
            }
            if (cost2 < maxCost) {
                ++cost2;
            }
        }

        return dp[cost1] ? cost1 : cost2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> baseCosts = { 1,7 };
    vector<int> toppingCosts = { 3,4 };
    check.checkInt(10, o.closestCost(baseCosts, toppingCosts, 10));

    baseCosts = { 2,3 };
    toppingCosts = { 4,5,100 };
    check.checkInt(17, o.closestCost(baseCosts, toppingCosts, 18));

    baseCosts = { 3,10 };
    toppingCosts = { 2,5 };
    check.checkInt(8, o.closestCost(baseCosts, toppingCosts, 9));

    baseCosts = { 10 };
    toppingCosts = { 1 };
    check.checkInt(10, o.closestCost(baseCosts, toppingCosts, 1));

    baseCosts = { 9015,4152,7816,5153,1641,3402,5201 };
    toppingCosts = { 650,447,173,4843 };
    check.checkInt(9788, o.closestCost(baseCosts, toppingCosts, 9775));

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
