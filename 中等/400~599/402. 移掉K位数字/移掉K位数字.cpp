/* 移掉K位数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意:

num 的长度小于 10002 且 ≥ k。
num 不会包含任何前导零。
示例 1 :

输入: num = "1432219", k = 3
输出: "1219"
解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
示例 2 :

输入: num = "10200", k = 1
输出: "200"
解释: 移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。
示例 3 :

输入: num = "10", k = 2
输出: "0"
解释: 从原数字移除所有的数字，剩余为空就是0。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-k-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> noLessNumIndexs;

        for (int times = 0; times < k; times++) {
            if (noLessNumIndexs.empty()) {
                noLessNumIndexs.push(0);
            }

            int index = noLessNumIndexs.top(), size = num.size(), prev = num[index++] - '0';
            while ((index < size) && (num[index] - '0' >= prev)) {
                prev = num[index] - '0';
                noLessNumIndexs.push(index++);
            }

            num.erase(index - 1, 1);
            noLessNumIndexs.pop();
        }

        while (!num.empty() && (num[0] == '0')) {
            num.erase(0, 1);
        }
        
        return num.empty() ? "0" : num;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("1219", o.removeKdigits("1432219", 3));
    check.checkString("200", o.removeKdigits("10200", 1));
    check.checkString("0", o.removeKdigits("10200", 2));
    check.checkString("0", o.removeKdigits("10", 2));
    check.checkString("123", o.removeKdigits("12345", 2));
    check.checkString("0", o.removeKdigits("12345", 5));
    check.checkString("0", o.removeKdigits("120", 2));
    check.checkString("21", o.removeKdigits("54321", 3));
    check.checkString("212345", o.removeKdigits("345234512345", 6));
    check.checkString("4050", o.removeKdigits("304050203040501020304050", 10));
    check.checkString("534", o.removeKdigits("7658765934", 7));
    check.checkString("5090304", o.removeKdigits("7060508070605090304", 6));
    check.checkString("0", o.removeKdigits("0", 0));
    check.checkString("0", o.removeKdigits("0", 1));
    check.checkString("123", o.removeKdigits("123", 0));
    check.checkString("112", o.removeKdigits("1122334", 4));
    check.checkString("221", o.removeKdigits("4422331", 4));
    check.checkString("33", o.removeKdigits("5337", 2));
    check.checkString("435", o.removeKdigits("100435", 1));
    check.checkString("35", o.removeKdigits("100435", 2));
    check.checkString("3", o.removeKdigits("100435", 3));
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
