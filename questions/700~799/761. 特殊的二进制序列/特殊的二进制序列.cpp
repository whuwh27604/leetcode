/* 特殊的二进制序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
特殊的二进制序列是具有以下两个性质的二进制序列：

0 的数量与 1 的数量相等。
二进制序列的每一个前缀码中 1 的数量要大于等于 0 的数量。
给定一个特殊的二进制序列 S，以字符串形式表示。定义一个操作 为首先选择 S 的两个连续且非空的特殊的子串，然后将它们交换。（两个子串为连续的当且仅当第一个子串的最后一个字符恰好为第二个子串的第一个字符的前一个字符。)

在任意次数的操作之后，交换后的字符串按照字典序排列的最大的结果是什么？

示例 1:

输入: S = "11011000"
输出: "11100100"
解释:
将子串 "10" （在S[1]出现） 和 "1100" （在S[3]出现）进行交换。
这是在进行若干次操作后按字典序排列最大的结果。
说明:

S 的长度不超过 50。
S 保证为一个满足上述定义的特殊 的二进制序列。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/special-binary-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        /* s是合法的括号，只能是()(())(()())形式，那么可以任意交换()，(())，(()())，选最大的结果。
           而对于(()())形式，去掉最外层的()以后，内部()()仍然是合法的括号，所以可以递归解决。 */
        string maxSpecial;
        vector<string> subs;
        int left = 0, count = 0;

        for (int right = 0; right < (int)s.size(); ++right) {
            s[right] == '1' ? ++count : --count;

            if (count == 0) {
                string sub = "1";
                sub += makeLargestSpecial(string(s, left + 1, right - left - 1));
                sub += '0';
                subs.push_back(sub);
                left = right + 1;
            }
        }

        sort(subs.begin(), subs.end(), greater<string>());

        for (auto& sub : subs) {
            maxSpecial += sub;
        }

        return maxSpecial;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("11100100", o.makeLargestSpecial("11011000"));
    check.checkString("10", o.makeLargestSpecial("10"));
    check.checkString("111001010010", o.makeLargestSpecial("101101011000"));
    check.checkString("1101001101001010", o.makeLargestSpecial("1011010011010010"));
    check.checkString("111001010011100100111001001101001101001010101010", o.makeLargestSpecial("101101001101001010110101100010110110001101100010"));
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
