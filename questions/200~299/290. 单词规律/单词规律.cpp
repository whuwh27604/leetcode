/* 单词规律.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

示例1:

输入: pattern = "abba", str = "dog cat cat dog"
输出: true
示例 2:

输入:pattern = "abba", str = "dog cat cat fish"
输出: false
示例 3:

输入: pattern = "aaaa", str = "dog cat cat dog"
输出: false
示例 4:

输入: pattern = "abba", str = "dog dog dog dog"
输出: false
说明:
你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern.size() == 0) {
            return (str.size() == 0);
        }

        unordered_map<char, string> pattern2Word;
        unordered_map<string, char> word2Pattern;
        unsigned int i = 0, index = 0;
        char nextPattern;
        string nextWord;

        for (i = 0; i < pattern.size(); i++) {
            nextPattern = pattern[i];
            nextWord = getNextWord(str, index);
            if (nextWord.empty()) {
                return false;
            }

            auto iter1 = pattern2Word.find(nextPattern);
            if (iter1 == pattern2Word.end()) {
                pattern2Word[nextPattern] = nextWord;
            }
            else {
                if (iter1->second != nextWord) {
                    return false;
                }
            }

            auto iter2 = word2Pattern.find(nextWord);
            if (iter2 == word2Pattern.end()) {
                word2Pattern[nextWord] = nextPattern;
            }
            else {
                if (iter2->second != nextPattern) {
                    return false;
                }
            }
        }

        nextWord = getNextWord(str, index);
        return (nextWord.empty());
    }

    string getNextWord(string str, unsigned int& index) {
        string nextWord = "";
        bool exist = false;
        for (; index < str.size(); index++) {
            if (str[index] == ' ') {
                if (exist == true) {
                    return nextWord;
                }
            }
            else {
                exist = true;
                nextWord.push_back(str[index]);
            }
        }

        return nextWord;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    string pattern = "abba", str = "dog cat cat dog";
    check.checkBool(true, o.wordPattern(pattern, str));

    pattern = "abba";
    str = "dog cat cat fish";
    check.checkBool(false, o.wordPattern(pattern, str));

    pattern = "aaaa";
    str = "dog cat cat dog";
    check.checkBool(false, o.wordPattern(pattern, str));

    pattern = "abba";
    str = "dog dog dog dog";
    check.checkBool(false, o.wordPattern(pattern, str));

    pattern = "";
    str = "";
    check.checkBool(true, o.wordPattern(pattern, str));

    pattern = "";
    str = "d";
    check.checkBool(false, o.wordPattern(pattern, str));

    pattern = "a";
    str = " dog ";
    check.checkBool(true, o.wordPattern(pattern, str));

    pattern = "a";
    str = "dog dog";
    check.checkBool(false, o.wordPattern(pattern, str));

    pattern = "aa";
    str = "dog";
    check.checkBool(false, o.wordPattern(pattern, str));
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
