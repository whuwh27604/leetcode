/* 找两个和为目标值且不重叠的子数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr 和一个整数值 target 。

请你在 arr 中找 两个互不重叠的子数组 且它们的和都等于 target 。可能会有多种方案，请你返回满足要求的两个子数组长度和的 最小值 。

请返回满足要求的最小长度和，如果无法找到这样的两个子数组，请返回 -1 。

 

示例 1：

输入：arr = [3,2,2,4,3], target = 3
输出：2
解释：只有两个子数组和为 3 （[3] 和 [3]）。它们的长度和为 2 。
示例 2：

输入：arr = [7,3,4,7], target = 7
输出：2
解释：尽管我们有 3 个互不重叠的子数组和为 7 （[7], [3,4] 和 [7]），但我们会选择第一个和第三个子数组，因为它们的长度和 2 是最小值。
示例 3：

输入：arr = [4,3,2,6,2,3,4], target = 6
输出：-1
解释：我们只有一个和为 6 的子数组。
示例 4：

输入：arr = [5,5,4,4,5], target = 3
输出：-1
解释：我们无法找到和为 3 的子数组。
示例 5：

输入：arr = [3,1,1,1,5,1,2,1], target = 3
输出：3
解释：注意子数组 [1,2] 和 [2,1] 不能成为一个方案因为它们重叠了。
 

提示：

1 <= arr.length <= 10^5
1 <= arr[i] <= 1000
1 <= target <= 10^8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int size = arr.size(), left = 0, right, sum = 0, minSumOfLens = INT_MAX;
        vector<int> dp(size + 1, 0);
        dp[0] = size + 1;  // dp[i]表示区间[0,i)之间最短的和为target的子数组，先初始化为一个较大的数表示不存在。因为会做加法运算，不能初始化为INT_MAX

        for (right = 0; right < size; ++right) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            if (sum == target) {
                int len = right - left + 1;  // 区间[left,right]是一个和为target的子数组，该子数组长度为len
                minSumOfLens = min(minSumOfLens, len + dp[left]);  // 如果有解，我们遍历了所有的第二个子数组，同时加上它前面长度最短的第一个子数组就是答案
                dp[right + 1] = min(dp[right], len);  // 更新dp，取长度更小的一个
            }
            else {
                dp[right + 1] = dp[right];  // 不是一个和为target的子数组，dp[i]保持不变
            }
        }

        return minSumOfLens > size ? -1 : minSumOfLens;  // 大于size说明没有找到两个不重叠的子数组
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 3,2,2,4,3 };
    check.checkInt(2, o.minSumOfLengths(arr, 3));

    arr = { 7,3,4,7 };
    check.checkInt(2, o.minSumOfLengths(arr, 7));

    arr = { 4,3,2,6,2,3,4 };
    check.checkInt(-1, o.minSumOfLengths(arr, 6));

    arr = { 5,5,4,4,5 };
    check.checkInt(-1, o.minSumOfLengths(arr, 3));

    arr = { 3,1,1,1,5,1,2,1 };
    check.checkInt(3, o.minSumOfLengths(arr, 3));

    arr = { 1,2,1,3,1 };
    check.checkInt(5, o.minSumOfLengths(arr, 4));

    arr = { 5,4,10,15,9,13,12,1,1,1,1,1,8,8,8,8,2,1,1 };
    check.checkInt(7, o.minSumOfLengths(arr, 34));

    arr = { 3,1,1,1,2,3,2,1 };
    check.checkInt(7, o.minSumOfLengths(arr, 6));
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
