/* 删除元素后和的最小差值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums ，它包含 3 * n 个元素。

你可以从 nums 中删除 恰好 n 个元素，剩下的 2 * n 个元素将会被分成两个 相同大小 的部分。

前面 n 个元素属于第一部分，它们的和记为 sumfirst 。
后面 n 个元素属于第二部分，它们的和记为 sumsecond 。
两部分和的 差值 记为 sumfirst - sumsecond 。

比方说，sumfirst = 3 且 sumsecond = 2 ，它们的差值为 1 。
再比方，sumfirst = 2 且 sumsecond = 3 ，它们的差值为 -1 。
请你返回删除 n 个元素之后，剩下两部分和的 差值的最小值 是多少。

 

示例 1：

输入：nums = [3,1,2]
输出：-1
解释：nums 有 3 个元素，所以 n = 1 。
所以我们需要从 nums 中删除 1 个元素，并将剩下的元素分成两部分。
- 如果我们删除 nums[0] = 3 ，数组变为 [1,2] 。两部分和的差值为 1 - 2 = -1 。
- 如果我们删除 nums[1] = 1 ，数组变为 [3,2] 。两部分和的差值为 3 - 2 = 1 。
- 如果我们删除 nums[2] = 2 ，数组变为 [3,1] 。两部分和的差值为 3 - 1 = 2 。
两部分和的最小差值为 min(-1,1,2) = -1 。
示例 2：

输入：nums = [7,9,5,8,1,3]
输出：1
解释：n = 2 。所以我们需要删除 2 个元素，并将剩下元素分为 2 部分。
如果我们删除元素 nums[2] = 5 和 nums[3] = 8 ，剩下元素为 [7,9,1,3] 。和的差值为 (7+9) - (1+3) = 12 。
为了得到最小差值，我们应该删除 nums[1] = 9 和 nums[4] = 1 ，剩下的元素为 [7,5,8,3] 。和的差值为 (7+5) - (8+3) = 1 。
观察可知，最优答案为 1 。
 

提示：

nums.length == 3 * n
1 <= n <= 105
1 <= nums[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-difference-in-sums-after-removal-of-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int size = nums.size(), n = size / 3;
        vector<long long> presums(size + 1, 0), sumMaxK(n + 1, 0), sumMinK(n + 1, 0);

        getPresums(nums, presums);
        getSumMaxK(n, nums, sumMaxK);
        getSumMinK(n, nums, sumMinK);

        return getMinDiff(n, presums, sumMaxK, sumMinK);
    }

    void getPresums(vector<int>& nums, vector<long long>& presums) {
        for (int i = 0; i < (int)nums.size(); ++i) {
            presums[i + 1] = presums[i] + nums[i];
        }
    }

    void getSumMaxK(int n, vector<int>& nums, vector<long long>& sumMaxK) {
        priority_queue<int> q;
        long long sum = 0;

        for (int i = 0; i < n; ++i) {
            q.push(nums[i]);
        }

        for (int i = 0; i < n; ++i) {
            q.push(nums[n + i]);
            sum += q.top();
            sumMaxK[i + 1] = sum;
            q.pop();
        }
    }

    void getSumMinK(int n, vector<int>& nums, vector<long long>& sumMinK) {
        priority_queue<int, vector<int>, greater<int>> q;
        long long sum = 0;

        for (int i = 3 * n - 1; i >= 2 * n ; --i) {
            q.push(nums[i]);
        }

        for (int i = 1; i <= n; ++i) {
            q.push(nums[2 * n - i]);
            sum += q.top();
            sumMinK[i] = sum;
            q.pop();
        }
    }

    long long getMinDiff(int n, vector<long long>& presums, vector<long long>& sumMaxK, vector<long long>& sumMinK) {
        long long minDiff = LLONG_MAX;

        for (int i = 0; i <= n; ++i) {
            long long sumLeft = presums[n + i] - sumMaxK[i];
            long long sumRight = presums[3 * n] - presums[n + i] - sumMinK[n - i];
            minDiff = min(minDiff, sumLeft - sumRight);
        }

        return minDiff;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,1,2 };
    check.checkLongLong(-1, o.minimumDifference(nums));

    nums = { 7,9,5,8,1,3 };
    check.checkLongLong(1, o.minimumDifference(nums));

    nums = { 7,9,5,8,1,3,3,1,2,7,9,5,8,1,3,3,1,2,7,9,5,8,1,3,3,1,2,7,9,5,8,1,3,3,1,2,7,9,5,8,1,3,3,1,2,7,9,5,8,1,3,3,1,2,7,9,5,8,1,3,3,1,2 };
    check.checkLongLong(-66, o.minimumDifference(nums));

    nums = { 7,9,5,8,1,3,3,1,2,7,9,5,8,1,3,3,1,2,7,9,5,8,1,3,3,1,2,7,9,5,8,1,3,3,1,2,7,9,5,8,1,3,3,1,2,7,9,5,8,1,3,3,1,2,7,9,5,8,1,3,3,1,2,7,9,5,8,1,3,3,1,2,7,9,5,8,1,3,3,1,2,7,9,5,8,1,3,3,1,2,7,9,5,8,1,3,3,1,2,7,9,5,8,1,3,3,1,2,7,9,5,8,1,3,3,1,2,7,9,5,8,1,3,3,1,2 };
    check.checkLongLong(-140, o.minimumDifference(nums));
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
