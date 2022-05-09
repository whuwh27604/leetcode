/* 统计是给定字符串前缀的字符串数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串数组 words 和一个字符串 s ，其中 words[i] 和 s 只包含 小写英文字母 。

请你返回 words 中是字符串 s 前缀 的 字符串数目 。

一个字符串的 前缀 是出现在字符串开头的子字符串。子字符串 是一个字符串中的连续一段字符序列。

 

示例 1：

输入：words = ["a","b","c","ab","bc","abc"], s = "abc"
输出：3
解释：
words 中是 s = "abc" 前缀的字符串为：
"a" ，"ab" 和 "abc" 。
所以 words 中是字符串 s 前缀的字符串数目为 3 。
示例 2：

输入：words = ["a","a"], s = "aa"
输出：2
解释：
两个字符串都是 s 的前缀。
注意，相同的字符串可能在 words 中出现多次，它们应该被计数多次。
 

提示：

1 <= words.length <= 1000
1 <= words[i].length, s.length <= 10
words[i] 和 s 只 包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-prefixes-of-a-given-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int i = 0, count = 0;

        for (string& word : words) {
            if (word.size() <= s.size()) {
                for (i = 0; i < (int)word.size() && word[i] == s[i]; ++i) {}

                if (i == word.size()) {
                    ++count;
                }
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "a","b","c","ab","bc","abc" };
    check.checkInt(3, o.countPrefixes(words, "abc"));

    words = { "a","a" };
    check.checkInt(2, o.countPrefixes(words, "aa"));
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
