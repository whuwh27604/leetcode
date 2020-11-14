/* 反转字符串中的单词 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

 

示例：

输入："Let's take LeetCode contest"
输出："s'teL ekat edoCteeL tsetnoc"
 

提示：

在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int start = 0, end;

        while ((end = s.find(' ', start)) != s.npos) {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }

        reverse(s.begin() + start, s.end());

        return s;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkString("s'teL ekat edoCteeL tsetnoc", o.reverseWords("Let's take LeetCode contest"));
    check.checkString("s'teL", o.reverseWords("Let's"));
    check.checkString("", o.reverseWords(""));
    check.checkString("s", o.reverseWords("s"));
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
