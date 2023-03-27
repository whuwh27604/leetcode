/* 使数组元素全部相等的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数数组 nums 。

同时给你一个长度为 m 的整数数组 queries 。第 i 个查询中，你需要将 nums 中所有元素变成 queries[i] 。你可以执行以下操作 任意 次：

将数组里一个元素 增大 或者 减小 1 。
请你返回一个长度为 m 的数组 answer ，其中 answer[i]是将 nums 中所有元素变成 queries[i] 的 最少 操作次数。

注意，每次查询后，数组变回最开始的值。



示例 1：

输入：nums = [3,1,6,8], queries = [1,5]
输出：[14,10]
解释：第一个查询，我们可以执行以下操作：
- 将 nums[0] 减小 2 次，nums = [1,1,6,8] 。
- 将 nums[2] 减小 5 次，nums = [1,1,1,8] 。
- 将 nums[3] 减小 7 次，nums = [1,1,1,1] 。
第一个查询的总操作次数为 2 + 5 + 7 = 14 。
第二个查询，我们可以执行以下操作：
- 将 nums[0] 增大 2 次，nums = [5,1,6,8] 。
- 将 nums[1] 增大 4 次，nums = [5,5,6,8] 。
- 将 nums[2] 减小 1 次，nums = [5,5,5,8] 。
- 将 nums[3] 减小 3 次，nums = [5,5,5,5] 。
第二个查询的总操作次数为 2 + 4 + 1 + 3 = 10 。
示例 2：

输入：nums = [2,9,6,3], queries = [10]
输出：[20]
解释：我们可以将数组中所有元素都增大到 10 ，总操作次数为 8 + 1 + 4 + 7 = 20 。


提示：

n == nums.length
m == queries.length
1 <= n, m <= 105
1 <= nums[i], queries[i] <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());

        int size1 = nums.size(), size2 = queries.size();
        vector<long long> presums(size1 + 1, 0), ans(size2);

        for (int i = 0; i < size1; ++i) {
            presums[i + 1] = presums[i] + nums[i];
        }

        for (int i = 0; i < size2; ++i) {
            int num = queries[i];
            int index = distance(nums.begin(), upper_bound(nums.begin(), nums.end(), num));
            ans[i] = (long long)num * index - presums[index] + presums[size1] - presums[index] - num * ((long long)size1 - index);
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,1,6,8 };
    vector<int> queries = { 1,5 };
    vector<long long> actual = o.minOperations(nums, queries);
    vector<long long> expected = { 14,10 };
    check.checkLongLongVector(expected, actual);

    nums = { 2,9,6,3 };
    queries = { 10 };
    actual = o.minOperations(nums, queries);
    expected = { 20 };
    check.checkLongLongVector(expected, actual);

    nums = { 1 };
    queries = { 3 };
    actual = o.minOperations(nums, queries);
    expected = { 2 };
    check.checkLongLongVector(expected, actual);

    nums = { 3 };
    queries = { 1 };
    actual = o.minOperations(nums, queries);
    expected = { 2 };
    check.checkLongLongVector(expected, actual);
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
