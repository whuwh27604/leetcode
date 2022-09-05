/* 会议室 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n ，共有编号从 0 到 n - 1 的 n 个会议室。

给你一个二维整数数组 meetings ，其中 meetings[i] = [starti, endi] 表示一场会议将会在 半闭 时间区间 [starti, endi) 举办。所有 starti 的值 互不相同 。

会议将会按以下方式分配给会议室：

每场会议都会在未占用且编号 最小 的会议室举办。
如果没有可用的会议室，会议将会延期，直到存在空闲的会议室。延期会议的持续时间和原会议持续时间 相同 。
当会议室处于未占用状态时，将会优先提供给原 开始 时间更早的会议。
返回举办最多次会议的房间 编号 。如果存在多个房间满足此条件，则返回编号 最小 的房间。

半闭区间 [a, b) 是 a 和 b 之间的区间，包括 a 但 不包括 b 。

 

示例 1：

输入：n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
输出：0
解释：
- 在时间 0 ，两个会议室都未占用，第一场会议在会议室 0 举办。
- 在时间 1 ，只有会议室 1 未占用，第二场会议在会议室 1 举办。
- 在时间 2 ，两个会议室都被占用，第三场会议延期举办。
- 在时间 3 ，两个会议室都被占用，第四场会议延期举办。
- 在时间 5 ，会议室 1 的会议结束。第三场会议在会议室 1 举办，时间周期为 [5,10) 。
- 在时间 10 ，两个会议室的会议都结束。第四场会议在会议室 0 举办，时间周期为 [10,11) 。
会议室 0 和会议室 1 都举办了 2 场会议，所以返回 0 。
示例 2：

输入：n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
输出：1
解释：
- 在时间 1 ，所有三个会议室都未占用，第一场会议在会议室 0 举办。
- 在时间 2 ，会议室 1 和 2 未占用，第二场会议在会议室 1 举办。
- 在时间 3 ，只有会议室 2 未占用，第三场会议在会议室 2 举办。
- 在时间 4 ，所有三个会议室都被占用，第四场会议延期举办。
- 在时间 5 ，会议室 2 的会议结束。第四场会议在会议室 2 举办，时间周期为 [5,10) 。
- 在时间 6 ，所有三个会议室都被占用，第五场会议延期举办。
- 在时间 10 ，会议室 1 和 2 的会议结束。第五场会议在会议室 1 举办，时间周期为 [10,12) 。
会议室 1 和会议室 2 都举办了 2 场会议，所以返回 1 。
 

提示：

1 <= n <= 100
1 <= meetings.length <= 105
meetings[i].length == 2
0 <= starti < endi <= 5 * 105
starti 的所有值 互不相同

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/meeting-rooms-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>> idleRooms;
        vector<int> bookedCnt(n, 0);

        sort(meetings.begin(), meetings.end());
        init(n, idleRooms);
        book(n, meetings, idleRooms, bookedCnt);

        return getMostBooked(n, bookedCnt);
    }

    void init(int n, priority_queue<int, vector<int>, greater<int>>& idleRooms) {
        for (int room = 0; room < n; ++room) {
            idleRooms.push(room);
        }
    }

    void book(int n, vector<vector<int>>& meetings, priority_queue<int, vector<int>, greater<int>>& idleRooms, vector<int>& bookedCnt) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyRooms;  // { endTime, roomId }

        for (auto& meeting : meetings) {
            while (!busyRooms.empty() && busyRooms.top().first <= meeting[0]) {  // 将meeting[0]时刻之前结束的room释放掉
                idleRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if (idleRooms.empty()) {  // 如果没有idle的房间，只能等到最早结束的会议释放出一个房间
                long long time = max(busyRooms.top().first, (long long)meeting[0]);
                int room = busyRooms.top().second;
                busyRooms.pop();
                ++bookedCnt[room];
                busyRooms.push({ time + meeting[1] - meeting[0],room });
            }
            else {  // 如果还有idle的房间，直接使用它
                int room = idleRooms.top();
                idleRooms.pop();
                ++bookedCnt[room];
                busyRooms.push({ meeting[1],room });
            }
        }
    }

    int getMostBooked(int n, vector<int>& bookedCnt) {
        int maxCount = 0, maxBookedRoom = 0;

        for (int room = 0; room < n; ++room) {
            if (bookedCnt[room] > maxCount) {
                maxCount = bookedCnt[room];
                maxBookedRoom = room;
            }
        }

        return maxBookedRoom;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> meetings = { {0,10},{1,5},{2,7},{3,4} };
    check.checkInt(0, o.mostBooked(2, meetings));

    meetings = { {1,20},{2,10},{3,5},{4,9},{6,8} };
    check.checkInt(1, o.mostBooked(3, meetings));

    meetings = { {0,10},{1,2},{12,14},{13,15} };
    check.checkInt(0, o.mostBooked(2, meetings));
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
