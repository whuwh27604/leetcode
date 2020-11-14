/* 最大子序和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prevMax = 0, maxSub = nums[0];

        for (unsigned int i = 0; i < nums.size(); i++) {
            // 对于每一个nums[i]，需要决策它是继续加入前面的最大数组，还是以它为开头重新开始一个新的最大数组
            // 所以，如果prevMax + nums[i]大于nums[i]，则继续加入前面的最大数组，反之则从nums[i]重新开始一个最大数组
            prevMax = max(prevMax + nums[i], nums[i]);

            // 记录这一过程中出现的最大数组
            maxSub = max(maxSub, prevMax);
        }

        return maxSub;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
    check.checkInt(6, o.maxSubArray(nums));

    nums = { -5 };
    check.checkInt(-5, o.maxSubArray(nums));

    nums = { -5,5 };
    check.checkInt(5, o.maxSubArray(nums));

    nums = { -5,5,-3 };
    check.checkInt(5, o.maxSubArray(nums));

    nums = { -5,5,-3,4 };
    check.checkInt(6, o.maxSubArray(nums));

    nums = { -5,5,-3,4,-6 };
    check.checkInt(6, o.maxSubArray(nums));

    nums = { -5,5,-3,4,-6,1 };
    check.checkInt(6, o.maxSubArray(nums));

    nums = { -5,5,-3,4,-6,1,6 };
    check.checkInt(7, o.maxSubArray(nums));

    nums = { -5,5,-3,4,-6,1,6,-8 };
    check.checkInt(7, o.maxSubArray(nums));

    nums = { -5,5,-3,4,-6,1,6,-8,10 };
    check.checkInt(10, o.maxSubArray(nums));
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
