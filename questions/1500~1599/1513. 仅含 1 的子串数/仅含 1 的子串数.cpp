/* 仅含 1 的子串数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二进制字符串 s（仅由 '0' 和 '1' 组成的字符串）。

返回所有字符都为 1 的子字符串的数目。

由于答案可能很大，请你将它对 10^9 + 7 取模后返回。

 

示例 1：

输入：s = "0110111"
输出：9
解释：共有 9 个子字符串仅由 '1' 组成
"1" -> 5 次
"11" -> 3 次
"111" -> 1 次
示例 2：

输入：s = "101"
输出：2
解释：子字符串 "1" 在 s 中共出现 2 次
示例 3：

输入：s = "111111"
输出：21
解释：每个子字符串都仅由 '1' 组成
示例 4：

输入：s = "000"
输出：0
 

提示：

s[i] == '0' 或 s[i] == '1'
1 <= s.length <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-substrings-with-only-1s
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numSub(string s) {
        int subs = 0, mod = 1000000007;
        long long count = 0;

        s += '0';

        for (char c : s) {
            if (c == '1') {
                ++count;
            }
            else {
                subs = (int)((subs + count * (count + 1) / 2) % mod);
                count = 0;
            }
        }

        return subs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(9, o.numSub("0110111"));
    check.checkInt(2, o.numSub("101"));
    check.checkInt(21, o.numSub("111111"));
    check.checkInt(0, o.numSub("000"));
    check.checkInt(0, o.numSub("0"));
    check.checkInt(1, o.numSub("1"));
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
