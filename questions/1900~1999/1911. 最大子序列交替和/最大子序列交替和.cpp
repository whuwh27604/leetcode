/* 最大子序列交替和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个下标从 0 开始的数组的 交替和 定义为 偶数 下标处元素之 和 减去 奇数 下标处元素之 和 。

比方说，数组 [4,2,5,3] 的交替和为 (4 + 5) - (2 + 3) = 4 。
给你一个数组 nums ，请你返回 nums 中任意子序列的 最大交替和 （子序列的下标 重新 从 0 开始编号）。

一个数组的 子序列 是从原数组中删除一些元素后（也可能一个也不删除）剩余元素不改变顺序组成的数组。比方说，[2,7,4] 是 [4,2,3,7,2,1,4] 的一个子序列（加粗元素），但是 [2,4,2] 不是。

 

示例 1：

输入：nums = [4,2,5,3]
输出：7
解释：最优子序列为 [4,2,5] ，交替和为 (4 + 5) - 2 = 7 。
示例 2：

输入：nums = [5,6,7,8]
输出：8
解释：最优子序列为 [8] ，交替和为 8 。
示例 3：

输入：nums = [6,2,1,2,4,5]
输出：10
解释：最优子序列为 [6,1,5] ，交替和为 (6 + 5) - 1 = 10 。
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-alternating-subsequence-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        /* 1、最优子序列必为奇数个，因为偶数个去掉最后一个数会得到更优解
           2、如果nums[i-1] > nums[i]，那么nums[i]不在最优子序列。因为：假设nums[i-1]在最优子序列，那么同时去掉nums[i-1]和nums[i]是一个更好的结果；
              假设nums[i-1]不在最优子序列，那么用nums[i-1]替换nums[i]是一个更好的结果。
           3、如果nums[i-1] < nums[i]，那么nums[i]必然在最优子序列。 */
        long long sum = 0;
        int prev = 0;

        for (int num : nums) {
            if (num > prev) {
                sum += ((long long)num - prev);
            }

            prev = num;
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 4,2,5,3 };
    check.checkLongLong(7, o.maxAlternatingSum(nums));

    nums = { 5,6,7,8 };
    check.checkLongLong(8, o.maxAlternatingSum(nums));

    nums = { 6,2,1,2,4,5 };
    check.checkLongLong(10, o.maxAlternatingSum(nums));
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
