/* 替换隐藏数字得到的最晚时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个字符串 time ，格式为 hh:mm（小时：分钟），其中某几位数字被隐藏（用 ? 表示）。

有效的时间为 00:00 到 23:59 之间的所有时间，包括 00:00 和 23:59 。

替换 time 中隐藏的数字，返回你可以得到的最晚有效时间。

 

示例 1：

输入：time = "2?:?0"
输出："23:50"
解释：以数字 '2' 开头的最晚一小时是 23 ，以 '0' 结尾的最晚一分钟是 50 。
示例 2：

输入：time = "0?:3?"
输出："09:39"
示例 3：

输入：time = "1?:22"
输出："19:22"
 

提示：

time 的格式为 hh:mm
题目数据保证你可以由输入的字符串生成有效的时间

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/latest-time-by-replacing-hidden-digits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string maximumTime(string time) {
        if (time[0] == '?') {
            if ((time[1] == '?') || (time[1] >= '0' && time[1] <= '3')) {
                time[0] = '2';
            }
            else {
                time[0] = '1';
            }
        }

        if (time[1] == '?') {
            if (time[0] == '2') {
                time[1] = '3';
            }
            else {
                time[1] = '9';
            }
        }

        if (time[3] == '?') {
            time[3] = '5';
        }

        if (time[4] == '?') {
            time[4] = '9';
        }

        return time;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkString("23:50", o.maximumTime("2?:?0"));
    check.checkString("09:39", o.maximumTime("0?:3?"));
    check.checkString("19:22", o.maximumTime("1?:22"));
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
