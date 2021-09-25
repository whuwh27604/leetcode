/* 找到所有的农场组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始，大小为 m x n 的二进制矩阵 land ，其中 0 表示一单位的森林土地，1 表示一单位的农场土地。

为了让农场保持有序，农场土地之间以矩形的 农场组 的形式存在。每一个农场组都 仅 包含农场土地。且题目保证不会有两个农场组相邻，也就是说一个农场组中的任何一块土地都 不会 与另一个农场组的任何一块土地在四个方向上相邻。

land 可以用坐标系统表示，其中 land 左上角坐标为 (0, 0) ，右下角坐标为 (m-1, n-1) 。请你找到所有 农场组 最左上角和最右下角的坐标。一个左上角坐标为 (r1, c1) 且右下角坐标为 (r2, c2) 的 农场组 用长度为 4 的数组 [r1, c1, r2, c2] 表示。

请你返回一个二维数组，它包含若干个长度为 4 的子数组，每个子数组表示 land 中的一个 农场组 。如果没有任何农场组，请你返回一个空数组。可以以 任意顺序 返回所有农场组。

示例 1：



输入：land = [[1,0,0],[0,1,1],[0,1,1]]
输出：[[0,0,0,0],[1,1,2,2]]
解释：
第一个农场组的左上角为 land[0][0] ，右下角为 land[0][0] 。
第二个农场组的左上角为 land[1][1] ，右下角为 land[2][2] 。
示例 2：



输入：land = [[1,1],[1,1]]
输出：[[0,0,1,1]]
解释：
第一个农场组左上角为 land[0][0] ，右下角为 land[1][1] 。
示例 3：



输入：land = [[0]]
输出：[]
解释：
没有任何农场组。
 

提示：

m == land.length
n == land[i].length
1 <= m, n <= 300
land 只包含 0 和 1 。
农场组都是 矩形 的形状。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-all-groups-of-farmland
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> farmlands;
        int r1, c1, row = land.size(), column = land[0].size();

        for (r1 = 0; r1 < row; ++r1) {
            for (c1 = 0; c1 < column; ++c1) {
                if (land[r1][c1] == 0) {
                    continue;
                }

                farmlands.push_back({ r1,c1 });
                int r2 = r1, c2 = c1;

                while (c2 + 1 < column && land[r1][c2 + 1] == 1) {
                    ++c2;
                }

                while (r2 + 1 < row && land[r2 + 1][c2] == 1) {
                    ++r2;
                }

                farmlands.back().push_back(r2);
                farmlands.back().push_back(c2);

                for (int i = r1; i <= r2; ++i) {
                    for (int j = c1; j <= c2; ++j) {
                        land[i][j] = 0;
                    }
                }
            }
        }

        return farmlands;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> land = { {1,0,0},{0,1,1},{0,1,1} };
    vector<vector<int>> actual = o.findFarmland(land);
    vector<vector<int>> expected = { {0,0,0,0},{1,1,2,2} };
    check.checkIntVectorRandomOrderVector(expected, actual);

    land = { {1,1},{1,1} };
    actual = o.findFarmland(land);
    expected = { {0,0,1,1} };
    check.checkIntVectorRandomOrderVector(expected, actual);

    land = { {0} };
    actual = o.findFarmland(land);
    expected = {};
    check.checkIntVectorRandomOrderVector(expected, actual);
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
