/* 找出有效子序列的最大长度 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个 正 整数 k 。
nums 的一个
子序列
 sub 的长度为 x ，如果其满足以下条件，则称其为 有效子序列 ：

(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k
返回 nums 的 最长有效子序列 的长度。


示例 1：

输入：nums = [1,2,3,4,5], k = 2

输出：5

解释：

最长有效子序列是 [1, 2, 3, 4, 5] 。

示例 2：

输入：nums = [1,4,2,3,1,4], k = 3

输出：4

解释：

最长有效子序列是 [1, 4, 1, 4] 。



提示：

2 <= nums.length <= 103
1 <= nums[i] <= 107
1 <= k <= 103
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int maxLen = 2;

        for (int rem = 0; rem < k; ++rem) {  // 枚举子序列的余数 = (nums[i] + nums[j]) % k
            vector<int> dp(k, 0);  // dp[r]表示以余数r为结尾的最大长度

            for (int num : nums) {
                int r1 = num % k;
                int r2 = (rem + k - r1) % k;
                dp[r1] = dp[r2] + 1;  // num可以接在前面余数为r2的数后面
                maxLen = max(maxLen, dp[r1]);
            }
        }

        return maxLen;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3,4,5 };
    check.checkInt(5, o.maximumLength(nums, 2));

    nums = { 1,4,2,3,1,4 };
    check.checkInt(4, o.maximumLength(nums, 3));
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
