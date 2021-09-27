/* 增量元素之间的最大差值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums ，该数组的大小为 n ，请你计算 nums[j] - nums[i] 能求得的 最大差值 ，其中 0 <= i < j < n 且 nums[i] < nums[j] 。

返回 最大差值 。如果不存在满足要求的 i 和 j ，返回 -1 。

 

示例 1：

输入：nums = [7,1,5,4]
输出：4
解释：
最大差值出现在 i = 1 且 j = 2 时，nums[j] - nums[i] = 5 - 1 = 4 。
注意，尽管 i = 1 且 j = 0 时 ，nums[j] - nums[i] = 7 - 1 = 6 > 4 ，但 i > j 不满足题面要求，所以 6 不是有效的答案。
示例 2：

输入：nums = [9,4,3,2]
输出：-1
解释：
不存在同时满足 i < j 和 nums[i] < nums[j] 这两个条件的 i, j 组合。
示例 3：

输入：nums = [1,5,2,10]
输出：9
解释：
最大差值出现在 i = 0 且 j = 3 时，nums[j] - nums[i] = 10 - 1 = 9 。
 

提示：

n == nums.length
2 <= n <= 1000
1 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-difference-between-increasing-elements
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minimum = nums[0], maxDiff = 0;

        for (int num : nums) {
            maxDiff = max(maxDiff, num - minimum);
            minimum = min(minimum, num);
        }

        return maxDiff == 0 ? -1 : maxDiff;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 7,1,5,4 };
    check.checkInt(4, o.maximumDifference(nums));

    nums = { 9,4,3,2 };
    check.checkInt(-1, o.maximumDifference(nums));

    nums = { 1,5,2,10 };
    check.checkInt(9, o.maximumDifference(nums));

    nums = { 2,3,1 };
    check.checkInt(1, o.maximumDifference(nums));

    nums = { 5,5 };
    check.checkInt(-1, o.maximumDifference(nums));
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
