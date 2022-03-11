/* 得到回文串的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个只包含小写英文字母的字符串 s 。

每一次 操作 ，你可以选择 s 中两个 相邻 的字符，并将它们交换。

请你返回将 s 变成回文串的 最少操作次数 。

注意 ，输入数据会确保 s 一定能变成一个回文串。

 

示例 1：

输入：s = "aabb"
输出：2
解释：
我们可以将 s 变成 2 个回文串，"abba" 和 "baab" 。
- 我们可以通过 2 次操作得到 "abba" ："aabb" -> "abab" -> "abba" 。
- 我们可以通过 2 次操作得到 "baab" ："aabb" -> "abab" -> "baab" 。
因此，得到回文串的最少总操作次数为 2 。
示例 2：

输入：s = "letelt"
输出：2
解释：
通过 2 次操作从 s 能得到回文串 "lettel" 。
其中一种方法是："letelt" -> "letetl" -> "lettel" 。
其他回文串比方说 "tleelt" 也可以通过 2 次操作得到。
可以证明少于 2 次操作，无法得到回文串。
 

提示：

1 <= s.length <= 2000
s 只包含小写英文字母。
s 可以通过有限次操作得到一个回文串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-moves-to-make-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        // 贪心，从左到右固定左侧字符，然后找到右侧对应字符并移动到回文位置
        int size = s.size(), half = size / 2, left, right = size - 1, odd = -1, i, moves = 0;

        for (left = 0; left < half; ++left) {
            for (i = right; i > left && s[i] != s[left]; --i) {}  // 找到右侧第一个对应的字符

            if (i == left) {
                odd = i;  // 单个的字符，最后移到中间
            }
            else {
                moves += (right - i);

                for (; i < right; ++i) {  // 将该字符移到回文位置
                    s[i] = s[i + 1];
                }

                --right;
            }
        }

        return moves + (odd == -1 ? 0 : (half - odd));  // 将单个字符移到中间
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.minMovesToMakePalindrome("aabb"));
    check.checkInt(2, o.minMovesToMakePalindrome("letelt"));
    check.checkInt(0, o.minMovesToMakePalindrome("z"));
    check.checkInt(9, o.minMovesToMakePalindrome("aabbccd"));
    check.checkInt(17, o.minMovesToMakePalindrome("eqvvhtcsaaqtqesvvqch"));
    check.checkInt(163, o.minMovesToMakePalindrome("skwhhaaunskegmdtutlgtteunmuuludii"));
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
