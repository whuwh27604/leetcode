/* 好数字之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 nums 和一个整数 k，如果元素 nums[i] 严格 大于下标 i - k 和 i + k 处的元素（如果这些元素存在），则该元素 nums[i] 被认为是 好 的。如果这两个下标都不存在，那么 nums[i] 仍然被认为是 好 的。

返回数组中所有 好 元素的 和。



示例 1：

输入： nums = [1,3,2,1,5,4], k = 2

输出： 12

解释：

好的数字包括 nums[1] = 3，nums[4] = 5 和 nums[5] = 4，因为它们严格大于下标 i - k 和 i + k 处的数字。

示例 2：

输入： nums = [2,1], k = 1

输出： 2

解释：

唯一的好数字是 nums[0] = 2，因为它严格大于 nums[1]。



提示：

2 <= nums.length <= 100
1 <= nums[i] <= 1000
1 <= k <= floor(nums.length / 2)
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0, size = (int)nums.size();

        for (int i = 0; i < size; ++i) {
            if (i - k >= 0 && nums[i] <= nums[i - k]) {
                continue;
            }
            if (i + k < size && nums[i] <= nums[i + k]) {
                continue;
            }

            sum += nums[i];
        }

        return sum;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,3,2,1,5,4 };
    check.checkInt(12, o.sumOfGoodNumbers(nums, 2));

    nums = { 2,1 };
    check.checkInt(2, o.sumOfGoodNumbers(nums, 1));
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
