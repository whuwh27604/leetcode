/* K 个元素的最大和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。你需要执行以下操作 恰好 k 次，最大化你的得分：

从 nums 中选择一个元素 m 。
将选中的元素 m 从数组中删除。
将新元素 m + 1 添加到数组中。
你的得分增加 m 。
请你返回执行以上操作恰好 k 次后的最大得分。



示例 1：

输入：nums = [1,2,3,4,5], k = 3
输出：18
解释：我们需要从 nums 中恰好选择 3 个元素并最大化得分。
第一次选择 5 。和为 5 ，nums = [1,2,3,4,6] 。
第二次选择 6 。和为 6 ，nums = [1,2,3,4,7] 。
第三次选择 7 。和为 5 + 6 + 7 = 18 ，nums = [1,2,3,4,8] 。
所以我们返回 18 。
18 是可以得到的最大答案。
示例 2：

输入：nums = [5,5,5], k = 2
输出：11
解释：我们需要从 nums 中恰好选择 2 个元素并最大化得分。
第一次选择 5 。和为 5 ，nums = [5,5,6] 。
第二次选择 6 。和为 6 ，nums = [5,5,7] 。
所以我们返回 11 。
11 是可以得到的最大答案。


提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 100
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxNum = *max_element(nums.begin(), nums.end());

        return (maxNum + maxNum + k - 1) * k / 2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,3,4,5 };
    check.checkInt(18, o.maximizeSum(nums, 3));

    nums = { 5,5,5 };
    check.checkInt(11, o.maximizeSum(nums, 2));
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
