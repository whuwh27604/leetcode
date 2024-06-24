/* 使所有元素都可以被 3 整除的最少操作数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 。一次操作中，你可以将 nums 中的 任意 一个元素增加或者减少 1 。

请你返回将 nums 中所有元素都可以被 3 整除的 最少 操作次数。



示例 1：

输入：nums = [1,2,3,4]

输出：3

解释：

通过以下 3 个操作，数组中的所有元素都可以被 3 整除：

将 1 减少 1 。
将 2 增加 1 。
将 4 减少 1 。
示例 2：

输入：nums = [3,6,9]

输出：0



提示：

1 <= nums.length <= 50
1 <= nums[i] <= 50
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int opers = 0;

        for (int num : nums) {
            if (num % 3 != 0) {
                ++opers;
            }
        }

        return opers;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3,4 };
    check.checkInt(3, o.minimumOperations(nums));

    nums = { 3,6,9 };
    check.checkInt(0, o.minimumOperations(nums));
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
