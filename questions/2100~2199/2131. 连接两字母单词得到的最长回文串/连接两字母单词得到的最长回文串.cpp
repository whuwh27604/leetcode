/* 连接两字母单词得到的最长回文串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串数组 words 。words 中每个元素都是一个包含 两个 小写英文字母的单词。

请你从 words 中选择一些元素并按 任意顺序 连接它们，并得到一个 尽可能长的回文串 。每个元素 至多 只能使用一次。

请你返回你能得到的最长回文串的 长度 。如果没办法得到任何一个回文串，请你返回 0 。

回文串 指的是从前往后和从后往前读一样的字符串。

 

示例 1：

输入：words = ["lc","cl","gg"]
输出：6
解释：一个最长的回文串为 "lc" + "gg" + "cl" = "lcggcl" ，长度为 6 。
"clgglc" 是另一个可以得到的最长回文串。
示例 2：

输入：words = ["ab","ty","yt","lc","cl","ab"]
输出：8
解释：最长回文串是 "ty" + "lc" + "cl" + "yt" = "tylcclyt" ，长度为 8 。
"lcyttycl" 是另一个可以得到的最长回文串。
示例 3：

输入：words = ["cc","ll","xx"]
输出：2
解释：最长回文串是 "cc" ，长度为 2 。
"ll" 是另一个可以得到的最长回文串。"xx" 也是。
 

提示：

1 <= words.length <= 105
words[i].length == 2
words[i] 仅包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindrome-by-concatenating-two-letter-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> wordsCount;
        int len = 0;
        bool addTwo = false;

        for (string& word : words) {
            ++wordsCount[word];
        }

        for (auto& wordCount : wordsCount) {
            string word = wordCount.first;
            int count = wordCount.second;

            if (word[0] == word[1]) {  // 本身是回文串
                len += (count / 2 * 4);

                if ((count & 1) == 1) {
                    addTwo = true;  // 奇数个可以在中间放一个
                }
            }
            else {
                string palindrome;
                palindrome += word[1];
                palindrome += word[0];

                if (wordsCount.count(palindrome) != 0) {
                    int cnt = min(count, wordsCount[palindrome]);
                    len += (cnt * 4);
                    wordCount.second -= cnt;
                    wordsCount[palindrome] -= cnt;
                }
            }
        }

        return addTwo ? len + 2 : len;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "lc","cl","gg" };
    check.checkInt(6, o.longestPalindrome(words));

    words = { "ab","ty","yt","lc","cl","ab" };
    check.checkInt(8, o.longestPalindrome(words));

    words = { "cc","ll","xx" };
    check.checkInt(2, o.longestPalindrome(words));

    words = { "oo","vv","uu","gg","pp","ff","ss","yy","vv","cc","rr","ig","jj","uu","ig","gb","zz","xx","ff","bb","ii","dd","ii","ee","mm","qq","ig","ww","ss","tt","vv","oo","ww","ss","bi","ff","gg","bi","jj","ee","gb","qq","bg","nn","vv","oo","bb","pp","ww","qq","mm","ee","tt","hh","ss","tt","ee","gi","ig","uu","ff","zz","ii","ff","ss","gi","yy","gb","mm","pp","uu","kk","jj","ee" };
    check.checkInt(102, o.longestPalindrome(words));
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
