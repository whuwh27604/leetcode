/* 时钟指针的夹角.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个数 hour 和 minutes 。请你返回在时钟上，由给定时间的时针和分针组成的较小角的角度（60 单位制）。

 

示例 1：



输入：hour = 12, minutes = 30
输出：165
示例 2：



输入：hour = 3, minutes = 30
输出；75
示例 3：



输入：hour = 3, minutes = 15
输出：7.5
示例 4：

输入：hour = 4, minutes = 50
输出：155
示例 5：

输入：hour = 12, minutes = 0
输出：0
 

提示：

1 <= hour <= 12
0 <= minutes <= 59
与标准答案误差在 10^-5 以内的结果都被视为正确结果。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/angle-between-hands-of-a-clock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double MinuteHandDegreesPerMinute = 6, HourhandDegreesPerMinute = 0.5;

        double angle = abs(MinuteHandDegreesPerMinute * minutes - HourhandDegreesPerMinute * ((double)hour * 60 + minutes));

        return min(angle, 360 - angle);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkDouble(165, o.angleClock(12, 30));
    check.checkDouble(75, o.angleClock(3, 30));
    check.checkDouble(7.5, o.angleClock(3, 15));
    check.checkDouble(155, o.angleClock(4, 50));
    check.checkDouble(0, o.angleClock(12, 0));
    check.checkDouble(30, o.angleClock(11, 0));
    check.checkDouble(112.5, o.angleClock(12, 45));
    check.checkDouble(5.5, o.angleClock(12, 1));
    check.checkDouble(35.5, o.angleClock(12, 59));
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
