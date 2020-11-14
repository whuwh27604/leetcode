/* 前K个高频单词.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给一非空的单词列表，返回前 k 个出现次数最多的单词。

返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。

示例 1：

输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
输出: ["i", "love"]
解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
    注意，按字母顺序 "i" 在 "love" 之前。
 

示例 2：

输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
输出: ["the", "is", "sunny", "day"]
解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
    出现次数依次为 4, 3, 2 和 1 次。
 

注意：

假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。
输入的单词均由小写字母组成。
 

扩展练习：

尝试以 O(n log k) 时间复杂度和 O(n) 空间复杂度解决。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/top-k-frequent-words
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

struct pairCompare {
    bool operator() (const pair<string, int>& v1, const pair<string, int>& v2) const {
        if (v1.second > v2.second) {
            return true;
        }
        else if (v1.second < v2.second) {
            return false;
        }
        else {
            return v1.first < v2.first;
        }
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> wordCount;
        countWords(words, wordCount);

        set<pair<string, int>, pairCompare> topWords;
        for (auto iter = wordCount.begin(); iter != wordCount.end(); iter++) {
            topWords.insert({ iter->first, iter->second });

            if ((int)topWords.size() > k) {
                topWords.erase(--topWords.end());
            }
        }

        vector<string> ans;
        for (auto iter = topWords.begin(); iter != topWords.end(); iter++) {
            ans.push_back(iter->first);
        }

        return ans;
    }

    void countWords(vector<string>& words, unordered_map<string, int>& wordCount) {
        for (string& word : words) {
            auto iter = wordCount.find(word);
            if (iter == wordCount.end()) {
                wordCount[word] = 1;
            }
            else {
                iter->second++;
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> words = { "a","ab","bc","bcd" };
    vector<string> actual = o.topKFrequent(words, 3);
    vector<string> expected = { "a","ab","bc" };
    check.checkStringVector(expected, actual);

    words = { "i", "love", "leetcode", "i", "love", "coding" };
    actual = o.topKFrequent(words, 2);
    expected = { "i", "love" };
    check.checkStringVector(expected, actual);

    words = { "i", "love", "leetcode", "i", "love", "coding" };
    actual = o.topKFrequent(words, 3);
    expected = { "i", "love", "coding" };
    check.checkStringVector(expected, actual);

    words = { "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
    actual = o.topKFrequent(words, 4);
    expected = { "the", "is", "sunny", "day" };
    check.checkStringVector(expected, actual);

    words = { "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
    actual = o.topKFrequent(words, 1);
    expected = { "the" };
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
