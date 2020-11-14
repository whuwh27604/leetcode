/* 重新格式化字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个混合了数字和字母的字符串 s，其中的字母均为小写英文字母。

请你将该字符串重新格式化，使得任意两个相邻字符的类型都不同。也就是说，字母后面应该跟着数字，而数字后面应该跟着字母。

请你返回 重新格式化后 的字符串；如果无法按要求重新格式化，则返回一个 空字符串 。

 

示例 1：

输入：s = "a0b1c2"
输出："0a1b2c"
解释："0a1b2c" 中任意两个相邻字符的类型都不同。 "a0b1c2", "0a1b2c", "0c2a1b" 也是满足题目要求的答案。
示例 2：

输入：s = "leetcode"
输出：""
解释："leetcode" 中只有字母，所以无法满足重新格式化的条件。
示例 3：

输入：s = "1229857369"
输出：""
解释："1229857369" 中只有数字，所以无法满足重新格式化的条件。
示例 4：

输入：s = "covid2019"
输出："c2o0v1i9d"
示例 5：

输入：s = "ab123"
输出："1a2b3"
 

提示：

1 <= s.length <= 500
s 仅由小写英文字母和/或数字组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reformat-the-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string reformat(string s) {
        string alternant, letters, digits;

        for (unsigned int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a') {
                letters += s[i];
            }
            else {
                digits += s[i];
            }
        }

        int len1 = letters.size(), len2 = digits.size();
        if (abs(len1 - len2) > 1) {
            return "";
        }

        int minLen = min(len1, len2);
        for (int i = 0; i < minLen; i++) {
            alternant += letters[i];
            alternant += digits[i];
        }

        if (len1 > minLen) {
            alternant += letters[minLen];
        }

        if (len2 > minLen) {
            alternant.insert(alternant.begin(), digits[minLen]);
        }

        return alternant;        
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("a0b1c2", o.reformat("a0b1c2"));
    check.checkString("", o.reformat("leetcode"));
    check.checkString("", o.reformat("1229857369"));
    check.checkString("c2o0v1i9d", o.reformat("covid2019"));
    check.checkString("3a1b2", o.reformat("ab123"));
    check.checkString("a", o.reformat("a"));
    check.checkString("1", o.reformat("1"));
    check.checkString("", o.reformat("11"));
    check.checkString("", o.reformat("aa"));
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
