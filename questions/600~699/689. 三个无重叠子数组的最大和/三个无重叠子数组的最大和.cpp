/* 三个无重叠子数组的最大和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个整数 k ，找出三个长度为 k 、互不重叠、且 3 * k 项的和最大的子数组，并返回这三个子数组。

以下标的数组形式返回结果，数组中的每一项分别指示每个子数组的起始位置（下标从 0 开始）。如果有多个结果，返回字典序最小的一个。

 

示例 1：

输入：nums = [1,2,1,2,6,7,5,1], k = 2
输出：[0,3,5]
解释：子数组 [1, 2], [2, 6], [7, 5] 对应的起始下标为 [0, 3, 5]。
也可以取 [2, 1], 但是结果 [1, 3, 5] 在字典序上更大。
示例 2：

输入：nums = [1,2,1,2,1,2,1,2,1], k = 2
输出：[0,2,4]
 

提示：

1 <= nums.length <= 2 * 104
1 <= nums[i] < 216
1 <= k <= floor(nums.length / 3)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-sum-of-3-non-overlapping-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> sums(size, 0);
        vector<vector<int>> maxOneSums(size, vector<int>(2, 0));  // sum, index1
        vector<vector<int>> maxTwoSums(size, vector<int>(3, 0));  // sum, index1, index2
        vector<vector<int>> maxThreeSums(size, vector<int>(4, 0));  // sum, index1, index2, index3

        getSums(k, nums, sums);
        getMaxOneSums(k, sums, maxOneSums);
        getMaxTwoSums(k, sums, maxOneSums, maxTwoSums);
        getMaxThreeSums(k, sums, maxTwoSums, maxThreeSums);

        return { maxThreeSums.back()[1] - k + 1, maxThreeSums.back()[2] - k + 1, maxThreeSums.back()[3] - k + 1 };
    }

    void getSums(int k, vector<int>& nums, vector<int>& sums) {
        int i, size = nums.size(), sum = 0;

        for (i = 0; i < k; ++i) {
            sum += nums[i];
        }

        sums[i - 1] = sum;

        for (; i < size; ++i) {
            sum += (nums[i] - nums[i - k]);
            sums[i] = sum;
        }
    }

    void getMaxOneSums(int k, vector<int>& sums, vector<vector<int>>& maxOneSums) {
        int i, size = sums.size(), maxOneSum = 0;

        for (i = k - 1; i < size; ++i) {
            if (sums[i] > maxOneSum) {
                maxOneSum = sums[i];
                maxOneSums[i] = { maxOneSum, i };
            }
            else {
                maxOneSums[i] = maxOneSums[i - 1];
            }
        }
    }

    void getMaxTwoSums(int k, vector<int>& sums, vector<vector<int>>& maxOneSums, vector<vector<int>>& maxTwoSums) {
        int i, size = sums.size(), maxTwoSum = 0;

        for (i = 2 * k - 1; i < size; ++i) {
            if (sums[i] + maxOneSums[i - k][0] > maxTwoSum) {
                maxTwoSum = sums[i] + maxOneSums[i - k][0];
                maxTwoSums[i] = { maxTwoSum, maxOneSums[i - k][1], i };
            }
            else {
                maxTwoSums[i] = maxTwoSums[i - 1];
            }
        }
    }

    void getMaxThreeSums(int k, vector<int>& sums, vector<vector<int>>& maxTwoSums, vector<vector<int>>& maxThreeSums) {
        int i, size = sums.size(), maxThreeSum = 0;

        for (i = 3 * k - 1; i < size; ++i) {
            if (sums[i] + maxTwoSums[i - k][0] > maxThreeSum) {
                maxThreeSum = sums[i] + maxTwoSums[i - k][0];
                maxThreeSums[i] = { maxThreeSum, maxTwoSums[i - k][1], maxTwoSums[i - k][2], i };
            }
            else {
                maxThreeSums[i] = maxThreeSums[i - 1];
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,1,2,6,7,5,1 };
    vector<int> actual = o.maxSumOfThreeSubarrays(nums, 2);
    vector<int> expected = { 0,3,5 };
    check.checkIntVector(expected, actual);

    nums = { 1,2,1,2,1,2,1,2,1 };
    actual = o.maxSumOfThreeSubarrays(nums, 2);
    expected = { 0,2,4 };
    check.checkIntVector(expected, actual);

    nums = { 17,9,3,2,7,10,20,1,13,4,5,16,4,1,17,6,4,19,8,3 };
    actual = o.maxSumOfThreeSubarrays(nums, 4);
    expected = { 3,8,14 };
    check.checkIntVector(expected, actual);

    nums = { 1,2,3 };
    actual = o.maxSumOfThreeSubarrays(nums, 1);
    expected = { 0,1,2 };
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
