/* 包含所有三种字符的子字符串数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，它只包含三种字符 a, b 和 c 。

请你返回 a，b 和 c 都 至少 出现过一次的子字符串数目。

 

示例 1：

输入：s = "abcabc"
输出：10
解释：包含 a，b 和 c 各至少一次的子字符串为 "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" 和 "abc" (相同字符串算多次)。
示例 2：

输入：s = "aaacb"
输出：3
解释：包含 a，b 和 c 各至少一次的子字符串为 "aaacb", "aacb" 和 "acb" 。
示例 3：

输入：s = "abc"
输出：1
 

提示：

3 <= s.length <= 5 x 10^4
s 只包含字符 a，b 和 c 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-substrings-containing-all-three-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, right, size = s.size(), count = 0;
        vector<int> abc('d', 0);

        for (right = 0; right < size; ++right) {
            ++abc[s[right]];

            while (abc['a'] > 0 && abc['b'] > 0 && abc['c'] > 0) {
                count += (size - right);
                --abc[s[left++]];
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(10, o.numberOfSubstrings("abcabc"));
    check.checkInt(3, o.numberOfSubstrings("aaacb"));
    check.checkInt(1, o.numberOfSubstrings("abc"));
    check.checkInt(0, o.numberOfSubstrings("aaa"));
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
