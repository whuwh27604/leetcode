/* 使数组的值全部为 K 的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个整数 k 。

如果一个数组中所有 严格大于 h 的整数值都 相等 ，那么我们称整数 h 是 合法的 。

比方说，如果 nums = [10, 8, 10, 8] ，那么 h = 9 是一个 合法 整数，因为所有满足 nums[i] > 9 的数都等于 10 ，但是 5 不是 合法 整数。

你可以对 nums 执行以下操作：

选择一个整数 h ，它对于 当前 nums 中的值是合法的。
对于每个下标 i ，如果它满足 nums[i] > h ，那么将 nums[i] 变为 h 。
你的目标是将 nums 中的所有元素都变为 k ，请你返回 最少 操作次数。如果无法将所有元素都变 k ，那么返回 -1 。



示例 1：

输入：nums = [5,2,5,4,5], k = 2

输出：2

解释：

依次选择合法整数 4 和 2 ，将数组全部变为 2 。

示例 2：

输入：nums = [2,1,2], k = 2

输出：-1

解释：

没法将所有值变为 2 。

示例 3：

输入：nums = [9,7,5,3], k = 1

输出：4

解释：

依次选择合法整数 7 ，5 ，3 和 1 ，将数组全部变为 1 。



提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 100
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int minNum = INT_MAX;
        unordered_set<int> numbers;

        for (int num : nums) {
            numbers.insert(num);
            minNum = min(minNum, num);
        }

        return (k > minNum ? -1 : (k == minNum ? (int)numbers.size() - 1 : (int)numbers.size()));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 5,2,5,4,5 };
    check.checkInt(2, o.minOperations(nums, 2));

    nums = { 2,1,2 };
    check.checkInt(-1, o.minOperations(nums, 2));

    nums = { 9,7,5,3 };
    check.checkInt(4, o.minOperations(nums, 1));
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
