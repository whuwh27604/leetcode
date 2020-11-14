/* 长按键入.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。

你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。

 

示例 1：

输入：name = "alex", typed = "aaleex"
输出：true
解释：'alex' 中的 'a' 和 'e' 被长按。
示例 2：

输入：name = "saeed", typed = "ssaaedd"
输出：false
解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
示例 3：

输入：name = "leelee", typed = "lleeelee"
输出：true
示例 4：

输入：name = "laiden", typed = "laiden"
输出：true
解释：长按名字中的字符并不是必要的。
 

提示：

name.length <= 1000
typed.length <= 1000
name 和 typed 的字符都是小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/long-pressed-name
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (name.empty()) {
            return typed.empty();
        }

        char prev = name[0];
        int i = 0, size = typed.size();

        for (char c : name) {
            if (i >= size) {
                return false;
            }

            if (typed[i] != c) {
                while ((i < size) && (typed[i] == prev)) {
                    ++i;
                }

                if ((i >= size) || (typed[i] != c)) {
                    return false;
                }
            }

            ++i;
            prev = c;
        }

        while (i < size) {
            if (typed[i++] != prev) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.isLongPressedName("alex", "aaleex"));
    check.checkBool(false, o.isLongPressedName("saeed", "ssaaedd"));
    check.checkBool(false, o.isLongPressedName("saeed", "ssaaeeddx"));
    check.checkBool(true, o.isLongPressedName("leelee", "lleeelee"));
    check.checkBool(true, o.isLongPressedName("laiden", "laiden"));
    check.checkBool(true, o.isLongPressedName("", ""));
    check.checkBool(false, o.isLongPressedName("", "a"));
    check.checkBool(false, o.isLongPressedName("a", ""));
    check.checkBool(true, o.isLongPressedName("a", "aaaaaaaaaaaaa"));
    check.checkBool(false, o.isLongPressedName("a", "aaaaaaaab"));
    check.checkBool(false, o.isLongPressedName("ab", "aaaaaaaa"));
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
