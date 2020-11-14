/* 01 矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

示例 1:
输入:

0 0 0
0 1 0
0 0 0
输出:

0 0 0
0 1 0
0 0 0
示例 2:
输入:

0 0 0
0 1 0
1 1 1
输出:

0 0 0
0 1 0
1 2 1
注意:

给定矩阵的元素个数不超过 10000。
给定矩阵中至少有一个元素是 0。
矩阵中的元素只在四个方向上相邻: 上、下、左、右。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/01-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int i, j, row = matrix.size(), column = matrix[0].size();
        queue<pair<int, int>> points;
        vector<vector<int>> distanceMatrix(row, vector<int>(column, 0));

        for (i = 0; i < row; i++) {
            for (j = 0; j < column; j++) {
                if (matrix[i][j] == 0) {
                    points.push({ i, j });
                }
            }
        }

        BFS(matrix, points, distanceMatrix);
        return distanceMatrix;
    }

    void BFS(vector<vector<int>>& matrix, queue<pair<int, int>>& points, vector<vector<int>>& distanceMatrix) {
        int row = matrix.size(), column = matrix[0].size();
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        int distance = 0;

        while (!points.empty()) {
            int size = points.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> point = points.front();
                points.pop();
                distanceMatrix[point.first][point.second] = distance;

                for (int j = 0; j < 4; j++) {
                    pair<int, int> next = { point.first + dr[j], point.second + dc[j] };
                    if ((next.first >= 0) && (next.first < row) && (next.second >= 0) && (next.second < column)
                        && (matrix[next.first][next.second] == 1)) {
                        matrix[next.first][next.second] = 0;
                        points.push({ next.first, next.second });
                    }
                }
            }

            distance++;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> matrix = { {0} };
    vector<vector<int>> actual = o.updateMatrix(matrix);
    vector<vector<int>> expected = { {0} };
    check.checkIntVectorVector(expected, actual);

    matrix = { {0,1,0,1,0,1} };
    actual = o.updateMatrix(matrix);
    expected = { {0,1,0,1,0,1} };
    check.checkIntVectorVector(expected, actual);

    matrix = { {0,1,1,1,1,1} };
    actual = o.updateMatrix(matrix);
    expected = { {0,1,2,3,4,5} };
    check.checkIntVectorVector(expected, actual);

    matrix = { {0,0,0},{0,1,0},{0,0,0} };
    actual = o.updateMatrix(matrix);
    expected = { {0,0,0},{0,1,0},{0,0,0} };
    check.checkIntVectorVector(expected, actual);

    matrix = { {0,0,0},{0,1,0},{1,1,1} };
    actual = o.updateMatrix(matrix);
    expected = { {0,0,0},{0,1,0},{1,2,1} };
    check.checkIntVectorVector(expected, actual);

    matrix = { {0,1,0,1,1},{1,1,0,0,1},{0,0,0,1,0},{1,0,1,1,1},{1,0,0,0,1} };
    actual = o.updateMatrix(matrix);
    expected = { {0,1,0,1,2},{1,1,0,0,1},{0,0,0,1,0},{1,0,1,1,1},{1,0,0,0,1} };
    check.checkIntVectorVector(expected, actual);

    matrix = { {1,1,1,0},{1,1,1,1},{1,1,1,1},{1,1,1,1} };
    actual = o.updateMatrix(matrix);
    expected = { {3,2,1,0},{4,3,2,1},{5,4,3,2},{6,5,4,3} };
    check.checkIntVectorVector(expected, actual);
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
