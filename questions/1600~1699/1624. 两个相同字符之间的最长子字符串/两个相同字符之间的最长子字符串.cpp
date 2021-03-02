/* 两个相同字符之间的最长子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s，请你返回 两个相同字符之间的最长子字符串的长度 ，计算长度时不含这两个字符。如果不存在这样的子字符串，返回 -1 。

子字符串 是字符串中的一个连续字符序列。

 

示例 1：

输入：s = "aa"
输出：0
解释：最优的子字符串是两个 'a' 之间的空子字符串。
示例 2：

输入：s = "abca"
输出：2
解释：最优的子字符串是 "bc" 。
示例 3：

输入：s = "cbzxy"
输出：-1
解释：s 中不存在出现出现两次的字符，所以返回 -1 。
示例 4：

输入：s = "cabbac"
输出：4
解释：最优的子字符串是 "abba" ，其他的非最优解包括 "bb" 和 "" 。
 

提示：

1 <= s.length <= 300
s 只含小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-substring-between-two-equal-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int i, size = s.size(), maxLen = -1;
        vector<int> firstIndices('z' + 1, -1);

        for (i = 0; i < size; ++i) {
            if (firstIndices[s[i]] == -1) {
                firstIndices[s[i]] = i;
            }
            else {
                maxLen = max(maxLen, i - firstIndices[s[i]] - 1);
            }
        }

        return maxLen;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(0, o.maxLengthBetweenEqualCharacters("aa"));
    check.checkInt(2, o.maxLengthBetweenEqualCharacters("abca"));
    check.checkInt(-1, o.maxLengthBetweenEqualCharacters("cbzxy"));
    check.checkInt(4, o.maxLengthBetweenEqualCharacters("cabbac"));
    check.checkInt(-1, o.maxLengthBetweenEqualCharacters("z"));
    check.checkInt(11, o.maxLengthBetweenEqualCharacters("zzzzzzzzzzzzz"));
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
