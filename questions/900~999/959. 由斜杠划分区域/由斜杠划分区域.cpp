/* 由斜杠划分区域.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在由 1 x 1 方格组成的 N x N 网格 grid 中，每个 1 x 1 方块由 /、\ 或空格构成。这些字符会将方块划分为一些共边的区域。

（请注意，反斜杠字符是转义的，因此 \ 用 "\\" 表示。）。

返回区域的数目。

 

示例 1：

输入：
[
  " /",
  "/ "
]
输出：2
解释：2x2 网格如下：

示例 2：

输入：
[
  " /",
  "  "
]
输出：1
解释：2x2 网格如下：

示例 3：

输入：
[
  "\\/",
  "/\\"
]
输出：4
解释：（回想一下，因为 \ 字符是转义的，所以 "\\/" 表示 \/，而 "/\\" 表示 /\。）
2x2 网格如下：

示例 4：

输入：
[
  "/\\",
  "\\/"
]
输出：5
解释：（回想一下，因为 \ 字符是转义的，所以 "/\\" 表示 /\，而 "\\/" 表示 \/。）
2x2 网格如下：

示例 5：

输入：
[
  "//",
  "/ "
]
输出：3
解释：2x2 网格如下：

 

提示：

1 <= grid.length == grid[0].length <= 30
grid[i][j] 是 '/'、'\'、或 ' '。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/regions-cut-by-slashes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int size = grid.size(), len = size * size * 4;
        int* parents = new int[len];
        init(parents, len);

        // 每个grid有4条side：[up:0, right:1, down:2, left:3]
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                int side = (i * size + j) * 4;  // side0的编号
                if (grid[i][j] == '/') {  // side0和side3连通，side1和side2连通
                    unionSet(side, side + 3, parents);
                    unionSet(side + 1, side + 2, parents);
                }
                else if (grid[i][j] == '\\') {  // side0和side1连通，side2和side3连通
                    unionSet(side, side + 1, parents);
                    unionSet(side + 2, side + 3, parents);
                }
                else {  // side0、side1、side2和side3连通
                    unionSet(side, side + 1, parents);
                    unionSet(side, side + 2, parents);
                    unionSet(side, side + 3, parents);
                }

                if (i != 0) {  // 如果不是第一行，side0和上面一行的side2连通
                    unionSet(side, ((i - 1) * size + j) * 4 + 2, parents);
                }
                if (j != 0) {  // 如果不是第一列，side3和左边一列的side1连通
                    unionSet(side - 3, side + 3, parents);
                }
            }
        }

        int regions = countSet(parents, len);        
        delete[] parents;
        return regions;
    }

    void init(int* parents, int len) {
        for (int i = 0; i < len; ++i) {
            parents[i] = i;
        }
    }

    int findParent(int side, int* parents) {
        if (side != parents[side]) {
            parents[side] = findParent(parents[side], parents);
        }

        return parents[side];
    }

    void unionSet(int side1, int side2, int* parents) {
        parents[findParent(side1, parents)] = parents[findParent(side2, parents)];
    }

    int countSet(int* parents, int len) {
        int sets = 0;

        for (int i = 0; i < len; ++i) {
            int parent = findParent(i, parents);
            if (parent == i) {
                ++sets;
            }
        }

        return sets;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> grid = { " /","/ " };
    check.checkInt(2, o.regionsBySlashes(grid));

    grid = { " /","  " };
    check.checkInt(1, o.regionsBySlashes(grid));

    grid = { "\\/","/\\" };
    check.checkInt(4, o.regionsBySlashes(grid));

    grid = { "/\\","\\/" };
    check.checkInt(5, o.regionsBySlashes(grid));

    grid = { "//","/ " };
    check.checkInt(3, o.regionsBySlashes(grid));
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
