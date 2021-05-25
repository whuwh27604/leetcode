/* 哪种连续子字符串更长.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二进制字符串 s 。如果字符串中由 1 组成的 最长 连续子字符串 严格长于 由 0 组成的 最长 连续子字符串，返回 true ；否则，返回 false 。

例如，s = "110100010" 中，由 1 组成的最长连续子字符串的长度是 2 ，由 0 组成的最长连续子字符串的长度是 3 。
注意，如果字符串中不存在 0 ，此时认为由 0 组成的最长连续子字符串的长度是 0 。字符串中不存在 1 的情况也适用此规则。

 

示例 1：

输入：s = "1101"
输出：true
解释：
由 1 组成的最长连续子字符串的长度是 2："1101"
由 0 组成的最长连续子字符串的长度是 1："1101"
由 1 组成的子字符串更长，故返回 true 。
示例 2：

输入：s = "111000"
输出：false
解释：
由 1 组成的最长连续子字符串的长度是 3："111000"
由 0 组成的最长连续子字符串的长度是 3："111000"
由 1 组成的子字符串不比由 0 组成的子字符串长，故返回 false 。
示例 3：

输入：s = "110100010"
输出：false
解释：
由 1 组成的最长连续子字符串的长度是 2："110100010"
由 0 组成的最长连续子字符串的长度是 3："110100010"
由 1 组成的子字符串不比由 0 组成的子字符串长，故返回 false 。
 

提示：

1 <= s.length <= 100
s[i] 不是 '0' 就是 '1'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longer-contiguous-segments-of-ones-than-zeros
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkZeroOnes(string s) {
        char prev = s[0];
        int zeros = 0, ones = 0, maxZeros = 0, maxOnes = 0;

        for (char c : s) {
            if (c == prev) {
                c == '0' ? ++zeros : ++ones;
            }
            else {
                maxZeros = max(maxZeros, zeros);
                maxOnes = max(maxOnes, ones);
                c == '0' ? zeros = 1, ones = 0 : zeros = 0, ones = 1;
            }

            prev = c;
        }

        return max(maxOnes, ones) > max(maxZeros, zeros);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.checkZeroOnes("1101"));
    check.checkBool(false, o.checkZeroOnes("111000"));
    check.checkBool(false, o.checkZeroOnes("110100010"));
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
