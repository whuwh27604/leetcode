/* 课程表 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
这里有 n 门不同的在线课程，按从 1 到 n 编号。给你一个数组 courses ，其中 courses[i] = [durationi, lastDayi] 表示第 i 门课将会 持续 上 durationi 天课，并且必须在不晚于 lastDayi 的时候完成。

你的学期从第 1 天开始。且不能同时修读两门及两门以上的课程。

返回你最多可以修读的课程数目。

 

示例 1：

输入：courses = [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
输出：3
解释：
这里一共有 4 门课程，但是你最多可以修 3 门：
首先，修第 1 门课，耗费 100 天，在第 100 天完成，在第 101 天开始下门课。
第二，修第 3 门课，耗费 1000 天，在第 1100 天完成，在第 1101 天开始下门课程。
第三，修第 2 门课，耗时 200 天，在第 1300 天完成。
第 4 门课现在不能修，因为将会在第 3300 天完成它，这已经超出了关闭日期。
示例 2：

输入：courses = [[1,2]]
输出：1
示例 3：

输入：courses = [[3,2],[4,3]]
输出：0
 

提示:

1 <= courses.length <= 104
1 <= durationi, lastDayi <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/course-schedule-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[1] < v2[1];  // 按照lastDay升序排序
}

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> scheduled;
        int endDay = 0;

        sort(courses.begin(), courses.end(), vectorCompare);

        for (auto& course : courses) {
            if (endDay + course[0] <= course[1]) {  // 如果这门课可以安排，则先安排上
                endDay += course[0];
                scheduled.push(course[0]);
            }
            else {  // 这门课无法安排，那么把已经安排的课里面耗时最大的换掉，这样endDay更早，后面的课有更多可能可以安排
                if (!scheduled.empty() && course[0] < scheduled.top()) {
                    endDay += (course[0] - scheduled.top());
                    scheduled.pop();
                    scheduled.push(course[0]);
                }
            }
        }

        return (int)scheduled.size();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> courses = { {100,200},{200,1300},{1000,1250},{2000,3200} };
    check.checkInt(3, o.scheduleCourse(courses));

    courses = { {1,2} };
    check.checkInt(1, o.scheduleCourse(courses));

    courses = { {1,2},{2,3} };
    check.checkInt(2, o.scheduleCourse(courses));

    courses = { {3,2},{4,3} };
    check.checkInt(0, o.scheduleCourse(courses));

    courses = { {4,6},{5,5},{2,6} };
    check.checkInt(2, o.scheduleCourse(courses));

    courses = { {100,2},{32,50} };
    check.checkInt(1, o.scheduleCourse(courses));

    courses = { {7,17},{3,12},{10,20},{9,10},{5,20},{10,19},{4,18} };
    check.checkInt(4, o.scheduleCourse(courses));

    courses = { {100,200},{11,201},{90,201},{90,201},{10,201},{200,1300},{1000,1250},{2000,3200} };
    check.checkInt(6, o.scheduleCourse(courses));

    courses = { {9,10},{3,12},{7,17},{4,18},{5,20},{10,19},{10,20} };
    check.checkInt(4, o.scheduleCourse(courses));
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
