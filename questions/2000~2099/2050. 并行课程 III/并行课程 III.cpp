/* 并行课程 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n ，表示有 n 节课，课程编号从 1 到 n 。同时给你一个二维整数数组 relations ，其中 relations[j] = [prevCoursej, nextCoursej] ，表示课程 prevCoursej 必须在课程 nextCoursej 之前 完成（先修课的关系）。同时给你一个下标从 0 开始的整数数组 time ，其中 time[i] 表示完成第 (i+1) 门课程需要花费的 月份 数。

请你根据以下规则算出完成所有课程所需要的 最少 月份数：

如果一门课的所有先修课都已经完成，你可以在 任意 时间开始这门课程。
你可以 同时 上 任意门课程 。
请你返回完成所有课程所需要的 最少 月份数。

注意：测试数据保证一定可以完成所有课程（也就是先修课的关系构成一个有向无环图）。

 

示例 1:



输入：n = 3, relations = [[1,3],[2,3]], time = [3,2,5]
输出：8
解释：上图展示了输入数据所表示的先修关系图，以及完成每门课程需要花费的时间。
你可以在月份 0 同时开始课程 1 和 2 。
课程 1 花费 3 个月，课程 2 花费 2 个月。
所以，最早开始课程 3 的时间是月份 3 ，完成所有课程所需时间为 3 + 5 = 8 个月。
示例 2：



输入：n = 5, relations = [[1,5],[2,5],[3,5],[3,4],[4,5]], time = [1,2,3,4,5]
输出：12
解释：上图展示了输入数据所表示的先修关系图，以及完成每门课程需要花费的时间。
你可以在月份 0 同时开始课程 1 ，2 和 3 。
在月份 1，2 和 3 分别完成这三门课程。
课程 4 需在课程 3 之后开始，也就是 3 个月后。课程 4 在 3 + 4 = 7 月完成。
课程 5 需在课程 1，2，3 和 4 之后开始，也就是在 max(1,2,3,7) = 7 月开始。
所以完成所有课程所需的最少时间为 7 + 5 = 12 个月。
 

提示：

1 <= n <= 5 * 104
0 <= relations.length <= min(n * (n - 1) / 2, 5 * 104)
relations[j].length == 2
1 <= prevCoursej, nextCoursej <= n
prevCoursej != nextCoursej
所有的先修课程对 [prevCoursej, nextCoursej] 都是 互不相同 的。
time.length == n
1 <= time[i] <= 104
先修课程图是一个有向无环图。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/parallel-courses-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> indegrees(n + 1, 0), minTimes(n + 1, 0);
        vector<vector<int>> afters(n + 1);
        queue<int> courses;

        build(relations, afters, indegrees);
        init(n, courses, indegrees, time, minTimes);
        topSort(courses, indegrees, afters, time, minTimes);

        return *max_element(minTimes.begin(), minTimes.end());
    }

    void build(vector<vector<int>>& relations, vector<vector<int>>& afters, vector<int>& indegrees) {
        for (auto& relation : relations) {
            afters[relation[0]].push_back(relation[1]);
            ++indegrees[relation[1]];
        }
    }

    void init(int n, queue<int>& courses, vector<int>& indegrees, vector<int>& time, vector<int>& minTimes) {
        for (int course = 1; course <= n; ++course) {
            if (indegrees[course] == 0) {
                courses.push(course);
                minTimes[course] = time[course - 1];
            }
        }
    }

    void topSort(queue<int>& courses, vector<int>& indegrees, vector<vector<int>>& afters, vector<int>& time, vector<int>& minTimes) {
        while (!courses.empty()) {
            int course = courses.front();
            courses.pop();

            for (int after : afters[course]) {
                if (--indegrees[after] == 0) {
                    courses.push(after);
                }

                minTimes[after] = max(minTimes[after], minTimes[course] + time[after - 1]);
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> relations = { {1,3},{2,3} };
    vector<int> time = { 3,2,5 };
    check.checkInt(8, o.minimumTime(3, relations, time));

    relations = { {1,5},{2,5},{3,5},{3,4},{4,5} };
    time = { 1,2,3,4,5 };
    check.checkInt(12, o.minimumTime(5, relations, time));

    relations = {  };
    time = { 5 };
    check.checkInt(5, o.minimumTime(1, relations, time));

    relations = { {35,25},{34,24},{33,23},{32,22},{31,21},{24,14},{23,13},{22,12},{21,11},{13,3},{12,2},{11,1} };
    time = { 1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10 };
    check.checkInt(12, o.minimumTime(50, relations, time));
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
