/* 最长特殊序列 Ⅰ.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串，请你从这两个字符串中找出最长的特殊序列。

「最长特殊序列」定义如下：该序列为某字符串独有的最长子序列（即不能是其他字符串的子序列）。

子序列 可以通过删去字符串中的某些字符实现，但不能改变剩余字符的相对顺序。空序列为所有字符串的子序列，任何字符串为其自身的子序列。

输入为两个字符串，输出最长特殊序列的长度。如果不存在，则返回 -1。

 

示例 1：

输入: "aba", "cdc"
输出: 3
解释: 最长特殊序列可为 "aba" (或 "cdc")，两者均为自身的子序列且不是对方的子序列。
示例 2：

输入：a = "aaa", b = "bbb"
输出：3
示例 3：

输入：a = "aaa", b = "aaa"
输出：-1
 

提示：

两个字符串长度均处于区间 [1 - 100] 。
字符串中的字符仅含有 'a'~'z' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-uncommon-subsequence-i
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        int lenA = a.size();
        int lenB = b.size();

        if (lenA != lenB) {
            return ((lenA > lenB) ? lenA : lenB);
        }

        if (a == b) {
            return -1;
        }

        return lenA;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(3, o.findLUSlength("aba", "cdc"));
    check.checkInt(3, o.findLUSlength("aaa", "bbb"));
    check.checkInt(-1, o.findLUSlength("aaa", "aaa"));
    check.checkInt(4, o.findLUSlength("aba", "abac"));
    check.checkInt(1, o.findLUSlength("a", "b"));
    check.checkInt(3, o.findLUSlength("a", "cdc"));
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
