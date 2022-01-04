/* 两个数组最小的异或值之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数数组 nums1 和 nums2 ，它们长度都为 n 。

两个数组的 异或值之和 为 (nums1[0] XOR nums2[0]) + (nums1[1] XOR nums2[1]) + ... + (nums1[n - 1] XOR nums2[n - 1]) （下标从 0 开始）。

比方说，[1,2,3] 和 [3,2,1] 的 异或值之和 等于 (1 XOR 3) + (2 XOR 2) + (3 XOR 1) = 2 + 0 + 2 = 4 。
请你将 nums2 中的元素重新排列，使得 异或值之和 最小 。

请你返回重新排列之后的 异或值之和 。

 

示例 1：

输入：nums1 = [1,2], nums2 = [2,3]
输出：2
解释：将 nums2 重新排列得到 [3,2] 。
异或值之和为 (1 XOR 3) + (2 XOR 2) = 2 + 0 = 2 。
示例 2：

输入：nums1 = [1,0,3], nums2 = [5,3,4]
输出：8
解释：将 nums2 重新排列得到 [5,4,3] 。
异或值之和为 (1 XOR 5) + (0 XOR 4) + (3 XOR 3) = 4 + 4 + 0 = 8 。
 

提示：

n == nums1.length
n == nums2.length
1 <= n <= 14
0 <= nums1[i], nums2[i] <= 107

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-xor-sum-of-two-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size(), maxMask = 1 << size;
        vector<int> dp(maxMask, INT_MAX);  // dp[mask]表示nums2选mask选中的i个数，nums1选前i个数，可以得到的最小值
        dp[0] = 0;

        for (int mask = 1; mask < maxMask; ++mask) {
            int count = popcount(mask);

            for (int i = 0, bit = 1; i < size; ++i, bit <<= 1) {  // 让nums1的最后一个数和所有的nums2匹配，然后加上剩下的数组异或和
                if ((mask & bit) != 0) {
                    dp[mask] = min(dp[mask], dp[mask ^ bit] + (nums1[count - 1] ^ nums2[i]));
                }
            }
        }

        return dp[maxMask - 1];
    }

    int popcount(int mask) {
        int count = 0;

        while (mask != 0) {
            if ((mask & 1) != 0) {
                ++count;
            }

            mask >>= 1;
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 1,2 };
    vector<int> nums2 = { 2,3 };
    check.checkInt(2, o.minimumXORSum(nums1, nums2));

    nums1 = { 1,0,3 };
    nums2 = { 5,3,4 };
    check.checkInt(8, o.minimumXORSum(nums1, nums2));

    nums1 = { 1 };
    nums2 = { 1 };
    check.checkInt(0, o.minimumXORSum(nums1, nums2));

    nums1 = { 1 };
    nums2 = { 2 };
    check.checkInt(3, o.minimumXORSum(nums1, nums2));

    nums1 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
    nums2 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
    check.checkInt(0, o.minimumXORSum(nums1, nums2));

    nums1 = { 1,10,100,1000,10000,2,12,120,1200,12000,3,13,130,1300 };
    nums2 = { 99999,99990,88888,88880,77777,77770,66666,66660,55555,55550,44444,44440,33333,33330 };
    check.checkInt(907921, o.minimumXORSum(nums1, nums2));
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
