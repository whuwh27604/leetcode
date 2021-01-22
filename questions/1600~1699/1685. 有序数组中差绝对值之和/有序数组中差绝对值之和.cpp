/* 有序数组中差绝对值之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 非递减 有序整数数组 nums 。

请你建立并返回一个整数数组 result，它跟 nums 长度相同，且result[i] 等于 nums[i] 与数组中所有其他元素差的绝对值之和。

换句话说， result[i] 等于 sum(|nums[i]-nums[j]|) ，其中 0 <= j < nums.length 且 j != i （下标从 0 开始）。

 

示例 1：

输入：nums = [2,3,5]
输出：[4,3,5]
解释：假设数组下标从 0 开始，那么
result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4，
result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3，
result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5。
示例 2：

输入：nums = [1,4,6,8,10]
输出：[24,15,13,15,21]
 

提示：

2 <= nums.length <= 105
1 <= nums[i] <= nums[i + 1] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-absolute-differences-in-a-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int i, size = nums.size();
        vector<int> presum(size + 1), sumAbsDiffs(size);
        presum[0] = 0;

        for (i = 0; i < size; ++i) {
            presum[i + 1] = presum[i] + nums[i];
        }

        for (i = 0; i < size; ++i) {
            /* i前面有i个数，这i个数的和是presum[i]，它们比nums[i]小，所以和是nums[i] * i - presum[i]
               i后面有size-1-i个数，这些数的和是presum[size] - presum[i + 1]，它们比nums[i]大，所以和是presum[size] - presum[i + 1] - nums[i] * (size - 1 - i) */
            sumAbsDiffs[i] = nums[i] * i - presum[i] + presum[size] - presum[i + 1] - nums[i] * (size - 1 - i);
        }

        return sumAbsDiffs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,3,5 };
    vector<int> actual = o.getSumAbsoluteDifferences(nums);
    vector<int> expected = { 4,3,5 };
    check.checkIntVector(expected, actual);

    nums = { 1,4,6,8,10 };
    actual = o.getSumAbsoluteDifferences(nums);
    expected = { 24,15,13,15,21 };
    check.checkIntVector(expected, actual);

    nums = { 8,10 };
    actual = o.getSumAbsoluteDifferences(nums);
    expected = { 2,2 };
    check.checkIntVector(expected, actual);
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
