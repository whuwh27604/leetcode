/* 判断是否可以赢得数字游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 正整数 数组 nums。

小红和小明正在玩游戏。在游戏中，小红可以从 nums 中选择所有个位数 或 所有两位数，剩余的数字归小明所有。如果小红所选数字之和 严格大于 小明的数字之和，则小红获胜。

如果小红能赢得这场游戏，返回 true；否则，返回 false。



示例 1：

输入：nums = [1,2,3,4,10]

输出：false

解释：

小红不管选个位数还是两位数都无法赢得比赛。

示例 2：

输入：nums = [1,2,3,4,5,14]

输出：true

解释：

小红选择个位数可以赢得比赛，所选数字之和为 15。

示例 3：

输入：nums = [5,5,5,25]

输出：true

解释：

小红选择两位数可以赢得比赛，所选数字之和为 25。



提示：

1 <= nums.length <= 100
1 <= nums[i] <= 99
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum1 = 0, sum2 = 0;

        for (int num : nums) {
            if (num < 10) {
                sum1 += num;
            }
            else {
                sum2 += num;
            }
        }

        return sum1 != sum2;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 1,2,3,4,10 };
    check.checkBool(false, o.canAliceWin(nums));

    nums = { 1,2,3,4,5,14 };
    check.checkBool(true, o.canAliceWin(nums));

    nums = { 5,5,5,25 };
    check.checkBool(true, o.canAliceWin(nums));
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
