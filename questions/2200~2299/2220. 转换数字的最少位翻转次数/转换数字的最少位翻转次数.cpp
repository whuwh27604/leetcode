/* 转换数字的最少位翻转次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一次 位翻转 定义为将数字 x 二进制中的一个位进行 翻转 操作，即将 0 变成 1 ，或者将 1 变成 0 。

比方说，x = 7 ，二进制表示为 111 ，我们可以选择任意一个位（包含没有显示的前导 0 ）并进行翻转。比方说我们可以翻转最右边一位得到 110 ，或者翻转右边起第二位得到 101 ，或者翻转右边起第五位（这一位是前导 0 ）得到 10111 等等。
给你两个整数 start 和 goal ，请你返回将 start 转变成 goal 的 最少位翻转 次数。

 

示例 1：

输入：start = 10, goal = 7
输出：3
解释：10 和 7 的二进制表示分别为 1010 和 0111 。我们可以通过 3 步将 10 转变成 7 ：
- 翻转右边起第一位得到：1010 -> 1011 。
- 翻转右边起第三位：1011 -> 1111 。
- 翻转右边起第四位：1111 -> 0111 。
我们无法在 3 步内将 10 转变成 7 。所以我们返回 3 。
示例 2：

输入：start = 3, goal = 4
输出：3
解释：3 和 4 的二进制表示分别为 011 和 100 。我们可以通过 3 步将 3 转变成 4 ：
- 翻转右边起第一位：011 -> 010 。
- 翻转右边起第二位：010 -> 000 。
- 翻转右边起第三位：000 -> 100 。
我们无法在 3 步内将 3 变成 4 。所以我们返回 3 。
 

提示：

0 <= start, goal <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-bit-flips-to-convert-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start ^ goal);
    }

    int __builtin_popcount(int num) {
        int count = 0;

        while (num != 0) {
            count += ((num & 1) == 1 ? 1 : 0);
            num >>= 1;
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.minBitFlips(10, 7));
    check.checkInt(3, o.minBitFlips(3, 4));
    check.checkInt(0, o.minBitFlips(0, 0));
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
