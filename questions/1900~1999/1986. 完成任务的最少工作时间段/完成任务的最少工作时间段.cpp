/* 完成任务的最少工作时间段.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你被安排了 n 个任务。任务需要花费的时间用长度为 n 的整数数组 tasks 表示，第 i 个任务需要花费 tasks[i] 小时完成。一个 工作时间段 中，你可以 至多 连续工作 sessionTime 个小时，然后休息一会儿。

你需要按照如下条件完成给定任务：

如果你在某一个时间段开始一个任务，你需要在 同一个 时间段完成它。
完成一个任务后，你可以 立马 开始一个新的任务。
你可以按 任意顺序 完成任务。
给你 tasks 和 sessionTime ，请你按照上述要求，返回完成所有任务所需要的 最少 数目的 工作时间段 。

测试数据保证 sessionTime 大于等于 tasks[i] 中的 最大值 。

 

示例 1：

输入：tasks = [1,2,3], sessionTime = 3
输出：2
解释：你可以在两个工作时间段内完成所有任务。
- 第一个工作时间段：完成第一和第二个任务，花费 1 + 2 = 3 小时。
- 第二个工作时间段：完成第三个任务，花费 3 小时。
示例 2：

输入：tasks = [3,1,3,1,1], sessionTime = 8
输出：2
解释：你可以在两个工作时间段内完成所有任务。
- 第一个工作时间段：完成除了最后一个任务以外的所有任务，花费 3 + 1 + 3 + 1 = 8 小时。
- 第二个工作时间段，完成最后一个任务，花费 1 小时。
示例 3：

输入：tasks = [1,2,3,4,5], sessionTime = 15
输出：1
解释：你可以在一个工作时间段以内完成所有任务。
 

提示：

n == tasks.length
1 <= n <= 14
1 <= tasks[i] <= 10
max(tasks[i]) <= sessionTime <= 15

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size(), size = 1 << n, mask, subset;
        vector<bool> oneSession(size, false);
        vector<int> dp(size, n + 1);

        canBeOneSession(tasks, sessionTime, oneSession, dp);

        for (mask = 1; mask < size; ++mask) {
            for (subset = mask; subset != 0; subset = (subset - 1) & mask) {  // 枚举mask的所有子集
                if (oneSession[subset]) {
                    dp[mask] = min(dp[mask], 1 + dp[mask ^ subset]);
                }
            }
        }

        return dp.back();
    }

    void canBeOneSession(vector<int>& tasks, int sessionTime, vector<bool>& oneSession, vector<int>& dp) {
        int n = tasks.size(), size = 1 << n, i, bit, mask;

        for (mask = 1; mask < size; ++mask) {
            int time = 0;

            for (i = 0, bit = 1; i < n; ++i, bit <<= 1) {
                if ((bit & mask) != 0) {
                    time += tasks[i];
                }
            }

            if (time <= sessionTime) {
                oneSession[mask] = true;
                dp[mask] = 1;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> tasks = { 1,2,3 };
    check.checkInt(2, o.minSessions(tasks, 3));

    tasks = { 3,1,3,1,1 };
    check.checkInt(2, o.minSessions(tasks, 8));

    tasks = { 1,2,3,4,5 };
    check.checkInt(1, o.minSessions(tasks, 15));

    tasks = { 9,8,8,4,6 };
    check.checkInt(3, o.minSessions(tasks, 14));

    tasks = { 2,10,1,10,4,4,7,10,7,4,10,2 };
    check.checkInt(5, o.minSessions(tasks, 15));

    tasks = { 5 };
    check.checkInt(1, o.minSessions(tasks, 5));
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
