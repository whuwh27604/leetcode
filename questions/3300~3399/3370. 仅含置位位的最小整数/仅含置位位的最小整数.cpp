/* 仅含置位位的最小整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 n。

返回 大于等于 n 且二进制表示仅包含 置位 位的 最小 整数 x 。

置位 位指的是二进制表示中值为 1 的位。



示例 1：

输入： n = 5

输出： 7

解释：

7 的二进制表示是 "111"。

示例 2：

输入： n = 10

输出： 15

解释：

15 的二进制表示是 "1111"。

示例 3：

输入： n = 3

输出： 3

解释：

3 的二进制表示是 "11"。



提示：

1 <= n <= 1000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        int num = 1;

        while (num < n) {
            num = ((num << 1) | 1);
        }

        return num;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(7, o.smallestNumber(5));
    check.checkInt(15, o.smallestNumber(10));
    check.checkInt(3, o.smallestNumber(3));
    check.checkInt(1, o.smallestNumber(1));
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
