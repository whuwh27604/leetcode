/* 实现一个魔法字典.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
实现一个带有buildDict, 以及 search方法的魔法字典。

对于buildDict方法，你将被给定一串不重复的单词来构建一个字典。

对于search方法，你将被给定一个单词，并且判定能否只将这个单词中一个字母换成另一个字母，使得所形成的新单词存在于你构建的字典中。

示例 1:

Input: buildDict(["hello", "leetcode"]), Output: Null
Input: search("hello"), Output: False
Input: search("hhllo"), Output: True
Input: search("hell"), Output: False
Input: search("leetcoded"), Output: False
注意:

你可以假设所有输入都是小写字母 a-z。
为了便于竞赛，测试所用的数据量很小。你可以在竞赛结束后，考虑更高效的算法。
请记住重置MagicDictionary类中声明的类变量，因为静态/类变量会在多个测试用例中保留。 请参阅这里了解更多详情。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-magic-dictionary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
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

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode;
    }

    void buildDict(vector<string> dictionary) {
        for (string& word : dictionary) {
            insert(word);
        }
    }

    void insert(string& word) {
        TrieNode* current = root;

        for (char c : word) {
            int index = c - 'a';
            if (current->next[index] == NULL) {
                current->next[index] = new TrieNode;
            }

            current = current->next[index];
        }

        current->isEnd = true;
    }

    bool searchWithChange(string& searchWord, int start, TrieNode* current) {
        int index = searchWord[start] - 'a';

        if (start == searchWord.size() - 1) {
            for (int i = 0; i < 26; i++) {
                if ((i != index) && (current->next[i] != NULL) && current->next[i]->isEnd) {
                    return true;
                }
            }

            return false;
        }

        for (int i = 0; i < 26; i++) {
            if ((i != index) && (current->next[i] != NULL) && searchWithNoChange(searchWord, start + 1, current->next[i])) {
                return true;
            }
        }

        return (current->next[index] != NULL) && searchWithChange(searchWord, start + 1, current->next[index]);
    }

    bool searchWithNoChange(string& searchWord, int start, TrieNode* current) {
        int index = searchWord[start] - 'a';
        if (current->next[index] == NULL) {
            return false;
        }

        return (start == searchWord.size() - 1) ? current->next[index]->isEnd : searchWithNoChange(searchWord, start + 1, current->next[index]);
    }

    bool search(string searchWord) {
        if (searchWord.empty()) {
            return false;
        }

        return searchWithChange(searchWord, 0, root);
    }

private:
    TrieNode* root;
};

int main()
{
    CheckResult check;

    MagicDictionary o1;
    o1.buildDict({ "hello", "leetcode" });
    check.checkBool(true, o1.search("hhllo"));
    check.checkBool(true, o1.search("hella"));
    check.checkBool(true, o1.search("jello"));
    check.checkBool(false, o1.search("hello"));
    check.checkBool(false, o1.search("hell"));
    check.checkBool(false, o1.search("leetcoded"));
    check.checkBool(false, o1.search("meetcodf"));
    check.checkBool(true, o1.search("jeetcode"));
    check.checkBool(true, o1.search("leekcode"));
    check.checkBool(true, o1.search("leetcodd"));

    MagicDictionary o2;
    o2.buildDict({ "hello", "hella" });
    check.checkBool(true, o2.search("hello"));
    check.checkBool(true, o2.search("hella"));

    MagicDictionary o3;
    o3.buildDict({});
    check.checkBool(false, o3.search("a"));

    MagicDictionary o4;
    o4.buildDict({ "a" });
    check.checkBool(false, o4.search("a"));
    check.checkBool(true, o4.search("b"));

    MagicDictionary o5;
    o5.buildDict({ "a" });
    check.checkBool(false, o5.search(""));
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
