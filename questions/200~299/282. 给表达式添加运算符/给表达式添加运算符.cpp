/* 给表达式添加运算符.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个仅包含数字 0-9 的字符串 num 和一个目标值整数 target ，在 num 的数字之间添加 二元 运算符（不是一元）+、- 或 * ，返回所有能够得到目标值的表达式。

 

示例 1:

输入: num = "123", target = 6
输出: ["1+2+3", "1*2*3"]
示例 2:

输入: num = "232", target = 8
输出: ["2*3+2", "2+3*2"]
示例 3:

输入: num = "105", target = 5
输出: ["1*0+5","10-5"]
示例 4:

输入: num = "00", target = 0
输出: ["0+0", "0-0", "0*0"]
示例 5:

输入: num = "3456237490", target = 9191
输出: []
 

提示：

1 <= num.length <= 10
num 仅含数字
-231 <= target <= 231 - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/expression-add-operators
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> expressions;

        DFS(num, 0, 0, 0, target, "", expressions);

        return expressions;
    }

    void DFS(string& num, int index, long long prev, long long current, int target, string expression, vector<string>& expressions) {
        int i, size = num.size();

        if (index == size) {
            if (current == target) {
                expressions.push_back(expression);
            }

            return;
        }

        for (i = index; i < size; ++i) {
            if (num[index] == '0' && i != index) {
                break;  // 如果当前是0，那么只能作为0来处理，不能作为其它数的前导0
            }

            long long next = stoll(string(num, index, i + 1 - index));

            if (index == 0) {
                DFS(num, i + 1, next, next, target, to_string(next), expressions);
            }
            else {
                DFS(num, i + 1, next, current + next, target, expression + "+" + to_string(next), expressions);
                DFS(num, i + 1, -next, current - next, target, expression + "-" + to_string(next), expressions);
                long long product = prev * next;
                DFS(num, i + 1, product, current - prev + product, target, expression + "*" + to_string(next), expressions);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> actual = o.addOperators("123", 6);
    vector<string> expected = { "1+2+3","1*2*3" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.addOperators("232", 8);
    expected = { "2*3+2","2+3*2" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.addOperators("105", 5);
    expected = { "1*0+5","10-5" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.addOperators("00", 0);
    expected = { "0+0","0-0","0*0" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.addOperators("3456237490", 9191);
    expected = {  };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.addOperators("102", 3);
    expected = { "1+0+2","1-0+2" };
    check.checkStringVectorRandomOrder(expected, actual);

    actual = o.addOperators("2147483648", -2147483648);
    expected = {  };
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
