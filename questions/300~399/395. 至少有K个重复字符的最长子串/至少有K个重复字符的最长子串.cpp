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
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        return getLongestSubstr(s, k, 0, s.size() - 1);
    }

    int getLongestSubstr(string& s, int k, int start, int end) {
        if (end - start + 1 < k) {
            return 0;
        }

        vector<int> lettersCount(26);
        int left = start - 1, right, longestSubstr = 0;

        for (int i = start; i <= end; ++i) {
            ++lettersCount[s[i] - 'a'];
        }

        for (right = start; right <= end; ++right) {
            if (lettersCount[s[right] - 'a'] < k) {  // 当前字符的个数小于k，那么它一定不在目标子串中
                longestSubstr = max(longestSubstr, getLongestSubstr(s, k, left + 1, right - 1));
                left = right;
            }
        }

        if (left == start - 1) {  // 没有小于k的字符，返回整个区间的长度
            return end - start + 1;
        }

        if (left != end) {  // 如果s[end]大于k，最后一个子区间还没有计算，补上
            longestSubstr = max(longestSubstr, getLongestSubstr(s, k, left + 1, end));
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
