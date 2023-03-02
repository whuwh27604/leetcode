/* 左右元素和的差值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums ，请你找出一个下标从 0 开始的整数数组 answer ，其中：

answer.length == nums.length
answer[i] = |leftSum[i] - rightSum[i]|
其中：

leftSum[i] 是数组 nums 中下标 i 左侧元素之和。如果不存在对应的元素，leftSum[i] = 0 。
rightSum[i] 是数组 nums 中下标 i 右侧元素之和。如果不存在对应的元素，rightSum[i] = 0 。
返回数组 answer 。



示例 1：

输入：nums = [10,4,8,3]
输出：[15,1,11,22]
解释：数组 leftSum 为 [0,10,14,22] 且数组 rightSum 为 [15,11,3,0] 。
数组 answer 为 [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22] 。
示例 2：

输入：nums = [1]
输出：[0]
解释：数组 leftSum 为 [0] 且数组 rightSum 为 [0] 。
数组 answer 为 [|0 - 0|] = [0] 。


提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 105
*/

#include <iostream>
#include <numeric>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int index = 0, size = nums.size(), leftSum = 0, rightSum = sum;
        vector<int> ans(size);

        for (int num : nums) {
            rightSum -= num;
            ans[index++] = abs(leftSum - rightSum);
            leftSum += num;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 10,4,8,3 };
    vector<int> actual = o.leftRigthDifference(nums);
    vector<int> expected = { 15,1,11,22 };
    check.checkIntVector(expected, actual);

    nums = { 1 };
    actual = o.leftRigthDifference(nums);
    expected = { 0 };
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
