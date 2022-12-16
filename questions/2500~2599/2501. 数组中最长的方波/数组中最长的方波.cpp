/* 数组中最长的方波.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 。如果 nums 的子序列满足下述条件，则认为该子序列是一个 方波 ：

子序列的长度至少为 2 ，并且
将子序列从小到大排序 之后 ，除第一个元素外，每个元素都是前一个元素的 平方 。
返回 nums 中 最长方波 的长度，如果不存在 方波 则返回 -1 。

子序列 也是一个数组，可以由另一个数组删除一些或不删除元素且不改变剩余元素的顺序得到。



示例 1 ：

输入：nums = [4,3,6,16,8,2]
输出：3
解释：选出子序列 [4,16,2] 。排序后，得到 [2,4,16] 。
- 4 = 2 * 2.
- 16 = 4 * 4.
因此，[4,16,2] 是一个方波.
可以证明长度为 4 的子序列都不是方波。
示例 2 ：

输入：nums = [2,3,5,6,7]
输出：-1
解释：nums 不存在方波，所以返回 -1 。


提示：

2 <= nums.length <= 105
2 <= nums[i] <= 105
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end()), maxStreak = 1;
        vector<bool> exist(maxNum + 1, false);
        vector<int> lens(maxNum + 1, 1);

        for (int num : nums) {
            exist[num] = true;
        }

        for (int num = (int)sqrt(maxNum); num > 0; --num) {
            if (exist[num] && exist[num * num]) {
                lens[num] = lens[num * num] + 1;
            }

            maxStreak = max(maxStreak, lens[num]);
        }

        return maxStreak == 1 ? -1 : maxStreak;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 4,3,6,16,8,2 };
    check.checkInt(3, o.longestSquareStreak(nums));

    nums = { 2,3,5,6,7 };
    check.checkInt(-1, o.longestSquareStreak(nums));

    nums = { 18532,92682 };
    check.checkInt(-1, o.longestSquareStreak(nums));

    nums = { 4,16,256,65536 };
    check.checkInt(4, o.longestSquareStreak(nums));
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
