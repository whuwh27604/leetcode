/* 半有序排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始、长度为 n 的整数排列 nums 。

如果排列的第一个数字等于 1 且最后一个数字等于 n ，则称其为 半有序排列 。你可以执行多次下述操作，直到将 nums 变成一个 半有序排列 ：

选择 nums 中相邻的两个元素，然后交换它们。
返回使 nums 变成 半有序排列 所需的最小操作次数。

排列 是一个长度为 n 的整数序列，其中包含从 1 到 n 的每个数字恰好一次。



示例 1：

输入：nums = [2,1,4,3]
输出：2
解释：可以依次执行下述操作得到半有序排列：
1 - 交换下标 0 和下标 1 对应元素。排列变为 [1,2,4,3] 。
2 - 交换下标 2 和下标 3 对应元素。排列变为 [1,2,3,4] 。
可以证明，要让 nums 成为半有序排列，不存在执行操作少于 2 次的方案。
示例 2：

输入：nums = [2,4,1,3]
输出：3
解释：
可以依次执行下述操作得到半有序排列：
1 - 交换下标 1 和下标 2 对应元素。排列变为 [2,1,4,3] 。
2 - 交换下标 0 和下标 1 对应元素。排列变为 [1,2,4,3] 。
3 - 交换下标 2 和下标 3 对应元素。排列变为 [1,2,3,4] 。
可以证明，要让 nums 成为半有序排列，不存在执行操作少于 3 次的方案。
示例 3：

输入：nums = [1,3,4,2,5]
输出：0
解释：这个排列已经是一个半有序排列，无需执行任何操作。


提示：

2 <= nums.length == n <= 50
1 <= nums[i] <= 50
nums 是一个 排列
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size(), index1 = 0, indexN = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) {
                index1 = i;
            }
            else if (nums[i] == n) {
                indexN = i;
            }
        }

        int opers = index1 + n - 1 - indexN;

        return index1 < indexN ? opers : opers - 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,1,4,3 };
    check.checkInt(2, o.semiOrderedPermutation(nums));

    nums = { 2,4,1,3 };
    check.checkInt(3, o.semiOrderedPermutation(nums));

    nums = { 1,3,4,2,5 };
    check.checkInt(0, o.semiOrderedPermutation(nums));
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
