/* 特别的排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums ，它包含 n 个 互不相同 的正整数。如果 nums 的一个排列满足以下条件，我们称它是一个特别的排列：

对于 0 <= i < n - 1 的下标 i ，要么 nums[i] % nums[i+1] == 0 ，要么 nums[i+1] % nums[i] == 0 。
请你返回特别排列的总数目，由于答案可能很大，请将它对 109 + 7 取余 后返回。



示例 1：

输入：nums = [2,3,6]
输出：2
解释：[3,6,2] 和 [2,6,3] 是 nums 两个特别的排列。
示例 2：

输入：nums = [1,4,3]
输出：2
解释：[3,1,4] 和 [4,1,3] 是 nums 两个特别的排列。


提示：

2 <= nums.length <= 14
1 <= nums[i] <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int specialPerm(vector<int>& nums) {
        int size = nums.size(), maxMask = (1 << size), count = 0, mod = 1000000007;
        vector<vector<int>> dp(size, vector<int>(maxMask, 0));  // dp[last][mask]表示排列的最后一个数索引是last，还剩下mask可选时的排列总数

        for (int last = 0; last < size; ++last) {
            dp[last][0] = 1;  // 所有数都已经选完，构成一个合法排列
        }

        for (int mask = 1; mask < maxMask; ++mask) {
            for (int last = 0, bit = 1; last < size; ++last, bit <<= 1) {
                if ((mask & bit) == 0) {  // 因为last已经被选了，剩下的mask里面不能有last
                    for (int cur = 0, bit1 = 1; cur < size; ++cur, bit1 <<= 1) {  // 枚举当前可选的数
                        if (((mask & bit1) != 0) && (nums[last] % nums[cur] == 0 || nums[cur] % nums[last] == 0)) {  // cur可以接在last后面
                            dp[last][mask] = (dp[last][mask] + dp[cur][mask ^ bit1]) % mod;
                        }
                    }
                }
            }
        }

        for (int last = 0, bit = 1; last < size; ++last, bit <<= 1) {
            count = (count + dp[last][(maxMask - 1) ^ bit]) % mod;  // 答案是枚举第一个数，剩下mask的排列总和
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,3,6 };
    check.checkInt(2, o.specialPerm(nums));

    nums = { 1,4,3 };
    check.checkInt(2, o.specialPerm(nums));

    nums = { 1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192 };
    check.checkInt(178290591, o.specialPerm(nums));
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
