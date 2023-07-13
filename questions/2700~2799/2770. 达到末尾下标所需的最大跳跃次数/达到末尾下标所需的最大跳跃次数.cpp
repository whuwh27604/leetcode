/* 达到末尾下标所需的最大跳跃次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始、由 n 个整数组成的数组 nums 和一个整数 target 。

你的初始位置在下标 0 。在一步操作中，你可以从下标 i 跳跃到任意满足下述条件的下标 j ：

0 <= i < j < n
-target <= nums[j] - nums[i] <= target
返回到达下标 n - 1 处所需的 最大跳跃次数 。

如果无法到达下标 n - 1 ，返回 -1 。



示例 1：

输入：nums = [1,3,6,4,1,2], target = 2
输出：3
解释：要想以最大跳跃次数从下标 0 到下标 n - 1 ，可以按下述跳跃序列执行操作：
- 从下标 0 跳跃到下标 1 。
- 从下标 1 跳跃到下标 3 。
- 从下标 3 跳跃到下标 5 。
可以证明，从 0 到 n - 1 的所有方案中，不存在比 3 步更长的跳跃序列。因此，答案是 3 。
示例 2：

输入：nums = [1,3,6,4,1,2], target = 3
输出：5
解释：要想以最大跳跃次数从下标 0 到下标 n - 1 ，可以按下述跳跃序列执行操作：
- 从下标 0 跳跃到下标 1 。
- 从下标 1 跳跃到下标 2 。
- 从下标 2 跳跃到下标 3 。
- 从下标 3 跳跃到下标 4 。
- 从下标 4 跳跃到下标 5 。
可以证明，从 0 到 n - 1 的所有方案中，不存在比 5 步更长的跳跃序列。因此，答案是 5 。
示例 3：

输入：nums = [1,3,6,4,1,2], target = 0
输出：-1
解释：可以证明不存在从 0 到 n - 1 的跳跃序列。因此，答案是 -1 。


提示：

2 <= nums.length == n <= 1000
-109 <= nums[i] <= 109
0 <= target <= 2 * 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n - 1] = 0;

        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (dp[j] != -1 && abs(nums[j] - nums[i]) <= target) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        return dp[0];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,6,4,1,2 };
    check.checkInt(3, o.maximumJumps(nums, 2));

    nums = { 1,3,6,4,1,2 };
    check.checkInt(5, o.maximumJumps(nums, 3));

    nums = { 1,3,6,4,1,2 };
    check.checkInt(-1, o.maximumJumps(nums, 0));
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
