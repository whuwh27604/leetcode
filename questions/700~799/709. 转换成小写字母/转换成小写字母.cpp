/* 转换成小写字母.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。

 

示例 1：

输入: "Hello"
输出: "hello"
示例 2：

输入: "here"
输出: "here"
示例 3：

输入: "LOVELY"
输出: "lovely"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/to-lower-case
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        for (unsigned int i = 0; i < str.size(); i++) {
            if ((str[i] >= 'A') && (str[i] <= 'Z')) {
                str[i] += 32;
            }
        }

        return str;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("hello", o.toLowerCase("Hello"));
    check.checkString("here", o.toLowerCase("here"));
    check.checkString("lovely", o.toLowerCase("LOVELY"));
    check.checkString("", o.toLowerCase(""));
    check.checkString("l", o.toLowerCase("L"));
    check.checkString("abc def", o.toLowerCase("ABC def"));
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
