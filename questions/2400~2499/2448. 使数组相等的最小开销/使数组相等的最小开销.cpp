/* 使数组相等的最小开销.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的数组 nums 和 cost ，分别包含 n 个 正 整数。

你可以执行下面操作 任意 次：

将 nums 中 任意 元素增加或者减小 1 。
对第 i 个元素执行一次操作的开销是 cost[i] 。

请你返回使 nums 中所有元素 相等 的 最少 总开销。

 

示例 1：

输入：nums = [1,3,5,2], cost = [2,3,1,14]
输出：8
解释：我们可以执行以下操作使所有元素变为 2 ：
- 增加第 0 个元素 1 次，开销为 2 。
- 减小第 1 个元素 1 次，开销为 3 。
- 减小第 2 个元素 3 次，开销为 1 + 1 + 1 = 3 。
总开销为 2 + 3 + 3 = 8 。
这是最小开销。
示例 2：

输入：nums = [2,2,2,2,2], cost = [4,2,8,1,3]
输出：0
解释：数组中所有元素已经全部相等，不需要执行额外的操作。
 

提示：

n == nums.length == cost.length
1 <= n <= 105
1 <= nums[i], cost[i] <= 106

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-cost-to-make-array-equal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int size = nums.size(), low = 0, high = 1000001;
        long long leastCost = LLONG_MAX;

        while (low <= high) {
            int target = (low + high) / 2;
            long long cost1 = getCost(nums, cost, target);
            long long cost2 = getCost(nums, cost, target + 1);

            if (cost1 > cost2) {  // cost在变小，应该让target变大
                leastCost = min(leastCost, cost2);
                low = target + 1;
            }
            else {  // cost在变大，应该让target变小
                leastCost = min(leastCost, cost1);
                high = target - 1;
            }
        }

        return leastCost;
    }

    long long getCost(vector<int>& nums, vector<int>& cost, int target) {
        long long totalCost = 0;

        for (int i = 0; i < (int)nums.size(); ++i) {
            totalCost += abs((long long)nums[i] - target) * cost[i];
        }

        return totalCost;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,5,2 };
    vector<int> cost = { 2,3,1,14 };
    check.checkLongLong(8, o.minCost(nums, cost));

    nums = { 2,2,2,2,2 };
    cost = { 4,2,8,1,3 };
    check.checkLongLong(0, o.minCost(nums, cost));
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
