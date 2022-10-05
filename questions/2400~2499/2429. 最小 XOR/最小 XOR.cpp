/* 最小 XOR.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个正整数 num1 和 num2 ，找出满足下述条件的整数 x ：

x 的置位数和 num2 相同，且
x XOR num1 的值 最小
注意 XOR 是按位异或运算。

返回整数 x 。题目保证，对于生成的测试用例， x 是 唯一确定 的。

整数的 置位数 是其二进制表示中 1 的数目。

 

示例 1：

输入：num1 = 3, num2 = 5
输出：3
解释：
num1 和 num2 的二进制表示分别是 0011 和 0101 。
整数 3 的置位数与 num2 相同，且 3 XOR 3 = 0 是最小的。
示例 2：

输入：num1 = 1, num2 = 12
输出：3
解释：
num1 和 num2 的二进制表示分别是 0001 和 1100 。
整数 3 的置位数与 num2 相同，且 3 XOR 1 = 2 是最小的。
 

提示：

1 <= num1, num2 <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimize-xor
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x = 0, ones = getOnes(num2);

        for (int i = 30, bit = (1 << 30); i >= 0 && ones != 0; --i, bit >>= 1) {
            if ((num1 & bit) != 0) {
                x |= bit;
                --ones;
            }
        }

        for (int i = 0, bit = 1; i < 31 && ones != 0; ++i, bit <<= 1) {
            if ((num1 & bit) == 0) {
                x |= bit;
                --ones;
            }
        }

        return x;
    }

    int getOnes(int num) {
        int ones = 0;

        while (num != 0) {
            num &= (num - 1);
            ++ones;
        }

        return ones;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.minimizeXor(3, 5));
    check.checkInt(3, o.minimizeXor(1, 12));
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
