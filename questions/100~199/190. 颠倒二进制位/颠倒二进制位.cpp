/* 颠倒二进制位.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
颠倒给定的 32 位无符号整数的二进制位。

 

示例 1：

输入: 00000010100101000001111010011100
输出: 00111001011110000010100101000000
解释: 输入的二进制串 00000010100101000001111010011100 表示无符号整数 43261596，
      因此返回 964176192，其二进制表示形式为 00111001011110000010100101000000。
示例 2：

输入：11111111111111111111111111111101
输出：10111111111111111111111111111111
解释：输入的二进制串 11111111111111111111111111111101 表示无符号整数 4294967293，
      因此返回 3221225471 其二进制表示形式为 10101111110010110010011101101001。
 

提示：

请注意，在某些语言（如 Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的还是无符号的，其内部的二进制表示形式都是相同的。
在 Java 中，编译器使用二进制补码记法来表示有符号整数。因此，在上面的 示例 2 中，输入表示有符号整数 -3，输出表示有符号整数 -1073741825。
 

进阶:
如果多次调用这个函数，你将如何优化你的算法？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-bits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {                          // n = abcdefghijklmnopqrstuvwxyz123456
        n = (n >> 16) | (n << 16);                              // n = qrstuvwxyz123456abcdefghijklmnop
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);  // n = yz123456qrstuvwxijklmnopabcdefgh
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);  // n = 3456yz12uvwxqrstmnopijklefghabcd
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);  // n = 563412yzwxuvstqropmnklijghefcdab
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);  // n = 654321zyxwvutsrqponmlkjihgfedcba
        return n;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkUint(964176192, o.reverseBits(43261596));
    check.checkUint(43261596, o.reverseBits(964176192));
    check.checkUint(3221225471, o.reverseBits(4294967293));
    check.checkUint(4294967293, o.reverseBits(3221225471));
    check.checkUint(0, o.reverseBits(0));
    check.checkUint(0xffffffff, o.reverseBits(0xffffffff));
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
