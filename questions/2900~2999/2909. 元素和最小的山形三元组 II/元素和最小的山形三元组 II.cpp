/* 元素和最小的山形三元组 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。

如果下标三元组 (i, j, k) 满足下述全部条件，则认为它是一个 山形三元组 ：

i < j < k
nums[i] < nums[j] 且 nums[k] < nums[j]
请你找出 nums 中 元素和最小 的山形三元组，并返回其 元素和 。如果不存在满足条件的三元组，返回 -1 。



示例 1：

输入：nums = [8,6,1,5,3]
输出：9
解释：三元组 (2, 3, 4) 是一个元素和等于 9 的山形三元组，因为：
- 2 < 3 < 4
- nums[2] < nums[3] 且 nums[4] < nums[3]
这个三元组的元素和等于 nums[2] + nums[3] + nums[4] = 9 。可以证明不存在元素和小于 9 的山形三元组。
示例 2：

输入：nums = [5,4,8,7,10,2]
输出：13
解释：三元组 (1, 3, 5) 是一个元素和等于 13 的山形三元组，因为：
- 1 < 3 < 5
- nums[1] < nums[3] 且 nums[5] < nums[3]
这个三元组的元素和等于 nums[1] + nums[3] + nums[5] = 13 。可以证明不存在元素和小于 13 的山形三元组。
示例 3：

输入：nums = [6,5,4,3,4,5]
输出：-1
解释：可以证明 nums 中不存在山形三元组。


提示：

3 <= nums.length <= 105
1 <= nums[i] <= 108
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int size = nums.size(), minSum = INT_MAX;
        vector<int> leftMin(size), rightMin(size);

        leftMin[0] = nums[0];
        for (int i = 1; i < size; ++i) {
            leftMin[i] = min(leftMin[i - 1], nums[i]);
        }

        rightMin[size - 1] = nums[size - 1];
        for (int i = size - 2; i >= 0; --i) {
            rightMin[i] = min(rightMin[i + 1], nums[i]);
        }

        for (int j = 1; j < size - 1; ++j) {
            if (leftMin[j - 1] < nums[j] && rightMin[j + 1] < nums[j]) {
                minSum = min(minSum, leftMin[j - 1] + nums[j] + rightMin[j + 1]);
            }
        }

        return minSum == INT_MAX ? -1 : minSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 8,6,1,5,3 };
    check.checkInt(9, o.minimumSum(nums));

    nums = { 5,4,8,7,10,2 };
    check.checkInt(13, o.minimumSum(nums));

    nums = { 6,5,4,3,4,5 };
    check.checkInt(-1, o.minimumSum(nums));
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
