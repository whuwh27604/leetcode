/* 玩筹码.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
数轴上放置了一些筹码，每个筹码的位置存在数组 chips 当中。

你可以对 任何筹码 执行下面两种操作之一（不限操作次数，0 次也可以）：

将第 i 个筹码向左或者右移动 2 个单位，代价为 0。
将第 i 个筹码向左或者右移动 1 个单位，代价为 1。
最开始的时候，同一位置上也可能放着两个或者更多的筹码。

返回将所有筹码移动到同一位置（任意位置）上所需要的最小代价。

 

示例 1：

输入：chips = [1,2,3]
输出：1
解释：第二个筹码移动到位置三的代价是 1，第一个筹码移动到位置三的代价是 0，总代价为 1。
示例 2：

输入：chips = [2,2,2,3,3]
输出：2
解释：第四和第五个筹码移动到位置二的代价都是 1，所以最小总代价为 2。
 

提示：

1 <= chips.length <= 100
1 <= chips[i] <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/play-with-chips
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int i, even = 0, len = chips.size();

        for (i = 0; i < len; i++) {
            if ((chips[i] % 2) == 0) {
                even++;
            }
        }

        return min(even, len - even);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> chips = { 1,2,3 };
    check.checkInt(1, o.minCostToMoveChips(chips));

    chips = { 2,2,2,3,3 };
    check.checkInt(2, o.minCostToMoveChips(chips));
    
    chips = { 33333333 };
    check.checkInt(0, o.minCostToMoveChips(chips));

    chips = { 33333334 };
    check.checkInt(0, o.minCostToMoveChips(chips));

    chips = { 2,4,6,3,5,7,9 };
    check.checkInt(3, o.minCostToMoveChips(chips));
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
