/* 逃离大迷宫.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在一个 106 x 106 的网格中，每个网格上方格的坐标为 (x, y) 。

现在从源方格 source = [sx, sy] 开始出发，意图赶往目标方格 target = [tx, ty] 。数组 blocked 是封锁的方格列表，其中每个 blocked[i] = [xi, yi] 表示坐标为 (xi, yi) 的方格是禁止通行的。

每次移动，都可以走到网格中在四个方向上相邻的方格，只要该方格 不 在给出的封锁列表 blocked 上。同时，不允许走出网格。

只有在可以通过一系列的移动从源方格 source 到达目标方格 target 时才返回 true。否则，返回 false。

 

示例 1：

输入：blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
输出：false
解释：
从源方格无法到达目标方格，因为我们无法在网格中移动。
无法向北或者向东移动是因为方格禁止通行。
无法向南或者向西移动是因为不能走出网格。
示例 2：

输入：blocked = [], source = [0,0], target = [999999,999999]
输出：true
解释：
因为没有方格被封锁，所以一定可以到达目标方格。
 

提示：

0 <= blocked.length <= 200
blocked[i].length == 2
0 <= xi, yi < 106
source.length == target.length == 2
0 <= sx, sy, tx, ty < 106
source != target
题目数据保证 source 和 target 不在封锁列表内

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/escape-a-large-maze
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        int size = blocked.size(), maxPoints = size * (size - 1) / 2;  // size个障碍物最多可以围住maxPoints个点
        if (size < 2) {
            return true;  // 少于两个block，是不可能围住一个点的
        }

        unordered_set<long long> blockedPoints;
        getBlockedPoints(blocked, blockedPoints);

        return BFS(source, target, maxPoints, blockedPoints) && BFS(target, source, maxPoints, blockedPoints);
    }

    void getBlockedPoints(vector<vector<int>>& blocked, unordered_set<long long>& blockedPoints) {
        for (auto& point : blocked) {
            blockedPoints.insert(((long long)point[0] << 32) | point[1]);
        }
    }

    bool BFS(vector<int>& source, vector<int>& target, int maxPoints, unordered_set<long long>& blockedPoints) {
        int count = 1;
        long long size = 1000000, dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        long long sourcePoint = ((long long)source[0] << 32) | source[1], targetPoint = ((long long)target[0] << 32) | target[1];
        queue<long long> points;
        unordered_set<long long> visited;

        points.push(sourcePoint);
        visited.insert(sourcePoint);

        while (!points.empty()) {
            long long r = points.front() >> 32, c = points.front() & 0xffffffff;
            points.pop();

            for (int i = 0; i < 4; ++i) {
                long long nr = r + dr[i], nc = c + dc[i];
                if (nr < 0 || nr >= size || nc < 0 || nc >= size) {
                    continue;
                }

                long long npoint = (nr << 32) | nc;
                if (npoint == targetPoint) {
                    return true;
                }

                if (visited.count(npoint) == 0 && blockedPoints.count(npoint) == 0) {
                    if (++count > maxPoints) {
                        return true;
                    }

                    points.push(npoint);
                    visited.insert(npoint);
                }
            }
        }

        return false;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> blocked = { {0,1},{1,0} };
    vector<int> source = { 0,0 };
    vector<int> target = { 0,2 };
    check.checkBool(false, o.isEscapePossible(blocked, source, target));

    blocked = {};
    source = { 0,0 };
    target = { 999999,999999 };
    check.checkBool(true, o.isEscapePossible(blocked, source, target));

    blocked = {};
    source = { 0,0 };
    target = { 999999,999999 };
    check.checkBool(true, o.isEscapePossible(blocked, source, target));

    blocked = { {0,5},{1,4},{2,3},{3,2},{4,1},{5,0} };
    source = { 0,0 };
    target = { 999999,999999 };
    check.checkBool(false, o.isEscapePossible(blocked, source, target));

    blocked = { {0,5},{1,4},{2,3},{3,2},{4,1} };
    source = { 0,0 };
    target = { 999999,999999 };
    check.checkBool(true, o.isEscapePossible(blocked, source, target));
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
