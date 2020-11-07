/* 打家劫舍.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

 

示例 1：

输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2：

输入：[2,7,9,3,1]
输出：12
解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 

提示：

0 <= nums.length <= 100
0 <= nums[i] <= 400

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/house-robber
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return nums[0];
        }

        // dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
        int prevTwo = nums[0], prev = max(nums[0], nums[1]), dp = prev;
        for (int i = 2; i < len; i++) {
            dp = max(prevTwo + nums[i], prev);
            prevTwo = prev;
            prev = dp;
        }

        return dp;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = {};
    check.checkInt(0, o.rob(nums));

    nums = {4};
    check.checkInt(4, o.rob(nums));

    nums = { 4,6 };
    check.checkInt(6, o.rob(nums));

    nums = { 1,4,2 };
    check.checkInt(4, o.rob(nums));

    nums = { 2,4,3 };
    check.checkInt(5, o.rob(nums));

    nums = { 1,2,3,1 };
    check.checkInt(4, o.rob(nums));

    nums = { 2,7,9,3,1 };
    check.checkInt(12, o.rob(nums));

    nums = { 2,7,9,3,1,3 };
    check.checkInt(14, o.rob(nums));
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
