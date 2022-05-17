/* 移除字母异位词后的结果数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串 words ，其中 words[i] 由小写英文字符组成。

在一步操作中，需要选出任一下标 i ，从 words 中 删除 words[i] 。其中下标 i 需要同时满足下述两个条件：

0 < i < words.length
words[i - 1] 和 words[i] 是 字母异位词 。
只要可以选出满足条件的下标，就一直执行这个操作。

在执行所有操作后，返回 words 。可以证明，按任意顺序为每步操作选择下标都会得到相同的结果。

字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。例如，"dacb" 是 "abdc" 的一个字母异位词。

 

示例 1：

输入：words = ["abba","baba","bbaa","cd","cd"]
输出：["abba","cd"]
解释：
获取结果数组的方法之一是执行下述步骤：
- 由于 words[2] = "bbaa" 和 words[1] = "baba" 是字母异位词，选择下标 2 并删除 words[2] 。
  现在 words = ["abba","baba","cd","cd"] 。
- 由于 words[1] = "baba" 和 words[0] = "abba" 是字母异位词，选择下标 1 并删除 words[1] 。
  现在 words = ["abba","cd","cd"] 。
- 由于 words[2] = "cd" 和 words[1] = "cd" 是字母异位词，选择下标 2 并删除 words[2] 。
  现在 words = ["abba","cd"] 。
无法再执行任何操作，所以 ["abba","cd"] 是最终答案。
示例 2：

输入：words = ["a","b","c","d","e"]
输出：["a","b","c","d","e"]
解释：
words 中不存在互为字母异位词的两个相邻字符串，所以无需执行任何操作。
 

提示：

1 <= words.length <= 100
1 <= words[i].length <= 10
words[i] 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-resultant-array-after-removing-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        vector<int> count(26, 0);

        for (string& word : words) {
            vector<int> cnt(26, 0);
            int i = 0;

            for (char c : word) {
                ++cnt[c - 'a'];
            }

            for (i = 0; i < 26; ++i) {
                if (cnt[i] != count[i]) {
                    break;
                }
            }

            if (i != 26) {
                ans.push_back(word);
                count = cnt;
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "abba","baba","bbaa","cd","cd" };
    vector<string> actual = o.removeAnagrams(words);
    vector<string> expected = { "abba","cd" };
    check.checkStringVector(expected, actual);

    words = { "a","b","c","d","e" };
    actual = o.removeAnagrams(words);
    expected = { "a","b","c","d","e" };
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
