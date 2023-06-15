/* 执行子串操作后的字典序最小字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个仅由小写英文字母组成的字符串 s 。在一步操作中，你可以完成以下行为：

选则 s 的任一非空子字符串，可能是整个字符串，接着将字符串中的每一个字符替换为英文字母表中的前一个字符。例如，'b' 用 'a' 替换，'a' 用 'z' 替换。
返回执行上述操作 恰好一次 后可以获得的 字典序最小 的字符串。

子字符串 是字符串中的一个连续字符序列。

现有长度相同的两个字符串 x 和 字符串 y ，在满足 x[i] != y[i] 的第一个位置 i 上，如果  x[i] 在字母表中先于 y[i] 出现，则认为字符串 x 比字符串 y 字典序更小 。


示例 1：

输入：s = "cbabc"
输出："baabc"
解释：我们选择从下标 0 开始、到下标 1 结束的子字符串执行操作。
可以证明最终得到的字符串是字典序最小的。
示例 2：

输入：s = "acbbc"
输出："abaab"
解释：我们选择从下标 1 开始、到下标 4 结束的子字符串执行操作。
可以证明最终得到的字符串是字典序最小的。
示例 3：

输入：s = "leetcode"
输出："kddsbncd"
解释：我们选择整个字符串执行操作。
可以证明最终得到的字符串是字典序最小的。


提示：

1 <= s.length <= 3 * 105
s 仅由小写英文字母组成
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string smallestString(string s) {
        bool changed = false;

        for (char& c : s) {
            if (c == 'a') {
                if (changed) {
                    break;
                }
            }
            else {
                c -= 1;
                changed = true;
            }
        }

        if (!changed) {
            s.back() = 'z';
        }

        return s;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("z", o.smallestString("a"));
    check.checkString("aaz", o.smallestString("aaa"));
    check.checkString("baabc", o.smallestString("cbabc"));
    check.checkString("abaab", o.smallestString("acbbc"));
    check.checkString("kddsbncd", o.smallestString("leetcode"));
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
