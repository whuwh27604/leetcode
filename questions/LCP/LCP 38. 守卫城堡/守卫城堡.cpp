/* 守卫城堡.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
城堡守卫游戏的胜利条件为使恶魔无法从出生点到达城堡。游戏地图可视作 2*N 的方格图，记作字符串数组 grid，其中：

"." 表示恶魔可随意通行的平地；
"#" 表示恶魔不可通过的障碍物，玩家可通过在 平地 上设置障碍物，即将 "." 变为 "#" 以阻挡恶魔前进；
"S" 表示恶魔出生点，将有大量的恶魔该点生成，恶魔可向上/向下/向左/向右移动，且无法移动至地图外；
"P" 表示瞬移点，移动到 "P" 点的恶魔可被传送至任意一个 "P" 点，也可选择不传送；
"C" 表示城堡。
然而在游戏中用于建造障碍物的金钱是有限的，请返回玩家最少需要放置几个障碍物才能获得胜利。若无论怎样放置障碍物均无法获胜，请返回 -1。

注意：

地图上可能有一个或多个出生点
地图上有且只有一个城堡
示例 1

输入：grid = ["S.C.P#P.", ".....#.S"]

输出：3

解释：至少需要放置三个障碍物image.png

示例 2：

输入：grid = ["SP#P..P#PC#.S", "..#P..P####.#"]

输出：-1

解释：无论怎样修筑障碍物，均无法阻挡最左侧出生的恶魔到达城堡位置image.png

示例 3：

输入：grid = ["SP#.C.#PS", "P.#...#.P"]

输出：0

解释：无需放置障碍物即可获得胜利image.png

示例 4：

输入：grid = ["CP.#.P.", "...S..S"]

输出：4

解释：至少需要放置 4 个障碍物，示意图为放置方法之一image.png

提示：

grid.length == 2
2 <= grid[0].length == grid[1].length <= 10^4
grid[i][j] 仅包含字符 "."、"#"、"C"、"P"、"S"
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int guardCastle(vector<string>& grid) {
        size = (int)grid[0].size();
        vector<string> newGrid;

        if (!canReachTransports(grid)) {
            newGrid = transfer(grid, GROUND);
            return isAdjacent(newGrid) ? -1 : getMinObstacles(newGrid);
        }

        int minObstacles = INT_MAX;
        newGrid = transfer(grid, CASTLE);
        if (!isAdjacent(newGrid)) {
            minObstacles = min(minObstacles, getMinObstacles(newGrid));
        }
        newGrid = transfer(grid, MONSTER);
        if (!isAdjacent(newGrid)) {
            minObstacles = min(minObstacles, getMinObstacles(newGrid));
        }

        return minObstacles == INT_MAX ? -1 : minObstacles;
    }

    vector<string> transfer(vector<string>& grid, char trans) {
        vector<string> newGrid(2, string(size, 0));

        for (int r = 0; r < 2; ++r) {
            for (int c = 0; c < size; ++c) {
                newGrid[r][c] = (grid[r][c] == TRANSPORT ? trans : grid[r][c]);
            }
        }

        return newGrid;
    }

    bool isAdjacent(vector<string>& grid) {
        for (int r = 0; r < 2; ++r) {
            for (int c = 0; c < size; ++c) {
                if (grid[r][c] == MONSTER) {
                    for (int i = 0; i < 4; ++i) {
                        int nr = r + dr[i], nc = c + dc[i];
                        if (nr >= 0 && nr < 2 && nc >= 0 && nc < size && grid[nr][nc] == CASTLE) {
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }

    int getMinObstacles(vector<string>& grid) {
        int minObstacles = 0, state = STATE_NOTHING;

        for (int i = 0; i < size; ++i) {
            if (grid[0][i] == CASTLE || grid[1][i] == CASTLE) {
                doCastle(grid, i, state, minObstacles);
            }
            else if (grid[0][i] == MONSTER || grid[1][i] == MONSTER) {
                doMonster(grid, i, state, minObstacles);
            }
            else if (grid[0][i] == OBSTACLE || grid[1][i] == OBSTACLE) {
                doObstacle(grid, i, state, minObstacles);
            }
        }

        return minObstacles;
    }

    void doCastle(vector<string>& grid, int idx, int& state, int& minObstacles) {
        if (grid[0][idx] == CASTLE && grid[1][idx] == CASTLE) {
            if (state == STATE_MONSTER1) {
                minObstacles += 1;
            }
            else if (state == STATE_MONSTER2) {
                minObstacles += 2;
            }
            state = STATE_CASTLE2;
        }
        else {
            bool leftOb = ((grid[0][idx] == CASTLE && idx != 0 && grid[0][idx - 1] == OBSTACLE)
                || (grid[1][idx] == CASTLE && idx != 0 && grid[1][idx - 1] == OBSTACLE));
            bool verticalOb = ((grid[0][idx] == CASTLE && grid[1][idx] == OBSTACLE)
                || (grid[1][idx] == CASTLE && grid[0][idx] == OBSTACLE));
            if (state == STATE_NOTHING || state == STATE_CASTLE1 || state == STATE_CASTLE2) {
                state = (verticalOb ? STATE_CASTLE1 : STATE_CASTLE2);
            }
            else if (state == STATE_MONSTER1) {  // 需要一个障碍物
                if (leftOb) {  // 左边有障碍物，优先放上/下面
                    state = STATE_CASTLE1;
                    minObstacles += (verticalOb ? 0 : 1);
                    grid[0][idx] == CASTLE ? grid[1][idx] = OBSTACLE : grid[0][idx] = OBSTACLE;  // 实际放一个
                }
                else {  // 左边没有障碍物，只能在前面放一个隔离开
                    state = (verticalOb ? STATE_CASTLE1 : STATE_CASTLE2);
                    minObstacles += 1;
                }
            }
            else {  // state == STATE_MONSTER2，要放2个障碍物，优先放CASTLE上/下面，这样CASTLE右边只需要一个障碍物就可以隔离开
                state = STATE_CASTLE1;
                minObstacles += (verticalOb ? 1 : 2);
                grid[0][idx] == CASTLE ? grid[1][idx] = OBSTACLE : grid[0][idx] = OBSTACLE;  // 实际放一个
            }
        }
    }

    void doMonster(vector<string>& grid, int idx, int& state, int& minObstacles) {
        if (grid[0][idx] == MONSTER && grid[1][idx] == MONSTER) {
            if (state == STATE_CASTLE1) {
                minObstacles += 1;
            }
            else if (state == STATE_CASTLE2) {
                minObstacles += 2;
            }
            state = STATE_MONSTER2;
        }
        else {
            bool leftOb = ((grid[0][idx] == MONSTER && idx != 0 && grid[0][idx - 1] == OBSTACLE)
                || (grid[1][idx] == MONSTER && idx != 0 && grid[1][idx - 1] == OBSTACLE));
            bool verticalOb = ((grid[0][idx] == MONSTER && grid[1][idx] == OBSTACLE)
                || (grid[1][idx] == MONSTER && grid[0][idx] == OBSTACLE));
            if (state == STATE_NOTHING || state == STATE_MONSTER1 || state == STATE_MONSTER2) {
                state = (verticalOb ? STATE_MONSTER1 : STATE_MONSTER2);
            }
            else if (state == STATE_CASTLE1) {  // 需要一个障碍物
                if (leftOb) {  // 左边有障碍物，优先放上/下面
                    state = STATE_MONSTER1;
                    minObstacles += (verticalOb ? 0 : 1);
                    grid[0][idx] == MONSTER ? grid[1][idx] = OBSTACLE : grid[0][idx] = OBSTACLE;  // 实际放一个
                }
                else {  // 左边没有障碍物，只能在前面放一个隔离开
                    state = (verticalOb ? STATE_MONSTER1 : STATE_MONSTER2);
                    minObstacles += 1;
                }
            }
            else {  // state == STATE_CASTLE2，要放2个障碍物，优先放MONSTER上/下面，这样MONSTER2右边只需要一个障碍物就可以隔离开
                state = STATE_MONSTER1;
                minObstacles += (verticalOb ? 1 : 2);
                grid[0][idx] == MONSTER ? grid[1][idx] = OBSTACLE : grid[0][idx] = OBSTACLE;  // 实际放一个
            }
        }
    }

    void doObstacle(vector<string>& grid, int idx, int& state, int& minObstacles) {
        if ((grid[0][idx] == OBSTACLE && grid[1][idx] == OBSTACLE)
            || (grid[0][idx] == OBSTACLE && idx != 0 && grid[1][idx - 1] == OBSTACLE)
            || (grid[1][idx] == OBSTACLE && idx != 0 && grid[0][idx - 1] == OBSTACLE)) {
            state = STATE_NOTHING;
        }
        else {
            if (state == STATE_MONSTER2) {
                state = STATE_MONSTER1;
            }
            else if (state == STATE_CASTLE2) {
                state = STATE_CASTLE1;
            }
        }
    }

    bool canReachTransports(vector<string>& grid) {
        vector<bool> visited(size * 2, false);
        queue<int> monsters;

        for (int r = 0; r < 2; ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] == MONSTER) {
                    int monster = r * size + c;
                    monsters.push(monster);
                    visited[monster] = true;
                }
            }
        }

        while (!monsters.empty()) {
            int monster = monsters.front();
            monsters.pop();
            int r = monster / size, c = monster % size;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < 2 && nc >= 0 && nc < size) {
                    int next = nr * size + nc;
                    if (!visited[next]) {
                        visited[next] = true;

                        if (grid[nr][nc] == TRANSPORT) {
                            return true;
                        }

                        if (grid[nr][nc] == GROUND) {
                            monsters.push(next);
                        }
                    }
                }
            }
        }

        return false;
    }

    int size = 0;
    int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };

    const char GROUND    = '.';
    const char OBSTACLE  = '#';
    const char MONSTER   = 'S';
    const char CASTLE    = 'C';
    const char TRANSPORT = 'P';

    const int STATE_NOTHING  = 0;  // 既没有monster也没有castle
    const int STATE_MONSTER1 = 1;  // monster联通，1个obstacle可以隔离
    const int STATE_MONSTER2 = 2;  // monster联通，2个obstacle可以隔离
    const int STATE_CASTLE1  = 3;  // castle联通，1个obstacle可以隔离
    const int STATE_CASTLE2  = 4;  // castle联通，2个obstacle可以隔离
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> grid = { "S.C.P#P.", ".....#.S" };
    check.checkInt(3, o.guardCastle(grid));

    grid = { "SP#P..P#PC#.S", "..#P..P####.#" };
    check.checkInt(-1, o.guardCastle(grid));

    grid = { "SP#.C.#PS", "P.#...#.P" };
    check.checkInt(0, o.guardCastle(grid));

    grid = { "CP.#.P.", "...S..S" };
    check.checkInt(4, o.guardCastle(grid));

    grid = { "..S..C", "S#...." };
    check.checkInt(2, o.guardCastle(grid));

    grid = { "#..#S....S.#....PP#...S.PC.P...S#...", "S.S.S.P#..##.S##..S#.#S...#.....P##S" };
    check.checkInt(8, o.guardCastle(grid));

    grid = { "S..C.#S",".S..#.." };
    check.checkInt(2, o.guardCastle(grid));

    grid = { "S.#.#...C....S", "......#...#.#S" };
    check.checkInt(2, o.guardCastle(grid));
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
