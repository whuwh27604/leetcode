/* 排列硬币.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。

给定一个数字 n，找出可形成完整阶梯行的总行数。

n 是一个非负整数，并且在32位有符号整型的范围内。

示例 1:

n = 5

硬币可排列成以下几行:
¤
¤ ¤
¤ ¤

因为第三行不完整，所以返回2.
示例 2:

n = 8

硬币可排列成以下几行:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

因为第四行不完整，所以返回3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/arranging-coins
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        long long steps = n;
        steps = (long long)sqrt(steps * 2);
        if ((steps * (steps + 1) / 2) <= n) {
            return (int)steps;
        }
        return (int)(steps - 1);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.arrangeCoins(0));
    check.checkInt(1, o.arrangeCoins(1));
    check.checkInt(1, o.arrangeCoins(2));
    check.checkInt(2, o.arrangeCoins(3));
    check.checkInt(2, o.arrangeCoins(5));
    check.checkInt(3, o.arrangeCoins(6));
    check.checkInt(3, o.arrangeCoins(7));
    check.checkInt(3, o.arrangeCoins(9));
    check.checkInt(4, o.arrangeCoins(10));
    check.checkInt(4, o.arrangeCoins(11));
    check.checkInt(4, o.arrangeCoins(14));
    check.checkInt(5, o.arrangeCoins(15));
    check.checkInt(5, o.arrangeCoins(16));
    check.checkInt(9999, o.arrangeCoins(50004999));
    check.checkInt(10000, o.arrangeCoins(50005000));
    check.checkInt(10000, o.arrangeCoins(50005001));
    check.checkInt(65533, o.arrangeCoins(2147385344));
    check.checkInt(65534, o.arrangeCoins(2147385345));
    check.checkInt(65534, o.arrangeCoins(2147385346));
    check.checkInt(65535, o.arrangeCoins(INT_MAX));
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
