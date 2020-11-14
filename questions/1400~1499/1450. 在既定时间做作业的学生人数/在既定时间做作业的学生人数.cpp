/* 在既定时间做作业的学生人数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数数组 startTime（开始时间）和 endTime（结束时间），并指定一个整数 queryTime 作为查询时间。

已知，第 i 名学生在 startTime[i] 时开始写作业并于 endTime[i] 时完成作业。

请返回在查询时间 queryTime 时正在做作业的学生人数。形式上，返回能够使 queryTime 处于区间 [startTime[i], endTime[i]]（含）的学生人数。

 

示例 1：

输入：startTime = [1,2,3], endTime = [3,2,7], queryTime = 4
输出：1
解释：一共有 3 名学生。
第一名学生在时间 1 开始写作业，并于时间 3 完成作业，在时间 4 没有处于做作业的状态。
第二名学生在时间 2 开始写作业，并于时间 2 完成作业，在时间 4 没有处于做作业的状态。
第二名学生在时间 3 开始写作业，预计于时间 7 完成作业，这是是唯一一名在时间 4 时正在做作业的学生。
示例 2：

输入：startTime = [4], endTime = [4], queryTime = 4
输出：1
解释：在查询时间只有一名学生在做作业。
示例 3：

输入：startTime = [4], endTime = [4], queryTime = 5
输出：0
示例 4：

输入：startTime = [1,1,1,1], endTime = [1,3,2,4], queryTime = 7
输出：0
示例 5：

输入：startTime = [9,8,7,6,5,4,3,2,1], endTime = [10,10,10,10,10,10,10,10,10], queryTime = 5
输出：5
 

提示：

startTime.length == endTime.length
1 <= startTime.length <= 100
1 <= startTime[i] <= endTime[i] <= 1000
1 <= queryTime <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-students-doing-homework-at-a-given-time
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int busyStudents = 0;

        for (unsigned int i = 0; i < startTime.size(); i++) {
            if ((startTime[i] <= queryTime) && (queryTime <= endTime[i])) {
                busyStudents++;
            }
        }

        return busyStudents;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> startTime = { 1,2,3 };
    vector<int> endTime = { 3,2,7 };
    check.checkInt(1, o.busyStudent(startTime, endTime, 4));

    startTime = { 4 };
    endTime = { 4 };
    check.checkInt(1, o.busyStudent(startTime, endTime, 4));

    startTime = { 4 };
    endTime = { 5 };
    check.checkInt(1, o.busyStudent(startTime, endTime, 4));

    startTime = { 4 };
    endTime = { 5 };
    check.checkInt(1, o.busyStudent(startTime, endTime, 5));

    startTime = { 4 };
    endTime = { 4 };
    check.checkInt(0, o.busyStudent(startTime, endTime, 5));

    startTime = { 1,1,1,1 };
    endTime = { 1,3,2,4 };
    check.checkInt(0, o.busyStudent(startTime, endTime, 7));

    startTime = { 9,8,7,6,5,4,3,2,1 };
    endTime = { 10,10,10,10,10,10,10,10,10 };
    check.checkInt(5, o.busyStudent(startTime, endTime, 5));
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
