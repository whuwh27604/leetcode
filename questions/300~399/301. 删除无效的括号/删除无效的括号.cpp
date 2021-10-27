/* 删除无效的括号.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。

返回所有可能的结果。答案可以按 任意顺序 返回。

 

示例 1：

输入：s = "()())()"
输出：["(())()","()()()"]
示例 2：

输入：s = "(a)())()"
输出：["(a())()","(a)()()"]
示例 3：

输入：s = ")("
输出：[""]
 

提示：

1 <= s.length <= 25
s 由小写英文字母以及括号 '(' 和 ')' 组成
s 中至多含 20 个括号

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-invalid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> validParentheses;
        unordered_set<string> visited;
        queue<string> strs;
        bool find = false;

        strs.push(s);

        while (!find && !strs.empty()) {
            int i, size = strs.size();

            for (i = 0; i < size; ++i) {
                string str = strs.front();
                strs.pop();

                if (isValid(str)) {
                    validParentheses.push_back(str);
                    find = true;
                }
                else {
                    for (int j = 0; j < (int)str.size(); ++j) {
                        if (str[j] == '(' || str[j] == ')') {
                            string next = str;
                            next.erase(j, 1);

                            if (visited.count(next) == 0) {
                                visited.insert(next);
                                strs.push(next);
                            }
                        }
                    }
                }
            }
        }

        return validParentheses;
    }

    bool isValid(string& str) {
        int count = 0;

        for (char c : str) {
            if (c == '(') {
                ++count;
            }
            else if (c == ')') {
                if (--count < 0) {
                    return false;
                }
            }
        }

        return count == 0;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> actual = o.removeInvalidParentheses("()())()");
    vector<string> expected = { "(())()","()()()" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.removeInvalidParentheses("(a)())()");
    expected = { "(a())()","(a)()()" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.removeInvalidParentheses(")(");
    expected = { "" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.removeInvalidParentheses("(");
    expected = { "" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.removeInvalidParentheses("z");
    expected = { "z" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.removeInvalidParentheses("))))))))z)z)z(z(z((((((((");
    expected = { "zzzzz" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.removeInvalidParentheses("(((k()((");
    expected = { "k()","(k)" };
    check.checkStringVectorRandomOrder(expected, actual);
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
