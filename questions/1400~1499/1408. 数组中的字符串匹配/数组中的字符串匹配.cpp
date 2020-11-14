/* 数组中的字符串匹配.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串数组 words ，数组中的每个字符串都可以看作是一个单词。请你按 任意 顺序返回 words 中是其他单词的子字符串的所有单词。

如果你可以删除 words[j] 最左侧和/或最右侧的若干字符得到 word[i] ，那么字符串 words[i] 就是 words[j] 的一个子字符串。

 

示例 1：

输入：words = ["mass","as","hero","superhero"]
输出：["as","hero"]
解释："as" 是 "mass" 的子字符串，"hero" 是 "superhero" 的子字符串。
["hero","as"] 也是有效的答案。
示例 2：

输入：words = ["leetcode","et","code"]
输出：["et","code"]
解释："et" 和 "code" 都是 "leetcode" 的子字符串。
示例 3：

输入：words = ["blue","green","bu"]
输出：[]
 

提示：

1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] 仅包含小写英文字母。
题目数据 保证 每个 words[i] 都是独一无二的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/string-matching-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> substrings;

        unsigned int i = 0, j;
        while (i < words.size()) {
            bool find = false;
            j = 0;

            while (j < words.size()) {
                if ((words[i].size() >= words[j].size()) || (j == i)) {
                    j++;
                    continue;
                }

                if (words[j].find(words[i]) != string::npos) {
                    substrings.push_back(words[i]);
                    words.erase(words.begin() + i);
                    find = true;
                    break;
                }
                else {
                    j++;
                }
            }

            if (!find) {
                i++;
            }
        }

        return substrings;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> words = { "mass","as","hero","superhero" };
    vector<string> actual = o.stringMatching(words);
    vector<string> expected = { "as","hero" };
    check.checkStringVector(expected, actual);

    words = { "leetcode","et","code" };
    actual = o.stringMatching(words);
    expected = { "et","code" };
    check.checkStringVector(expected, actual);

    words = { "blue","green","bu" };
    actual = o.stringMatching(words);
    expected = {  };
    check.checkStringVector(expected, actual);

    words = { "a" };
    actual = o.stringMatching(words);
    expected = {  };
    check.checkStringVector(expected, actual);

    words = { "a","aa","aaa","aaaa","aaaaa" };
    actual = o.stringMatching(words);
    expected = { "a","aa","aaa","aaaa" };
    check.checkStringVector(expected, actual);

    words = { "aaaaa","aaaa","aaa","aa","a" };
    actual = o.stringMatching(words);
    expected = { "aaaa","aaa","aa","a" };
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
