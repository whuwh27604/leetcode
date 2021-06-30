/* 最美子字符串的数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果某个字符串中 至多一个 字母出现 奇数 次，则称其为 最美 字符串。

例如，"ccjjc" 和 "abab" 都是最美字符串，但 "ab" 不是。
给你一个字符串 word ，该字符串由前十个小写英文字母组成（'a' 到 'j'）。请你返回 word 中 最美非空子字符串 的数目。如果同样的子字符串在 word 中出现多次，那么应当对 每次出现 分别计数。

子字符串 是字符串中的一个连续字符序列。

 

示例 1：

输入：word = "aba"
输出：4
解释：4 个最美子字符串如下所示：
- "aba" -> "a"
- "aba" -> "b"
- "aba" -> "a"
- "aba" -> "aba"
示例 2：

输入：word = "aabb"
输出：9
解释：9 个最美子字符串如下所示：
- "aabb" -> "a"
- "aabb" -> "aa"
- "aabb" -> "aab"
- "aabb" -> "aabb"
- "aabb" -> "a"
- "aabb" -> "abb"
- "aabb" -> "b"
- "aabb" -> "bb"
- "aabb" -> "b"
示例 3：

输入：word = "he"
输出：2
解释：2 个最美子字符串如下所示：
- "he" -> "h"
- "he" -> "e"
 

提示：

1 <= word.length <= 105
word 由从 'a' 到 'j' 的小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-wonderful-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"
#include "../tools/TestData.h"

using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long sum = 0;
        int mask = 0;
        vector<int> maskCounts(1024, 0);
        maskCounts[0] = 1;

        for (char c : word) {
            int bit = 1 << (c - 'a');
            mask ^= bit;

            if (maskCounts[mask] != 0) {  // 全部为偶数的子串个数
                sum += maskCounts[mask];
            }

            for (bit = 1; bit < 1024; bit <<= 1) {
                if (maskCounts[mask ^ bit] != 0) {  // 只有一个奇数的子串个数
                    sum += maskCounts[mask ^ bit];
                }
            }

            ++maskCounts[mask];
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkLongLong(4, o.wonderfulSubstrings("aba"));
    check.checkLongLong(9, o.wonderfulSubstrings("aabb"));
    check.checkLongLong(2, o.wonderfulSubstrings("he"));
    check.checkLongLong(1, o.wonderfulSubstrings("j"));
    check.checkLongLong(715, o.wonderfulSubstrings("abcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghij"));
    check.checkLongLong(42762841, o.wonderfulSubstrings(getString("./testcase1.txt")));
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
