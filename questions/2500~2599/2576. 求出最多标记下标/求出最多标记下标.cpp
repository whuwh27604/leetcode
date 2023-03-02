/* 求出最多标记下标.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 nums 。

一开始，所有下标都没有被标记。你可以执行以下操作任意次：

选择两个 互不相同且未标记 的下标 i 和 j ，满足 2 * nums[i] <= nums[j] ，标记下标 i 和 j 。
请你执行上述操作任意次，返回 nums 中最多可以标记的下标数目。



示例 1：

输入：nums = [3,5,2,4]
输出：2
解释：第一次操作中，选择 i = 2 和 j = 1 ，操作可以执行的原因是 2 * nums[2] <= nums[1] ，标记下标 2 和 1 。
没有其他更多可执行的操作，所以答案为 2 。
示例 2：

输入：nums = [9,2,5,4]
输出：4
解释：第一次操作中，选择 i = 3 和 j = 0 ，操作可以执行的原因是 2 * nums[3] <= nums[0] ，标记下标 3 和 0 。
第二次操作中，选择 i = 1 和 j = 2 ，操作可以执行的原因是 2 * nums[1] <= nums[2] ，标记下标 1 和 2 。
没有其他更多可执行的操作，所以答案为 4 。
示例 3：

输入：nums = [7,6,8]
输出：0
解释：没有任何可以执行的操作，所以答案为 0 。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int size = nums.size(), pairs = 0;

        sort(nums.begin(), nums.end());

        for (int i = (size + 1) / 2 - 1, j = size - 1; i >= 0; --j) {
            if (nums[j] != 0) {
                while (i >= 0 && nums[i] * 2 > nums[j]) {
                    --i;
                }

                if (i >= 0) {
                    ++pairs;
                    nums[i--] = 0;
                }
            }
        }

        return pairs * 2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 3,5,2,4 };
    check.checkInt(2, o.maxNumOfMarkedIndices(nums));

    nums = { 9,2,5,4 };
    check.checkInt(4, o.maxNumOfMarkedIndices(nums));

    nums = { 7,6,8 };
    check.checkInt(0, o.maxNumOfMarkedIndices(nums));

    nums = { 1 };
    check.checkInt(0, o.maxNumOfMarkedIndices(nums));

    nums = { 7,6,8,3,5,2,4,9,2,5,4,1,7,6,8,3,5,2,4,9,2,5,4,1,7,6,8,3,5,2,4,9,2,5,4,1,7,6,8,3,5,2,4,9,2,5,4,1 };
    check.checkInt(48, o.maxNumOfMarkedIndices(nums));

    nums = { 2,3,4,8 };
    check.checkInt(4, o.maxNumOfMarkedIndices(nums));

    nums = { 42,83,48,10,24,55,9,100,10,17,17,99,51,32,16,98,99,31,28,68,71,14,64,29,15,40 };
    check.checkInt(26, o.maxNumOfMarkedIndices(nums));
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
