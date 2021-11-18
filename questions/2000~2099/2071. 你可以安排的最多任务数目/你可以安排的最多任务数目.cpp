/* 你可以安排的最多任务数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你 n 个任务和 m 个工人。每个任务需要一定的力量值才能完成，需要的力量值保存在下标从 0 开始的整数数组 tasks 中，第 i 个任务需要 tasks[i] 的力量才能完成。每个工人的力量值保存在下标从 0 开始的整数数组 workers 中，第 j 个工人的力量值为 workers[j] 。每个工人只能完成 一个 任务，且力量值需要 大于等于 该任务的力量要求值（即 workers[j] >= tasks[i] ）。

除此以外，你还有 pills 个神奇药丸，可以给 一个工人的力量值 增加 strength 。你可以决定给哪些工人使用药丸，但每个工人 最多 只能使用 一片 药丸。

给你下标从 0 开始的整数数组tasks 和 workers 以及两个整数 pills 和 strength ，请你返回 最多 有多少个任务可以被完成。

 

示例 1：

输入：tasks = [3,2,1], workers = [0,3,3], pills = 1, strength = 1
输出：3
解释：
我们可以按照如下方案安排药丸：
- 给 0 号工人药丸。
- 0 号工人完成任务 2（0 + 1 >= 1）
- 1 号工人完成任务 1（3 >= 2）
- 2 号工人完成任务 0（3 >= 3）
示例 2：

输入：tasks = [5,4], workers = [0,0,0], pills = 1, strength = 5
输出：1
解释：
我们可以按照如下方案安排药丸：
- 给 0 号工人药丸。
- 0 号工人完成任务 0（0 + 5 >= 5）
示例 3：

输入：tasks = [10,15,30], workers = [0,10,10,10,10], pills = 3, strength = 10
输出：2
解释：
我们可以按照如下方案安排药丸：
- 给 0 号和 1 号工人药丸。
- 0 号工人完成任务 0（0 + 10 >= 10）
- 1 号工人完成任务 1（10 + 10 >= 15）
示例 4：

输入：tasks = [5,9,8,5,9], workers = [1,6,4,2,6], pills = 1, strength = 5
输出：3
解释：
我们可以按照如下方案安排药丸：
- 给 2 号工人药丸。
- 1 号工人完成任务 0（6 >= 5）
- 2 号工人完成任务 2（4 + 5 >= 8）
- 4 号工人完成任务 3（6 >= 5）
 

提示：

n == tasks.length
m == workers.length
1 <= n, m <= 5 * 104
0 <= pills <= m
0 <= tasks[i], workers[j], strength <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-tasks-you-can-assign
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <deque>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int low = 1, high = min(tasks.size(), workers.size()), maxTask = 0;

        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        while (low <= high) {
            int middle = (low + high) / 2;

            if (canFinish(tasks, workers, pills, strength, middle)) {
                maxTask = middle;
                low = middle + 1;
            }
            else {
                high = middle - 1;
            }
        }

        return maxTask;
    }

    //  要完成finished个任务，那么贪心的选择力量最大的finished个workers和花费最小的finished个tasks最有可能完成
    bool canFinish(vector<int>& tasks, vector<int>& workers, int pills, int strength, int finished) {
        deque<int> waitingWorks;
        int size = workers.size(), wIndex = size - 1;

        for (int tIndex = finished - 1; tIndex >= 0; --tIndex) {  // 从大到小枚举每一个task
            while (wIndex >= size - finished && workers[wIndex] + strength >= tasks[tIndex]) {  // 候选队列放入最小一个吃大力丸后可以完成该task的worker
                waitingWorks.push_back(workers[wIndex--]);
            }

            if (waitingWorks.empty()) {  // 吃了大力丸都没有人能完成task，所以返回失败
                return false;
            }

            /* 不吃大力丸就可以完成该task，那么我们选择该worker完成该task。没有必要选择更小的worker，因为task是按照从大到小的顺序讨论的，
               所有能完成tasks[i]的workers必然都能够完成tasks[i - 1] */
            if (waitingWorks.front() >= tasks[tIndex]) {
                waitingWorks.pop_front();
            }
            else {
                waitingWorks.pop_back();  // 没有人可以直接完成该task，那么吃一个大力丸，并贪心让最小的worker去完成。

                if (--pills < 0) {  // 可惜已经没有大力丸了，只能失败。
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> tasks = { 3,2,1 };
    vector<int> workers = { 0,3,3 };
    check.checkInt(3, o.maxTaskAssign(tasks, workers, 1, 1));

    tasks = { 5,4 };
    workers = { 0,0,0 };
    check.checkInt(1, o.maxTaskAssign(tasks, workers, 1, 5));

    tasks = { 10,15,30 };
    workers = { 0,10,10,10,10 };
    check.checkInt(2, o.maxTaskAssign(tasks, workers, 3, 10));

    tasks = { 5,9,8,5,9 };
    workers = { 1,6,4,2,6 };
    check.checkInt(3, o.maxTaskAssign(tasks, workers, 1, 5));

    tasks = { 5 };
    workers = { 5 };
    check.checkInt(1, o.maxTaskAssign(tasks, workers, 0, 0));

    tasks = { 5 };
    workers = { 4 };
    check.checkInt(0, o.maxTaskAssign(tasks, workers, 0, 0));
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
