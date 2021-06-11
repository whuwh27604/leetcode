/* 完成所有任务的最少初始能量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个任务数组 tasks ，其中 tasks[i] = [actuali, minimumi] ：

actuali 是完成第 i 个任务 需要耗费 的实际能量。
minimumi 是开始第 i 个任务前需要达到的最低能量。
比方说，如果任务为 [10, 12] 且你当前的能量为 11 ，那么你不能开始这个任务。如果你当前的能量为 13 ，你可以完成这个任务，且完成它后剩余能量为 3 。

你可以按照 任意顺序 完成任务。

请你返回完成所有任务的 最少 初始能量。

 

示例 1：

输入：tasks = [[1,2],[2,4],[4,8]]
输出：8
解释：
一开始有 8 能量，我们按照如下顺序完成任务：
    - 完成第 3 个任务，剩余能量为 8 - 4 = 4 。
    - 完成第 2 个任务，剩余能量为 4 - 2 = 2 。
    - 完成第 1 个任务，剩余能量为 2 - 1 = 1 。
注意到尽管我们有能量剩余，但是如果一开始只有 7 能量是不能完成所有任务的，因为我们无法开始第 3 个任务。
示例 2：

输入：tasks = [[1,3],[2,4],[10,11],[10,12],[8,9]]
输出：32
解释：
一开始有 32 能量，我们按照如下顺序完成任务：
    - 完成第 1 个任务，剩余能量为 32 - 1 = 31 。
    - 完成第 2 个任务，剩余能量为 31 - 2 = 29 。
    - 完成第 3 个任务，剩余能量为 29 - 10 = 19 。
    - 完成第 4 个任务，剩余能量为 19 - 10 = 9 。
    - 完成第 5 个任务，剩余能量为 9 - 8 = 1 。
示例 3：

输入：tasks = [[1,7],[2,8],[3,9],[4,10],[5,11],[6,12]]
输出：27
解释：
一开始有 27 能量，我们按照如下顺序完成任务：
    - 完成第 5 个任务，剩余能量为 27 - 5 = 22 。
    - 完成第 2 个任务，剩余能量为 22 - 2 = 20 。
    - 完成第 3 个任务，剩余能量为 20 - 3 = 17 。
    - 完成第 1 个任务，剩余能量为 17 - 1 = 16 。
    - 完成第 4 个任务，剩余能量为 16 - 4 = 12 。
    - 完成第 6 个任务，剩余能量为 12 - 6 = 6 。
 

提示：

1 <= tasks.length <= 105
1 <= actual​i <= minimumi <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-initial-energy-to-finish-tasks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[1] - v1[0] > v2[1] - v2[0];  // 按照minimum-actual排序，大的任务优先执行
}

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), vectorCompare);

        int minEffort = 0, actualSum = 0;

        for (auto& task : tasks) {
            minEffort = max(minEffort, actualSum + task[1]);
            actualSum += task[0];
        }

        return minEffort;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> tasks = { {1,2},{2,4},{4,8} };
    check.checkInt(8, o.minimumEffort(tasks));

    tasks = { {1,3},{2,4},{10,11},{10,12},{8,9} };
    check.checkInt(32, o.minimumEffort(tasks));

    tasks = { {1,7},{2,8},{3,9},{4,10},{5,11},{6,12} };
    check.checkInt(27, o.minimumEffort(tasks));

    tasks = { {1,10000},{1,10000},{2,3} };
    check.checkInt(10001, o.minimumEffort(tasks));
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
