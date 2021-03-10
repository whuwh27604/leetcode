/* 统计一致字符串的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由不同字符组成的字符串 allowed 和一个字符串数组 words 。如果一个字符串的每一个字符都在 allowed 中，就称这个字符串是 一致字符串 。

请你返回 words 数组中 一致字符串 的数目。

 

示例 1：

输入：allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
输出：2
解释：字符串 "aaab" 和 "baa" 都是一致字符串，因为它们只包含字符 'a' 和 'b' 。
示例 2：

输入：allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
输出：7
解释：所有字符串都是一致的。
示例 3：

输入：allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
输出：4
解释：字符串 "cc"，"acd"，"ac" 和 "d" 是一致字符串。
 

提示：

1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
allowed 中的字符 互不相同 。
words[i] 和 allowed 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-the-number-of-consistent-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> allowedLetters('z' + 1, 0);
        int count = 0;

        getAllowedLetters(allowed, allowedLetters);

        for (string& word : words) {
            if (isAllowedWord(allowedLetters, word)) {
                ++count;
            }
        }

        return count;
    }

    void getAllowedLetters(string& allowed, vector<int>& allowedLetters) {
        for (char c : allowed) {
            allowedLetters[c] = 1;
        }
    }

    bool isAllowedWord(vector<int>& allowedLetters, string& word) {
        for (char c : word) {
            if (allowedLetters[c] == 0) {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "ad","bd","aaab","baa","badab" };
    check.checkInt(2, o.countConsistentStrings("ab", words));

    words = { "a","b","c","ab","ac","bc","abc" };
    check.checkInt(7, o.countConsistentStrings("abc", words));

    words = { "cc","acd","b","ba","bac","bad","ac","d" };
    check.checkInt(4, o.countConsistentStrings("cad", words));

    words = { "c" };
    check.checkInt(1, o.countConsistentStrings("c", words));

    words = { "d" };
    check.checkInt(0, o.countConsistentStrings("c", words));
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
