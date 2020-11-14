/* 单词替换.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在英语中，我们有一个叫做 词根(root)的概念，它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，跟随着单词 other(其他)，可以形成新的单词 another(另一个)。

现在，给定一个由许多词根组成的词典和一个句子。你需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。

你需要输出替换之后的句子。

 

示例：

输入：dict(词典) = ["cat", "bat", "rat"] sentence(句子) = "the cattle was rattled by the battery"
输出："the cat was rat by the bat"
 

提示：

输入只包含小写字母。
1 <= dict.length <= 1000
1 <= dict[i].length <= 100
1 <= 句中词语数 <= 1000
1 <= 句中词语长度 <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/replace-words
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

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode* trie = createTrie(dict);

        int position, start = 0, end;
        string replaced;
        sentence.push_back(' ');

        while ((position = sentence.find(' ', start)) != sentence.npos) {
            bool findRoot = false;
            TrieNode* node = trie;

            for (end = start; end < position; end++) {
                int index = sentence[end] - 'a';
                if (node->next[index] == NULL) {
                    break;
                }

                node = node->next[index];
                if (node->isEnd) {
                    findRoot = true;
                    break;
                }
            }

            if (!findRoot) {
                end = position - 1;
            }

            replaced.insert(replaced.size(), sentence, start, end - start + 1);
            replaced += ' ';
            start = position + 1;
        }

        replaced.pop_back();
        return replaced;
    }

    TrieNode* createTrie(vector<string>& dict) {
        TrieNode* root = new TrieNode;

        for (string& word : dict) {
            TrieNode* nextNode = root;

            for (char& c : word) {
                int index = c - 'a';
                if (nextNode->next[index] == NULL) {
                    nextNode->next[index] = new TrieNode;
                }

                nextNode = nextNode->next[index];
            }

            nextNode->isEnd = true;
        }

        return root;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> dict = { "cat", "bat", "rat" };
    check.checkString("the cat was rat by the bat", o.replaceWords(dict, "the cattle was rattled by the battery"));

    dict = { "cat", "bat", "rat" };
    check.checkString("ca cat cat", o.replaceWords(dict, "ca cat cattle"));
    
    dict = { "cat", "bat", "a" };
    check.checkString("a a a ba", o.replaceWords(dict, "a ab abc ba"));

    dict = { "a", "b", "c" };
    check.checkString("a a b c", o.replaceWords(dict, "aadsfasf absbs bbab cadsfafs"));
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
