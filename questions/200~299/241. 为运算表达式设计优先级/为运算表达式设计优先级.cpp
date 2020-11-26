/* 为运算表达式设计优先级.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。

示例 1:

输入: "2-1-1"
输出: [0, 2]
解释:
((2-1)-1) = 0
(2-(1-1)) = 2
示例 2:

输入: "2*3-4*5"
输出: [-34, -14, -10, -10, 10]
解释:
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/different-ways-to-add-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<string> expression;
        parse(input, expression);

        unordered_map<int, vector<int>> memo;
        return diffWaysToCompute(expression, 0, expression.size() - 1, memo);
    }

    void parse(string& input, vector<string>& expression) {
        int start = 0, end, size = input.size();

        for (end = 0; end < size; ++end) {
            char c = input[end];
            if (c == '+' || c == '-' || c == '*') {
                string num(input, start, end - start);
                expression.push_back(num);
                string oper(1, c);
                expression.push_back(oper);
                start = end + 1;
            }
        }

        string num(input, start, end - start);
        expression.push_back(num);
    }

    vector<int> diffWaysToCompute(vector<string>& expression, int start, int end, unordered_map<int, vector<int>>& memo) {
        int key = (start << 16) + end;
        if (memo.count(key) != 0) {
            return memo[key];
        }

        vector<int> result;
        if (start == end) {
            result = { stoi(expression[start]) };
        }
        else {
            for (int i = start + 1; i < end; i += 2) {
                vector<int> leftResult = diffWaysToCompute(expression, start, i - 1, memo);
                vector<int> rightResult = diffWaysToCompute(expression, i + 1, end, memo);

                for (int left : leftResult) {
                    for (int right : rightResult) {
                        if (expression[i] == "+") {
                            result.push_back(left + right);
                        }
                        else if (expression[i] == "-") {
                            result.push_back(left - right);
                        }
                        else {
                            result.push_back(left * right);
                        }
                    }
                }
            }
        }

        memo[key] = result;
        return result;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = o.diffWaysToCompute("5");
    vector<int> expected = { 5 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.diffWaysToCompute("2-1-1");
    expected = { 0,2 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.diffWaysToCompute("2*3-4*5");
    expected = { -34,-14,-10,-10,10 };
    check.checkIntVectorRandomOrder(expected, actual);

    actual = o.diffWaysToCompute("1+2*3-4*5+6-7");
    expected = { -144,-130,-102,-95,-90,-88,-88,-76,-67,-59,-54,-54,-54,-52,-52,-52,-52,-48,-48,-44,-44,-44,-42,-40,-40,-40,-39,-39,-35,-35,-35,-34,-34,-34,-34,-34,-31,-31,-30,-30,-28,-28,-28,-28,-28,-28,-28,-26,-26,-26,-25,-25,-24,-18,-18,-18,-16,-16,-16,-16,-14,-14,-14,-14,-14,-14,-14,-12,-12,-12,-12,-12,-12,-12,-12,-12,-12,-11,-11,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-10,-9,-9,-9,-9,-7,-7,-7,-7,-7,-7,-6,-6,-4,-4,-4,-4,-4,9,9,10,10,10,10,10,12,12,12,12,14,14,14,14,16,16,20,20,24,24,26,26,48 };
    check.checkIntVectorRandomOrder(expected, actual);
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
