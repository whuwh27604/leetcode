/* 使数组中所有元素相等的最小操作数 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个整数数组 nums1 和 nums2 ，两个数组长度都是 n ，再给你一个整数 k 。你可以对数组 nums1 进行以下操作：

选择两个下标 i 和 j ，将 nums1[i] 增加 k ，将 nums1[j] 减少 k 。换言之，nums1[i] = nums1[i] + k 且 nums1[j] = nums1[j] - k 。
如果对于所有满足 0 <= i < n 都有 num1[i] == nums2[i] ，那么我们称 nums1 等于 nums2 。

请你返回使 nums1 等于 nums2 的 最少 操作数。如果没办法让它们相等，请你返回 -1 。



示例 1：

输入：nums1 = [4,3,1,4], nums2 = [1,3,7,1], k = 3
输出：2
解释：我们可以通过 2 个操作将 nums1 变成 nums2 。
第 1 个操作：i = 2 ，j = 0 。操作后得到 nums1 = [1,3,4,4] 。
第 2 个操作：i = 2 ，j = 3 。操作后得到 nums1 = [1,3,7,1] 。
无法用更少操作使两个数组相等。
示例 2：

输入：nums1 = [3,8,5,2], nums2 = [2,4,1,6], k = 1
输出：-1
解释：无法使两个数组相等。


提示：

n == nums1.length == nums2.length
2 <= n <= 105
0 <= nums1[i], nums2[j] <= 109
0 <= k <= 105
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k == 0) {
            return nums1 == nums2 ? 0 : -1;
        }

        int size = nums1.size();
        long long inc = 0, dec = 0;

        for (int i = 0; i < size; ++i) {
            int x = nums1[i], y = nums2[i];
            int diff = x > y ? x - y : y - x;
            if (diff % k != 0) {
                return -1;
            }

            diff /= k;
            if (x > y) {
                inc += diff;
            }
            else {
                dec += diff;
            }
        }

        return inc == dec ? inc : -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 4,3,1,4 };
    vector<int> nums2 = { 1,3,7,1 };
    check.checkLongLong(2, o.minOperations(nums1, nums2, 3));

    nums1 = { 3,8,5,2 };
    nums2 = { 2,4,1,6 };
    check.checkLongLong(-1, o.minOperations(nums1, nums2, 1));

    nums1 = { 1,2,3 };
    nums2 = { 1,2,3 };
    check.checkLongLong(0, o.minOperations(nums1, nums2, 0));

    nums1 = { 1,2,3 };
    nums2 = { 1,2,2 };
    check.checkLongLong(-1, o.minOperations(nums1, nums2, 0));
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
