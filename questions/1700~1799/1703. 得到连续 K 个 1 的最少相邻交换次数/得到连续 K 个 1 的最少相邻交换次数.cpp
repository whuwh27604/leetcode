/* 得到连续 K 个 1 的最少相邻交换次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 nums 和一个整数 k 。 nums 仅包含 0 和 1 。每一次移动，你可以选择 相邻 两个数字并将它们交换。

请你返回使 nums 中包含 k 个 连续 1 的 最少 交换次数。

 

示例 1：

输入：nums = [1,0,0,1,0,1], k = 2
输出：1
解释：在第一次操作时，nums 可以变成 [1,0,0,0,1,1] 得到连续两个 1 。
示例 2：

输入：nums = [1,0,0,0,0,0,1,1], k = 3
输出：5
解释：通过 5 次操作，最左边的 1 可以移到右边直到 nums 变为 [0,0,0,0,0,1,1,1] 。
示例 3：

输入：nums = [1,1,0,1], k = 2
输出：0
解释：nums 已经有连续 2 个 1 了。
 

提示：

1 <= nums.length <= 105
nums[i] 要么是 0 ，要么是 1 。
1 <= k <= sum(nums)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        if (k == 1) {
            return 0;
        }

        int i, left, right, size = nums.size(), half = (k + 1) / 2, count = 0, moves = 0;

        for (i = 0; i < size; ++i) {  // 找到第一个中心线
            count += nums[i];

            if (count == half) {
                break;
            }
        }

        for (left = i; left >= 0; --left) {  // 找到左边界
            if (nums[left] == 1) {
                moves += (i - (half - count) - left);
                
                if (--count == 0) {
                    break;
                }
            }
        }

        for (count = half, right = i + 1; right < size; ++right) {  // 找到右边界
            if (nums[right] == 1) {
                moves += (right - (i + count - half + 1));

                if (++count == k) {
                    break;
                }
            }
        }

        int leastMoves = moves;

        for (++i; i < size; ++i) {  // 往右滑动中心线
            if (nums[i] == 0) {
                moves += half;  // 左边一半要全部右移一格
                moves -= (k - half);  // 右边一半全部少移动一格
            }
            else {
                moves -= (i - half - left);  // 最左边一个不再需要，减去它的移动次数
                for (left += 1; nums[left] == 0; ++left) {}
                for (right += 1; right < size && nums[right] == 0; ++right) {}  // 右边需要再补齐一个

                if (right == size) {
                    break;
                }

                moves += (right - (i + (k - half)));
                leastMoves = min(leastMoves, moves);
            }
        }

        return leastMoves;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,0,0,1,0,1 };
    check.checkInt(1, o.minMoves(nums, 2));

    nums = { 1,0,0,0,0,0,1,1 };
    check.checkInt(5, o.minMoves(nums, 3));

    nums = { 1,1,0,1 };
    check.checkInt(0, o.minMoves(nums, 2));

    nums = { 0,0,1,0,0 };
    check.checkInt(0, o.minMoves(nums, 1));

    nums = { 1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1 };
    check.checkInt(10, o.minMoves(nums, 4));

    nums = { 1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1 };
    check.checkInt(40, o.minMoves(nums, 8));

    nums = { 1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1 };
    check.checkInt(60, o.minMoves(nums, 10));

    nums = { 1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1 };
    check.checkInt(75, o.minMoves(nums, 11));

    nums = { 1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,1,1 };
    check.checkInt(225, o.minMoves(nums, 19));
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
