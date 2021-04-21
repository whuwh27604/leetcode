/* 得分最高的单词集合.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你将会得到一份单词表 words，一个字母表 letters （可能会有重复字母），以及每个字母对应的得分情况表 score。

请你帮忙计算玩家在单词拼写游戏中所能获得的「最高得分」：能够由 letters 里的字母拼写出的 任意 属于 words 单词子集中，分数最高的单词集合的得分。

单词拼写游戏的规则概述如下：

玩家需要用字母表 letters 里的字母来拼写单词表 words 中的单词。
可以只使用字母表 letters 中的部分字母，但是每个字母最多被使用一次。
单词表 words 中每个单词只能计分（使用）一次。
根据字母得分情况表score，字母 'a', 'b', 'c', ... , 'z' 对应的得分分别为 score[0], score[1], ..., score[25]。
本场游戏的「得分」是指：玩家所拼写出的单词集合里包含的所有字母的得分之和。
 

示例 1：

输入：words = ["dog","cat","dad","good"], letters = ["a","a","c","d","d","d","g","o","o"], score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
输出：23
解释：
字母得分为  a=1, c=9, d=5, g=3, o=2
使用给定的字母表 letters，我们可以拼写单词 "dad" (5+1+5)和 "good" (3+2+2+5)，得分为 23 。
而单词 "dad" 和 "dog" 只能得到 21 分。
示例 2：

输入：words = ["xxxz","ax","bx","cx"], letters = ["z","a","b","c","x","x","x"], score = [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
输出：27
解释：
字母得分为  a=4, b=4, c=4, x=5, z=10
使用给定的字母表 letters，我们可以组成单词 "ax" (4+5)， "bx" (4+5) 和 "cx" (4+5) ，总得分为 27 。
单词 "xxxz" 的得分仅为 25 。
示例 3：

输入：words = ["leetcode"], letters = ["l","e","t","c","o","d"], score = [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
输出：0
解释：
字母 "e" 在字母表 letters 中只出现了一次，所以无法组成单词表 words 中的单词。
 

提示：

1 <= words.length <= 14
1 <= words[i].length <= 15
1 <= letters.length <= 100
letters[i].length == 1
score.length == 26
0 <= score[i] <= 10
words[i] 和 letters[i] 只包含小写的英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-score-words-formed-by-letters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int size = words.size(), bits, maxBits = (1 << size) - 1, maxScore = 0;
        vector<int> choseableLetters(26, 0);

        getChoseableLetters(letters, choseableLetters);

        for (bits = 1; bits <= maxBits; ++bits) {
            maxScore = max(maxScore, getScore(bits, size, words, choseableLetters, score));
        }

        return maxScore;
    }

    void getChoseableLetters(vector<char>& letters, vector<int>& choseableLetters) {
        for (char c : letters) {
            ++choseableLetters[c - 'a'];
        }
    }

    int getScore(int bits, int size, vector<string>& words, vector<int>& choseableLetters, vector<int>& score) {
        vector<int> count(26, 0);
        int i, bit, points = 0;

        for (bit = 1, i = 0; i < size; bit <<= 1, ++i) {
            if ((bit & bits) == bit) {
                for (char c : words[i]) {
                    ++count[c - 'a'];
                }
            }
        }

        for (i = 0; i < 26; ++i) {
            if (count[i] > choseableLetters[i]) {
                return 0;
            }

            points += (count[i] * score[i]);
        }

        return points;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "dog","cat","dad","good" };
    vector<char> letters = { 'a','a','c','d','d','d','g','o','o' };
    vector<int> score = { 1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0 };
    check.checkInt(23, o.maxScoreWords(words, letters, score));

    words = { "xxxz","ax","bx","cx" };
    letters = { 'z','a','b','c','x','x','x' };
    score = { 4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10 };
    check.checkInt(27, o.maxScoreWords(words, letters, score));

    words = { "leetcode" };
    letters = { 'l','e','t','c','o','d' };
    score = { 0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0 };
    check.checkInt(0, o.maxScoreWords(words, letters, score));

    words = { "ac","abd","db","ba","dddd","bca" };
    letters = { 'a','a','a','b','b','b','c','c','d','d','d','d' };
    score = { 6,4,4,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    check.checkInt(62, o.maxScoreWords(words, letters, score));
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
