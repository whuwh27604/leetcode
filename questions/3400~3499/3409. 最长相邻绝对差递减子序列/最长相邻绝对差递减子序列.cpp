/* 最长相邻绝对差递减子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 。

你的任务是找到 nums 中的 最长子序列 seq ，这个子序列中相邻元素的 绝对差 构成一个 非递增 整数序列。换句话说，nums 中的序列 seq0, seq1, seq2, ..., seqm 满足 |seq1 - seq0| >= |seq2 - seq1| >= ... >= |seqm - seqm - 1| 。

请你返回这个子序列的长度。

一个 子序列 指的是从一个数组中删除零个或多个元素后，剩下元素不改变顺序得到的 非空 数组。



示例 1：

输入：nums = [16,6,3]

输出：3

解释：

最长子序列是 [16, 6, 3] ，相邻绝对差值为 [10, 3] 。

示例 2：

输入：nums = [6,5,3,4,2,1]

输出：4

解释：

最长子序列是 [6, 4, 2, 1] ，相邻绝对差值为 [2, 2, 1] 。

示例 3：

输入：nums = [10,20,10,19,10,20]

输出：5

解释：

最长子序列是 [10, 20, 10, 19, 10] ，相邻绝对差值为 [10, 10, 9, 9] 。



提示：

2 <= nums.length <= 104
1 <= nums[i] <= 300
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int size = (int)nums.size(), maxSeqLen = 0;
        int maxNum = *max_element(nums.begin(), nums.end()), minNum = *min_element(nums.begin(), nums.end());
        int maxDiff = maxNum - minNum;
        vector<vector<int>> maxLen(maxNum + 1, vector<int>(maxDiff + 1, 0));  // maxLen[n][d]表示以n为结尾，最后一组diff为d的最长子序列
        vector<vector<int>> sufMax(maxNum + 1, vector<int>(maxDiff + 2, 0));  // sufMax[n][d]表示maxLen[n][d]~maxLen[n][maxDiff]的最大值，即maxLen[n]的后缀最大值

        for (int n : nums) {
            for (int d = maxDiff; d >= 0; --d) {
                maxLen[n][d] = max(maxLen[n][d], 1);  // 当前n构成一个新的seq

                if (n - d >= minNum) {  // 最后一个diff为d，那么n前面一个数为n - d或者n + d。对前一个数，所有d、d+1...maxDiff的子序列，后面都可以接n，选择里面最大的一个
                    maxLen[n][d] = max(maxLen[n][d], sufMax[n - d][d] + 1);
                }

                if (n + d <= maxNum) {
                    maxLen[n][d] = max(maxLen[n][d], sufMax[n + d][d] + 1);
                }

                sufMax[n][d] = max(sufMax[n][d + 1], maxLen[n][d]);  // maxLen计算完成，更新后缀最大值
                maxSeqLen = max(maxSeqLen, maxLen[n][d]);
            }
        }

        return maxSeqLen;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 16,6,3 };
    check.checkInt(3, o.longestSubsequence(nums));

    nums = { 6,5,3,4,2,1 };
    check.checkInt(4, o.longestSubsequence(nums));

    nums = { 10,20,10,19,10,20 };
    check.checkInt(5, o.longestSubsequence(nums));

    nums = { 16,6,3,10,20,10,19,10,20,6,5,3,4,2,1,16,6,3,10,20,10,19,10,20,6,5,3,4,2,1,16,6,3,10,20,10,19,10,20,6,5,3,4,2,1,16,6,3,10,20,10,19,10,20,6,5,3,4,2,1,16,6,3,10,20,10,19,10,20,6,5,3,4,2,1,16,6,3,10,20,10,19,10,20,6,5,3,4,2,1 };
    check.checkInt(29, o.longestSubsequence(nums));
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
