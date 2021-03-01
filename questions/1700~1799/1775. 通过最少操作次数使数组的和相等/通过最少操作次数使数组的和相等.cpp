/* 通过最少操作次数使数组的和相等.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个长度可能不等的整数数组 nums1 和 nums2 。两个数组中的所有值都在 1 到 6 之间（包含 1 和 6）。

每次操作中，你可以选择 任意 数组中的任意一个整数，将它变成 1 到 6 之间 任意 的值（包含 1 和 6）。

请你返回使 nums1 中所有数的和与 nums2 中所有数的和相等的最少操作次数。如果无法使两个数组的和相等，请返回 -1 。

 

示例 1：

输入：nums1 = [1,2,3,4,5,6], nums2 = [1,1,2,2,2,2]
输出：3
解释：你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。以下数组下标都从 0 开始。
- 将 nums2[0] 变为 6 。 nums1 = [1,2,3,4,5,6], nums2 = [6,1,2,2,2,2] 。
- 将 nums1[5] 变为 1 。 nums1 = [1,2,3,4,5,1], nums2 = [6,1,2,2,2,2] 。
- 将 nums1[2] 变为 2 。 nums1 = [1,2,2,4,5,1], nums2 = [6,1,2,2,2,2] 。
示例 2：

输入：nums1 = [1,1,1,1,1,1,1], nums2 = [6]
输出：-1
解释：没有办法减少 nums1 的和或者增加 nums2 的和使二者相等。
示例 3：

输入：nums1 = [6,6], nums2 = [1]
输出：3
解释：你可以通过 3 次操作使 nums1 中所有数的和与 nums2 中所有数的和相等。以下数组下标都从 0 开始。
- 将 nums1[0] 变为 2 。 nums1 = [2,6], nums2 = [1] 。
- 将 nums1[1] 变为 2 。 nums1 = [2,2], nums2 = [1] 。
- 将 nums2[0] 变为 4 。 nums1 = [2,2], nums2 = [4] 。
 

提示：

1 <= nums1.length, nums2.length <= 105
1 <= nums1[i], nums2[i] <= 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/equal-sum-arrays-with-minimum-number-of-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums1Count(7), nums2Count(7);
        int sum1 = 0, sum2 = 0;

        countNums(nums1, sum1, nums1Count);
        countNums(nums2, sum2, nums2Count);

        return sum1 < sum2 ? getMinOperations(nums1Count, sum1, nums2Count, sum2) : getMinOperations(nums2Count, sum2, nums1Count, sum1);
    }

    void countNums(vector<int>& nums, int& sum, vector<int>& numsCount) {
        for (int num : nums) {
            ++numsCount[num];
            sum += num;
        }
    }

    int getMinOperations(vector<int>& nums1Count, int sum1, vector<int>& nums2Count, int sum2) {
        int operations = 0;

        for (int i = 1, j = 6; i < 6; ++i, --j) {
            int diff = 6 - i;
            if (sum1 + nums1Count[i] * diff >= sum2) {
                return operations + (sum2 - sum1 + diff - 1) / diff;
            }

            sum1 += (nums1Count[i] * diff);
            operations += nums1Count[i];

            if (sum2 - nums2Count[j] * diff <= sum1) {
                return operations + (sum2 - sum1 + diff - 1) / diff;
            }

            sum2 -= nums2Count[j] * diff;
            operations += nums2Count[j];
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 1,2,3,4,5,6 };
    vector<int> nums2 = { 1,1,2,2,2,2 };
    check.checkInt(3, o.minOperations(nums1, nums2));

    nums1 = { 1,1,2,2,2,2 };
    nums2 = { 1,2,3,4,5,6 };
    check.checkInt(3, o.minOperations(nums1, nums2));

    nums1 = { 1,1,1,1,1,1,1 };
    nums2 = { 6 };
    check.checkInt(-1, o.minOperations(nums1, nums2));

    nums1 = { 6,6 };
    nums2 = { 1 };
    check.checkInt(3, o.minOperations(nums1, nums2));
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
