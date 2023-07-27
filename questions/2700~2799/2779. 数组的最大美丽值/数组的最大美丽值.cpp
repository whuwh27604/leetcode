/* 数组的最大美丽值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 和一个 非负 整数 k 。

在一步操作中，你可以执行下述指令：

在范围 [0, nums.length - 1] 中选择一个 此前没有选过 的下标 i 。
将 nums[i] 替换为范围 [nums[i] - k, nums[i] + k] 内的任一整数。
数组的 美丽值 定义为数组中由相等元素组成的最长子序列的长度。

对数组 nums 执行上述操作任意次后，返回数组可能取得的 最大 美丽值。

注意：你 只 能对每个下标执行 一次 此操作。

数组的 子序列 定义是：经由原数组删除一些元素（也可能不删除）得到的一个新数组，且在此过程中剩余元素的顺序不发生改变。



示例 1：

输入：nums = [4,6,1,2], k = 2
输出：3
解释：在这个示例中，我们执行下述操作：
- 选择下标 1 ，将其替换为 4（从范围 [4,8] 中选出），此时 nums = [4,4,1,2] 。
- 选择下标 3 ，将其替换为 4（从范围 [0,4] 中选出），此时 nums = [4,4,1,4] 。
执行上述操作后，数组的美丽值是 3（子序列由下标 0 、1 、3 对应的元素组成）。
可以证明 3 是我们可以得到的由相等元素组成的最长子序列长度。
示例 2：

输入：nums = [1,1,1,1], k = 10
输出：4
解释：在这个示例中，我们无需执行任何操作。
数组 nums 的美丽值是 4（整个数组）。


提示：

1 <= nums.length <= 105
0 <= nums[i], k <= 105
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int minNum = *min_element(nums.begin(), nums.end()), maxNum = *max_element(nums.begin(), nums.end());

        int delta = 0;
        if (minNum - k < 0) {
            delta = k - minNum;
        }

        vector<int> diffs(maxNum + k + delta + 2, 0);
        int sum = 0, maxBeauty = 1;

        for (int num : nums) {
            diffs[num - k + delta] += 1;
            diffs[num + k + delta + 1] -= 1;
        }

        for (int diff : diffs) {
            sum += diff;
            maxBeauty = max(maxBeauty, sum);
        }

        return maxBeauty;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 4,6,1,2 };
    check.checkInt(3, o.maximumBeauty(nums, 2));

    nums = { 1,1,1,1 };
    check.checkInt(4, o.maximumBeauty(nums, 10));
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
