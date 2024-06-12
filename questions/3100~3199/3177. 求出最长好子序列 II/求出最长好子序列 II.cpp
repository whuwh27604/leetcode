/* 求出最长好子序列 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个 非负 整数 k 。如果一个整数序列 seq 满足在范围下标范围 [0, seq.length - 2] 中存在 不超过 k 个下标 i 满足 seq[i] != seq[i + 1] ，那么我们称这个整数序列为 好 序列。

请你返回 nums 中 好
子序列
 的最长长度



示例 1：

输入：nums = [1,2,1,1,3], k = 2

输出：4

解释：

最长好子序列为 [1,2,1,1,3] 。

示例 2：

输入：nums = [1,2,3,4,5,1], k = 0

输出：2

解释：

最长好子序列为 [1,2,3,4,5,1] 。



提示：

1 <= nums.length <= 5 * 103
1 <= nums[i] <= 109
0 <= k <= min(50, nums.length)
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int dp1;
    int x1;
    int dp2;
    int x2;

    Node() : dp1(0), x1(0), dp2(0), x2(0) {}

    void insert(int dp, int x) {
        if (dp > dp1) {
            dp2 = dp1;
            x2 = x1;
            dp1 = dp;
            x1 = x;
        }
        else if (dp > dp2) {
            dp2 = dp;
            x2 = x;
        }
    }
};

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int size = (int)nums.size(), maxLen = 0;
        vector<int> numbers(size);
        int maxNum = discrete(nums, numbers);
        vector<vector<int>> dp(maxNum, vector<int>(k + 1, 0));
        vector<Node> maxDp(k + 1);  // 维护dp[][c]的最大2个

        /* dp[x][c]表示以x结尾，最多c个不同的最长子系列，那么对每一个x：
           1、不选x，那么dp[x][c]不变
           2、选x，作为子系列的第一个数，或者前面子系列的最后一个数也是x，那么dp[x][c] = dp[x][c] + 1
           3，选x，前面子系列的最后一个数是y，那么需要知道max(dp[y][c - 1]) */

        for (int x : numbers) {
            dp[x][0] += 1;
            maxDp[0].insert(dp[x][0], x);

            for (int c = k; c > 0; --c) {
                dp[x][c] += 1;
                Node& node = maxDp[c - 1];
                dp[x][c] = max(dp[x][c], (x == node.x1 ? node.dp2 : node.dp1) + 1);
                maxDp[c].insert(dp[x][c], x);
            }

            maxLen = max(maxLen, dp[x][k]);
        }

        return maxLen;
    }

    int discrete(vector<int>& nums, vector<int>& numbers) {
        int size = (int)nums.size(), idx = 0, number = 0;
        unordered_map<int, int> mp;

        for (int num : nums) {
            if (mp.count(num) == 0) {
                mp[num] = number++;
            }

            numbers[idx++] = mp[num];
        }

        return number;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,1,1,3 };
    check.checkInt(4, o.maximumLength(nums, 2));

    nums = { 1,2,3,4,5,1 };
    check.checkInt(2, o.maximumLength(nums, 0));

    nums = { 2 };
    check.checkInt(1, o.maximumLength(nums, 0));

    nums = { 29,30,30 };
    check.checkInt(2, o.maximumLength(nums, 0));

    nums = { 29,28,28 };
    check.checkInt(3, o.maximumLength(nums, 2));
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
