/* 使字符串平衡的最少删除次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，它仅包含字符 'a' 和 'b'​​​​ 。

你可以删除 s 中任意数目的字符，使得 s 平衡 。我们称 s 平衡的 当不存在下标对 (i,j) 满足 i < j 且 s[i] = 'b' 同时 s[j]= 'a' 。

请你返回使 s 平衡 的 最少 删除次数。

 

示例 1：

输入：s = "aababbab"
输出：2
解释：你可以选择以下任意一种方案：
下标从 0 开始，删除第 2 和第 6 个字符（"aababbab" -> "aaabbb"），
下标从 0 开始，删除第 3 和第 6 个字符（"aababbab" -> "aabbbb"）。
示例 2：

输入：s = "bbaaaaabb"
输出：2
解释：唯一的最优解是删除最前面两个字符。
 

提示：

1 <= s.length <= 105
s[i] 要么是 'a' 要么是 'b'​ 。​

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-deletions-to-make-string-balanced
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int countB = 0, dp = 0;  // 令dp表示将s[0,i]变平衡最少需要删除的次数

        for (char c : s) {
            if (c == 'a') {
                dp = min(dp + 1, countB);  // 末尾出现a的时候，2个选择：1、删除这个a，然后将s[0,i-1]变平衡；2、保留这个a，删除前面所有的b
            }
            else {
                ++countB;  // 出现b的时候，最后面的b不需要删除，dp不变，b的个数加1就好
            }
        }

        return dp;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.minimumDeletions("aababbab"));
    check.checkInt(2, o.minimumDeletions("bbaaaaabb"));
    check.checkInt(1, o.minimumDeletions("ba"));
    check.checkInt(0, o.minimumDeletions("a"));
    check.checkInt(12, o.minimumDeletions("ababababababababababababa"));
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
