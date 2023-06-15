/* 既不是最小值也不是最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，数组由 不同正整数 组成，请你找出并返回数组中 任一 既不是 最小值 也不是 最大值 的数字，如果不存在这样的数字，返回 -1 。

返回所选整数。



示例 1：

输入：nums = [3,2,1,4]
输出：2
解释：在这个示例中，最小值是 1 ，最大值是 4 。因此，2 或 3 都是有效答案。
示例 2：

输入：nums = [1,2]
输出：-1
解释：由于不存在既不是最大值也不是最小值的数字，我们无法选出满足题目给定条件的数字。因此，不存在答案，返回 -1 。
示例 3：

输入：nums = [2,1,3]
输出：2
解释：2 既不是最小值，也不是最大值，这个示例只有这一个有效答案。


提示：

1 <= nums.length <= 100
1 <= nums[i] <= 100
nums 中的所有数字互不相同
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end()), minNum = *min_element(nums.begin(), nums.end());

        for (int num : nums) {
            if (num != minNum && num != maxNum) {
                return num;
            }
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,2,1,4 };
    check.checkInt(3, o.findNonMinOrMax(nums));

    nums = { 1,2 };
    check.checkInt(-1, o.findNonMinOrMax(nums));

    nums = { 2,1,3 };
    check.checkInt(2, o.findNonMinOrMax(nums));
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
