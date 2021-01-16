/* 可以到达的最远建筑.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数数组 heights ，表示建筑物的高度。另有一些砖块 bricks 和梯子 ladders 。

你从建筑物 0 开始旅程，不断向后面的建筑物移动，期间可能会用到砖块或梯子。

当从建筑物 i 移动到建筑物 i+1（下标 从 0 开始 ）时：

如果当前建筑物的高度 大于或等于 下一建筑物的高度，则不需要梯子或砖块
如果当前建筑的高度 小于 下一个建筑的高度，您可以使用 一架梯子 或 (h[i+1] - h[i]) 个砖块
如果以最佳方式使用给定的梯子和砖块，返回你可以到达的最远建筑物的下标（下标 从 0 开始 ）。
 

示例 1：


输入：heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
输出：4
解释：从建筑物 0 出发，你可以按此方案完成旅程：
- 不使用砖块或梯子到达建筑物 1 ，因为 4 >= 2
- 使用 5 个砖块到达建筑物 2 。你必须使用砖块或梯子，因为 2 < 7
- 不使用砖块或梯子到达建筑物 3 ，因为 7 >= 6
- 使用唯一的梯子到达建筑物 4 。你必须使用砖块或梯子，因为 6 < 9
无法越过建筑物 4 ，因为没有更多砖块或梯子。
示例 2：

输入：heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
输出：7
示例 3：

输入：heights = [14,3,19,3], bricks = 17, ladders = 0
输出：3
 

提示：

1 <= heights.length <= 105
1 <= heights[i] <= 106
0 <= bricks <= 109
0 <= ladders <= heights.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/furthest-building-you-can-reach
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        multiset<int> greatestKths;
        int i, size = heights.size(), bricksUsed = 0;

        for (i = 1; i < size; ++i) {
            if (heights[i] <= heights[i - 1]) {
                continue;
            }

            greatestKths.insert(heights[i] - heights[i - 1]);
            
            if ((int)greatestKths.size() > ladders) {
                bricksUsed += *greatestKths.begin();

                if (bricksUsed > bricks) {
                    break;
                }

                greatestKths.erase(greatestKths.begin());
            }
        }

        return i - 1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> heights = { 4,2,7,6,9,14,12 };
    check.checkInt(4, o.furthestBuilding(heights, 5, 1));

    heights = { 4,12,2,7,3,18,20,3,19 };
    check.checkInt(7, o.furthestBuilding(heights, 10, 2));

    heights = { 4,12,2,7,3,18,20,3,19 };
    check.checkInt(8, o.furthestBuilding(heights, 46, 0));

    heights = { 14,3,19,3 };
    check.checkInt(3, o.furthestBuilding(heights, 17, 0));

    heights = { 2,7,8,9,10,11 };
    check.checkInt(5, o.furthestBuilding(heights, 5, 1));

    heights = { 1,5,6,7,8 };
    check.checkInt(4, o.furthestBuilding(heights, 4, 1));

    heights = { 1,5,1,2,3,4 };
    check.checkInt(5, o.furthestBuilding(heights, 4, 1));

    heights = { 1 };
    check.checkInt(0, o.furthestBuilding(heights, 0, 0));
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
