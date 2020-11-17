/* 阶乘后的零.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数 n，返回 n! 结果尾数中零的数量。

示例 1:

输入: 3
输出: 0
解释: 3! = 6, 尾数中没有零。
示例 2:

输入: 5
输出: 1
解释: 5! = 120, 尾数中有 1 个零.
说明: 你算法的时间复杂度应为 O(log n) 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/factorial-trailing-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

class Solution {
public:
    int trailingZeroes(int n) {
        // 就是统计5的倍数出现的个数，注意25的倍数算2次，125的倍数算3次...为避免溢出转换为除法
        int count = 0;
        int divisor = 5;
        while (n >= divisor) {
            count += (n / divisor);
            n /= divisor;
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.trailingZeroes(3));
    check.checkInt(1, o.trailingZeroes(5));
    check.checkInt(1, o.trailingZeroes(9));
    check.checkInt(2, o.trailingZeroes(10));
    check.checkInt(6, o.trailingZeroes(25));
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
