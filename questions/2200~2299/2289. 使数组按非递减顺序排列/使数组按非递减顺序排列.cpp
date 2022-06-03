/* 使数组按非递减顺序排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。在一步操作中，移除所有满足 nums[i - 1] > nums[i] 的 nums[i] ，其中 0 < i < nums.length 。

重复执行步骤，直到 nums 变为 非递减 数组，返回所需执行的操作数。

 

示例 1：

输入：nums = [5,3,4,4,7,3,6,11,8,5,11]
输出：3
解释：执行下述几个步骤：
- 步骤 1 ：[5,3,4,4,7,3,6,11,8,5,11] 变为 [5,4,4,7,6,11,11]
- 步骤 2 ：[5,4,4,7,6,11,11] 变为 [5,4,7,11,11]
- 步骤 3 ：[5,4,7,11,11] 变为 [5,7,11,11]
[5,7,11,11] 是一个非递减数组，因此，返回 3 。
示例 2：

输入：nums = [4,5,7,7,13]
输出：0
解释：nums 已经是一个非递减数组，因此，返回 0 。
 

提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/steps-to-make-array-non-decreasing
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int, int>> numSteps;
        int totalMaxSteps = 0;

        for (int num : nums) {
            int maxSteps = 0;

            while (!numSteps.empty() && numSteps.top().first <= num) {  // 栈顶元素比num小，那么删除栈顶元素之后的下一轮才能删除num
                maxSteps = max(maxSteps, numSteps.top().second);
                numSteps.pop();
            }

            maxSteps = numSteps.empty() ? 0 : maxSteps + 1;  // 如果栈为空，说明num不会被删除，将保留到最终的递增序列
            numSteps.push({ num, maxSteps });
            totalMaxSteps = max(totalMaxSteps, maxSteps);
        }

        return totalMaxSteps;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 5,3,4,4,7,3,6,11,8,5,11 };
    check.checkInt(3, o.totalSteps(nums));

    nums = { 4,5,7,7,13 };
    check.checkInt(0, o.totalSteps(nums));

    nums = { 1 };
    check.checkInt(0, o.totalSteps(nums));

    nums = { 5,4,3,2,1 };
    check.checkInt(1, o.totalSteps(nums));

    nums = { 9,1,2,3,4,5 };
    check.checkInt(5, o.totalSteps(nums));

    nums = { 10,6,5,10,15 };
    check.checkInt(1, o.totalSteps(nums));

    nums = { 3,2,2 };
    check.checkInt(2, o.totalSteps(nums));

    nums = { 7,14,4,14,13,2,6,13 };
    check.checkInt(3, o.totalSteps(nums));
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
