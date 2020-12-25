/* 定长子串中元音的最大数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你字符串 s 和整数 k 。

请返回字符串 s 中长度为 k 的单个子字符串中可能包含的最大元音字母数。

英文中的 元音字母 为（a, e, i, o, u）。

 

示例 1：

输入：s = "abciiidef", k = 3
输出：3
解释：子字符串 "iii" 包含 3 个元音字母。
示例 2：

输入：s = "aeiou", k = 2
输出：2
解释：任意长度为 2 的子字符串都包含 2 个元音字母。
示例 3：

输入：s = "leetcode", k = 3
输出：2
解释："lee"、"eet" 和 "ode" 都包含 2 个元音字母。
示例 4：

输入：s = "rhythms", k = 4
输出：0
解释：字符串 s 中不含任何元音字母。
示例 5：

输入：s = "tryhard", k = 4
输出：1
 

提示：

1 <= s.length <= 10^5
s 由小写英文字母组成
1 <= k <= s.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        vector<int> vowels('z' + 1, 0);
        vowels['a'] = vowels['e'] = vowels['i'] = vowels['o'] = vowels['u'] = 1;

        int i, size = s.size(), count = 0;
        for (i = 0; i < k; ++i) {
            if (vowels[s[i]] == 1) {
                ++count;
            }
        }

        int j = 0, maxLen = count;
        for (; i < size; ++i, ++j) {
            if (vowels[s[i]]) {
                ++count;
            }

            if (vowels[s[j]]) {
                --count;
            }

            maxLen = max(maxLen, count);
        }

        return maxLen;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.maxVowels("abciiidef", 3));
    check.checkInt(2, o.maxVowels("aeiou", 2));
    check.checkInt(2, o.maxVowels("leetcode", 3));
    check.checkInt(0, o.maxVowels("rhythms", 4));
    check.checkInt(0, o.maxVowels("rhythms", 7));
    check.checkInt(1, o.maxVowels("tryhard", 4));
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
