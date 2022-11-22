/* 不同的平均值数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始长度为 偶数 的整数数组 nums 。

只要 nums 不是 空数组，你就重复执行以下步骤：

找到 nums 中的最小值，并删除它。
找到 nums 中的最大值，并删除它。
计算删除两数的平均值。
两数 a 和 b 的 平均值 为 (a + b) / 2 。

比方说，2 和 3 的平均值是 (2 + 3) / 2 = 2.5 。
返回上述过程能得到的 不同 平均值的数目。

注意 ，如果最小值或者最大值有重复元素，可以删除任意一个。



示例 1：

输入：nums = [4,1,4,0,3,5]
输出：2
解释：
1. 删除 0 和 5 ，平均值是 (0 + 5) / 2 = 2.5 ，现在 nums = [4,1,4,3] 。
2. 删除 1 和 4 ，平均值是 (1 + 4) / 2 = 2.5 ，现在 nums = [4,3] 。
3. 删除 3 和 4 ，平均值是 (3 + 4) / 2 = 3.5 。
2.5 ，2.5 和 3.5 之中总共有 2 个不同的数，我们返回 2 。
示例 2：

输入：nums = [1,100]
输出：1
解释：
删除 1 和 100 后只有一个平均值，所以我们返回 1 。


提示：

2 <= nums.length <= 100
nums.length 是偶数。
0 <= nums[i] <= 100
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<int> sums;

        sort(nums.begin(), nums.end());

        for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
            sums.insert(nums[i] + nums[j]);
        }

        return sums.size();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 4,1,4,0,3,5 };
    check.checkInt(2, o.distinctAverages(nums));

    nums = { 1,100 };
    check.checkInt(1, o.distinctAverages(nums));

    nums = { 9,5,7,8,7,9,8,2,0,7 };
    check.checkInt(5, o.distinctAverages(nums));
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
