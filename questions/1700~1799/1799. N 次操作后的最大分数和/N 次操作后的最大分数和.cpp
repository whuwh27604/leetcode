/* N 次操作后的最大分数和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你 nums ，它是一个大小为 2 * n 的正整数数组。你必须对这个数组执行 n 次操作。

在第 i 次操作时（操作编号从 1 开始），你需要：

选择两个元素 x 和 y 。
获得分数 i * gcd(x, y) 。
将 x 和 y 从 nums 中删除。
请你返回 n 次操作后你能获得的分数和最大为多少。

函数 gcd(x, y) 是 x 和 y 的最大公约数。

 

示例 1：

输入：nums = [1,2]
输出：1
解释：最优操作是：
(1 * gcd(1, 2)) = 1
示例 2：

输入：nums = [3,4,6,8]
输出：11
解释：最优操作是：
(1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11
示例 3：

输入：nums = [1,2,3,4,5,6]
输出：14
解释：最优操作是：
(1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
 

提示：

1 <= n <= 7
nums.length == 2 * n
1 <= nums[i] <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximize-score-after-n-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        int size = nums.size(), n = size / 2, len = 1 << size;
        vector<int> dp(len, 0);

        for (int bits = 3; bits < len; ++bits) {
            int count = countBits(bits);

            if ((count & 1) == 0) {
                for (int i = 0, bit1 = 1; i < size - 1; ++i, bit1 <<= 1) {
                    if ((bits & bit1) != 0) {
                        for (int j = i + 1, bit2 = (bit1 << 1); j < size; ++j, bit2 <<= 1) {
                            if ((bits & bit2) != 0) {
                                dp[bits] = max(dp[bits], (count / 2) * gcd(nums[i], nums[j]) + dp[bits ^ bit1 ^ bit2]);
                            }
                        }
                    }
                }
            }
        }

        return dp[len - 1];
    }

    int countBits(int bits) {
        int count = 0;

        while (bits != 0) {
            count += (bits & 1);
            bits >>= 1;
        }

        return count;
    }

    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2 };
    check.checkInt(1, o.maxScore(nums));

    nums = { 5,10 };
    check.checkInt(5, o.maxScore(nums));

    nums = { 3,4,6,8 };
    check.checkInt(11, o.maxScore(nums));

    nums = { 1,2,3,4,5,6 };
    check.checkInt(14, o.maxScore(nums));

    nums = { 2,2,2,2,2,2,2,2,2,2,2,2,2,2 };
    check.checkInt(56, o.maxScore(nums));

    nums = { 123,456,789,1234,5678,3456,12345,23456,34567,45678,56789,2,8,16 };
    check.checkInt(323, o.maxScore(nums));
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
