/* 完成旅途的最少时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 time ，其中 time[i] 表示第 i 辆公交车完成 一趟旅途 所需要花费的时间。

每辆公交车可以 连续 完成多趟旅途，也就是说，一辆公交车当前旅途完成后，可以 立马开始 下一趟旅途。每辆公交车 独立 运行，也就是说可以同时有多辆公交车在运行且互不影响。

给你一个整数 totalTrips ，表示所有公交车 总共 需要完成的旅途数目。请你返回完成 至少 totalTrips 趟旅途需要花费的 最少 时间。

 

示例 1：

输入：time = [1,2,3], totalTrips = 5
输出：3
解释：
- 时刻 t = 1 ，每辆公交车完成的旅途数分别为 [1,0,0] 。
  已完成的总旅途数为 1 + 0 + 0 = 1 。
- 时刻 t = 2 ，每辆公交车完成的旅途数分别为 [2,1,0] 。
  已完成的总旅途数为 2 + 1 + 0 = 3 。
- 时刻 t = 3 ，每辆公交车完成的旅途数分别为 [3,1,1] 。
  已完成的总旅途数为 3 + 1 + 1 = 5 。
所以总共完成至少 5 趟旅途的最少时间为 3 。
示例 2：

输入：time = [2], totalTrips = 1
输出：2
解释：
只有一辆公交车，它将在时刻 t = 2 完成第一趟旅途。
所以完成 1 趟旅途的最少时间为 2 。
 

提示：

1 <= time.length <= 105
1 <= time[i], totalTrips <= 107

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-time-to-complete-trips
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = *min_element(time.begin(), time.end()), right = left * totalTrips, minTime = 0;

        while (left <= right) {
            long long middle = (left + right) / 2;

            if (check(time, totalTrips, middle)) {
                minTime = middle;
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }

        return minTime;
    }

    bool check(vector<int>& time, int totalTrips, long long totalTime) {
        long long trips = 0;

        for (int t : time) {
            trips += totalTime / t;

            if (trips >= totalTrips) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> time = { 1,2,3 };
    check.checkLongLong(3, o.minimumTime(time, 5));

    time = { 2 };
    check.checkLongLong(2, o.minimumTime(time, 1));

    time = { 1,2,3,2,3,5 };
    check.checkLongLong(3488373, o.minimumTime(time, 10000000));

    time = { 3,3,8 };
    check.checkLongLong(9, o.minimumTime(time, 6));
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
