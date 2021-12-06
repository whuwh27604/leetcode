/* 统计出现过一次的公共字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串数组 words1 和 words2 ，请你返回在两个字符串数组中 都恰好出现一次 的字符串的数目。

 

示例 1：

输入：words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
输出：2
解释：
- "leetcode" 在两个数组中都恰好出现一次，计入答案。
- "amazing" 在两个数组中都恰好出现一次，计入答案。
- "is" 在两个数组中都出现过，但在 words1 中出现了 2 次，不计入答案。
- "as" 在 words1 中出现了一次，但是在 words2 中没有出现过，不计入答案。
所以，有 2 个字符串在两个数组中都恰好出现了一次。
示例 2：

输入：words1 = ["b","bb","bbb"], words2 = ["a","aa","aaa"]
输出：0
解释：没有字符串在两个数组中都恰好出现一次。
示例 3：

输入：words1 = ["a","ab"], words2 = ["a","a","a","ab"]
输出：1
解释：唯一在两个数组中都出现一次的字符串是 "ab" 。
 

提示：

1 <= words1.length, words2.length <= 1000
1 <= words1[i].length, words2[j].length <= 30
words1[i] 和 words2[j] 都只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-common-words-with-one-occurrence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> wordsCount1, wordsCount2;
        int count = 0;

        for (string& word : words1) {
            ++wordsCount1[word];
        }

        for (string& word : words2) {
            ++wordsCount2[word];
        }

        for (auto& wordsCount : wordsCount1) {
            if (wordsCount.second == 1 && wordsCount2[wordsCount.first] == 1) {
                ++count;
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words1 = { "leetcode","is","amazing","as","is" };
    vector<string> words2 = { "amazing","leetcode","is" };
    check.checkInt(2, o.countWords(words1, words2));

    words1 = { "b","bb","bbb" };
    words2 = { "a","aa","aaa" };
    check.checkInt(0, o.countWords(words1, words2));

    words1 = { "a","ab" };
    words2 = { "a","a","a","ab" };
    check.checkInt(1, o.countWords(words1, words2));

    words1 = { "z" };
    words2 = { "z" };
    check.checkInt(1, o.countWords(words1, words2));
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
