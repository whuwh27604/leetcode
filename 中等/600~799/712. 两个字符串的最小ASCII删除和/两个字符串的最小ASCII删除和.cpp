/* 两个字符串的最小ASCII删除和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个字符串s1, s2，找到使两个字符串相等所需删除字符的ASCII值的最小和。

示例 1:

输入: s1 = "sea", s2 = "eat"
输出: 231
解释: 在 "sea" 中删除 "s" 并将 "s" 的值(115)加入总和。
在 "eat" 中删除 "t" 并将 116 加入总和。
结束时，两个字符串相等，115 + 116 = 231 就是符合条件的最小和。
示例 2:

输入: s1 = "delete", s2 = "leet"
输出: 403
解释: 在 "delete" 中删除 "dee" 字符串变成 "let"，
将 100[d]+101[e]+101[e] 加入总和。在 "leet" 中删除 "e" 将 101[e] 加入总和。
结束时，两个字符串都等于 "let"，结果即为 100+101+101+101 = 403 。
如果改为将两个字符串转换为 "lee" 或 "eet"，我们会得到 433 或 417 的结果，比答案更大。
注意:

0 < s1.length, s2.length <= 1000。
所有字符串中的字符ASCII值在[97, 122]之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-ascii-delete-sum-for-two-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        /* 令dp[i][j]表示s1[0,i]和s2[0,j]相等需要删除的最小和
           如果s1[i]==s2[j]，则dp[i][j]==dp[i-1][j-1]
           如果s1[i]!=s2[j]，则dp[i][j]=min(dp[i][j-1]+s2[j], dp[i-1][j]+s1[i]) */
        int i, j, size1 = s1.size(), size2 = s2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));

        for (i = 1; i <= size1; i++) {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }

        for (j = 1; j <= size2; j++) {
            dp[0][j] = dp[0][j - 1] + s2[j - 1];
        }

        for (i = 1; i <= size1; i++) {
            for (j = 1; j <= size2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i][j - 1] + s2[j - 1], dp[i - 1][j] + s1[i - 1]);
                }
            }
        }

        return dp[size1][size2];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.minimumDeleteSum("a", "a"));
    check.checkInt(195, o.minimumDeleteSum("a", "b"));
    check.checkInt(98, o.minimumDeleteSum("a", "ab"));
    check.checkInt(194, o.minimumDeleteSum("ab", "ba"));
    check.checkInt(231, o.minimumDeleteSum("sea", "eat"));
    check.checkInt(403, o.minimumDeleteSum("delete", "leet"));
    check.checkInt(2255, o.minimumDeleteSum("xnbteodleejrzeo", "gaouojqkkk"));
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
