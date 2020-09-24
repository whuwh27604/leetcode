/* 组合总和 Ⅳ.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。

示例:

nums = [1, 2, 3]
target = 4

所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

请注意，顺序不同的序列被视作不同的组合。

因此输出为 7。
进阶：
如果给定的数组中含有负数会怎么样？
问题会产生什么变化？
我们需要在题目中添加什么限制来允许负数的出现？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[i] = sum(dp[i-nums[0]], dp[i-nums[1]] ... dp[i-nums[size-1]])
        long long* dp = new long long[target + 1]();
        dp[0] = 1;  // 理解为啥也不选，结果为0，算一种方法；或者i等于nums里面的某个数，直接选这个数是一种方法。

        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                dp[i] += (i - num < 0 ? 0 : dp[i - num]);
                if (dp[i] > INT_MAX) {
                    dp[i] = 0;  // 超出整型范围的结果，int无法表示，实际是多少无所谓了。
                }
            }
        }

        int ans = (int)dp[target];
        delete[] dp;

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3 };
    check.checkInt(1, o.combinationSum4(nums, 1));
    check.checkInt(2, o.combinationSum4(nums, 2));
    check.checkInt(4, o.combinationSum4(nums, 3));
    check.checkInt(7, o.combinationSum4(nums, 4));
    check.checkInt(1132436852, o.combinationSum4(nums, 35));
    check.checkInt(2082876103, o.combinationSum4(nums, 36));

    nums = { 3,5 };
    check.checkInt(0, o.combinationSum4(nums, 1));
    check.checkInt(0, o.combinationSum4(nums, 2));
    check.checkInt(1, o.combinationSum4(nums, 3));
    check.checkInt(0, o.combinationSum4(nums, 4));
    check.checkInt(1, o.combinationSum4(nums, 5));
    check.checkInt(1, o.combinationSum4(nums, 6));
    check.checkInt(0, o.combinationSum4(nums, 7));
    check.checkInt(2, o.combinationSum4(nums, 8));
    check.checkInt(12964858, o.combinationSum4(nums, 100));
    check.checkInt(1850966760, o.combinationSum4(nums, 128));
    
    nums = {  };
    check.checkInt(0, o.combinationSum4(nums, 1));

    nums = { 3 };
    check.checkInt(0, o.combinationSum4(nums, 1));
    check.checkInt(0, o.combinationSum4(nums, 2));
    check.checkInt(1, o.combinationSum4(nums, 3));
    check.checkInt(0, o.combinationSum4(nums, 4));
    check.checkInt(0, o.combinationSum4(nums, 5));
    check.checkInt(1, o.combinationSum4(nums, 6));
    check.checkInt(0, o.combinationSum4(nums, 7));

    nums = { 3,33,333 };
    check.checkInt(0, o.combinationSum4(nums, 10000));
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
