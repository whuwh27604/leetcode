/* 设计任务管理器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个任务管理器系统可以让用户管理他们的任务，每个任务有一个优先级。这个系统需要高效地处理添加、修改、执行和删除任务的操作。

请你设计一个 TaskManager 类：

TaskManager(vector<vector<int>>& tasks) 初始化任务管理器，初始化的数组格式为 [userId, taskId, priority] ，表示给 userId 添加一个优先级为 priority 的任务 taskId 。

void add(int userId, int taskId, int priority) 表示给用户 userId 添加一个优先级为 priority 的任务 taskId ，输入 保证 taskId 不在系统中。

void edit(int taskId, int newPriority) 更新已经存在的任务 taskId 的优先级为 newPriority 。输入 保证 taskId 存在于系统中。

void rmv(int taskId) 从系统中删除任务 taskId 。输入 保证 taskId 存在于系统中。

int execTop() 执行所有用户的任务中优先级 最高 的任务，如果有多个任务优先级相同且都为 最高 ，执行 taskId 最大的一个任务。执行完任务后，taskId 从系统中 删除 。同时请你返回这个任务所属的用户 userId 。如果不存在任何任务，返回 -1 。

注意 ，一个用户可能被安排多个任务。



示例 1：

输入：
["TaskManager", "add", "edit", "execTop", "rmv", "add", "execTop"]
[[[[1, 101, 10], [2, 102, 20], [3, 103, 15]]], [4, 104, 5], [102, 8], [], [101], [5, 105, 15], []]

输出：
[null, null, null, 3, null, null, 5]

解释：

TaskManager taskManager = new TaskManager([[1, 101, 10], [2, 102, 20], [3, 103, 15]]); // 分别给用户 1 ，2 和 3 初始化一个任务。
taskManager.add(4, 104, 5); // 给用户 4 添加优先级为 5 的任务 104 。
taskManager.edit(102, 8); // 更新任务 102 的优先级为 8 。
taskManager.execTop(); // 返回 3 。执行用户 3 的任务 103 。
taskManager.rmv(101); // 将系统中的任务 101 删除。
taskManager.add(5, 105, 15); // 给用户 5 添加优先级为 15 的任务 105 。
taskManager.execTop(); // 返回 5 。执行用户 5 的任务 105 。


提示：

1 <= tasks.length <= 105
0 <= userId <= 105
0 <= taskId <= 105
0 <= priority <= 109
0 <= newPriority <= 109
add ，edit ，rmv 和 execTop 的总操作次数 加起来 不超过 2 * 105 次。
*/

#include <iostream>
#include <set>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Task {
public:
    int userId;
    int taskId;
    int priority;

    Task() : userId(0), taskId(0), priority(0) {}
    Task(int u, int t, int p) : userId(u), taskId(t), priority(p) {}

    bool operator<(const Task& t) const {
        return priority == t.priority ? taskId > t.taskId : priority > t.priority;
    }
};

class TaskManager {
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        taskSet.insert(Task(userId, taskId, priority));
        taskMap[taskId] = { userId,priority };
    }

    void edit(int taskId, int newPriority) {
        int userId = taskMap[taskId].first, priority = taskMap[taskId].second;
        taskSet.erase(Task(userId, taskId, priority));
        taskSet.insert(Task(userId, taskId, newPriority));
        taskMap[taskId] = { userId,newPriority };
    }

    void rmv(int taskId) {
        int userId = taskMap[taskId].first, priority = taskMap[taskId].second;
        taskSet.erase(Task(userId, taskId, priority));
        taskMap.erase(taskId);
    }

    int execTop() {
        if (taskSet.empty()) {
            return -1;
        }

        int userId = taskSet.begin()->userId, taskId = taskSet.begin()->taskId;
        rmv(taskId);

        return userId;
    }

    set<Task> taskSet;
    unordered_map<int, pair<int, int>> taskMap;
};

int main()
{
    CheckResult check;

    vector<vector<int>> tasks = { {1,101,10},{2,102,20},{3,103,15} };
    TaskManager o1(tasks);
    o1.add(4, 104, 5);
    o1.edit(102, 8);
    check.checkInt(3, o1.execTop());
    o1.rmv(101);
    o1.add(5, 105, 15);
    check.checkInt(5, o1.execTop());
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
