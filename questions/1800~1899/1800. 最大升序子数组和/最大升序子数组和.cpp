/* 最大升序子数组和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正整数组成的数组 nums ，返回 nums 中一个 升序 子数组的最大可能元素和。

子数组是数组中的一个连续数字序列。

已知子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，若对所有 i（l <= i < r），numsi < numsi+1 都成立，则称这一子数组为 升序 子数组。注意，大小为 1 的子数组也视作 升序 子数组。

 

示例 1：

输入：nums = [10,20,30,5,10,50]
输出：65
解释：[5,10,50] 是元素和最大的升序子数组，最大元素和为 65 。
示例 2：

输入：nums = [10,20,30,40,50]
输出：150
解释：[10,20,30,40,50] 是元素和最大的升序子数组，最大元素和为 150 。
示例 3：

输入：nums = [12,17,15,13,10,11,12]
输出：33
解释：[10,11,12] 是元素和最大的升序子数组，最大元素和为 33 。
示例 4：

输入：nums = [100,10,1]
输出：100
 

提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-ascending-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = 0, prev = 0, maxSum = 0;

        for (int num : nums) {
            if (num > prev) {
                sum += num;
            }
            else {
                maxSum = max(maxSum, sum);
                sum = num;
            }

            prev = num;
        }

        return max(maxSum, sum);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 10,20,30,5,10,50 };
    check.checkInt(65, o.maxAscendingSum(nums));

    nums = { 10,20,30,40,50 };
    check.checkInt(150, o.maxAscendingSum(nums));

    nums = { 12,17,15,13,10,11,12 };
    check.checkInt(33, o.maxAscendingSum(nums));

    nums = { 100,10,1 };
    check.checkInt(100, o.maxAscendingSum(nums));
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
