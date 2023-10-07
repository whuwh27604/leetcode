/* 无限数组的最短子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的数组 nums 和一个整数 target 。

下标从 0 开始的数组 infinite_nums 是通过无限地将 nums 的元素追加到自己之后生成的。

请你从 infinite_nums 中找出满足 元素和 等于 target 的 最短 子数组，并返回该子数组的长度。如果不存在满足条件的子数组，返回 -1 。



示例 1：

输入：nums = [1,2,3], target = 5
输出：2
解释：在这个例子中 infinite_nums = [1,2,3,1,2,3,1,2,...] 。
区间 [1,2] 内的子数组的元素和等于 target = 5 ，且长度 length = 2 。
可以证明，当元素和等于目标值 target = 5 时，2 是子数组的最短长度。
示例 2：

输入：nums = [1,1,1,2,3], target = 4
输出：2
解释：在这个例子中 infinite_nums = [1,1,1,2,3,1,1,1,2,3,1,1,...].
区间 [4,5] 内的子数组的元素和等于 target = 4 ，且长度 length = 2 。
可以证明，当元素和等于目标值 target = 4 时，2 是子数组的最短长度。
示例 3：

输入：nums = [2,4,6,8], target = 3
输出：-1
解释：在这个例子中 infinite_nums = [2,4,6,8,2,4,6,8,...] 。
可以证明，不存在元素和等于目标值 target = 3 的子数组。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= target <= 109
*/

#include <iostream>
#include <numeric>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long sum = accumulate(nums.begin(), nums.end(), 0L);
        int circle = (int)(target / sum * (int)nums.size());
        target %= sum;
        sum = 0;
        vector<int> infinite_nums = nums;
        infinite_nums.insert(infinite_nums.end(), nums.begin(), nums.end());
        int size = infinite_nums.size(), left = 0, right = 0, minSize = INT_MAX;

        for (; left < size; ++left) {
            while (right < size && sum < target) {
                sum += infinite_nums[right++];
            }

            if (sum == target) {
                minSize = min(minSize, right - left);
            }

            sum -= infinite_nums[left];
        }

        return minSize == INT_MAX ? -1 : minSize + circle;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3 };
    check.checkInt(2, o.minSizeSubarray(nums, 5));

    nums = { 1,1,1,2,3 };
    check.checkInt(2, o.minSizeSubarray(nums, 4));

    nums = { 2,4,6,8 };
    check.checkInt(-1, o.minSizeSubarray(nums, 3));

    nums = { 2,1,5,7,7,1,6,3 };
    check.checkInt(9, o.minSizeSubarray(nums, 39));
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
