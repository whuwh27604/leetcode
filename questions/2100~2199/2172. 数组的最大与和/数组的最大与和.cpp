/* 数组的最大与和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组 nums 和一个整数 numSlots ，满足2 * numSlots >= n 。总共有 numSlots 个篮子，编号为 1 到 numSlots 。

你需要把所有 n 个整数分到这些篮子中，且每个篮子 至多 有 2 个整数。一种分配方案的 与和 定义为每个数与它所在篮子编号的 按位与运算 结果之和。

比方说，将数字 [1, 3] 放入篮子 1 中，[4, 6] 放入篮子 2 中，这个方案的与和为 (1 AND 1) + (3 AND 1) + (4 AND 2) + (6 AND 2) = 1 + 1 + 0 + 2 = 4 。
请你返回将 nums 中所有数放入 numSlots 个篮子中的最大与和。

 

示例 1：

输入：nums = [1,2,3,4,5,6], numSlots = 3
输出：9
解释：一个可行的方案是 [1, 4] 放入篮子 1 中，[2, 6] 放入篮子 2 中，[3, 5] 放入篮子 3 中。
最大与和为 (1 AND 1) + (4 AND 1) + (2 AND 2) + (6 AND 2) + (3 AND 3) + (5 AND 3) = 1 + 0 + 2 + 2 + 3 + 1 = 9 。
示例 2：

输入：nums = [1,3,10,4,7,1], numSlots = 9
输出：24
解释：一个可行的方案是 [1, 1] 放入篮子 1 中，[3] 放入篮子 3 中，[4] 放入篮子 4 中，[7] 放入篮子 7 中，[10] 放入篮子 9 中。
最大与和为 (1 AND 1) + (1 AND 1) + (3 AND 3) + (4 AND 4) + (7 AND 7) + (10 AND 9) = 1 + 1 + 3 + 4 + 7 + 8 = 24 。
注意，篮子 2 ，5 ，6 和 8 是空的，这是允许的。
 

提示：

n == nums.length
1 <= numSlots <= 9
1 <= n <= 2 * numSlots
1 <= nums[i] <= 15

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-and-sum-of-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        numSlots *= 2;
        int size = nums.size(), maxMask = (1 << numSlots);
        vector<int> dp(maxMask, 0);  // dp[mask]表示将nums的前popcount(mask)个数放入mask的位置，可以得到的最大和

        for (int mask = 0; mask < maxMask; ++mask) {
            int ones = popcount(mask);

            if (ones < size) {
                for (int slot = 1, bit = 1; slot <= numSlots; ++slot, bit <<= 1) {
                    if ((bit & mask) == 0) {  // 该位置可以放一个数，那就尝试放入
                        int nextMask = (mask | bit);
                        dp[nextMask] = max(dp[nextMask], dp[mask] + (nums[ones] & ((slot + 1) / 2)));
                    }
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }

    int popcount(int mask) {
        int count = 0;

        for (int bit = 1; bit < (1 << 20); bit <<= 1) {
            if ((bit & mask) != 0) {
                ++count;
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3,4,5,6 };
    check.checkInt(9, o.maximumANDSum(nums, 3));

    nums = { 1,3,10,4,7,1 };
    check.checkInt(24, o.maximumANDSum(nums, 9));

    nums = { 1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9 };
    check.checkInt(90, o.maximumANDSum(nums, 9));
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
