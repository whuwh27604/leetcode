/* 比较含退格的字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。

 

示例 1：

输入：S = "ab#c", T = "ad#c"
输出：true
解释：S 和 T 都会变成 “ac”。
示例 2：

输入：S = "ab##", T = "c#d#"
输出：true
解释：S 和 T 都会变成 “”。
示例 3：

输入：S = "a##c", T = "#a#c"
输出：true
解释：S 和 T 都会变成 “c”。
示例 4：

输入：S = "a#c", T = "b"
输出：false
解释：S 会变成 “c”，但 T 仍然是 “b”。
 

提示：

1 <= S.length <= 200
1 <= T.length <= 200
S 和 T 只含有小写字母以及字符 '#'。
 

进阶：

你可以用 O(N) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/backspace-string-compare
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int indexS = S.size(), indexT = T.size();

        while (indexS >= 0 && indexT >= 0) {
            if (prev(S, indexS) != prev(T, indexT)) {
                return false;
            }
        }

        return true;
    }

    char prev(string& s, int& index) {
        if (--index < 0) {
            return 0;
        }

        if (s[index] != '#') {
            return s[index];
        }

        int count = 2;
        while (count > 0) {
            if (--index < 0) {
                return 0;
            }

            if (s[index] == '#') {
                ++count;
            }
            else {
                --count;
            }
        }

        return s[index];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.backspaceCompare("ab#c", "ad#c"));
    check.checkBool(true, o.backspaceCompare("ab##", "c#d#"));
    check.checkBool(true, o.backspaceCompare("a##c", "#a#c"));
    check.checkBool(false, o.backspaceCompare("a#c", "b"));
    check.checkBool(true, o.backspaceCompare("###c", "##c"));
    check.checkBool(true, o.backspaceCompare("aaa###c", "aa##c"));
    check.checkBool(true, o.backspaceCompare("baaa###c", "baa##c"));
    check.checkBool(false, o.backspaceCompare("baaa###c", "aaa##c"));
    check.checkBool(false, o.backspaceCompare("ba", "a"));
    check.checkBool(false, o.backspaceCompare("bb#a", "a#a"));
    check.checkBool(true, o.backspaceCompare("nzp#o#g", "b#nzp#o#g"));
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
