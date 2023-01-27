/* 拆分数组的最小代价.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个整数 k 。

将数组拆分成一些非空子数组。拆分的 代价 是每个子数组中的 重要性 之和。

令 trimmed(subarray) 作为子数组的一个特征，其中所有仅出现一次的数字将会被移除。

例如，trimmed([3,1,2,4,3,4]) = [3,4,3,4] 。
子数组的 重要性 定义为 k + trimmed(subarray).length 。

例如，如果一个子数组是 [1,2,3,3,3,4,4] ，trimmed([1,2,3,3,3,4,4]) = [3,3,3,4,4] 。这个子数组的重要性就是 k + 5 。
找出并返回拆分 nums 的所有可行方案中的最小代价。

子数组 是数组的一个连续 非空 元素序列。



示例 1：

输入：nums = [1,2,1,2,1,3,3], k = 2
输出：8
解释：将 nums 拆分成两个子数组：[1,2], [1,2,1,3,3]
[1,2] 的重要性是 2 + (0) = 2 。
[1,2,1,3,3] 的重要性是 2 + (2 + 2) = 6 。
拆分的代价是 2 + 6 = 8 ，可以证明这是所有可行的拆分方案中的最小代价。
示例 2：

输入：nums = [1,2,1,2,1], k = 2
输出：6
解释：将 nums 拆分成两个子数组：[1,2], [1,2,1] 。
[1,2] 的重要性是 2 + (0) = 2 。
[1,2,1] 的重要性是 2 + (2) = 4 。
拆分的代价是 2 + 4 = 6 ，可以证明这是所有可行的拆分方案中的最小代价。
示例 3：

输入：nums = [1,2,1,2,1], k = 5
输出：10
解释：将 nums 拆分成一个子数组：[1,2,1,2,1].
[1,2,1,2,1] 的重要性是 5 + (3 + 2) = 10 。
拆分的代价是 10 ，可以证明这是所有可行的拆分方案中的最小代价。


提示：

1 <= nums.length <= 1000
0 <= nums[i] < nums.length
1 <= k <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int size = nums.size();
        vector<vector<int>> trimSize(size, vector<int>(size));

        getTrimSize(nums, size, trimSize);

        return getMinCost(nums, k, trimSize);
    }

    void getTrimSize(vector<int>& nums, int size, vector<vector<int>>& trimSize) {
        for (int i = 0; i < size; ++i) {
            vector<int> count(1000, 0);
            int single = 0;

            for (int j = i; j < size; ++j) {
                int num = nums[j];
                ++count[num];
                if (count[num] == 1) {
                    ++single;
                }
                else if (count[num] == 2) {
                    --single;
                }
                trimSize[i][j] = j - i + 1 - single;
            }
        }
    }

    int getMinCost(vector<int>& nums, int k, vector<vector<int>>& trimSize) {
        int size = nums.size();
        vector<int> dp(size);

        for (int i = 0; i < size; ++i) {
            dp[i] = k + trimSize[0][i];

            for (int j = 1; j <= i; ++j) {
                dp[i] = min(dp[i], dp[j - 1] + k + trimSize[j][i]);
            }
        }

        return dp.back();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,1,2,1,3,3 };
    check.checkInt(8, o.minCost(nums, 2));

    nums = { 1,2,1,2,1 };
    check.checkInt(6, o.minCost(nums, 2));

    nums = { 1,2,1,2,1 };
    check.checkInt(10, o.minCost(nums, 5));

    nums = { 1 };
    check.checkInt(8, o.minCost(nums, 8));

    nums = { 2,3,3,3,1,5,5,0,5,3,4,2,1,2,5,1,2,0 };
    check.checkInt(21, o.minCost(nums, 5));
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
