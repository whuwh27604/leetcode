/* 集水器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
字符串数组 shape 描述了一个二维平面中的矩阵形式的集水器，shape[i][j] 表示集水器的第 i 行 j 列为：

'l'表示向左倾斜的隔板（即从左上到右下）；
'r'表示向右倾斜的隔板（即从左下到右上）；
'.' 表示此位置没有隔板image.png
已知当隔板构成存储容器可以存水，每个方格代表的蓄水量为 2。集水器初始浸泡在水中，除内部密闭空间外，所有位置均被水填满。 现将其从水中竖直向上取出，请返回集水器最终的蓄水量。

注意：

隔板具有良好的透气性，因此空气可以穿过隔板，但水无法穿过
示例 1：

输入： shape = ["....rl","l.lr.r",".l..r.","..lr.."]

输出：18

解释：如下图所示，由于空气会穿过隔板，因此红框区域没有水image.png

示例 2：

输入： shape = [".rlrlrlrl","ll..rl..r",".llrrllrr","..lr..lr."] 输出：18

解释：如图所示。由于红框右侧未闭合，因此多余的水会从该处流走。image.png

示例 3：

输入： shape = ["rlrr","llrl","llr."] 输出：6

解释：如图所示。image.png

示例 4：

输入： shape = ["...rl...","..r..l..",".r.rl.l.","r.r..l.l","l.l..rl.",".l.lr.r.","..l..r..","...lr..."]

输出：30

解释：如下图所示。由于中间为内部密闭空间，无法蓄水。image.png

提示：

1 <= shape.length <= 50
1 <= shape[i].length <= 50
shape[i][j] 仅为 'l'、'r' 或 '.'
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class DSU {
public:
    DSU(int size) {
        parents.resize(size);

        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    void merge(int x, int y) {
        parents[find(x)] = find(y);
    }

private:
    vector<int> parents;
};

class Solution {
public:
    int reservoir(vector<string>& shape) {
        int row = shape.size(), column = shape[0].size();
        int row2 = row + 2, column2 = column + 2;
        int size = row2 * column2 * 4 + 1;
        DSU dsuAll(size), dsuRow(size);

        reverse(shape.begin(), shape.end());  // row从下往上考虑更符合习惯
        mergeAll(size, row2, column2, shape, dsuAll);  // 先跑一遍全量并查集，看哪些位置有水，哪些位置是密闭的不可能有水

        return count(size, row2, column2, shape, dsuAll, dsuRow);
    }

    void mergeWater(int size, int row2, int column2, DSU& dsu) {
        for (int r = 1; r < row2 - 1; ++r) {
            dsu.merge(r * column2 * 4 + 1, size - 1);  // size - 1位置是虚拟水源，四周的点都连接到这里
            dsu.merge(r * column2 * 4 + (column2 - 1) * 4 + 3, size - 1);
        }

        for (int c = 1; c < column2 - 1; ++c) {
            dsu.merge(c * 4, size - 1);
            dsu.merge((row2 - 1) * column2 * 4 + c * 4 + 2, size - 1);
        }
    }

    void mergeRow(int size, int column2, bool mergeUp, int rIndex, vector<string>& shape, DSU& dsu) {
        for (int c = 1; c < column2 - 1; ++c) {
            int idx = rIndex * column2 * 4 + c * 4;  // 每个方格按对角线划分为4个格子，按上右下左顺序分别是0/1/2/3
            if (mergeUp) {
                dsu.merge(idx, idx + column2 * 4 + 2);  // 0 <--> up
            }
            if (shape[rIndex - 1][c - 1] != 'r') {
                dsu.merge(idx, idx + 1);  // 0 <--> 1
            }
            dsu.merge(idx + 1, idx + 7);  // 1 <--> right
            if (shape[rIndex - 1][c - 1] != 'l') {
                dsu.merge(idx + 1, idx + 2);  // 1 <--> 2
            }
            dsu.merge(idx + 2, idx - column2 * 4);  // 2 <--> down
            if (shape[rIndex - 1][c - 1] != 'r') {
                dsu.merge(idx + 2, idx + 3);  // 2 <--> 3
            }
            dsu.merge(idx + 3, idx - 3);  // 3 <--> left
            if (shape[rIndex - 1][c - 1] != 'l') {
                dsu.merge(idx + 3, idx);  // 3 <--> 0
            }
        }
    }

    void mergeAll(int size, int row2, int column2, vector<string>& shape, DSU& dsuAll) {
        mergeWater(size, row2, column2, dsuAll);

        for (int r = 1; r < row2 - 1; ++r) {
            mergeRow(size, column2, true, r, shape, dsuAll);
        }
    }

    int count(int size, int row2, int column2, vector<string>& shape, DSU& dsuAll, DSU& dsuRow) {
        int cnt = 0;

        mergeWater(size, row2, column2, dsuRow);

        for (int r = 1; r < row2 - 1; ++r) {
            mergeRow(size, column2, false, r, shape, dsuRow);  // 从低往高连接一行，此时先不要连接到上面的区域

            for (int c = 1; c < column2 - 1; ++c) {
                for (int i = 0; i < 4; ++i) {
                    int idx = r * column2 * 4 + c * 4 + i;
                    if (dsuAll.find(idx) == dsuAll.find(size - 1) && dsuRow.find(idx) != dsuRow.find(size - 1)) {
                        ++cnt;  // 一个有水的格子，在不连通上面的情况下，不会连通到周边的有水区域，则这个格子的水不会流走
                    }
                }
            }
        }

        return cnt / 2;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> shape = { "rlrr","llrl","llr." };
    check.checkInt(6, o.reservoir(shape));

    shape = { "....rl","l.lr.r",".l..r.","..lr.." };
    check.checkInt(18, o.reservoir(shape));

    shape = { ".rlrlrlrl","ll..rl..r",".llrrllrr","..lr..lr." };
    check.checkInt(18, o.reservoir(shape));

    shape = { "...rl...","..r..l..",".r.rl.l.","r.r..l.l","l.l..rl.",".l.lr.r.","..l..r..","...lr..." };
    check.checkInt(30, o.reservoir(shape));
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
