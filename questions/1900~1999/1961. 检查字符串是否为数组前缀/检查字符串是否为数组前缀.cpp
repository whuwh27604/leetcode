/* 检查字符串是否为数组前缀.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个字符串数组 words ，请你判断 s 是否为 words 的 前缀字符串 。

字符串 s 要成为 words 的 前缀字符串 ，需要满足：s 可以由 words 中的前 k（k 为 正数 ）个字符串按顺序相连得到，且 k 不超过 words.length 。

如果 s 是 words 的 前缀字符串 ，返回 true ；否则，返回 false 。

 

示例 1：

输入：s = "iloveleetcode", words = ["i","love","leetcode","apples"]
输出：true
解释：
s 可以由 "i"、"love" 和 "leetcode" 相连得到。
示例 2：

输入：s = "iloveleetcode", words = ["apples","i","love","leetcode"]
输出：false
解释：
数组的前缀相连无法得到 s 。
 

提示：

1 <= words.length <= 100
1 <= words[i].length <= 20
1 <= s.length <= 1000
words[i] 和 s 仅由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-string-is-a-prefix-of-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        unsigned int i = 0, size = s.size();

        for (string& word : words) {
            for (unsigned int j = 0; j < word.size(); ++j) {
                if (word[j] != s[i]) {
                    return false;
                }

                if (++i == size) {
                    return j == word.size() - 1;
                }
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> words = { "i","love","leetcode","apples" };
    check.checkBool(true, o.isPrefixString("iloveleetcode", words));

    words = { "apples","i","love","leetcode" };
    check.checkBool(false, o.isPrefixString("iloveleetcode", words));

    words = { "c","cc" };
    check.checkBool(false, o.isPrefixString("cccccccccccc", words));

    words = { "z" };
    check.checkBool(true, o.isPrefixString("z", words));

    words = { "z" };
    check.checkBool(false, o.isPrefixString("c", words));

    words = { "aa","aaaa","banana" };
    check.checkBool(false, o.isPrefixString("a", words));
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
