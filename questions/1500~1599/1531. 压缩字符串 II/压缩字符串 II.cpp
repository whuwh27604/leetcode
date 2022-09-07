/* 压缩字符串 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
行程长度编码 是一种常用的字符串压缩方法，它将连续的相同字符（重复 2 次或更多次）替换为字符和表示字符计数的数字（行程长度）。例如，用此方法压缩字符串 "aabccc" ，将 "aa" 替换为 "a2" ，"ccc" 替换为` "c3" 。因此压缩后的字符串变为 "a2bc3" 。

注意，本问题中，压缩时没有在单个字符后附加计数 '1' 。

给你一个字符串 s 和一个整数 k 。你需要从字符串 s 中删除最多 k 个字符，以使 s 的行程长度编码长度最小。

请你返回删除最多 k 个字符后，s 行程长度编码的最小长度 。

 

示例 1：

输入：s = "aaabcccd", k = 2
输出：4
解释：在不删除任何内容的情况下，压缩后的字符串是 "a3bc3d" ，长度为 6 。最优的方案是删除 'b' 和 'd'，这样一来，压缩后的字符串为 "a3c3" ，长度是 4 。
示例 2：

输入：s = "aabbaa", k = 2
输出：2
解释：如果删去两个 'b' 字符，那么压缩后的字符串是长度为 2 的 "a4" 。
示例 3：

输入：s = "aaaaaaaaaaa", k = 0
输出：3
解释：由于 k 等于 0 ，不能删去任何字符。压缩后的字符串是 "a11" ，长度为 3 。
 

提示：

1 <= s.length <= 100
0 <= k <= s.length
s 仅包含小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/string-compression-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int size = s.size();
        vector<vector<int>> dp(size + 1, vector<int>(k + 1, INT_MAX / 2));  // dp[len][del]表示s的前len个字符删除del个字符后的最小行程编码长度
        dp[0][0] = 0;

        for (int len = 1; len <= size; ++len) {
            for (int del = 0; del <= k && del <= len; ++del) {
                if (del != 0) {
                    dp[len][del] = dp[len - 1][del - 1];  // 删除最后一个字符，剩下len - 1长度还可以删除del - 1个字符
                }

                // 不删除最后一个字符，设为x，那么枚举最后一个连续xxx...x的长度。对每个xxx...x，从后往前删除其中不是x的字符得到xxx...x是最优解
                int count = 0, diff = 0;

                for (int last = len; last >= 1 && diff <= del; --last) {
                    if (s[last - 1] == s[len - 1]) {
                        ++count;

                        // 最后是count个连续的x，它的长度是getLen(count)，这中间删除了diff个字符；前面还剩last - 1个字符，还可以删除del - diff个字符
                        dp[len][del] = min(dp[len][del], dp[last - 1][del - diff] + getLen(count));
                    }
                    else {
                        ++diff;
                    }
                }
            }
        }

        return dp[size][k];
    }

    int getLen(int count) {
        return count == 1 ? 1 : (count < 10 ? 2 : (count < 100 ? 3 : 4));
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(4, o.getLengthOfOptimalCompression("aaabcccd", 2));
    check.checkInt(2, o.getLengthOfOptimalCompression("aabbaa", 2));
    check.checkInt(3, o.getLengthOfOptimalCompression("aaaaaaaaaaa", 0));
    check.checkInt(4, o.getLengthOfOptimalCompression("abcedfg", 3));
    check.checkInt(1, o.getLengthOfOptimalCompression("ab", 1));
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
