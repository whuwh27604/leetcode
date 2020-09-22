/* 回文素数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
求出大于或等于 N 的最小回文素数。

回顾一下，如果一个数大于 1，且其因数只有 1 和它自身，那么这个数是素数。

例如，2，3，5，7，11 以及 13 是素数。

回顾一下，如果一个数从左往右读与从右往左读是一样的，那么这个数是回文数。

例如，12321 是回文数。

 

示例 1：

输入：6
输出：7
示例 2：

输入：8
输出：11
示例 3：

输入：13
输出：101
 

提示：

1 <= N <= 10^8
答案肯定存在，且小于 2 * 10^8。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/prime-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int primePalindrome(int N) {
        if (N == 1) {
            return 2;
        }

        string s = to_string(N), palindrome = s;
        if (isPrime(N) && isPalindrome(s)) {
            return N;
        }

        if (s.size() % 2 == 0) {
            evenFirstPalindrome(palindrome);
            if (palindrome < s) {
                evenNextPalindrome(palindrome);
            }
        }
        else {
            oddFirstPalindrome(palindrome);
            if (palindrome < s) {
                oddNextPalindrome(palindrome);
            }
        }

        int num = atoi(palindrome.data());

        while (!isPrime(num)) {
            if (palindrome.size() % 2 == 0) {
                evenNextPalindrome(palindrome);
            }
            else {
                oddNextPalindrome(palindrome);
            }

            num = atoi(palindrome.data());
        }

        return num;
    }

    bool isPrime(int n) {
        int root = (int)sqrt(n);

        for (int i = 2; i <= root; ++i) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    bool isPalindrome(string& s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }

        return true;
    }

    void oddFirstPalindrome(string& palindrome) {
        int middle = palindrome.size() / 2;

        for (int i = 1; i <= middle; ++i) {
            palindrome[middle + i] = palindrome[middle - i];
        }
    }

    void evenFirstPalindrome(string& palindrome) {
        int middle = palindrome.size() / 2;
        palindrome[middle] = palindrome[middle - 1];

        for (int i = 1; i < middle; ++i) {
            palindrome[middle + i] = palindrome[middle - 1 - i];
        }
    }

    void oddNextPalindrome(string& palindrome) {
        int middle = palindrome.size() / 2;

        if (palindrome[middle] != '9') {
            palindrome[middle] += 1;
            return;
        }

        palindrome[middle] = '0';

        for (int i = 1; i <= middle; ++i) {
            if (palindrome[middle - i] != '9') {
                palindrome[middle - i] += 1;
                palindrome[middle + i] += 1;
                return;
            }

            palindrome[middle - i] = '0';
            palindrome[middle + i] = '0';
        }

        palindrome.insert(palindrome.begin(), 1, '1');
        palindrome.back() = '1';
    }

    void evenNextPalindrome(string& palindrome) {
        int middle = palindrome.size() / 2;

        if (palindrome[middle] != '9') {
            palindrome[middle] += 1;
            palindrome[middle - 1] += 1;
            return;
        }

        palindrome[middle] = '0';
        palindrome[middle - 1] = '0';

        for (int i = 1; i < middle; ++i) {
            if (palindrome[middle - 1 - i] != '9') {
                palindrome[middle - 1 - i] += 1;
                palindrome[middle + i] += 1;
                return;
            }

            palindrome[middle - 1 - i] = '0';
            palindrome[middle + i] = '0';
        }

        palindrome.insert(palindrome.begin(), 1, '1');
        palindrome.back() = '1';
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(2, o.primePalindrome(1));
    check.checkInt(7, o.primePalindrome(6));
    check.checkInt(11, o.primePalindrome(8));
    check.checkInt(11, o.primePalindrome(9));
    check.checkInt(101, o.primePalindrome(13));
    check.checkInt(101, o.primePalindrome(99));
    check.checkInt(101, o.primePalindrome(101));
    check.checkInt(10301, o.primePalindrome(999));
    check.checkInt(12421, o.primePalindrome(12345));
    check.checkInt(100030001, o.primePalindrome(9999998));
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
