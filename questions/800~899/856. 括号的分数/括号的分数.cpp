/* 括号的分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：

() 得 1 分。
AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
(A) 得 2 * A 分，其中 A 是平衡括号字符串。
 

示例 1：

输入： "()"
输出： 1
示例 2：

输入： "(())"
输出： 2
示例 3：

输入： "()()"
输出： 2
示例 4：

输入： "(()(()))"
输出： 6
 

提示：

S 是平衡括号字符串，且只含有 ( 和 ) 。
2 <= S.length <= 50

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/score-of-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> score;

        for (char c : S) {
            if (c == '(') {
                score.push(-1);
                continue;
            }

            if (score.top() == -1) {
                score.pop();
                score.push(1);
                continue;
            }

            int num = 0;
            while (score.top() != -1) {
                num += score.top();
                score.pop();
            }

            score.pop();
            score.push(num * 2);
        }

        int num = 0;
        while (!score.empty()) {
            num += score.top();
            score.pop();
        }

        return num;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(1, o.scoreOfParentheses("()"));
    check.checkInt(2, o.scoreOfParentheses("(())"));
    check.checkInt(2, o.scoreOfParentheses("()()"));
    check.checkInt(6, o.scoreOfParentheses("(()(()))"));
    check.checkInt(16777216, o.scoreOfParentheses("((((((((((((((((((((((((()))))))))))))))))))))))))"));
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
