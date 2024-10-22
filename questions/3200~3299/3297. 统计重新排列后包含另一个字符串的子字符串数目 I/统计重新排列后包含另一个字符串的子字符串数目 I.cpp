/* 统计重新排列后包含另一个字符串的子字符串数目 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 word1 和 word2 。

如果一个字符串 x 重新排列后，word2 是重排字符串的
前缀
 ，那么我们称字符串 x 是 合法的 。

请你返回 word1 中 合法
子字符串
 的数目。



示例 1：

输入：word1 = "bcca", word2 = "abc"

输出：1

解释：

唯一合法的子字符串是 "bcca" ，可以重新排列得到 "abcc" ，"abc" 是它的前缀。

示例 2：

输入：word1 = "abcabc", word2 = "abc"

输出：10

解释：

除了长度为 1 和 2 的所有子字符串都是合法的。

示例 3：

输入：word1 = "abcabc", word2 = "aaabc"

输出：0



解释：

1 <= word1.length <= 105
1 <= word2.length <= 104
word1 和 word2 都只包含小写英文字母。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> count1(26, 0), count2(26, 0);
        int size = (int)word1.size(), right = 0, idx = 0, target = 0, mask = 0;
        long long subs = 0;

        countWord2(word2, count2, target);

        for (int left = 0; left < size; ++left) {
            while (right < size && mask != target) {
                idx = word1[right++] - 'a';
                if (++count1[idx] >= count2[idx] && count2[idx] != 0) {
                    mask |= (1 << idx);
                }
            }

            if (mask == target) {
                subs += ((long long)size - right + 1);
            }

            idx = word1[left] - 'a';
            if (--count1[idx] < count2[idx]) {
                mask &= ~(1 << idx);
            }
        }

        return subs;
    }

    void countWord2(string& word2, vector<int>& count2, int& target) {
        for (char c : word2) {
            ++count2[c - 'a'];
        }

        for (int i = 0, bit = 1; i < 26; ++i, bit <<= 1) {
            if (count2[i] != 0) {
                target |= bit;
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkLongLong(1, o.validSubstringCount("bcca", "abc"));
    check.checkLongLong(10, o.validSubstringCount("abcabc", "abc"));
    check.checkLongLong(0, o.validSubstringCount("abcabc", "aaabc"));
    check.checkLongLong(15, o.validSubstringCount("zzzzz", "z"));
    check.checkLongLong(62, o.validSubstringCount("dddddededddeeeddd", "eee"));
    check.checkLongLong(1, o.validSubstringCount("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz"));
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
