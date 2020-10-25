/* 一维数组的动态和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 nums 。数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 。

请返回 nums 的动态和。

 

示例 1：

输入：nums = [1,2,3,4]
输出：[1,3,6,10]
解释：动态和计算过程为 [1, 1+2, 1+2+3, 1+2+3+4] 。
示例 2：

输入：nums = [1,1,1,1,1]
输出：[1,2,3,4,5]
解释：动态和计算过程为 [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1] 。
示例 3：

输入：nums = [3,1,2,10,1]
输出：[3,4,6,16,17]
 

提示：

1 <= nums.length <= 1000
-10^6 <= nums[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/running-sum-of-1d-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sums;
        int sum = 0;

        for (int n : nums) {
            sum += n;
            sums.push_back(sum);
        }

        return sums;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = {};
    vector<int> actual = o.runningSum(nums);
    vector<int> expected = {};
    check.checkIntVector(expected, actual);

    nums = { 1 };
    actual = o.runningSum(nums);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    nums = { 1,3 };
    actual = o.runningSum(nums);
    expected = { 1,4 };
    check.checkIntVector(expected, actual);

    nums = { 1,2,3,4 };
    actual = o.runningSum(nums);
    expected = { 1,3,6,10 };
    check.checkIntVector(expected, actual);

    nums = { 1,1,1,1,1 };
    actual = o.runningSum(nums);
    expected = { 1,2,3,4,5 };
    check.checkIntVector(expected, actual);

    nums = { 3,1,2,10,1 };
    actual = o.runningSum(nums);
    expected = { 3,4,6,16,17 };
    check.checkIntVector(expected, actual);
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
