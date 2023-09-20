/* 删除数对后的最小数组长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的 非递减 整数数组 nums 。

你可以执行以下操作任意次：

选择 两个 下标 i 和 j ，满足 i < j 且 nums[i] < nums[j] 。
将 nums 中下标在 i 和 j 处的元素删除。剩余元素按照原来的顺序组成新的数组，下标也重新从 0 开始编号。
请你返回一个整数，表示执行以上操作任意次后（可以执行 0 次），nums 数组的 最小 数组长度。



示例 1：

输入：nums = [1,3,4,9]
输出：0
解释：一开始，nums = [1, 3, 4, 9] 。
第一次操作，我们选择下标 0 和 1 ，满足 nums[0] < nums[1] <=> 1 < 3 。
删除下标 0 和 1 处的元素，nums 变成 [4, 9] 。
下一次操作，我们选择下标 0 和 1 ，满足 nums[0] < nums[1] <=> 4 < 9 。
删除下标 0 和 1 处的元素，nums 变成空数组 [] 。
所以，可以得到的最小数组长度为 0 。
示例 2：

输入：nums = [2,3,6,9]
输出：0
解释：一开始，nums = [2, 3, 6, 9] 。
第一次操作，我们选择下标 0 和 2 ，满足 nums[0] < nums[2] <=> 2 < 6 。
删除下标 0 和 2 处的元素，nums 变成 [3, 9] 。
下一次操作，我们选择下标 0 和 1 ，满足 nums[0] < nums[1] <=> 3 < 9 。
删除下标 0 和 1 处的元素，nums 变成空数组 [] 。
所以，可以得到的最小数组长度为 0 。
示例 3：

输入：nums = [1,1,2]
输出：1
解释：一开始，nums = [1, 1, 2] 。
第一次操作，我们选择下标 0 和 2 ，满足 nums[0] < nums[2] <=> 1 < 2 。
删除下标 0 和 2 处的元素，nums 变成 [1] 。
无法对数组再执行操作。
所以，可以得到的最小数组长度为 1 。


提示：

1 <= nums.length <= 105
1 <= nums[i] <= 109
nums 是 非递减 数组。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int size = nums.size(), freq = 0, maxFreq = 0, prev = 0;

        for (int i = 0; i < size; ++i) {
            if (nums[i] == prev) {
                ++freq;
            }
            else {
                maxFreq = max(maxFreq, freq);
                freq = 1;
                prev = nums[i];
            }
        }

        maxFreq = max(maxFreq, freq);

        if (maxFreq * 2 >= size) {
            return maxFreq * 2 - size;
        }

        return (size & 1);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,3,4,9 };
    check.checkInt(0, o.minLengthAfterRemovals(nums));

    nums = { 2,3,6,9 };
    check.checkInt(0, o.minLengthAfterRemovals(nums));

    nums = { 1,1,2 };
    check.checkInt(1, o.minLengthAfterRemovals(nums));

    nums = { 1,1,2,2,3,3 };
    check.checkInt(0, o.minLengthAfterRemovals(nums));

    nums = { 1,1,2,2,2,2,2,2 };
    check.checkInt(4, o.minLengthAfterRemovals(nums));

    nums = { 3 };
    check.checkInt(1, o.minLengthAfterRemovals(nums));
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
