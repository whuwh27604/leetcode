/* 收集巧克力.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 、下标从 0 开始的整数数组 nums ，表示收集不同巧克力的成本。每个巧克力都对应一个不同的类型，最初，位于下标 i 的巧克力就对应第 i 个类型。

在一步操作中，你可以用成本 x 执行下述行为：

同时修改所有巧克力的类型，将巧克力的类型 ith 修改为类型 ((i + 1) mod n)th。
假设你可以执行任意次操作，请返回收集所有类型巧克力所需的最小成本。



示例 1：

输入：nums = [20,1,15], x = 5
输出：13
解释：最开始，巧克力的类型分别是 [0,1,2] 。我们可以用成本 1 购买第 1 个类型的巧克力。
接着，我们用成本 5 执行一次操作，巧克力的类型变更为 [1,2,0] 。我们可以用成本 1 购买第 2 个类型的巧克力。
然后，我们用成本 5 执行一次操作，巧克力的类型变更为 [2,0,1] 。我们可以用成本 1 购买第 0 个类型的巧克力。
因此，收集所有类型的巧克力需要的总成本是 (1 + 5 + 1 + 5 + 1) = 13 。可以证明这是一种最优方案。
示例 2：

输入：nums = [1,2,3], x = 4
输出：6
解释：我们将会按最初的成本收集全部三个类型的巧克力，而不需执行任何操作。因此，收集所有类型的巧克力需要的总成本是 1 + 2 + 3 = 6 。


提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 109
1 <= x <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int size = nums.size();
        long long leastCost = LLONG_MAX;
        vector<vector<int>> minNums(size, vector<int>(size));  // minNums[i][j]表示nums[i, i + j]范围内的最小值

        getMinNums(size, nums, minNums);

        for (int opers = 0; opers < size; ++opers) {  // 枚举操作次数
            leastCost = min(leastCost, getCost(size, minNums, opers) + (long long)x * opers);
        }

        return leastCost;
    }

    void getMinNums(int size, vector<int>& nums, vector<vector<int>>& minNums) {
        for (int i = 0; i < size; ++i) {
            minNums[i][0] = nums[i];

            for (int j = 1; j < size; ++j) {
                minNums[i][j] = min(minNums[i][j - 1], nums[(i + j) % size]);
            }
        }
    }

    long long getCost(int size, vector<vector<int>>& minNums, int opers) {
        long long cost = 0;

        for (int i = 0; i < size; ++i) {
            cost += minNums[i][opers];
        }

        return cost;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 20,1,15 };
    check.checkLongLong(13, o.minCost(nums, 5));

    nums = { 1,2,3 };
    check.checkLongLong(6, o.minCost(nums, 4));

    nums = { 271,902,792,501,184,559,140,506,94,161 };
    check.checkLongLong(1947, o.minCost(nums, 167));
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
