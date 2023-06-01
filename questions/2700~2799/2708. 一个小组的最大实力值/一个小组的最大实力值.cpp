/* 一个小组的最大实力值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums ，它表示一个班级中所有学生在一次考试中的成绩。老师想选出一部分同学组成一个 非空 小组，且这个小组的 实力值 最大，如果这个小组里的学生下标为 i0, i1, i2, ... , ik ，那么这个小组的实力值定义为 nums[i0] * nums[i1] * nums[i2] * ... * nums[ik​] 。

请你返回老师创建的小组能得到的最大实力值为多少。



示例 1：

输入：nums = [3,-1,-5,2,5,-9]
输出：1350
解释：一种构成最大实力值小组的方案是选择下标为 [0,2,3,4,5] 的学生。实力值为 3 * (-5) * 2 * 5 * (-9) = 1350 ，这是可以得到的最大实力值。
示例 2：

输入：nums = [-4,-5,-4]
输出：20
解释：选择下标为 [0, 1] 的学生。得到的实力值为 20 。我们没法得到更大的实力值。


提示：

1 <= nums.length <= 13
-9 <= nums[i] <= 9
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) {  // 如果只有一个数，必须返回它
            return nums[0];
        }

        int count0 = 0, countNeg = 0, maxNeg = INT_MIN;
        long long maxStr = 1;

        for (int num : nums) {  // 统计0的个数，负数的个数，最大的负数，所有非0数相乘
            if (num == 0) {
                ++count0;
            }
            else {
                maxStr *= num;

                if (num < 0) {
                    ++countNeg;
                    maxNeg = max(maxNeg, num);
                }
            }
        }

        if ((countNeg == 1 && count0 == size - 1) || (count0 == size)) {  // 如果只有一个负数，其它都是0，或者全部是0，那么返回0
            return 0;
        }

        if ((countNeg & 1) == 1) {  // 如果负数有奇数个，需要将最大的负数排除在外
            maxStr /= maxNeg;
        }

        return maxStr;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,-1,-5,2,5,-9 };
    check.checkLongLong(1350, o.maxStrength(nums));

    nums = { -4,-5,-4 };
    check.checkLongLong(20, o.maxStrength(nums));

    nums = { 3 };
    check.checkLongLong(3, o.maxStrength(nums));

    nums = { -5,0 };
    check.checkLongLong(0, o.maxStrength(nums));

    nums = { -5,0,0 };
    check.checkLongLong(0, o.maxStrength(nums));

    nums = { -5,5 };
    check.checkLongLong(5, o.maxStrength(nums));

    nums = { 0,0,0,0,0,0,0,0,0,0,0,0,0 };
    check.checkLongLong(0, o.maxStrength(nums));
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
