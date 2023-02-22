/* 最小无法得到的或值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。

如果存在一些整数满足 0 <= index1 < index2 < ... < indexk < nums.length ，得到 nums[index1] | nums[index2] | ... | nums[indexk] = x ，那么我们说 x 是 可表达的 。换言之，如果一个整数能由 nums 的某个子序列的或运算得到，那么它就是可表达的。

请你返回 nums 不可表达的 最小非零整数 。



示例 1：

输入：nums = [2,1]
输出：4
解释：1 和 2 已经在数组中，因为 nums[0] | nums[1] = 2 | 1 = 3 ，所以 3 是可表达的。由于 4 是不可表达的，所以我们返回 4 。
示例 2：

输入：nums = [5,3,2]
输出：1
解释：1 是最小不可表达的数字。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        for (int num = 1; ; num <<= 1) {
            if (!isExist(nums, num)) {
                return num;
            }
        }
    }

    bool isExist(vector<int>& nums, int n) {
        for (int num : nums) {
            if (num == n) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,1 };
    check.checkInt(4, o.minImpossibleOR(nums));

    nums = { 5,3,2 };
    check.checkInt(1, o.minImpossibleOR(nums));
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
