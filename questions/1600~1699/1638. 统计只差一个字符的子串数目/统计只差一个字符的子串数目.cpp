/* 统计只差一个字符的子串数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 s 和 t ，请你找出 s 中的非空子串的数目，这些子串满足替换 一个不同字符 以后，是 t 串的子串。换言之，请你找到 s 和 t 串中 恰好 只有一个字符不同的子字符串对的数目。

比方说， "computer" 和 "computation" 加粗部分只有一个字符不同： 'e'/'a' ，所以这一对子字符串会给答案加 1 。

请你返回满足上述条件的不同子字符串对数目。

一个 子字符串 是一个字符串中连续的字符。

 

示例 1：

输入：s = "aba", t = "baba"
输出：6
解释：以下为只相差 1 个字符的 s 和 t 串的子字符串对：
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
("aba", "baba")
加粗部分分别表示 s 和 t 串选出来的子字符串。
示例 2：
输入：s = "ab", t = "bb"
输出：3
解释：以下为只相差 1 个字符的 s 和 t 串的子字符串对：
("ab", "bb")
("ab", "bb")
("ab", "bb")
加粗部分分别表示 s 和 t 串选出来的子字符串。
示例 3：
输入：s = "a", t = "a"
输出：0
示例 4：

输入：s = "abe", t = "bbc"
输出：10
 

提示：

1 <= s.length, t.length <= 100
s 和 t 都只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-substrings-that-differ-by-one-character
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countSubstrings(string s, string t) {
        int i, j, sizeS = s.size(), sizeT = t.size(), count = 0;
        vector<vector<int>> dpSame(sizeS + 1, vector<int>(sizeT + 1, 0));  // dp[i+1][j+1]表示以s[i]、t[j]为尾部的子串完全相等的长度
        vector<vector<int>> dpOneDiff(sizeS + 1, vector<int>(sizeT + 1, 0));  // dp[i+1][j+1]表示以s[i]、t[j]为尾部的子串只有一个字符不同的长度

        for (i = 0; i < sizeS; ++i) {
            for (j = 0; j < sizeT; ++j) {
                if (s[i] == t[j]) {
                    dpSame[i + 1][j + 1] = dpSame[i][j] + 1;  // 当前字符相同，那么相同的长度继续加1
                    dpOneDiff[i + 1][j + 1] = dpOneDiff[i][j];  // 不同的长度保持不变
                }
                else {
                    // dpSame[i + 1][j + 1] = 0;  // 当前字符不同，那么相同长度清零。由于已经初始化为0，该语句可以省略
                    dpOneDiff[i + 1][j + 1] = dpSame[i][j] + 1;  // 不同长度为前一个相同长度加上现在不同的1个字符
                }

                count += dpOneDiff[i + 1][j + 1];  // 统计以s[i]、t[j]为尾部的差1字符串
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(6, o.countSubstrings("aba", "baba"));
    check.checkInt(3, o.countSubstrings("ab", "bb"));
    check.checkInt(0, o.countSubstrings("a", "a"));
    check.checkInt(10, o.countSubstrings("abe", "bbc"));
    check.checkInt(42, o.countSubstrings("aaaxbb", "aaaybb"));
    check.checkInt(655, o.countSubstrings("aaaxbbxaaaaxbbbbbxaaxb", "aaaybbyaaaaybbbbbyaayb"));
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
