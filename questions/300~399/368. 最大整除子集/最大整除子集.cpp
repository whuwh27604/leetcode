/* 最大整除子集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对 (answer[i], answer[j]) 都应当满足：
answer[i] % answer[j] == 0 ，或
answer[j] % answer[i] == 0
如果存在多个有效解子集，返回其中任何一个均可。

 

示例 1：

输入：nums = [1,2,3]
输出：[1,2]
解释：[1,3] 也会被视为正确答案。
示例 2：

输入：nums = [1,2,4,8]
输出：[1,2,4,8]
 

提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
nums 中的所有整数 互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-divisible-subset
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int i, j, size = nums.size(), maxDp = 1, maxDpIndex = 0;
        vector<int> dp(size, 1), prev(size, -1);
        vector<int> subset;

        sort(nums.begin(), nums.end());

        for (i = 1; i < size; ++i) {
            for (j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }

            if (dp[i] > maxDp) {
                maxDp = dp[i];
                maxDpIndex = i;
            }
        }

        do {
            subset.push_back(nums[maxDpIndex]);
            maxDpIndex = prev[maxDpIndex];
        } while (maxDpIndex != -1);

        return subset;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2 };
    vector<int> actual = o.largestDivisibleSubset(nums);
    vector<int> expected = { 2 };
    check.checkIntVector(expected, actual);

    nums = { 2,3 };
    actual = o.largestDivisibleSubset(nums);
    expected = { 2 };
    check.checkIntVector(expected, actual);

    nums = { 1,2,3 };
    actual = o.largestDivisibleSubset(nums);
    expected = { 2,1 };
    check.checkIntVector(expected, actual);

    nums = { 1,2,4,8 };
    actual = o.largestDivisibleSubset(nums);
    expected = { 8,4,2,1 };
    check.checkIntVector(expected, actual);

    nums = { 1,3,4,6,7,8,9,10,11,12,16,18,20,21 };
    actual = o.largestDivisibleSubset(nums);
    expected = { 12,6,3,1 };
    check.checkIntVector(expected, actual);

    nums = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100 };
    actual = o.largestDivisibleSubset(nums);
    expected = { 64,32,16,8,4,2,1 };
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
