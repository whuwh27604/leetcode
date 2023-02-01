/* 统计上升四元组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 下标从 0 开始的整数数组 nums ，它包含 1 到 n 的所有数字，请你返回上升四元组的数目。

如果一个四元组 (i, j, k, l) 满足以下条件，我们称它是上升的：

0 <= i < j < k < l < n 且
nums[i] < nums[k] < nums[j] < nums[l] 。


示例 1：

输入：nums = [1,3,2,4,5]
输出：2
解释：
- 当 i = 0 ，j = 1 ，k = 2 且 l = 3 时，有 nums[i] < nums[k] < nums[j] < nums[l] 。
- 当 i = 0 ，j = 1 ，k = 2 且 l = 4 时，有 nums[i] < nums[k] < nums[j] < nums[l] 。
没有其他的四元组，所以我们返回 2 。
示例 2：

输入：nums = [1,2,3,4]
输出：0
解释：只存在一个四元组 i = 0 ，j = 1 ，k = 2 ，l = 3 ，但是 nums[j] < nums[k] ，所以我们返回 0 。


提示：

4 <= nums.length <= 4000
1 <= nums[i] <= nums.length
nums 中所有数字 互不相同 ，nums 是一个排列。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        long long quadruplets = 0;
        int n = nums.size();
        vector<vector<int>> lessCount(n, vector<int>(n + 1, 0)), greaterCount(n, vector<int>(n + 1, 0));

        getLess(nums, n, lessCount);
        getGreater(nums, n, greaterCount);

        for (int j = 1; j < n - 2; ++j) {
            for (int k = j + 1; k < n - 1; ++k) {
                if (nums[k] < nums[j]) {
                    quadruplets += ((long long)lessCount[j - 1][nums[k]] * greaterCount[k + 1][nums[j]]);
                }
            }
        }

        return quadruplets;
    }

    void getLess(vector<int>& nums, int n, vector<vector<int>>& lessCount) {
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                lessCount[i] = lessCount[i - 1];
            }

            for (int j = nums[i] + 1; j <= n; ++j) {
                ++lessCount[i][j];
            }
        }
    }

    void getGreater(vector<int>& nums, int n, vector<vector<int>>& greaterCount) {
        for (int i = n - 1; i >= 0; --i) {
            if (i != n - 1) {
                greaterCount[i] = greaterCount[i + 1];
            }

            for (int j = 1; j < nums[i]; ++j) {
                ++greaterCount[i][j];
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,2,4,5 };
    check.checkLongLong(2, o.countQuadruplets(nums));

    nums = { 1,2,3,4 };
    check.checkLongLong(0, o.countQuadruplets(nums));
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
