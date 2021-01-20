/* 确定两个字符串是否接近.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果可以使用以下操作从一个字符串得到另一个字符串，则认为两个字符串 接近 ：

操作 1：交换任意两个 现有 字符。
例如，abcde -> aecdb
操作 2：将一个 现有 字符的每次出现转换为另一个 现有 字符，并对另一个字符执行相同的操作。
例如，aacabb -> bbcbaa（所有 a 转化为 b ，而所有的 b 转换为 a ）
你可以根据需要对任意一个字符串多次使用这两种操作。

给你两个字符串，word1 和 word2 。如果 word1 和 word2 接近 ，就返回 true ；否则，返回 false 。

 

示例 1：

输入：word1 = "abc", word2 = "bca"
输出：true
解释：2 次操作从 word1 获得 word2 。
执行操作 1："abc" -> "acb"
执行操作 1："acb" -> "bca"
示例 2：

输入：word1 = "a", word2 = "aa"
输出：false
解释：不管执行多少次操作，都无法从 word1 得到 word2 ，反之亦然。
示例 3：

输入：word1 = "cabbba", word2 = "abbccc"
输出：true
解释：3 次操作从 word1 获得 word2 。
执行操作 1："cabbba" -> "caabbb"
执行操作 2："caabbb" -> "baaccc"
执行操作 2："baaccc" -> "abbccc"
示例 4：

输入：word1 = "cabbba", word2 = "aabbss"
输出：false
解释：不管执行多少次操作，都无法从 word1 得到 word2 ，反之亦然。
 

提示：

1 <= word1.length, word2.length <= 105
word1 和 word2 仅包含小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/determine-if-two-strings-are-close
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> count1(26, 0), count2(26, 0);

        countLetters(word1, count1);
        countLetters(word2, count2);

        for (int i = 0; i < 26; ++i) {
            if ((count1[i] == 0 && count2[i] != 0) || (count1[i] != 0 && count2[i] == 0)) {  // 字符的种类必须相同
                return false;
            }
        }

        sort(count1.begin(), count1.end());
        sort(count2.begin(), count2.end());

        for (int i = 0; i < 26; ++i) {  // 字符出现的频率种类必须相同
            if (count1[i] != count2[i]) {
                return false;
            }
        }

        return true;
    }

    void countLetters(string& word, vector<int>& count) {
        for (char c : word) {
            ++count[c - 'a'];
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.closeStrings("abc", "bca"));
    check.checkBool(false, o.closeStrings("a", "aa"));
    check.checkBool(true, o.closeStrings("cabbba", "abbccc"));
    check.checkBool(false, o.closeStrings("cabbba", "aabbss"));
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
