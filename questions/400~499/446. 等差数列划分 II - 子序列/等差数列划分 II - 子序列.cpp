/* 等差数列划分 II - 子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，返回 nums 中所有 等差子序列 的数目。

如果一个序列中 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该序列为等差序列。

例如，[1, 3, 5, 7, 9]、[7, 7, 7, 7] 和 [3, -1, -5, -9] 都是等差序列。
再例如，[1, 1, 2, 5, 7] 不是等差序列。
数组中的子序列是从数组中删除一些元素（也可能不删除）得到的一个序列。

例如，[2,5,10] 是 [1,2,1,2,4,1,5,10] 的一个子序列。
题目数据保证答案是一个 32-bit 整数。

 

示例 1：

输入：nums = [2,4,6,8,10]
输出：7
解释：所有的等差子序列为：
[2,4,6]
[4,6,8]
[6,8,10]
[2,4,6,8]
[4,6,8,10]
[2,4,6,8,10]
[2,6,10]
示例 2：

输入：nums = [7,7,7,7,7]
输出：16
解释：数组中的任意子序列都是等差子序列。
 

提示：

1  <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int i, j, size = nums.size(), count = 0;
        vector<unordered_map<long long, int>> dp(size);  // 以nums[i]为结尾，公差为diff的子系列的个数

        for (i = 1; i < size; ++i) {
            for (j = 0; j < i; ++j) {
                long long diff = (long long)nums[i] - nums[j];

                if (dp[j].count(diff) == 0) {
                    dp[i][diff] += 1;  // 两个数的等差序列
                }
                else {
                    count += dp[j][diff];  // 三个以上的等差序列
                    dp[i][diff] += (dp[j][diff] + 1);  // nums[j]、nums[i]可以构成一个两个数的序列，所以要加1
                }
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,4,6,8,10 };
    check.checkInt(7, o.numberOfArithmeticSlices(nums));

    nums = { 7,7,7,7,7 };
    check.checkInt(16, o.numberOfArithmeticSlices(nums));

    nums = { 7 };
    check.checkInt(0, o.numberOfArithmeticSlices(nums));

    nums = { 7,7 };
    check.checkInt(0, o.numberOfArithmeticSlices(nums));

    nums = { 0,1,2,3,4,5,6,7,8,9 };
    check.checkInt(55, o.numberOfArithmeticSlices(nums));

    nums = { 4,1,1,1,1 };
    check.checkInt(5, o.numberOfArithmeticSlices(nums));

    nums = { 2,2,3,4 };
    check.checkInt(2, o.numberOfArithmeticSlices(nums));
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
