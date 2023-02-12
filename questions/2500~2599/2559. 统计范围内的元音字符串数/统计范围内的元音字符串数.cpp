/* 统计范围内的元音字符串数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的字符串数组 words 以及一个二维整数数组 queries 。

每个查询 queries[i] = [li, ri] 会要求我们统计在 words 中下标在 li 到 ri 范围内（包含 这两个值）并且以元音开头和结尾的字符串的数目。

返回一个整数数组，其中数组的第 i 个元素对应第 i 个查询的答案。

注意：元音字母是 'a'、'e'、'i'、'o' 和 'u' 。



示例 1：

输入：words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
输出：[2,3,0]
解释：以元音开头和结尾的字符串是 "aba"、"ece"、"aa" 和 "e" 。
查询 [0,2] 结果为 2（字符串 "aba" 和 "ece"）。
查询 [1,4] 结果为 3（字符串 "ece"、"aa"、"e"）。
查询 [1,1] 结果为 0 。
返回结果 [2,3,0] 。
示例 2：

输入：words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
输出：[3,2,1]
解释：每个字符串都满足这一条件，所以返回 [3,2,1] 。


提示：

1 <= words.length <= 105
1 <= words[i].length <= 40
words[i] 仅由小写英文字母组成
sum(words[i].length) <= 3 * 105
1 <= queries.length <= 105
0 <= queries[j][0] <= queries[j][1] < words.length
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int size = words.size(), index = 0;
        vector<int> presums(size + 1, 0);
        vector<int> ans(queries.size());

        for (int i = 0; i < size; ++i) {
            presums[i + 1] = presums[i] + (isVowel(words[i]) ? 1 : 0);
        }

        for (auto& query : queries) {
            ans[index++] = presums[query[1] + 1] - presums[query[0]];
        }

        return ans;
    }

    bool isVowel(string& word) {
        char s = word.front(), e = word.back();

        return (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') && (e == 'a' || e == 'e' || e == 'i' || e == 'o' || e == 'u');
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "aba","bcb","ece","aa","e" };
    vector<vector<int>> queries = { {0,2},{1,4},{1,1} };
    vector<int> actual = o.vowelStrings(words, queries);
    vector<int> expected = { 2,3,0 };
    check.checkIntVector(expected, actual);

    words = { "a","e","i" };
    queries = { {0,2},{0,1},{2,2} };
    actual = o.vowelStrings(words, queries);
    expected = { 3,2,1 };
    check.checkIntVector(expected, actual);
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
