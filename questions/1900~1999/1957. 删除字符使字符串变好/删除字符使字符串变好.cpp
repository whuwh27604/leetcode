/* 删除字符使字符串变好.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个字符串如果没有 三个连续 相同字符，那么它就是一个 好字符串 。

给你一个字符串 s ，请你从 s 删除 最少 的字符，使它变成一个 好字符串 。

请你返回删除后的字符串。题目数据保证答案总是 唯一的 。

 

示例 1：

输入：s = "leeetcode"
输出："leetcode"
解释：
从第一组 'e' 里面删除一个 'e' ，得到 "leetcode" 。
没有连续三个相同字符，所以返回 "leetcode" 。
示例 2：

输入：s = "aaabaaaa"
输出："aabaa"
解释：
从第一组 'a' 里面删除一个 'a' ，得到 "aabaaaa" 。
从第二组 'a' 里面删除两个 'a' ，得到 "aabaa" 。
没有连续三个相同字符，所以返回 "aabaa" 。
示例 3：

输入：s = "aab"
输出："aab"
解释：没有连续三个相同字符，所以返回 "aab" 。
 

提示：

1 <= s.length <= 105
s 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-characters-to-make-fancy-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        int i, size = s.size();
        if (size < 3) {
            return s;
        }

        string ans(s, 0, 2);

        for (i = 2; i < size; ++i) {
            if (s[i] != s[i - 1] || s[i] != s[i - 2]) {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("leetcode", o.makeFancyString("leeetcode"));
    check.checkString("aabaa", o.makeFancyString("aaabaaaa"));
    check.checkString("aab", o.makeFancyString("aab"));
    check.checkString("a", o.makeFancyString("a"));
    check.checkString("ab", o.makeFancyString("ab"));
    check.checkString("zz", o.makeFancyString("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"));
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
