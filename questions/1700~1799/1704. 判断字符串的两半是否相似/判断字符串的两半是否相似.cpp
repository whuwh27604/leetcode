/* 判断字符串的两半是否相似.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个偶数长度的字符串 s 。将其拆分成长度相同的两半，前一半为 a ，后一半为 b 。

两个字符串 相似 的前提是它们都含有相同数目的元音（'a'，'e'，'i'，'o'，'u'，'A'，'E'，'I'，'O'，'U'）。注意，s 可能同时含有大写和小写字母。

如果 a 和 b 相似，返回 true ；否则，返回 false 。

 

示例 1：

输入：s = "book"
输出：true
解释：a = "bo" 且 b = "ok" 。a 中有 1 个元音，b 也有 1 个元音。所以，a 和 b 相似。
示例 2：

输入：s = "textbook"
输出：false
解释：a = "text" 且 b = "book" 。a 中有 1 个元音，b 中有 2 个元音。因此，a 和 b 不相似。
注意，元音 o 在 b 中出现两次，记为 2 个。
示例 3：

输入：s = "MerryChristmas"
输出：false
示例 4：

输入：s = "AbCdEfGh"
输出：true
 

提示：

2 <= s.length <= 1000
s.length 是偶数
s 由 大写和小写 字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/determine-if-string-halves-are-alike
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int i, size = s.size(), firstHalf = 0, secondHalf = 0;
        unordered_set<char> vowels = { 'a','e','i','o','u','A','E','I','O','U' };

        for (i = 0; i < size / 2; ++i) {
            if (vowels.count(s[i]) != 0) {
                ++firstHalf;
            }
        }

        for (; i < size; ++i) {
            if (vowels.count(s[i]) != 0) {
                ++secondHalf;
            }
        }

        return firstHalf == secondHalf;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.halvesAreAlike("book"));
    check.checkBool(false, o.halvesAreAlike("textbook"));
    check.checkBool(false, o.halvesAreAlike("MerryChristmas"));
    check.checkBool(true, o.halvesAreAlike("AbCdEfGh"));
    check.checkBool(true, o.halvesAreAlike("bb"));
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
