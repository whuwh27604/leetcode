/* 好子数组的最大分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums （下标从 0 开始）和一个整数 k 。

一个子数组 (i, j) 的 分数 定义为 min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1) 。一个 好 子数组的两个端点下标需要满足 i <= k <= j 。

请你返回 好 子数组的最大可能 分数 。

 

示例 1：

输入：nums = [1,4,3,7,4,5], k = 3
输出：15
解释：最优子数组的左右端点下标是 (1, 5) ，分数为 min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15 。
示例 2：

输入：nums = [5,5,4,5,4,1,1,1], k = 0
输出：20
解释：最优子数组的左右端点下标是 (0, 4) ，分数为 min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20 。
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 2 * 104
0 <= k < nums.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-score-of-a-good-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left = k, right = k, size = nums.size();
        int maxScore = 0, minNum, leftMin, rightMin;

        while (left >= 0 || right < size) {
            leftMin = left >= 0 ? nums[left] : INT_MIN;
            rightMin = right < size ? nums[right] : INT_MIN;
            minNum = max(leftMin, rightMin);  // 遍历所有可能的minNum，所以选择较大的一个

            while (left >= 0 && nums[left] >= minNum) {  // 假设最小数为minNum，向左向右扩展
                --left;
            }

            while (right < size && nums[right] >= minNum) {
                ++right;
            }

            maxScore = max(maxScore, minNum * (right - left - 1));  // 计算最小数为minNum的得分
        }

        return maxScore;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,4,3,7,4,5 };
    check.checkInt(15, o.maximumScore(nums, 3));

    nums = { 1,4,3,7,4,5 };
    check.checkInt(15, o.maximumScore(nums, 2));

    nums = { 1,4,3,7,4,5 };
    check.checkInt(15, o.maximumScore(nums, 1));

    nums = { 1,4,3,7,4,5 };
    check.checkInt(15, o.maximumScore(nums, 5));

    nums = { 5,5,4,5,4,1,1,1 };
    check.checkInt(20, o.maximumScore(nums, 0));

    nums = { 5 };
    check.checkInt(5, o.maximumScore(nums, 0));
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
