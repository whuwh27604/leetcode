/* 通过给定词典构造目标字符串的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串列表 words 和一个目标字符串 target 。words 中所有字符串都 长度相同  。

你的目标是使用给定的 words 字符串列表按照下述规则构造 target ：

从左到右依次构造 target 的每一个字符。
为了得到 target 第 i 个字符（下标从 0 开始），当 target[i] = words[j][k] 时，你可以使用 words 列表中第 j 个字符串的第 k 个字符。
一旦你使用了 words 中第 j 个字符串的第 k 个字符，你不能再使用 words 字符串列表中任意单词的第 x 个字符（x <= k）。也就是说，所有单词下标小于等于 k 的字符都不能再被使用。
请你重复此过程直到得到目标字符串 target 。
请注意， 在构造目标字符串的过程中，你可以按照上述规定使用 words 列表中 同一个字符串 的 多个字符 。

请你返回使用 words 构造 target 的方案数。由于答案可能会很大，请对 109 + 7 取余 后返回。

（译者注：此题目求的是有多少个不同的 k 序列，详情请见示例。）

 

示例 1：

输入：words = ["acca","bbbb","caca"], target = "aba"
输出：6
解释：总共有 6 种方法构造目标串。
"aba" -> 下标为 0 ("acca")，下标为 1 ("bbbb")，下标为 3 ("caca")
"aba" -> 下标为 0 ("acca")，下标为 2 ("bbbb")，下标为 3 ("caca")
"aba" -> 下标为 0 ("acca")，下标为 1 ("bbbb")，下标为 3 ("acca")
"aba" -> 下标为 0 ("acca")，下标为 2 ("bbbb")，下标为 3 ("acca")
"aba" -> 下标为 1 ("caca")，下标为 2 ("bbbb")，下标为 3 ("acca")
"aba" -> 下标为 1 ("caca")，下标为 2 ("bbbb")，下标为 3 ("caca")
示例 2：

输入：words = ["abba","baab"], target = "bab"
输出：4
解释：总共有 4 种不同形成 target 的方法。
"bab" -> 下标为 0 ("baab")，下标为 1 ("baab")，下标为 2 ("abba")
"bab" -> 下标为 0 ("baab")，下标为 1 ("baab")，下标为 3 ("baab")
"bab" -> 下标为 0 ("baab")，下标为 2 ("baab")，下标为 3 ("baab")
"bab" -> 下标为 1 ("abba")，下标为 2 ("baab")，下标为 3 ("baab")
示例 3：

输入：words = ["abcd"], target = "abcd"
输出：1
示例 4：

输入：words = ["abab","baba","abba","baab"], target = "abba"
输出：16
 

提示：

1 <= words.length <= 1000
1 <= words[i].length <= 1000
words 中所有单词长度相同。
1 <= target.length <= 1000
words[i] 和 target 都仅包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int i, j, column = words[0].size(), size = target.size(), mod = 1000000007;
        vector<vector<int>> letters(column, vector<int>(26, 0));
        vector<vector<long long>> dp(column, vector<long long>(size, 0));  // dp[i][j]表示words[0, i]完成target[0, j]的方法数

        count(words, letters);
        dp[0][0] = letters[0][target[0] - 'a'];

        for (i = 1; i < column; ++i) {
            dp[i][0] = (dp[i - 1][0] + letters[i][target[0] - 'a']) % mod;

            for (j = 1; j < size && j <= i; ++j) {  // 1、最后一列选字符target[j]，然后前面i-1列匹配target[0, j-1]；2、不用最后一列，前面i-1列匹配target[0, j]
                dp[i][j] = (dp[i - 1][j - 1] * letters[i][target[j] - 'a'] + dp[i - 1][j]) % mod;
            }
        }

        return (int)dp[column - 1][size - 1];
    }

    void count(vector<string>& words, vector<vector<int>>& letters) {
        int i, j, row = words.size(), column = words[0].size();

        for (j = 0; j < column; ++j) {
            for (i = 0; i < row; ++i) {
                ++letters[j][words[i][j] - 'a'];
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "acca","bbbb","caca" };
    string target = "aba";
    check.checkInt(6, o.numWays(words, target));

    words = { "abba","baab" };
    target = "bab";
    check.checkInt(4, o.numWays(words, target));

    words = { "abcd" };
    target = "abcd";
    check.checkInt(1, o.numWays(words, target));

    words = { "abab","baba","abba","baab" };
    target = "abba";
    check.checkInt(16, o.numWays(words, target));

    words = { "a" };
    target = "a";
    check.checkInt(1, o.numWays(words, target));

    words = { "a" };
    target = "z";
    check.checkInt(0, o.numWays(words, target));

    words = { "acca","bbbb","caca","acca","bbbb","caca","abba","baab","abba","baab","abab","baba","abba","baab","abab","baba","abba","baab" };
    target = "aba";
    check.checkInt(2304, o.numWays(words, target));
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
