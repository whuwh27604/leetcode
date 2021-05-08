/* 完成所有工作的最短时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 jobs ，其中 jobs[i] 是完成第 i 项工作要花费的时间。

请你将这些工作分配给 k 位工人。所有工作都应该分配给工人，且每项工作只能分配给一位工人。工人的 工作时间 是完成分配给他们的所有工作花费时间的总和。请你设计一套最佳的工作分配方案，使工人的 最大工作时间 得以 最小化 。

返回分配方案中尽可能 最小 的 最大工作时间 。

 

示例 1：

输入：jobs = [3,2,3], k = 3
输出：3
解释：给每位工人分配一项工作，最大工作时间是 3 。
示例 2：

输入：jobs = [1,2,4,7,8], k = 2
输出：11
解释：按下述方式分配工作：
1 号工人：1、2、8（工作时间 = 1 + 2 + 8 = 11）
2 号工人：4、7（工作时间 = 4 + 7 = 11）
最大工作时间是 11 。
 

提示：

1 <= k <= jobs.length <= 12
1 <= jobs[i] <= 107

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-minimum-time-to-finish-all-jobs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(), jobs.end(), greater<int>());  // 先尝试大的可以尽快失败

        int left = jobs[0], right = getSum(jobs);

        while (left <= right) {
            int middle = (left + right) / 2;
            vector<int> workloads(k, 0);

            if (canFinish(jobs, workloads, 0, middle)) {
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }

        return left;
    }

    int getSum(vector<int>& jobs) {
        int sum = 0;

        for (int job : jobs) {
            sum += job;
        }

        return sum;
    }

    bool canFinish(vector<int>& jobs, vector<int>& workloads, int index, int maxTime) {
        if (index >= (int)jobs.size()) {
            return true;
        }

        int job = jobs[index];

        for (int& workload : workloads) {
            if (workload + job <= maxTime) {
                workload += job;  // 该job分配给当前工人

                if (canFinish(jobs, workloads, index + 1, maxTime)) {
                    return true;
                }

                workload -= job;  // 不能完成，回溯
            }

            /* 1、workload == 0意味着是一个全新的工人，该任务分配给他不能完成，则分配给其他人一样也不能完成
               2、workload + job == maxTime是一个极限情况，该任务分配给其他人最终完成的可能性更小 */
            if (workload == 0 || workload + job == maxTime) {
                break;
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> jobs = { 3,2,3 };
    check.checkInt(3, o.minimumTimeRequired(jobs, 3));

    jobs = { 1,2,4,7,8 };
    check.checkInt(11, o.minimumTimeRequired(jobs, 2));

    jobs = { 4,4,3,3,3,3,3,3,1 };
    check.checkInt(9, o.minimumTimeRequired(jobs, 3));

    jobs = { 4,4,4,3,3,3,3,3,3 };
    check.checkInt(10, o.minimumTimeRequired(jobs, 3));

    jobs = { 254,256,256,254,251,256,254,253,255,251,251,255 };
    check.checkInt(504, o.minimumTimeRequired(jobs, 10));
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
