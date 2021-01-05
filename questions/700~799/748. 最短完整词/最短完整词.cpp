/* 最短完整词.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果单词列表（words）中的一个单词包含牌照（licensePlate）中所有的字母，那么我们称之为完整词。在所有完整词中，最短的单词我们称之为最短完整词。

单词在匹配牌照中的字母时不区分大小写，比如牌照中的 "P" 依然可以匹配单词中的 "p" 字母。

我们保证一定存在一个最短完整词。当有多个单词都符合最短完整词的匹配条件时取单词列表中最靠前的一个。

牌照中可能包含多个相同的字符，比如说：对于牌照 "PP"，单词 "pair" 无法匹配，但是 "supper" 可以匹配。

 

示例 1：

输入：licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
输出："steps"
说明：最短完整词应该包括 "s"、"p"、"s" 以及 "t"。对于 "step" 它只包含一个 "s" 所以它不符合条件。同时在匹配过程中我们忽略牌照中的大小写。
 

示例 2：

输入：licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
输出："pest"
说明：存在 3 个包含字母 "s" 且有着最短长度的完整词，但我们返回最先出现的完整词。
 

注意:

牌照（licensePlate）的长度在区域[1, 7]中。
牌照（licensePlate）将会包含数字、空格、或者字母（大写和小写）。
单词列表（words）长度在区间 [10, 1000] 中。
每一个单词 words[i] 都是小写，并且长度在区间 [1, 15] 中。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-completing-word
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string minMatchWord;
        unsigned int minLen = INT_MAX;

        vector<pair<int, int>> licenseCount;
        countLicense(licensePlate, licenseCount);

        for (string& word : words) {
            vector<int> wordCount(26, 0);
            countWord(word, wordCount);

            if (isMatch(licenseCount, wordCount) && word.size() < minLen) {
                minMatchWord = word;
                minLen = word.size();
            }
        }

        return minMatchWord;
    }

    void countLicense(string& license, vector<pair<int, int>>& count) {
        vector<int> tmp(26, 0);

        for (char c : license) {
            if (c >= 'A' && c <= 'Z') {
                c += 32;
                ++tmp[c - 'a'];
            }
            else if (c >= 'a' && c <= 'z') {
                ++tmp[c - 'a'];
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (tmp[i] != 0) {
                count.push_back({ i, tmp[i] });
            }
        }
    }

    void countWord(string& word, vector<int>& count) {
        for (char c : word) {
            ++count[c - 'a'];
        }
    }

    bool isMatch(vector<pair<int, int>>& licenseCount, vector<int>& wordCount) {
        for (auto& letterCount : licenseCount) {
            if (wordCount[letterCount.first] < letterCount.second) {
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

    string licensePlate = "1s3 PSt";
    vector<string> words = { "step", "steps", "stripe", "stepple" };
    check.checkString("steps", o.shortestCompletingWord(licensePlate, words));

    licensePlate = "1s3 456";
    words = { "looks", "pest", "stew", "show" };
    check.checkString("pest", o.shortestCompletingWord(licensePlate, words));

    licensePlate = "A";
    words = { "aaa", "abc", "acc", "addd" };
    check.checkString("aaa", o.shortestCompletingWord(licensePlate, words));

    licensePlate = "AAA";
    words = { "ababab", "abcabcabc", "acacac", "addd" };
    check.checkString("ababab", o.shortestCompletingWord(licensePlate, words));
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
