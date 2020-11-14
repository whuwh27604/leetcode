/* 课程表 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。

可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。

示例 1:

输入: 2, [[1,0]]
输出: [0,1]
解释: 总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
示例 2:

输入: 4, [[1,0],[2,0],[3,1],[3,2]]
输出: [0,1,2,3] or [0,2,1,3]
解释: 总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
     因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
说明:

输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
你可以假定输入的先决条件中没有重复的边。
提示:

这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
拓扑排序也可以通过 BFS 完成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/course-schedule-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int* indegrees = new int[numCourses]();
        int totolIndegrees = 0;
        unordered_map<int, vector<int>> coursesAfter;
        vector<int> orderedCourses;

        for (vector<int>& prerequisite : prerequisites) {
            indegrees[prerequisite[0]]++;
            totolIndegrees++;
            coursesAfter[prerequisite[1]].push_back(prerequisite[0]);
        }

        list<int> zeroIndegreeCourses;
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                zeroIndegreeCourses.push_back(i);
            }
        }

        while (!zeroIndegreeCourses.empty()) {
            int courseIndex = zeroIndegreeCourses.front();
            zeroIndegreeCourses.pop_front();
            orderedCourses.push_back(courseIndex);

            for (int courseAfterIndex : coursesAfter[courseIndex]) {
                indegrees[courseAfterIndex]--;
                totolIndegrees--;
                if (indegrees[courseAfterIndex] == 0) {
                    zeroIndegreeCourses.push_back(courseAfterIndex);
                }
            }
        }

        delete[] indegrees;

        if (totolIndegrees == 0) {
            return orderedCourses;
        }
        else {
            return {};
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> prerequisites = { {1,0} };
    vector<int> actual = o.findOrder(2, prerequisites);
    vector<int> expected = { 0,1 };
    check.checkIntVector(expected, actual);

    prerequisites = { {1,0},{2,0},{3,1},{3,2} };
    actual = o.findOrder(4, prerequisites);
    expected = { 0,1,2,3 };
    check.checkIntVector(expected, actual);

    prerequisites = { {1,0},{0,1} };
    actual = o.findOrder(2, prerequisites);
    expected = {  };
    check.checkIntVector(expected, actual);

    prerequisites = {  };
    actual = o.findOrder(4, prerequisites);
    expected = { 0,1,2,3 };
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
