/* 满足目标工作时长的员工数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
公司里共有 n 名员工，按从 0 到 n - 1 编号。每个员工 i 已经在公司工作了 hours[i] 小时。

公司要求每位员工工作 至少 target 小时。

给你一个下标从 0 开始、长度为 n 的非负整数数组 hours 和一个非负整数 target 。

请你用整数表示并返回工作至少 target 小时的员工数。



示例 1：

输入：hours = [0,1,2,3,4], target = 2
输出：3
解释：公司要求每位员工工作至少 2 小时。
- 员工 0 工作 0 小时，不满足要求。
- 员工 1 工作 1 小时，不满足要求。
- 员工 2 工作 2 小时，满足要求。
- 员工 3 工作 3 小时，满足要求。
- 员工 4 工作 4 小时，满足要求。
共有 3 位满足要求的员工。
示例 2：

输入：hours = [5,1,4,2,2], target = 6
输出：0
解释：公司要求每位员工工作至少 6 小时。
共有 0 位满足要求的员工。


提示：

1 <= n == hours.length <= 50
0 <= hours[i], target <= 105
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count = 0;

        for (int hour : hours) {
            if (hour >= target) {
                ++count;
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> hours = { 0,1,2,3,4 };
    check.checkInt(3, o.numberOfEmployeesWhoMetTarget(hours, 2));

    hours = { 5,1,4,2,2 };
    check.checkInt(0, o.numberOfEmployeesWhoMetTarget(hours, 6));
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
