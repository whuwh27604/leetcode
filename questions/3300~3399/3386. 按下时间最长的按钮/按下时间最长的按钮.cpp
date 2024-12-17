/* 按下时间最长的按钮.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维数组 events，表示孩子在键盘上按下一系列按钮触发的按钮事件。

每个 events[i] = [indexi, timei] 表示在时间 timei 时，按下了下标为 indexi 的按钮。

数组按照 time 的递增顺序排序。
按下一个按钮所需的时间是连续两次按钮按下的时间差。按下第一个按钮所需的时间就是其时间戳。
返回按下时间 最长 的按钮的 index。如果有多个按钮的按下时间相同，则返回 index 最小的按钮。



示例 1：

输入： events = [[1,2],[2,5],[3,9],[1,15]]

输出： 1

解释：

下标为 1 的按钮在时间 2 被按下。
下标为 2 的按钮在时间 5 被按下，因此按下时间为 5 - 2 = 3。
下标为 3 的按钮在时间 9 被按下，因此按下时间为 9 - 5 = 4。
下标为 1 的按钮再次在时间 15 被按下，因此按下时间为 15 - 9 = 6。
最终，下标为 1 的按钮按下时间最长，为 6。

示例 2：

输入： events = [[10,5],[1,7]]

输出： 10

解释：

下标为 10 的按钮在时间 5 被按下。
下标为 1 的按钮在时间 7 被按下，因此按下时间为 7 - 5 = 2。
最终，下标为 10 的按钮按下时间最长，为 5。



提示：

1 <= events.length <= 1000
events[i] == [indexi, timei]
1 <= indexi, timei <= 105
输入保证数组 events 按照 timei 的递增顺序排序。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int maxTime = events[0][1], index = events[0][0];

        for (int i = 1; i < (int)events.size(); ++i) {
            int time = events[i][1] - events[i - 1][1];

            if (time > maxTime) {
                maxTime = time;
                index = events[i][0];
            }
            else if (time == maxTime) {
                index = min(index, events[i][0]);
            }
        }

        return index;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> events = { {1,2},{2,5},{3,9},{1,15} };
    check.checkInt(1, o.buttonWithLongestTime(events));

    events = { {10,5},{1,7} };
    check.checkInt(10, o.buttonWithLongestTime(events));
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
