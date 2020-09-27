/* 至少有K个重复字符的最长子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。输出 T 的长度。

示例 1:

输入:
s = "aaabb", k = 3

输出:
3

最长子串为 "aaa" ，其中 'a' 重复了 3 次。
示例 2:

输入:
s = "ababbc", k = 2

输出:
5

最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int longestSubstr = 0;
        list<pair<int, int>> splitSections;
        splitSections.push_back({ 0, s.size() - 1 });

        while (!splitSections.empty()) {
            int start = splitSections.front().first;
            int end = splitSections.front().second;
            splitSections.pop_front();

            if ((end - start + 1) <= longestSubstr) {
                continue;
            }

            unordered_map<char, vector<int>> charCount;  // vector[0]记录char的个数，vector[1...n]记录char的index
            for (int i = start; i <= end; i++) {
                auto iter = charCount.find(s[i]);
                if (iter == charCount.end()) {
                    charCount[s[i]] = { 1,i };
                }
                else {
                    iter->second[0]++;
                    if (iter->second[0] < k) {
                        iter->second.push_back(i);
                    }
                }
            }

            set<int> lessKIndexs;
            bool noLessKSection = true;

            for (auto iter = charCount.begin(); iter != charCount.end(); iter++) {
                if (iter->second[0] >= k) {
                    continue;
                }

                noLessKSection = false;

                for (int i = 1; i <= iter->second[0]; i++) {
                    lessKIndexs.insert(iter->second[i]);  // 所有小于k次的字符的index按顺序排好
                }
            }

            if (noLessKSection) {
                longestSubstr = max(longestSubstr, end - start + 1);
                continue;
            }

            int splitStart = start, splitEnd;  // 以小于k次的字符的index为边界，把原区间划分为n个小的区间
            for (auto iter = lessKIndexs.begin(); iter != lessKIndexs.end(); iter++) {
                splitEnd = *iter - 1;
                splitSections.push_back({ splitStart, splitEnd });
                splitStart = *iter + 1;
            }
            splitSections.push_back({ splitStart, end });
        }

        return longestSubstr;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(3, o.longestSubstring("aaabb", 3));
    check.checkInt(5, o.longestSubstring("aaabb", 0));
    check.checkInt(5, o.longestSubstring("aaabb", 1));
    check.checkInt(5, o.longestSubstring("aaabb", 2));
    check.checkInt(0, o.longestSubstring("aaabb", 4));
    check.checkInt(5, o.longestSubstring("daaabb", 2));
    check.checkInt(5, o.longestSubstring("daaabbc", 2));
    check.checkInt(5, o.longestSubstring("daaabbcd", 2));
    check.checkInt(5, o.longestSubstring("ababbc", 2));
    check.checkInt(6, o.longestSubstring("ababbc", 1));
    check.checkInt(0, o.longestSubstring("ababbc", 3));
    check.checkInt(0, o.longestSubstring("ababacb", 3));
    check.checkInt(21, o.longestSubstring("abcdbcdacaaaaadabdabc", 4));
    check.checkInt(5, o.longestSubstring("abcdbcdacaaaaadabdabc", 5));
    check.checkInt(0, o.longestSubstring("abcdbcdacaaaaadabdabc", 6));
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
