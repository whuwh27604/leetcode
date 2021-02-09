/* 检查数组是否经排序和轮转得到.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 nums 。nums 的源数组中，所有元素与 nums 相同，但按非递减顺序排列。

如果 nums 能够由源数组轮转若干位置（包括 0 个位置）得到，则返回 true ；否则，返回 false 。

源数组中可能存在 重复项 。

注意：我们称数组 A 在轮转 x 个位置后得到长度相同的数组 B ，当它们满足 A[i] == B[(i+x) % A.length] ，其中 % 为取余运算。

 

示例 1：

输入：nums = [3,4,5,1,2]
输出：true
解释：[1,2,3,4,5] 为有序的源数组。
可以轮转 x = 3 个位置，使新数组从值为 3 的元素开始：[3,4,5,1,2] 。
示例 2：

输入：nums = [2,1,3,4]
输出：false
解释：源数组无法经轮转得到 nums 。
示例 3：

输入：nums = [1,2,3]
输出：true
解释：[1,2,3] 为有序的源数组。
可以轮转 x = 0 个位置（即不轮转）得到 nums 。
示例 4：

输入：nums = [1,1,1]
输出：true
解释：[1,1,1] 为有序的源数组。
轮转任意个位置都可以得到 nums 。
示例 5：

输入：nums = [2,1]
输出：true
解释：[1,2] 为有序的源数组。
可以轮转 x = 5 个位置，使新数组从值为 2 的元素开始：[2,1] 。
 

提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-array-is-sorted-and-rotated
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        // 从nums[0]到nums[size-1]再到nums[0]，最多只能有一次降序
        int prev = INT_MIN, decreasing = 0;

        for (int num : nums) {
            if (num < prev && ++decreasing > 1) {
                return false;
            }

            prev = num;
        }

        return (decreasing == 0) || (nums[0] >= nums.back());
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,4,5,1,2 };
    check.checkBool(true, o.check(nums));

    nums = { 2,1,3,4 };
    check.checkBool(false, o.check(nums));

    nums = { 4,1,3,2 };
    check.checkBool(false, o.check(nums));

    nums = { 1,2,3 };
    check.checkBool(true, o.check(nums));

    nums = { 1,1,1 };
    check.checkBool(true, o.check(nums));

    nums = { 2,1 };
    check.checkBool(true, o.check(nums));

    nums = { 5 };
    check.checkBool(true, o.check(nums));
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
