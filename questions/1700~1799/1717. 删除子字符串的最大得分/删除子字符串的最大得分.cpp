/* 删除子字符串的最大得分.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和两个整数 x 和 y 。你可以执行下面两种操作任意次。

删除子字符串 "ab" 并得到 x 分。
比方说，从 "cabxbae" 删除 ab ，得到 "cxbae" 。
删除子字符串"ba" 并得到 y 分。
比方说，从 "cabxbae" 删除 ba ，得到 "cabxe" 。
请返回对 s 字符串执行上面操作若干次能得到的最大得分。

 

示例 1：

输入：s = "cdbcbbaaabab", x = 4, y = 5
输出：19
解释：
- 删除 "cdbcbbaaabab" 中加粗的 "ba" ，得到 s = "cdbcbbaaab" ，加 5 分。
- 删除 "cdbcbbaaab" 中加粗的 "ab" ，得到 s = "cdbcbbaa" ，加 4 分。
- 删除 "cdbcbbaa" 中加粗的 "ba" ，得到 s = "cdbcba" ，加 5 分。
- 删除 "cdbcba" 中加粗的 "ba" ，得到 s = "cdbc" ，加 5 分。
总得分为 5 + 4 + 5 + 5 = 19 。
示例 2：

输入：s = "aabbaaxybbaabb", x = 5, y = 4
输出：20
 

提示：

1 <= s.length <= 105
1 <= x, y <= 104
s 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-score-from-removing-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        s += 'c';
        return x > y ? maxGain(s, x, y, 'a', 'b') : maxGain(s, y, x, 'b', 'a');
    }

    int maxGain(string& s, int x, int y, char a, char b) {
        int countA = 0, countB = 0, gain = 0;

        for (char c : s) {
            if (c == a) {
                ++countA;
            }
            else if (c == b) {
                if (countA != 0) {
                    --countA;
                    gain += x;
                }
                else {
                    ++countB;
                }
            }
            else {
                gain += (min(countA, countB) * y);
                countA = 0;
                countB = 0;
            }
        }

        return gain;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(0, o.maximumGain("a", 4, 5));
    check.checkInt(4, o.maximumGain("ab", 4, 5));
    check.checkInt(5, o.maximumGain("ba", 4, 5));
    check.checkInt(5, o.maximumGain("aba", 4, 5));
    check.checkInt(19, o.maximumGain("bbaaabab", 4, 5));
    check.checkInt(19, o.maximumGain("cdbcbbaaabab", 4, 5));
    check.checkInt(16, o.maximumGain("cdbcbbaaabab", 5, 3));
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
