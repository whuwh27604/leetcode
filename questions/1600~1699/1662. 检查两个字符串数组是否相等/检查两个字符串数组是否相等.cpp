/* 检查两个字符串数组是否相等.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串数组 word1 和 word2 。如果两个数组表示的字符串相同，返回 true ；否则，返回 false 。

数组表示的字符串 是由数组中的所有元素 按顺序 连接形成的字符串。

 

示例 1：

输入：word1 = ["ab", "c"], word2 = ["a", "bc"]
输出：true
解释：
word1 表示的字符串为 "ab" + "c" -> "abc"
word2 表示的字符串为 "a" + "bc" -> "abc"
两个字符串相同，返回 true
示例 2：

输入：word1 = ["a", "cb"], word2 = ["ab", "c"]
输出：false
示例 3：

输入：word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
输出：true
 

提示：

1 <= word1.length, word2.length <= 103
1 <= word1[i].length, word2[i].length <= 103
1 <= sum(word1[i].length), sum(word2[i].length) <= 103
word1[i] 和 word2[i] 由小写字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-two-string-arrays-are-equivalent
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int r1 = 0, c1 = 0, r2 = 0, c2 = 0;

        while (true) {
            if (word1[r1][c1] != word2[r2][c2]) {
                return false;
            }

            if (++c1 == word1[r1].size()) {
                ++r1;
                c1 = 0;
            }

            if (++c2 == word2[r2].size()) {
                ++r2;
                c2 = 0;
            }

            if (r1 == word1.size()) {
                return r2 == word2.size();
            }

            if (r2 == word2.size()) {
                return false;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> word1 = { "ab", "c" };
    vector<string> word2 = { "a", "bc" };
    check.checkBool(true, o.arrayStringsAreEqual(word1, word2));

    word1 = { "a", "cb" };
    word2 = { "ab", "c" };
    check.checkBool(false, o.arrayStringsAreEqual(word1, word2));

    word1 = { "abc", "d", "defg" };
    word2 = { "abcddefg" };
    check.checkBool(true, o.arrayStringsAreEqual(word1, word2));

    word1 = { "abc", "d", "defg" };
    word2 = { "abcddefgh" };
    check.checkBool(false, o.arrayStringsAreEqual(word1, word2));

    word1 = { "abc", "d", "defgh" };
    word2 = { "abcddefg" };
    check.checkBool(false, o.arrayStringsAreEqual(word1, word2));

    word1 = { "a"};
    word2 = { "a" };
    check.checkBool(true, o.arrayStringsAreEqual(word1, word2));

    word1 = { "a" };
    word2 = { "b" };
    check.checkBool(false, o.arrayStringsAreEqual(word1, word2));
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
