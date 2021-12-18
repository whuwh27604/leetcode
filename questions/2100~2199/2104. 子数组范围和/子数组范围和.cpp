/* 子数组范围和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 。nums 中，子数组的 范围 是子数组中最大元素和最小元素的差值。

返回 nums 中 所有 子数组范围的 和 。

子数组是数组中一个连续 非空 的元素序列。

 

示例 1：

输入：nums = [1,2,3]
输出：4
解释：nums 的 6 个子数组如下所示：
[1]，范围 = 最大 - 最小 = 1 - 1 = 0
[2]，范围 = 2 - 2 = 0
[3]，范围 = 3 - 3 = 0
[1,2]，范围 = 2 - 1 = 1
[2,3]，范围 = 3 - 2 = 1
[1,2,3]，范围 = 3 - 1 = 2
所有范围的和是 0 + 0 + 0 + 1 + 1 + 2 = 4
示例 2：

输入：nums = [1,3,3]
输出：4
解释：nums 的 6 个子数组如下所示：
[1]，范围 = 最大 - 最小 = 1 - 1 = 0
[3]，范围 = 3 - 3 = 0
[3]，范围 = 3 - 3 = 0
[1,3]，范围 = 3 - 1 = 2
[3,3]，范围 = 3 - 3 = 0
[1,3,3]，范围 = 3 - 1 = 2
所有范围的和是 0 + 0 + 0 + 2 + 0 + 2 = 4
示例 3：

输入：nums = [4,-2,-3,4,1]
输出：59
解释：nums 中所有子数组范围的和是 59
 

提示：

1 <= nums.length <= 1000
-109 <= nums[i] <= 109
 

进阶：你可以设计一种时间复杂度为 O(n) 的解决方案吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-subarray-ranges
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int i, size = nums.size();
        long long sum = 0;
        vector<int> leftLess(size), leftGreater(size), rightLess(size), rightGreater(size);

        getLeft(nums, leftLess, leftGreater);
        getRight(nums, rightLess, rightGreater);

        for (i = 0; i < size; ++i) {
            sum += (nums[i] * ((long long)i - leftGreater[i]) * ((long long)rightGreater[i] - i));
            sum -= (nums[i] * ((long long)i - leftLess[i]) * ((long long)rightLess[i] - i));
        }

        return sum;
    }

    void getLeft(vector<int>& nums, vector<int>& leftLess, vector<int>& leftGreater) {
        int i, size = nums.size();
        stack<int> increasing, decreasing;

        for (i = 0; i < size; ++i) {
            while (!increasing.empty() && nums[increasing.top()] > nums[i]) {
                increasing.pop();
            }

            leftLess[i] = increasing.empty() ? -1 : increasing.top();
            increasing.push(i);

            while (!decreasing.empty() && nums[decreasing.top()] < nums[i]) {
                decreasing.pop();
            }

            leftGreater[i] = decreasing.empty() ? -1 : decreasing.top();
            decreasing.push(i);
        }
    }

    void getRight(vector<int>& nums, vector<int>& rightLess, vector<int>& rightGreater) {
        int i, size = nums.size();
        stack<int> increasing, decreasing;

        for (i = size - 1; i >= 0; --i) {
            while (!increasing.empty() && nums[increasing.top()] >= nums[i]) {
                increasing.pop();
            }

            rightLess[i] = increasing.empty() ? size : increasing.top();
            increasing.push(i);

            while (!decreasing.empty() && nums[decreasing.top()] <= nums[i]) {
                decreasing.pop();
            }

            rightGreater[i] = decreasing.empty() ? size : decreasing.top();
            decreasing.push(i);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3 };
    check.checkLongLong(4, o.subArrayRanges(nums));

    nums = { 1,3,3 };
    check.checkLongLong(4, o.subArrayRanges(nums));

    nums = { 4,-2,-3,4,1 };
    check.checkLongLong(59, o.subArrayRanges(nums));

    nums = { 3 };
    check.checkLongLong(0, o.subArrayRanges(nums));

    nums = { 1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8,9,8,7,6,5,4,3,2,1 };
    check.checkLongLong(15708, o.subArrayRanges(nums));
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
