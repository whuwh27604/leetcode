/* 含特定字母的最小子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，一个整数 k ，一个字母 letter 以及另一个整数 repetition 。

返回 s 中长度为 k 且 字典序最小 的子序列，该子序列同时应满足字母 letter 出现 至少 repetition 次。生成的测试用例满足 letter 在 s 中出现 至少 repetition 次。

子序列 是由原字符串删除一些（或不删除）字符且不改变剩余字符顺序得到的剩余字符串。

字符串 a 字典序比字符串 b 小的定义为：在 a 和 b 出现不同字符的第一个位置上，字符串 a 的字符在字母表中的顺序早于字符串 b 的字符。

 

示例 1：

输入：s = "leet", k = 3, letter = "e", repetition = 1
输出："eet"
解释：存在 4 个长度为 3 ，且满足字母 'e' 出现至少 1 次的子序列：
- "lee"（"leet"）
- "let"（"leet"）
- "let"（"leet"）
- "eet"（"leet"）
其中字典序最小的子序列是 "eet" 。
示例 2：



输入：s = "leetcode", k = 4, letter = "e", repetition = 2
输出："ecde"
解释："ecde" 是长度为 4 且满足字母 "e" 出现至少 2 次的字典序最小的子序列。
示例 3：

输入：s = "bb", k = 2, letter = "b", repetition = 2
输出："bb"
解释："bb" 是唯一一个长度为 2 且满足字母 "b" 出现至少 2 次的子序列。
 

提示：

1 <= repetition <= k <= s.length <= 5 * 104
s 由小写英文字母组成
letter 是一个小写英文字母，在 s 中至少出现 repetition 次

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <deque>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int size = s.size(), delCount = 0, delLetter = 0, letterCount = 0;
        deque<char> letters;
        string subseq;

        for (char c : s) {
            if (c == letter) {
                ++letterCount;
            }
        }

        for (char c : s) {
            while (!letters.empty() && c < letters.back() && delCount < size - k) {
                if (letters.back() == letter && delLetter + repetition == letterCount) {
                    break;
                }

                delLetter += (letters.back() == letter ? 1 : 0);
                delCount += 1;
                letters.pop_back();
            }

            letters.push_back(c);
        }

        letterCount = 0;
                
        while ((int)subseq.size() < k) {
            if (k - (int)subseq.size() == repetition - letterCount) {
                subseq += string(repetition - letterCount, letter);
                break;
            }

            letterCount += (letters.front() == letter ? 1 : 0);
            subseq.push_back(letters.front());
            letters.pop_front();
        }

        return subseq;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("eet", o.smallestSubsequence("leet", 3, 'e', 1));
    check.checkString("ecde", o.smallestSubsequence("leetcode", 4, 'e', 2));
    check.checkString("bb", o.smallestSubsequence("bb", 2, 'b', 2));
    check.checkString("z", o.smallestSubsequence("z", 1, 'z', 1));
    check.checkString("fffffffff", o.smallestSubsequence("facfffkfnffoppfffzfz", 9, 'f', 9));
    check.checkString("aaaaffdfff", o.smallestSubsequence("afjhfhfhfkdfhfahfahfhflahfhfdhlkhfqeruefhjfey", 10, 'f', 5));
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
