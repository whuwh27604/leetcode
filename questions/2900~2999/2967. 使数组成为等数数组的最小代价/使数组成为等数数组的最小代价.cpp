﻿/* 使数组成为等数数组的最小代价.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 下标从 0 开始的整数数组 nums 。

你可以对 nums 执行特殊操作 任意次 （也可以 0 次）。每一次特殊操作中，你需要 按顺序 执行以下步骤：

从范围 [0, n - 1] 里选择一个下标 i 和一个 正 整数 x 。
将 |nums[i] - x| 添加到总代价里。
将 nums[i] 变为 x 。
如果一个正整数正着读和反着读都相同，那么我们称这个数是 回文数 。比方说，121 ，2552 和 65756 都是回文数，但是 24 ，46 ，235 都不是回文数。

如果一个数组中的所有元素都等于一个整数 y ，且 y 是一个小于 109 的 回文数 ，那么我们称这个数组是一个 等数数组 。

请你返回一个整数，表示执行任意次特殊操作后使 nums 成为 等数数组 的 最小 总代价。



示例 1：

输入：nums = [1,2,3,4,5]
输出：6
解释：我们可以将数组中所有元素变为回文数 3 得到等数数组，数组变成 [3,3,3,3,3] 需要执行 4 次特殊操作，代价为 |1 - 3| + |2 - 3| + |4 - 3| + |5 - 3| = 6 。
将所有元素变为其他回文数的总代价都大于 6 。
示例 2：

输入：nums = [10,12,13,14,15]
输出：11
解释：我们可以将数组中所有元素变为回文数 11 得到等数数组，数组变成 [11,11,11,11,11] 需要执行 5 次特殊操作，代价为 |10 - 11| + |12 - 11| + |13 - 11| + |14 - 11| + |15 - 11| = 11 。
将所有元素变为其他回文数的总代价都大于 11 。
示例 3 ：

输入：nums = [22,33,22,33,22]
输出：22
解释：我们可以将数组中所有元素变为回文数 22 得到等数数组，数组变为 [22,22,22,22,22] 需要执行 2 次特殊操作，代价为 |33 - 22| + |33 - 22| = 22 。
将所有元素变为其他回文数的总代价都大于 22 。


提示：

1 <= n <= 105
1 <= nums[i] <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        int size = nums.size();

        sort(nums.begin(), nums.end());

        return ((size & 1) == 1) ? getOddMinCost(nums, nums[size / 2]) : getEvenMinCost(nums, nums[size / 2 - 1], nums[size / 2]);
    }

    long long getOddMinCost(vector<int>& nums, int median) {
        int num1 = getLessPalindrome(median), num2 = getGreaterPalindrome(median);

        return min(getCost(nums, num1), getCost(nums, num2));
    }

    long long getEvenMinCost(vector<int>& nums, int median1, int median2) {
        int num1 = getGreaterPalindrome(median1), num2 = getLessPalindrome(median2);

        return min(getCost(nums, num1), getCost(nums, num2));
    }

    int getLessPalindrome(int num) {
        while (!isPalindrome(num)) {
            --num;
        }

        return num;
    }

    int getGreaterPalindrome(int num) {
        while (!isPalindrome(num)) {
            ++num;
        }

        return num;
    }

    bool isPalindrome(int num) {
        string n = to_string(num);

        for (int i = 0, j = n.size() - 1; i < j; ++i, --j) {
            if (n[i] != n[j]) {
                return false;
            }
        }

        return true;
    }

    long long getCost(vector<int>& nums, int target) {
        long long cost = 0;

        for (int num : nums) {
            cost += abs(num - target);
        }

        return cost;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3,4,5 };
    check.checkLongLong(6, o.minimumCost(nums));

    nums = { 10,12,13,14,15 };
    check.checkLongLong(11, o.minimumCost(nums));

    nums = { 22,33,22,33,22 };
    check.checkLongLong(22, o.minimumCost(nums));
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
