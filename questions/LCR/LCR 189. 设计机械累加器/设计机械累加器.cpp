/* 设计机械累加器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请设计一个机械累加器，计算从 1、2... 一直累加到目标数值 target 的总和。注意这是一个只能进行加法操作的程序，不具备乘除、if-else、switch-case、for 循环、while 循环，及条件判断语句等高级功能。



示例 1：

输入: target = 5
输出: 15
示例 2：

输入: target = 7
输出: 28


提示：

1 <= target <= 10000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int mechanicalAccumulator(int target) {
        return target * (target + 1) / 2;  // 题目太无聊了，不理它
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(15, o.mechanicalAccumulator(5));
    check.checkInt(28, o.mechanicalAccumulator(7));
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
