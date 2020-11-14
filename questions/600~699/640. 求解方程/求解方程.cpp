/* 求解方程.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
求解一个给定的方程，将x以字符串"x=#value"的形式返回。该方程仅包含'+'，' - '操作，变量 x 和其对应系数。

如果方程没有解，请返回“No solution”。

如果方程有无限解，则返回“Infinite solutions”。

如果方程中只有一个解，要保证返回值 x 是一个整数。

示例 1：

输入: "x+5-3+x=6+x-2"
输出: "x=2"
示例 2:

输入: "x=x"
输出: "Infinite solutions"
示例 3:

输入: "2x=x"
输出: "x=0"
示例 4:

输入: "2x+3x-6x=x+2"
输出: "x=-1"
示例 5:

输入: "x=x+2"
输出: "No solution"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/solve-the-equation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
        int a = 0, b = 0, size = equation.size();
        int position = equation.find('=');
        parse(equation, 0, position, a, b);
        parse(equation, position + 1, size, a, b);

        if (a == 0) {
            if (b == 0) {
                return "Infinite solutions";
            }
            else {
                return "No solution";
            }
        }

        return "x=" + to_string(-b / a);
    }

    void parse(string& equation, int from, int to, int& a, int& b) {
        bool negative = false;
        int num;

        for (int i = from; i < to; i++) {
            if (equation[i] == '+') {
                negative = false;
            }
            else if (equation[i] == '-') {
                negative = true;
            }
            else if (equation[i] == 'x') {
                if ((i == from) || (equation[i - 1] == '+') || (equation[i - 1] == '-')) {
                    num = 1;
                    if (negative) {
                        num = -num;
                    }
                    if (from != 0) {
                        num = -num;
                    }
                    a += num;
                }
            }
            else if ((equation[i] >= '0') && (equation[i] <= '9')) {
                int next;
                num = getNumber(equation, i, next);
                if (negative) {
                    num = -num;
                }
                if (from != 0) {
                    num = -num;
                }

                if (equation[next] == 'x') {
                    a += num;
                }
                else {
                    b += num;
                }

                i = next - 1;
            }
        }
    }

    int getNumber(string& equation, int index, int& next) {
        int num = 0;

        while ((equation[index] >= '0') && (equation[index] <= '9')) {
            num = num * 10 + equation[index++] - '0';
        }

        next = index;
        return num;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("x=2", o.solveEquation("x+5-3+x=6+x-2"));
    check.checkString("Infinite solutions", o.solveEquation("x=x"));
    check.checkString("x=0", o.solveEquation("2x=x"));
    check.checkString("x=-1", o.solveEquation("2x+3x-6x=x+2"));
    check.checkString("No solution", o.solveEquation("x=x+2"));
    check.checkString("Infinite solutions", o.solveEquation("0x=0"));
    check.checkString("x=1", o.solveEquation("1+x=2"));
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
