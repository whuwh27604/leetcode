/* 判断矩形的两个角落是否可达.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个正整数 X 和 Y 和一个二维整数数组 circles ，其中 circles[i] = [xi, yi, ri] 表示一个圆心在 (xi, yi) 半径为 ri 的圆。

坐标平面内有一个左下角在原点，右上角在 (X, Y) 的矩形。你需要判断是否存在一条从左下角到右上角的路径满足：路径 完全 在矩形内部，不会 触碰或者经过 任何 圆的内部和边界，同时 只 在起点和终点接触到矩形。

如果存在这样的路径，请你返回 true ，否则返回 false 。



示例 1：

输入：X = 3, Y = 4, circles = [[2,1,1]]

输出：true

解释：



黑色曲线表示一条从 (0, 0) 到 (3, 4) 的路径。

示例 2：

输入：X = 3, Y = 3, circles = [[1,1,2]]

输出：false

解释：



不存在从 (0, 0) 到 (3, 3) 的路径。

示例 3：

输入：X = 3, Y = 3, circles = [[2,1,1],[1,2,1]]

输出：false

解释：



不存在从 (0, 0) 到 (3, 3) 的路径。



提示：

3 <= X, Y <= 109
1 <= circles.length <= 1000
circles[i].length == 3
1 <= xi, yi, ri <= 109
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        int n = (int)circles.size();
        vector<vector<int>> adjs(n + 2);
        vector<bool> visited(n + 2, false);

        getAdjs(X, Y, n, circles, adjs);

        return !DFS(n, n + 1, adjs, visited);
    }

    void getAdjs(int X, int Y, int n, vector<vector<int>>& circles, vector<vector<int>>& adjs) {
        for (int i = 0; i < n; ++i) {
            int x1 = circles[i][0], y1 = circles[i][1], r1 = circles[i][2];
            if (isAdjLeft(x1, y1, r1, Y) || isAdjUp(x1, y1, r1, X, Y)) {  // 和左上相交
                adjs[i].push_back(n);
                adjs[n].push_back(i);
            }
            if (isAdjRight(x1, y1, r1, X, Y) || isAdjDown(x1, y1, r1, X)) {  // 和右下相交
                adjs[i].push_back(n + 1);
                adjs[n + 1].push_back(i);
            }

            for (int j = i + 1; j < n; ++j) {
                long long x2 = circles[j][0], y2 = circles[j][1], r2 = circles[j][2];
                if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= (r2 + r1) * (r2 + r1)) {  // 两圆有交集
                    // 点x = ((x1 * r2) + (x2 * r1)) / (r1 + r2), y = ((y1 * r2) + (y2 * r1)) / (r1 + r2)一定在交集内
                    long long x = (x1 * r2) + (x2 * r1), y = (y1 * r2) + (y2 * r1), r = r1 + r2;
                    if (x >= 0 && x <= X * r && y >= 0 && y <= Y * r) {  // 点[x, y]在矩形内部
                        adjs[i].push_back(j);
                        adjs[j].push_back(i);
                    }
                }
            }
        }
    }

    bool isAdjLeft(int x, int y, int r, int Y) {
        return ((y >= Y && isInCircle(x, y, r, 0, Y)) || (y <= Y && x <= r));
    }

    bool isAdjRight(int x, int y, int r, int X, int Y) {
        return ((y >= Y && isInCircle(x, y, r, X, Y)) || (y <= Y && abs(X - x) <= r));
    }

    bool isAdjUp(int x, int y, int r, int X, int Y) {
        return ((x >= X && isInCircle(x, y, r, X, Y)) || (x <= X && abs(Y - y) <= r));
    }

    bool isAdjDown(int x, int y, int r, int X) {
        return ((x >= X && isInCircle(x, y, r, X, 0)) || (x <= X && y <= r));
    }

    bool isInCircle(int x, int y, int r, int px, int py) {  // 点[px, py]是否在circle[x, y, r]内部
        return ((long long)x - px) * ((long long)x - px) + ((long long)y - py) * ((long long)y - py) <= (long long)r * r;
    }

    bool DFS(int node, int target, vector<vector<int>>& adjs, vector<bool>& visited) {
        if (node == target) {
            return true;
        }

        visited[node] = true;

        for (int next : adjs[node]) {
            if (!visited[next] && DFS(next, target, adjs, visited)) {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> circles = { {6,7,5} };
    check.checkBool(false, o.canReachCorner(3, 3, circles));

    circles = { {1,1,2} };
    check.checkBool(false, o.canReachCorner(3, 3, circles));

    circles = { {2,1,1},{1,2,1} };
    check.checkBool(false, o.canReachCorner(3, 3, circles));

    circles = { {4,4,100} };
    check.checkBool(false, o.canReachCorner(3, 3, circles));

    circles = { {2,1,1} };
    check.checkBool(true, o.canReachCorner(3, 4, circles));

    circles = { {2,1000,997},{1000,2,997} };
    check.checkBool(true, o.canReachCorner(3, 3, circles));

    circles = { {2,4,1},{4,4,1},{4,2,1} };
    check.checkBool(true, o.canReachCorner(3, 3, circles));
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
