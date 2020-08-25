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

/* 第一感觉是字典树，但由于必须改变一个字符的条件，字典树其实很难处理这个逻辑。考虑字典{"hello", "jello"}，如果要查找hello，到底什么时候改变这个字符呢？
   一个方案就是遍历每个字符变一次的情况，变了后面的字符就要全匹配；不变，后面的字符还需要变一个。这样最差的时间复杂度是O(26*searchWord.size)。
   如果暴力匹配，时间复杂度最差是O(sum(searchWord.size) */
class MagicDictionary {
public:
    /** Initialize your data structure here. */
    MagicDictionary() {

    }

    void buildDict(vector<string> dictionary) {
        for (string& word : dictionary) {
            int size = word.size();
            auto iter = sameLenWords.find(size);
            if (iter == sameLenWords.end()) {
                sameLenWords[size] = { word };
            }
            else {
                iter->second.push_back(word);
            }
        }
    }

    bool search(string searchWord) {
        int size = searchWord.size();
        auto iter = sameLenWords.find(size);
        if (iter == sameLenWords.end()) {
            return false;
        }

        vector<string>& words = iter->second;
        for (string& word : words) {
            if (isPairs(word, searchWord)) {
                return true;
            }
        }

        return false;
    }

    bool isPairs(string& word, string& searchWord) {
        int i, size = word.size(), diff = 0;

        for (i = 0; i < size; i++) {
            if (word[i] == searchWord[i]) {
                continue;
            }

            if (++diff >= 2) {
                break;
            }
        }

        return diff == 1;
    }

private:
    unordered_map<int, vector<string>> sameLenWords;
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
    o4.buildDict({"a"});
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
