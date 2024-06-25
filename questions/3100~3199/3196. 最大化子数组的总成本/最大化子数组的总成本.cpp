/* 最大化子数组的总成本.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组 nums。

子数组 nums[l..r]（其中 0 <= l <= r < n）的 成本 定义为：

cost(l, r) = nums[l] - nums[l + 1] + ... + nums[r] * (−1)r − l

你的任务是将 nums 分割成若干子数组，使得所有子数组的成本之和 最大化，并确保每个元素 正好 属于一个子数组。

具体来说，如果 nums 被分割成 k 个子数组，且分割点为索引 i1, i2, ..., ik − 1（其中 0 <= i1 < i2 < ... < ik - 1 < n - 1），则总成本为：

cost(0, i1) + cost(i1 + 1, i2) + ... + cost(ik − 1 + 1, n − 1)

返回在最优分割方式下的子数组成本之和的最大值。

注意：如果 nums 没有被分割，即 k = 1，则总成本即为 cost(0, n - 1)。



示例 1：

输入： nums = [1,-2,3,4]

输出： 10

解释：

一种总成本最大化的方法是将 [1, -2, 3, 4] 分割成子数组 [1, -2, 3] 和 [4]。总成本为 (1 + 2 + 3) + 4 = 10。

示例 2：

输入： nums = [1,-1,1,-1]

输出： 4

解释：

一种总成本最大化的方法是将 [1, -1, 1, -1] 分割成子数组 [1, -1] 和 [1, -1]。总成本为 (1 + 1) + (1 + 1) = 4。

示例 3：

输入： nums = [0]

输出： 0

解释：

无法进一步分割数组，因此答案为 0。

示例 4：

输入： nums = [1,-1]

输出： 2

解释：

选择整个数组，总成本为 1 + 1 = 2，这是可能的最大成本。



提示：

1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int size = (int)nums.size();
        long long dpPrev = nums[0], dp = nums[0], dpEvenLast = nums[0], dpOddLast = nums[0];

        for (int i = 1; i < size; ++i) {
            dpEvenLast += ((i & 1) == 0 ? nums[i] : -nums[i]);  // max(dp + last)加入nums[i]
            if ((i & 1) == 0) {
                dpEvenLast = max(dpEvenLast, dpPrev + nums[i]);  // 当前是偶数，dpEvenLast新增nums[i]单独一组的情况
            }
            dpOddLast += ((i & 1) == 0 ? -nums[i] : nums[i]);  // max(dp + last)加入nums[i]
            if ((i & 1) != 0) {
                dpOddLast = max(dpOddLast, dpPrev + nums[i]);  // 当前是奇数，dpOddLast新增nums[i]单独一组的情况
            }
            dp = max(dpEvenLast, dpOddLast);
            dpPrev = dp;
        }

        return dp;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,-2,3,4 };
    check.checkLongLong(10, o.maximumTotalCost(nums));

    nums = { 1,-1,1,-1 };
    check.checkLongLong(4, o.maximumTotalCost(nums));

    nums = { 0 };
    check.checkLongLong(0, o.maximumTotalCost(nums));

    nums = { 1,-1 };
    check.checkLongLong(2, o.maximumTotalCost(nums));

    nums = { -13,3 };
    check.checkLongLong(-10, o.maximumTotalCost(nums));
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
