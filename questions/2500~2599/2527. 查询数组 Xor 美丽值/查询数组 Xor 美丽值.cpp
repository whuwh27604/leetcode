/* 查询数组 Xor 美丽值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。

三个下标 i ，j 和 k 的 有效值 定义为 ((nums[i] | nums[j]) & nums[k]) 。

一个数组的 xor 美丽值 是数组中所有满足 0 <= i, j, k < n  的三元组 (i, j, k) 的 有效值 的异或结果。

请你返回 nums 的 xor 美丽值。

注意：

val1 | val2 是 val1 和 val2 的按位或。
val1 & val2 是 val1 和 val2 的按位与。


示例 1：

输入：nums = [1,4]
输出：5
解释：
三元组和它们对应的有效值如下：
- (0,0,0) 有效值为 ((1 | 1) & 1) = 1
- (0,0,1) 有效值为 ((1 | 1) & 4) = 0
- (0,1,0) 有效值为 ((1 | 4) & 1) = 1
- (0,1,1) 有效值为 ((1 | 4) & 4) = 4
- (1,0,0) 有效值为 ((4 | 1) & 1) = 1
- (1,0,1) 有效值为 ((4 | 1) & 4) = 4
- (1,1,0) 有效值为 ((4 | 4) & 1) = 0
- (1,1,1) 有效值为 ((4 | 4) & 4) = 4
数组的 xor 美丽值为所有有效值的按位异或 1 ^ 0 ^ 1 ^ 4 ^ 1 ^ 4 ^ 0 ^ 4 = 5 。
示例 2：

输入：nums = [15,45,20,2,34,35,5,44,32,30]
输出：34
解释：数组的 xor 美丽值为 34 。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int beauty = 0;

        for (int num : nums) {
            beauty ^= num;
        }

        return beauty;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,4 };
    check.checkInt(5, o.xorBeauty(nums));

    nums = { 15,45,20,2,34,35,5,44,32,30 };
    check.checkInt(34, o.xorBeauty(nums));
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
