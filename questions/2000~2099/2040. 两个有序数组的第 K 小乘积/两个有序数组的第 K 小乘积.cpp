/* 两个有序数组的第 K 小乘积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个 从小到大排好序 且下标从 0 开始的整数数组 nums1 和 nums2 以及一个整数 k ，请你返回第 k （从 1 开始编号）小的 nums1[i] * nums2[j] 的乘积，其中 0 <= i < nums1.length 且 0 <= j < nums2.length 。
 

示例 1：

输入：nums1 = [2,5], nums2 = [3,4], k = 2
输出：8
解释：第 2 小的乘积计算如下：
- nums1[0] * nums2[0] = 2 * 3 = 6
- nums1[0] * nums2[1] = 2 * 4 = 8
第 2 小的乘积为 8 。
示例 2：

输入：nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
输出：0
解释：第 6 小的乘积计算如下：
- nums1[0] * nums2[1] = (-4) * 4 = -16
- nums1[0] * nums2[0] = (-4) * 2 = -8
- nums1[1] * nums2[1] = (-2) * 4 = -8
- nums1[1] * nums2[0] = (-2) * 2 = -4
- nums1[2] * nums2[0] = 0 * 2 = 0
- nums1[2] * nums2[1] = 0 * 4 = 0
第 6 小的乘积为 0 。
示例 3：

输入：nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
输出：-6
解释：第 3 小的乘积计算如下：
- nums1[0] * nums2[4] = (-2) * 5 = -10
- nums1[0] * nums2[3] = (-2) * 4 = -8
- nums1[4] * nums2[0] = 2 * (-3) = -6
第 3 小的乘积为 -6 。
 

提示：

1 <= nums1.length, nums2.length <= 5 * 104
-105 <= nums1[i], nums2[j] <= 105
1 <= k <= nums1.length * nums2.length
nums1 和 nums2 都是从小到大排好序的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-product-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        int size1 = nums1.size(), size2 = nums2.size();
        int negatives1 = distance(nums1.begin(), lower_bound(nums1.begin(), nums1.end(), 0)), positives1 = size1 - negatives1;
        int negatives2 = distance(nums2.begin(), lower_bound(nums2.begin(), nums2.end(), 0)), positives2 = size2 - negatives2;
        long long a = nums1.front(), b = nums1.back(), c = nums2.front(), d = nums2.back();
        long long left = min({ a * c, a * d, b * c, b * d }), right = max({ a * c, a * d, b * c, b * d }), kthNumber = 0;

        while (left <= right) {
            long long middle = (left + right) / 2;

            if (isNoGreaterTargetNoLessK(nums1, negatives1, nums2, negatives2, k, middle)) {
                kthNumber = middle;
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }

        return kthNumber;
    }

    bool isNoGreaterTargetNoLessK(vector<int>& nums1, int negatives1, vector<int>& nums2, int negatives2, long long k, long long target) {
        int size1 = nums1.size(), size2 = nums2.size();
        long long count = 0;

        if (target >= 0) {
            count = negatives1 * ((long long)size2 - negatives2) + negatives2 * ((long long)size1 - negatives1);
            if (count >= k) {
                return true;
            }

            count += countNegativeNegative(nums1, negatives1, nums2, negatives2, k, target);
            if (count >= k) {
                return true;
            }

            count += countPositivePositive(nums1, negatives1, nums2, negatives2, k, target);
            return count >= k;
        }
        else {
            count += countNegativePositive(nums1, negatives1, nums2, negatives2, k, target);
            if (count >= k) {
                return true;
            }

            count += countPositiveNegative(nums1, negatives1, nums2, negatives2, k, target);
            return count >= k;
        }
    }

    long long countNegativeNegative(vector<int>& nums1, int negatives1, vector<int>& nums2, int negatives2, long long k, long long target) {
        int size1 = nums1.size(), size2 = nums2.size(), i, j = 0;
        long long count = 0;

        for (i = negatives1 - 1; i >= 0; --i) {
            while (j < negatives2 && (long long)nums1[i] * nums2[j] > target) {
                ++j;
            }

            count += ((long long)negatives2 - j);
            if (count >= k || j == negatives2) {
                break;
            }
        }

        return count;
    }

    long long countNegativePositive(vector<int>& nums1, int negatives1, vector<int>& nums2, int negatives2, long long k, long long target) {
        int size1 = nums1.size(), size2 = nums2.size(), i, j = negatives2;
        long long count = 0;

        for (i = 0; i < negatives1; ++i) {
            while (j < size2 && (long long)nums1[i] * nums2[j] > target) {
                ++j;
            }

            count += ((long long)size2 - j);
            if (count >= k || j == size2) {
                break;
            }
        }

        return count;
    }

    long long countPositiveNegative(vector<int>& nums1, int negatives1, vector<int>& nums2, int negatives2, long long k, long long target) {
        int size1 = nums1.size(), size2 = nums2.size(), i, j = negatives2 - 1;
        long long count = 0;

        for (i = size1 - 1; i >= negatives1; --i) {
            while (j >= 0 && (long long)nums1[i] * nums2[j] > target) {
                --j;
            }

            count += ((long long)j + 1);
            if (count >= k || j < 0) {
                break;
            }
        }

        return count;
    }

    long long countPositivePositive(vector<int>& nums1, int negatives1, vector<int>& nums2, int negatives2, long long k, long long target) {
        int size1 = nums1.size(), size2 = nums2.size(), i, j = size2 - 1;
        long long count = 0;

        for (i = negatives1; i < size1; ++i) {
            while (j >= negatives2 && (long long)nums1[i] * nums2[j] > target) {
                --j;
            }

            count += ((long long)j + 1 - negatives2);
            if (count >= k || j < negatives2) {
                break;
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 2,5 };
    vector<int> nums2 = { 3,4 };
    check.checkLongLong(8, o.kthSmallestProduct(nums1, nums2, 2));

    nums1 = { -4,-2,0,3 };
    nums2 = { 2,4 };
    check.checkLongLong(0, o.kthSmallestProduct(nums1, nums2, 6));

    nums1 = { 3 };
    nums2 = { 4 };
    check.checkLongLong(12, o.kthSmallestProduct(nums1, nums2, 1));

    nums1 = { -10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10 };
    nums2 = { -10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10 };
    check.checkLongLong(-100, o.kthSmallestProduct(nums1, nums2, 1));
    check.checkLongLong(-24, o.kthSmallestProduct(nums1, nums2, 100));
    check.checkLongLong(-1, o.kthSmallestProduct(nums1, nums2, 200));
    check.checkLongLong(12, o.kthSmallestProduct(nums1, nums2, 300));
    check.checkLongLong(100, o.kthSmallestProduct(nums1, nums2, 441));
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
