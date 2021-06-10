/* 奇怪的打印机 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个奇怪的打印机，它有如下两个特殊的打印规则：

每一次操作时，打印机会用同一种颜色打印一个矩形的形状，每次打印会覆盖矩形对应格子里原本的颜色。
一旦矩形根据上面的规则使用了一种颜色，那么 相同的颜色不能再被使用 。
给你一个初始没有颜色的 m x n 的矩形 targetGrid ，其中 targetGrid[row][col] 是位置 (row, col) 的颜色。

如果你能按照上述规则打印出矩形 targetGrid ，请你返回 true ，否则返回 false 。

 

示例 1：



输入：targetGrid = [[1,1,1,1],[1,2,2,1],[1,2,2,1],[1,1,1,1]]
输出：true
示例 2：



输入：targetGrid = [[1,1,1,1],[1,1,3,3],[1,1,3,4],[5,5,1,4]]
输出：true
示例 3：

输入：targetGrid = [[1,2,1],[2,1,2],[1,2,1]]
输出：false
解释：没有办法得到 targetGrid ，因为每一轮操作使用的颜色互不相同。
示例 4：

输入：targetGrid = [[1,1,1],[3,1,3]]
输出：false
 

提示：

m == targetGrid.length
n == targetGrid[i].length
1 <= m, n <= 60
1 <= targetGrid[row][col] <= 60

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/strange-printer-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int size = 61;
        vector<vector<int>> rectangles(size, { INT_MAX, INT_MAX, INT_MIN, INT_MIN });
        getRectangles(targetGrid, rectangles);

        vector<int> indegrees(size, 0);
        int totalIndegree = 0;
        vector<vector<int>> after(size);
        buildIndegreesTable(targetGrid, rectangles, indegrees, totalIndegree, after);

        queue<int> zeroIndegreeRects;

        for (int color = 1; color < size; ++color) {
            if (indegrees[color] == 0) {
                zeroIndegreeRects.push(color);
            }
        }

        while (!zeroIndegreeRects.empty()) {
            int color = zeroIndegreeRects.front();
            zeroIndegreeRects.pop();

            for (int rect : after[color]) {
                --totalIndegree;

                if (--indegrees[rect] == 0) {
                    zeroIndegreeRects.push(rect);
                }
            }
        }

        return totalIndegree == 0;
    }

    void getRectangles(vector<vector<int>>& targetGrid, vector<vector<int>>& rectangles) {
        int r, c, row = targetGrid.size(), column = targetGrid[0].size();

        for (r = 0; r < row; ++r) {
            for (c = 0; c < column; ++c) {
                int color = targetGrid[r][c];
                rectangles[color][0] = min(rectangles[color][0], r);
                rectangles[color][1] = min(rectangles[color][1], c);
                rectangles[color][2] = max(rectangles[color][2], r);
                rectangles[color][3] = max(rectangles[color][3], c);
            }
        }
    }

    void buildIndegreesTable(vector<vector<int>>& targetGrid, vector<vector<int>>& rectangles,
        vector<int>& indegrees, int& totalIndegree, vector<vector<int>>& after) {
        for (int color = 1; color < 61; ++color) {
            if (rectangles[color][0] != INT_MAX) {
                build(targetGrid, rectangles[color], color, indegrees, totalIndegree, after);
            }
        }
    }

    void build(vector<vector<int>>& targetGrid, vector<int>& rectangle, int color, 
        vector<int>& indegrees, int& totalIndegree, vector<vector<int>>& after) {
        for (int r = rectangle[0]; r <= rectangle[2]; ++r) {
            for (int c = rectangle[1]; c <= rectangle[3]; ++c) {
                if (targetGrid[r][c] != color) {
                    ++indegrees[targetGrid[r][c]];
                    ++totalIndegree;
                    after[color].push_back(targetGrid[r][c]);
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> targetGrid = { {1,1,1,1},{1,2,2,1},{1,2,2,1},{1,1,1,1} };
    check.checkBool(true, o.isPrintable(targetGrid));

    targetGrid = { {1,1,1,1},{1,1,3,3},{1,1,3,4},{5,5,1,4} };
    check.checkBool(true, o.isPrintable(targetGrid));

    targetGrid = { {1,2,1},{2,1,2},{1,2,1} };
    check.checkBool(false, o.isPrintable(targetGrid));

    targetGrid = { {1,1,1},{3,1,3} };
    check.checkBool(false, o.isPrintable(targetGrid));
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
