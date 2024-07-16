/* 玩具套圈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
「力扣挑战赛」场地外，小力组织了一个套玩具的游戏。所有的玩具摆在平地上，toys[i] 以 [xi,yi,ri] 的形式记录了第 i 个玩具的坐标 (xi,yi) 和半径 ri。小扣试玩了一下，他扔了若干个半径均为 r 的圈，circles[j] 记录了第 j 个圈的坐标 (xj,yj)。套圈的规则如下：

若一个玩具被某个圈完整覆盖了（即玩具的任意部分均在圈内或者圈上），则该玩具被套中。
若一个玩具被多个圈同时套中，最终仅计算为套中一个玩具
请帮助小扣计算，他成功套中了多少玩具。

注意：

输入数据保证任意两个玩具的圆心不会重合，但玩具之间可能存在重叠。
示例 1：

输入：toys = [[3,3,1],[3,2,1]], circles = [[4,3]], r = 2

输出：1

解释： 如图所示，仅套中一个玩具image.png

示例 2：

输入：toys = [[1,3,2],[4,3,1],[7,1,2]], circles = [[1,0],[3,3]], r = 4

输出：2

解释： 如图所示，套中两个玩具image.png

提示：

1 <= toys.length <= 10^4
0 <= toys[i][0], toys[i][1] <= 10^9
1 <= circles.length <= 10^4
0 <= circles[i][0], circles[i][1] <= 10^9
1 <= toys[i][2], r <= 10
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int circleGame(vector<vector<int>>& toys, vector<vector<int>>& circles, int r) {
        unordered_set<long long> centers;
        int count = 0;

        for (auto& circle : circles) {
            centers.insert(((long long)circle[0] << 32) | circle[1]);
        }

        for (auto& toy : toys) {
            int x1 = toy[0], y1 = toy[1], r1 = toy[2];
            if (r1 > r) {
                continue;
            }

            int dr = r - r1, dr2 = dr * dr;
            for (int x2 = x1 - dr, find = 0; x2 <= x1 + dr && find == 0; ++x2) {
                for (int y2 = y1 - dr; y2 <= y1 + dr; ++y2) {
                    int dx = x2 - x1, dx2 = dx * dx, dy = y2 - y1, dy2 = dy * dy;
                    if (dx2 + dy2 <= dr2 && centers.count(((long long)x2 << 32) | y2) != 0) {
                        ++count;
                        find = 1;
                        break;
                    }
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> toys = { {3,3,1},{3,2,1} };
    vector<vector<int>> circles = { {4,3} };
    check.checkInt(1, o.circleGame(toys, circles, 2));

    toys = { {1,3,2},{4,3,1},{7,1,2} };
    circles = { {1,0},{3,3} };
    check.checkInt(2, o.circleGame(toys, circles, 4));

    toys = { {1,3,2},{4,3,1} };
    circles = { {1,0},{3,3},{0,0},{3,4} };
    check.checkInt(2, o.circleGame(toys, circles, 4));

    toys = { {3,4,5},{1,4,4},{4,4,1},{1,5,5} };
    circles = { {4,1},{4,2} };
    check.checkInt(1, o.circleGame(toys, circles, 6));
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
