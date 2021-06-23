/* 推箱子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
「推箱子」是一款风靡全球的益智小游戏，玩家需要将箱子推到仓库中的目标位置。

游戏地图用大小为 n * m 的网格 grid 表示，其中每个元素可以是墙、地板或者是箱子。

现在你将作为玩家参与游戏，按规则将箱子 'B' 移动到目标位置 'T' ：

玩家用字符 'S' 表示，只要他在地板上，就可以在网格中向上、下、左、右四个方向移动。
地板用字符 '.' 表示，意味着可以自由行走。
墙用字符 '#' 表示，意味着障碍物，不能通行。 
箱子仅有一个，用字符 'B' 表示。相应地，网格上有一个目标位置 'T'。
玩家需要站在箱子旁边，然后沿着箱子的方向进行移动，此时箱子会被移动到相邻的地板单元格。记作一次「推动」。
玩家无法越过箱子。
返回将箱子推到目标位置的最小 推动 次数，如果无法做到，请返回 -1。

 

示例 1：



输入：grid = [["#","#","#","#","#","#"],
             ["#","T","#","#","#","#"],
             ["#",".",".","B",".","#"],
             ["#",".","#","#",".","#"],
             ["#",".",".",".","S","#"],
             ["#","#","#","#","#","#"]]
输出：3
解释：我们只需要返回推箱子的次数。
示例 2：

输入：grid = [["#","#","#","#","#","#"],
             ["#","T","#","#","#","#"],
             ["#",".",".","B",".","#"],
             ["#","#","#","#",".","#"],
             ["#",".",".",".","S","#"],
             ["#","#","#","#","#","#"]]
输出：-1
示例 3：

输入：grid = [["#","#","#","#","#","#"],
             ["#","T",".",".","#","#"],
             ["#",".","#","B",".","#"],
             ["#",".",".",".",".","#"],
             ["#",".",".",".","S","#"],
             ["#","#","#","#","#","#"]]
输出：5
解释：向下、向左、向左、向上再向上。
示例 4：

输入：grid = [["#","#","#","#","#","#","#"],
             ["#","S","#",".","B","T","#"],
             ["#","#","#","#","#","#","#"]]
输出：-1
 

提示：

1 <= grid.length <= 20
1 <= grid[i].length <= 20
grid 仅包含字符 '.', '#',  'S' , 'T', 以及 'B'。
grid 中 'S', 'B' 和 'T' 各只能出现一个。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-moves-to-move-a-box-to-their-target-location
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int row = grid.size(), column = grid[0].size(), push = 0;
        vector<vector<char>> gridAroundWall(row + 2, vector<char>(column + 2, '#'));
        int target = 0, box = 0, player = 0;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        queue<int> bfs;
        unordered_set<int> visited;

        aroundWall(grid, gridAroundWall);
        findTarget(gridAroundWall, target, box, player);

        int node = (box << 16) | player;
        bfs.push(node);
        visited.insert(node);

        while (!bfs.empty()) {
            int i, size = bfs.size();
            push += 1;

            for (i = 0; i < size; ++i) {
                node = bfs.front();
                bfs.pop();

                int rbox, cbox, rplayer, cplayer;
                decode(node, rbox, cbox, rplayer, cplayer);

                for (int j = 0; j < 4; ++j) {
                    int nrbox = rbox + dr[j], ncbox = cbox + dc[j], rrbox = rbox - dr[j], rcbox = cbox - dc[j];
                    if (gridAroundWall[nrbox][ncbox] == '#' || gridAroundWall[rrbox][rcbox] == '#'
                        || !reachable(gridAroundWall, rbox, cbox, (rplayer << 8) | cplayer, (rrbox << 8) | rcbox)) {
                        continue;
                    }

                    if (((nrbox << 8) | ncbox) == target) {
                        return push;
                    }

                    int next = encode(nrbox, ncbox, rbox, cbox);
                    if (visited.count(next) == 0) {
                        visited.insert(next);
                        bfs.push(next);
                    }
                }
            }
        }

        return -1;
    }

    void aroundWall(vector<vector<char>>& grid, vector<vector<char>>& gridAroundWall) {
        for (unsigned int i = 0; i < grid.size(); ++i) {
            for (unsigned int j = 0; j < grid[0].size(); ++j) {
                gridAroundWall[i + 1][j + 1] = grid[i][j];
            }
        }
    }

    void findTarget(vector<vector<char>>& gridAroundWall, int& target, int& box, int& player) {
        for (unsigned int i = 0; i < gridAroundWall.size(); ++i) {
            for (unsigned int j = 0; j < gridAroundWall[0].size(); ++j) {
                if (gridAroundWall[i][j] == 'S') {
                    player = ((i << 8) | j);
                    gridAroundWall[i][j] = '.';
                }
                else if (gridAroundWall[i][j] == 'B') {
                    box = ((i << 8) | j);
                    gridAroundWall[i][j] = '.';
                }
                else if (gridAroundWall[i][j] == 'T') {
                    target = ((i << 8) | j);
                    gridAroundWall[i][j] = '.';
                }
            }
        }
    }

    bool reachable(vector<vector<char>>& gridAroundWall, int rbox, int cbox, int player1, int player2) {
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        unordered_set<int> visited;
        queue<int> bfs;

        bfs.push(player1);
        visited.insert(player1);
        gridAroundWall[rbox][cbox] = '#';

        while (!bfs.empty()) {
            int node = bfs.front(), r = node >> 8, c = node & 0xff;
            bfs.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i], next = ((nr << 8) | nc);

                if (next == player2) {
                    gridAroundWall[rbox][cbox] = '.';
                    return true;
                }

                if (gridAroundWall[nr][nc] == '.' && visited.count(next) == 0) {
                    visited.insert(next);
                    bfs.push(next);
                }
            }
        }

        gridAroundWall[rbox][cbox] = '.';
        return false;
    }

    int encode(int rbox, int cbox, int rplayer, int cplayer) {
        return (rbox << 24) | (cbox << 16) | (rplayer << 8) | cplayer;
    }

    void decode(int node, int& rbox, int& cbox, int& rplayer, int& cplayer) {
        cplayer = node & 0xff;
        node >>= 8;
        rplayer = node & 0xff;
        node >>= 8;
        cbox = node & 0xff;
        node >>= 8;
        rbox = node & 0xff;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<char>> grid = { {'#','#','#','#','#','#'},
        {'#','T','#','#','#','#'},
        {'#','.','.','B','.','#'},
        {'#','.','#','#','.','#'},
        {'#','.','.','.','S','#'},
        {'#','#','#','#','#','#'} };
    check.checkInt(3, o.minPushBox(grid));

    grid = { {'#','#','#','#','#','#'},
        {'#','T','#','#','#','#'},
        {'#','.','.','B','.','#'},
        {'#','#','#','#','.','#'},
        {'#','.','.','.','S','#'},
        {'#','#','#','#','#','#'} };
    check.checkInt(-1, o.minPushBox(grid));

    grid = { {'#','#','#','#','#','#'},
        {'#','T','.','.','#','#'},
        {'#','.','#','B','.','#'},
        {'#','.','.','.','.','#'},
        {'#','.','.','.','S','#'},
        {'#','#','#','#','#','#'} };
    check.checkInt(5, o.minPushBox(grid));

    grid = { {'#','.','.','#','#','#','#','#'},{'#','.','.','T','#','.','.','#'},{'#','.','.','.','#','B','.','#'},{'#','.','.','.','.','.','.','#'},{'#','.','.','.','#','.','S','#'},{'#','.','.','#','#','#','#','#'} };
    check.checkInt(7, o.minPushBox(grid));

    grid = { {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'},
            {'#','.','.','.','.','.','.','.','.','.','.','.','#','#','#','#','#','#','#','#'},
            {'#','.','.','.','#','#','.','#','#','#','#','.','#','#','#','.','#','#','T','#'},
            {'#','.','.','.','.','.','.','#','.','#','.','.','#','#','#','.','#','#','.','#'},
            {'#','.','.','.','#','.','.','.','.','.','.','.','#','#','#','.','#','#','.','#'},
            {'#','.','#','.','.','.','.','.','.','.','.','.','#','#','#','.','#','#','.','#'},
            {'#','.','#','.','#','#','#','#','#','#','#','.','#','#','#','.','#','#','.','#'},
            {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
            {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
            {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#'},
            {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
            {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
            {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
            {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
            {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
            {'#','.','B','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
            {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
            {'#','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','#','.','.','#'},
            {'#','.','.','.','.','.','.','.','S','.','.','.','.','.','.','.','#','.','.','#'},
            {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#'} };
    check.checkInt(29, o.minPushBox(grid));

    grid = { {'#','.','.','#','#','#','#','#'},{'#','.','.','T','#','.','.','#'},{'#','.','.','.','#','B','.','#'},{'#','.','.','.','.','.','.','#'},{'#','.','.','.','#','.','S','#'},{'#','.','.','#','#','#','#','#'} };
    check.checkInt(7, o.minPushBox(grid));

    grid = {{'.','.','#','.','.','.','.','#'},{'.','B','.','.','.','.','.','#'},{'.','.','S','.','.','.','.','.'},{'.','#','.','.','.','.','.','.'},{'.','.','.','.','.','.','.','.'},{'.','.','.','T','.','.','.','.'},{'.','.','.','.','.','.','.','#'},{'.','#','.','.','.','.','.','.'}};
    check.checkInt(6, o.minPushBox(grid));
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
