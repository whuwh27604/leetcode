/* 网络信号最好的坐标.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 towers 和一个整数 radius ，数组中包含一些网络信号塔，其中 towers[i] = [xi, yi, qi] 表示第 i 个网络信号塔的坐标是 (xi, yi) 且信号强度参数为 qi 。所有坐标都是在  X-Y 坐标系内的 整数 坐标。两个坐标之间的距离用 欧几里得距离 计算。

整数 radius 表示一个塔 能到达 的 最远距离 。如果一个坐标跟塔的距离在 radius 以内，那么该塔的信号可以到达该坐标。在这个范围以外信号会很微弱，所以 radius 以外的距离该塔是 不能到达的 。

如果第 i 个塔能到达 (x, y) ，那么该塔在此处的信号为 ⌊qi / (1 + d)⌋ ，其中 d 是塔跟此坐标的距离。一个坐标的 网络信号 是所有 能到达 该坐标的塔的信号强度之和。

请你返回 网络信号 最大的整数坐标点。如果有多个坐标网络信号一样大，请你返回字典序最小的一个坐标。

注意：

坐标 (x1, y1) 字典序比另一个坐标 (x2, y2) 小：要么 x1 < x2 ，要么 x1 == x2 且 y1 < y2 。
⌊val⌋ 表示小于等于 val 的最大整数（向下取整函数）。
 

示例 1：


输入：towers = [[1,2,5],[2,1,7],[3,1,9]], radius = 2
输出：[2,1]
解释：
坐标 (2, 1) 信号强度之和为 13
- 塔 (2, 1) 强度参数为 7 ，在该点强度为 ⌊7 / (1 + sqrt(0)⌋ = ⌊7⌋ = 7
- 塔 (1, 2) 强度参数为 5 ，在该点强度为 ⌊5 / (1 + sqrt(2)⌋ = ⌊2.07⌋ = 2
- 塔 (3, 1) 强度参数为 9 ，在该点强度为 ⌊9 / (1 + sqrt(1)⌋ = ⌊4.5⌋ = 4
没有别的坐标有更大的信号强度。
示例 2：

输入：towers = [[23,11,21]], radius = 9
输出：[23,11]
示例 3：

输入：towers = [[1,2,13],[2,1,7],[0,1,9]], radius = 2
输出：[1,2]
示例 4：

输入：towers = [[2,1,9],[0,1,9]], radius = 2
输出：[0,1]
解释：坐标 (0, 1) 和坐标 (2, 1) 都是强度最大的位置，但是 (0, 1) 字典序更小。
 

提示：

1 <= towers.length <= 50
towers[i].length == 3
0 <= xi, yi, qi <= 50
1 <= radius <= 50

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coordinate-with-maximum-network-quality
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        if (towers.size() == 1 && towers[0][2] == 0) {
            return { 0,0 };
        }

        // 考虑一个正方形，信号最强的点在中心，而不是4个角上。所以不能只遍历tower的位置。
        int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN, maxNetworkQuality = INT_MIN;
        vector<int> maxNQCoordinate;

        getBorder(towers, minX, minY, maxX, maxY);

        for (int x = minX; x <= maxX; ++x) {
            for (int y = minY; y <= maxY; ++y) {
                int networkQuality = calcNetWorkQuality(x, y, towers, radius);

                if (networkQuality > maxNetworkQuality) {
                    maxNetworkQuality = networkQuality;
                    maxNQCoordinate = { x,y };
                }
                else if (networkQuality == maxNetworkQuality) {
                    if (x < maxNQCoordinate[0] || (x == maxNQCoordinate[0] && y < maxNQCoordinate[1])) {
                        maxNQCoordinate = { x,y };
                    }
                }
            }
        }

        return maxNQCoordinate;
    }

    void getBorder(vector<vector<int>>& towers, int& minX, int& minY, int& maxX, int& maxY) {
        for (auto& tower : towers) {
            minX = min(minX, tower[0]);
            minY = min(minY, tower[1]);
            maxX = max(maxX, tower[0]);
            maxY = max(maxY, tower[1]);
        }
    }

    int calcNetWorkQuality(int x, int y, vector<vector<int>>& towers, int radius) {
        double distance;
        int quality = 0;

        for (auto& tower : towers) {
            distance = sqrt((tower[0] - x) * (tower[0] - x) + (tower[1] - y) * (tower[1] - y));

            if (distance <= radius) {
                quality += (int)((double)tower[2] / (distance + 1));
            }
        }

        return quality;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> towers = { {1,2,5},{2,1,7},{3,1,9} };
    vector<int> actual = o.bestCoordinate(towers, 2);
    vector<int> expected = { 2,1 };
    check.checkIntVector(expected, actual);

    towers = { {23,11,21} };
    actual = o.bestCoordinate(towers, 9);
    expected = { 23,11 };
    check.checkIntVector(expected, actual);

    towers = { {1,2,13},{2,1,7},{0,1,9} };
    actual = o.bestCoordinate(towers, 2);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    towers = { {2,1,9},{0,1,9} };
    actual = o.bestCoordinate(towers, 2);
    expected = { 0,1 };
    check.checkIntVector(expected, actual);

    towers = { {0,1,2},{2,1,2},{1,0,2},{1,2,2} };
    actual = o.bestCoordinate(towers, 1);
    expected = { 1,1 };
    check.checkIntVector(expected, actual);

    towers = { {0,0,2},{2,0,2},{0,2,2},{2,2,2} };
    actual = o.bestCoordinate(towers, 1);
    expected = { 0,0 };
    check.checkIntVector(expected, actual);

    towers = { {42,0,0} };
    actual = o.bestCoordinate(towers, 7);
    expected = { 0,0 };
    check.checkIntVector(expected, actual);

    towers = { {42,0,1} };
    actual = o.bestCoordinate(towers, 7);
    expected = { 42,0 };
    check.checkIntVector(expected, actual);

    towers = { {44,31,4},{47,27,27},{7,13,0},{13,21,20},{50,34,18},{47,44,28} };
    actual = o.bestCoordinate(towers, 13);
    expected = { 47,27 };
    check.checkIntVector(expected, actual);
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
