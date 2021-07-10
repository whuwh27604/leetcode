/* 带限制的子序列和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个整数 k ，请你返回 非空 子序列元素和的最大值，子序列需要满足：子序列中每两个 相邻 的整数 nums[i] 和 nums[j] ，它们在原数组中的下标 i 和 j 满足 i < j 且 j - i <= k 。

数组的子序列定义为：将数组中的若干个数字删除（可以删除 0 个数字），剩下的数字按照原本的顺序排布。

 

示例 1：

输入：nums = [10,2,-10,5,20], k = 2
输出：37
解释：子序列为 [10, 2, 5, 20] 。
示例 2：

输入：nums = [-1,-2,-3], k = 1
输出：-1
解释：子序列必须是非空的，所以我们选择最大的数字。
示例 3：

输入：nums = [10,-2,-10,-5,20], k = 2
输出：23
解释：子序列为 [10, -2, -5, 20] 。
 

提示：

1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/constrained-subsequence-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <deque>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> dp(size);  // dp[i]表示选择nums[i]，nums[i,size)可以构成的最大和
        dp.back() = nums.back();

        deque<int> indices;  // dp[i]构成的单调递减队列
        indices.push_back(size - 1);
        int maxSum = nums.back();

        for (int i = size - 2; i >= 0; --i) {
            while (!indices.empty() && indices.front() - i > k) {  // 超出范围的sum扔掉
                indices.pop_front();
            }

            dp[i] = nums[i];
            if (!indices.empty() && dp[indices.front()] > 0) {  // 后面有大于0的sum，连接上
                dp[i] += dp[indices.front()];
            }

            while (!indices.empty() && dp[indices.back()] <= dp[i]) {  // 更小的sum可以扔掉了
                indices.pop_back();
            }

            indices.push_back(i);
            maxSum = max(maxSum, dp[i]);
        }

        return maxSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 10,2,-10,5,20 };
    check.checkInt(37, o.constrainedSubsetSum(nums, 2));

    nums = { -1,-2,-3 };
    check.checkInt(-1, o.constrainedSubsetSum(nums, 1));

    nums = { 10,-2,-10,-5,20 };
    check.checkInt(23, o.constrainedSubsetSum(nums, 2));

    nums = { 1,-5000,-5000,5000 };
    check.checkInt(5000, o.constrainedSubsetSum(nums, 2));

    nums = { 10,-9,-8,7,6,-5,-4,3,2,-1,-2,3,4,-5,-6,7,8,-9,-10,11 };
    check.checkInt(61, o.constrainedSubsetSum(nums, 7));
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
