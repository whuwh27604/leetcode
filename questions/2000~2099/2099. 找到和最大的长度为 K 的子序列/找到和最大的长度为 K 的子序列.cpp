/* 找到和最大的长度为 K 的子序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个整数 k 。你需要找到 nums 中长度为 k 的 子序列 ，且这个子序列的 和最大 。

请你返回 任意 一个长度为 k 的整数子序列。

子序列 定义为从一个数组里删除一些元素后，不改变剩下元素的顺序得到的数组。

 

示例 1：

输入：nums = [2,1,3,3], k = 2
输出：[3,3]
解释：
子序列有最大和：3 + 3 = 6 。
示例 2：

输入：nums = [-1,-2,3,4], k = 3
输出：[-1,3,4]
解释：
子序列有最大和：-1 + 3 + 4 = 6 。
示例 3：

输入：nums = [3,4,3,3], k = 2
输出：[3,4]
解释：
子序列有最大和：3 + 4 = 7 。
另一个可行的子序列为 [4, 3] 。
 

提示：

1 <= nums.length <= 1000
-105 <= nums[i] <= 105
1 <= k <= nums.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-subsequence-of-length-k-with-the-largest-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool pairFirstCompare(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.first > p2.first;
}

bool pairSecondCompare(const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second < p2.second;
}

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int i, size = nums.size();
        vector<pair<int, int>> numIndices(size);
        vector<int> subseq(k);

        for (i = 0; i < size; ++i) {
            numIndices[i] = { nums[i],i };
        }

        sort(numIndices.begin(), numIndices.end(), pairFirstCompare);
        sort(numIndices.begin(), numIndices.begin() + k, pairSecondCompare);

        for (i = 0; i < k; ++i) {
            subseq[i] = numIndices[i].first;
        }

        return subseq;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,1,3,3 };
    vector<int> actual = o.maxSubsequence(nums, 2);
    vector<int> expected = { 3,3 };
    check.checkIntVector(expected, actual);

    nums = { -1,-2,3,4 };
    actual = o.maxSubsequence(nums, 3);
    expected = { -1,3,4 };
    check.checkIntVector(expected, actual);

    nums = { -1,-2,3,4 };
    actual = o.maxSubsequence(nums, 4);
    expected = { -1,-2,3,4 };
    check.checkIntVector(expected, actual);

    nums = { 3,4,3,3 };
    actual = o.maxSubsequence(nums, 2);
    expected = { 3,4 };
    check.checkIntVector(expected, actual);

    nums = { 3 };
    actual = o.maxSubsequence(nums, 1);
    expected = { 3 };
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
