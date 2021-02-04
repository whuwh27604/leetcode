/* 跳跃游戏 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:

假设你总是可以到达数组的最后一个位置。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int prev = -1, current = 0, next = 0, target = nums.size() - 1, jumps = 0;

        while (current < target) {
            for (int i = prev + 1; i <= current; ++i) {  // 贪心，每次找到最远能达到的地方
                next = max(next, i + nums[i]);
            }

            prev = current;
            current = next;
            ++jumps;
        }

        return jumps;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 2,3,1,1,4 };
    check.checkInt(2, o.jump(nums));

    nums = { 2 };
    check.checkInt(0, o.jump(nums));

    nums = { 4,3,1,1,2,5,4 };
    check.checkInt(2, o.jump(nums));
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
