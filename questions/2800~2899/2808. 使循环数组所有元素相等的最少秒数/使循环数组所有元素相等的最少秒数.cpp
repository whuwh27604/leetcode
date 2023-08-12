/* 使循环数组所有元素相等的最少秒数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始长度为 n 的数组 nums 。

每一秒，你可以对数组执行以下操作：

对于范围在 [0, n - 1] 内的每一个下标 i ，将 nums[i] 替换成 nums[i] ，nums[(i - 1 + n) % n] 或者 nums[(i + 1) % n] 三者之一。
注意，所有元素会被同时替换。

请你返回将数组 nums 中所有元素变成相等元素所需要的 最少 秒数。



示例 1：

输入：nums = [1,2,1,2]
输出：1
解释：我们可以在 1 秒内将数组变成相等元素：
- 第 1 秒，将每个位置的元素分别变为 [nums[3],nums[1],nums[3],nums[3]] 。变化后，nums = [2,2,2,2] 。
1 秒是将数组变成相等元素所需要的最少秒数。
示例 2：

输入：nums = [2,1,3,3,2]
输出：2
解释：我们可以在 2 秒内将数组变成相等元素：
- 第 1 秒，将每个位置的元素分别变为 [nums[0],nums[2],nums[2],nums[2],nums[3]] 。变化后，nums = [2,3,3,3,3] 。
- 第 2 秒，将每个位置的元素分别变为 [nums[1],nums[1],nums[2],nums[3],nums[4]] 。变化后，nums = [3,3,3,3,3] 。
2 秒是将数组变成相等元素所需要的最少秒数。
示例 3：

输入：nums = [5,5,5,5]
输出：0
解释：不需要执行任何操作，因为一开始数组中的元素已经全部相等。


提示：

1 <= n == nums.length <= 105
1 <= nums[i] <= 109
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> indices;
        int size = nums.size(), minSecond = size;
        vector<int> numbers = nums;
        numbers.insert(numbers.end(), nums.begin(), nums.end());

        for (int i = 0; i < 2 * size; ++i) {
            int num = numbers[i];
            if (indices[num].empty() || i - indices[num][0] <= size) {
                indices[num].push_back(i);
            }
        }

        for (auto& kv : indices) {
            minSecond = min(minSecond, getMinSecond(kv.second));
        }

        return minSecond;
    }

    int getMinSecond(vector<int>& indices) {
        int size = indices.size(), minSecond = 0;

        for (int i = 1; i < size; ++i) {
            minSecond = max(minSecond, (indices[i] - indices[i - 1]) / 2);
        }

        return minSecond;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,2,1,2 };
    check.checkInt(1, o.minimumSeconds(nums));

    nums = { 2,1,3,3,2 };
    check.checkInt(2, o.minimumSeconds(nums));

    nums = { 5,5,5,5 };
    check.checkInt(0, o.minimumSeconds(nums));

    nums = { 1,2,3 };
    check.checkInt(1, o.minimumSeconds(nums));

    nums = { 1,2,3,4 };
    check.checkInt(2, o.minimumSeconds(nums));

    nums = { 1,11,11,11,19,12,8,7,19 };
    check.checkInt(2, o.minimumSeconds(nums));
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
