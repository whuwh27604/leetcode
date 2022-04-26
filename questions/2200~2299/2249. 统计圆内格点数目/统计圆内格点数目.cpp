// 统计圆内格点数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int minX = INT_MAX, maxX = INT_MIN, minY = INT_MAX, maxY = INT_MIN, points = 0;
        getMaxXY(circles, minX, maxX, minY, maxY);

        for (int y = minY; y <= maxY; ++y) {
            vector<int> diffs(maxX + 2, 0);

            for (auto& circle : circles) {
                if (y >= circle[1] - circle[2] && y <= circle[1] + circle[2]) {
                    pair<int, int> leftRightX = getLeftRightX(circle[0], circle[1], circle[2], y);
                    diffs[leftRightX.first] += 1;
                    diffs[leftRightX.second + 1] -= 1;
                }
            }

            for (int x = minX; x <= maxX; ++x) {
                if (x != 0) {
                    diffs[x] += diffs[x - 1];
                }

                if (diffs[x] > 0) {
                    ++points;
                }
            }
        }

        return points;
    }

    void getMaxXY(vector<vector<int>>& circles, int& minX, int& maxX, int& minY, int& maxY) {
        for (auto& circle : circles) {
            minX = min(minX, circle[0] - circle[2]);
            maxX = max(maxX, circle[0] + circle[2]);
            minY = min(minY, circle[1] - circle[2]);
            maxY = max(maxY, circle[1] + circle[2]);
        }
    }

    pair<int, int> getLeftRightX(int centerX, int centerY, int radius, int y) {
        int deltaX = (int)sqrt(radius * radius - (centerY - y) * (centerY - y));

        return { centerX - deltaX, centerX + deltaX };
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> circles = { {2,2,1} };
    check.checkInt(5, o.countLatticePoints(circles));

    circles = { {2,2,2},{3,4,1} };
    check.checkInt(16, o.countLatticePoints(circles));

    circles = { {1,4,1},{9,4,4},{8,4,4},{1,10,1},{5,6,2},{5,5,5} };
    check.checkInt(109, o.countLatticePoints(circles));

    circles = { {8,9,6},{9,8,4},{4,1,1},{8,5,1},{7,1,1},{6,7,5},{7,1,1},{7,1,1},{5,5,3} };
    check.checkInt(141, o.countLatticePoints(circles));
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
