/* 使字符串总不同字符的数目相等.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的字符串 word1 和 word2 。

一次 移动 由以下两个步骤组成：

选中两个下标 i 和 j ，分别满足 0 <= i < word1.length 和 0 <= j < word2.length ，
交换 word1[i] 和 word2[j] 。
如果可以通过 恰好一次 移动，使 word1 和 word2 中不同字符的数目相等，则返回 true ；否则，返回 false 。



示例 1：

输入：word1 = "ac", word2 = "b"
输出：false
解释：交换任何一组下标都会导致第一个字符串中有 2 个不同的字符，而在第二个字符串中只有 1 个不同字符。
示例 2：

输入：word1 = "abcc", word2 = "aab"
输出：true
解释：交换第一个字符串的下标 2 和第二个字符串的下标 0 。之后得到 word1 = "abac" 和 word2 = "cab" ，各有 3 个不同字符。
示例 3：

输入：word1 = "abcde", word2 = "fghij"
输出：true
解释：无论交换哪一组下标，两个字符串中都会有 5 个不同字符。


提示：

1 <= word1.length, word2.length <= 105
word1 和 word2 仅由小写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> cnt1(26, 0), cnt2(26, 0);
        int types1 = count(word1, cnt1), types2 = count(word2, cnt2);

        for (int i = 0; i < 26; ++i) {
            if (cnt1[i] != 0) {
                if (--cnt1[i] == 0) {
                    --types1;
                }
                if (++cnt2[i] == 1) {
                    ++types2;
                }

                for (int j = 0; j < 26; ++j) {
                    if (cnt2[j] != 0 && !(j == i && (cnt2[j] == 1))) {
                        if (++cnt1[j] == 1) {
                            ++types1;
                        }
                        if (--cnt2[j] == 0) {
                            --types2;
                        }

                        if (types1 == types2) {
                            return true;
                        }

                        if (--cnt1[j] == 0) {
                            --types1;
                        }
                        if (++cnt2[j] == 1) {
                            ++types2;
                        }
                    }
                }

                if (++cnt1[i] == 1) {
                    ++types1;
                }
                if (--cnt2[i] == 0) {
                    --types2;
                }
            }
        }

        return false;
    }

    int count(string& word, vector<int>& cnt) {
        int types = 0;

        for (char c : word) {
            ++cnt[c - 'a'];
        }

        for (int num : cnt) {
            if (num != 0) {
                ++types;
            }
        }

        return types;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.isItPossible("abcc", "aab"));
    check.checkBool(true, o.isItPossible("abcde", "fghij"));
    check.checkBool(true, o.isItPossible("a", "a"));
    check.checkBool(true, o.isItPossible("ac", "caca"));
    check.checkBool(false, o.isItPossible("ac", "b"));
    check.checkBool(false, o.isItPossible("a", "bb"));
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
