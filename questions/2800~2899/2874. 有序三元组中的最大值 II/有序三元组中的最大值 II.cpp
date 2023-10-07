/* 有序三元组中的最大值 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。

请你从所有满足 i < j < k 的下标三元组 (i, j, k) 中，找出并返回下标三元组的最大值。如果所有满足条件的三元组的值都是负数，则返回 0 。

下标三元组 (i, j, k) 的值等于 (nums[i] - nums[j]) * nums[k] 。



示例 1：

输入：nums = [12,6,1,2,7]
输出：77
解释：下标三元组 (0, 2, 4) 的值是 (nums[0] - nums[2]) * nums[4] = 77 。
可以证明不存在值大于 77 的有序下标三元组。
示例 2：

输入：nums = [1,10,3,4,19]
输出：133
解释：下标三元组 (1, 2, 4) 的值是 (nums[1] - nums[2]) * nums[4] = 133 。
可以证明不存在值大于 133 的有序下标三元组。
示例 3：

输入：nums = [1,2,3]
输出：0
解释：唯一的下标三元组 (0, 1, 2) 的值是一个负数，(nums[0] - nums[1]) * nums[2] = -3 。因此，答案是 0 。


提示：

3 <= nums.length <= 105
1 <= nums[i] <= 106
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxValue = 0;
        int size = nums.size(), maxNum = 0;
        vector<int> leftMax(size, 0), rightMax(size + 1, 0);

        for (int i = 0; i < size; ++i) {
            maxNum = max(maxNum, nums[i]);
            leftMax[i] = maxNum;
        }

        for (int i = size - 1; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }

        for (int j = 1; j < size - 1; ++j) {
            maxValue = max(maxValue, ((long long)leftMax[j - 1] - nums[j]) * rightMax[j + 1]);
        }

        return maxValue;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 12,6,1,2,7 };
    check.checkLongLong(77, o.maximumTripletValue(nums));

    nums = { 1,10,3,4,19 };
    check.checkLongLong(133, o.maximumTripletValue(nums));

    nums = { 1,2,3 };
    check.checkLongLong(0, o.maximumTripletValue(nums));
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
