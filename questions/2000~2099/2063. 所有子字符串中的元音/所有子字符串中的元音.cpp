/* 所有子字符串中的元音.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 word ，返回 word 的所有子字符串中 元音的总数 ，元音是指 'a'、'e'、'i'、'o' 和 'u' 。

子字符串 是字符串中一个连续（非空）的字符序列。

注意：由于对 word 长度的限制比较宽松，答案可能超过有符号 32 位整数的范围。计算时需当心。

 

示例 1：

输入：word = "aba"
输出：6
解释：
所有子字符串是："a"、"ab"、"aba"、"b"、"ba" 和 "a" 。
- "b" 中有 0 个元音
- "a"、"ab"、"ba" 和 "a" 每个都有 1 个元音
- "aba" 中有 2 个元音
因此，元音总数 = 0 + 1 + 1 + 1 + 1 + 2 = 6 。
示例 2：

输入：word = "abc"
输出：3
解释：
所有子字符串是："a"、"ab"、"abc"、"b"、"bc" 和 "c" 。
- "a"、"ab" 和 "abc" 每个都有 1 个元音
- "b"、"bc" 和 "c" 每个都有 0 个元音
因此，元音总数 = 1 + 1 + 1 + 0 + 0 + 0 = 3 。
示例 3：

输入：word = "ltcd"
输出：0
解释："ltcd" 的子字符串均不含元音。
示例 4：

输入：word = "noosabasboosa"
输出：237
解释：所有子字符串中共有 237 个元音。
 

提示：

1 <= word.length <= 105
word 由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/vowels-of-all-substrings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long countVowels(string word) {
        long long substrings = 0, vowels = 0, total = 0;

        for (char c : word) {
            substrings += 1;

            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels += substrings;
            }

            total += vowels;
        }

        return total;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkLongLong(6, o.countVowels("aba"));
    check.checkLongLong(3, o.countVowels("abc"));
    check.checkLongLong(0, o.countVowels("ltcd"));
    check.checkLongLong(1, o.countVowels("a"));
    check.checkLongLong(0, o.countVowels("z"));
    check.checkLongLong(237, o.countVowels("noosabasboosa"));
    check.checkLongLong(280840, o.countVowels("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"));
    check.checkLongLong(16710, o.countVowels("weurpquytoyralkfhahflkxvfaskadweruwqiopafjldfjazxvnzxvnzkljazvnnxnvznznnvzzvcv"));
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
