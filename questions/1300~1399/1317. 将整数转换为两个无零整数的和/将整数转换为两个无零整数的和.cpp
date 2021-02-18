/* 将整数转换为两个无零整数的和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
「无零整数」是十进制表示中 不含任何 0 的正整数。

给你一个整数 n，请你返回一个 由两个整数组成的列表 [A, B]，满足：

A 和 B 都是无零整数
A + B = n
题目数据保证至少有一个有效的解决方案。

如果存在多个有效解决方案，你可以返回其中任意一个。

 

示例 1：

输入：n = 2
输出：[1,1]
解释：A = 1, B = 1. A + B = n 并且 A 和 B 的十进制表示形式都不包含任何 0 。
示例 2：

输入：n = 11
输出：[2,9]
示例 3：

输入：n = 10000
输出：[1,9999]
示例 4：

输入：n = 69
输出：[1,68]
示例 5：

输入：n = 1010
输出：[11,999]
 

提示：

2 <= n <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <math.h>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int remainder;
        double a = 0, b = 0, round = 0;

        while (n != 0) {
            remainder = n % 10;
            n /= 10;

            if (remainder == 0) {
                n -= 1;
                a += 1 * pow(10, round);
                b += 9 * pow(10, round);
            }
            else if (remainder == 1) {
                if (n != 0) {
                    n -= 1;
                    a += 2 * pow(10, round);
                    b += 9 * pow(10, round);
                }
                else {
                    a += 1 * pow(10, round);
                }
            }
            else {
                a += 1 * pow(10, round);
                b += (remainder - 1) * pow(10, round);
            }

            round += 1;
        }

        return { (int)a, (int)b };
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> actual = o.getNoZeroIntegers(2);
    vector<int> expected = { 1,1 };
    check.checkIntVector(expected, actual);

    actual = o.getNoZeroIntegers(11);
    expected = { 2,9 };
    check.checkIntVector(expected, actual);
    
    actual = o.getNoZeroIntegers(111);
    expected = { 12,99 };
    check.checkIntVector(expected, actual);

    actual = o.getNoZeroIntegers(1111);
    expected = { 112,999 };
    check.checkIntVector(expected, actual);

    actual = o.getNoZeroIntegers(10000);
    expected = { 1111,8889 };
    check.checkIntVector(expected, actual);

    actual = o.getNoZeroIntegers(69);
    expected = { 11,58 };
    check.checkIntVector(expected, actual);

    actual = o.getNoZeroIntegers(1010);
    expected = { 111,899 };
    check.checkIntVector(expected, actual);
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
