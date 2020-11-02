/* 替换空格.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."
 

限制：

0 <= s 的长度 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int space = -1, start = 0;
        string replaced;

        while ((space = s.find(' ', start)) != s.npos) {
            if (start < space) {
                replaced.append(s, start, space - start);
            }

            replaced += "%20";
            start = space + 1;
        }

        replaced.append(s, start, s.size() - start);

        return replaced;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("We%20are%20happy.", o.replaceSpace("We are happy."));
    check.checkString("%20We%20are%20happy.", o.replaceSpace(" We are happy."));
    check.checkString("We%20are%20happy.%20", o.replaceSpace("We are happy. "));
    check.checkString("", o.replaceSpace(""));
    check.checkString("W", o.replaceSpace("W"));
    check.checkString("%20%20%20", o.replaceSpace("   "));
    check.checkString("%20%20a%20%20b%20%20c%20%20", o.replaceSpace("  a  b  c  "));
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
