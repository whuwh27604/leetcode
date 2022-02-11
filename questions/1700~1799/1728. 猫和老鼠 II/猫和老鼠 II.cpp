/* 猫和老鼠 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一只猫和一只老鼠在玩一个叫做猫和老鼠的游戏。

它们所处的环境设定是一个 rows x cols 的方格 grid ，其中每个格子可能是一堵墙、一块地板、一位玩家（猫或者老鼠）或者食物。

玩家由字符 'C' （代表猫）和 'M' （代表老鼠）表示。
地板由字符 '.' 表示，玩家可以通过这个格子。
墙用字符 '#' 表示，玩家不能通过这个格子。
食物用字符 'F' 表示，玩家可以通过这个格子。
字符 'C' ， 'M' 和 'F' 在 grid 中都只会出现一次。
猫和老鼠按照如下规则移动：

老鼠 先移动 ，然后两名玩家轮流移动。
每一次操作时，猫和老鼠可以跳到上下左右四个方向之一的格子，他们不能跳过墙也不能跳出 grid 。
catJump 和 mouseJump 是猫和老鼠分别跳一次能到达的最远距离，它们也可以跳小于最大距离的长度。
它们可以停留在原地。
老鼠可以跳跃过猫的位置。
游戏有 4 种方式会结束：

如果猫跟老鼠处在相同的位置，那么猫获胜。
如果猫先到达食物，那么猫获胜。
如果老鼠先到达食物，那么老鼠获胜。
如果老鼠不能在 1000 次操作以内到达食物，那么猫获胜。
给你 rows x cols 的矩阵 grid 和两个整数 catJump 和 mouseJump ，双方都采取最优策略，如果老鼠获胜，那么请你返回 true ，否则返回 false 。

 

示例 1：



输入：grid = ["####F","#C...","M...."], catJump = 1, mouseJump = 2
输出：true
解释：猫无法抓到老鼠，也没法比老鼠先到达食物。
示例 2：



输入：grid = ["M.C...F"], catJump = 1, mouseJump = 4
输出：true
示例 3：

输入：grid = ["M.C...F"], catJump = 1, mouseJump = 3
输出：false
示例 4：

输入：grid = ["C...#","...#F","....#","M...."], catJump = 2, mouseJump = 5
输出：false
示例 5：

输入：grid = [".M...","..#..","#..#.","C#.#.","...#F"], catJump = 3, mouseJump = 1
输出：true
 

提示：

rows == grid.length
cols = grid[i].length
1 <= rows, cols <= 8
grid[i][j] 只包含字符 'C' ，'M' ，'F' ，'.' 和 '#' 。
grid 中只包含一个 'C' ，'M' 和 'F' 。
1 <= catJump, mouseJump <= 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cat-and-mouse-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        init(grid, catJump, mouseJump);

        int cat = 0, mouse = 0;
        getPosition(grid, cat, mouse);

        return getMouseResults(cat, mouse, 0) == WIN;
    }

    int getMouseResults(int cat, int mouse, int turns) {
        int state = ((cat << 6) | mouse), r = mouse / 8, c = mouse % 8;

        if (turns == MAXTURNS) {  // 超过最大轮数，判定为LOST
            return LOST;
        }

        int& result = results[turns][state];
        if (result != INIT) {
            return result;
        }

        for (int i = 0; i < 4; ++i) {  // 尝试4个方向，mouse不可选择不动，因为mouse只有吃到food才能获胜，不动是不可能吃到food的
            for (int j = 1; j <= mJump; ++j) {  // 尝试每一个步长
                int nr = r + dr[i] * j, nc = c + dc[i] * j, next = (nr * 8 + nc);

                if (nr < 0 || nr >= row || nc < 0 || nc >= column || board[nr][nc] == '#') {  // 该方向已到边界
                    break;
                }

                if (board[nr][nc] == 'F') {  // mouse抓到food，获胜
                    return result = WIN;
                }
                else if (next == cat) {  // mouse碰到cat，失败
                    continue;
                }

                int nResult = getCatResults(cat, next, turns + 1);
                if (nResult == LOST) {  // 对方必输，那么选择这个走法
                    return result = WIN;
                }
            }
        }

        return result = LOST;  // 所有方法都尝试了，对方都是必胜，自己只能认负
    }

    int getCatResults(int cat, int mouse, int turns) {
        int state = ((cat << 6) | mouse), r = cat / 8, c = cat % 8;

        int& result = results[turns][state];
        if (result != INIT) {
            return result;
        }

        int nResult = getMouseResults(cat, mouse, turns + 1);  // cat自己不动
        if (nResult == LOST) {  // 对方必输，那么选择这个走法
            return result = WIN;
        }

        for (int i = 0; i < 4; ++i) {  // 尝试4个方向
            for (int j = 1; j <= cJump; ++j) {  // 尝试每一个步长
                int nr = r + dr[i] * j, nc = c + dc[i] * j, next = (nr * 8 + nc);

                if (nr < 0 || nr >= row || nc < 0 || nc >= column || board[nr][nc] == '#') {  // 该方向已到边界
                    break;
                }

                if (next == mouse || board[nr][nc] == 'F') {  // cat抓到mouse或者food，获胜
                    return result = WIN;
                }

                nResult = getMouseResults(next, mouse, turns + 1);
                if (nResult == LOST) {  // 对方必输，那么选择这个走法
                    return result = WIN;
                }
            }
        }

        return result = LOST;  // 所有方法都尝试了，对方都是必胜，自己只能认负
    }

    void init(vector<string>& grid, int catJump, int mouseJump) {
        row = grid.size();
        column = grid[0].size();
        cJump = catJump;
        mJump = mouseJump;
        INIT = 0;
        WIN = 1;
        LOST = 2;
        MAXTURNS = row * column * 2;  // 最大轮次使用1000会超时，使用row * column会有反例过不了，准确是多少并没有想明白...
        dr[0] = 0, dr[1] = 1, dr[2] = 0, dr[3] = -1;
        dc[0] = 1, dc[1] = 0, dc[2] = -1, dc[3] = 0;
        board = grid;
        results = vector<vector<int>>(MAXTURNS, vector<int>(4096, 0));  // ((63 << 6) | 64)最多需要4096个状态
    }

    void getPosition(vector<string>& grid, int& cat, int& mouse) {
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (grid[i][j] == 'C') {
                    cat = (i * 8 + j);
                }
                else if (grid[i][j] == 'M') {
                    mouse = (i * 8 + j);
                }
            }
        }
    }

private:
    int row;
    int column;
    int cJump;
    int mJump;
    int INIT;
    int WIN;
    int LOST;
    int MAXTURNS;
    int dr[4];
    int dc[4];
    vector<string> board;
    vector<vector<int>> results;
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> grid = { "####F","#C...","M...." };
    check.checkBool(true, o.canMouseWin(grid, 1, 2));

    grid = { "M.C...F" };
    check.checkBool(true, o.canMouseWin(grid, 1, 4));

    grid = { "M.C...F" };
    check.checkBool(false, o.canMouseWin(grid, 1, 3));

    grid = { "C...#","...#F","....#","M...." };
    check.checkBool(false, o.canMouseWin(grid, 2, 5));

    grid = { ".M...","..#..","#..#.","C#.#.","...#F" };
    check.checkBool(true, o.canMouseWin(grid, 3, 1));

    grid = { "#..C...","M....#.","######.","######.","######.","######F" };
    check.checkBool(false, o.canMouseWin(grid, 1, 5));

    grid = { ".#...#..","....C..#","........","........","........","#..#.F#.","..#.....","....#M.." };
    check.checkBool(true, o.canMouseWin(grid, 2, 1));

    grid = { "CM......", "#######.", "........", ".#######", "........", "#######.", "........", "F#######" };
    check.checkBool(true, o.canMouseWin(grid, 1, 1));
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
