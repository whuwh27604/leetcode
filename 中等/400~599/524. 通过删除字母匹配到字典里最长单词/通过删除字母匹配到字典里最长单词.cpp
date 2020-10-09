/* 通过删除字母匹配到字典里最长单词.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。如果答案不止一个，返回长度最长且字典顺序最小的字符串。如果答案不存在，则返回空字符串。

示例 1:

输入:
s = "abpcplea", d = ["ale","apple","monkey","plea"]

输出:
"apple"
示例 2:

输入:
s = "abpcplea", d = ["a","b","c"]

输出:
"a"
说明:

所有输入的字符串只包含小写字母。
字典的大小不会超过 1000。
所有输入的字符串长度不会超过 1000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(string& s1, string& s2) {
    return s1.size() > s2.size();
}

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), vectorCompare);

        string longestWord;
        for (string word : d) {
            if (word.size() < longestWord.size()) {
                return longestWord;
            }

            if (!isSubsequence(s, word)) {
                continue;
            }

            if (longestWord.empty()) {
                longestWord = word;
            }
            else if (word.compare(longestWord) < 0) {
                longestWord = word;
            }
        }

        return longestWord;
    }

    bool isSubsequence(string& s, string& word) {
        int position = -1;

        for (char c : word) {
            if ((position = s.find(c, position + 1)) == s.npos) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> d = { "ale","apple","monkey","plea" };
    check.checkString("apple", o.findLongestWord("abpcplea", d));

    d = { "ale","apple","monkey","plea","abpca" };
    check.checkString("abpca", o.findLongestWord("abpcplea", d));

    d = { "","ale","apple","monkey","plea","abpca" };
    check.checkString("abpca", o.findLongestWord("abpcplea", d));

    d = { "a","b","c" };
    check.checkString("a", o.findLongestWord("abpcplea", d));

    d = {  };
    check.checkString("", o.findLongestWord("abpcplea", d));

    d = { "a","b","c" };
    check.checkString("", o.findLongestWord("", d));

    d = { "ba","ab","a","b" };
    check.checkString("ab", o.findLongestWord("bab", d));

    d = { "apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf" };
    check.checkString("ewaf", o.findLongestWord("aewfafwafjlwajflwajflwafj", d));
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
