/* 最长定差子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 arr 和一个整数 difference，请你找出 arr 中所有相邻元素之间的差等于给定 difference 的等差子序列，并返回其中最长的等差子序列的长度。

 

示例 1：

输入：arr = [1,2,3,4], difference = 1
输出：4
解释：最长的等差子序列是 [1,2,3,4]。
示例 2：

输入：arr = [1,3,5,7], difference = 1
输出：1
解释：最长的等差子序列是任意单个元素。
示例 3：

输入：arr = [1,5,7,8,5,3,4,2,1], difference = -2
输出：4
解释：最长的等差子序列是 [7,5,3,1]。
 

提示：

1 <= arr.length <= 10^5
-10^4 <= arr[i], difference <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int* dp = new int[40001]();
        int maxLen = 0;

        for (int num : arr) {
            int index = num + 20000;
            dp[index] = dp[index - difference] + 1;
            maxLen = max(maxLen, dp[index]);
        }

        delete[] dp;
        return maxLen;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 1,2,3,4 };
    check.checkInt(4, o.longestSubsequence(arr, 1));

    arr = { 1,3,5,7 };
    check.checkInt(1, o.longestSubsequence(arr, 1));

    arr = { 1,5,7,8,5,3,4,2,1 };
    check.checkInt(4, o.longestSubsequence(arr, -2));

    arr = { 3,0,-3,4,-4,7,6 };
    check.checkInt(2, o.longestSubsequence(arr, 3));

    arr = { 3,4,-3,-2,-4 };
    check.checkInt(2, o.longestSubsequence(arr, -5));

    arr = { 1,2,3,4,6,5,6,7 };
    check.checkInt(7, o.longestSubsequence(arr, 1));

    arr = { 1 };
    check.checkInt(1, o.longestSubsequence(arr, 1));
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
