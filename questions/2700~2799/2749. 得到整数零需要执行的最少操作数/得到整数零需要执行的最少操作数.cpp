/* 得到整数零需要执行的最少操作数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数：num1 和 num2 。

在一步操作中，你需要从范围 [0, 60] 中选出一个整数 i ，并从 num1 减去 2i + num2 。

请你计算，要想使 num1 等于 0 需要执行的最少操作数，并以整数形式返回。

如果无法使 num1 等于 0 ，返回 -1 。



示例 1：

输入：num1 = 3, num2 = -2
输出：3
解释：可以执行下述步骤使 3 等于 0 ：
- 选择 i = 2 ，并从 3 减去 22 + (-2) ，num1 = 3 - (4 + (-2)) = 1 。
- 选择 i = 2 ，并从 1 减去 22 + (-2) ，num1 = 1 - (4 + (-2)) = -1 。
- 选择 i = 0 ，并从 -1 减去 20 + (-2) ，num1 = (-1) - (1 + (-2)) = 0 。
可以证明 3 是需要执行的最少操作数。
示例 2：

输入：num1 = 5, num2 = 7
输出：-1
解释：可以证明，执行操作无法使 5 等于 0 。


提示：

1 <= num1 <= 109
-109 <= num2 <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int opers = 0;
        long long num = num1;

        while (num >= num2) {
            ++opers;
            num -= num2;

            if (popcount(num) <= opers && num >= opers) {  // num可以表示为opers个2的幂之和，需要满足两个条件：1、num肯定要大于等于opers；2、num中1的个数要小于等于opers。
                return opers;
            }
        }

        return -1;
    }

    int popcount(long long x) {
        int count = 0;

        while (x != 0) {
            count += (x & 1);
            x >>= 1;
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.makeTheIntegerZero(3, -2));
    check.checkInt(-1, o.makeTheIntegerZero(5, 7));
    check.checkInt(-1, o.makeTheIntegerZero(85, 42));
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
