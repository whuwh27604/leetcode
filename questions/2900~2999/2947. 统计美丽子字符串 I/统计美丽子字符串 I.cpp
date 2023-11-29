/* 统计美丽子字符串 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s 和一个正整数 k 。

用 vowels 和 consonants 分别表示字符串中元音字母和辅音字母的数量。

如果某个字符串满足以下条件，则称其为 美丽字符串 ：

vowels == consonants，即元音字母和辅音字母的数量相等。
(vowels * consonants) % k == 0，即元音字母和辅音字母的数量的乘积能被 k 整除。
返回字符串 s 中 非空美丽子字符串 的数量。

子字符串是字符串中的一个连续字符序列。

英语中的 元音字母 为 'a'、'e'、'i'、'o' 和 'u' 。

英语中的 辅音字母 为除了元音字母之外的所有字母。



示例 1：

输入：s = "baeyh", k = 2
输出：2
解释：字符串 s 中有 2 个美丽子字符串。
- 子字符串 "baeyh"，vowels = 2（["a","e"]），consonants = 2（["y","h"]）。
可以看出字符串 "aeyh" 是美丽字符串，因为 vowels == consonants 且 vowels * consonants % k == 0 。
- 子字符串 "baeyh"，vowels = 2（["a","e"]），consonants = 2（["b","y"]）。
可以看出字符串 "baey" 是美丽字符串，因为 vowels == consonants 且 vowels * consonants % k == 0 。
可以证明字符串 s 中只有 2 个美丽子字符串。
示例 2：

输入：s = "abba", k = 1
输出：3
解释：字符串 s 中有 3 个美丽子字符串。
- 子字符串 "abba"，vowels = 1（["a"]），consonants = 1（["b"]）。
- 子字符串 "abba"，vowels = 1（["a"]），consonants = 1（["b"]）。
- 子字符串 "abba"，vowels = 2（["a","a"]），consonants = 2（["b","b"]）。
可以证明字符串 s 中只有 3 个美丽子字符串。
示例 3：

输入：s = "bcdf", k = 1
输出：0
解释：字符串 s 中没有美丽子字符串。


提示：

1 <= s.length <= 1000
1 <= k <= 1000
s 仅由小写英文字母组成。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int size = s.size(), beautifulStrings = 0;

        for (int i = 0; i < size - 1; ++i) {
            int vowels = 0, consonants = 0;

            for (int j = i; j < size; ++j) {
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
                    ++vowels;
                }
                else {
                    ++consonants;
                }

                if ((vowels == consonants) && (vowels * consonants % k == 0)) {
                    ++beautifulStrings;
                }
            }
        }

        return beautifulStrings;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.beautifulSubstrings("baeyh", 2));
    check.checkInt(3, o.beautifulSubstrings("abba", 1));
    check.checkInt(0, o.beautifulSubstrings("bcdf", 1));
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
