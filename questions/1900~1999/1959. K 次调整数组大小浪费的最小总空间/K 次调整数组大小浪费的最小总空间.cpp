/* K 次调整数组大小浪费的最小总空间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你正在设计一个动态数组。给你一个下标从 0 开始的整数数组 nums ，其中 nums[i] 是 i 时刻数组中的元素数目。除此以外，你还有一个整数 k ，表示你可以 调整 数组大小的 最多 次数（每次都可以调整成 任意 大小）。

t 时刻数组的大小 sizet 必须大于等于 nums[t] ，因为数组需要有足够的空间容纳所有元素。t 时刻 浪费的空间 为 sizet - nums[t] ，总 浪费空间为满足 0 <= t < nums.length 的每一个时刻 t 浪费的空间 之和 。

在调整数组大小不超过 k 次的前提下，请你返回 最小总浪费空间 。

注意：数组最开始时可以为 任意大小 ，且 不计入 调整大小的操作次数。

 

示例 1：

输入：nums = [10,20], k = 0
输出：10
解释：size = [20,20].
我们可以让数组初始大小为 20 。
总浪费空间为 (20 - 10) + (20 - 20) = 10 。
示例 2：

输入：nums = [10,20,30], k = 1
输出：10
解释：size = [20,20,30].
我们可以让数组初始大小为 20 ，然后时刻 2 调整大小为 30 。
总浪费空间为 (20 - 10) + (20 - 20) + (30 - 30) = 10 。
示例 3：

输入：nums = [10,20,15,30,20], k = 2
输出：15
解释：size = [10,20,20,30,30].
我们可以让数组初始大小为 10 ，时刻 1 调整大小为 20 ，时刻 3 调整大小为 30 。
总浪费空间为 (10 - 10) + (20 - 20) + (20 - 15) + (30 - 30) + (30 - 20) = 15 。
 

提示：

1 <= nums.length <= 200
1 <= nums[i] <= 106
0 <= k <= nums.length - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-total-space-wasted-with-k-resizing-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        /* 令dp[i][j]表示nums[0,i]调整j次的最小浪费，那么对于dp[i+1][j]，可以枚举最后一次调整的长度，将nums[0,i+1]划分为[0,s]和(s,i+1]
           区间[0,s]可以调整j-1次，所以浪费是dp[s][j-1]。区间(s,i+1]调整一次，浪费是max(s,i+1]*size(s,i+1]-sum(s,i+1]
           最终，dp[i+1][j] = min(dp[s][j-1] + max(s,i+1]*size(s,i+1]-sum(s,i+1]) */
        int i, j, s, size = nums.size();
        vector<vector<int>> dp(size, vector<int>(k + 1, INT_MAX)), wasted(size, vector<int>(size, 0));
        dp[0] = vector<int>(k + 1, 0);  // nums[0]不浪费任何空间

        getWasted(nums, wasted);

        for (i = 1; i < size; ++i) {
            dp[i][0] = wasted[0][i];  // nums[0,i]调整0次，浪费的空间就是wasted[0][i]

            for (j = 1; j <= k; ++j) {
                for (s = 0; s < i; ++s) {
                    dp[i][j] = min(dp[i][j], dp[s][j - 1] + wasted[s + 1][i]);
                }
            }
        }

        return dp[size - 1][k];
    }

    void getWasted(vector<int>& nums, vector<vector<int>>& wasted) {
        int i, j, size = nums.size();

        for (i = 0; i < size - 1; ++i) {
            int sum = nums[i], maximum = nums[i];

            for (j = i + 1; j < size; ++j) {
                sum += nums[j];
                maximum = max(maximum, nums[j]);
                wasted[i][j] = maximum * (j - i + 1) - sum;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 10,20 };
    check.checkInt(10, o.minSpaceWastedKResizing(nums, 0));

    nums = { 10,20,30 };
    check.checkInt(10, o.minSpaceWastedKResizing(nums, 1));

    nums = { 10,20,15,30,20 };
    check.checkInt(15, o.minSpaceWastedKResizing(nums, 2));

    nums = { 10 };
    check.checkInt(0, o.minSpaceWastedKResizing(nums, 0));

    nums = { 1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1 };
    check.checkInt(114, o.minSpaceWastedKResizing(nums, 10));
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
