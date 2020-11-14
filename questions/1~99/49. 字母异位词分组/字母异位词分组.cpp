/* 字母异位词分组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

示例:

输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
输出:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
说明：

所有输入均为小写字母。
不考虑答案输出的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/group-anagrams
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int charTable[26];
        unordered_map<string, vector<string>> anagrams;

        for (unsigned int i = 0; i < strs.size(); i++) {
            memset(charTable, 0, sizeof(charTable));
            string word = strs[i];
            for (unsigned int j = 0; j < word.size(); j++) {
                charTable[word[j] - 'a']++;
            }
            string key = hashCharTable(charTable);
            auto iter = anagrams.find(key);
            if (iter == anagrams.end()) {
                anagrams[key] = { word };
            }
            else {
                iter->second.push_back(word);
            }
        }

        vector<vector<string>> ans;
        for (auto iter = anagrams.begin(); iter != anagrams.end(); iter++) {
            ans.push_back(iter->second);
        }

        return ans;
    }

    string hashCharTable(int* charTable) {
        string s;
        for (int i = 0; i < 26; i++) {
            if (charTable[i] != 0) {
                s += ('a' + i);
                s += to_string(charTable[i]);
            }
        }

        return s;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    vector<vector<string>> actual = o.groupAnagrams(strs);
    vector<vector<string>> expected = { {"eat","tea","ate"},{"tan","nat"},{"bat"} };
    check.checkStringVectorVector(expected, actual);

    strs = {  };
    actual = o.groupAnagrams(strs);
    expected = {  };
    check.checkStringVectorVector(expected, actual);

    strs = { "a","b","c" };
    actual = o.groupAnagrams(strs);
    expected = { {"a"},{"b"},{"c"} };
    check.checkStringVectorVector(expected, actual);

    strs = { "abc","bca","cab" };
    actual = o.groupAnagrams(strs);
    expected = { {"abc","bca","cab"} };
    check.checkStringVectorVector(expected, actual);

    strs = { "abc","bca","cab","aabbcc","bbccaa","ccaabb" };
    actual = o.groupAnagrams(strs);
    expected = { {"abc","bca","cab"},{"aabbcc","bbccaa","ccaabb"} };
    check.checkStringVectorVector(expected, actual);
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
