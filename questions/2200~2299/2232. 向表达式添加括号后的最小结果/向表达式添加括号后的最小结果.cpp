/* 向表达式添加括号后的最小结果.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串 expression ，格式为 "<num1>+<num2>" ，其中 <num1> 和 <num2> 表示正整数。

请你向 expression 中添加一对括号，使得在添加之后， expression 仍然是一个有效的数学表达式，并且计算后可以得到 最小 可能值。左括号 必须 添加在 '+' 的左侧，而右括号必须添加在 '+' 的右侧。

返回添加一对括号后形成的表达式 expression ，且满足 expression 计算得到 最小 可能值。如果存在多个答案都能产生相同结果，返回任意一个答案。

生成的输入满足：expression 的原始值和添加满足要求的任一对括号之后 expression 的值，都符合 32-bit 带符号整数范围。

 

示例 1：

输入：expression = "247+38"
输出："2(47+38)"
解释：表达式计算得到 2 * (47 + 38) = 2 * 85 = 170 。
注意 "2(4)7+38" 不是有效的结果，因为右括号必须添加在 '+' 的右侧。
可以证明 170 是最小可能值。
示例 2：

输入：expression = "12+34"
输出："1(2+3)4"
解释：表达式计算得到 1 * (2 + 3) * 4 = 1 * 5 * 4 = 20 。
示例 3：

输入：expression = "999+999"
输出："(999+999)"
解释：表达式计算得到 999 + 999 = 1998 。
 

提示：

3 <= expression.length <= 10
expression 仅由数字 '1' 到 '9' 和 '+' 组成
expression 由数字开始和结束
expression 恰好仅含有一个 '+'.
expression 的原始值和添加满足要求的任一对括号之后 expression 的值，都符合 32-bit 带符号整数范围

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimize-result-by-adding-parentheses-to-expression
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string minimizeResult(string expression) {
        int i, j, size = expression.size(), add = expression.find('+');
        long long minResult = LLONG_MAX;
        string ans;

        for (i = 0; i < add; ++i) {
            for (j = add + 1; j < size; ++j) {
                string a(expression, 0, i), b(expression, i, add - i), c(expression, add + 1, j - add), d(expression, j + 1, size - 1 - j);
                long long result = (a.empty() ? 1 : stoll(a)) * (stoll(b) + stoll(c)) * (d.empty() ? 1 : stoll(d));

                if (result < minResult) {
                    minResult = result;
                    ans = a + '(' + b + '+' + c + ')' + d;
                }
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("2(47+38)", o.minimizeResult("247+38"));
    check.checkString("1(2+3)4", o.minimizeResult("12+34"));
    check.checkString("(999+999)", o.minimizeResult("999+999"));
    check.checkString("2(47+38)", o.minimizeResult("247+38"));
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
