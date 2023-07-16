/* 构造最长非递减子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个下标从 0 开始的整数数组 nums1 和 nums2 ，长度均为 n 。

让我们定义另一个下标从 0 开始、长度为 n 的整数数组，nums3 。对于范围 [0, n - 1] 的每个下标 i ，你可以将 nums1[i] 或 nums2[i] 的值赋给 nums3[i] 。

你的任务是使用最优策略为 nums3 赋值，以最大化 nums3 中 最长非递减子数组 的长度。

以整数形式表示并返回 nums3 中 最长非递减 子数组的长度。

注意：子数组 是数组中的一个连续非空元素序列。



示例 1：

输入：nums1 = [2,3,1], nums2 = [1,2,1]
输出：2
解释：构造 nums3 的方法之一是：
nums3 = [nums1[0], nums2[1], nums2[2]] => [2,2,1]
从下标 0 开始到下标 1 结束，形成了一个长度为 2 的非递减子数组 [2,2] 。
可以证明 2 是可达到的最大长度。
示例 2：

输入：nums1 = [1,3,2,1], nums2 = [2,2,3,4]
输出：4
解释：构造 nums3 的方法之一是：
nums3 = [nums1[0], nums2[1], nums2[2], nums2[3]] => [1,2,3,4]
整个数组形成了一个长度为 4 的非递减子数组，并且是可达到的最大长度。
示例 3：

输入：nums1 = [1,1], nums2 = [2,2]
输出：2
解释：构造 nums3 的方法之一是：
nums3 = [nums1[0], nums1[1]] => [1,1]
整个数组形成了一个长度为 2 的非递减子数组，并且是可达到的最大长度。


提示：

1 <= nums1.length == nums2.length == n <= 105
1 <= nums1[i], nums2[i] <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), ans = 1;
        vector<int> dp1(n, 1), dp2(n, 1);

        for (int i = n - 2; i >= 0; --i) {
            int current1 = min(nums1[i], nums2[i]), current2 = max(nums1[i], nums2[i]);
            int next1 = min(nums1[i + 1], nums2[i + 1]), next2 = max(nums1[i + 1], nums2[i + 1]);

            if (current1 <= next1) {
                dp1[i] = 1 + dp1[i + 1];
            }
            if (current1 <= next2) {
                dp1[i] = max(dp1[i], 1 + dp2[i + 1]);
            }

            ans = max(ans, dp1[i]);

            if (current2 <= next1) {
                dp2[i] = 1 + dp1[i + 1];
            }
            if (current2 <= next2) {
                dp2[i] = max(dp2[i], 1 + dp2[i + 1]);
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 2,3,1 };
    vector<int> nums2 = { 1,2,1 };
    check.checkInt(2, o.maxNonDecreasingLength(nums1, nums2));

    nums1 = { 1,3,2,1 };
    nums2 = { 2,2,3,4 };
    check.checkInt(4, o.maxNonDecreasingLength(nums1, nums2));

    nums1 = { 1,1 };
    nums2 = { 2,2 };
    check.checkInt(2, o.maxNonDecreasingLength(nums1, nums2));

    nums1 = { 5 };
    nums2 = { 3 };
    check.checkInt(1, o.maxNonDecreasingLength(nums1, nums2));

    nums1 = { 8,7,4 };
    nums2 = { 13,4,4 };
    check.checkInt(2, o.maxNonDecreasingLength(nums1, nums2));
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
