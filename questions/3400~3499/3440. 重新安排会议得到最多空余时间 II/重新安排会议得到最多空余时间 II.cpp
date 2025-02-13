/* 重新安排会议得到最多空余时间 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 eventTime 表示一个活动的总时长，这个活动开始于 t = 0 ，结束于 t = eventTime 。

同时给你两个长度为 n 的整数数组 startTime 和 endTime 。它们表示这次活动中 n 个时间 没有重叠 的会议，其中第 i 个会议的时间为 [startTime[i], endTime[i]] 。

你可以重新安排 至多 一个会议，安排的规则是将会议时间平移，且保持原来的 会议时长 ，你的目的是移动会议后 最大化 相邻两个会议之间的 最长 连续空余时间。

请你返回重新安排会议以后，可以得到的 最大 空余时间。

注意，会议 不能 安排到整个活动的时间以外，且会议之间需要保持互不重叠。

注意：重新安排会议以后，会议之间的顺序可以发生改变。



示例 1：

输入：eventTime = 5, startTime = [1,3], endTime = [2,5]

输出：2

解释：



将 [1, 2] 的会议安排到 [2, 3] ，得到空余时间 [0, 2] 。

示例 2：

输入：eventTime = 10, startTime = [0,7,9], endTime = [1,8,10]

输出：7

解释：



将 [0, 1] 的会议安排到 [8, 9] ，得到空余时间 [0, 7] 。

示例 3：

输入：eventTime = 10, startTime = [0,3,7,9], endTime = [1,4,8,10]

输出：6

解释：



将 [3, 4] 的会议安排到 [8, 9] ，得到空余时间 [1, 7] 。

示例 4：

输入：eventTime = 5, startTime = [0,1,2,3,4], endTime = [1,2,3,4,5]

输出：0

解释：

活动中的所有时间都被会议安排满了。



提示：

1 <= eventTime <= 109
n == startTime.length == endTime.length
2 <= n <= 105
0 <= startTime[i] < endTime[i] <= eventTime
endTime[i] <= startTime[i + 1] 其中 i 在范围 [0, n - 2] 之间。
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = (int)endTime.size(), maxTime = 0;
        map<int, int, greater<int>> intervals;
        ++intervals[startTime[0]];
        ++intervals[eventTime - endTime[n - 1]];

        for (int i = 1; i < n; ++i) {
            ++intervals[startTime[i] - endTime[i - 1]];
        }

        for (int i = 0; i < n; ++i) {
            int time = endTime[i] - startTime[i];
            int i1 = (i == 0 ? startTime[i] : startTime[i] - endTime[i - 1]);
            int i2 = (i == n - 1 ? eventTime - endTime[i] : startTime[i + 1] - endTime[i]);

            if (--intervals[i1] == 0) {
                intervals.erase(i1);
            }
            if (--intervals[i2] == 0) {
                intervals.erase(i2);
            }

            if (intervals.begin()->first >= time) {  // 当前会议可以移动到其它地方去
                maxTime = max(maxTime, time + i1 + i2);
            }
            else {  // 只能在本地平移
                maxTime = max(maxTime, i1 + i2);
            }

            ++intervals[i1], ++intervals[i2];
        }

        return maxTime;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> startTime = { 1,3 };
    vector<int> endTime = { 2,5 };
    check.checkInt(2, o.maxFreeTime(5, startTime, endTime));

    startTime = { 0,7,9 };
    endTime = { 1,8,10 };
    check.checkInt(7, o.maxFreeTime(10, startTime, endTime));

    startTime = { 0,3,7,9 };
    endTime = { 1,4,8,10 };
    check.checkInt(6, o.maxFreeTime(10, startTime, endTime));
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
