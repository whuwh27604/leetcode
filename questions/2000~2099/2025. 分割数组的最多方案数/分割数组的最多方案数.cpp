/* 分割数组的最多方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始且长度为 n 的整数数组 nums 。分割 数组 nums 的方案数定义为符合以下两个条件的 pivot 数目：

1 <= pivot < n
nums[0] + nums[1] + ... + nums[pivot - 1] == nums[pivot] + nums[pivot + 1] + ... + nums[n - 1]
同时给你一个整数 k 。你可以将 nums 中 一个 元素变为 k 或 不改变 数组。

请你返回在 至多 改变一个元素的前提下，最多 有多少种方法 分割 nums 使得上述两个条件都满足。

 

示例 1：

输入：nums = [2,-1,2], k = 3
输出：1
解释：一个最优的方案是将 nums[0] 改为 k 。数组变为 [3,-1,2] 。
有一种方法分割数组：
- pivot = 2 ，我们有分割 [3,-1 | 2]：3 + -1 == 2 。
示例 2：

输入：nums = [0,0,0], k = 1
输出：2
解释：一个最优的方案是不改动数组。
有两种方法分割数组：
- pivot = 1 ，我们有分割 [0 | 0,0]：0 == 0 + 0 。
- pivot = 2 ，我们有分割 [0,0 | 0]: 0 + 0 == 0 。
示例 3：

输入：nums = [22,4,-25,-20,-15,15,-16,7,19,-10,0,-13,-14], k = -33
输出：4
解释：一个最优的方案是将 nums[2] 改为 k 。数组变为 [22,4,-33,-20,-15,15,-16,7,19,-10,0,-13,-14] 。
有四种方法分割数组。
 

提示：

n == nums.length
2 <= n <= 105
-105 <= k, nums[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-ways-to-partition-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        int i, size = nums.size();
        long long totalSum = 0;
        vector<long long> presums(size);
        unordered_map<long long, int> presumsCount, currentCount;

        for (i = 0; i < size; ++i) {
            totalSum += nums[i];
            presums[i] = totalSum;
            ++presumsCount[totalSum];
        }

        --presumsCount[totalSum];  // 数组必须被分割，所以整个数组全部划入左边的方案去掉
        int maxWays = ((totalSum & 1) == 1 ? 0 : presumsCount[totalSum / 2]);
        long long currentSum = 0;

        for (i = 0; i < size; ++i) {
            int diff = k - nums[i];
            long long newTotalSum = totalSum + diff, target = newTotalSum >> 1;
            currentSum += nums[i];

            if ((newTotalSum & 1) == 0) {
                maxWays = max(maxWays, currentCount[target] + presumsCount[target - diff] - currentCount[target - diff]);
            }

            ++currentCount[currentSum];
        }

        return maxWays;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,-1,2 };
    check.checkInt(1, o.waysToPartition(nums, 3));

    nums = { 0,0,0 };
    check.checkInt(2, o.waysToPartition(nums, 1));

    nums = { 2,2 };
    check.checkInt(1, o.waysToPartition(nums, 1));

    nums = { 2,3 };
    check.checkInt(0, o.waysToPartition(nums, 1));

    nums = { 22,4,-25,-20,-15,15,-16,7,19,-10,0,-13,-14 };
    check.checkInt(4, o.waysToPartition(nums, -33));

    nums = { 0,3,0 };
    check.checkInt(2, o.waysToPartition(nums, 0));

    nums = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30827,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    check.checkInt(33, o.waysToPartition(nums, 0));
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
