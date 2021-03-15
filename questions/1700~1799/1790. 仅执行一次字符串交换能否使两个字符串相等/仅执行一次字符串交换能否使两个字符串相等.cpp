/* 仅执行一次字符串交换能否使两个字符串相等.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你长度相等的两个字符串 s1 和 s2 。一次 字符串交换 操作的步骤如下：选出某个字符串中的两个下标（不必不同），并交换这两个下标所对应的字符。

如果对 其中一个字符串 执行 最多一次字符串交换 就可以使两个字符串相等，返回 true ；否则，返回 false 。

 

示例 1：

输入：s1 = "bank", s2 = "kanb"
输出：true
解释：例如，交换 s2 中的第一个和最后一个字符可以得到 "bank"
示例 2：

输入：s1 = "attack", s2 = "defend"
输出：false
解释：一次字符串交换无法使两个字符串相等
示例 3：

输入：s1 = "kelb", s2 = "kelb"
输出：true
解释：两个字符串已经相等，所以不需要进行字符串交换
示例 4：

输入：s1 = "abcd", s2 = "dcba"
输出：false
 

提示：

1 <= s1.length, s2.length <= 100
s1.length == s2.length
s1 和 s2 仅由小写英文字母组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-one-string-swap-can-make-strings-equal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int i, size = s1.size(), diff = 0;
        char diff1, diff2;

        for (i = 0; i < size; ++i) {
            if (s1[i] == s2[i]) {
                continue;
            }

            if (++diff > 2) {
                return false;
            }

            if (diff == 1) {
                diff1 = s1[i];
                diff2 = s2[i];
            }
            else {
                if (s1[i] != diff2 || s2[i] != diff1) {
                    return false;
                }
            }
        }

        return diff != 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkBool(true, o.areAlmostEqual("bank", "kanb"));
    check.checkBool(false, o.areAlmostEqual("attack", "defend"));
    check.checkBool(true, o.areAlmostEqual("kelb", "kelb"));
    check.checkBool(false, o.areAlmostEqual("abcd", "dcba"));
    check.checkBool(false, o.areAlmostEqual("abc", "abd"));
    check.checkBool(true, o.areAlmostEqual("z", "z"));
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
