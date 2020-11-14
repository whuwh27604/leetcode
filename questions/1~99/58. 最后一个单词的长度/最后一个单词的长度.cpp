/* 最后一个单词的长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。

 

示例:

输入: "Hello World"
输出: 5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/length-of-last-word
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int lenOfLast = 0;
        bool startCount = false;
        int len = s.size();
        if (len == 0) {
            return 0;
        }

        for (int i = len - 1; i >= 0; i--) {
            if (((s[i] >= 'a') && (s[i] <= 'z')) || ((s[i] >= 'A') && (s[i] <= 'Z'))) {
                startCount = true;
                lenOfLast++;
            }

            if (s[i] == ' ') {
                if (startCount) {
                    return lenOfLast;
                }
            }
        }

        if (startCount) {
            return lenOfLast;
        }
        return 0;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string s = "";
    check.checkInt(0, o.lengthOfLastWord(s));

    s = "     ";
    check.checkInt(0, o.lengthOfLastWord(s));

    s = "Hello World";
    check.checkInt(5, o.lengthOfLastWord(s));

    s = " aaa bbbb ";
    check.checkInt(4, o.lengthOfLastWord(s));

    s = " aaa bbbb";
    check.checkInt(4, o.lengthOfLastWord(s));

    s = "aaa bbbb ";
    check.checkInt(4, o.lengthOfLastWord(s));

    s = "aaaa";
    check.checkInt(4, o.lengthOfLastWord(s));

    s = " aaa";
    check.checkInt(3, o.lengthOfLastWord(s));

    s = "aa  ";
    check.checkInt(2, o.lengthOfLastWord(s));

    s = "  aaaaa  ";
    check.checkInt(5, o.lengthOfLastWord(s));

    s = "a";
    check.checkInt(1, o.lengthOfLastWord(s));

    s = "a ";
    check.checkInt(1, o.lengthOfLastWord(s));

    s = " a";
    check.checkInt(1, o.lengthOfLastWord(s));

    s = " a ";
    check.checkInt(1, o.lengthOfLastWord(s));
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
