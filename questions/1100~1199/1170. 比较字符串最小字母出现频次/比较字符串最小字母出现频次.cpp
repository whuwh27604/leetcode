/* 比较字符串最小字母出现频次.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们来定义一个函数 f(s)，其中传入参数 s 是一个非空字符串；该函数的功能是统计 s  中（按字典序比较）最小字母的出现频次。

例如，若 s = "dcce"，那么 f(s) = 2，因为最小的字母是 "c"，它出现了 2 次。

现在，给你两个字符串数组待查表 queries 和词汇表 words，请你返回一个整数数组 answer 作为答案，其中每个 answer[i] 是满足 f(queries[i]) < f(W) 的词的数目，W 是词汇表 words 中的词。

 

示例 1：

输入：queries = ["cbd"], words = ["zaaaz"]
输出：[1]
解释：查询 f("cbd") = 1，而 f("zaaaz") = 3 所以 f("cbd") < f("zaaaz")。
示例 2：

输入：queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
输出：[1,2]
解释：第一个查询 f("bbb") < f("aaaa")，第二个查询 f("aaa") 和 f("aaaa") 都 > f("cc")。
 

提示：

1 <= queries.length <= 2000
1 <= words.length <= 2000
1 <= queries[i].length, words[i].length <= 10
queries[i][j], words[i][j] 都是小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/compare-strings-by-frequency-of-the-smallest-character
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int frequencyTable[11] = { 0 };
        wordsMinCharFrequencyTable(words, frequencyTable);

        int biggerFrequencyTable[11] = { 0 };
        wordsBiggerFrequencyTable(frequencyTable, biggerFrequencyTable);

        vector<int> ans;
        ans.reserve(queries.size());
        for (unsigned int i = 0; i < queries.size(); i++) {
            int frequency = minCharFrequency(queries[i]);
            ans.push_back(biggerFrequencyTable[frequency]);
        }

        return ans;
    }

    int minCharFrequency(string word) {
        char minChar = '{';
        int frequency = 0;

        for (unsigned int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c == minChar) {
                frequency++;
            }
            else if (c < minChar) {
                minChar = c;
                frequency = 1;
            }
        }

        return frequency;
    }

    void wordsMinCharFrequencyTable(vector<string>& words, int* table) {
        for (unsigned int i = 0; i < words.size(); i++) {
            int frequency = minCharFrequency(words[i]);
            table[frequency]++;
        }
    }

    void wordsBiggerFrequencyTable(int* frequencyTable, int* biggerFrequencyTable) {
        int i, sum = 0;
        biggerFrequencyTable[10] = 0;
        for (i = 1; i < 11; i++) {
            sum += frequencyTable[11 - i];
            biggerFrequencyTable[10 - i] = sum;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> queries = { "cbd" };
    vector<string> words = { "zaaaz" };
    vector<int> actual = o.numSmallerByFrequency(queries, words);
    vector<int> expected = { 1 };
    check.checkIntVector(expected, actual);

    queries = { "bbb","cc" };
    words = { "a","aa","aaa","aaaa" };
    actual = o.numSmallerByFrequency(queries, words);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    queries = { "b" };
    words = { "a","aa","aaa","aaaa" };
    actual = o.numSmallerByFrequency(queries, words);
    expected = { 3 };
    check.checkIntVector(expected, actual);

    queries = { "b" };
    words = { "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
    actual = o.numSmallerByFrequency(queries, words);
    expected = { 9 };
    check.checkIntVector(expected, actual);

    queries = { "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
    words = { "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
    actual = o.numSmallerByFrequency(queries, words);
    expected = { 9,8,7,6,5,4,3,2,1,0 };
    check.checkIntVector(expected, actual);

    queries = { "aaaaaaaaaa","aaaaaaaaa","aaaaaaaa","aaaaaaa","aaaaaa","aaaaa","aaaa","aaa","aa","a" };
    words = { "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa","a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
    actual = o.numSmallerByFrequency(queries, words);
    expected = { 0,2,4,6,8,10,12,14,16,18 };
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
