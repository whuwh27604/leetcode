/* 找到字符串中所有字母异位词.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

说明：

字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。
示例 1:

输入:
s: "cbaebabacd" p: "abc"

输出:
[0, 6]

解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
 示例 2:

输入:
s: "abab" p: "ab"

输出:
[0, 1, 2]

解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-anagrams-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sizeS = s.size(), sizeP = p.size();
        int i, charCountS[123] = { 0 }, charCountP[123] = {0};

        for (i = 0; i < sizeP; i++) {
            charCountP[p[i]]++;
        }

        int left = 0, right = 0;
        vector<int> anagramIndexs;

        while (right < sizeS) {
            char c = s[right];
            if (charCountP[c] == 0) {  // 该字符在p中没有，统统清空
                left = ++right;
                for (i = 'a'; i <= 'z'; i++) {
                    charCountS[i] = 0;
                }
                continue;
            }

            charCountS[c]++;
            if (charCountS[c] > charCountP[c]) {  // c字符超标了，窗口收缩到移除一个c
                while (s[left] != c) {
                    charCountS[s[left++]]--;
                }
                charCountS[s[left++]]--;
            }

            right++;  // 有效字符，扩张窗口。如果窗口扩张到p的大小，说明找到一个anagram
            if ((right - left) == sizeP) {
                anagramIndexs.push_back(left);
            }
        }

        return anagramIndexs;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> actual = o.findAnagrams("cbaebabacd", "abc");
    vector<int> expected = { 0,6 };
    check.checkIntVector(expected, actual);

    actual = o.findAnagrams("abab", "ab");
    expected = { 0,1,2 };
    check.checkIntVector(expected, actual);

    actual = o.findAnagrams("", "ab");
    expected = {  };
    check.checkIntVector(expected, actual);

    actual = o.findAnagrams("ab", "ab");
    expected = { 0 };
    check.checkIntVector(expected, actual);

    actual = o.findAnagrams("baaaaaxab", "ab");
    expected = { 0,7 };
    check.checkIntVector(expected, actual);

    actual = o.findAnagrams("aaaaa", "a");
    expected = { 0,1,2,3,4 };
    check.checkIntVector(expected, actual);

    actual = o.findAnagrams("abcde", "abcde");
    expected = { 0 };
    check.checkIntVector(expected, actual);

    actual = o.findAnagrams("abcde", "abcdef");
    expected = {  };
    check.checkIntVector(expected, actual);
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
