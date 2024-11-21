/* 最强祝福力场.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
小扣在探索丛林的过程中，无意间发现了传说中“落寞的黄金之都”。而在这片建筑废墟的地带中，小扣使用探测仪监测到了存在某种带有「祝福」效果的力场。 经过不断的勘测记录，小扣将所有力场的分布都记录了下来。forceField[i] = [x,y,side] 表示第 i 片力场将覆盖以坐标 (x,y) 为中心，边长为 side 的正方形区域。

若任意一点的 力场强度 等于覆盖该点的力场数量，请求出在这片地带中 力场强度 最强处的 力场强度。

注意：

力场范围的边缘同样被力场覆盖。
示例 1：

输入： forceField = [[0,0,1],[1,0,1]]

输出：2

解释：如图所示，（0.5, 0) 处力场强度最强为 2， （0.5，-0.5）处力场强度同样是 2。image.png

示例 2：

输入： forceField = [[4,4,6],[7,5,3],[1,6,2],[5,6,3]]

输出：3

解释：如下图所示， forceField[0]、forceField[1]、forceField[3] 重叠的区域力场强度最大，返回 3image.png

提示：

1 <= forceField.length <= 100
forceField[i].length == 3
0 <= forceField[i][0], forceField[i][1] <= 10^9
1 <= forceField[i][2] <= 10^9
*/

#include <iostream>
#include <set>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

typedef long long LL;

class Square {
public:
    LL x1;
    LL x2;
    LL y1;
    LL y2;

    Square() : x1(0), x2(0), y1(0), y2(0) {}
    Square(LL a, LL b, LL c, LL d) : x1(a), x2(b), y1(c), y2(d) {}
};

class Solution {
public:
    int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {
        vector<Square> squares;
        set<LL> xs, ys;
        unordered_map<LL, int> xIndices, yIndices;

        getSquare(forceField, squares, xs, ys);
        getIndex(xs, xIndices);
        getIndex(ys, yIndices);

        int n = (int)xs.size(), m = (int)ys.size(), maxBlessing = 0;
        vector<vector<int>> diff(n + 2, vector<int>(m + 2, 0));

        for (Square& square : squares) {
            int x1 = xIndices[square.x1], x2 = xIndices[square.x2], y1 = yIndices[square.y1], y2 = yIndices[square.y2];
            ++diff[x1 + 1][y1 + 1];
            ++diff[x2 + 2][y2 + 2];
            --diff[x2 + 2][y1 + 1];
            --diff[x1 + 1][y2 + 2];
        }

        for (int x = 1; x <= n; ++x) {
            for (int y = 1; y <= m; ++y) {
                diff[x][y] += diff[x - 1][y] + diff[x][y - 1] - diff[x - 1][y - 1];
                maxBlessing = max(maxBlessing, diff[x][y]);
            }
        }

        return maxBlessing;
    }

    void getSquare(vector<vector<int>>& forceField, vector<Square>& squares, set<LL>& xs, set<LL>& ys) {
        for (auto& field : forceField) {
            LL x = field[0], y = field[1], side = field[2];
            LL x1 = x * 2 - side, x2 = x * 2 + side, y1 = y * 2 - side, y2 = y * 2 + side;
            squares.push_back(Square(x1, x2, y1, y2));
            xs.insert(x1);
            xs.insert(x2);
            ys.insert(y1);
            ys.insert(y2);
        }
    }

    void getIndex(set<LL>& xs, unordered_map<LL, int>& indices) {
        int index = 0;

        for (LL x : xs) {
            indices[x] = index++;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> forceField = { {0,0,1},{1,0,1} };
    check.checkInt(2, o.fieldOfGreatestBlessing(forceField));

    forceField = { {4,4,6},{7,5,3},{1,6,2},{5,6,3} };
    check.checkInt(3, o.fieldOfGreatestBlessing(forceField));

    int n = 100;
    forceField = vector<vector<int>>(n, { 0,0,0 });
    for (int i = 0; i < n; ++i) {
        forceField[i][2] = n - i;
    }
    check.checkInt(n, o.fieldOfGreatestBlessing(forceField));
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
