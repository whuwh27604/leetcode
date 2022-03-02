/* 完成比赛的最少时间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的二维整数数组 tires ，其中 tires[i] = [fi, ri] 表示第 i 种轮胎如果连续使用，第 x 圈需要耗时 fi * ri(x-1) 秒。

比方说，如果 fi = 3 且 ri = 2 ，且一直使用这种类型的同一条轮胎，那么该轮胎完成第 1 圈赛道耗时 3 秒，完成第 2 圈耗时 3 * 2 = 6 秒，完成第 3 圈耗时 3 * 22 = 12 秒，依次类推。
同时给你一个整数 changeTime 和一个整数 numLaps 。

比赛总共包含 numLaps 圈，你可以选择 任意 一种轮胎开始比赛。每一种轮胎都有 无数条 。每一圈后，你可以选择耗费 changeTime 秒 换成 任意一种轮胎（也可以换成当前种类的新轮胎）。

请你返回完成比赛需要耗费的 最少 时间。

 

示例 1：

输入：tires = [[2,3],[3,4]], changeTime = 5, numLaps = 4
输出：21
解释：
第 1 圈：使用轮胎 0 ，耗时 2 秒。
第 2 圈：继续使用轮胎 0 ，耗时 2 * 3 = 6 秒。
第 3 圈：耗费 5 秒换一条新的轮胎 0 ，然后耗时 2 秒完成这一圈。
第 4 圈：继续使用轮胎 0 ，耗时 2 * 3 = 6 秒。
总耗时 = 2 + 6 + 5 + 2 + 6 = 21 秒。
完成比赛的最少时间为 21 秒。
示例 2：

输入：tires = [[1,10],[2,2],[3,4]], changeTime = 6, numLaps = 5
输出：25
解释：
第 1 圈：使用轮胎 1 ，耗时 2 秒。
第 2 圈：继续使用轮胎 1 ，耗时 2 * 2 = 4 秒。
第 3 圈：耗时 6 秒换一条新的轮胎 1 ，然后耗时 2 秒完成这一圈。
第 4 圈：继续使用轮胎 1 ，耗时 2 * 2 = 4 秒。
第 5 圈：耗时 6 秒换成轮胎 0 ，然后耗时 1 秒完成这一圈。
总耗时 = 2 + 4 + 6 + 2 + 4 + 6 + 1 = 25 秒。
完成比赛的最少时间为 25 秒。
 

提示：

1 <= tires.length <= 105
tires[i].length == 2
1 <= fi, changeTime <= 105
2 <= ri <= 105
1 <= numLaps <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-time-to-finish-the-race
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        int maxFinishTime = (getMinF(tires) + changeTime) * numLaps;

        vector<int> minNoChangeTimes;
        getFinishTimeNoChange(tires, maxFinishTime, minNoChangeTimes);

        return getMinFinishTime(minNoChangeTimes, changeTime, numLaps);
    }

    int getMinF(vector<vector<int>>& tires) {
        int minF = INT_MAX;

        for (auto& tire : tires) {
            minF = min(minF, tire[0]);
        }

        return minF;
    }

    void getFinishTimeNoChange(vector<vector<int>>& tires, int maxFinishTime, vector<int>& minNoChangeTimes) {
        for (int i = 0; i < (int)tires.size(); ++i) {
            long long time = tires[i][0], total = time;
            int lap = 0;

            while (total <= maxFinishTime) {
                if (lap == minNoChangeTimes.size()) {
                    minNoChangeTimes.push_back((int)total);
                }
                else {
                    minNoChangeTimes[lap] = min(minNoChangeTimes[lap], (int)total);
                }

                time *= tires[i][1];
                total += time;
                lap += 1;
            }
        }
    }

    int getMinFinishTime(vector<int>& minNoChangeTimes, int changeTime, int numLaps) {
        vector<int> dp(numLaps + 1, INT_MAX);

        for (int lap = 1; lap <= numLaps; ++lap) {
            if (lap <= (int)minNoChangeTimes.size()) {
                dp[lap] = minNoChangeTimes[lap - 1];
            }

            for (int change = 1; change < lap; ++change) {
                dp[lap] = min(dp[lap], dp[change] + changeTime + dp[lap - change]);
            }
        }

        return dp[numLaps];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> tires = { {2,3},{3,4} };
    check.checkInt(21, o.minimumFinishTime(tires, 5, 4));

    tires = { {1,10},{2,2},{3,4} };
    check.checkInt(25, o.minimumFinishTime(tires, 6, 5));

    tires = { {3,4},{84,2},{63,8},{72,8},{82,7},{83,6},{23,2},{77,5},{51,10},{28,2},{47,9},{8,3},{48,3},{56,3},{8,10},{66,6},{92,9},{44,6},{23,5},{5,6},{86,9},{13,10},{91,3},{2,2},{8,4},{67,8},{63,6},{52,5},{42,10},{3,9},{66,5},{35,10},{63,6},{65,6},{22,8},{40,9},{43,4},{73,9},{81,5},{32,2},{30,5},{80,9},{50,4},{35,4},{52,7},{11,5},{7,8},{68,3},{54,8},{49,8} };
    check.checkInt(2526, o.minimumFinishTime(tires, 90, 87));
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
