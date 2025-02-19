/* 变长子数组求和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组 nums 。对于 每个 下标 i（0 <= i < n），定义对应的子数组 nums[start ... i]（start = max(0, i - nums[i])）。

返回为数组中每个下标定义的子数组中所有元素的总和。

子数组 是数组中的一个连续、非空 的元素序列。


示例 1：

输入：nums = [2,3,1]

输出：11

解释：

下标 i	子数组	和
0	nums[0] = [2]	2
1	nums[0 ... 1] = [2, 3]	5
2	nums[1 ... 2] = [3, 1]	4
总和	 	11
总和为 11 。因此，输出 11 。

示例 2：

输入：nums = [3,1,1,2]

输出：13

解释：

下标 i	子数组	和
0	nums[0] = [3]	3
1	nums[0 ... 1] = [3, 1]	4
2	nums[1 ... 2] = [1, 1]	2
3	nums[1 ... 3] = [1, 1, 2]	4
总和	 	13
总和为 13 。因此，输出为 13 。



提示：

1 <= n == nums.length <= 100
1 <= nums[i] <= 1000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = (int)nums.size(), sum = 0;
        vector<int> presum(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            presum[i + 1] = presum[i] + nums[i];
            int start = max(0, i - nums[i]);
            sum += (presum[i + 1] - presum[start]);
        }

        return sum;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 2,3,1 };
    check.checkInt(11, o.subarraySum(nums));

    nums = { 3,1,1,2 };
    check.checkInt(13, o.subarraySum(nums));
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
