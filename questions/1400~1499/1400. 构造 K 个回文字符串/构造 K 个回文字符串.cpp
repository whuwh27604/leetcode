/* 构造 K 个回文字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个整数 k 。请你用 s 字符串中 所有字符 构造 k 个非空 回文串 。

如果你可以用 s 中所有字符构造 k 个回文字符串，那么请你返回 True ，否则返回 False 。

 

示例 1：

输入：s = "annabelle", k = 2
输出：true
解释：可以用 s 中所有字符构造 2 个回文字符串。
一些可行的构造方案包括："anna" + "elble"，"anbna" + "elle"，"anellena" + "b"
示例 2：

输入：s = "leetcode", k = 3
输出：false
解释：无法用 s 中所有字符构造 3 个回文串。
示例 3：

输入：s = "true", k = 4
输出：true
解释：唯一可行的方案是让 s 中每个字符单独构成一个字符串。
示例 4：

输入：s = "yzyzyzyzyzyzyzy", k = 2
输出：true
解释：你只需要将所有的 z 放在一个字符串中，所有的 y 放在另一个字符串中。那么两个字符串都是回文串。
示例 5：

输入：s = "cr", k = 7
输出：false
解释：我们没有足够的字符去构造 7 个回文串。
 

提示：

1 <= s.length <= 10^5
s 中所有字符都是小写英文字母。
1 <= k <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-k-palindrome-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int> count(26, 0);
        int sum = 0;

        for (char c : s) {
            count[c - 'a'] ^= 1;  // 统计奇数个字母的个数，每一个奇数字母都必须单独构成一个回文串，也就是k的最小值
        }

        for (int num : count) {
            sum += num;
        }

        return k >= sum && k <= (int)s.size();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.canConstruct("annabelle", 2));
    check.checkBool(false, o.canConstruct("leetcode", 3));
    check.checkBool(true, o.canConstruct("true", 4));
    check.checkBool(true, o.canConstruct("yzyzyzyzyzyzyzy", 2));
    check.checkBool(false, o.canConstruct("cr", 7));
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
