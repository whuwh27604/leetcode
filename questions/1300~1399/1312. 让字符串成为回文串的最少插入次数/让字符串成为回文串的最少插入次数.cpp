/* 让字符串成为回文串的最少插入次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符。

请你返回让 s 成为回文串的 最少操作次数 。

「回文串」是正读和反读都相同的字符串。

 

示例 1：

输入：s = "zzazz"
输出：0
解释：字符串 "zzazz" 已经是回文串了，所以不需要做任何插入操作。
示例 2：

输入：s = "mbadm"
输出：2
解释：字符串可变为 "mbdadbm" 或者 "mdbabdm" 。
示例 3：

输入：s = "leetcode"
输出：5
解释：插入 5 个字符后字符串变为 "leetcodocteel" 。
示例 4：

输入：s = "g"
输出：0
示例 5：

输入：s = "no"
输出：1
 

提示：

1 <= s.length <= 500
s 中所有字符都是小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-insertion-steps-to-make-a-string-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int i, j, len, size = s.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));  // dp[i][j]表示将区间[i,j]变为回文串需要的最小操作次数

        for (i = 0; i < size - 1; ++i) {
            dp[i][i + 1] = s[i] == s[i + 1] ? 0 : 1;  // len = 2
        }

        for (len = 3; len <= size; ++len) {
            for (i = 0; i <= size - len; ++i) {
                j = i + len - 1;
                dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }

        return dp[0][size - 1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(0, o.minInsertions("zzazz"));
    check.checkInt(2, o.minInsertions("mbadm"));
    check.checkInt(5, o.minInsertions("leetcode"));
    check.checkInt(0, o.minInsertions("g"));
    check.checkInt(1, o.minInsertions("no"));
    check.checkInt(15, o.minInsertions("qyeryeryrqiyerqieyrqeyoieyrqiyro"));
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
