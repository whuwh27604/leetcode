/* 标记所有元素后数组的分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 nums ，它包含若干正整数。

一开始分数 score = 0 ，请你按照下面算法求出最后分数：

从数组中选择最小且没有被标记的整数。如果有相等元素，选择下标最小的一个。
将选中的整数加到 score 中。
标记 被选中元素，如果有相邻元素，则同时标记 与它相邻的两个元素 。
重复此过程直到数组中所有元素都被标记。
请你返回执行上述算法后最后的分数。



示例 1：

输入：nums = [2,1,3,4,5,2]
输出：7
解释：我们按照如下步骤标记元素：
- 1 是最小未标记元素，所以标记它和相邻两个元素：[2,1,3,4,5,2] 。
- 2 是最小未标记元素，所以标记它和左边相邻元素：[2,1,3,4,5,2] 。
- 4 是仅剩唯一未标记的元素，所以我们标记它：[2,1,3,4,5,2] 。
总得分为 1 + 2 + 4 = 7 。
示例 2：

输入：nums = [2,3,5,1,3,2]
输出：5
解释：我们按照如下步骤标记元素：
- 1 是最小未标记元素，所以标记它和相邻两个元素：[2,3,5,1,3,2] 。
- 2 是最小未标记元素，由于有两个 2 ，我们选择最左边的一个 2 ，也就是下标为 0 处的 2 ，以及它右边相邻的元素：[2,3,5,1,3,2] 。
- 2 是仅剩唯一未标记的元素，所以我们标记它：[2,3,5,1,3,2] 。
总得分为 1 + 2 + 2 = 5 。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 106
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int size = nums.size();
        vector<bool> marked(size, false);
        vector<pair<int, int>> numIndices(size);

        for (int i = 0; i < size; ++i) {
            numIndices[i] = { nums[i],i };
        }

        sort(numIndices.begin(), numIndices.end());

        for (auto& numIndex : numIndices) {
            if (!marked[numIndex.second]) {
                score += numIndex.first;

                marked[numIndex.second] = true;
                if (numIndex.second != 0) {
                    marked[numIndex.second - 1] = true;
                }
                if (numIndex.second != size - 1) {
                    marked[numIndex.second + 1] = true;
                }
            }
        }

        return score;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,1,3,4,5,2 };
    check.checkLongLong(7, o.findScore(nums));

    nums = { 2,3,5,1,3,2 };
    check.checkLongLong(5, o.findScore(nums));
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
