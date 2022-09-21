/* 按位或最大的最小子数组长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 下标从 0 开始的数组 nums ，数组中所有数字均为非负整数。对于 0 到 n - 1 之间的每一个下标 i ，你需要找出 nums 中一个 最小 非空子数组，它的起始位置为 i （包含这个位置），同时有 最大 的 按位或运算值 。

换言之，令 Bij 表示子数组 nums[i...j] 的按位或运算的结果，你需要找到一个起始位置为 i 的最小子数组，这个子数组的按位或运算的结果等于 max(Bik) ，其中 i <= k <= n - 1 。
一个数组的按位或运算值是这个数组里所有数字按位或运算的结果。

请你返回一个大小为 n 的整数数组 answer，其中 answer[i]是开始位置为 i ，按位或运算结果最大，且 最短 子数组的长度。

子数组 是数组里一段连续非空元素组成的序列。

 

示例 1：

输入：nums = [1,0,2,1,3]
输出：[3,3,2,2,1]
解释：
任何位置开始，最大按位或运算的结果都是 3 。
- 下标 0 处，能得到结果 3 的最短子数组是 [1,0,2] 。
- 下标 1 处，能得到结果 3 的最短子数组是 [0,2,1] 。
- 下标 2 处，能得到结果 3 的最短子数组是 [2,1] 。
- 下标 3 处，能得到结果 3 的最短子数组是 [1,3] 。
- 下标 4 处，能得到结果 3 的最短子数组是 [3] 。
所以我们返回 [3,3,2,2,1] 。
示例 2：

输入：nums = [1,2]
输出：[2,1]
解释：
下标 0 处，能得到最大按位或运算值的最短子数组长度为 2 。
下标 1 处，能得到最大按位或运算值的最短子数组长度为 1 。
所以我们返回 [2,1] 。
 

提示：

n == nums.length
1 <= n <= 105
0 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/smallest-subarrays-with-maximum-bitwise-or
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int size = nums.size();
        vector<int> rightOnes(31, size), ans(size, 1);

        for (int i = size - 1; i >= 0; --i) {
            for (int j = 0, num = nums[i]; j < 31; ++j, num >>= 1) {
                if ((num & 1) == 0) {  // 如果当前bit位是0，那么需要尝试或一个该bit位为1的数
                    if (rightOnes[j] != size) {
                        ans[i] = max(ans[i], rightOnes[j] - i + 1);
                    }
                }
                else {  // 如果当前bit位是1，不需要再或任何数，记录下该索引
                    rightOnes[j] = i;
                }
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,0,2,1,3 };
    vector<int> actual = o.smallestSubarrays(nums);
    vector<int> expected = { 3,3,2,2,1 };
    check.checkIntVector(expected, actual);

    nums = { 1,2 };
    actual = o.smallestSubarrays(nums);
    expected = { 2,1 };
    check.checkIntVector(expected, actual);

    nums = { 9 };
    actual = o.smallestSubarrays(nums);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    nums = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };
    actual = o.smallestSubarrays(nums);
    expected = { 10,9,8,7,6,5,4,3,2,1 };
    check.checkIntVector(expected, actual);
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
