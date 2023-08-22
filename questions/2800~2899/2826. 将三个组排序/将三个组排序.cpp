/* 将三个组排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始长度为 n 的整数数组 nums 。

从 0 到 n - 1 的数字被分为编号从 1 到 3 的三个组，数字 i 属于组 nums[i] 。注意，有的组可能是 空的 。

你可以执行以下操作任意次：

选择数字 x 并改变它的组。更正式的，你可以将 nums[x] 改为数字 1 到 3 中的任意一个。
你将按照以下过程构建一个新的数组 res ：

将每个组中的数字分别排序。
将组 1 ，2 和 3 中的元素 依次 连接以得到 res 。
如果得到的 res 是 非递减顺序的，那么我们称数组 nums 是 美丽数组 。

请你返回将 nums 变为 美丽数组 需要的最少步数。



示例 1：

输入：nums = [2,1,3,2,1]
输出：3
解释：以下三步操作是最优方案：
1. 将 nums[0] 变为 1 。
2. 将 nums[2] 变为 1 。
3. 将 nums[3] 变为 1 。
执行以上操作后，将每组中的数字排序，组 1 为 [0,1,2,3,4] ，组 2 和组 3 都为空。所以 res 等于 [0,1,2,3,4] ，它是非递减顺序的。
三步操作是最少需要的步数。
示例 2：

输入：nums = [1,3,2,1,3,3]
输出：2
解释：以下两步操作是最优方案：
1. 将 nums[1] 变为 1 。
2. 将 nums[2] 变为 1 。
执行以上操作后，将每组中的数字排序，组 1 为 [0,1,2,3] ，组 2 为空，组 3 为 [4,5] 。所以 res 等于 [0,1,2,3,4,5] ，它是非递减顺序的。
两步操作是最少需要的步数。
示例 3：

输入：nums = [2,2,2,2,3,3]
输出：0
解释：不需要执行任何操作。
组 1 为空，组 2 为 [0,1,2,3] ，组 3 为 [4,5] 。所以 res 等于 [0,1,2,3,4,5] ，它是非递减顺序的。


提示：

1 <= nums.length <= 100
1 <= nums[i] <= 3
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int size = nums.size(), minOpers = size;
        vector<vector<int>> count(4, vector<int>(size + 1, 0));

        for (int i = 0; i < size; ++i) {
            for (int j = 1; j <= 3; ++j) {
                count[j][i + 1] = count[j][i] + (j == nums[i] ? 1 : 0);
            }
        }

        for (int i = 0; i <= size; ++i) {
            for (int j = i; j <= size; ++j) {
                minOpers = min(minOpers, size - count[1][i] - (count[2][j] - count[2][i]) - (count[3][size] - count[3][j]));
            }
        }

        return minOpers;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,1,3,2,1 };
    check.checkInt(3, o.minimumOperations(nums));

    nums = { 1,3,2,1,3,3 };
    check.checkInt(2, o.minimumOperations(nums));

    nums = { 2,2,2,2,3,3 };
    check.checkInt(0, o.minimumOperations(nums));
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
