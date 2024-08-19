/* 找出最大的 N 位 K 回文数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个 正整数 n 和 k。

如果整数 x 满足以下全部条件，则该整数是一个 k 回文数：

x 是一个
回文数
。
x 可以被 k 整除。
以字符串形式返回 最大的  n 位 k 回文数。

注意，该整数 不 含前导零。



示例 1：

输入： n = 3, k = 5

输出： "595"

解释：

595 是最大的 3 位 k 回文数。

示例 2：

输入： n = 1, k = 4

输出： "8"

解释：

1 位 k 回文数只有 4 和 8。

示例 3：

输入： n = 5, k = 6

输出： "89898"



提示：

1 <= n <= 105
1 <= k <= 9
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string largestPalindrome(int n, int k) {
        if (k == 1 || k == 3 || k == 9) {
            return string(n, '9');
        }
        else if (k == 2) {
            return (n == 1 ? "8" : "8" + string(n - 2, '9') + "8");
        }
        else if (k == 4) {
            return (n == 1 ? "8" : (n == 2 ? "88" : (n == 3 ? "888" : "88" + string(n - 4, '9') + "88")));
        }
        else if (k == 5) {
            return (n == 1 ? "5" : "5" + string(n - 2, '9') + "5");
        }
        else if (k == 6) {
            return largestPalindrome6(n);
        }
        else if (k == 7) {
            return largestPalindrome7(n);
        }
        else if (k == 8) {
            return (n < 6 ? string(n, '8') : "888" + string(n - 6, '9') + "888");
        }
        else {
            return "";
        }
    }

    string largestPalindrome6(int n) {
        if (n == 1) {
            return "6";
        }
        else if (n == 2) {
            return "66";
        }
        else {
            if ((n & 1) == 1) {  // 奇数个，899...99899...998
                return "8" + string((n - 3) / 2, '9') + "8" + string((n - 3) / 2, '9') + "8";
            }
            else {  // 偶数个，899...997799...998
                return "8" + string((n - 4) / 2, '9') + "77" + string((n - 4) / 2, '9') + "8";
            }
        }
    }

    string largestPalindrome7(int n) {
        if (n == 1) {
            return "7";
        }
        else if (n == 2) {
            return "77";
        }
        else {  // 99...99x99.999的形式一定有解
            string palindrome(n, '9');

            for (char c = '9'; c >= '0'; --c) {
                palindrome[n / 2] = c;
                if ((n & 1) == 0) {
                    palindrome[n / 2 - 1] = c;
                }

                if (divExactly(palindrome)) {
                    break;
                }
            }

            return palindrome;
        }
    }

    bool divExactly(string& palindrome) {
        int divisor = 7, remainder = 0;

        for (char c : palindrome) {
            int dividend = remainder * 10 + c - '0';
            remainder = dividend % divisor;
        }

        return remainder == 0;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("595", o.largestPalindrome(3, 5));
    check.checkString("8", o.largestPalindrome(1, 4));
    check.checkString("89898", o.largestPalindrome(5, 6));
    check.checkString("899989998", o.largestPalindrome(9, 6));
    check.checkString("99999999944999999999", o.largestPalindrome(20, 7));
    check.checkString("99999999999999799999999999999", o.largestPalindrome(29, 7));
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
