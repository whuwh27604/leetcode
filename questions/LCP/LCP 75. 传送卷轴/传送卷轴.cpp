/* 传送卷轴.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
随着不断的深入，小扣来到了守护者之森寻找的魔法水晶。首先，他必须先通过守护者的考验。

考验的区域是一个正方形的迷宫，maze[i][j] 表示在迷宫 i 行 j 列的地形：

若为 . ，表示可以到达的空地；
若为 # ，表示不可到达的墙壁；
若为 S ，表示小扣的初始位置；
若为 T ，表示魔法水晶的位置。
小扣每次可以向 上、下、左、右 相邻的位置移动一格。而守护者拥有一份「传送魔法卷轴」，使用规则如下：

魔法需要在小扣位于 空地 时才能释放，发动后卷轴消失；；
发动后，小扣会被传送到水平或者竖直的镜像位置，且目标位置不得为墙壁(如下图所示)；image.png
在使用卷轴后，小扣将被「附加负面效果」，因此小扣需要尽可能缩短传送后到达魔法水晶的距离。而守护者的目标是阻止小扣到达魔法水晶的位置；如果无法阻止，则尽可能 增加 小扣传送后到达魔法水晶的距离。 假设小扣和守护者都按最优策略行事，返回小扣需要在 「附加负面效果」的情况下 最少 移动多少次才能到达魔法水晶。如果无法到达，返回 -1。

注意：

守护者可以不使用卷轴；
传送后的镜像位置可能与原位置相同。
示例 1：

输入：maze = [".....","##S..","...#.","T.#..","###.."]

输出：7

解释：如下图所示： 守护者释放魔法的两个最佳的位置为 [2,0] 或 [3,1]： 若小扣经过 [2,0]，守护者在该位置释放魔法， 小扣被传送至 [2,4] 处且加上负面效果，此时小扣还需要移动 7 次才能到达魔法水晶； 若小扣经过 [3,1]，守护者在该位置释放魔法， 小扣被传送至 [3,3] 处且加上负面效果，此时小扣还需要移动 9 次才能到达魔法水晶； 因此小扣负面效果下最少需要移动 7 次才能到达魔法水晶。image.png

示例 2：

输入：maze = [".#..","..##",".#S.",".#.T"]

输出：-1

解释：如下图所示。 若小扣向下移动至 [3,2]，守护者使其传送至 [0,2]，小扣将无法到达魔法水晶； 若小扣向右移动至 [2,3]，守护者使其传送至 [2,0]，小扣将无法到达魔法水晶；image.png

示例 3：

输入：maze = ["S###.","..###","#..##","##..#","###.T"]

输出：5

解释：如下图所示： 守护者需要小扣在空地才能释放，因此初始无法将其从 [0,0] 传送至 [0,4]; 当小扣移动至 [2,1] 时，释放卷轴将其传送至水平方向的镜像位置 [2,1]（为原位置） 而后小扣需要移动 5 次到达魔法水晶image.png

提示：

4 <= maze.length == maze[i].length <= 200
maze[i][j] 仅包含 "."、"#"、"S"、"T"
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int r;
    int c;
    int negDist;

    Node() : r(0), c(0), negDist(0) {}
    Node(int x, int y, int dist) : r(x), c(y), negDist(dist) {}

    bool operator<(const Node& o) const {
        return negDist > o.negDist;  // 优先队列按negDist从小到大排序
    }
};

class Solution {
public:
    int challengeOfTheKeeper(vector<string>& maze) {
        int n = (int)maze.size(), rs = 0, cs = 0, rt = 0, ct = 0;
        getTarget(maze, n, rs, cs, rt, ct);

        vector<vector<int>> distance(n, vector<int>(n, inf));
        getDistance(maze, n, rt, ct, distance);

        vector<vector<int>> negDist(n, vector<int>(n, 0));  // 如果无法施加魔法，附加负面效果距离为0
        getNegDist(maze, n, distance, negDist);

        return getMaxNegDist(maze, n, rs, cs, rt, ct, negDist);
    }

    void getTarget(vector<string>& maze, int n, int& rs, int& cs, int& rt, int& ct) {
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (maze[r][c] == 'S') {
                    rs = r, cs = c;
                }
                else if (maze[r][c] == 'T') {
                    rt = r, ct = c;
                }
            }
        }
    }

    void getDistance(vector<string>& maze, int n, int rt, int ct, vector<vector<int>>& distance) {
        queue<pair<int, int>> nodes;
        nodes.push({ rt,ct });
        int dis = 0;
        distance[rt][ct] = dis;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[rt][ct] = true;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };

        while (!nodes.empty()) {
            int size = (int)nodes.size();
            ++dis;

            for (int i = 0; i < size; ++i) {
                int r = nodes.front().first, c = nodes.front().second;
                nodes.pop();

                for (int j = 0; j < 4; ++j) {
                    int nr = r + dr[j], nc = c + dc[j];

                    if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc]) {
                        continue;
                    }

                    visited[nr][nc] = true;

                    if (maze[nr][nc] != '#') {
                        distance[nr][nc] = dis;
                        nodes.push({ nr,nc });
                    }
                }
            }
        }
    }

    void getNegDist(vector<string>& maze, int n, vector<vector<int>>& distance, vector<vector<int>>& negDist) {
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (maze[r][c] == 'T') {  // 已经到达终点，再施加魔法没有意义
                    continue;
                }

                if (maze[r][n - 1 - c] != '#') {
                    negDist[r][c] = distance[r][n - 1 - c];
                }
                if (maze[n - 1 - r][c] != '#') {
                    negDist[r][c] = max(negDist[r][c], distance[n - 1 - r][c]);
                }
            }
        }
    }

    int getMaxNegDist(vector<string>& maze, int n, int rs, int cs, int rt, int ct, vector<vector<int>>& negDist) {
        priority_queue<Node> nodes;
        nodes.push(Node(rs, cs, 0));
        vector<vector<bool>> visited(n, vector<bool>(n, false));  // 小扣先手移动，从negDist的角度来说，起点还没有访问到
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        int maxNegDist = 0;

        while (!nodes.empty()) {
            Node node = nodes.top();  // 小扣的博弈逻辑是每次贪心选择negDist最小的点移动
            nodes.pop();
            maxNegDist = max(maxNegDist, node.negDist);  // 守护者的博弈逻辑是在小扣移动时，选择最大的negDist施加魔法

            for (int i = 0; i < 4; ++i) {
                int nr = node.r + dr[i], nc = node.c + dc[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n || visited[nr][nc] || maze[nr][nc] == '#' || negDist[nr][nc] == inf) {
                    continue;  // 如果移动到一个点会导致被转移到死路，那么不要移动到该点
                }

                if (nr == rt && nc == ct) {
                    return maxNegDist;
                }

                visited[nr][nc] = true;
                nodes.push(Node(nr, nc, negDist[nr][nc]));
            }
        }

        return -1;
    }
    
    int inf = INT_MAX / 2;
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> maze = { "#ST#","####","####","####" };
    check.checkInt(0, o.challengeOfTheKeeper(maze));

    maze = { ".ST.","####","####","####" };
    check.checkInt(0, o.challengeOfTheKeeper(maze));

    maze = { ".....","##S..","...#.","T.#..","###.." };
    check.checkInt(7, o.challengeOfTheKeeper(maze));

    maze = { ".#..","..##",".#S.",".#.T" };
    check.checkInt(-1, o.challengeOfTheKeeper(maze));

    maze = { "S###.","..###","#..##","##..#","###.T" };
    check.checkInt(5, o.challengeOfTheKeeper(maze));

    maze = { "##S##", "##.##", "##T##", "##.##", "##.##" };
    check.checkInt(1, o.challengeOfTheKeeper(maze));
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
