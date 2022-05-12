/* 字符流.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
设计一个算法：接收一个字符流，并检查这些字符的后缀是否是字符串数组 words 中的一个字符串。

例如，words = ["abc", "xyz"] 且字符流中逐个依次加入 4 个字符 'a'、'x'、'y' 和 'z' ，你所设计的算法应当可以检测到 "axyz" 的后缀 "xyz" 与 words 中的字符串 "xyz" 匹配。

按下述要求实现 StreamChecker 类：

StreamChecker(String[] words) ：构造函数，用字符串数组 words 初始化数据结构。
boolean query(char letter)：从字符流中接收一个新字符，如果字符流中的任一非空后缀能匹配 words 中的某一字符串，返回 true ；否则，返回 false。
 

示例：

输入：
["StreamChecker", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query", "query"]
[[["cd", "f", "kl"]], ["a"], ["b"], ["c"], ["d"], ["e"], ["f"], ["g"], ["h"], ["i"], ["j"], ["k"], ["l"]]
输出：
[null, false, false, false, true, false, true, false, false, false, false, false, true]

解释：
StreamChecker streamChecker = new StreamChecker(["cd", "f", "kl"]);
streamChecker.query("a"); // 返回 False
streamChecker.query("b"); // 返回 False
streamChecker.query("c"); // 返回n False
streamChecker.query("d"); // 返回 True ，因为 'cd' 在 words 中
streamChecker.query("e"); // 返回 False
streamChecker.query("f"); // 返回 True ，因为 'f' 在 words 中
streamChecker.query("g"); // 返回 False
streamChecker.query("h"); // 返回 False
streamChecker.query("i"); // 返回 False
streamChecker.query("j"); // 返回 False
streamChecker.query("k"); // 返回 False
streamChecker.query("l"); // 返回 True ，因为 'kl' 在 words 中
 

提示：

1 <= words.length <= 2000
1 <= words[i].length <= 2000
words[i] 由小写英文字母组成
letter 是一个小写英文字母
最多调用查询 4 * 104 次

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/stream-of-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class TrieNode {
public:
    TrieNode() {
        memset(next, 0, sizeof(TrieNode*) * 26);
        isEnd = false;
    }

    bool isEnd;
    TrieNode* next[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode;
    }

    void insert(string& word) {
        TrieNode* node = root;

        for (int i = word.size() - 1; i >= 0; --i) {
            int index = word[i] - 'a';

            if (node->next[index] == NULL) {
                node->next[index] = new TrieNode;
            }

            node = node->next[index];
        }

        node->isEnd = true;
    }

    bool search(string& word) {
        TrieNode* node = root;

        for (int i = word.size() - 1; i >= 0; --i) {
            int index = word[i] - 'a';

            if (node->next[index] == NULL) {
                return false;
            }

            node = node->next[index];

            if (node->isEnd) {
                return true;
            }
        }

        return false;
    }

private:
    TrieNode* root;
};

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        for (string& word : words) {
            trie.insert(word);
        }
    }

    bool query(char letter) {
        s.push_back(letter);

        return trie.search(s);
    }

private:
    Trie trie;
    string s;
};

int main()
{
    CheckResult check;

    vector<string> words = { "cd", "f", "kl" };
    StreamChecker o1(words);
    check.checkBool(false, o1.query('a'));
    check.checkBool(false, o1.query('b'));
    check.checkBool(false, o1.query('c'));
    check.checkBool(true, o1.query('d'));
    check.checkBool(false, o1.query('e'));
    check.checkBool(true, o1.query('f'));
    check.checkBool(false, o1.query('g'));
    check.checkBool(false, o1.query('h'));
    check.checkBool(false, o1.query('i'));
    check.checkBool(false, o1.query('j'));
    check.checkBool(false, o1.query('k'));
    check.checkBool(true, o1.query('l'));
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
