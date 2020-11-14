/* 恢复空格.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
哦，不！你不小心把一个长篇文章中的空格、标点都删掉了，并且大写也弄成了小写。像句子"I reset the computer. It still didn’t boot!"已经变成了"iresetthecomputeritstilldidntboot"。在处理标点符号和大小写之前，你得先把它断成词语。当然了，你有一本厚厚的词典dictionary，不过，有些词没在词典里。假设文章用sentence表示，设计一个算法，把文章断开，要求未识别的字符最少，返回未识别的字符数。

注意：本题相对原题稍作改动，只需返回未识别的字符数

 

示例：

输入：
dictionary = ["looked","just","like","her","brother"]
sentence = "jesslookedjustliketimherbrother"
输出： 7
解释： 断句后为"jess looked just like tim her brother"，共7个未识别字符。
提示：

0 <= len(sentence) <= 1000
dictionary中总字符数不超过 150000。
你可以认为dictionary和sentence中只包含小写字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/re-space-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class TrieNode {
public:
    TrieNode() {
        memset(next, 0, sizeof(next));
        isEnd = false;
    }

    bool isEnd;
    TrieNode* next[26];
};

class Trie {
public:
    Trie(vector<string>& dictionary) {
        root = new TrieNode;

        for (string word : dictionary) {
            insert(word);
        }
    }

    void insert(string word) {
        TrieNode* nextNode = root;
        int size = word.size();

        // 这里word按照逆序插入，因为匹配的时候是按照从后往前的顺序查找的。
        for (int i = size - 1; i >= 0; i--) {
            int index = word[i] - 'a';
            if (nextNode->next[index] == NULL) {
                nextNode->next[index] = new TrieNode;
            }

            nextNode = nextNode->next[index];
        }

        nextNode->isEnd = true;
    }

    bool isMatch(string& sentence, int sentenceIndex, vector<int>& matchLen) {
        TrieNode* nextNode = root;
        int count = 0;

        for (int i = sentenceIndex; i >= 0; i--) {
            int index = sentence[i] - 'a';
            if (nextNode->next[index] == NULL) {
                break;
            }

            nextNode = nextNode->next[index];
            count++;
            if (nextNode->isEnd == true) {
                matchLen.push_back(count);  // 一次可能匹配多个
            }
        }

        return !matchLen.empty();
    }

    TrieNode* root;
};

class Solution {
public:
    int respace(vector<string>& dictionary, string sentence) {
        /* dp[i]表示最小的未匹配字符数，如果s[i]没有匹配上，则dp[i]=dp[i-1]+1；
           如果s[i]匹配上了，则可以选择匹配，dp[i]=dp[i-len]，len为匹配上的长度；也可以选择不匹配，dp[i] = dp[i-1]+1。选两者小的。*/
        int size = sentence.size();
        int* dp = new int[size + 1];
        dp[0] = 0;
        Trie trie(dictionary);

        for (int i = 1; i <= size; i++) {
            dp[i] = dp[i - 1] + 1;

            vector<int> matchLen;
            if (trie.isMatch(sentence, i - 1, matchLen)) {
                for (int len : matchLen) {
                    dp[i] = min(dp[i - len], dp[i]);
                }
            }
        }

        int minNoMatch = dp[size];
        delete[] dp;

        return minNoMatch;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> dictionary = { "looked","just","like","her","brother" };
    check.checkInt(7, o.respace(dictionary, "jesslookedjustliketimherbrother"));

    dictionary = { "looked","just","like","her","brother" };
    check.checkInt(0, o.respace(dictionary, ""));

    dictionary = {  };
    check.checkInt(0, o.respace(dictionary, ""));

    dictionary = {  };
    check.checkInt(31, o.respace(dictionary, "jesslookedjustliketimherbrother"));

    dictionary = { "bc","cdefghi","j" };
    check.checkInt(3, o.respace(dictionary, "abcdefghixj"));

    dictionary = { "abc","cd","j" };
    check.checkInt(1, o.respace(dictionary, "abcd"));

    dictionary = { "abcd","def" };
    check.checkInt(2, o.respace(dictionary, "abcdef"));

    dictionary = { "aaysaayayaasyya","yyas","yayysaaayasasssy","yaasassssssayaassyaayaayaasssasysssaaayysaaasaysyaasaaaaaasayaayayysasaaaa",
        "aya","sya","ysasasy","syaaaa","aaaas","ysa","a","aasyaaassyaayaayaasyayaa","ssaayayyssyaayyysyayaasaaa","aya","aaasaay","aaaa",
        "ayyyayssaasasysaasaaayassasysaaayaassyysyaysaayyasayaaysyyaasasasaayyasasyaaaasysasy","aaasa","ysayssyasyyaaasyaaaayaaaaaaaaassaaa",
        "aasayaaaayssayyaayaaaaayaaays","s" };
    check.checkInt(7, o.respace(dictionary, "asasayaayaassayyayyyyssyaassasaysaaysaayaaaaysyaaaa"));
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
