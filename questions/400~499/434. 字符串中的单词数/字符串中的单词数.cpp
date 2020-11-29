/* 字符串中的单词数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。

请注意，你可以假定字符串里不包括任何不可打印的字符。

示例:

输入: "Hello, my name is John"
输出: 5
解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-segments-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        bool start = false;
        int count = 0;
        s.push_back(' ');

        for (unsigned int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                start = true;
                continue;
            }

            if (start == true) {
                count++;
                start = false;
            }
        }

        s.pop_back();
        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string s = "Hello, my name is John";
    check.checkInt(5, o.countSegments(s));

    s = "";
    check.checkInt(0, o.countSegments(s));

    s = "a";
    check.checkInt(1, o.countSegments(s));

    s = "aaa";
    check.checkInt(1, o.countSegments(s));

    s = " 1 2  3";
    check.checkInt(3, o.countSegments(s));

    s = "  1 2  3 ";
    check.checkInt(3, o.countSegments(s));

    s = "  1 2  , ..   ";
    check.checkInt(4, o.countSegments(s));
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
