/* 倍数求和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 n ，请你计算在 [1，n] 范围内能被 3、5、7 整除的所有整数之和。

返回一个整数，用于表示给定范围内所有满足约束条件的数字之和。



示例 1：

输入：n = 7
输出：21
解释：在 [1, 7] 范围内能被 3、5、7 整除的所有整数分别是 3、5、6、7 。数字之和为 21 。
示例 2：

输入：n = 10
输出：40
解释：在 [1, 10] 范围内能被 3、5、7 整除的所有整数分别是 3、5、6、7、9、10 。数字之和为 40 。
示例 3：

输入：n = 9
输出：30
解释：在 [1, 9] 范围内能被 3、5、7 整除的所有整数分别是 3、5、6、7、9 。数字之和为 30 。


提示：

1 <= n <= 103
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int sumOfMultiples(int n) {
        return getSum(n, 3) + getSum(n, 5) + getSum(n, 7) - getSum(n, 15) - getSum(n, 21) - getSum(n, 35) + getSum(n, 105);
    }

    int getSum(int n, int x) {
        int a = n / x, b = a * x;

        return (x + b) * a / 2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(21, o.sumOfMultiples(7));
    check.checkInt(40, o.sumOfMultiples(10));
    check.checkInt(30, o.sumOfMultiples(9));
    check.checkInt(0, o.sumOfMultiples(1));
    check.checkInt(272066, o.sumOfMultiples(1000));
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
