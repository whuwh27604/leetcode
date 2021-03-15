﻿/* 使数组互补的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 偶数 n 的整数数组 nums 和一个整数 limit 。每一次操作，你可以将 nums 中的任何整数替换为 1 到 limit 之间的另一个整数。

如果对于所有下标 i（下标从 0 开始），nums[i] + nums[n - 1 - i] 都等于同一个数，则数组 nums 是 互补的 。例如，数组 [1,2,3,4] 是互补的，因为对于所有下标 i ，nums[i] + nums[n - 1 - i] = 5 。

返回使数组 互补 的 最少 操作次数。

 

示例 1：

输入：nums = [1,2,4,3], limit = 4
输出：1
解释：经过 1 次操作，你可以将数组 nums 变成 [1,2,2,3]（加粗元素是变更的数字）：
nums[0] + nums[3] = 1 + 3 = 4.
nums[1] + nums[2] = 2 + 2 = 4.
nums[2] + nums[1] = 2 + 2 = 4.
nums[3] + nums[0] = 3 + 1 = 4.
对于每个 i ，nums[i] + nums[n-1-i] = 4 ，所以 nums 是互补的。
示例 2：

输入：nums = [1,2,2,1], limit = 2
输出：2
解释：经过 2 次操作，你可以将数组 nums 变成 [2,2,2,2] 。你不能将任何数字变更为 3 ，因为 3 > limit 。
示例 3：

输入：nums = [1,2,1,2], limit = 2
输出：0
解释：nums 已经是互补的。
 

提示：

n == nums.length
2 <= n <= 105
1 <= nums[i] <= limit <= 105
n 是偶数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-moves-to-make-array-complementary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> diff(limit * 2 + 2, 0);  // 使用差分数组延迟更新
        int i, j, size = nums.size(), sum = 0, minReplace = INT_MAX;

        for (i = 0, j = size - 1; i < j; ++i, --j) {
            /* 每一次，假设两个数是a、b，a<b，那么：
               1、把它们的和变为区间[2,a]中的数需要2次
               2、把它们的和变为区间(a,a+b)中的数需要1次
               3、把它们的和变为a+b需要0次
               4、把它们的和变为区间(a+b,b+limit]中的数需要1次
               5、把它们的和变为区间(b+limit,2*limit]中的数需要2次 */
            int a = min(nums[i], nums[j]), b = max(nums[i], nums[j]);
            diff[2] += 2;
            diff[a + 1] -= 2;
            diff[a + 1] += 1;
            diff[a + b] -= 1;
            diff[a + b + 1] += 1;
            diff[b + limit + 1] -= 1;
            diff[b + limit + 1] += 2;
        }

        for (i = 2; i <= limit * 2; ++i) {
            sum += diff[i];
            minReplace = min(minReplace, sum);
        }

        return minReplace;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,4,3 };
    check.checkInt(1, o.minMoves(nums, 4));

    nums = { 1,2,2,1 };
    check.checkInt(2, o.minMoves(nums, 2));

    nums = { 1,2,1,2 };
    check.checkInt(0, o.minMoves(nums, 2));

    nums = { 1,2 };
    check.checkInt(0, o.minMoves(nums, 2));

    nums = { 1,2,1,3,1,4,1,5,1,6,1,7 };
    check.checkInt(5, o.minMoves(nums, 10));
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
