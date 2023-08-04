/* 合并后数组中的最大元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始、由正整数组成的数组 nums 。

你可以在数组上执行下述操作 任意 次：

选中一个同时满足 0 <= i < nums.length - 1 和 nums[i] <= nums[i + 1] 的整数 i 。将元素 nums[i + 1] 替换为 nums[i] + nums[i + 1] ，并从数组中删除元素 nums[i] 。
返回你可以从最终数组中获得的 最大 元素的值。



示例 1：

输入：nums = [2,3,7,9,3]
输出：21
解释：我们可以在数组上执行下述操作：
- 选中 i = 0 ，得到数组 nums = [5,7,9,3] 。
- 选中 i = 1 ，得到数组 nums = [5,16,3] 。
- 选中 i = 0 ，得到数组 nums = [21,3] 。
最终数组中的最大元素是 21 。可以证明我们无法获得更大的元素。
示例 2：

输入：nums = [5,3,3]
输出：11
解释：我们可以在数组上执行下述操作：
- 选中 i = 1 ，得到数组 nums = [5,6] 。
- 选中 i = 0 ，得到数组 nums = [11] 。
最终数组中只有一个元素，即 11 。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 106
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long ans = 0;

        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] <= ans) {
                ans += nums[i];
            }
            else {
                ans = nums[i];
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,3,7,9,3 };
    check.checkLongLong(21, o.maxArrayValue(nums));

    nums = { 5,3,3 };
    check.checkLongLong(11, o.maxArrayValue(nums));
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
