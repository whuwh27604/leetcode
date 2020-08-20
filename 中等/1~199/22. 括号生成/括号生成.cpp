/* 括号生成.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例：

输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/generate-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <list>
#include "../check/CheckResult.h"

using namespace std;

struct parenthesisNode {
    string parenthesis;
    int left;
    int right;
    parenthesisNode(string s, int l, int r) : parenthesis(s), left(l), right(r) {}
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return {};
        }

        list<parenthesisNode> allParenthesis;
        parenthesisNode node("(", 1, 0);
        allParenthesis.push_back(node);

        for (int i = 2; i <= n * 2; i++) {
            int len = allParenthesis.size();
            for (int j = 0; j < len; j++) {
                node = allParenthesis.front();
                allParenthesis.pop_front();

                if (node.left < n) {
                    parenthesisNode newNode = node;
                    newNode.parenthesis += '(';
                    newNode.left++;
                    allParenthesis.push_back(newNode);
                }

                if (node.right < node.left) {
                    node.parenthesis += ')';
                    node.right++;
                    allParenthesis.push_back(node);
                }
            }
        }

        vector<string> ans;
        for (auto iter = allParenthesis.begin(); iter != allParenthesis.end(); iter++) {
            ans.push_back((*iter).parenthesis);
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> actual = o.generateParenthesis(1);
    vector<string> expected = { "()" };
    check.checkStringVector(expected, actual);

    actual = o.generateParenthesis(2);
    expected = { "(())","()()" };
    check.checkStringVector(expected, actual);

    actual = o.generateParenthesis(3);
    expected = { "((()))","(()())","(())()","()(())","()()()" };
    check.checkStringVector(expected, actual);

    actual = o.generateParenthesis(4);
    expected = { "(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()" };
    check.checkStringVector(expected, actual);

    actual = o.generateParenthesis(0);
    expected = {  };
    check.checkStringVector(expected, actual);
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
