/* 最长上升路径的长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的二维整数数组 coordinates 和一个整数 k ，其中 0 <= k < n 。

coordinates[i] = [xi, yi] 表示二维平面里一个点 (xi, yi) 。

如果一个点序列 (x1, y1), (x2, y2), (x3, y3), ..., (xm, ym) 满足以下条件，那么我们称它是一个长度为 m 的 上升序列 ：

对于所有满足 1 <= i < m 的 i 都有 xi < xi + 1 且 yi < yi + 1 。
对于所有 1 <= i <= m 的 i 对应的点 (xi, yi) 都在给定的坐标数组里。
请你返回包含坐标 coordinates[k] 的 最长上升路径 的长度。



示例 1：

输入：coordinates = [[3,1],[2,2],[4,1],[0,0],[5,3]], k = 1

输出：3

解释：

(0, 0) ，(2, 2) ，(5, 3) 是包含坐标 (2, 2) 的最长上升路径。

示例 2：

输入：coordinates = [[2,1],[7,0],[5,6]], k = 2

输出：2

解释：

(2, 1) ，(5, 6) 是包含坐标 (5, 6) 的最长上升路径。



提示：

1 <= n == coordinates.length <= 105
coordinates[i].length == 2
0 <= coordinates[i][0], coordinates[i][1] <= 109
coordinates 中的元素 互不相同 。
0 <= k <= n - 1
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] == v2[0] ? v1[1] > v2[1] : v1[0] < v2[0];  // x相等时，y大的排前面，这样可以保证LIS时相同的x最多选一个y
}

class Solution {
public:
    int maxPathLength(vector<vector<int>>& coordinates, int k) {
        int kx = coordinates[k][0], ky = coordinates[k][1];
        vector<int> inc;

        sort(coordinates.begin(), coordinates.end(), vectorCompare);

        for (auto& coordinate : coordinates) {
            int x = coordinate[0], y = coordinate[1];
            if ((x < kx && y < ky) || (x > kx && y > ky)) {
                auto iter = lower_bound(inc.begin(), inc.end(), y);
                if (iter == inc.end()) {
                    inc.push_back(y);
                }
                else {
                    *iter = y;  // 贪心思想，LIS相同长度下，每次保留最小的一个数
                }
            }
        }

        return (int)inc.size() + 1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> coordinates = { {3,1},{2,2},{4,1},{0,0},{5,3} };
    check.checkInt(3, o.maxPathLength(coordinates, 1));

    coordinates = { {2,1},{7,0},{5,6} };
    check.checkInt(2, o.maxPathLength(coordinates, 2));

    coordinates = { {1,1},{1,2},{3,3} };
    check.checkInt(2, o.maxPathLength(coordinates, 2));
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
