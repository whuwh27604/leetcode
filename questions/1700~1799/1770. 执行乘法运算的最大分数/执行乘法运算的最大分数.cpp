/* 执行乘法运算的最大分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个长度分别 n 和 m 的整数数组 nums 和 multipliers ，其中 n >= m ，数组下标 从 1 开始 计数。

初始时，你的分数为 0 。你需要执行恰好 m 步操作。在第 i 步操作（从 1 开始 计数）中，需要：

选择数组 nums 开头处或者末尾处 的整数 x 。
你获得 multipliers[i] * x 分，并累加到你的分数中。
将 x 从数组 nums 中移除。
在执行 m 步操作后，返回 最大 分数。

 

示例 1：

输入：nums = [1,2,3], multipliers = [3,2,1]
输出：14
解释：一种最优解决方案如下：
- 选择末尾处的整数 3 ，[1,2,3] ，得 3 * 3 = 9 分，累加到分数中。
- 选择末尾处的整数 2 ，[1,2] ，得 2 * 2 = 4 分，累加到分数中。
- 选择末尾处的整数 1 ，[1] ，得 1 * 1 = 1 分，累加到分数中。
总分数为 9 + 4 + 1 = 14 。
示例 2：

输入：nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
输出：102
解释：一种最优解决方案如下：
- 选择开头处的整数 -5 ，[-5,-3,-3,-2,7,1] ，得 -5 * -10 = 50 分，累加到分数中。
- 选择开头处的整数 -3 ，[-3,-3,-2,7,1] ，得 -3 * -5 = 15 分，累加到分数中。
- 选择开头处的整数 -3 ，[-3,-2,7,1] ，得 -3 * 3 = -9 分，累加到分数中。
- 选择末尾处的整数 1 ，[-2,7,1] ，得 1 * 4 = 4 分，累加到分数中。
- 选择末尾处的整数 7 ，[-2,7] ，得 7 * 6 = 42 分，累加到分数中。
总分数为 50 + 15 - 9 + 4 + 42 = 102 。
 

提示：

n == nums.length
m == multipliers.length
1 <= m <= 103
m <= n <= 105
-1000 <= nums[i], multipliers[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-score-from-performing-multiplication-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        /* 令dp[i][j]表示nums[i][j]能够取得的最大分数，那么dp[i][j]=max(nums[i]*multi[x]+dp[i+1][j],nums[j]*multi[x]+dp[i][j-1])
           只需要用到右上角一小块，将dp[i][j]平移到dp[i][j - n + m]就可以了 */
        int i, j, k, n = nums.size(), m = multipliers.size();
        vector<vector<int>> dp(m, vector<int>(m));

        for (i = 0, j = n - m; j < n; ++i, ++j) {
            dp[i][j - n + m] = max(nums[i] * multipliers[m - 1], nums[j] * multipliers[m - 1]);
        }

        for (k = n - m + 1; k < n; ++k) {
            for (i = 0, j = k; j < n; ++i, ++j) {
                dp[i][j - n + m] = max(nums[i] * multipliers[n - k - 1] + dp[i + 1][j - n + m], nums[j] * multipliers[n - k - 1] + dp[i][j - 1 - n + m]);
            }
        }

        return dp[0][m - 1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3 };
    vector<int> multipliers = { 3,2,1 };
    check.checkInt(14, o.maximumScore(nums, multipliers));

    nums = { -5,-3,-3,-2,7,1 };
    multipliers = { -10,-5,3,4,6 };
    check.checkInt(102, o.maximumScore(nums, multipliers));

    nums = { -5 };
    multipliers = { 6 };
    check.checkInt(-30, o.maximumScore(nums, multipliers));
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
