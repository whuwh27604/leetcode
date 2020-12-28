/* 重复叠加字符串匹配.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个字符串 A 和 B, 寻找重复叠加字符串A的最小次数，使得字符串B成为叠加后的字符串A的子串，如果不存在则返回 -1。

举个例子，A = "abcd"，B = "cdabcdab"。

答案为 3， 因为 A 重复叠加三遍后为 “abcdabcdabcd”，此时 B 是其子串；A 重复叠加两遍后为"abcdabcd"，B 并不是其子串。

注意:

 A 与 B 字符串的长度在1和10000区间范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/repeated-string-match
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int lenA = A.size(), lenB = B.size();

        if (lenA >= lenB) {
            if (A.find(B) != string::npos) {
                return 1;
            }

            A += A;
            if (A.find(B) != string::npos) {
                return 2;
            }
            return -1;
        }

        int repeat = lenB / lenA;
        int i = repeat - 1;
        string repeatA = A;
        while (i-- > 0) {
            repeatA += A;
        }

        if (lenB % lenA == 0) {
            if (repeatA == B) {
                return repeat;
            }

            repeatA += A;
            if (repeatA.find(B) != string::npos) {
                return repeat + 1;
            }
            return -1;
        }

        for (i = 1; i <= 2; i++) {
            repeatA += A;
            if (repeatA.find(B) != string::npos) {
                return repeat + i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(3, o.repeatedStringMatch("abcd", "cdabcdab"));
    check.checkInt(1, o.repeatedStringMatch("abcd", "bc"));
    check.checkInt(-1, o.repeatedStringMatch("abcd", "x"));
    check.checkInt(1, o.repeatedStringMatch("a", "a"));
    check.checkInt(-1, o.repeatedStringMatch("a", "b"));
    check.checkInt(3, o.repeatedStringMatch("ab", "ababab"));
    check.checkInt(-1, o.repeatedStringMatch("ab", "ababax"));
    check.checkInt(4, o.repeatedStringMatch("ab", "abababa"));
    check.checkInt(-1, o.repeatedStringMatch("ab", "bababax"));
    check.checkInt(5, o.repeatedStringMatch("abc", "cabcabcabca"));
    check.checkInt(-1, o.repeatedStringMatch("abc", "cabcabcabcx"));
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
