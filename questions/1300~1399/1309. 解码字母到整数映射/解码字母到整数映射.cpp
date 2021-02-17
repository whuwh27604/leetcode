/* 解码字母到整数映射.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s，它由数字（'0' - '9'）和 '#' 组成。我们希望按下述规则将 s 映射为一些小写英文字符：

字符（'a' - 'i'）分别用（'1' - '9'）表示。
字符（'j' - 'z'）分别用（'10#' - '26#'）表示。 
返回映射之后形成的新字符串。

题目数据保证映射始终唯一。

 

示例 1：

输入：s = "10#11#12"
输出："jkab"
解释："j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
示例 2：

输入：s = "1326#"
输出："acz"
示例 3：

输入：s = "25#"
输出："y"
示例 4：

输入：s = "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"
输出："abcdefghijklmnopqrstuvwxyz"
 

提示：

1 <= s.length <= 1000
s[i] 只包含数字（'0'-'9'）和 '#' 字符。
s 是映射始终存在的有效字符串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/decrypt-string-from-alphabet-to-integer-mapping
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        int i, len = s.size();
        string ans;

        for (i = len - 1; i >= 0; i--) {
            if (s[i] != '#') {
                ans.push_back(s[i] + 48);
            }
            else {
                int n = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
                ans.push_back('a' + n - 1);
                i -= 2;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("jkab", o.freqAlphabets("10#11#12"));
    check.checkString("acz", o.freqAlphabets("1326#"));
    check.checkString("y", o.freqAlphabets("25#"));
    check.checkString("abcdefghijklmnopqrstuvwxyz", o.freqAlphabets("12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"));
    check.checkString("a", o.freqAlphabets("1"));
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
