/* 最小元素和最大元素的最小平均值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有一个初始为空的浮点数数组 averages。另给你一个包含 n 个整数的数组 nums，其中 n 为偶数。

你需要重复以下步骤 n / 2 次：

从 nums 中移除 最小 的元素 minElement 和 最大 的元素 maxElement。
将 (minElement + maxElement) / 2 加入到 averages 中。
返回 averages 中的 最小 元素。



示例 1：

输入： nums = [7,8,3,4,15,13,4,1]

输出： 5.5

解释：

步骤	nums	averages
0	[7,8,3,4,15,13,4,1]	[]
1	[7,8,3,4,13,4]	[8]
2	[7,8,4,4]	[8,8]
3	[7,4]	[8,8,6]
4	[]	[8,8,6,5.5]
返回 averages 中最小的元素，即 5.5。
示例 2：

输入： nums = [1,9,8,3,10,5]

输出： 5.5

解释：

步骤	nums	averages
0	[1,9,8,3,10,5]	[]
1	[9,8,3,5]	[5.5]
2	[8,5]	[5.5,6]
3	[]	[5.5,6,6.5]
示例 3：

输入： nums = [1,2,3,7,8,9]

输出： 5.0

解释：

步骤	nums	averages
0	[1,2,3,7,8,9]	[]
1	[2,3,7,8]	[5]
2	[3,7]	[5,5]
3	[]	[5,5,5]


提示：

2 <= n == nums.length <= 50
n 为偶数。
1 <= nums[i] <= 50
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int size = (int)nums.size(), minSum = INT_MAX;

        sort(nums.begin(), nums.end());

        for (int i = 0, j = size - 1; i < j; ++i, --j) {
            minSum = min(minSum, nums[i] + nums[j]);
        }

        return (double)minSum / 2;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 7,8,3,4,15,13,4,1 };
    check.checkDouble(5.5, o.minimumAverage(nums));

    nums = { 1,9,8,3,10,5 };
    check.checkDouble(5.5, o.minimumAverage(nums));

    nums = { 1,2,3,7,8,9 };
    check.checkDouble(5.0, o.minimumAverage(nums));
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
