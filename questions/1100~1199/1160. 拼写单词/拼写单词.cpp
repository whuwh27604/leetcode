/* 拼写单词.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一份『词汇表』（字符串数组） words 和一张『字母表』（字符串） chars。

假如你可以用 chars 中的『字母』（字符）拼写出 words 中的某个『单词』（字符串），那么我们就认为你掌握了这个单词。

注意：每次拼写（指拼写词汇表中的一个单词）时，chars 中的每个字母都只能用一次。

返回词汇表 words 中你掌握的所有单词的 长度之和。

 

示例 1：

输入：words = ["cat","bt","hat","tree"], chars = "atach"
输出：6
解释：
可以形成字符串 "cat" 和 "hat"，所以答案是 3 + 3 = 6。
示例 2：

输入：words = ["hello","world","leetcode"], chars = "welldonehoneyr"
输出：10
解释：
可以形成字符串 "hello" 和 "world"，所以答案是 5 + 5 = 10。
 

提示：

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
所有字符串中都仅包含小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        char charTable[26] = { 0 };
        for (unsigned int i = 0; i < chars.size(); i++) {
            charTable[chars[i] - 'a']++;
        }

        int allGoodWordsLen = 0;
        for (unsigned int i = 0; i < words.size(); i++) {
            char tmp[26];
            copyTable(charTable, tmp);
            allGoodWordsLen += goodWordLen(words[i], tmp);
        }

        return allGoodWordsLen;
    }

    void copyTable(char* from, char* to) {
        for (int i = 0; i < 26; i++) {
            to[i] = from[i];
        }
    }

    int goodWordLen(string& word, char* charTable) {
        int i, len = word.size();
        for (i = 0; i < len; i++) {
            if (charTable[word[i] - 'a'] > 0) {
                charTable[word[i] - 'a']--;
            }
            else {
                return 0;
            }
        }

        return len;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> words = { "cat","bt","hat","tree" };
    check.checkInt(6, o.countCharacters(words, "atach"));

    words = { "hello","world","leetcode" };
    check.checkInt(10, o.countCharacters(words, "welldonehoneyr"));

    words = { "a" };
    check.checkInt(1, o.countCharacters(words, "a"));

    words = { "a" };
    check.checkInt(0, o.countCharacters(words, "b"));

    words = { "aaa","aaa","aaaa","a","aa" };
    check.checkInt(9, o.countCharacters(words, "aaa"));

    words = { "abcdefghijklmnopqrstuvwxyz" };
    check.checkInt(26, o.countCharacters(words, "abcdefghijklmnopqrstuvwxyz"));
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
