/* 最长快乐前缀.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
「快乐前缀」 是在原字符串中既是 非空 前缀也是后缀（不包括原字符串自身）的字符串。

给你一个字符串 s，请你返回它的 最长快乐前缀。如果不存在满足题意的前缀，则返回一个空字符串 "" 。

 

示例 1：

输入：s = "level"
输出："l"
解释：不包括 s 自己，一共有 4 个前缀（"l", "le", "lev", "leve"）和 4 个后缀（"l", "el", "vel", "evel"）。最长的既是前缀也是后缀的字符串是 "l" 。
示例 2：

输入：s = "ababab"
输出："abab"
解释："abab" 是最长的既是前缀也是后缀的字符串。题目允许前后缀在原字符串中重叠。
 

提示：

1 <= s.length <= 105
s 只含有小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-happy-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int i, j, size = s.size();
        vector<int> next(size, -1);

        for (i = 1; i < size; ++i) {  // 构建KMP算法的next表
            j = next[i - 1];

            while (j != -1 && s[j + 1] != s[i]) {
                j = next[j];
            }

            if (s[j + 1] == s[i]) {
                next[i] = j + 1;
            }
        }

        return string(s, 0, next[size - 1] + 1);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("l", o.longestPrefix("level"));
    check.checkString("abab", o.longestPrefix("ababab"));
    check.checkString("", o.longestPrefix("z"));
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
