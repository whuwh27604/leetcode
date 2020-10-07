/* 最小时间差.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个 24 小时制（小时:分钟）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。


示例 1：

输入: ["23:59","00:00"]
输出: 1

备注:

列表中时间数在 2~20000 之间。
每个时间取值在 00:00~23:59 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-time-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        const int size = 24 * 60;
        char times[size] = { 0 };
        for (string time : timePoints) {
            int minute = time2Minute(time);
            if (times[minute] == 1) {
                return 0;
            }
            times[minute] = 1;
        }

        int i, first, prev, minInterval = INT_MAX;
        for (i = 0; i < size; i++) {
            if (times[i] == 1) {
                first = i;
                prev = i;
                break;
            }
        }

        for (i = i + 1; i < size; i++) {
            if (times[i] != 0) {
                int interval = i - prev;
                minInterval = min(minInterval, interval);
                prev = i;
            }
        }

        return min(minInterval, size - prev + first);
    }

    int time2Minute(string& time) {
        int hour = (time[0] - '0') * 10 + time[1] - '0';
        int minute = (time[3] - '0') * 10 + time[4] - '0';
        return hour * 60 + minute;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> timePoints = { "23:59","00:00" };
    check.checkInt(1, o.findMinDifference(timePoints));

    timePoints = { "01:01","02:02" };
    check.checkInt(61, o.findMinDifference(timePoints));

    timePoints = { "01:01","02:02","23:59","00:01" };
    check.checkInt(2, o.findMinDifference(timePoints));

    timePoints = { "01:01","02:02","23:59","00:01","00:01" };
    check.checkInt(0, o.findMinDifference(timePoints));
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
