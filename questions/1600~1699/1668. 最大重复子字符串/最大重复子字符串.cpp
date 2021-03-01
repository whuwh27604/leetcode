/* 最大重复子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 sequence ，如果字符串 word 连续重复 k 次形成的字符串是 sequence 的一个子字符串，那么单词 word 的 重复值为 k 。单词 word 的 最大重复值 是单词 word 在 sequence 中最大的重复值。如果 word 不是 sequence 的子串，那么重复值 k 为 0 。

给你一个字符串 sequence 和 word ，请你返回 最大重复值 k 。

 

示例 1：

输入：sequence = "ababc", word = "ab"
输出：2
解释："abab" 是 "ababc" 的子字符串。
示例 2：

输入：sequence = "ababc", word = "ba"
输出：1
解释："ba" 是 "ababc" 的子字符串，但 "baba" 不是 "ababc" 的子字符串。
示例 3：

输入：sequence = "ababc", word = "ac"
输出：0
解释："ac" 不是 "ababc" 的子字符串。
 

提示：

1 <= sequence.length <= 100
1 <= word.length <= 100
sequence 和 word 都只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-repeating-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int i, j, sizeSeq = sequence.size(), sizeWord = word.size(), maxRepeat = 0;

        for (int start = 0; start < sizeWord; ++start) {
            int repeat = 0;

            for (i = start; i < sizeSeq; i += sizeWord) {
                bool equal = true;

                for (j = 0; j < sizeWord; ++j) {
                    if (word[j] != sequence[i + j]) {
                        equal = false;
                        break;
                    }
                }

                if (equal) {
                    ++repeat;
                    maxRepeat = max(maxRepeat, repeat);
                }
                else {
                    repeat = 0;
                }
            }
        }

        return maxRepeat;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.maxRepeating("ababc", "ba"));
    check.checkInt(2, o.maxRepeating("ababc", "ab"));
    check.checkInt(0, o.maxRepeating("ababc", "ac"));
    check.checkInt(5, o.maxRepeating("aaabaaaabaaabaaaabaaaabaaaabaaaaba", "aaaba"));
    check.checkInt(6, o.maxRepeating("aaaaaa", "a"));
    check.checkInt(1, o.maxRepeating("a", "a"));
    check.checkInt(0, o.maxRepeating("b", "a"));
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
