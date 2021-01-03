/* 使用最小花费爬楼梯.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
数组的每个索引做为一个阶梯，第 i个阶梯对应着一个非负数的体力花费值 cost[i](索引从0开始)。

每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续爬一个阶梯或者爬两个阶梯。

您需要找到达到楼层顶部的最低花费。在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯。

示例 1:

输入: cost = [10, 15, 20]
输出: 15
解释: 最低花费是从cost[1]开始，然后走两步即可到阶梯顶，一共花费15。
 示例 2:

输入: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
输出: 6
解释: 最低花费方式是从cost[0]开始，逐个经过那些1，跳过cost[3]，一共花费6。
注意：

cost 的长度将会在 [2, 1000]。
每一个 cost[i] 将会是一个Integer类型，范围为 [0, 999]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-cost-climbing-stairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        int minSumCost2 = min(cost[0], cost[1]);
        if (len == 2) {
            return minSumCost2;
        }

        int minSumCost3 = min(cost[1], minSumCost2 + cost[2]);
        int minSumCost = minSumCost3, frontMinSumCost = minSumCost3, front2MinSumCost = minSumCost2;

        for (int i = 4; i <= len; i++) {
            minSumCost = min(frontMinSumCost + cost[i - 1], front2MinSumCost + cost[i - 2]);
            front2MinSumCost = frontMinSumCost;
            frontMinSumCost = minSumCost;
        }

        return minSumCost;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> cost = { 10, 15, 20 };
    check.checkInt(15, o.minCostClimbingStairs(cost));

    cost = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
    check.checkInt(6, o.minCostClimbingStairs(cost));

    cost = { 1, 100 };
    check.checkInt(1, o.minCostClimbingStairs(cost));

    cost = { 100, 1 };
    check.checkInt(1, o.minCostClimbingStairs(cost));

    cost = { 15, 10, 20 };
    check.checkInt(10, o.minCostClimbingStairs(cost));

    cost = { 15, 10, 20, 1 };
    check.checkInt(11, o.minCostClimbingStairs(cost));

    cost = { 15, 10, 20, 1, 2 };
    check.checkInt(11, o.minCostClimbingStairs(cost));

    cost = { 15, 10, 20, 1, 2, 100 };
    check.checkInt(13, o.minCostClimbingStairs(cost));
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
