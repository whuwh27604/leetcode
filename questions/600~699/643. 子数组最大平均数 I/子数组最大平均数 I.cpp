/* 子数组最大平均数 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。

示例 1:

输入: [1,12,-5,-6,50,3], k = 4
输出: 12.75
解释: 最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
 

注意:

1 <= k <= n <= 30,000。
所给数据范围 [-10,000，10,000]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-average-subarray-i
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, maxSum = 0;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        maxSum = sum;

        for (unsigned int j = k; j < nums.size(); j++) {
            sum = (sum - nums[j - k] + nums[j]);
            maxSum = max(maxSum, sum);
        }

        return (((double)maxSum) / k);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,12,-5,-6,50,3 };
    check.checkDouble(12.75, o.findMaxAverage(nums, 4));
    check.checkDouble(50, o.findMaxAverage(nums, 1));
    check.checkDouble(9.1666666666, o.findMaxAverage(nums, 6));

    nums = { 12 };
    check.checkDouble(12, o.findMaxAverage(nums, 1));
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
