/* 字符串连接删减字母.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的数组 words ，它包含 n 个字符串。

定义 连接 操作 join(x, y) 表示将字符串 x 和 y 连在一起，得到 xy 。如果 x 的最后一个字符与 y 的第一个字符相等，连接后两个字符中的一个会被 删除 。

比方说 join("ab", "ba") = "aba" ， join("ab", "cde") = "abcde" 。

你需要执行 n - 1 次 连接 操作。令 str0 = words[0] ，从 i = 1 直到 i = n - 1 ，对于第 i 个操作，你可以执行以下操作之一：

令 stri = join(stri - 1, words[i])
令 stri = join(words[i], stri - 1)
你的任务是使 strn - 1 的长度 最小 。

请你返回一个整数，表示 strn - 1 的最小长度。



示例 1：

输入：words = ["aa","ab","bc"]
输出：4
解释：这个例子中，我们按以下顺序执行连接操作，得到 str2 的最小长度：
str0 = "aa"
str1 = join(str0, "ab") = "aab"
str2 = join(str1, "bc") = "aabc"
str2 的最小长度为 4 。
示例 2：

输入：words = ["ab","b"]
输出：2
解释：这个例子中，str0 = "ab"，可以得到两个不同的 str1：
join(str0, "b") = "ab" 或者 join("b", str0) = "bab" 。
第一个字符串 "ab" 的长度最短，所以答案为 2 。
示例 3：

输入：words = ["aaa","c","aba"]
输出：6
解释：这个例子中，我们按以下顺序执行连接操作，得到 str2 的最小长度：
str0 = "aaa"
str1 = join(str0, "c") = "aaac"
str2 = join("aba", str1) = "abaaac"
str2 的最小长度为 6 。


提示：

1 <= words.length <= 1000
1 <= words[i].length <= 50
words[i] 中只包含小写英文字母。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        unordered_map<int, int> memo;

        return words[0].size() + getMinLen(words, 1, words[0][0], words[0].back(), memo);
    }

    int getMinLen(vector<string>& words, int index, char head, char tail, unordered_map<int, int>& memo) {  // 函数表示，当前字符的首尾分别是head和tail时，从words的index单词开始往后，可以得到的最小长度
        int size = words.size();
        if (index == size) {
            return 0;
        }

        int key = ((index << 16) | ((int)head << 8) | tail);
        if (memo.count(key) != 0) {
            return memo[key];
        }

        string& word = words[index];
        int len = word.size();
        int minLen = min(len - (tail == word[0] ? 1 : 0) + getMinLen(words, index + 1, head, word.back(), memo),
            len - (head == word.back() ? 1 : 0) + getMinLen(words, index + 1, word[0], tail, memo));
        memo[key] = minLen;

        return minLen;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "aa","ab","bc" };
    check.checkInt(4, o.minimizeConcatenatedLength(words));

    words = { "ab","b" };
    check.checkInt(2, o.minimizeConcatenatedLength(words));

    words = { "aaa","c","aba" };
    check.checkInt(6, o.minimizeConcatenatedLength(words));
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
