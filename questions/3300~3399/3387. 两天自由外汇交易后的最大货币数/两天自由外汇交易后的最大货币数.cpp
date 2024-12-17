/* 两天自由外汇交易后的最大货币数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 initialCurrency，表示初始货币类型，并且你一开始拥有 1.0 单位的 initialCurrency。

另给你四个数组，分别表示货币对（字符串）和汇率（实数）：

pairs1[i] = [startCurrencyi, targetCurrencyi] 表示在 第 1 天，可以按照汇率 rates1[i] 将 startCurrencyi 转换为 targetCurrencyi。
pairs2[i] = [startCurrencyi, targetCurrencyi] 表示在 第 2 天，可以按照汇率 rates2[i] 将 startCurrencyi 转换为 targetCurrencyi。
此外，每种 targetCurrency 都可以以汇率 1 / rate 转换回对应的 startCurrency。
你可以在 第 1 天 使用 rates1 进行任意次数的兑换（包括 0 次），然后在 第 2 天 使用 rates2 再进行任意次数的兑换（包括 0 次）。

返回在两天兑换后，最大可能拥有的 initialCurrency 的数量。

注意：汇率是有效的，并且第 1 天和第 2 天的汇率之间相互独立，不会产生矛盾。



示例 1：

输入： initialCurrency = "EUR", pairs1 = [["EUR","USD"],["USD","JPY"]], rates1 = [2.0,3.0], pairs2 = [["JPY","USD"],["USD","CHF"],["CHF","EUR"]], rates2 = [4.0,5.0,6.0]

输出： 720.00000

解释：

根据题目要求，需要最大化最终的 EUR 数量，从 1.0 EUR 开始：

第 1 天：
将 EUR 换成 USD，得到 2.0 USD。
将 USD 换成 JPY，得到 6.0 JPY。
第 2 天：
将 JPY 换成 USD，得到 24.0 USD。
将 USD 换成 CHF，得到 120.0 CHF。
最后将 CHF 换回 EUR，得到 720.0 EUR。
示例 2：

输入： initialCurrency = "NGN", pairs1 = [["NGN","EUR"]], rates1 = [9.0], pairs2 = [["NGN","EUR"]], rates2 = [6.0]

输出： 1.50000

解释：

在第 1 天将 NGN 换成 EUR，并在第 2 天用反向汇率将 EUR 换回 NGN，可以最大化最终的 NGN 数量。

示例 3：

输入： initialCurrency = "USD", pairs1 = [["USD","EUR"]], rates1 = [1.0], pairs2 = [["EUR","JPY"]], rates2 = [10.0]

输出： 1.00000

解释：

在这个例子中，不需要在任何一天进行任何兑换。



提示：

1 <= initialCurrency.length <= 3
initialCurrency 仅由大写英文字母组成。
1 <= n == pairs1.length <= 10
1 <= m == pairs2.length <= 10
pairs1[i] == [startCurrencyi, targetCurrencyi]
pairs2[i] == [startCurrencyi, targetCurrencyi]
1 <= startCurrencyi.length, targetCurrencyi.length <= 3
startCurrencyi 和 targetCurrencyi 仅由大写英文字母组成。
rates1.length == n
rates2.length == m
1.0 <= rates1[i], rates2[i] <= 10.0
输入保证两个转换图在各自的天数中没有矛盾或循环。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2) {
        unordered_map<string, vector<pair<string, double>>> adjs1, adjs2;
        unordered_map<string, double> mp1, mp2;
        string parent;

        getAdjs(pairs1, rates1, adjs1);
        DFS1(parent, initialCurrency, 1, adjs1, mp1);
        getAdjs(pairs2, rates2, adjs2);
        DFS2(parent, initialCurrency, 1, adjs2, mp2);

        return getAns(mp1, mp2);
    }

    void getAdjs(vector<vector<string>>& pairs, vector<double>& rates, unordered_map<string, vector<pair<string, double>>>& adjs) {
        for (int i = 0; i < (int)pairs.size(); ++i) {
            string& x = pairs[i][0];
            string& y = pairs[i][1];
            double rate = rates[i];

            adjs[x].push_back({ y,rate });
            adjs[y].push_back({ x,1 / rate });
        }
    }

    void DFS1(string& parent, string& cur, double amount, unordered_map<string, vector<pair<string, double>>>& adjs1, unordered_map<string, double>& mp1) {
        mp1[cur] = max(mp1[cur], amount);

        for (auto& next : adjs1[cur]) {
            if (next.first != parent) {
                DFS1(cur, next.first, next.second * amount, adjs1, mp1);
            }
        }
    }

    void DFS2(string& parent, string& cur, double amount, unordered_map<string, vector<pair<string, double>>>& adjs2, unordered_map<string, double>& mp2) {
        if (mp2.count(cur) == 0) {
            mp2[cur] = amount;
        }
        else {
            mp2[cur] = min(mp2[cur], amount);
        }

        for (auto& next : adjs2[cur]) {
            if (next.first != parent) {
                DFS1(cur, next.first, next.second * amount, adjs2, mp2);
            }
        }
    }

    double getAns(unordered_map<string, double>& mp1, unordered_map<string, double>& mp2) {
        double ans = 1;

        for (auto& kv : mp2) {
            if (mp1.count(kv.first) != 0) {
                ans = max(ans, mp1[kv.first] / kv.second);
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<string>> pairs1 = { {"EUR","USD"},{"USD","JPY"} };
    vector<double> rates1 = { 2.0,3.0 };
    vector<vector<string>> pairs2 = { {"JPY","USD"},{"USD","CHF"},{"CHF","EUR"} };
    vector<double> rates2 = { 4.0,5.0,6.0 };
    check.checkDouble(720, o.maxAmount("EUR", pairs1, rates1, pairs2, rates2));

    pairs1 = { {"NGN","EUR"} };
    rates1 = { 9.0 };
    pairs2 = { {"NGN","EUR"} };
    rates2 = { 6.0 };
    check.checkDouble(1.5, o.maxAmount("NGN", pairs1, rates1, pairs2, rates2));

    pairs1 = { {"USD","EUR"} };
    rates1 = { 1.0 };
    pairs2 = { {"EUR","JPY"} };
    rates2 = { 10.0 };
    check.checkDouble(1, o.maxAmount("USD", pairs1, rates1, pairs2, rates2));
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
