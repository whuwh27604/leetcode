/* 两个子序列的最大点积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个数组 nums1 和 nums2 。

请你返回 nums1 和 nums2 中两个长度相同的 非空 子序列的最大点积。

数组的非空子序列是通过删除原数组中某些元素（可能一个也不删除）后剩余数字组成的序列，但不能改变数字间相对顺序。比方说，[2,3,5] 是 [1,2,3,4,5] 的一个子序列而 [1,5,3] 不是。

 

示例 1：

输入：nums1 = [2,1,-2,5], nums2 = [3,0,-6]
输出：18
解释：从 nums1 中得到子序列 [2,-2] ，从 nums2 中得到子序列 [3,-6] 。
它们的点积为 (2*3 + (-2)*(-6)) = 18 。
示例 2：

输入：nums1 = [3,-2], nums2 = [2,-6,7]
输出：21
解释：从 nums1 中得到子序列 [3] ，从 nums2 中得到子序列 [7] 。
它们的点积为 (3*7) = 21 。
示例 3：

输入：nums1 = [-1,-1], nums2 = [1,1]
输出：-1
解释：从 nums1 中得到子序列 [-1] ，从 nums2 中得到子序列 [1] 。
它们的点积为 -1 。
 

提示：

1 <= nums1.length, nums2.length <= 500
-1000 <= nums1[i], nums2[i] <= 100
 

点积：

定义 a = [a1, a2,…, an] 和 b = [b1, b2,…, bn] 的点积为：



这里的 Σ 指示总和符号。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-dot-product-of-two-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int i, j, size1 = nums1.size(), size2 = nums2.size();
        vector<vector<int>> dp(size1, vector<int>(size2));
        dp[0][0] = nums1[0] * nums2[0];

        for (i = 1; i < size1; ++i) {
            dp[i][0] = max(dp[i - 1][0], nums1[i] * nums2[0]);
        }

        for (j = 1; j < size2; ++j) {
            dp[0][j] = max(dp[0][j - 1], nums1[0] * nums2[j]);
        }

        for (i = 1; i < size1; ++i) {
            for (j = 1; j < size2; ++j) {
                dp[i][j] = max({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + nums1[i] * nums2[j], nums1[i] * nums2[j] });
            }
        }

        return dp[size1 - 1][size2 - 1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 2,1,-2,5 };
    vector<int> nums2 = { 3,0,-6 };
    check.checkInt(18, o.maxDotProduct(nums1, nums2));

    nums1 = { 3,-2 };
    nums2 = { 2,-6,7 };
    check.checkInt(21, o.maxDotProduct(nums1, nums2));

    nums1 = { -1,-1 };
    nums2 = { 1,1 };
    check.checkInt(-1, o.maxDotProduct(nums1, nums2));

    nums1 = { -3,-8,3,-10,1,3,9 };
    nums2 = { 9,2,3,7,-9,1,-8,5,-1,-1 };
    check.checkInt(200, o.maxDotProduct(nums1, nums2));

    nums1 = { 3 };
    nums2 = { -2 };
    check.checkInt(-6, o.maxDotProduct(nums1, nums2));
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
