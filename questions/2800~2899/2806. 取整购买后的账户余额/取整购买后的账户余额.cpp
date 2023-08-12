/* 取整购买后的账户余额.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一开始，你的银行账户里有 100 块钱。

给你一个整数purchaseAmount ，它表示你在一次购买中愿意支出的金额。

在一个商店里，你进行一次购买，实际支出的金额会向 最近 的 10 的 倍数 取整。换句话说，你实际会支付一个 非负 金额 roundedAmount ，满足 roundedAmount 是 10 的倍数且 abs(roundedAmount - purchaseAmount) 的值 最小 。

如果存在多于一个最接近的 10 的倍数，较大的倍数 是你的实际支出金额。

请你返回一个整数，表示你在愿意支出金额为 purchaseAmount 块钱的前提下，购买之后剩下的余额。

注意： 0 也是 10 的倍数。



示例 1：

输入：purchaseAmount = 9
输出：90
解释：这个例子中，最接近 9 的 10 的倍数是 10 。所以你的账户余额为 100 - 10 = 90 。
示例 2：

输入：purchaseAmount = 15
输出：80
解释：这个例子中，有 2 个最接近 15 的 10 的倍数：10 和 20，较大的数 20 是你的实际开销。
所以你的账户余额为 100 - 20 = 80 。


提示：

0 <= purchaseAmount <= 100
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        return 100 - (purchaseAmount + 5) / 10 * 10;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(90, o.accountBalanceAfterPurchase(9));
    check.checkInt(80, o.accountBalanceAfterPurchase(15));
    check.checkInt(100, o.accountBalanceAfterPurchase(0));
    check.checkInt(100, o.accountBalanceAfterPurchase(1));
    check.checkInt(0, o.accountBalanceAfterPurchase(99));
    check.checkInt(0, o.accountBalanceAfterPurchase(100));
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
