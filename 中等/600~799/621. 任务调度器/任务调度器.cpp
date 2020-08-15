/* 任务调度器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26 种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。

然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。

你需要计算完成所有任务所需要的最短时间。

 

示例 ：

输入：tasks = ["A","A","A","B","B","B"], n = 2
输出：8
解释：A -> B -> (待命) -> A -> B -> (待命) -> A -> B.
     在本示例中，两个相同类型任务之间必须间隔长度为 n = 2 的冷却时间，而执行一个任务只需要一个单位时间，所以中间出现了（待命）状态。
 

提示：

任务的总个数为 [1, 10000]。
n 的取值范围为 [0, 100]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/task-scheduler
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int taskCount[26] = { 0 };
        for (char task : tasks) {
            taskCount[task - 'A']++;
        }

        sort(taskCount, taskCount + 26);

        int i = 24, mostFrequencyTask = taskCount[25];
        while ((i >= 0) && (taskCount[i] == mostFrequencyTask)) {
            i--;
        }

        int totalTask = tasks.size();
        int mostFrequencyTaskCount = 25 - i;
        int buckets = mostFrequencyTask - 1;
        int idleSlots = (n + 1 > mostFrequencyTaskCount) ? (n + 1 - mostFrequencyTaskCount) * buckets : 0;
        int notMostFrequncyTasks = totalTask - mostFrequencyTaskCount * mostFrequencyTask;
        int taskLeft = (notMostFrequncyTasks > idleSlots) ? notMostFrequncyTasks - idleSlots : 0;
        
        return max((n + 1), mostFrequencyTaskCount) * buckets + mostFrequencyTaskCount + taskLeft;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<char> tasks = { 'A','A','A','B','B','B' };
    check.checkInt(8, o.leastInterval(tasks, 2));

    tasks = { 'A','A','A','B','B','B' };
    check.checkInt(6, o.leastInterval(tasks, 0));

    tasks = { 'A','A','A','B','B','B','C','D' };
    check.checkInt(8, o.leastInterval(tasks, 2));

    tasks = { 'A','A','A','B','B','B','C','D','E','E','E','E','F','F','F' };
    check.checkInt(15, o.leastInterval(tasks, 2));

    tasks = { 'A','B','C','D','E','A','B','C','D','E' };
    check.checkInt(10, o.leastInterval(tasks, 4));
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
