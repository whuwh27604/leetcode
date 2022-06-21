/* 小于等于 K 的最长二进制子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二进制字符串 s 和一个正整数 k 。

请你返回 s 的 最长 子序列，且该子序列对应的 二进制 数字小于等于 k 。

注意：

子序列可以有 前导 0 。
空字符串视为 0 。
子序列 是指从一个字符串中删除零个或者多个字符后，不改变顺序得到的剩余字符序列。
 

示例 1：

输入：s = "1001010", k = 5
输出：5
解释：s 中小于等于 5 的最长子序列是 "00010" ，对应的十进制数字是 2 。
注意 "00100" 和 "00101" 也是可行的最长子序列，十进制分别对应 4 和 5 。
最长子序列的长度为 5 ，所以返回 5 。
示例 2：

输入：s = "00101001", k = 1
输出：6
解释："000001" 是 s 中小于等于 1 的最长子序列，对应的十进制数字是 1 。
最长子序列的长度为 6 ，所以返回 6 。
 

提示：

1 <= s.length <= 1000
s[i] 要么是 '0' ，要么是 '1' 。
1 <= k <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/longest-binary-subsequence-less-than-or-equal-to-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        string sk = binaryString(k);
        int sizeS = s.size(), sizeK = sk.size();

        if (sizeS < sizeK) {
            return sizeS;
        }

        string last(s, sizeS - sizeK, sizeK);
        int subseq = (last.compare(sk) <= 0) ? sizeK : sizeK - 1;

        for (int i = 0; i < sizeS - sizeK; ++i) {
            if (s[i] == '0') {
                ++subseq;
            }
        }

        return subseq;
    }

    string binaryString(int k) {
        string s;

        while (k != 0) {
            s.push_back((k & 1) == 0 ? '0' : '1');
            k >>= 1;
        }

        reverse(s.begin(), s.end());

        return s;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(5, o.longestSubsequence("1001010", 5));
    check.checkInt(6, o.longestSubsequence("00101001", 1));
    check.checkInt(2, o.longestSubsequence("110", 5));
    check.checkInt(3, o.longestSubsequence("101", 5));
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
