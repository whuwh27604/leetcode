/* 满足条件的子序列数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个整数 target 。

请你统计并返回 nums 中能满足其最小元素与最大元素的 和 小于或等于 target 的 非空 子序列的数目。

由于答案可能很大，请将结果对 10^9 + 7 取余后返回。

 

示例 1：

输入：nums = [3,5,6,7], target = 9
输出：4
解释：有 4 个子序列满足该条件。
[3] -> 最小元素 + 最大元素 <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)
示例 2：

输入：nums = [3,3,6,8], target = 10
输出：6
解释：有 6 个子序列满足该条件。（nums 中可以有重复数字）
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
示例 3：

输入：nums = [2,3,3,4,6,7], target = 12
输出：61
解释：共有 63 个非空子序列，其中 2 个不满足条件（[6,7], [7]）
有效序列总数为（63 - 2 = 61）
示例 4：

输入：nums = [5,2,4,1,7,6,8], target = 16
输出：127
解释：所有非空子序列都满足条件 (2^7 - 1) = 127
 

提示：

1 <= nums.length <= 10^5
1 <= nums[i] <= 10^6
1 <= target <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int right = upper_bound(nums.begin(), nums.end(), target - nums[0]) - nums.begin() - 1;
        int mod = 1000000007, totalSubseqs = 0;
        vector<int> subseqs(right + 2);

        subseqs[0] = 1;
        for (int i = 1; i <= right; ++i) {
            subseqs[i] = (subseqs[i - 1] << 1) % mod;
        }

        for (int left = 0; left <= right; ++left) {
            for (; nums[left] + nums[right] > target && left <= right; --right) {}

            if (left <= right) {
                totalSubseqs = (totalSubseqs + subseqs[right - left]) % mod;
            }
        }

        return totalSubseqs;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,5,6,7 };
    check.checkInt(4, o.numSubseq(nums, 9));

    nums = { 3,3,6,8 };
    check.checkInt(6, o.numSubseq(nums, 10));

    nums = { 2,3,3,4,6,7 };
    check.checkInt(61, o.numSubseq(nums, 12));

    nums = { 5,2,4,1,7,6,8 };
    check.checkInt(127, o.numSubseq(nums, 16));

    nums = { 3 };
    check.checkInt(0, o.numSubseq(nums, 2));

    nums = { 3 };
    check.checkInt(0, o.numSubseq(nums, 3));

    nums = { 3 };
    check.checkInt(0, o.numSubseq(nums, 5));

    nums = { 3 };
    check.checkInt(1, o.numSubseq(nums, 6));

    nums = { 3,5 };
    check.checkInt(0, o.numSubseq(nums, 2));

    nums = { 3,5 };
    check.checkInt(0, o.numSubseq(nums, 3));

    nums = { 3,5 };
    check.checkInt(0, o.numSubseq(nums, 4));

    nums = { 3,5 };
    check.checkInt(0, o.numSubseq(nums, 5));

    nums = { 3,5 };
    check.checkInt(1, o.numSubseq(nums, 6));

    nums = { 3,5 };
    check.checkInt(2, o.numSubseq(nums, 8));

    nums = { 3,5 };
    check.checkInt(3, o.numSubseq(nums, 10));

    nums = { 3,5 };
    check.checkInt(3, o.numSubseq(nums, 11));

    nums = { 1,2,3,4,4,4,5,6 };
    check.checkInt(215, o.numSubseq(nums, 8));

    nums = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
    check.checkInt(896465608, o.numSubseq(nums, 20));
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
