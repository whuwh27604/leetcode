/* 使数组元素相等的减少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，你的目标是令 nums 中的所有元素相等。完成一次减少操作需要遵照下面的几个步骤：

找出 nums 中的 最大 值。记这个值为 largest 并取其下标 i （下标从 0 开始计数）。如果有多个元素都是最大值，则取最小的 i 。
找出 nums 中的 下一个最大 值，这个值 严格小于 largest ，记为 nextLargest 。
将 nums[i] 减少到 nextLargest 。
返回使 nums 中的所有元素相等的操作次数。

 

示例 1：

输入：nums = [5,1,3]
输出：3
解释：需要 3 次操作使 nums 中的所有元素相等：
1. largest = 5 下标为 0 。nextLargest = 3 。将 nums[0] 减少到 3 。nums = [3,1,3] 。
2. largest = 3 下标为 0 。nextLargest = 1 。将 nums[0] 减少到 1 。nums = [1,1,3] 。
3. largest = 3 下标为 2 。nextLargest = 1 。将 nums[2] 减少到 1 。nums = [1,1,1] 。
示例 2：

输入：nums = [1,1,1]
输出：0
解释：nums 中的所有元素已经是相等的。
示例 3：

输入：nums = [1,1,2,2,3]
输出：4
解释：需要 4 次操作使 nums 中的所有元素相等：
1. largest = 3 下标为 4 。nextLargest = 2 。将 nums[4] 减少到 2 。nums = [1,1,2,2,2] 。
2. largest = 2 下标为 2 。nextLargest = 1 。将 nums[2] 减少到 1 。nums = [1,1,1,2,2] 。
3. largest = 2 下标为 3 。nextLargest = 1 。将 nums[3] 减少到 1 。nums = [1,1,1,1,2] 。
4. largest = 2 下标为 4 。nextLargest = 1 。将 nums[4] 减少到 1 。nums = [1,1,1,1,1] 。
 

提示：

1 <= nums.length <= 5 * 104
1 <= nums[i] <= 5 * 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reduction-operations-to-make-the-array-elements-equal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int prev = 0, diff = 0, opers = 0;

        for (int num : nums) {
            if (num != prev) {
                ++diff;
                prev = num;
            }

            opers += (diff - 1);
        }

        return opers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 5,1,3 };
    check.checkInt(3, o.reductionOperations(nums));

    nums = { 1,1,1 };
    check.checkInt(0, o.reductionOperations(nums));

    nums = { 1,1,2,2,3 };
    check.checkInt(4, o.reductionOperations(nums));

    nums = { 3 };
    check.checkInt(0, o.reductionOperations(nums));
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
