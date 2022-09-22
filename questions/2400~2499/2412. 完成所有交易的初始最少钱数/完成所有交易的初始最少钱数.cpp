/* 完成所有交易的初始最少钱数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的二维整数数组 transactions，其中transactions[i] = [costi, cashbacki] 。

数组描述了若干笔交易。其中每笔交易必须以 某种顺序 恰好完成一次。在任意一个时刻，你有一定数目的钱 money ，为了完成交易 i ，money >= costi 这个条件必须为真。执行交易后，你的钱数 money 变成 money - costi + cashbacki 。

请你返回 任意一种 交易顺序下，你都能完成所有交易的最少钱数 money 是多少。

 

示例 1：

输入：transactions = [[2,1],[5,0],[4,2]]
输出：10
解释：
刚开始 money = 10 ，交易可以以任意顺序进行。
可以证明如果 money < 10 ，那么某些交易无法进行。
示例 2：

输入：transactions = [[3,0],[0,3]]
输出：3
解释：
- 如果交易执行的顺序是 [[3,0],[0,3]] ，完成所有交易需要的最少钱数是 3 。
- 如果交易执行的顺序是 [[0,3],[3,0]] ，完成所有交易需要的最少钱数是 0 。
所以，刚开始钱数为 3 ，任意顺序下交易都可以全部完成。
 

提示：

1 <= transactions.length <= 105
transactions[i].length == 2
0 <= costi, cashbacki <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-money-required-before-transactions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        long long minMoney = 0;
        int maxCost = 0, maxBack = 0;

        for (auto& transaction : transactions) {
            int cost = transaction[0], cashback = transaction[1];

            if (cost > cashback) {
                minMoney += ((long long)cost - cashback);
                maxBack = max(maxBack, cashback);
            }
            else {
                maxCost = max(maxCost, cost);
            }
        }

        return minMoney + maxBack + ((maxBack < maxCost) ? (maxCost - maxBack) : 0);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> transactions = { {2,1},{5,0},{4,2} };
    check.checkLongLong(10, o.minimumMoney(transactions));

    transactions = { {3,0},{0,3} };
    check.checkLongLong(3, o.minimumMoney(transactions));

    transactions = { {6,5},{0,5},{8,5},{3,6},{9,0},{10,1},{4,10} };
    check.checkLongLong(27, o.minimumMoney(transactions));
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
