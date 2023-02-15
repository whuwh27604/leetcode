/* 超级回文数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果一个正整数自身是回文数，而且它也是一个回文数的平方，那么我们称这个数为超级回文数。

现在，给定两个正整数 L 和 R （以字符串形式表示），返回包含在范围 [L, R] 中的超级回文数的数目。



示例：

输入：L = "4", R = "1000"
输出：4
解释：
4，9，121，以及 484 是超级回文数。
注意 676 不是一个超级回文数： 26 * 26 = 676，但是 26 不是回文数。


提示：

1 <= len(L) <= 18
1 <= len(R) <= 18
L 和 R 是表示 [1, 10^18) 范围的整数的字符串。
int(L) <= int(R)
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

vector<long long> superPalindromes = { 1,4,9 };

bool isSuperPalindrome(long long num) {
    string s = to_string(num);

    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }

    return true;
}

void init() {
    static bool inited = false;

    if (!inited) {
        inited = true;
        long long maxSuper = 1000000000000000000;

        for (long long num = 1; ; ++num) {
            long long mirror = 0, power = 1, n = num;

            while (n != 0) {
                int digit = n % 10;
                mirror = mirror * 10 + digit;
                n /= 10;
                power *= 10;
            }

            long long evenPal = num * power + mirror, sqr = evenPal * evenPal;
            if (sqr >= maxSuper) {
                break;
            }

            if (isSuperPalindrome(sqr)) {
                superPalindromes.push_back(sqr);
            }

            for (int i = 0; i < 10; ++i) {
                long long oddPal = num * power * 10 + i * power + mirror;
                sqr = oddPal * oddPal;
                if (sqr < maxSuper && isSuperPalindrome(sqr)) {
                    superPalindromes.push_back(sqr);
                }
            }
        }

        sort(superPalindromes.begin(), superPalindromes.end());
    }
}

class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        long long low = stoll(left), high = stoll(right);

        init();

        return distance(superPalindromes.begin(), upper_bound(superPalindromes.begin(), superPalindromes.end(), high))
            - distance(superPalindromes.begin(), lower_bound(superPalindromes.begin(), superPalindromes.end(), low));
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.superpalindromesInRange("4", "1000"));
    check.checkInt(70, o.superpalindromesInRange("1", "999999999999999999"));
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
