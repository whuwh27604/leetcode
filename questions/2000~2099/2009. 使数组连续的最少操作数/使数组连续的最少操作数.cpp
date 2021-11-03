/* 使数组连续的最少操作数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 。每一次操作中，你可以将 nums 中 任意 一个元素替换成 任意 整数。

如果 nums 满足以下条件，那么它是 连续的 ：

nums 中所有元素都是 互不相同 的。
nums 中 最大 元素与 最小 元素的差等于 nums.length - 1 。
比方说，nums = [4, 2, 5, 3] 是 连续的 ，但是 nums = [1, 2, 3, 5, 6] 不是连续的 。

请你返回使 nums 连续 的 最少 操作次数。

 

示例 1：

输入：nums = [4,2,5,3]
输出：0
解释：nums 已经是连续的了。
示例 2：

输入：nums = [1,2,3,5,6]
输出：1
解释：一个可能的解是将最后一个元素变为 4 。
结果数组为 [1,2,3,5,4] ，是连续数组。
示例 3：

输入：nums = [1,10,100,1000]
输出：3
解释：一个可能的解是：
- 将第二个元素变为 2 。
- 将第三个元素变为 3 。
- 将第四个元素变为 4 。
结果数组为 [1,2,3,4] ，是连续数组。
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-operations-to-make-array-continuous
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int size = nums.size(), right = 0, minOpers = INT_MAX;

        sort(nums.begin(), nums.end());
        int newSize = distance(nums.begin(), unique(nums.begin(), nums.end()));

        for (int left = 0; left < newSize; ++left) {
            while (right < newSize && nums[right] < nums[left] + size) {
                ++right;
            }

            minOpers = min(minOpers, size - (right - left));
        }

        return minOpers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 4,2,5,3 };
    check.checkInt(0, o.minOperations(nums));

    nums = { 1,2,3,5,6 };
    check.checkInt(1, o.minOperations(nums));

    nums = { 1,10,100,1000 };
    check.checkInt(3, o.minOperations(nums));

    nums = { 1000 };
    check.checkInt(0, o.minOperations(nums));

    nums = { 1,3,5,7,9,12,14,16,18,20 };
    check.checkInt(5, o.minOperations(nums));
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
