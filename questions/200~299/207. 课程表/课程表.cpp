/* 课程表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]

给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？

 

示例 1:

输入: 2, [[1,0]]
输出: true
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
示例 2:

输入: 2, [[1,0],[0,1]]
输出: false
解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
 

提示：

输入的先决条件是由 边缘列表 表示的图形，而不是 邻接矩阵 。详情请参见图的表示法。
你可以假定输入的先决条件中没有重复的边。
1 <= numCourses <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/course-schedule
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int* indegrees = new int[numCourses]();
        int totolIndegrees = 0;
        unordered_map<int, vector<int>> coursesAfter;

        for (vector<int> prerequisite : prerequisites) {
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

            for (int courseAfterIndex : coursesAfter[courseIndex]) {
                indegrees[courseAfterIndex]--;
                totolIndegrees--;
                if (indegrees[courseAfterIndex] == 0) {
                    zeroIndegreeCourses.push_back(courseAfterIndex);
                }
            }
        }

        delete[] indegrees;
        return (totolIndegrees == 0);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> prerequisites = { {1,0} };
    check.checkBool(true, o.canFinish(2, prerequisites));

    prerequisites = { {1,0},{0,1} };
    check.checkBool(false, o.canFinish(2, prerequisites));

    prerequisites = {  };
    check.checkBool(true, o.canFinish(1, prerequisites));

    prerequisites = { {35,25},{34,24},{33,23},{32,22},{31,21},{24,14},{23,13},{22,12},{21,11},{13,3},{12,2},{11,1} };
    check.checkBool(true, o.canFinish(50, prerequisites));
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
