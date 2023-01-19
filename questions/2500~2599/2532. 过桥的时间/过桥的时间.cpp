/* 过桥的时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
共有 k 位工人计划将 n 个箱子从旧仓库移动到新仓库。给你两个整数 n 和 k，以及一个二维整数数组 time ，数组的大小为 k x 4 ，其中 time[i] = [leftToRighti, pickOldi, rightToLefti, putNewi] 。

一条河将两座仓库分隔，只能通过一座桥通行。旧仓库位于河的右岸，新仓库在河的左岸。开始时，所有 k 位工人都在桥的左侧等待。为了移动这些箱子，第 i 位工人（下标从 0 开始）可以：

从左岸（新仓库）跨过桥到右岸（旧仓库），用时 leftToRighti 分钟。
从旧仓库选择一个箱子，并返回到桥边，用时 pickOldi 分钟。不同工人可以同时搬起所选的箱子。
从右岸（旧仓库）跨过桥到左岸（新仓库），用时 rightToLefti 分钟。
将箱子放入新仓库，并返回到桥边，用时 putNewi 分钟。不同工人可以同时放下所选的箱子。
如果满足下面任一条件，则认为工人 i 的 效率低于 工人 j ：

leftToRighti + rightToLefti > leftToRightj + rightToLeftj
leftToRighti + rightToLefti == leftToRightj + rightToLeftj 且 i > j
工人通过桥时需要遵循以下规则：

如果工人 x 到达桥边时，工人 y 正在过桥，那么工人 x 需要在桥边等待。
如果没有正在过桥的工人，那么在桥右边等待的工人可以先过桥。如果同时有多个工人在右边等待，那么 效率最低 的工人会先过桥。
如果没有正在过桥的工人，且桥右边也没有在等待的工人，同时旧仓库还剩下至少一个箱子需要搬运，此时在桥左边的工人可以过桥。如果同时有多个工人在左边等待，那么 效率最低 的工人会先过桥。
所有 n 个盒子都需要放入新仓库，请你返回最后一个搬运箱子的工人 到达河左岸 的时间。



示例 1：

输入：n = 1, k = 3, time = [[1,1,2,1],[1,1,3,1],[1,1,4,1]]
输出：6
解释：
从 0 到 1 ：工人 2 从左岸过桥到达右岸。
从 1 到 2 ：工人 2 从旧仓库搬起一个箱子。
从 2 到 6 ：工人 2 从右岸过桥到达左岸。
从 6 到 7 ：工人 2 将箱子放入新仓库。
整个过程在 7 分钟后结束。因为问题关注的是最后一个工人到达左岸的时间，所以返回 6 。
示例 2：

输入：n = 3, k = 2, time = [[1,9,1,8],[10,10,10,10]]
输出：50
解释：
从 0 到 10 ：工人 1 从左岸过桥到达右岸。
从 10 到 20 ：工人 1 从旧仓库搬起一个箱子。
从 10 到 11 ：工人 0 从左岸过桥到达右岸。
从 11 到 20 ：工人 0 从旧仓库搬起一个箱子。
从 20 到 30 ：工人 1 从右岸过桥到达左岸。
从 30 到 40 ：工人 1 将箱子放入新仓库。
从 30 到 31 ：工人 0 从右岸过桥到达左岸。
从 31 到 39 ：工人 0 将箱子放入新仓库。
从 39 到 40 ：工人 0 从左岸过桥到达右岸。
从 40 到 49 ：工人 0 从旧仓库搬起一个箱子。
从 49 到 50 ：工人 0 从右岸过桥到达左岸。
从 50 到 58 ：工人 0 将箱子放入新仓库。
整个过程在 58 分钟后结束。因为问题关注的是最后一个工人到达左岸的时间，所以返回 50 。


提示：

1 <= n, k <= 104
time.length == k
time[i].length == 4
1 <= leftToRighti, pickOldi, rightToLefti, putNewi <= 1000
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Worker {
public:
    int index;
    int l2r;
    int pickOld;
    int r2l;
    int putNew;
    int cost;
    int arriveTime;

    Worker() : index(0), l2r(0), pickOld(0), r2l(0), putNew(0), cost(0), arriveTime(0) {}
    Worker(int i, int l, int pick, int r, int put, int t) : index(i), l2r(l), pickOld(pick), r2l(r), putNew(put), cost(l + r), arriveTime(0) {}
};

class timeCompare {
public:
    bool operator()(const Worker& w1, const Worker& w2) const {
        return w1.arriveTime > w2.arriveTime;
    }
};

class efficientCompare {
public:
    bool operator()(const Worker& w1, const Worker& w2) const {
        return w1.cost == w2.cost ? w1.index < w2.index : w1.cost < w2.cost;
    }
};

class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<Worker, vector<Worker>, timeCompare> leftArrivings, rightArrivings;
        priority_queue<Worker, vector<Worker>, efficientCompare> leftArriveds, rightArriveds;
        int current = 0, boxes = 0;

        for (int i = 0; i < k; ++i) {
            Worker worker(i, time[i][0], time[i][1], time[i][2], time[i][3], 0);
            leftArriveds.push(worker);
        }

        while (boxes < n) {  // 搬n个箱子到右岸
            if (!rightArrivings.empty() && rightArrivings.top().arriveTime <= current) {  // 如果在当前时间内有人到达右岸，将他移入到达队列
                rightArriveds.push(rightArrivings.top());
                rightArrivings.pop();
            }
            else if (!rightArriveds.empty()) {  // 如果右岸到达队列不为空，放行一人到左岸
                Worker worker = rightArriveds.top();
                rightArriveds.pop();
                current += worker.r2l;  // 该worker到达左岸的时间
                worker.arriveTime = current + worker.putNew;  // 该worker放下箱子再回到左岸的时间
                leftArrivings.push(worker);
            }
            else if (!leftArrivings.empty() && leftArrivings.top().arriveTime <= current) { // 如果在当前时间内有人到达左岸，将他移入到达队列
                leftArriveds.push(leftArrivings.top());
                leftArrivings.pop();
            }
            else if (!leftArriveds.empty()) {  // 如果左岸到达队列不为空，放行一人到右岸
                Worker worker = leftArriveds.top();
                leftArriveds.pop();
                current += worker.l2r;  // 该worker到达右岸的时间
                worker.arriveTime = current + worker.pickOld;  // 该worker放下箱子再回到右岸的时间
                rightArrivings.push(worker);
                ++boxes;
            }
            else {  // 当前时间没有人到达桥边，将时间调整到第一个到达的人
                current = min(leftArrivings.empty() ? INT_MAX : leftArrivings.top().arriveTime, rightArrivings.empty() ? INT_MAX : rightArrivings.top().arriveTime);
            }
        }

        while (!rightArrivings.empty() || !rightArriveds.empty()) {  // 搬箱子的人全部回到左岸
            if (!rightArrivings.empty() && rightArrivings.top().arriveTime <= current) {  // 如果在当前时间内有人到达右岸，将他移入到达队列
                rightArriveds.push(rightArrivings.top());
                rightArrivings.pop();
            }
            else if (!rightArriveds.empty()) {  // 如果右岸到达队列不为空，放行一人到左岸
                Worker worker = rightArriveds.top();
                rightArriveds.pop();
                current += worker.r2l;
            }
            else {  // 当前时间没有人到达桥边，将时间调整到第一个到达的人
                current = rightArrivings.top().arriveTime;
            }
        }

        return current;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> time = { {1,1,2,1},{1,1,3,1},{1,1,4,1} };
    check.checkInt(6, o.findCrossingTime(1, 3, time));

    time = { {1,9,1,8},{10,10,10,10} };
    check.checkInt(50, o.findCrossingTime(3, 2, time));
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
