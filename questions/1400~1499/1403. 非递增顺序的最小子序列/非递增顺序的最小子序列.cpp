/* 非递增顺序的最小子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 nums，请你从中抽取一个子序列，满足该子序列的元素之和 严格 大于未包含在该子序列中的各元素之和。

如果存在多个解决方案，只需返回 长度最小 的子序列。如果仍然有多个解决方案，则返回 元素之和最大 的子序列。

与子数组不同的地方在于，「数组的子序列」不强调元素在原数组中的连续性，也就是说，它可以通过从数组中分离一些（也可能不分离）元素得到。

注意，题目数据保证满足所有约束条件的解决方案是 唯一 的。同时，返回的答案应当按 非递增顺序 排列。

 

示例 1：

输入：nums = [4,3,10,9,8]
输出：[10,9]
解释：子序列 [10,9] 和 [10,8] 是最小的、满足元素之和大于其他各元素之和的子序列。但是 [10,9] 的元素之和最大。 
示例 2：

输入：nums = [4,4,7,6,7]
输出：[7,7,6]
解释：子序列 [7,7] 的和为 14 ，不严格大于剩下的其他元素之和（14 = 4 + 4 + 6）。因此，[7,6,7] 是满足题意的最小子序列。注意，元素按非递增顺序返回。
示例 3：

输入：nums = [6]
输出：[6]
 

提示：

1 <= nums.length <= 500
1 <= nums[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-subsequence-in-non-increasing-order
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int i, len = nums.size(), sum = 0;
        for (i = 0; i < len; i++) {
            sum += nums[i];
        }

        int half = sum / 2;
        sum = 0;
        vector<int> ans;
        for (i = len - 1; i >= 0; i--) {
            ans.push_back(nums[i]);
            sum += nums[i];
            if (sum > half) {
                break;
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 4,3,10,9,8 };
    vector<int> actual = o.minSubsequence(nums);
    vector<int> expected = { 10,9 };
    check.checkIntVector(expected, actual);

    nums = { 4,4,7,6,7 };
    actual = o.minSubsequence(nums);
    expected = { 7,7,6 };
    check.checkIntVector(expected, actual);

    nums = { 6 };
    actual = o.minSubsequence(nums);
    expected = { 6 };
    check.checkIntVector(expected, actual);

    nums = { 1 };
    actual = o.minSubsequence(nums);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    nums = { 1,1,1,1,1,1 };
    actual = o.minSubsequence(nums);
    expected = { 1,1,1,1 };
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
