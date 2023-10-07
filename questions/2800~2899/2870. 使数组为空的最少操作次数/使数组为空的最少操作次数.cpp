/* 使数组为空的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的正整数数组 nums 。

你可以对数组执行以下两种操作 任意次 ：

从数组中选择 两个 值 相等 的元素，并将它们从数组中 删除 。
从数组中选择 三个 值 相等 的元素，并将它们从数组中 删除 。
请你返回使数组为空的 最少 操作次数，如果无法达成，请返回 -1 。



示例 1：

输入：nums = [2,3,3,2,2,4,2,3,4]
输出：4
解释：我们可以执行以下操作使数组为空：
- 对下标为 0 和 3 的元素执行第一种操作，得到 nums = [3,3,2,4,2,3,4] 。
- 对下标为 2 和 4 的元素执行第一种操作，得到 nums = [3,3,4,3,4] 。
- 对下标为 0 ，1 和 3 的元素执行第二种操作，得到 nums = [4,4] 。
- 对下标为 0 和 1 的元素执行第一种操作，得到 nums = [] 。
至少需要 4 步操作使数组为空。
示例 2：

输入：nums = [2,1,2,2,3,3]
输出：-1
解释：无法使数组为空。


提示：

2 <= nums.length <= 105
1 <= nums[i] <= 106
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> count;
        int opers = 0;

        for (int num : nums) {
            ++count[num];
        }

        for (auto& kv : count) {
            int cnt = kv.second;
            if (cnt == 1) {
                return -1;
            }

            if ((cnt % 3) == 0) {
                opers += cnt / 3;
            }
            else {
                opers += (cnt / 3 + 1);
            }
        }

        return opers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,3,3,2,2,4,2,3,4 };
    check.checkInt(4, o.minOperations(nums));

    nums = { 2,1,2,2,3,3 };
    check.checkInt(-1, o.minOperations(nums));
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
