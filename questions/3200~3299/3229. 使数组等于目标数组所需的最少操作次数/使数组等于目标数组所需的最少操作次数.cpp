/* 使数组等于目标数组所需的最少操作次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个长度相同的正整数数组 nums 和 target。

在一次操作中，你可以选择 nums 的任何子数组，并将该子数组内的每个元素的值增加或减少 1。

返回使 nums 数组变为 target 数组所需的 最少 操作次数。



示例 1：

输入： nums = [3,5,1,2], target = [4,6,2,4]

输出： 2

解释：

执行以下操作可以使 nums 等于 target：
- nums[0..3] 增加 1，nums = [4,6,2,3]。
- nums[3..3] 增加 1，nums = [4,6,2,4]。

示例 2：

输入： nums = [1,3,2], target = [2,1,4]

输出： 5

解释：

执行以下操作可以使 nums 等于 target：
- nums[0..0] 增加 1，nums = [2,3,2]。
- nums[1..1] 减少 1，nums = [2,2,2]。
- nums[1..1] 减少 1，nums = [2,1,2]。
- nums[2..2] 增加 1，nums = [2,1,3]。
- nums[2..2] 增加 1，nums = [2,1,4]。



提示：

1 <= nums.length == target.length <= 105
1 <= nums[i], target[i] <= 108
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int size = (int)nums.size(), prev = nums[0] - target[0];
        long long opered = abs(prev), total = opered;

        for (int i = 1; i < size; ++i) {
            int cur = nums[i] - target[i], opers = abs(cur);

            if ((long long)prev * cur < 0) {
                total += opers;
            }
            else {
                if (opers > opered) {
                    total += (opers - opered);
                }
            }

            prev = cur;
            opered = opers;
        }

        return total;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 3,5,1,2 };
    vector<int> target = { 4,6,2,4 };
    check.checkLongLong(2, o.minimumOperations(nums, target));

    nums = { 1,3,2 };
    target = { 2,1,4 };
    check.checkLongLong(5, o.minimumOperations(nums, target));
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
