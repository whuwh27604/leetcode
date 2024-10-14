/* 计算子数组的 x-sum I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个由 n 个整数组成的数组 nums，以及两个整数 k 和 x。

数组的 x-sum 计算按照以下步骤进行：

统计数组中所有元素的出现次数。
仅保留出现次数最多的前 x 个元素的每次出现。如果两个元素的出现次数相同，则数值 较大 的元素被认为出现次数更多。
计算结果数组的和。
注意，如果数组中的不同元素少于 x 个，则其 x-sum 是数组的元素总和。

返回一个长度为 n - k + 1 的整数数组 answer，其中 answer[i] 是
子数组
 nums[i..i + k - 1] 的 x-sum。

子数组 是数组内的一个连续 非空 的元素序列。



示例 1：

输入：nums = [1,1,2,2,3,4,2,3], k = 6, x = 2

输出：[6,10,12]

解释：

对于子数组 [1, 1, 2, 2, 3, 4]，只保留元素 1 和 2。因此，answer[0] = 1 + 1 + 2 + 2。
对于子数组 [1, 2, 2, 3, 4, 2]，只保留元素 2 和 4。因此，answer[1] = 2 + 2 + 2 + 4。注意 4 被保留是因为其数值大于出现其他出现次数相同的元素（3 和 1）。
对于子数组 [2, 2, 3, 4, 2, 3]，只保留元素 2 和 3。因此，answer[2] = 2 + 2 + 2 + 3 + 3。
示例 2：

输入：nums = [3,8,7,8,7,5], k = 2, x = 2

输出：[11,15,15,15,12]

解释：

由于 k == x，answer[i] 等于子数组 nums[i..i + k - 1] 的总和。



提示：

1 <= n == nums.length <= 50
1 <= nums[i] <= 50
1 <= x <= k <= nums.length
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int size = (int)nums.size();
        vector<int> ans(size - k + 1);

        for (int i = 0; i < size - k + 1; ++i) {
            ans[i] = xSum(nums, i, i + k - 1, x);
        }

        return ans;
    }

    int xSum(vector<int>& nums, int start, int end, int x) {
        vector<int> count(51, 0);
        vector<pair<int, int>> cntNums;
        int sum = 0;

        for (int i = start; i <= end; ++i) {
            ++count[nums[i]];
        }

        for (int n = 1; n <= 50; ++n) {
            if (count[n] != 0) {
                cntNums.push_back({ count[n],n });
            }
        }

        sort(cntNums.begin(), cntNums.end());

        for (int i = (int)cntNums.size() - 1, j = 0; i >= 0 && j < x; --i, ++j) {
            sum += cntNums[i].first * cntNums[i].second;
        }

        return sum;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,1,2,2,3,4,2,3 };
    vector<int> actual = o.findXSum(nums, 6, 2);
    vector<int> expected = { 6,10,12 };
    check.checkIntVector(expected, actual);

    nums = { 3,8,7,8,7,5 };
    actual = o.findXSum(nums, 2, 2);
    expected = { 11,15,15,15,12 };
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
