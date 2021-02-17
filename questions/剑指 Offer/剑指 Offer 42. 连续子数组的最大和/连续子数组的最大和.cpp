/* 连续子数组的最大和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

 

示例1:

输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 

提示：

1 <= arr.length <= 10^5
-100 <= arr[i] <= 100
注意：本题与主站 53 题相同：https://leetcode-cn.com/problems/maximum-subarray/

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSum = INT_MIN;

        for (int num : nums) {
            sum += num;
            maxSum = sum > maxSum ? sum : maxSum;
            sum = sum < 0 ? 0 : sum;
        }

        return maxSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

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
