/* 统计相似字符串对的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串数组 words 。

如果两个字符串由相同的字符组成，则认为这两个字符串 相似 。

例如，"abca" 和 "cba" 相似，因为它们都由字符 'a'、'b'、'c' 组成。
然而，"abacba" 和 "bcfd" 不相似，因为它们不是相同字符组成的。
请你找出满足字符串 words[i] 和 words[j] 相似的下标对 (i, j) ，并返回下标对的数目，其中 0 <= i < j <= word.length - 1 。



示例 1：

输入：words = ["aba","aabb","abcd","bac","aabc"]
输出：2
解释：共有 2 对满足条件：
- i = 0 且 j = 1 ：words[0] 和 words[1] 只由字符 'a' 和 'b' 组成。
- i = 3 且 j = 4 ：words[3] 和 words[4] 只由字符 'a'、'b' 和 'c' 。
示例 2：

输入：words = ["aabb","ab","ba"]
输出：3
解释：共有 3 对满足条件：
- i = 0 且 j = 1 ：words[0] 和 words[1] 只由字符 'a' 和 'b' 组成。
- i = 0 且 j = 2 ：words[0] 和 words[2] 只由字符 'a' 和 'b' 组成。
- i = 1 且 j = 2 ：words[1] 和 words[2] 只由字符 'a' 和 'b' 组成。
示例 3：

输入：words = ["nba","cba","dba"]
输出：0
解释：不存在满足条件的下标对，返回 0 。


提示：

1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] 仅由小写英文字母组成
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<string, int> count;
        int pairs = 0;

        for (string& word : words) {
            ++count[getSimilar(word)];
        }

        for (auto& kv : count) {
            pairs += kv.second * (kv.second - 1) / 2;
        }

        return pairs;
    }

    string getSimilar(string& word) {
        vector<bool> letters('z' + 1, false);
        string similar;

        for (char c : word) {
            letters[c] = true;
        }

        for (char c = 'a'; c <= 'z'; ++c) {
            if (letters[c]) {
                similar += c;
            }
        }

        return similar;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "aba","aabb","abcd","bac","aabc" };
    check.checkInt(2, o.similarPairs(words));

    words = { "aabb","ab","ba" };
    check.checkInt(3, o.similarPairs(words));

    words = { "nba","cba","dba" };
    check.checkInt(0, o.similarPairs(words));
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
