/* 解码方法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一条包含字母 A-Z 的消息通过以下方式进行了编码：

'A' -> 1
'B' -> 2
...
'Z' -> 26
给定一个只包含数字的非空字符串，请计算解码方法的总数。

题目数据保证答案肯定是一个 32 位的整数。

 

示例 1：

输入：s = "12"
输出：2
解释：它可以解码为 "AB"（1 2）或者 "L"（12）。
示例 2：

输入：s = "226"
输出：3
解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
示例 3：

输入：s = "0"
输出：0
示例 4：

输入：s = "1"
输出：1
示例 5：

输入：s = "2"
输出：1
 

提示：

1 <= s.length <= 100
s 只包含数字，并且可能包含前导零。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decode-ways
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        string newS;
        if (!delZero(s, newS)) {
            return 0;
        }

        int i, size = newS.size(), current = 1, post = 1;

        for (i = size - 2; i >= 0; --i) {
            if ((newS[i] == '1' && (newS[i + 1] >= '1' && newS[i + 1] <= '9')) || (newS[i] == '2' && (newS[i + 1] >= '1' && newS[i + 1] <= '6'))) {
                current += post;
                post = current - post;
            }
            else {
                post = current;
            }
        }

        return current;
    }

    bool delZero(string& s, string& newS) {
        int i, size = s.size();

        for (i = 0; i < size; ++i) {
            if (s[i] == '0') {
                return false;
            }

            if (s[i + 1] == '0') {
                if (s[i] == '1' || s[i] == '2') {
                    newS += 'a';
                    ++i;
                }
                else {
                    return false;
                }
            }
            else {
                newS += s[i];
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.numDecodings("12"));
    check.checkInt(3, o.numDecodings("226"));
    check.checkInt(0, o.numDecodings("0226"));
    check.checkInt(0, o.numDecodings("000226"));
    check.checkInt(1, o.numDecodings("1"));
    check.checkInt(1, o.numDecodings("2"));
    check.checkInt(1, o.numDecodings("10"));
    check.checkInt(1, o.numDecodings("8"));
    check.checkInt(1, o.numDecodings("20"));
    check.checkInt(2, o.numDecodings("26"));
    check.checkInt(1, o.numDecodings("27"));
    check.checkInt(1, o.numDecodings("99"));
    check.checkInt(0, o.numDecodings("100"));
    check.checkInt(0, o.numDecodings("0"));
    check.checkInt(0, o.numDecodings("000"));
    check.checkInt(1, o.numDecodings("101"));
    check.checkInt(1, o.numDecodings("2101"));
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
