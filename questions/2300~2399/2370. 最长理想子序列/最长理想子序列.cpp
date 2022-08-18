/* 最长理想子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由小写字母组成的字符串 s ，和一个整数 k 。如果满足下述条件，则可以将字符串 t 视作是 理想字符串 ：

t 是字符串 s 的一个子序列。
t 中每两个 相邻 字母在字母表中位次的绝对差值小于或等于 k 。
返回 最长 理想字符串的长度。

字符串的子序列同样是一个字符串，并且子序列还满足：可以经由其他字符串删除某些字符（也可以不删除）但不改变剩余字符的顺序得到。

注意：字母表顺序不会循环。例如，'a' 和 'z' 在字母表中位次的绝对差值是 25 ，而不是 1 。

 

示例 1：

输入：s = "acfgbd", k = 2
输出：4
解释：最长理想字符串是 "acbd" 。该字符串长度为 4 ，所以返回 4 。
注意 "acfgbd" 不是理想字符串，因为 'c' 和 'f' 的字母表位次差值为 3 。
示例 2：

输入：s = "abcd", k = 3
输出：4
解释：最长理想字符串是 "abcd" ，该字符串长度为 4 ，所以返回 4 。
 

提示：

1 <= s.length <= 105
0 <= k <= 25
s 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-ideal-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        int i, j, size = s.size(), maxIdealString = 0;
        vector<int> longestStrs(26, 0);

        for (i = size - 1; i >= 0; --i) {
            int index = s[i] - 'a';
            ++longestStrs[index];

            for (j = 1; j <= k; ++j) {
                if (index - j >= 0) {
                    longestStrs[index] = max(longestStrs[index], longestStrs[index - j] + 1);
                }

                if (index + j < 26) {
                    longestStrs[index] = max(longestStrs[index], longestStrs[index + j] + 1);
                }
            }

            maxIdealString = max(maxIdealString, longestStrs[index]);
        }

        return maxIdealString;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.longestIdealString("acfgbd", 2));
    check.checkInt(4, o.longestIdealString("abcd", 3));
    check.checkInt(1, o.longestIdealString("z", 2));
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
