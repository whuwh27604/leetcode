/* 数组中两元素的最大乘积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums，请你选择数组的两个不同下标 i 和 j，使 (nums[i]-1)*(nums[j]-1) 取得最大值。

请你计算并返回该式的最大值。

 

示例 1：

输入：nums = [3,4,5,2]
输出：12
解释：如果选择下标 i=1 和 j=2（下标从 0 开始），则可以获得最大值，(nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12 。
示例 2：

输入：nums = [1,5,4,5]
输出：16
解释：选择下标 i=1 和 j=3（下标从 0 开始），则可以获得最大值 (5-1)*(5-1) = 16 。
示例 3：

输入：nums = [3,7]
输出：12
 

提示：

2 <= nums.length <= 500
1 <= nums[i] <= 10^3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-of-two-elements-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i, len = nums.size(), maximum = 0, secondMax = 0;

        for (i = 0; i < len; i++) {
            int number = nums[i];
            if (number >= maximum) {
                secondMax = maximum;
                maximum = number;
            }
            else if (number > secondMax) {
                secondMax = number;
            }
        }

        return (maximum - 1) * (secondMax - 1);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 3,4,5,2 };
    check.checkInt(12, o.maxProduct(nums));

    nums = { 1,5,4,5 };
    check.checkInt(16, o.maxProduct(nums));

    nums = { 3,7 };
    check.checkInt(12, o.maxProduct(nums));

    nums = { 1,1 };
    check.checkInt(0, o.maxProduct(nums));

    nums = { 6,5,4,3 };
    check.checkInt(20, o.maxProduct(nums));

    nums = { 5,6,4,3 };
    check.checkInt(20, o.maxProduct(nums));

    nums = { 3,4,5,6 };
    check.checkInt(20, o.maxProduct(nums));

    nums = { 3,4,6,5 };
    check.checkInt(20, o.maxProduct(nums));
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
