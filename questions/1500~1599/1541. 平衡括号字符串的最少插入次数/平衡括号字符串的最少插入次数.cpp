/* 平衡括号字符串的最少插入次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个括号字符串 s ，它只包含字符 '(' 和 ')' 。一个括号字符串被称为平衡的当它满足：

任何左括号 '(' 必须对应两个连续的右括号 '))' 。
左括号 '(' 必须在对应的连续两个右括号 '))' 之前。
比方说 "())"， "())(())))" 和 "(())())))" 都是平衡的， ")()"， "()))" 和 "(()))" 都是不平衡的。

你可以在任意位置插入字符 '(' 和 ')' 使字符串平衡。

请你返回让 s 平衡的最少插入次数。

 

示例 1：

输入：s = "(()))"
输出：1
解释：第二个左括号有与之匹配的两个右括号，但是第一个左括号只有一个右括号。我们需要在字符串结尾额外增加一个 ')' 使字符串变成平衡字符串 "(())))" 。
示例 2：

输入：s = "())"
输出：0
解释：字符串已经平衡了。
示例 3：

输入：s = "))())("
输出：3
解释：添加 '(' 去匹配最开头的 '))' ，然后添加 '))' 去匹配最后一个 '(' 。
示例 4：

输入：s = "(((((("
输出：12
解释：添加 12 个 ')' 得到平衡字符串。
示例 5：

输入：s = ")))))))"
输出：5
解释：在字符串开头添加 4 个 '(' 并在结尾添加 1 个 ')' ，字符串变成平衡字符串 "(((())))))))" 。
 

提示：

1 <= s.length <= 10^5
s 只包含 '(' 和 ')' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-insertions-to-balance-a-parentheses-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int left = 0, right = 0, insertions = 0;

        for (char c : s) {
            if (c == '(') {
                ++left;

                if (right == 1) {  // 右括号没有两个连续的，需要补充一个
                    right = 0;
                    ++insertions;
                }
            }
            else {
                if (right == 1) {  // 连续的2个右括号中的第二个
                    right = 0;
                }
                else {
                    right = 1;

                    if (left == 0) {  // 匹配一个左括号，如果左括号已经没有了，则需要补充一个
                        ++insertions;
                    }
                    else {
                        --left;
                    }
                }
            }
        }

        return insertions + 2 * left + right;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.minInsertions("()()))"));
    check.checkInt(1, o.minInsertions("(()))"));
    check.checkInt(0, o.minInsertions("())"));
    check.checkInt(3, o.minInsertions("))())("));
    check.checkInt(12, o.minInsertions("(((((("));
    check.checkInt(5, o.minInsertions(")))))))"));
    check.checkInt(4, o.minInsertions("(()))(()))()())))"));
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
