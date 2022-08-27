/* 找出数组的第 K 大和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个 正 整数 k 。你可以选择数组的任一 子序列 并且对其全部元素求和。

数组的 第 k 大和 定义为：可以获得的第 k 个 最大 子序列和（子序列和允许出现重复）

返回数组的 第 k 大和 。

子序列是一个可以由其他数组删除某些或不删除元素排生而来的数组，且派生过程不改变剩余元素的顺序。

注意：空子序列的和视作 0 。

 

示例 1：

输入：nums = [2,4,-2], k = 5
输出：2
解释：所有可能获得的子序列和列出如下，按递减顺序排列：
- 6、4、4、2、2、0、0、-2
数组的第 5 大和是 2 。
示例 2：

输入：nums = [1,-2,3,4,-10,12], k = 16
输出：10
解释：数组的第 16 大和是 10 。
 

提示：

n == nums.length
1 <= n <= 105
-109 <= nums[i] <= 109
1 <= k <= min(2000, 2n)

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-the-k-sum-of-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long sum = getMaxSum(nums);
        if (k == 1) {
            return sum;
        }

        sort(nums.begin(), nums.end());

        return sum - getMinKSum(nums, k);
    }

    long long getMaxSum(vector<int>& nums) {
        long long sum = 0;

        for (int& num : nums) {
            if (num >= 0) {
                sum += num;
            }
            else {
                num = -num;  // 先计算正数的最大和，然后每次减去最小的正数序列，或者是加入最大的负数序列（这等价于减去该负数的绝对值，所以负数取反）
            }
        }

        return sum;
    }

    long long getMinKSum(vector<int>& nums, int k) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> minSeqSums;
        minSeqSums.push({ nums[0],0 });

        for (int i = 2; i < k; ++i) {
            long long seqSum = minSeqSums.top().first;
            int lastIndex = minSeqSums.top().second;
            minSeqSums.pop();

            /* 对以lastIndex结尾的序列，后续枚举两个序列：1、直接加入lastIndex + 1；2、用lastIndex + 1替换lastIndex
               1、这样可以不重复、不遗漏的枚举所有序列
               2、每次新枚举的序列一定比队列头部的序列sum要大 */
            if (lastIndex != nums.size() - 1) {
                minSeqSums.push({ seqSum - nums[lastIndex] + nums[lastIndex + 1], lastIndex + 1 });
                minSeqSums.push({ seqSum + nums[lastIndex + 1], lastIndex + 1 });
            }
        }

        return minSeqSums.top().first;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,4,-2 };
    check.checkLongLong(6, o.kSum(nums, 1));

    nums = { 2,4,-2 };
    check.checkLongLong(4, o.kSum(nums, 2));

    nums = { 2,4,-2 };
    check.checkLongLong(4, o.kSum(nums, 3));

    nums = { 2,4,-2 };
    check.checkLongLong(2, o.kSum(nums, 4));

    nums = { 2,4,-2 };
    check.checkLongLong(2, o.kSum(nums, 5));

    nums = { 2,4,-2 };
    check.checkLongLong(0, o.kSum(nums, 6));

    nums = { 2,4,-2 };
    check.checkLongLong(0, o.kSum(nums, 7));

    nums = { 2,4,-2 };
    check.checkLongLong(-2, o.kSum(nums, 8));

    nums = { 1,-2,3,4,-10,12 };
    check.checkLongLong(10, o.kSum(nums, 16));

    nums = { 1 };
    check.checkLongLong(1, o.kSum(nums, 1));

    nums = { 1 };
    check.checkLongLong(0, o.kSum(nums, 2));

    nums = { -5 };
    check.checkLongLong(0, o.kSum(nums, 1));

    nums = { -5 };
    check.checkLongLong(-5, o.kSum(nums, 2));

    nums = { 3,5 };
    check.checkLongLong(0, o.kSum(nums, 4));
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
