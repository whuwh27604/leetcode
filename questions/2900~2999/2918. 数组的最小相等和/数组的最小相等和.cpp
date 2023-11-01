/* 数组的最小相等和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个由正整数和 0 组成的数组 nums1 和 nums2 。

你必须将两个数组中的 所有 0 替换为 严格 正整数，并且满足两个数组中所有元素的和 相等 。

返回 最小 相等和 ，如果无法使两数组相等，则返回 -1 。



示例 1：

输入：nums1 = [3,2,0,1,0], nums2 = [6,5,0]
输出：12
解释：可以按下述方式替换数组中的 0 ：
- 用 2 和 4 替换 nums1 中的两个 0 。得到 nums1 = [3,2,2,1,4] 。
- 用 1 替换 nums2 中的一个 0 。得到 nums2 = [6,5,1] 。
两个数组的元素和相等，都等于 12 。可以证明这是可以获得的最小相等和。
示例 2：

输入：nums1 = [2,0,2,0], nums2 = [1,4]
输出：-1
解释：无法使两个数组的和相等。


提示：

1 <= nums1.length, nums2.length <= 105
0 <= nums1[i], nums2[i] <= 106
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int zero1 = 0, zero2 = 0;

        count(nums1, sum1, zero1);
        count(nums2, sum2, zero2);

        if (zero1 != 0 && zero2 != 0) {  // 如果两边都有0，那么一定有解，并且解就是和较大的一个
            return max(sum1 + zero1, sum2 + zero2);
        }

        if (zero1 != 0) {  // nums1有0，nums2没有0，那么1的和要小于等于2的和才有解
            return sum1 + zero1 <= sum2 ? sum2 : -1;
        }

        if (zero2 != 0) {  // nums2有0，nums1没有0，那么2的和要小于等于1的和才有解
            return sum2 + zero2 <= sum1 ? sum1 : -1;
        }

        return sum1 == sum2 ? sum1 : -1;  // 两边都没有0，只能原始和就相等
    }

    void count(vector<int>& nums, long long& sum, int& zero) {
        for (int num : nums) {
            if (num == 0) {
                ++zero;
            }
            else {
                sum += num;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 3,2,0,1,0 };
    vector<int> nums2 = { 6,5,0 };
    check.checkLongLong(12, o.minSum(nums1, nums2));

    nums1 = { 2,0,2,0 };
    nums2 = { 1,4 };
    check.checkLongLong(-1, o.minSum(nums1, nums2));
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
