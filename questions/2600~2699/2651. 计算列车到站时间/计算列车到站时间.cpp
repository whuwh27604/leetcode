/* 计算列车到站时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 arrivalTime 表示列车正点到站的时间（单位：小时），另给你一个正整数 delayedTime 表示列车延误的小时数。

返回列车实际到站的时间。

注意，该问题中的时间采用 24 小时制。



示例 1：

输入：arrivalTime = 15, delayedTime = 5
输出：20
解释：列车正点到站时间是 15:00 ，延误 5 小时，所以列车实际到站的时间是 15 + 5 = 20（20:00）。
示例 2：

输入：arrivalTime = 13, delayedTime = 11
输出：0
解释：列车正点到站时间是 13:00 ，延误 11 小时，所以列车实际到站的时间是 13 + 11 = 24（在 24 小时制中表示为 00:00 ，所以返回 0）。


提示：

1 <= arrivaltime < 24
1 <= delayedTime <= 24
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(20, o.findDelayedArrivalTime(15, 5));
    check.checkInt(0, o.findDelayedArrivalTime(13, 11));
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
