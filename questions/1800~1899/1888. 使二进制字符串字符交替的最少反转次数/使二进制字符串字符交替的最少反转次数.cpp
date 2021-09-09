/* 使二进制字符串字符交替的最少反转次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二进制字符串 s 。你可以按任意顺序执行以下两种操作任意次：

类型 1 ：删除 字符串 s 的第一个字符并将它 添加 到字符串结尾。
类型 2 ：选择 字符串 s 中任意一个字符并将该字符 反转 ，也就是如果值为 '0' ，则反转得到 '1' ，反之亦然。
请你返回使 s 变成 交替 字符串的前提下， 类型 2 的 最少 操作次数 。

我们称一个字符串是 交替 的，需要满足任意相邻字符都不同。

比方说，字符串 "010" 和 "1010" 都是交替的，但是字符串 "0100" 不是。
 

示例 1：

输入：s = "111000"
输出：2
解释：执行第一种操作两次，得到 s = "100011" 。
然后对第三个和第六个字符执行第二种操作，得到 s = "101010" 。
示例 2：

输入：s = "010"
输出：0
解释：字符串已经是交替的。
示例 3：

输入：s = "1110"
输出：1
解释：对第二个字符执行第二种操作，得到 s = "1010" 。
 

提示：

1 <= s.length <= 105
s[i] 要么是 '0' ，要么是 '1' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minFlips(string s) {
        /* 将s拼接一次，以原长度的窗口遍历所有可能轮转出来的字符串，统计将它变为1010...模式需要改变的次数，取最小值。
           也可能是变为0101...模式，那么改变的次数是原长度减去变为1010...模式的次数。 */
        int flips = 0;
        char frontWanted = '1', backWanted = '1';

        for (char c : s) {
            if (c != backWanted) {
                ++flips;
            }

            backWanted = (backWanted == '0' ? '1' : '0');
        }

        int minimumFlips = flips, maximumFlips = flips;

        for (char c : s) {
            if (c != frontWanted) {
                --flips;
            }

            if (c != backWanted) {
                ++flips;
            }

            frontWanted = (frontWanted == '0' ? '1' : '0');
            backWanted = (backWanted == '0' ? '1' : '0');
            minimumFlips = min(minimumFlips, flips);
            maximumFlips = max(maximumFlips, flips);
        }

        return min(minimumFlips, (int)s.size() - maximumFlips);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(2, o.minFlips("111000"));
    check.checkInt(0, o.minFlips("010"));
    check.checkInt(1, o.minFlips("1110"));
    check.checkInt(30, o.minFlips("111111111111111000000000000000000000000010010011001010110101001110010101001"));
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
