/* 将数组分成两个数组并最小化数组和的差.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 2 * n 的整数数组。你需要将 nums 分成 两个 长度为 n 的数组，分别求出两个数组的和，并 最小化 两个数组和之 差的绝对值 。nums 中每个元素都需要放入两个数组之一。

请你返回 最小 的数组和之差。

 

示例 1：



输入：nums = [3,9,7,3]
输出：2
解释：最优分组方案是分成 [3,9] 和 [7,3] 。
数组和之差的绝对值为 abs((3 + 9) - (7 + 3)) = 2 。
示例 2：

输入：nums = [-36,36]
输出：72
解释：最优分组方案是分成 [-36] 和 [36] 。
数组和之差的绝对值为 abs((-36) - (36)) = 72 。
示例 3：



输入：nums = [2,-1,0,4,-2,-9]
输出：0
解释：最优分组方案是分成 [2,4,-9] 和 [-1,0,-2] 。
数组和之差的绝对值为 abs((2 + 4 + -9) - (-1 + 0 + -2)) = 0 。
 

提示：

1 <= n <= 15
nums.length == 2 * n
-107 <= nums[i] <= 107

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <numeric>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int i, n = nums.size() / 2, minDiff = INT_MAX;

        for (int& num : nums) {  // 将原数组乘2，确保和的一半target是整数。这样可以避免下面abs后不知道大于还是小于target的问题
            num *= 2;
        }

        int halfAllSum = accumulate(nums.begin(), nums.end(), 0) / 2;
        vector<vector<int>> sums1(n + 1), sums2(n + 1);

        getSums(nums, sums1, n, 0);
        getSums(nums, sums2, n, n);

        for (auto& sum : sums1) {
            sort(sum.begin(), sum.end());
        }

        for (auto& sum : sums2) {
            sort(sum.begin(), sum.end());
        }

        for (i = 0; i <= n; ++i) {
            minDiff = min(minDiff, getMinDiff(sums1[i], sums2[n - i], halfAllSum));  // 求得离halfAllSum最近的两数之和
            if (minDiff == 0) {
                break;
            }
        }

        return minDiff;  // 一组数相差halfAllSum为diff，那么另一组数必定也相差diff，所以两组数相差2*diff。又因为一开始都乘以2，所以实际相差diff。
    }

    void getSums(vector<int>& nums, vector<vector<int>>& sums, int n, int start) {
        int i, j, bit, size = 1 << n;
        vector<int> allSums(size, 0), countOnes(size, 0);
        sums[0] = { 0 };

        for (i = 1; i < size; ++i) {
            for (j = 0, bit = 1; j < n; ++j, bit <<= 1) {
                if ((i & bit) != 0) {
                    int count = countOnes[i ^ bit] + 1;
                    countOnes[i] = count;
                    allSums[i] = allSums[i ^ bit] + nums[j + start];
                    sums[count].push_back(allSums[i]);
                    break;
                }
            }
        }
    }

    int getMinDiff(vector<int>& nums1, vector<int>& nums2, int target) {
        int left = 0, right = nums2.size() - 1, size = nums1.size(), minDiff = INT_MAX;

        while (left < size && right >= 0) {
            int sum = nums1[left] + nums2[right];
            minDiff = min(minDiff, abs(sum - target));

            if (sum == target) {
                break;
            }
            else if (sum > target) {
                --right;
            }
            else {
                ++left;
            }
        }

        return minDiff;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,9,7,3 };
    check.checkInt(2, o.minimumDifference(nums));

    nums = { -36,36 };
    check.checkInt(72, o.minimumDifference(nums));

    nums = { 2,-1,0,4,-2,-9 };
    check.checkInt(0, o.minimumDifference(nums));

    nums = { 7772197,4460211,-7641449,-8856364,546755,-3673029,527497,-9392076,3130315,-5309187,-4781283,5919119,3093450,1132720,6380128,-3954678,-1651499,-7944388,-3056827,1610628,7711173,6595873,302974,7656726,-2572679,0,2121026,-5743797,-8897395,-9699694 };
    check.checkInt(1, o.minimumDifference(nums));
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
