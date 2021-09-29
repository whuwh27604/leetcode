/* 删除一个元素使数组严格递增.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums ，如果 恰好 删除 一个 元素后，数组 严格递增 ，那么请你返回 true ，否则返回 false 。如果数组本身已经是严格递增的，请你也返回 true 。

数组 nums 是 严格递增 的定义为：对于任意下标的 1 <= i < nums.length 都满足 nums[i - 1] < nums[i] 。

 

示例 1：

输入：nums = [1,2,10,5,7]
输出：true
解释：从 nums 中删除下标 2 处的 10 ，得到 [1,2,5,7] 。
[1,2,5,7] 是严格递增的，所以返回 true 。
示例 2：

输入：nums = [2,3,1,2]
输出：false
解释：
[3,1,2] 是删除下标 0 处元素后得到的结果。
[2,1,2] 是删除下标 1 处元素后得到的结果。
[2,3,2] 是删除下标 2 处元素后得到的结果。
[2,3,1] 是删除下标 3 处元素后得到的结果。
没有任何结果数组是严格递增的，所以返回 false 。
示例 3：

输入：nums = [1,1,1]
输出：false
解释：删除任意元素后的结果都是 [1,1] 。
[1,1] 不是严格递增的，所以返回 false 。
示例 4：

输入：nums = [1,2,3]
输出：true
解释：[1,2,3] 已经是严格递增的，所以返回 true 。
 

提示：

2 <= nums.length <= 1000
1 <= nums[i] <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-one-element-to-make-the-array-strictly-increasing
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int i, size = nums.size(), prev2 = -1, prev = nums[0];

        for (i = 1; i < size; ++i) {
            if (nums[i] <= nums[i - 1]) {
                if (nums[i] > prev2) {
                    prev = nums[i];
                }
                break;
            }

            prev2 = prev;
            prev = nums[i];
        }

        for (++i; i < size; ++i) {
            if (nums[i] <= prev) {
                return false;
            }

            prev = nums[i];
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,10,5,7 };
    check.checkBool(true, o.canBeIncreasing(nums));

    nums = { 2,3,1,2 };
    check.checkBool(false, o.canBeIncreasing(nums));

    nums = { 1,1,1 };
    check.checkBool(false, o.canBeIncreasing(nums));

    nums = { 1,2,3 };
    check.checkBool(true, o.canBeIncreasing(nums));

    nums = { 3,1,2 };
    check.checkBool(true, o.canBeIncreasing(nums));

    nums = { 3,1,2,4 };
    check.checkBool(true, o.canBeIncreasing(nums));

    nums = { 2,1 };
    check.checkBool(true, o.canBeIncreasing(nums));
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
