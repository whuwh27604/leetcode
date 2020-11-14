/* 无重复字符的最长子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int i, j, start = 0, strLen = s.size(), substrLen = 0, maxSubstrLen = 0;

        for (i = 0; i < strLen; i++) {
            auto iter = charIndex.find(s[i]);
            if (iter == charIndex.end()) {
                charIndex[s[i]] = i;
                substrLen++;
                continue;
            }

            int repeatingCharIndex = iter->second;
            for (j = start; j <= repeatingCharIndex; j++) {
                charIndex.erase(s[j]);
            }

            maxSubstrLen = (maxSubstrLen > substrLen) ? maxSubstrLen : substrLen;
            substrLen = i - repeatingCharIndex;
            charIndex[s[i]] = i;
            start = repeatingCharIndex + 1;
        }

        return (maxSubstrLen > substrLen) ? maxSubstrLen : substrLen;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(3, o.lengthOfLongestSubstring("abcabcbb"));
    check.checkInt(1, o.lengthOfLongestSubstring("bbbbb"));
    check.checkInt(3, o.lengthOfLongestSubstring("pwwkew"));
    check.checkInt(0, o.lengthOfLongestSubstring(""));
    check.checkInt(5, o.lengthOfLongestSubstring("abcde"));
    check.checkInt(5, o.lengthOfLongestSubstring("ababcde"));
    check.checkInt(2, o.lengthOfLongestSubstring("aabbcc"));
    check.checkInt(5, o.lengthOfLongestSubstring("abcdea"));
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
