/* 拼接数组的最大分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，长度都是 n 。

你可以选择两个整数 left 和 right ，其中 0 <= left <= right < n ，接着 交换 两个子数组 nums1[left...right] 和 nums2[left...right] 。

例如，设 nums1 = [1,2,3,4,5] 和 nums2 = [11,12,13,14,15] ，整数选择 left = 1 和 right = 2，那么 nums1 会变为 [1,12,13,4,5] 而 nums2 会变为 [11,2,3,14,15] 。
你可以选择执行上述操作 一次 或不执行任何操作。

数组的 分数 取 sum(nums1) 和 sum(nums2) 中的最大值，其中 sum(arr) 是数组 arr 中所有元素之和。

返回 可能的最大分数 。

子数组 是数组中连续的一个元素序列。arr[left...right] 表示子数组包含 nums 中下标 left 和 right 之间的元素（含 下标 left 和 right 对应元素）。

 

示例 1：

输入：nums1 = [60,60,60], nums2 = [10,90,10]
输出：210
解释：选择 left = 1 和 right = 1 ，得到 nums1 = [60,90,60] 和 nums2 = [10,60,10] 。
分数为 max(sum(nums1), sum(nums2)) = max(210, 80) = 210 。
示例 2：

输入：nums1 = [20,40,20,70,30], nums2 = [50,20,50,40,20]
输出：220
解释：选择 left = 3 和 right = 4 ，得到 nums1 = [20,40,20,40,20] 和 nums2 = [50,20,50,70,30] 。
分数为 max(sum(nums1), sum(nums2)) = max(140, 220) = 220 。
示例 3：

输入：nums1 = [7,11,13], nums2 = [1,1,1]
输出：31
解释：选择不交换任何子数组。
分数为 max(sum(nums1), sum(nums2)) = max(31, 3) = 31 。
 

提示：

n == nums1.length == nums2.length
1 <= n <= 105
1 <= nums1[i], nums2[i] <= 104

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-score-of-spliced-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <numeric>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0), sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        return max(sum1 + getMaxSum(nums1, nums2), sum2 + getMaxSum(nums2, nums1));
    }

    int getMaxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), sum = 0, maxSum = 0;

        for (int i = 0; i < n; ++i) {
            sum += (nums2[i] - nums1[i]);

            if (sum > 0) {
                maxSum = max(maxSum, sum);
            }
            else {
                sum = 0;
            }
        }

        return maxSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 20,40,20,70,30 };
    vector<int> nums2 = { 50,20,50,40,20 };
    check.checkInt(220, o.maximumsSplicedArray(nums1, nums2));

    nums1 = { 50,20,50,40,20 };
    nums2 = { 20,40,20,70,30 };
    check.checkInt(220, o.maximumsSplicedArray(nums1, nums2));

    nums1 = { 60,60,60 };
    nums2 = { 10,90,10 };
    check.checkInt(210, o.maximumsSplicedArray(nums1, nums2));

    nums1 = { 7,11,13 };
    nums2 = { 1,1,1 };
    check.checkInt(31, o.maximumsSplicedArray(nums1, nums2));
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
