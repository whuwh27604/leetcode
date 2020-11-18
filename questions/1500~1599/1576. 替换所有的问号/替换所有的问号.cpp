/* 替换所有的问号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个仅包含小写英文字母和 '?' 字符的字符串 s，请你将所有的 '?' 转换为若干小写字母，使最终的字符串不包含任何 连续重复 的字符。

注意：你 不能 修改非 '?' 字符。

题目测试用例保证 除 '?' 字符 之外，不存在连续重复的字符。

在完成所有转换（可能无需转换）后返回最终的字符串。如果有多个解决方案，请返回其中任何一个。可以证明，在给定的约束条件下，答案总是存在的。

 

示例 1：

输入：s = "?zs"
输出："azs"
解释：该示例共有 25 种解决方案，从 "azs" 到 "yzs" 都是符合题目要求的。只有 "z" 是无效的修改，因为字符串 "zzs" 中有连续重复的两个 'z' 。
示例 2：

输入：s = "ubv?w"
输出："ubvaw"
解释：该示例共有 24 种解决方案，只有替换成 "v" 和 "w" 不符合题目要求。因为 "ubvvw" 和 "ubvww" 都包含连续重复的字符。
示例 3：

输入：s = "j?qg??b"
输出："jaqgacb"
示例 4：

输入：s = "??yw?ipkj?"
输出："acywaipkja"
 

提示：

1 <= s.length <= 100

s 仅包含小写英文字母和 '?' 字符

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string modifyString(string s) {
        int i, size = s.size();

        if (size == 1) {
            return s[0] == '?' ? "a" : s;
        }

        if (s[0] == '?') {
            s[0] = (s[1] == 'a' ? 'b' : 'a');
        }

        for (i = 1; i < size - 1; ++i) {
            if (s[i] == '?') {
                s[i] = s[i - 1] == 'z' ? 'a' : s[i - 1] + 1;
                if (s[i] == s[i + 1]) {
                    s[i] = s[i] == 'z' ? 'a' : s[i] + 1;
                }
            }
        }

        if (s[size - 1] == '?') {
            s[size - 1] = (s[size - 2] == 'z' ? 'a' : s[size - 2] + 1);
        }

        return s;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("a", o.modifyString("?"));
    check.checkString("b", o.modifyString("b"));
    check.checkString("azs", o.modifyString("?zs"));
    check.checkString("bas", o.modifyString("?as"));
    check.checkString("ubvxw", o.modifyString("ubv?w"));
    check.checkString("ubyaz", o.modifyString("uby?z"));
    check.checkString("jkqghib", o.modifyString("j?qg??b"));
    check.checkString("abywxipkjk", o.modifyString("??yw?ipkj?"));
    check.checkString("abywxipkza", o.modifyString("??yw?ipkz?"));
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
