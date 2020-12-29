/* 数组的度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指数组里任一元素出现频数的最大值。

你的任务是找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。

示例 1:

输入: [1, 2, 2, 3, 1]
输出: 2
解释:
输入数组的度是2，因为元素1和2的出现频数最大，均为2.
连续子数组里面拥有相同度的有如下所示:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
最短连续子数组[2, 2]的长度为2，所以返回2.
示例 2:

输入: [1,2,2,3,1,4,2]
输出: 6
注意:

nums.length 在1到50,000区间范围内。
nums[i] 是一个在0到49,999范围内的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/degree-of-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> numInfo;  // vector[0] = numCount, vector[1] = minIndex, vector[2] = maxIndex
        int i, len = nums.size(), degree = 0, shortest = INT_MAX;

        for (i = 0; i < len; i++) {
            auto iter = numInfo.find(nums[i]);
            if (iter == numInfo.end()) {
                numInfo[nums[i]] = { 1, i, i };
            }
            else {
                iter->second[0]++;
                iter->second[2] = i;
            }

            vector<int>& info = numInfo[nums[i]];
            if (info[0] > degree) {
                degree = info[0];
                shortest = info[2] - info[1];
            }
            else if (info[0] == degree) {
                shortest = min(shortest, info[2] - info[1]);
            }
        }

        return shortest + 1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1, 2, 2, 3, 1 };
    check.checkInt(2, o.findShortestSubArray(nums));

    nums = { 1,2,2,3,1,4,2 };
    check.checkInt(6, o.findShortestSubArray(nums));

    nums = { 1 };
    check.checkInt(1, o.findShortestSubArray(nums));

    nums = { 1,2,3,4,5,6,1 };
    check.checkInt(7, o.findShortestSubArray(nums));

    nums = { 2,3,4,1,1,5,6,7 };
    check.checkInt(2, o.findShortestSubArray(nums));

    nums = { 1,2,3,4,2,5,5 };
    check.checkInt(2, o.findShortestSubArray(nums));

    nums = { 1,2,3,4,2,5,5,6,7,6,6 };
    check.checkInt(4, o.findShortestSubArray(nums));
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
