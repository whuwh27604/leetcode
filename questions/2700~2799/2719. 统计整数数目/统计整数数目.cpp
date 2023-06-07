/* 统计整数数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个数字字符串 num1 和 num2 ，以及两个整数 max_sum 和 min_sum 。如果一个整数 x 满足以下条件，我们称它是一个好整数：

num1 <= x <= num2
min_sum <= digit_sum(x) <= max_sum.
请你返回好整数的数目。答案可能很大，请返回答案对 109 + 7 取余后的结果。

注意，digit_sum(x) 表示 x 各位数字之和。



示例 1：

输入：num1 = "1", num2 = "12", min_num = 1, max_num = 8
输出：11
解释：总共有 11 个整数的数位和在 1 到 8 之间，分别是 1,2,3,4,5,6,7,8,10,11 和 12 。所以我们返回 11 。
示例 2：

输入：num1 = "1", num2 = "5", min_num = 1, max_num = 5
输出：5
解释：数位和在 1 到 5 之间的 5 个整数分别为 1,2,3,4 和 5 。所以我们返回 5 。


提示：

1 <= num1 <= num2 <= 1022
1 <= min_sum <= max_sum <= 400
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        minusOne(num1);

        return (count(num2, min_sum, max_sum) + mod - count(num1, min_sum, max_sum)) % mod;
    }

    int count(string& num, int minSum, int maxSum) {
        int size = num.size();
        vector<vector<int>> memo(size, vector<int>(min(9 * size, maxSum) + 1, -1));

        return dp(num, 0, 0, minSum, maxSum, true, memo);
    }

    int dp(string& num, int i, int sum, int minSum, int maxSum, bool isLimited, vector<vector<int>>& memo) {
        if (sum > maxSum) {
            return 0;
        }

        if (i == num.size()) {
            return sum >= minSum ? 1 : 0;
        }

        if (!isLimited && memo[i][sum] != -1) {
            return memo[i][sum];
        }

        int ans = 0;
        int maxDigit = isLimited ? num[i] - '0' : 9;  // 如果受限，只能枚举[0, num[i]]，否则可以枚举[0, 9]

        for (int d = 0; d <= maxDigit; ++d) {
            ans = (ans + dp(num, i + 1, sum + d, minSum, maxSum, isLimited && d == maxDigit, memo)) % mod;  // 如果已经受限，并且当前位选择了最大数，那么后续也是受限状态
        }

        if (!isLimited) {
            memo[i][sum] = ans;
        }

        return ans;
    }

    void minusOne(string& num) {
        int i = num.size() - 1;

        while (num[i] == '0') {
            num[i--] = '9';
        }

        num[i] -= 1;
    }

    int mod = 1000000007;
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(11, o.count("1", "12", 1, 8));
    check.checkInt(5, o.count("1", "5", 1, 5));
    check.checkInt(1, o.count("100", "100", 1, 1));
    check.checkInt(1, o.count("100", "200", 1, 1));
    check.checkInt(1, o.count("100", "100", 1, 5));
    check.checkInt(814816192, o.count("1", "12345678901234567890", 1, 400));
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
