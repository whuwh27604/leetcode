/* 删除字符串两端相同字符后的最短长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个只包含字符 'a'，'b' 和 'c' 的字符串 s ，你可以执行下面这个操作（5 个步骤）任意次：

选择字符串 s 一个 非空 的前缀，这个前缀的所有字符都相同。
选择字符串 s 一个 非空 的后缀，这个后缀的所有字符都相同。
前缀和后缀在字符串中任意位置都不能有交集。
前缀和后缀包含的所有字符都要相同。
同时删除前缀和后缀。
请你返回对字符串 s 执行上面操作任意次以后（可能 0 次），能得到的 最短长度 。

 

示例 1：

输入：s = "ca"
输出：2
解释：你没法删除任何一个字符，所以字符串长度仍然保持不变。
示例 2：

输入：s = "cabaabac"
输出：0
解释：最优操作序列为：
- 选择前缀 "c" 和后缀 "c" 并删除它们，得到 s = "abaaba" 。
- 选择前缀 "a" 和后缀 "a" 并删除它们，得到 s = "baab" 。
- 选择前缀 "b" 和后缀 "b" 并删除它们，得到 s = "aa" 。
- 选择前缀 "a" 和后缀 "a" 并删除它们，得到 s = "" 。
示例 3：

输入：s = "aabccabba"
输出：3
解释：最优操作序列为：
- 选择前缀 "aa" 和后缀 "a" 并删除它们，得到 s = "bccabb" 。
- 选择前缀 "b" 和后缀 "bb" 并删除它们，得到 s = "cca" 。
 

提示：

1 <= s.length <= 105
s 只包含字符 'a'，'b' 和 'c' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-length-of-string-after-deleting-similar-ends
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right && s[left] == s[right]) {
            char target = s[left];

            while (left <= right && s[left] == target) {
                ++left;
            }

            while (right >= left && s[right] == target) {
                --right;
            }
        }

        return right - left + 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(1, o.minimumLength("a"));
    check.checkInt(0, o.minimumLength("aa"));
    check.checkInt(0, o.minimumLength("aaa"));
    check.checkInt(1, o.minimumLength("aba"));
    check.checkInt(2, o.minimumLength("ca"));
    check.checkInt(0, o.minimumLength("cabaabac"));
    check.checkInt(3, o.minimumLength("aabccabba"));
    check.checkInt(2, o.minimumLength("aabcabba"));
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
