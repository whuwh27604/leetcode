/* 字符串的好分割数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 s ，一个分割被称为 「好分割」 当它满足：将 s 分割成 2 个字符串 p 和 q ，它们连接起来等于 s 且 p 和 q 中不同字符的数目相同。

请你返回 s 中好分割的数目。

 

示例 1：

输入：s = "aacaba"
输出：2
解释：总共有 5 种分割字符串 "aacaba" 的方法，其中 2 种是好分割。
("a", "acaba") 左边字符串和右边字符串分别包含 1 个和 3 个不同的字符。
("aa", "caba") 左边字符串和右边字符串分别包含 1 个和 3 个不同的字符。
("aac", "aba") 左边字符串和右边字符串分别包含 2 个和 2 个不同的字符。这是一个好分割。
("aaca", "ba") 左边字符串和右边字符串分别包含 2 个和 2 个不同的字符。这是一个好分割。
("aacab", "a") 左边字符串和右边字符串分别包含 3 个和 1 个不同的字符。
示例 2：

输入：s = "abcd"
输出：1
解释：好分割为将字符串分割成 ("ab", "cd") 。
示例 3：

输入：s = "aaaaa"
输出：4
解释：所有分割都是好分割。
示例 4：

输入：s = "acbadbaada"
输出：2
 

提示：

s 只包含小写英文字母。
1 <= s.length <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-good-ways-to-split-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numSplits(string s) {
        vector<int> lettersCount('z' + 1, 0), firstHalfCount('z' + 1, 0);
        int goodSplits = 0, distinct1stHalf = 0, distinct2ndHalf = countLetters(s, lettersCount);

        for (char c : s) {
            if (++firstHalfCount[c] == 1) {
                ++distinct1stHalf;
            }

            if (--lettersCount[c] == 0) {
                --distinct2ndHalf;
            }

            if (distinct1stHalf == distinct2ndHalf) {
                ++goodSplits;
            }
        }

        return goodSplits;
    }

    int countLetters(string& s, vector<int>& lettersCount) {
        int distinctLetters = 0;

        for (char c : s) {
            if (++lettersCount[c] == 1) {
                ++distinctLetters;
            }
        }

        return distinctLetters;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.numSplits("aacaba"));
    check.checkInt(1, o.numSplits("abcd"));
    check.checkInt(4, o.numSplits("aaaaa"));
    check.checkInt(2, o.numSplits("acbadbaada"));
    check.checkInt(0, o.numSplits("z"));
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
