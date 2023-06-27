/* 构造最长的新字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
这三个整数表示你有 x 个 "AA" 字符串，y 个 "BB" 字符串，和 z 个 "AB" 字符串。你需要选择这些字符串中的部分字符串（可以全部选择也可以一个都不选择），将它们按顺序连接得到一个新的字符串。新字符串不能包含子字符串 "AAA" 或者 "BBB" 。

请你返回新字符串的最大可能长度。

子字符串 是一个字符串中一段连续 非空 的字符序列。



示例 1：

输入：x = 2, y = 5, z = 1
输出：12
解释： 我们可以按顺序连接 "BB" ，"AA" ，"BB" ，"AA" ，"BB" 和 "AB" ，得到新字符串 "BBAABBAABBAB" 。
字符串长度为 12 ，无法得到一个更长的符合题目要求的字符串。
示例 2：

输入：x = 3, y = 2, z = 2
输出：14
解释：我们可以按顺序连接 "AB" ，"AB" ，"AA" ，"BB" ，"AA" ，"BB" 和 "AA" ，得到新字符串 "ABABAABBAABBAA" 。
字符串长度为 14 ，无法得到一个更长的符合题目要求的字符串。


提示：

1 <= x, y, z <= 50
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestString(int x, int y, int z) {
        // 1、AA与BB只能交替出现；2、AB显然可以全选；3、不论AB如何放置，不改变结论1，AA与BB仍然只能交替出现
        int n = min(x, y);
        n *= 2;  // 选相同个数的x、y
        n += (x == y ? 0 : 1);  // 如果x != y，可以多选一个
        n += z;  // z可以全部选上
        n *= 2;  // 每个的长度为2

        return n;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(12, o.longestString(2, 5, 1));
    check.checkInt(14, o.longestString(3, 2, 2));
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
