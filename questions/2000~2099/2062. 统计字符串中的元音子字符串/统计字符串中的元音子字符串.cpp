/* 统计字符串中的元音子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
子字符串 是字符串中的一个连续（非空）的字符序列。

元音子字符串 是 仅 由元音（'a'、'e'、'i'、'o' 和 'u'）组成的一个子字符串，且必须包含 全部五种 元音。

给你一个字符串 word ，统计并返回 word 中 元音子字符串的数目 。

 

示例 1：

输入：word = "aeiouu"
输出：2
解释：下面列出 word 中的元音子字符串（斜体加粗部分）：
- "aeiouu"
- "aeiouu"
示例 2：

输入：word = "unicornarihan"
输出：0
解释：word 中不含 5 种元音，所以也不会存在元音子字符串。
示例 3：

输入：word = "cuaieuouac"
输出：7
解释：下面列出 word 中的元音子字符串（斜体加粗部分）：
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
示例 4：

输入：word = "bbaeixoubb"
输出：0
解释：所有包含全部五种元音的子字符串都含有辅音，所以不存在元音子字符串。
 

提示：

1 <= word.length <= 100
word 仅由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-vowel-substrings-of-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countVowelSubstrings(string word) {
        int size = word.size(), start = 0, left = 0, right, vowelSubstrings = 0;
        vector<int> count('z' + 1, 0);

        for (right = 0; right < size; ++right) {
            char c = word[right];

            if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
                count['a'] = count['e'] = count['i'] = count['o'] = count['u'] = 0;
                start = left = right + 1;
                continue;
            }

            ++count[c];

            while (count['a'] > 0 && count['e'] > 0 && count['i'] > 0 && count['o'] > 0 && count['u'] > 0) {
                --count[word[left++]];
            }

            vowelSubstrings += (left - start);
        }

        return vowelSubstrings;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.countVowelSubstrings("aeiouu"));
    check.checkInt(0, o.countVowelSubstrings("unicornarihan"));
    check.checkInt(7, o.countVowelSubstrings("cuaieuouac"));
    check.checkInt(0, o.countVowelSubstrings("bbaeixoubb"));
    check.checkInt(0, o.countVowelSubstrings("a"));
    check.checkInt(0, o.countVowelSubstrings("z"));
    check.checkInt(1, o.countVowelSubstrings("aeiou"));
    check.checkInt(2228, o.countVowelSubstrings("aeiouoieaaeiouoieaaeiouoieaaeiouoieaaeiouoieaaeiouoieaaeiouoieaaeiouoiea"));
    check.checkInt(242, o.countVowelSubstrings("zzzaeiouoieaaeziouoieaaeiouoieaaezouoieaaeiouoieaaeiouozieaaeiouoizeaaeziouoieazzz"));
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
