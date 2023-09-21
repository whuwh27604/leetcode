/* 计算 K 置位下标对应元素的和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。

请你用整数形式返回 nums 中的特定元素之 和 ，这些特定元素满足：其对应下标的二进制表示中恰存在 k 个置位。

整数的二进制表示中的 1 就是这个整数的 置位 。

例如，21 的二进制表示为 10101 ，其中有 3 个置位。



示例 1：

输入：nums = [5,10,1,5,2], k = 1
输出：13
解释：下标的二进制表示是：
0 = 0002
1 = 0012
2 = 0102
3 = 0112
4 = 1002
下标 1、2 和 4 在其二进制表示中都存在 k = 1 个置位。
因此，答案为 nums[1] + nums[2] + nums[4] = 13 。
示例 2：

输入：nums = [4,3,2,1], k = 2
输出：1
解释：下标的二进制表示是：
0 = 002
1 = 012
2 = 102
3 = 112
只有下标 3 的二进制表示中存在 k = 2 个置位。
因此，答案为 nums[3] = 1 。


提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 105
0 <= k <= 10
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int size = nums.size(), sum = 0;

        for (int i = 0; i < size; ++i) {
            if (popcount(i) == k) {
                sum += nums[i];
            }
        }

        return sum;
    }

    int popcount(int n) {
        int cnt = 0;

        while (n != 0) {
            n &= (n - 1);
            ++cnt;
        }

        return cnt;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 5,10,1,5,2 };
    check.checkInt(13, o.sumIndicesWithKSetBits(nums, 1));

    nums = { 4,3,2,1 };
    check.checkInt(1, o.sumIndicesWithKSetBits(nums, 2));
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
