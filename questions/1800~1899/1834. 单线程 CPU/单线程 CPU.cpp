// 单线程 CPU.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] != v2[0] ? v1[0] < v2[0] : v1[1] < v2[1];  // 先按照任务开始时间排序，开始时间相同则duration小的排在前面
}

struct pairCompare {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return p1.first != p2.first ? p1.first > p2.first : p1.second > p2.second;  // duration小的排在前面，duration相等则index小的排在前面
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, pairCompare> tasksQueue;  // duration, index
        vector<int> order(tasks.size());
        int endTime = -1, index = 0;

        addIndices(tasks);
        sort(tasks.begin(), tasks.end(), vectorCompare);

        for (auto& task : tasks) {
            while (!tasksQueue.empty() && task[0] > endTime) {  // 先将当前任务开始时间之前结束的任务依次执行，同时更新结束时间
                endTime += tasksQueue.top().first;
                order[index++] = tasksQueue.top().second;
                tasksQueue.pop();
            }

            if (task[0] <= endTime) {  // 结束时间已经超过了当前任务的开始时间，那么当前任务要参与排队
                tasksQueue.push({ task[1], task[2] });
            }
            else {  // 排队任务为空了，那么需要等到当前任务的开始时间再开始执行
                order[index++] = task[2];
                endTime = task[0] + task[1];
            }
        }

        while (!tasksQueue.empty()) {
            order[index++] = tasksQueue.top().second;
            tasksQueue.pop();
        }

        return order;
    }

    void addIndices(vector<vector<int>>& tasks) {
        int index = 0;

        for (auto& task : tasks) {
            task.push_back(index++);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> tasks = { {1,2},{2,4},{3,2},{4,1} };
    vector<int> actual = o.getOrder(tasks);
    vector<int> expected = { 0,2,3,1 };
    check.checkIntVector(expected, actual);

    tasks = { {7,10},{7,12},{7,5},{7,4},{7,2} };
    actual = o.getOrder(tasks);
    expected = { 4,3,2,0,1 };
    check.checkIntVector(expected, actual);
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
