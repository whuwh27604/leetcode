/* 为高尔夫比赛砍树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你被请来给一个要举办高尔夫比赛的树林砍树。树林由一个 m x n 的矩阵表示， 在这个矩阵中：

0 表示障碍，无法触碰
1 表示地面，可以行走
比 1 大的数 表示有树的单元格，可以行走，数值表示树的高度
每一步，你都可以向上、下、左、右四个方向之一移动一个单位，如果你站的地方有一棵树，那么你可以决定是否要砍倒它。

你需要按照树的高度从低向高砍掉所有的树，每砍过一颗树，该单元格的值变为 1（即变为地面）。

你将从 (0, 0) 点开始工作，返回你砍完所有树需要走的最小步数。 如果你无法砍完所有的树，返回 -1 。

可以保证的是，没有两棵树的高度是相同的，并且你至少需要砍倒一棵树。

 

示例 1：


输入：forest = [[1,2,3],[0,0,4],[7,6,5]]
输出：6
解释：沿着上面的路径，你可以用 6 步，按从最矮到最高的顺序砍掉这些树。
示例 2：


输入：forest = [[1,2,3],[0,0,0],[7,6,5]]
输出：-1
解释：由于中间一行被障碍阻塞，无法访问最下面一行中的树。
示例 3：

输入：forest = [[2,3,4],[0,0,5],[8,7,6]]
输出：6
解释：可以按与示例 1 相同的路径来砍掉所有的树。
(0,0) 位置的树，可以直接砍去，不用算步数。
 

提示：

m == forest.length
n == forest[i].length
1 <= m, n <= 50
0 <= forest[i][j] <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/cut-off-trees-for-golf-event
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Tree {
public:
    int height;
    int r;
    int c;

    Tree(int _h, int _r, int _c) : height(_h), r(_r), c(_c) {}

    bool operator<(const Tree& t) const {
        return height < t.height;
    }
};

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        vector<Tree> trees;
        int srcR = 0, srcC = 0, totalSteps = 0;

        getTrees(forest, trees);
        sort(trees.begin(), trees.end());

        for (Tree& tree : trees) {
            int dstR = tree.r, dstC = tree.c;
            int steps = getSteps(forest, srcR, srcC, dstR, dstC);

            if (steps == -1) {
                return -1;
            }

            totalSteps += steps;
            srcR = dstR, srcC = dstC;
        }

        return totalSteps;
    }

    void getTrees(vector<vector<int>>& forest, vector<Tree>& trees) {
        int m = forest.size(), n = forest[0].size();

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (forest[r][c] > 1) {
                    trees.push_back(Tree(forest[r][c], r, c));
                }
            }
        }
    }

    int getSteps(vector<vector<int>>& forest, int srcR, int srcC, int dstR, int dstC) {
        int m = forest.size(), n = forest[0].size(), steps = -1;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        queue<pair<int, int>> bfs;
        bfs.push({ srcR,srcC });
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[srcR][srcC] = true;

        while (!bfs.empty()) {
            int i, j, size = bfs.size();
            ++steps;

            for (i = 0; i < size; ++i) {
                int r = bfs.front().first, c = bfs.front().second;
                bfs.pop();

                if (r == dstR && c == dstC) {
                    return steps;
                }

                for (j = 0; j < 4; ++j) {
                    int nr = r + dr[j], nc = c + dc[j];

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && forest[nr][nc] != 0 && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        bfs.push({ nr,nc });
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> forest = { {0} };
    check.checkInt(0, o.cutOffTree(forest));

    forest = { {0,2} };
    check.checkInt(1, o.cutOffTree(forest));

    forest = {{1,2,3},{0,0,4},{7,6,5}};
    check.checkInt(6,o.cutOffTree(forest));

    forest = {{1,2,3},{0,0,0},{7,6,5}};
    check.checkInt(-1,o.cutOffTree(forest));

    forest = {{2,3,4},{0,0,5},{8,7,6}};
    check.checkInt(6,o.cutOffTree(forest));

    forest = {{4,2,3},{0,0,1},{7,6,5}};
    check.checkInt(10,o.cutOffTree(forest));

    forest = {{1,1,2},{0,3,0},{7,6,5}};
    check.checkInt(8, o.cutOffTree(forest));
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
