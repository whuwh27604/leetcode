/* 检查一个字符串是否可以打破另一个字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个字符串 s1 和 s2 ，它们长度相等，请你检查是否存在一个 s1  的排列可以打破 s2 的一个排列，或者是否存在一个 s2 的排列可以打破 s1 的一个排列。

字符串 x 可以打破字符串 y （两者长度都为 n ）需满足对于所有 i（在 0 到 n - 1 之间）都有 x[i] >= y[i]（字典序意义下的顺序）。

 

示例 1：

输入：s1 = "abc", s2 = "xya"
输出：true
解释："ayx" 是 s2="xya" 的一个排列，"abc" 是字符串 s1="abc" 的一个排列，且 "ayx" 可以打破 "abc" 。
示例 2：

输入：s1 = "abe", s2 = "acd"
输出：false
解释：s1="abe" 的所有排列包括："abe"，"aeb"，"bae"，"bea"，"eab" 和 "eba" ，s2="acd" 的所有排列包括："acd"，"adc"，"cad"，"cda"，"dac" 和 "dca"。然而没有任何 s1 的排列可以打破 s2 的排列。也没有 s2 的排列能打破 s1 的排列。
示例 3：

输入：s1 = "leetcodee", s2 = "interview"
输出：true
 

提示：

s1.length == n
s2.length == n
1 <= n <= 10^5
所有字符串都只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-a-string-can-break-another-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> s1Count('z' + 1, 0), s2Count('z' + 1, 0);

        countLetters(s1, s1Count);
        countLetters(s2, s2Count);

        return canBreak(s1Count, s2Count) || canBreak(s2Count, s1Count);
    }

    void countLetters(string& s, vector<int>& lettersCount) {
        for (char c : s) {
            ++lettersCount[c];
        }
    }

    bool canBreak(vector<int>& s1Count, vector<int>& s2Count) {
        int i, j = 'a' - 1, left = 0;

        for (i = 'a'; i <= 'z'; ++i) {
            int count = s1Count[i];
            if (count == 0) {
                continue;
            }

            while (left < count) {
                if (++j > i) {
                    return false;
                }
                left += s2Count[j];
            }

            left -= count;
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.checkIfCanBreak("abc", "acd"));
    check.checkBool(true, o.checkIfCanBreak("abc", "xya"));
    check.checkBool(false, o.checkIfCanBreak("abe", "acd"));
    check.checkBool(true, o.checkIfCanBreak("leetcodee", "interview"));
    check.checkBool(true, o.checkIfCanBreak("interview", "interview"));
    check.checkBool(true, o.checkIfCanBreak("z", "z"));
    check.checkBool(false, o.checkIfCanBreak("ad", "bc"));
    check.checkBool(true, o.checkIfCanBreak("abbccc", "cccddd"));
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
