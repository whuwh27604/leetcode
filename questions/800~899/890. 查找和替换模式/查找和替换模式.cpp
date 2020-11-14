/* 查找和替换模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有一个单词列表 words 和一个模式  pattern，你想知道 words 中的哪些单词与模式匹配。

如果存在字母的排列 p ，使得将模式中的每个字母 x 替换为 p(x) 之后，我们就得到了所需的单词，那么单词与模式是匹配的。

（回想一下，字母的排列是从字母到字母的双射：每个字母映射到另一个字母，没有两个字母映射到同一个字母。）

返回 words 中与给定模式匹配的单词列表。

你可以按任何顺序返回答案。

 

示例：

输入：words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
输出：["mee","aqq"]
解释：
"mee" 与模式匹配，因为存在排列 {a -> m, b -> e, ...}。
"ccc" 与模式不匹配，因为 {a -> c, b -> c, ...} 不是排列。
因为 a 和 b 映射到同一个字母。
 

提示：

1 <= words.length <= 50
1 <= pattern.length = words[i].length <= 20

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-and-replace-pattern
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> matchWords;

        for (string& word : words) {
            if (isMatch(word, pattern)) {
                matchWords.push_back(word);
            }
        }

        return matchWords;
    }

    bool isMatch(string& word, string& pattern) {
        vector<int> hash1(127, -1), hash2(127, -1);

        for (int i = 0; i < (int)word.size(); ++i) {
            if (hash1[word[i]] != hash2[pattern[i]]) {
                return false;
            }

            hash1[word[i]] = hash2[pattern[i]] = i;
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> words = { "abc","deq","mee","aqq","dkd","ccc" };
    vector<string> actual = o.findAndReplacePattern(words, "abb");
    vector<string> expected = { "mee","aqq" };
    check.checkStringVector(expected, actual);

    words = { "aa" };
    actual = o.findAndReplacePattern(words, "aA");
    expected = {  };
    check.checkStringVector(expected, actual);

    words = { "badc","abab","dddd","dede","yyxx" };
    actual = o.findAndReplacePattern(words, "baba");
    expected = { "abab","dede" };
    check.checkStringVector(expected, actual);
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
