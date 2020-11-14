/* 太平洋大西洋水流问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个 m x n 的非负整数矩阵来表示一片大陆上各个单元格的高度。“太平洋”处于大陆的左边界和上边界，而“大西洋”处于大陆的右边界和下边界。

规定水流只能按照上、下、左、右四个方向流动，且只能从高到低或者在同等高度上流动。

请找出那些水流既可以流动到“太平洋”，又能流动到“大西洋”的陆地单元的坐标。

 

提示：

输出坐标的顺序不重要
m 和 n 都小于150
 

示例：

 

给定下面的 5x5 矩阵:

  太平洋 ~   ~   ~   ~   ~
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * 大西洋

返回:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (上图中带括号的单元).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pacific-atlantic-water-flow
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }

        unordered_set<long long> fromPacific2Atlantic, fromAtlantic2Pacific;
        int i, j, row = matrix.size(), column = matrix[0].size();

        for (i = 0; i < row; i++) {
            DFS(matrix, { i, 0 }, fromPacific2Atlantic);
            DFS(matrix, { i, column - 1 }, fromAtlantic2Pacific);
        }

        for (j = 0; j < column; j++) {
            DFS(matrix, { 0, j }, fromPacific2Atlantic);
            DFS(matrix, { row - 1, j }, fromAtlantic2Pacific);
        }

        vector<vector<int>> bothReachingPoints;
        for (long long point : fromPacific2Atlantic) {
            if (fromAtlantic2Pacific.find(point) != fromAtlantic2Pacific.end()) {
                bothReachingPoints.push_back({ (int)(point >> 32), (int)point });
            }
        }

        return bothReachingPoints;
    }

    void DFS(vector<vector<int>>& matrix, pair<int, int> originalPoint, unordered_set<long long>& reachablePoint) {
        int dr[5] = { 0,1,0,-1,0 }, dc[5] = { 0,0,1,0,-1 };
        int row = matrix.size(), column = matrix[0].size();
        stack<pair<pair<int, int>, int>> reachedPoint;
        reachedPoint.push({ originalPoint, 0 });
        reachablePoint.insert(((long long)(originalPoint.first) << 32) + originalPoint.second);

        while (!reachedPoint.empty()) {
            pair<int, int> currentPoint = reachedPoint.top().first;
            int direction = reachedPoint.top().second + 1;
            reachedPoint.pop();

            for (; direction < 5; direction++) {
                pair<int, int> nextPoint = { currentPoint.first + dr[direction],currentPoint.second + dc[direction] };
                if ((nextPoint.first < 0) || (nextPoint.first >= row) || (nextPoint.second < 0) || (nextPoint.second >= column)) {
                    continue;
                }

                if (reachablePoint.find(((long long)(nextPoint.first) << 32) + nextPoint.second) != reachablePoint.end()) {
                    continue;  // 如果这个点从其他路径已经访问过了，跳过
                }

                if (matrix[currentPoint.first][currentPoint.second] <= matrix[nextPoint.first][nextPoint.second]) {
                    reachedPoint.push({ currentPoint, direction });
                    reachablePoint.insert(((long long)(currentPoint.first) << 32) + currentPoint.second);
                    currentPoint = nextPoint;
                    direction = 0;
                }
            }

            reachablePoint.insert(((long long)(currentPoint.first) << 32) + currentPoint.second);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> matrix = {};
    vector<vector<int>> actual = o.pacificAtlantic(matrix);
    vector<vector<int>> expected = {};
    check.checkIntVectorVectorRandomOrder(expected, actual);

    matrix = { {} };
    actual = o.pacificAtlantic(matrix);
    expected = {};
    check.checkIntVectorVectorRandomOrder(expected, actual);

    matrix = { {1,2,3} };
    actual = o.pacificAtlantic(matrix);
    expected = { {0,0},{0,1},{0,2} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    matrix = { {1,2,3},{2,3,2},{3,2,1} };
    actual = o.pacificAtlantic(matrix);
    expected = { {0,2},{2,0},{1,1} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    matrix = { {1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4} };
    actual = o.pacificAtlantic(matrix);
    expected = { {1,3},{3,1},{2,2},{4,0},{0,4},{1,4},{3,0} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    matrix = { {1,2,3},{8,9,4},{7,6,5} };
    actual = o.pacificAtlantic(matrix);
    expected = { {2,2},{1,1},{1,0},{0,2},{2,0},{1,2},{2,1} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    matrix = { {10,10,10},{10,1,10},{10,10,10} };
    actual = o.pacificAtlantic(matrix);
    expected = { {0,0},{0,1},{0,2},{1,0},{1,2},{2,0},{2,1},{2,2} };
    check.checkIntVectorVectorRandomOrder(expected, actual);

    matrix = { {10,1,1},{10,10,10},{10,10,10} };
    actual = o.pacificAtlantic(matrix);
    expected = { {0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2} };
    check.checkIntVectorVectorRandomOrder(expected, actual);
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
