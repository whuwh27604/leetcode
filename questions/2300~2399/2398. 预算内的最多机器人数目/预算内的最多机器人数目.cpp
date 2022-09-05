/* 预算内的最多机器人数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有 n 个机器人，给你两个下标从 0 开始的整数数组 chargeTimes 和 runningCosts ，两者长度都为 n 。第 i 个机器人充电时间为 chargeTimes[i] 单位时间，花费 runningCosts[i] 单位时间运行。再给你一个整数 budget 。

运行 k 个机器人 总开销 是 max(chargeTimes) + k * sum(runningCosts) ，其中 max(chargeTimes) 是这 k 个机器人中最大充电时间，sum(runningCosts) 是这 k 个机器人的运行时间之和。

请你返回在 不超过 budget 的前提下，你 最多 可以 连续 运行的机器人数目为多少。

 

示例 1：

输入：chargeTimes = [3,6,1,3,4], runningCosts = [2,1,3,4,5], budget = 25
输出：3
解释：
可以在 budget 以内运行所有单个机器人或者连续运行 2 个机器人。
选择前 3 个机器人，可以得到答案最大值 3 。总开销是 max(3,6,1) + 3 * sum(2,1,3) = 6 + 3 * 6 = 24 ，小于 25 。
可以看出无法在 budget 以内连续运行超过 3 个机器人，所以我们返回 3 。
示例 2：

输入：chargeTimes = [11,12,19], runningCosts = [10,8,7], budget = 19
输出：0
解释：即使运行任何一个单个机器人，还是会超出 budget，所以我们返回 0 。
 

提示：

chargeTimes.length == runningCosts.length == n
1 <= n <= 5 * 104
1 <= chargeTimes[i], runningCosts[i] <= 105
1 <= budget <= 1015

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-number-of-robots-within-budget
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int left = 0, right, size = chargeTimes.size(), maxConsecutive = 0;
        long long sum = 0;
        map<int, int> chargeTimeCount;

        for (right = 0; right < size; ++right) {
            ++chargeTimeCount[chargeTimes[right]];
            sum += runningCosts[right];

            while (!chargeTimeCount.empty() && chargeTimeCount.rbegin()->first + ((long long)right - left + 1) * sum > budget) {
                if (--chargeTimeCount[chargeTimes[left]] == 0) {
                    chargeTimeCount.erase(chargeTimes[left]);
                }

                sum -= runningCosts[left++];
            }

            maxConsecutive = max(maxConsecutive, right - left + 1);
        }

        return maxConsecutive;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> chargeTimes = { 1,100,1,100 };
    vector<int> runningCosts = { 1,100,1,100 };
    check.checkInt(1, o.maximumRobots(chargeTimes, runningCosts, 5));

    chargeTimes = { 100,1,1,100 };
    runningCosts = { 100,1,1,100 };
    check.checkInt(2, o.maximumRobots(chargeTimes, runningCosts, 5));

    chargeTimes = { 3,6,1,3,4 };
    runningCosts = { 2,1,3,4,5 };
    check.checkInt(3, o.maximumRobots(chargeTimes, runningCosts, 25));

    chargeTimes = { 11,12,19 };
    runningCosts = { 10,8,7 };
    check.checkInt(0, o.maximumRobots(chargeTimes, runningCosts, 19));
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
