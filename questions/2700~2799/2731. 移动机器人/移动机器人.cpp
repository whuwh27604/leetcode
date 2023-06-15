﻿/* 移动机器人.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一些机器人分布在一条无限长的数轴上，他们初始坐标用一个下标从 0 开始的整数数组 nums 表示。当你给机器人下达命令时，它们以每秒钟一单位的速度开始移动。

给你一个字符串 s ，每个字符按顺序分别表示每个机器人移动的方向。'L' 表示机器人往左或者数轴的负方向移动，'R' 表示机器人往右或者数轴的正方向移动。

当两个机器人相撞时，它们开始沿着原本相反的方向移动。

请你返回指令重复执行 d 秒后，所有机器人之间两两距离之和。由于答案可能很大，请你将答案对 109 + 7 取余后返回。

注意：

对于坐标在 i 和 j 的两个机器人，(i,j) 和 (j,i) 视为相同的坐标对。也就是说，机器人视为无差别的。
当机器人相撞时，它们 立即改变 它们的前进时间，这个过程不消耗任何时间。
当两个机器人在同一时刻占据相同的位置时，就会相撞。

例如，如果一个机器人位于位置 0 并往右移动，另一个机器人位于位置 2 并往左移动，下一秒，它们都将占据位置 1，并改变方向。再下一秒钟后，第一个机器人位于位置 0 并往左移动，而另一个机器人位于位置 2 并往右移动。

例如，如果一个机器人位于位置 0 并往右移动，另一个机器人位于位置 1 并往左移动，下一秒，第一个机器人位于位置 0 并往左行驶，而另一个机器人位于位置 1 并往右移动。



示例 1：

输入：nums = [-2,0,2], s = "RLL", d = 3
输出：8
解释：
1 秒后，机器人的位置为 [-1,-1,1] 。现在下标为 0 的机器人开始往左移动，下标为 1 的机器人开始往右移动。
2 秒后，机器人的位置为 [-2,0,0] 。现在下标为 1 的机器人开始往左移动，下标为 2 的机器人开始往右移动。
3 秒后，机器人的位置为 [-3,-1,1] 。
下标为 0 和 1 的机器人之间距离为 abs(-3 - (-1)) = 2 。
下标为 0 和 2 的机器人之间的距离为 abs(-3 - 1) = 4 。
下标为 1 和 2 的机器人之间的距离为 abs(-1 - 1) = 2 。
所有机器人对之间的总距离为 2 + 4 + 2 = 8 。
示例 2：

输入：nums = [1,0], s = "RL", d = 2
输出：5
解释：
1 秒后，机器人的位置为 [2,-1] 。
2 秒后，机器人的位置为 [3,-2] 。
两个机器人的距离为 abs(-2 - 3) = 5 。


提示：

2 <= nums.length <= 105
-2 * 109 <= nums[i] <= 2 * 109
0 <= d <= 109
nums.length == s.length
s 只包含 'L' 和 'R' 。
nums[i] 互不相同。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int size = nums.size(), mod = 1000000007;
        long long sum = 0, totalSum = 0;
        vector<long long> position(size);

        for (int i = 0; i < size; ++i) {  // 关键的关键是要意识到，发生碰撞和直接穿越过对方的效果是一样一样的
            if (s[i] == 'R') {
                position[i] = (long long)nums[i] + d;
            }
            else {
                position[i] = (long long)nums[i] - d;
            }
        }

        sort(position.begin(), position.end());

        for (int i = 1; i < size; ++i) {
            totalSum = (totalSum + (position[i] - position[0]) * i - sum) % mod;
            sum += (position[i] - position[0]);
        }

        return (int)totalSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { -2,0,2 };
    check.checkInt(8, o.sumDistance(nums, "RLL", 3));

    nums = { 1,0 };
    check.checkInt(5, o.sumDistance(nums, "RL", 2));
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
