/* 计算各个位数不同的数字个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10n 。

示例:

输入: 2
输出: 91
解释: 答案应为除去 11,22,33,44,55,66,77,88,99 外，在 [0,100) 区间内的所有数字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-numbers-with-unique-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }

        // 令dp[i]为i位数的个数，则dp[i]=dp[i-1]*(10-(i-1))
        int dpPrev = 9, dp, count = 10;

        for (int i = 2; ((i <= n) && (i <= 10)); i++) {
            dp = dpPrev * (10 - (i - 1));
            dpPrev = dp;
            count += dp;
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(1, o.countNumbersWithUniqueDigits(0));
    check.checkInt(10, o.countNumbersWithUniqueDigits(1));
    check.checkInt(91, o.countNumbersWithUniqueDigits(2));
    check.checkInt(739, o.countNumbersWithUniqueDigits(3));
    check.checkInt(8877691, o.countNumbersWithUniqueDigits(10));
    check.checkInt(8877691, o.countNumbersWithUniqueDigits(11));
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
