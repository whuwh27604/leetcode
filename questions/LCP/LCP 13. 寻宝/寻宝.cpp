/* 寻宝.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们得到了一副藏宝图，藏宝图显示，在一个迷宫中存在着未被世人发现的宝藏。

迷宫是一个二维矩阵，用一个字符串数组表示。它标识了唯一的入口（用 'S' 表示），和唯一的宝藏地点（用 'T' 表示）。但是，宝藏被一些隐蔽的机关保护了起来。在地图上有若干个机关点（用 'M' 表示），只有所有机关均被触发，才可以拿到宝藏。

要保持机关的触发，需要把一个重石放在上面。迷宫中有若干个石堆（用 'O' 表示），每个石堆都有无限个足够触发机关的重石。但是由于石头太重，我们一次只能搬一个石头到指定地点。

迷宫中同样有一些墙壁（用 '#' 表示），我们不能走入墙壁。剩余的都是可随意通行的点（用 '.' 表示）。石堆、机关、起点和终点（无论是否能拿到宝藏）也是可以通行的。

我们每步可以选择向上/向下/向左/向右移动一格，并且不能移出迷宫。搬起石头和放下石头不算步数。那么，从起点开始，我们最少需要多少步才能最后拿到宝藏呢？如果无法拿到宝藏，返回 -1 。

示例 1：

输入： ["S#O", "M..", "M.T"]

输出：16

解释：最优路线为： S->O, cost = 4, 去搬石头 O->第二行的M, cost = 3, M机关触发 第二行的M->O, cost = 3, 我们需要继续回去 O 搬石头。 O->第三行的M, cost = 4, 此时所有机关均触发 第三行的M->T, cost = 2，去T点拿宝藏。 总步数为16。图片.gif

示例 2：

输入： ["S#O", "M.#", "M.T"]

输出：-1

解释：我们无法搬到石头触发机关

示例 3：

输入： ["S#O", "M.T", "M.."]

输出：17

解释：注意终点也是可以通行的。

限制：

1 <= maze.length <= 100
1 <= maze[i].length <= 100
maze[i].length == maze[j].length
S 和 T 有且只有一个
0 <= M的数量 <= 16
0 <= O的数量 <= 40，题目保证当迷宫中存在 M 时，一定存在至少一个 O 。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int r;
    int c;

    Node() : r(0), c(0) {}
    Node(int a, int b) : r(a), c(b) {}
};

class Solution {
public:
    int minimalSteps(vector<string>& maze) {
        init(maze);
        if (cntM == 0) {
            return ST == inf ? -1 : ST;
        }

        int allMask = (1 << cntM) - 1;
        vector<vector<int>> dp(cntM, vector<int>(allMask, inf));  // dp[i][mask]表示当前在M[i]，还未选的集合是mask，到达T的minSteps

        for (int unchosen = 0; unchosen < allMask; ++unchosen) {
            int chosen = allMask ^ unchosen;

            for (int i = 0, bit1 = 1; i < cntM; ++i, bit1 <<= 1) {  // 枚举当前所在位置M[i]
                if (unchosen == 0) {  // 所有M都已经选了
                    dp[i][unchosen] = MTs[i];  // 最后M[i]到T的距离
                }
                else {
                    if ((bit1 & chosen) != 0) {  // 当前M[i]只能在已选集合里面
                        for (int j = 0, bit2 = 1; j < cntM; ++j, bit2 <<= 1) {  // 枚举下一跳
                            if ((bit2 & unchosen) != 0) {
                                dp[i][unchosen] = min(dp[i][unchosen], MMs[i][j] + dp[j][bit2 ^ unchosen]);  // M[i] -> M[j] + M[j] -> T
                            }
                        }
                    }
                }
            }
        }

        int minSteps = inf;
        for (int i = 0, bit = 1; i < cntM; ++i, bit <<= 1) {  // 枚举第一个M
            minSteps = min(minSteps, SMs[i] + dp[i][bit ^ allMask]);
        }

        return minSteps == inf ? -1 : minSteps;
    }

    void init(vector<string>& maze) {
        row = (int)maze.size(), column = (int)maze[0].size();
        cntM = 0, cntO = 0, ST = inf;
        MIndices.clear();
        MIndices.resize(row * column, -1);
        OIndices.clear();
        OIndices.resize(row * column, -1);

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                if (maze[r][c] == 'S') {
                    S = Node(r, c);
                }
                else if (maze[r][c] == 'T') {
                    T = Node(r, c);
                }
                else if (maze[r][c] == 'M') {
                    MIndices[r * column + c] = cntM++;
                }
                else if (maze[r][c] == 'O') {
                    OIndices[r * column + c] = cntO++;
                }
            }
        }

        SOs.resize(cntO, inf);
        SMs.resize(cntM, inf);
        MTs.resize(cntM, inf);
        MOs.clear();
        MOs.resize(cntM, vector<int>(cntO, inf));
        MMs.clear();
        MMs.resize(cntM, vector<int>(cntM, inf));
        getMinSteps(maze);
        getSMs();
        getMMs();
    }

    void getMinSteps(vector<string>& maze) {
        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                if (maze[r][c] == 'M') {
                    BFS(maze, Node(r, c), true);
                }
                else if (maze[r][c] == 'S') {
                    BFS(maze, Node(r, c), false);
                }
            }
        }
    }

    void BFS(vector<string>& maze, Node start, bool fromM) {
        int index = MIndices[start.r * column + start.c];
        int steps = 0;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        queue<Node> nodes;
        nodes.push(start);
        vector<vector<bool>> visited(row, vector<bool>(column, false));
        visited[start.r][start.c] = true;

        while (!nodes.empty()) {
            ++steps;
            int size = (int)nodes.size();

            for (int i = 0; i < size; ++i) {
                Node node = nodes.front();
                nodes.pop();

                for (int j = 0; j < 4; ++j) {
                    int nr = node.r + dr[j], nc = node.c + dc[j];
                    if (nr >= 0 && nr < row && nc >= 0 && nc < column && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        if (maze[nr][nc] == '#') {
                            continue;
                        }

                        nodes.push(Node(nr, nc));

                        if (fromM) {
                            if (maze[nr][nc] == 'T') {
                                MTs[index] = steps;
                            }
                            else if (maze[nr][nc] == 'O') {
                                MOs[index][OIndices[nr * column + nc]] = steps;
                            }
                        }
                        else {  // from S
                            if (maze[nr][nc] == 'T') {
                                ST = steps;
                            }
                            else if (maze[nr][nc] == 'O') {
                                SOs[OIndices[nr * column + nc]] = steps;
                            }
                        }
                    }
                }
            }
        }
    }

    void getSMs() {  // SOM最短路径
        for (int i = 0; i < cntM; ++i) {
            for (int j = 0; j < cntO; ++j) {
                SMs[i] = min(SMs[i], SOs[j] + MOs[i][j]);  // S -> M[i] = S -> O[j] + O[j] -> M[i]
            }
        }
    }

    void getMMs() {  // MOM最短路径
        for (int i = 0; i < cntM; ++i) {
            for (int j = 0; j < cntM; ++j) {
                if (i != j) {
                    for (int k = 0; k < cntO; ++k) {
                        MMs[i][j] = min(MMs[i][j], MOs[i][k] + MOs[j][k]);  // M[i] -> M[j] = M[i] -> O[k] + O[k] -> M[j]
                    }
                }
            }
        }
    }

    Node S;
    Node T;
    vector<int> MIndices;
    vector<int> OIndices;
    vector<int> SOs;
    vector<int> SMs;
    vector<int> MTs;
    vector<vector<int>> MOs;
    vector<vector<int>> MMs;
    int ST = 0;
    int row = 0;
    int column = 0;
    int cntM = 0;
    int cntO = 0;
    int inf = INT_MAX / 2;
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> maze = { "S#O", "M..", "M.T" };
    check.checkInt(16, o.minimalSteps(maze));

    maze = { "S#O", "M.#", "M.T" };
    check.checkInt(-1, o.minimalSteps(maze));

    maze = { "S#O", "M.T", "M.." };
    check.checkInt(17, o.minimalSteps(maze));

    maze = { "ST" };
    check.checkInt(1, o.minimalSteps(maze));

    maze = { "S#T" };
    check.checkInt(-1, o.minimalSteps(maze));
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
