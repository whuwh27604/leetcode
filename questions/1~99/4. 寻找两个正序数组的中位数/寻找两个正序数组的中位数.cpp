/* 寻找两个正序数组的中位数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。

进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？

 

示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
示例 3：

输入：nums1 = [0,0], nums2 = [0,0]
输出：0.00000
示例 4：

输入：nums1 = [], nums2 = [1]
输出：1.00000
示例 5：

输入：nums1 = [2], nums2 = []
输出：2.00000
 

提示：

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size(), size = size1 + size2;
        if (size1 > size2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int rank1Low = 0, rank1High = size1, median1 = 0, median2 = 0;  // nums1最少一个也不出，最多出size1个数

        while (rank1Low <= rank1High) {
            int rank1Mid = (rank1Low + rank1High) / 2;
            int rank2 = (size + 1) / 2 - rank1Mid;  // nums1出mid个数，那么nums2需要出总个数的一半-mid个数
            int nums1LowMax = (rank1Mid == 0) ? INT_MIN : nums1[rank1Mid - 1];
            int nums1HighMin = (rank1Mid == size1) ? INT_MAX : nums1[rank1Mid];
            int nums2LowMax = (rank2 == 0) ? INT_MIN : nums2[rank2 - 1];
            int nums2HighMin = (rank2 == size2) ? INT_MAX : nums2[rank2];

            if (nums1LowMax <= nums2HighMin) {
                rank1Low = rank1Mid + 1;  // nums1出的数少了，尝试增多

                median1 = max(nums1LowMax, nums2LowMax);  // 合并nums1、nums2的low区间，找出最大值
                median2 = min(nums1HighMin, nums2HighMin);  // 合并nums1、nums2的high区间，找出最小值
            }
            else {
                rank1High = rank1Mid - 1;  // nums1出的数少了，尝试减少
            }
        }

        return size % 2 == 0 ? ((double)median1 + median2) / 2 : median1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 1,3,4,9 };
    vector<int> nums2 = { 1,2,3,4,5,6,7,8,9 };
    check.checkDouble(4, o.findMedianSortedArrays(nums1, nums2));

    nums1 = { 1,3 };
    nums2 = { 2 };
    check.checkDouble(2, o.findMedianSortedArrays(nums1, nums2));

    nums1 = { 1,2 };
    nums2 = { 3,4 };
    check.checkDouble(2.5, o.findMedianSortedArrays(nums1, nums2));

    nums1 = { 0,0 };
    nums2 = { 0,0 };
    check.checkDouble(0, o.findMedianSortedArrays(nums1, nums2));

    nums1 = {  };
    nums2 = { 1 };
    check.checkDouble(1, o.findMedianSortedArrays(nums1, nums2));

    nums1 = { 2 };
    nums2 = {  };
    check.checkDouble(2, o.findMedianSortedArrays(nums1, nums2));

    nums1 = { 1,1,1,1,1,1,1,1,1,1,4,4 };
    nums2 = { 1,3,4,4,4,4,4,4,4,4,4 };
    check.checkDouble(3, o.findMedianSortedArrays(nums1, nums2));
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
