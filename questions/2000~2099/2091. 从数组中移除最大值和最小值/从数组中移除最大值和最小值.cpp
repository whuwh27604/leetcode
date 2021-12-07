/* 从数组中移除最大值和最小值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的数组 nums ，数组由若干 互不相同 的整数组成。

nums 中有一个值最小的元素和一个值最大的元素。分别称为 最小值 和 最大值 。你的目标是从数组中移除这两个元素。

一次 删除 操作定义为从数组的 前面 移除一个元素或从数组的 后面 移除一个元素。

返回将数组中最小值和最大值 都 移除需要的最小删除次数。

 

示例 1：

输入：nums = [2,10,7,5,4,1,8,6]
输出：5
解释：
数组中的最小元素是 nums[5] ，值为 1 。
数组中的最大元素是 nums[1] ，值为 10 。
将最大值和最小值都移除需要从数组前面移除 2 个元素，从数组后面移除 3 个元素。
结果是 2 + 3 = 5 ，这是所有可能情况中的最小删除次数。
示例 2：

输入：nums = [0,-4,19,1,8,-2,-3,5]
输出：3
解释：
数组中的最小元素是 nums[1] ，值为 -4 。
数组中的最大元素是 nums[2] ，值为 19 。
将最大值和最小值都移除需要从数组前面移除 3 个元素。
结果是 3 ，这是所有可能情况中的最小删除次数。
示例 3：

输入：nums = [101]
输出：1
解释：
数组中只有这一个元素，那么它既是数组中的最小值又是数组中的最大值。
移除它只需要 1 次删除操作。
 

提示：

1 <= nums.length <= 105
-105 <= nums[i] <= 105
nums 中的整数 互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/removing-minimum-and-maximum-from-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int i, size = nums.size(), minimum = INT_MAX, maximum = INT_MIN, minIndex = 0, maxIndex = 0;

        for (i = 0; i < size; ++i) {
            int num = nums[i];

            if (num < minimum) {
                minimum = num;
                minIndex = i;
            }

            if (num > maximum) {
                maximum = num;
                maxIndex = i;
            }
        }

        if (minIndex > maxIndex) {
            swap(minIndex, maxIndex);
        }

        return min({ maxIndex + 1, size - minIndex, minIndex + 1 + size - maxIndex });
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,10,7,5,4,1,8,6 };
    check.checkInt(5, o.minimumDeletions(nums));

    nums = { 0,-4,19,1,8,-2,-3,5 };
    check.checkInt(3, o.minimumDeletions(nums));

    nums = { 101 };
    check.checkInt(1, o.minimumDeletions(nums));

    nums = { 1,2 };
    check.checkInt(2, o.minimumDeletions(nums));

    nums = { 1,2,3 };
    check.checkInt(2, o.minimumDeletions(nums));

    nums = { 1,3,2 };
    check.checkInt(2, o.minimumDeletions(nums));

    nums = { 1,2,3,4,5,6,7 };
    check.checkInt(2, o.minimumDeletions(nums));

    nums = { 7,1,2,3,4,5,6 };
    check.checkInt(2, o.minimumDeletions(nums));

    nums = { 2,3,4,5,6,7,1 };
    check.checkInt(2, o.minimumDeletions(nums));

    nums = { 2,3,1,4,7,5,6 };
    check.checkInt(5, o.minimumDeletions(nums));
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
