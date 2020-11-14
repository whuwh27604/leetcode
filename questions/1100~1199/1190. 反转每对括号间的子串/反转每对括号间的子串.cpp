/* 反转每对括号间的子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出一个字符串 s（仅含有小写英文字母和括号）。

请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。

注意，您的结果中 不应 包含任何括号。

 

示例 1：

输入：s = "(abcd)"
输出："dcba"
示例 2：

输入：s = "(u(love)i)"
输出："iloveu"
示例 3：

输入：s = "(ed(et(oc))el)"
输出："leetcode"
示例 4：

输入：s = "a(bcdefghijkl(mno)p)q"
输出："apmnolkjihgfedcbq"
 

提示：

0 <= s.length <= 2000
s 中只有小写英文字母和括号
我们确保所有括号都是成对出现的

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-substrings-between-each-pair-of-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        int i, size = s.size(), direction;
        vector<int> pairs(size, 0);

        getAllParenthesisPairs(s, pairs);

        string reversed;
        for (i = 0, direction = 1; i < size; i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                direction = -direction;
                i = pairs[i];
            }
            else {
                reversed += s[i];
            }
        }

        return reversed;
    }

    void getAllParenthesisPairs(string& s, vector<int>& pairs) {
        stack<int> leftIndex;
        int i, size = s.size();

        for (i = 0; i < size; ++i) {
            if (s[i] == '(') {
                leftIndex.push(i);
            }
            else if (s[i] == ')') {
                pairs[i] = leftIndex.top();
                pairs[leftIndex.top()] = i;
                leftIndex.pop();
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("zyxhikjlrstcdfeguvwba", o.reverseParentheses("(ab(cd(ef)(g)uvw)(hi(jk)(l)rst)xyz)"));
    check.checkString("ba", o.reverseParentheses("(ab)"));
    check.checkString("cdab", o.reverseParentheses("((ab)(cd))"));
    check.checkString("", o.reverseParentheses(""));
    check.checkString("a", o.reverseParentheses("a"));
    check.checkString("dcba", o.reverseParentheses("(abcd)"));
    check.checkString("iloveu", o.reverseParentheses("(u(love)i)"));
    check.checkString("leetcode", o.reverseParentheses("(ed(et(oc))el)"));
    check.checkString("apmnolkjihgfedcbq", o.reverseParentheses("a(bcdefghijkl(mno)p)q"));
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
