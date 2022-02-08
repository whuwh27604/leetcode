/* 网格照明.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在大小为 n x n 的网格 grid 上，每个单元格都有一盏灯，最初灯都处于 关闭 状态。

给你一个由灯的位置组成的二维数组 lamps ，其中 lamps[i] = [rowi, coli] 表示 打开 位于 grid[rowi][coli] 的灯。即便同一盏灯可能在 lamps 中多次列出，不会影响这盏灯处于 打开 状态。

当一盏灯处于打开状态，它将会照亮 自身所在单元格 以及同一 行 、同一 列 和两条 对角线 上的 所有其他单元格 。

另给你一个二维数组 queries ，其中 queries[j] = [rowj, colj] 。对于第 j 个查询，如果单元格 [rowj, colj] 是被照亮的，则查询结果为 1 ，否则为 0 。在第 j 次查询之后 [按照查询的顺序] ，关闭 位于单元格 grid[rowj][colj] 上及相邻 8 个方向上（与单元格 grid[rowi][coli] 共享角或边）的任何灯。

返回一个整数数组 ans 作为答案， ans[j] 应等于第 j 次查询 queries[j] 的结果，1 表示照亮，0 表示未照亮。

 

示例 1：


输入：n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,0]]
输出：[1,0]
解释：最初所有灯都是关闭的。在执行查询之前，打开位于 [0, 0] 和 [4, 4] 的灯。第 0 次查询检查 grid[1][1] 是否被照亮（蓝色方框）。该单元格被照亮，所以 ans[0] = 1 。然后，关闭红色方框中的所有灯。

第 1 次查询检查 grid[1][0] 是否被照亮（蓝色方框）。该单元格没有被照亮，所以 ans[1] = 0 。然后，关闭红色矩形中的所有灯。

示例 2：

输入：n = 5, lamps = [[0,0],[4,4]], queries = [[1,1],[1,1]]
输出：[1,1]
示例 3：

输入：n = 5, lamps = [[0,0],[0,4]], queries = [[0,4],[0,1],[1,4]]
输出：[1,1,0]
 

提示：

1 <= n <= 109
0 <= lamps.length <= 20000
0 <= queries.length <= 20000
lamps[i].length == 2
0 <= rowi, coli < n
queries[j].length == 2
0 <= rowj, colj < n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/grid-illumination
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> rows, columns, diagonals, backDiagonals;
        unordered_set<long long> lights;
        int dr[9] = { 0,0,1,1,1,0,-1,-1,-1 }, dc[9] = { 0,1,1,0,-1,-1,-1,0,1 };
        int index = 0, size = queries.size();
        vector<int> ans(size);

        for (auto& lamp : lamps) {
            lights.insert((((long long)lamp[0]) << 32) | lamp[1]);
        }

        for (long long light : lights) {
            int r = (int)(light >> 32), c = (int)light;
            ++rows[r];
            ++columns[c];
            ++diagonals[r - c];
            ++backDiagonals[r + c];
        }

        for (auto& query : queries) {
            int r = query[0], c = query[1];
            ans[index++] = ((rows.count(r) != 0 && rows[r] > 0)
                || (columns.count(c) != 0 && columns[c] > 0)
                || (diagonals.count(r - c) != 0 && diagonals[r - c] > 0)
                || (backDiagonals.count(r + c) != 0 && backDiagonals[r + c] > 0));

            for (int i = 0; i < 9; ++i) {
                int nr = r + dr[i], nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    long long light = (((long long)nr) << 32) | nc;

                    if (lights.count(light) != 0) {
                        lights.erase(light);
                        --rows[nr];
                        --columns[nc];
                        --diagonals[nr - nc];
                        --backDiagonals[nr + nc];
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> lamps = { {0,0},{4,4} };
    vector<vector<int>> queries = { {1,1},{1,0} };
    vector<int> actual = o.gridIllumination(5, lamps, queries);
    vector<int> expected = { 1,0 };
    check.checkIntVector(expected, actual);

    lamps = { {0,0},{4,4} };
    queries = { {1,1},{1,1} };
    actual = o.gridIllumination(5, lamps, queries);
    expected = { 1,1 };
    check.checkIntVector(expected, actual);

    lamps = { {0,0},{0,4} };
    queries = { {0,4},{0,1},{1,4} };
    actual = o.gridIllumination(5, lamps, queries);
    expected = { 1,1,0 };
    check.checkIntVector(expected, actual);

    lamps = {  };
    queries = {  };
    actual = o.gridIllumination(1, lamps, queries);
    expected = {  };
    check.checkIntVector(expected, actual);

    lamps = { {0,0} };
    queries = { {0,0},{0,0},{0,0},{0,0} };
    actual = o.gridIllumination(1, lamps, queries);
    expected = { 1,0,0,0 };
    check.checkIntVector(expected, actual);

    lamps = { {2,5},{4,2},{0,3},{0,5},{1,4},{4,2},{3,3},{1,0} };
    queries = { {4,3},{3,1},{5,3},{0,5},{4,4},{3,3} };
    actual = o.gridIllumination(6, lamps, queries);
    expected = { 1,0,1,1,0,1 };
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
