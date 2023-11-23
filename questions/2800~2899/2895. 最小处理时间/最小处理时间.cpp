/* 最小处理时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有 n 颗处理器，每颗处理器都有 4 个核心。现有 n * 4 个待执行任务，每个核心只执行 一个 任务。

给你一个下标从 0 开始的整数数组 processorTime ，表示每颗处理器最早空闲时间。另给你一个下标从 0 开始的整数数组 tasks ，表示执行每个任务所需的时间。返回所有任务都执行完毕需要的 最小时间 。

注意：每个核心独立执行任务。



示例 1：

输入：processorTime = [8,10], tasks = [2,2,3,1,8,7,4,5]
输出：16
解释：
最优的方案是将下标为 4, 5, 6, 7 的任务分配给第一颗处理器（最早空闲时间 time = 8），下标为 0, 1, 2, 3 的任务分配给第二颗处理器（最早空闲时间 time = 10）。
第一颗处理器执行完所有任务需要花费的时间 = max(8 + 8, 8 + 7, 8 + 4, 8 + 5) = 16 。
第二颗处理器执行完所有任务需要花费的时间 = max(10 + 2, 10 + 2, 10 + 3, 10 + 1) = 13 。
因此，可以证明执行完所有任务需要花费的最小时间是 16 。
示例 2：

输入：processorTime = [10,20], tasks = [2,3,1,2,5,8,4,3]
输出：23
解释：
最优的方案是将下标为 1, 4, 5, 6 的任务分配给第一颗处理器（最早空闲时间 time = 10），下标为 0, 2, 3, 7 的任务分配给第二颗处理器（最早空闲时间 time = 20）。
第一颗处理器执行完所有任务需要花费的时间 = max(10 + 3, 10 + 5, 10 + 8, 10 + 4) = 18 。
第二颗处理器执行完所有任务需要花费的时间 = max(20 + 2, 20 + 1, 20 + 2, 20 + 3) = 23 。
因此，可以证明执行完所有任务需要花费的最小时间是 23 。


提示：

1 <= n == processorTime.length <= 25000
1 <= tasks.length <= 105
0 <= processorTime[i] <= 109
1 <= tasks[i] <= 109
tasks.length == 4 * n
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int n = processorTime.size(), minTime = 0;

        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end());

        for (int i = 0, j = 4 * n - 1; i < n; ++i, j -= 4) {
            minTime = max(minTime, processorTime[i] + tasks[j]);
        }

        return minTime;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> processorTime = { 8,10 };
    vector<int> tasks = { 2,2,3,1,8,7,4,5 };
    check.checkInt(16, o.minProcessingTime(processorTime, tasks));

    processorTime = { 10,20 };
    tasks = { 2,3,1,2,5,8,4,3 };
    check.checkInt(23, o.minProcessingTime(processorTime, tasks));
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
