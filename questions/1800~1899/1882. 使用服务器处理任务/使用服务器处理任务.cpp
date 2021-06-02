/* 使用服务器处理任务.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个 下标从 0 开始 的整数数组 servers 和 tasks ，长度分别为 n​​​​​​ 和 m​​​​​​ 。servers[i] 是第 i​​​​​​​​​​ 台服务器的 权重 ，而 tasks[j] 是处理第 j​​​​​​ 项任务 所需要的时间（单位：秒）。

你正在运行一个仿真系统，在处理完所有任务后，该系统将会关闭。每台服务器只能同时处理一项任务。第 0 项任务在第 0 秒可以开始处理，相应地，第 j 项任务在第 j 秒可以开始处理。处理第 j 项任务时，你需要为它分配一台 权重最小 的空闲服务器。如果存在多台相同权重的空闲服务器，请选择 下标最小 的服务器。如果一台空闲服务器在第 t 秒分配到第 j 项任务，那么在 t + tasks[j] 时它将恢复空闲状态。

如果没有空闲服务器，则必须等待，直到出现一台空闲服务器，并 尽可能早 地处理剩余任务。 如果有多项任务等待分配，则按照 下标递增 的顺序完成分配。

如果同一时刻存在多台空闲服务器，可以同时将多项任务分别分配给它们。

构建长度为 m 的答案数组 ans ，其中 ans[j] 是第 j 项任务分配的服务器的下标。

返回答案数组 ans​​​​ 。

 

示例 1：

输入：servers = [3,3,2], tasks = [1,2,3,2,1,2]
输出：[2,2,0,2,1,2]
解释：事件按时间顺序如下：
- 0 秒时，第 0 项任务加入到任务队列，使用第 2 台服务器处理到 1 秒。
- 1 秒时，第 2 台服务器空闲，第 1 项任务加入到任务队列，使用第 2 台服务器处理到 3 秒。
- 2 秒时，第 2 项任务加入到任务队列，使用第 0 台服务器处理到 5 秒。
- 3 秒时，第 2 台服务器空闲，第 3 项任务加入到任务队列，使用第 2 台服务器处理到 5 秒。
- 4 秒时，第 4 项任务加入到任务队列，使用第 1 台服务器处理到 5 秒。
- 5 秒时，所有服务器都空闲，第 5 项任务加入到任务队列，使用第 2 台服务器处理到 7 秒。
示例 2：

输入：servers = [5,1,4,3,2], tasks = [2,1,2,4,5,2,1]
输出：[1,4,1,4,1,3,2]
解释：事件按时间顺序如下：
- 0 秒时，第 0 项任务加入到任务队列，使用第 1 台服务器处理到 2 秒。
- 1 秒时，第 1 项任务加入到任务队列，使用第 4 台服务器处理到 2 秒。
- 2 秒时，第 1 台和第 4 台服务器空闲，第 2 项任务加入到任务队列，使用第 1 台服务器处理到 4 秒。
- 3 秒时，第 3 项任务加入到任务队列，使用第 4 台服务器处理到 7 秒。
- 4 秒时，第 1 台服务器空闲，第 4 项任务加入到任务队列，使用第 1 台服务器处理到 9 秒。
- 5 秒时，第 5 项任务加入到任务队列，使用第 3 台服务器处理到 7 秒。
- 6 秒时，第 6 项任务加入到任务队列，使用第 2 台服务器处理到 7 秒。
 

提示：

servers.length == n
tasks.length == m
1 <= n, m <= 2 * 105
1 <= servers[i], tasks[j] <= 2 * 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/process-tasks-using-servers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Task {
public:
    Task(long long _end, int _id) : end(_end), serverId(_id) {}
    long long end;
    int serverId;

    bool operator< (const Task& t) const {
        return end > t.end;
    }
};

class Server {
public:
    Server(int _id, int _weight) : id(_id), weight(_weight) {}

    bool operator< (const Server& s) const {
        return weight == s.weight ? id > s.id : weight > s.weight;
    }

    int id;
    int weight;
};

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int index = 0, id, size = tasks.size();
        vector<int> assignedServers(size);
        queue<int> waitingTasks;
        priority_queue<Task> runningTasks;
        priority_queue<Server> idleServers;

        for (int i = 0; i < (int)servers.size(); ++i) {
            idleServers.push(Server(i, servers[i]));
        }

        for (int second = 0; second < size; ++second) {
            waitingTasks.push(tasks[second]);  // 每秒将一个任务放入队列等待执行

            while (!runningTasks.empty() && runningTasks.top().end == second) {  // 将这一秒所有执行完的任务服务器释放回空闲队列
                id = runningTasks.top().serverId;
                idleServers.push(Server(id, servers[id]));
                runningTasks.pop();
            }

            while (!idleServers.empty() && !waitingTasks.empty()) {  // 尽最大可能给等待任务安排服务器
                runningTasks.push(Task((long long)second + waitingTasks.front(), idleServers.top().id));
                assignedServers[index++] = idleServers.top().id;
                idleServers.pop();
                waitingTasks.pop();
            }
        }

        while (!waitingTasks.empty()) {  // 在size秒之后，不能再遍历每一秒，而是直接考察下一个任务结束的时间
            long long second = runningTasks.top().end;

            while (!runningTasks.empty() && runningTasks.top().end == second) {  // 重复上面的过程
                id = runningTasks.top().serverId;
                idleServers.push(Server(id, servers[id]));
                runningTasks.pop();
            }

            while (!idleServers.empty() && !waitingTasks.empty()) {
                runningTasks.push(Task(second + waitingTasks.front(), idleServers.top().id));
                assignedServers[index++] = idleServers.top().id;
                idleServers.pop();
                waitingTasks.pop();
            }
        }

        return assignedServers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> servers = { 3,3,2 };
    vector<int> tasks = { 1,2,3,2,1,2 };
    vector<int> actual = o.assignTasks(servers, tasks);
    vector<int> expected = { 2,2,0,2,1,2 };
    check.checkIntVector(expected, actual);

    servers = { 5,1,4,3,2 };
    tasks = { 2,1,2,4,5,2,1 };
    actual = o.assignTasks(servers, tasks);
    expected = { 1,4,1,4,1,3,2 };
    check.checkIntVector(expected, actual);

    servers = { 338,890,301,532,284,930,426,616,919,267,571,140,716,859,980,469,628,490,195,664,925,652,503,301,917,563,82,947,910,451,366,190,253,516,503,721,889,964,506,914,986,718,520,328,341,765,922,139,911,578,86,435,824,321,942,215,147,985,619,865 };
    tasks = { 773,537,46,317,233,34,712,625,336,221,145,227,194,693,981,861,317,308,400,2,391,12,626,265,710,792,620,416,267,611,875,361,494,128,133,157,638,632,2,158,428,284,847,431,94,782,888,44,117,489,222,932,494,948,405,44,185,587,738,164,356,783,276,547,605,609,930,847,39,579,768,59,976,790,612,196,865,149,975,28,653,417,539,131,220,325,252,160,761,226,629,317,185,42,713,142,130,695,944,40,700,122,992,33,30,136,773,124,203,384,910,214,536,767,859,478,96,172,398,146,713,80,235,176,876,983,363,646,166,928,232,699,504,612,918,406,42,931,647,795,139,933,746,51,63,359,303,752,799,836,50,854,161,87,346,507,468,651,32,717,279,139,851,178,934,233,876,797,701,505,878,731,468,884,87,921,782,788,803,994,67,905,309,2,85,200,368,672,995,128,734,157,157,814,327,31,556,394,47,53,755,721,159,843 };
    actual = o.assignTasks(servers, tasks);
    expected = { 26,50,47,11,56,31,18,55,32,9,4,2,23,53,43,0,44,30,6,51,29,51,15,17,22,34,38,33,42,3,25,10,49,51,7,58,16,21,19,31,19,12,41,35,45,52,13,59,47,36,1,28,48,39,24,8,46,20,5,54,27,37,14,57,40,59,8,45,4,51,47,7,58,4,31,23,54,7,9,56,2,46,56,1,17,42,11,30,12,44,14,32,7,10,23,1,29,27,6,10,33,24,19,10,35,30,35,10,17,49,50,36,29,1,48,44,7,11,24,57,42,30,10,55,3,20,38,15,7,46,32,21,40,16,59,30,53,17,18,22,51,11,53,36,57,26,5,36,56,55,31,34,57,7,52,37,31,10,0,51,41,2,32,25,0,7,49,47,13,14,24,57,28,4,45,43,39,38,8,2,44,45,29,25,25,12,54,5,44,30,27,23,26,7,33,58,41,25,52,40,58,9,52,40 };
    check.checkIntVector(expected, actual);

    servers = { 10,63,95,16,85,57,83,95,6,29,71 };
    tasks = { 70,31,83,15,32,67,98,65,56,48,38,90,5 };
    actual = o.assignTasks(servers, tasks);
    expected = { 8,0,3,9,5,1,10,6,4,2,7,9,0 };
    check.checkIntVector(expected, actual);

    servers = { 1 };
    tasks = { 1 };
    actual = o.assignTasks(servers, tasks);
    expected = { 0 };
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
