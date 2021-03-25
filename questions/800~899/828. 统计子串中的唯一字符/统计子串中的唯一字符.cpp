/* 统计子串中的唯一字符.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们定义了一个函数 countUniqueChars(s) 来统计字符串 s 中的唯一字符，并返回唯一字符的个数。

例如：s = "LEETCODE" ，则其中 "L", "T","C","O","D" 都是唯一字符，因为它们只出现一次，所以 countUniqueChars(s) = 5 。

本题将会给你一个字符串 s ，我们需要返回 countUniqueChars(t) 的总和，其中 t 是 s 的子字符串。注意，某些子字符串可能是重复的，但你统计时也必须算上这些重复的子字符串（也就是说，你必须统计 s 的所有子字符串中的唯一字符）。

由于答案可能非常大，请将结果 mod 10 ^ 9 + 7 后再返回。

 

示例 1：

输入: s = "ABC"
输出: 10
解释: 所有可能的子串为："A","B","C","AB","BC" 和 "ABC"。
     其中，每一个子串都由独特字符构成。
     所以其长度总和为：1 + 1 + 1 + 2 + 2 + 3 = 10
示例 2：

输入: s = "ABA"
输出: 8
解释: 除了 countUniqueChars("ABA") = 1 之外，其余与示例 1 相同。
示例 3：

输入：s = "LEETCODE"
输出：92
 

提示：

0 <= s.length <= 10^4
s 只包含大写英文字符

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-unique-characters-of-all-substrings-of-a-given-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        int i, size = s.size(), count = 0, total = 0, mod = 1000000007;
        vector<int> dp('Z' + 1, 0);  // dp[i][j]表示以s[i]为结尾的子串中，每个字符贡献的次数，优化到一维空间
        vector<int> indices('Z' + 1, -1);

        for (i = 0; i < size; ++i) {
            char c = s[i];
            count = (count + (i - indices[c] - dp[c])) % mod;  // 其它字符贡献的次数都不会改变，c贡献的次数由dp[c]变为i-indices[c]
            total = (total + count) % mod;
            dp[c] = i - indices[c];  // c最后出现在indices[c]的位置，所以以c结尾的子串，c能贡献的次数是i-indices[c]
            indices[c] = i;
        }

        return total;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(10, o.uniqueLetterString("ABC"));
    check.checkInt(8, o.uniqueLetterString("ABA"));
    check.checkInt(92, o.uniqueLetterString("LEETCODE"));
    check.checkInt(1, o.uniqueLetterString("Z"));
    check.checkInt(2, o.uniqueLetterString("ZZ"));
    check.checkInt(53404, o.uniqueLetterString("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"));
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
