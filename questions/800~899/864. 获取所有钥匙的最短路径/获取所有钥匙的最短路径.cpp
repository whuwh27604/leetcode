/* 获取所有钥匙的最短路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二维网格 grid。 "." 代表一个空房间， "#" 代表一堵墙， "@" 是起点，（"a", "b", ...）代表钥匙，（"A", "B", ...）代表锁。

我们从起点开始出发，一次移动是指向四个基本方向之一行走一个单位空间。我们不能在网格外面行走，也无法穿过一堵墙。如果途经一个钥匙，我们就把它捡起来。除非我们手里有对应的钥匙，否则无法通过锁。

假设 K 为钥匙/锁的个数，且满足 1 <= K <= 6，字母表中的前 K 个字母在网格中都有自己对应的一个小写和一个大写字母。换言之，每个锁有唯一对应的钥匙，每个钥匙也有唯一对应的锁。另外，代表钥匙和锁的字母互为大小写并按字母顺序排列。

返回获取所有钥匙所需要的移动的最少次数。如果无法获取所有钥匙，返回 -1 。

 

示例 1：

输入：["@.a.#","###.#","b.A.B"]
输出：8
示例 2：

输入：["@..aA","..B#.","....b"]
输出：6
 

提示：

1 <= grid.length <= 30
1 <= grid[0].length <= 30
grid[i][j] 只含有 '.', '#', '@', 'a'-'f' 以及 'A'-'F'
钥匙的数目范围是 [1, 6]，每个钥匙都对应一个不同的字母，正好打开一个对应的锁。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-path-to-get-all-keys
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int row = grid.size(), column = grid[0].size();
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };

        int sr = 0, sc = 0, allKeys = 0, steps = -1;
        findStart(grid, sr, sc, allKeys);

        queue<int> bfs;
        int node = encode(0, sr, sc);
        bfs.push(node);

        vector<bool> visited(1 << 22, false);
        visited[node] = true;

        while (!bfs.empty()) {
            int i, size = bfs.size();
            ++steps;

            for (i = 0; i < size; ++i) {
                node = bfs.front();
                bfs.pop();

                int r, c, keys;
                decode(node, keys, r, c);

                if (grid[r][c] >= 'a' && grid[r][c] <= 'f') {
                    keys |= (1 << (grid[r][c] - 'a'));  // 如果是钥匙，捡上
                    if (keys == allKeys) {
                        return steps;
                    }
                }

                for (int j = 0; j < 4; ++j) {
                    int nr = r + dr[j], nc = c + dc[j];
                    if (nr >= 0 && nr < row && nc >= 0 && nc < column) {
                        int nnode = encode(keys, nr, nc);
                        if (!visited[nnode] && reachable(grid[nr][nc], keys)) {
                            bfs.push(nnode);
                            visited[nnode] = true;
                        }
                    }
                }
            }
        }

        return -1;
    }

    void findStart(vector<string>& grid, int& sr, int& sc, int& allKeys) {
        for (int i = 0; i < (int)grid.size(); ++i) {
            for (int j = 0; j < (int)grid[0].size(); ++j) {
                if (grid[i][j] == '@') {
                    sr = i;
                    sc = j;
                    grid[i][j] = '.';  // 起点设置为空房间，后续不用再判断是否起点
                }
                else if (grid[i][j] >= 'a' && grid[i][j] <= 'f') {
                    allKeys |= (1 << (grid[i][j] - 'a'));
                }
            }
        }
    }

    int encode(int keys, int r, int c) {
        return (keys << 16) | (r << 8) | c;
    }

    void decode(int node, int& keys, int& r, int& c) {
        keys = node >> 16;
        r = (node & 0xff00) >> 8;
        c = node & 0xff;
    }

    bool reachable(char c, int keys) {
        return (c == '.')  // 空房间
            || (c >= 'a' && c <= 'f')  // 钥匙
            || (c >= 'A' && c <= 'F' && ((keys & (1 << (c - 'A'))) != 0));  // 锁，有钥匙
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> grid = { "@.a.#","###.#","b.A.B" };
    check.checkInt(8, o.shortestPathAllKeys(grid));
    
    grid = { "@..aA","..B#.","....b" };
    check.checkInt(6, o.shortestPathAllKeys(grid));

    grid = { "@...a",".###A","b.BCc" };
    check.checkInt(10, o.shortestPathAllKeys(grid));

    grid = { "@...a",".###A","b.BcC" };
    check.checkInt(13, o.shortestPathAllKeys(grid));

    grid = { "@..c.","BD.#C","a.Adb" };
    check.checkInt(16, o.shortestPathAllKeys(grid));

    grid = { "a@A" };
    check.checkInt(1, o.shortestPathAllKeys(grid));

    grid = { "@aBbA" };
    check.checkInt(-1, o.shortestPathAllKeys(grid));

    grid = { "bA@aB" };
    check.checkInt(4, o.shortestPathAllKeys(grid));

    grid = { "#..#.#.#..#.#.#.....#......#..",".#.......#....#A.....#.#......","#....#.....#.........#........","...#.#.........#..@....#....#.",".#.#.##...#.........##....#..#","..........#..#..###....##..#.#",".......#......#...#...#.....c#",".#...#.##......#...#.###...#..","..........##...#.......#......","#...#.........a#....#.#.##....","..#..#...#...#..#....#.....##.","..........#...#.##............","...#....#..#.........#..D.....","....#E.#....##................","...........##.#.......#.#....#","...#..#...#.#............#e...","..#####....#.#...........##..#","##......##......#.#...#..#.#..",".#F.......#..##.......#....#..","............#....#..#..#...#..",".............#...#f...#..##...","....#..#...##.........#..#..#.",".....#.....##.###..##.#......#",".#..#.#...#.....#........###..",".....#.#...#...#.....#.....#..","##.....#....B.....#..#b.......",".####....##..#.##..d.#......#.","..#.....#....##........##...##","...#...#...C..#..#....#.......","#.....##.....#.#......#......." };
    check.checkInt(70, o.shortestPathAllKeys(grid));
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
