/* 执行操作后不同元素的最大数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个整数 k。

你可以对数组中的每个元素 最多 执行 一次 以下操作：

将一个在范围 [-k, k] 内的整数加到该元素上。
返回执行这些操作后，nums 中可能拥有的不同元素的 最大 数量。



示例 1：

输入： nums = [1,2,2,3,3,4], k = 2

输出： 6

解释：

对前四个元素执行操作，nums 变为 [-1, 0, 1, 2, 3, 4]，可以获得 6 个不同的元素。

示例 2：

输入： nums = [4,4,4,4], k = 1

输出： 3

解释：

对 nums[0] 加 -1，以及对 nums[1] 加 1，nums 变为 [3, 5, 4, 4]，可以获得 3 个不同的元素。



提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
0 <= k <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  // 排序后贪心，第一个数安排最小的num - k，接下来每个数尽可能安排可选的最小的不同数

        int size = (int)nums.size(), wanted = nums[0] - k + 1, distinct = 1;

        for (int i = 1; i < size; ++i) {
            int num = nums[i];
            if (num - k >= wanted) {  // num - k比wanted还大，那么当前只能安排num - k，下一个want为num - k + 1
                ++distinct;
                wanted = num - k + 1;
            }
            else if (num + k >= wanted) {  // num - k比wanted小，但num + k比wanted大，那么当前安排wanted，下一个wanted加1
                ++distinct;
                ++wanted;
            }
            else {
                // num + k比wanted小，那么只能安排一个重复的数了，wanted不变
            }
        }

        return distinct;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,2,3,3,4 };
    check.checkInt(6, o.maxDistinctElements(nums, 2));

    nums = { 4,4,4,4 };
    check.checkInt(3, o.maxDistinctElements(nums, 1));
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
