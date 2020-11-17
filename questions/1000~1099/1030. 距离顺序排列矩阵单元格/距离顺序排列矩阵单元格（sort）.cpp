/* 距离顺序排列矩阵单元格.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出 R 行 C 列的矩阵，其中的单元格的整数坐标为 (r, c)，满足 0 <= r < R 且 0 <= c < C。

另外，我们在该矩阵中给出了一个坐标为 (r0, c0) 的单元格。

返回矩阵中的所有单元格的坐标，并按到 (r0, c0) 的距离从最小到最大的顺序排，其中，两单元格(r1, c1) 和 (r2, c2) 之间的距离是曼哈顿距离，|r1 - r2| + |c1 - c2|。（你可以按任何满足此条件的顺序返回答案。）

 

示例 1：

输入：R = 1, C = 2, r0 = 0, c0 = 0
输出：[[0,0],[0,1]]
解释：从 (r0, c0) 到其他单元格的距离为：[0,1]
示例 2：

输入：R = 2, C = 2, r0 = 0, c0 = 1
输出：[[0,1],[0,0],[1,1],[1,0]]
解释：从 (r0, c0) 到其他单元格的距离为：[0,1,1,2]
[[0,1],[1,1],[0,0],[1,0]] 也会被视作正确答案。
示例 3：

输入：R = 2, C = 3, r0 = 1, c0 = 2
输出：[[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
解释：从 (r0, c0) 到其他单元格的距离为：[0,1,1,2,2,3]
其他满足题目要求的答案也会被视为正确，例如 [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]]。
 

提示：

1 <= R <= 100
1 <= C <= 100
0 <= r0 < R
0 <= c0 < C

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/matrix-cells-in-distance-order
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        multimap <int, Coordinate> disCoordinate;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                int distance = abs(i - r0) + abs(j - c0);
                Coordinate o(i, j);
                disCoordinate.insert(pair<int, Coordinate>(distance, o));
            }
        }

        vector<vector<int>> allCells;
        allCells.reserve(R * C);
        for (auto iter = disCoordinate.begin(); iter != disCoordinate.end(); iter++) {
            allCells.push_back({ iter->second.r, iter->second.c });
        }

        return allCells;
    }

    struct Coordinate {
        int r;
        int c;
        Coordinate(int a, int b) : r(a), c(b) {}
    };
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> expected = { {0,0}, {0,1} };
    vector<vector<int>> actual = o.allCellsDistOrder(1, 2, 0, 0);
    check.checkIntDoubleVector(expected, actual);

    expected = { {0,1}, {0,0}, {1,1}, {1,0} };
    actual = o.allCellsDistOrder(2, 2, 0, 1);
    check.checkIntDoubleVector(expected, actual);

    expected = { {1,2}, {0,2}, {1,1}, {0,1}, {1,0}, {0,0} };
    actual = o.allCellsDistOrder(2, 3, 1, 2);
    check.checkIntDoubleVector(expected, actual);

    expected = { {3,3}, {2,3}, {3,2}, {1,3}, {2,2}, {3,1}, {0,3}, {1,2}, {2,1}, {3,0}, {0,2}, {1,1}, {2,0}, {0,1}, {1,0}, {0,0} };
    actual = o.allCellsDistOrder(4, 4, 3, 3);
    check.checkIntDoubleVector(expected, actual);
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
