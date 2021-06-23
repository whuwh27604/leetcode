/* 长度为三且各字符不同的子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果一个字符串不含有任何重复字符，我们称这个字符串为 好 字符串。

给你一个字符串 s ，请你返回 s 中长度为 3 的 好子字符串 的数量。

注意，如果相同的好子字符串出现多次，每一次都应该被记入答案之中。

子字符串 是一个字符串中连续的字符序列。

 

示例 1：

输入：s = "xyzzaz"
输出：1
解释：总共有 4 个长度为 3 的子字符串："xyz"，"yzz"，"zza" 和 "zaz" 。
唯一的长度为 3 的好子字符串是 "xyz" 。
示例 2：

输入：s = "aababcabc"
输出：4
解释：总共有 7 个长度为 3 的子字符串："aab"，"aba"，"bab"，"abc"，"bca"，"cab" 和 "abc" 。
好子字符串包括 "abc"，"bca"，"cab" 和 "abc" 。
 

提示：

1 <= s.length <= 100
s​​​​​​ 只包含小写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/substrings-of-size-three-with-distinct-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        int i, size = s.size(), count = 0;

        for (i = 2; i < size; ++i) {
            if (s[i] != s[i - 1] && s[i] != s[i - 2] && s[i - 1] != s[i - 2]) {
                ++count;
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.countGoodSubstrings("xyzzaz"));
    check.checkInt(4, o.countGoodSubstrings("aababcabc"));
    check.checkInt(0, o.countGoodSubstrings("z"));
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
