/* 交换得到字典序最小的数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的 正整数 数组 nums 和一个 正整数 limit 。

在一次操作中，你可以选择任意两个下标 i 和 j，如果 满足 |nums[i] - nums[j]| <= limit ，则交换 nums[i] 和 nums[j] 。

返回执行任意次操作后能得到的 字典序最小的数组 。

如果在数组 a 和数组 b 第一个不同的位置上，数组 a 中的对应元素比数组 b 中的对应元素的字典序更小，则认为数组 a 就比数组 b 字典序更小。例如，数组 [2,10,3] 比数组 [10,2,3] 字典序更小，下标 0 处是两个数组第一个不同的位置，且 2 < 10 。



示例 1：

输入：nums = [1,5,3,9,8], limit = 2
输出：[1,3,5,8,9]
解释：执行 2 次操作：
- 交换 nums[1] 和 nums[2] 。数组变为 [1,3,5,9,8] 。
- 交换 nums[3] 和 nums[4] 。数组变为 [1,3,5,8,9] 。
即便执行更多次操作，也无法得到字典序更小的数组。
注意，执行不同的操作也可能会得到相同的结果。
示例 2：

输入：nums = [1,7,6,18,2,1], limit = 3
输出：[1,6,7,18,1,2]
解释：执行 3 次操作：
- 交换 nums[1] 和 nums[2] 。数组变为 [1,6,7,18,2,1] 。
- 交换 nums[0] 和 nums[4] 。数组变为 [2,6,7,18,1,1] 。
- 交换 nums[0] 和 nums[5] 。数组变为 [1,6,7,18,1,2] 。
即便执行更多次操作，也无法得到字典序更小的数组。
示例 3：

输入：nums = [1,7,28,19,10], limit = 3
输出：[1,7,28,19,10]
解释：[1,7,28,19,10] 是字典序最小的数组，因为不管怎么选择下标都无法执行操作。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= limit <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int size = nums.size();
        vector<pair<int, int>> numIndices(size);
        vector<int> ans(size);

        for (int i = 0; i < size; ++i) {
            numIndices[i] = { nums[i],i };
        }

        sort(numIndices.begin(), numIndices.end());

        int i = 0;
        while (i < size) {
            int j = i;
            vector<int> indices;

            do {
                indices.push_back(numIndices[j++].second);
            } while (j < size && numIndices[j].first - numIndices[j - 1].first <= limit);

            sort(indices.begin(), indices.end());

            for (int k = 0; k < (int)indices.size(); ++k) {
                ans[indices[k]] = numIndices[i + k].first;
            }

            i = j;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,5,3,9,8 };
    vector<int> actual = o.lexicographicallySmallestArray(nums, 2);
    vector<int> expected = { 1,3,5,8,9 };
    check.checkIntVector(expected, actual);

    nums = { 1,7,6,18,2,1 };
    actual = o.lexicographicallySmallestArray(nums, 3);
    expected = { 1,6,7,18,1,2 };
    check.checkIntVector(expected, actual);

    nums = { 1,7,28,19,10 };
    actual = o.lexicographicallySmallestArray(nums, 3);
    expected = { 1,7,28,19,10 };
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
