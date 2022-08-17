/* 任务调度器 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的正整数数组 tasks ，表示需要 按顺序 完成的任务，其中 tasks[i] 表示第 i 件任务的 类型 。

同时给你一个正整数 space ，表示一个任务完成 后 ，另一个 相同 类型任务完成前需要间隔的 最少 天数。

在所有任务完成前的每一天，你都必须进行以下两种操作中的一种：

完成 tasks 中的下一个任务
休息一天
请你返回完成所有任务所需的 最少 天数。

 

示例 1：

输入：tasks = [1,2,1,2,3,1], space = 3
输出：9
解释：
9 天完成所有任务的一种方法是：
第 1 天：完成任务 0 。
第 2 天：完成任务 1 。
第 3 天：休息。
第 4 天：休息。
第 5 天：完成任务 2 。
第 6 天：完成任务 3 。
第 7 天：休息。
第 8 天：完成任务 4 。
第 9 天：完成任务 5 。
可以证明无法少于 9 天完成所有任务。
示例 2：

输入：tasks = [5,8,8,5], space = 2
输出：6
解释：
6 天完成所有任务的一种方法是：
第 1 天：完成任务 0 。
第 2 天：完成任务 1 。
第 3 天：休息。
第 4 天：休息。
第 5 天：完成任务 2 。
第 6 天：完成任务 3 。
可以证明无法少于 6 天完成所有任务。
 

提示：

1 <= tasks.length <= 105
1 <= tasks[i] <= 109
1 <= space <= tasks.length

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/task-scheduler-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int, long long> taskDays;
        long long day = 0;

        for (int task : tasks) {
            if (taskDays.count(task) == 0 || taskDays[task] + space < day) {
                taskDays[task] = day++;  // 该任务第一次执行或者已经过了间隔期，可以直接执行它
            }
            else {  // 还在间隔期内，需要间隔space，然后下一天执行它
                day = taskDays[task] + space + 1;
                taskDays[task] = day++;
            }
        }

        return day;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> tasks = { 1,2,1,2,3,1 };
    check.checkLongLong(9, o.taskSchedulerII(tasks, 3));

    tasks = { 5,8,8,5 };
    check.checkLongLong(6, o.taskSchedulerII(tasks, 2));

    tasks = { 450,610,68,810,992,306,336,907,6,288,336,985,265,828,737,771,508,210,907,973,336,654,766,783,654,508,654,291,926,839,352,210,336,744,6,771,450,481,680,610,661,15,985,420,810,737,19,837,737,811,338,737,449,741,335,596,541,948,993,629,341,839,741,674,667,992,771,929,237,664,265,795,795,839,341,541,811,859,811,596,582,771,948,541,514,691,306,462,907,486,992,115 };
    check.checkLongLong(289, o.taskSchedulerII(tasks, 25));
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
