/* 工作计划的最低难度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你需要制定一份 d 天的工作计划表。工作之间存在依赖，要想执行第 i 项工作，你必须完成全部 j 项工作（ 0 <= j < i）。

你每天 至少 需要完成一项任务。工作计划的总难度是这 d 天每一天的难度之和，而一天的工作难度是当天应该完成工作的最大难度。

给你一个整数数组 jobDifficulty 和一个整数 d，分别代表工作难度和需要计划的天数。第 i 项工作的难度是 jobDifficulty[i]。

返回整个工作计划的 最小难度 。如果无法制定工作计划，则返回 -1 。

 

示例 1：



输入：jobDifficulty = [6,5,4,3,2,1], d = 2
输出：7
解释：第一天，您可以完成前 5 项工作，总难度 = 6.
第二天，您可以完成最后一项工作，总难度 = 1.
计划表的难度 = 6 + 1 = 7
示例 2：

输入：jobDifficulty = [9,9,9], d = 4
输出：-1
解释：就算你每天完成一项工作，仍然有一天是空闲的，你无法制定一份能够满足既定工作时间的计划表。
示例 3：

输入：jobDifficulty = [1,1,1], d = 3
输出：3
解释：工作计划为每天一项工作，总难度为 3 。
示例 4：

输入：jobDifficulty = [7,1,7,1,7,1], d = 3
输出：15
示例 5：

输入：jobDifficulty = [11,111,22,222,33,333,44,444], d = 6
输出：843
 

提示：

1 <= jobDifficulty.length <= 300
0 <= jobDifficulty[i] <= 1000
1 <= d <= 10

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-difficulty-of-a-job-schedule
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int start, day, index, size = jobDifficulty.size();
        if (size < d) {
            return -1;
        }

        vector<vector<int>> dp(size + 1, vector<int>(d + 1, 1000000000));  // dp[start][day]表示job[start, size)安排day天完成的minDifficulty
        dp[size - 1][1] = jobDifficulty.back();

        for (start = size - 2; start >= 0; --start) {
            dp[start][1] = max(dp[start + 1][1], jobDifficulty[start]);

            for (day = 2; day <= d && day <= size - start; ++day) {
                int firstDayDifficulty = 0;

                for (index = start; index < size - day + 1; ++index) {
                    firstDayDifficulty = max(firstDayDifficulty, jobDifficulty[index]);
                    dp[start][day] = min(dp[start][day], firstDayDifficulty + dp[index + 1][day - 1]);
                }
            }
        }

        return dp[0][d];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> jobDifficulty = { 6,5,4,3,2,1 };
    check.checkInt(7, o.minDifficulty(jobDifficulty, 2));

    jobDifficulty = { 9,9,9 };
    check.checkInt(-1, o.minDifficulty(jobDifficulty, 4));

    jobDifficulty = { 1,1,1 };
    check.checkInt(3, o.minDifficulty(jobDifficulty, 3));

    jobDifficulty = { 7,1,7,1,7,1 };
    check.checkInt(15, o.minDifficulty(jobDifficulty, 3));

    jobDifficulty = { 11,111,22,222,33,333,44,444 };
    check.checkInt(843, o.minDifficulty(jobDifficulty, 6));
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
