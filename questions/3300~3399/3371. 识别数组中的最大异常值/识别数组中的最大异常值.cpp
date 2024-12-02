/* 识别数组中的最大异常值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums。该数组包含 n 个元素，其中 恰好 有 n - 2 个元素是 特殊数字 。剩下的 两个 元素中，一个是这些 特殊数字 的 和 ，另一个是 异常值 。

异常值 的定义是：既不是原始特殊数字之一，也不是表示这些数字元素和的数字。

注意，特殊数字、和 以及 异常值 的下标必须 不同 ，但可以共享 相同 的值。

返回 nums 中可能的 最大异常值。



示例 1：

输入： nums = [2,3,5,10]

输出： 10

解释：

特殊数字可以是 2 和 3，因此和为 5，异常值为 10。

示例 2：

输入： nums = [-2,-1,-3,-6,4]

输出： 4

解释：

特殊数字可以是 -2、-1 和 -3，因此和为 -6，异常值为 4。

示例 3：

输入： nums = [1,1,1,1,1,5,5]

输出： 5

解释：

特殊数字可以是 1、1、1、1 和 1，因此和为 5，另一个 5 为异常值。



提示：

3 <= nums.length <= 105
-1000 <= nums[i] <= 1000
输入保证 nums 中至少存在 一个 可能的异常值。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int total = 0, maxOutlier = INT_MIN;
        unordered_map<int, int> numsCount;

        for (int num : nums) {
            total += num;
            ++numsCount[num];
        }

        for (int outlier : nums) {
            int sum2 = total - outlier, sum = sum2 / 2;
            if ((sum2 & 1) == 0 && ((sum != outlier && numsCount.count(sum) != 0) || (sum == outlier && numsCount[sum] > 1))) {
                maxOutlier = max(maxOutlier, outlier);
            }
        }

        return maxOutlier;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 2,3,5,10 };
    check.checkInt(10, o.getLargestOutlier(nums));

    nums = { -2,-1,-3,-6,4 };
    check.checkInt(4, o.getLargestOutlier(nums));

    nums = { 1,1,1,1,1,5,5 };
    check.checkInt(5, o.getLargestOutlier(nums));

    nums = { -108,-108,-517 };
    check.checkInt(-517, o.getLargestOutlier(nums));

    nums = { -947,-326,200,-747 };
    check.checkInt(-326, o.getLargestOutlier(nums));

    nums = { 6,-31,50,-35,41,37,-42,13 };
    check.checkInt(-35, o.getLargestOutlier(nums));
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
