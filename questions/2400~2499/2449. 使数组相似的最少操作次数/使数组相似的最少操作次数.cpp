/* 使数组相似的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个正整数数组 nums 和 target ，两个数组长度相等。

在一次操作中，你可以选择两个 不同 的下标 i 和 j ，其中 0 <= i, j < nums.length ，并且：

令 nums[i] = nums[i] + 2 且
令 nums[j] = nums[j] - 2 。
如果两个数组中每个元素出现的频率相等，我们称两个数组是 相似 的。

请你返回将 nums 变得与 target 相似的最少操作次数。测试数据保证 nums 一定能变得与 target 相似。

 

示例 1：

输入：nums = [8,12,6], target = [2,14,10]
输出：2
解释：可以用两步操作将 nums 变得与 target 相似：
- 选择 i = 0 和 j = 2 ，nums = [10,12,4] 。
- 选择 i = 1 和 j = 2 ，nums = [10,14,2] 。
2 次操作是最少需要的操作次数。
示例 2：

输入：nums = [1,2,5], target = [4,1,3]
输出：1
解释：一步操作可以使 nums 变得与 target 相似：
- 选择 i = 1 和 j = 2 ，nums = [1,4,3] 。
示例 3：

输入：nums = [1,1,1,1,1], target = [1,1,1,1,1]
输出：0
解释：数组 nums 已经与 target 相似。
 

提示：

n == nums.length == target.length
1 <= n <= 105
1 <= nums[i], target[i] <= 106
nums 一定可以变得与 target 相似。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-number-of-operations-to-make-arrays-similar
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> odds, evens, oddTargets, evenTargets;

        getOddEvens(nums, odds, evens);
        getOddEvens(target, oddTargets, evenTargets);
        sort(odds.begin(), odds.end());
        sort(evens.begin(), evens.end());
        sort(oddTargets.begin(), oddTargets.end());
        sort(evenTargets.begin(), evenTargets.end());

        return getOpers(odds, oddTargets) + getOpers(evens, evenTargets);
    }

    void getOddEvens(vector<int>& nums, vector<int>& odds, vector<int>& evens) {
        for (int num : nums) {
            if ((num & 1) == 0) {
                evens.push_back(num);
            }
            else {
                odds.push_back(num);
            }
        }
    }

    long long getOpers(vector<int>& nums, vector<int>& target) {
        int size = nums.size();
        long long opers = 0;

        for (int i = 0; i < size; ++i) {
            if (nums[i] < target[i]) {
                opers += ((long long)target[i] - nums[i]) / 2;
            }
        }

        return opers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 8,12,6 };
    vector<int> target = { 2,14,10 };
    check.checkLongLong(2, o.makeSimilar(nums, target));

    nums = { 1,2,5 };
    target = { 4,1,3 };
    check.checkLongLong(1, o.makeSimilar(nums, target));

    nums = { 1,1,1,1,1 };
    target = { 1,1,1,1,1 };
    check.checkLongLong(0, o.makeSimilar(nums, target));
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
