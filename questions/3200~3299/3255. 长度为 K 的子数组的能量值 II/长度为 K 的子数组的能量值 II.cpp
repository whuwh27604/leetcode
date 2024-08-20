/* 长度为 K 的子数组的能量值 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的整数数组 nums 和一个正整数 k 。

一个数组的 能量值 定义为：

如果 所有 元素都是依次 连续 且 上升 的，那么能量值为 最大 的元素。
否则为 -1 。
你需要求出 nums 中所有长度为 k 的
子数组
 的能量值。

请你返回一个长度为 n - k + 1 的整数数组 results ，其中 results[i] 是子数组 nums[i..(i + k - 1)] 的能量值。



示例 1：

输入：nums = [1,2,3,4,3,2,5], k = 3

输出：[3,4,-1,-1,-1]

解释：

nums 中总共有 5 个长度为 3 的子数组：

[1, 2, 3] 中最大元素为 3 。
[2, 3, 4] 中最大元素为 4 。
[3, 4, 3] 中元素 不是 连续的。
[4, 3, 2] 中元素 不是 上升的。
[3, 2, 5] 中元素 不是 连续的。
示例 2：

输入：nums = [2,2,2,2,2], k = 4

输出：[-1,-1]

示例 3：

输入：nums = [3,2,3,2,3,2], k = 2

输出：[-1,3,-1,3,-1]



提示：

1 <= n == nums.length <= 105
1 <= nums[i] <= 106
1 <= k <= n
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int size = (int)nums.size(), count = 0, prev = INT_MIN;
        vector<int> ans(size - k + 1);

        for (int i = 0; i < size; ++i) {
            if (nums[i] == prev + 1) {
                ++count;
            }
            else {
                count = 1;
            }

            if (i >= k - 1) {
                if (count >= k) {
                    ans[i - k + 1] = nums[i];
                }
                else {
                    ans[i - k + 1] = -1;
                }
            }

            prev = nums[i];
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3,4,3,2,5 };
    vector<int> actual = o.resultsArray(nums, 3);
    vector<int> expected = { 3,4,-1,-1,-1 };
    check.checkIntVector(expected, actual);

    nums = { 2,2,2,2,2 };
    actual = o.resultsArray(nums, 4);
    expected = { -1,-1 };
    check.checkIntVector(expected, actual);

    nums = { 3,2,3,2,3,2 };
    actual = o.resultsArray(nums, 2);
    expected = { -1,3,-1,3,-1 };
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
