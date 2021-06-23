/* 规划兼职工作.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你打算利用空闲时间来做兼职工作赚些零花钱。

这里有 n 份兼职工作，每份工作预计从 startTime[i] 开始到 endTime[i] 结束，报酬为 profit[i]。

给你一份兼职工作表，包含开始时间 startTime，结束时间 endTime 和预计报酬 profit 三个数组，请你计算并返回可以获得的最大报酬。

注意，时间上出现重叠的 2 份工作不能同时进行。

如果你选择的工作在时间 X 结束，那么你可以立刻进行在时间 X 开始的下一份工作。

 

示例 1：



输入：startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
输出：120
解释：
我们选出第 1 份和第 4 份工作，
时间范围是 [1-3]+[3-6]，共获得报酬 120 = 50 + 70。
示例 2：



输入：startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
输出：150
解释：
我们选择第 1，4，5 份工作。
共获得报酬 150 = 20 + 70 + 60。
示例 3：



输入：startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
输出：6
 

提示：

1 <= startTime.length == endTime.length == profit.length <= 5 * 10^4
1 <= startTime[i] < endTime[i] <= 10^9
1 <= profit[i] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-profit-in-job-scheduling
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Job {
public:
    int start;
    int end;
    int profit;

    Job() : start(0), end(0), profit(0) {}
    Job(int _start, int _end, int _profit) : start(_start), end(_end), profit(_profit) {}

    bool operator<(const Job& job) const {
        return start < job.start;
    }
};

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int i, size = startTime.size();
        vector<Job> jobs(size);
        vector<int> dp(size + 1, 0);

        for (i = 0; i < size; ++i) {
            jobs[i] = Job(startTime[i], endTime[i], profit[i]);
        }

        sort(jobs.begin(), jobs.end());

        for (i = size - 1; i >= 0; --i) {
            auto iter = lower_bound(jobs.begin(), jobs.end(), Job(jobs[i].end, 0, 0));
            int index = distance(jobs.begin(), iter);
            dp[i] = max(dp[i + 1], jobs[i].profit + dp[index]);
        }

        return dp[0];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> startTime = { 1,2,3,3 };
    vector<int> endTime = { 3,4,5,6 };
    vector<int> profit = { 50,10,40,70 };
    check.checkInt(120, o.jobScheduling(startTime, endTime, profit));

    startTime = { 1,2,3,4,6 };
    endTime = { 3,5,10,6,9 };
    profit = { 20,20,100,70,60 };
    check.checkInt(150, o.jobScheduling(startTime, endTime, profit));

    startTime = { 1,1,1 };
    endTime = { 2,3,4 };
    profit = { 5,6,4 };
    check.checkInt(6, o.jobScheduling(startTime, endTime, profit));
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
