/* 二进制数转字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
二进制数转字符串。给定一个介于0和1之间的实数（如0.72），类型为double，打印它的二进制表达式。如果该数字无法精确地用32位以内的二进制表示，则打印“ERROR”。

示例1:

 输入：0.625
 输出："0.101"
示例2:

 输入：0.1
 输出："ERROR"
 提示：0.1无法被二进制准确表示


提示：

32位包括输出中的 "0." 这两位。
题目保证输入用例的小数位数最多只有 6 位
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string printBin(double num) {
        string ans = "0.";
        double exp = 1e-8;

        for (int i = 0; i < 30 && num >= exp; ++i) {
            num *= 2;
            if (num >= 1) {
                ans.push_back('1');
                num -= 1;
            }
            else {
                ans.push_back('0');
            }
        }

        return num < exp ? ans : "ERROR";
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("0.101", o.printBin(0.625));
    check.checkString("ERROR", o.printBin(0.1));
    check.checkString("0.1", o.printBin(0.5));
    check.checkString("ERROR", o.printBin(0.05));
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
