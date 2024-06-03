/* 无需开会的工作日.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数 days，表示员工可工作的总天数（从第 1 天开始）。另给你一个二维数组 meetings，长度为 n，其中 meetings[i] = [start_i, end_i] 表示第 i 次会议的开始和结束天数（包含首尾）。

返回员工可工作且没有安排会议的天数。

注意：会议时间可能会有重叠。



示例 1：

输入：days = 10, meetings = [[5,7],[1,3],[9,10]]

输出：2

解释：

第 4 天和第 8 天没有安排会议。

示例 2：

输入：days = 5, meetings = [[2,4],[1,3]]

输出：1

解释：

第 5 天没有安排会议。

示例 3：

输入：days = 6, meetings = [[1,6]]

输出：0

解释：

所有工作日都安排了会议。



提示：

1 <= days <= 109
1 <= meetings.length <= 105
meetings[i].length == 2
1 <= meetings[i][0] <= meetings[i][1] <= days
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int last = 0, count = 0;

        sort(meetings.begin(), meetings.end());

        for (auto& meeting : meetings) {
            if (meeting[0] > last) {
                count += (meeting[0] - last - 1);
            }

            last = max(last, meeting[1]);
        }

        count += (days - last);

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> meetings = { {5,7},{1,3},{9,10} };
    check.checkInt(2, o.countDays(10, meetings));

    meetings = { {2,4},{1,3} };
    check.checkInt(1, o.countDays(5, meetings));

    meetings = { {1,6} };
    check.checkInt(0, o.countDays(6, meetings));
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
