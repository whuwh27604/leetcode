/* 只出现一次的数字 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。



示例 1：

输入：nums = [2,2,3,2]
输出：3
示例 2：

输入：nums = [0,1,0,1,0,1,100]
输出：100


提示：

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
nums 中，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次


进阶：你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？



注意：本题与主站 137 题相同：https://leetcode-cn.com/problems/single-number-ii/
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;

        for (int num : nums) {
            b = ~a & (b ^ num);
            a = ~b & (a ^ num);
        }

        return b;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 2,2,3,2 };
    check.checkInt(3, o.singleNumber(nums));

    nums = { 0,1,0,1,0,1,100 };
    check.checkInt(100, o.singleNumber(nums));
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
