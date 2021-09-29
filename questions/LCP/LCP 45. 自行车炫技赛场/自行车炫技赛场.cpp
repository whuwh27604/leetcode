/* 自行车炫技赛场.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
「力扣挑战赛」中 N*M 大小的自行车炫技赛场的场地由一片连绵起伏的上下坡组成，场地的高度值记录于二维数组 terrain 中，场地的减速值记录于二维数组 obstacle 中。

若选手骑着自行车从高度为 h1 且减速值为 o1 的位置到高度为 h2 且减速值为 o2 的相邻位置（上下左右四个方向），速度变化值为 h1-h2-o2（负值减速，正值增速）。
选手初始位于坐标 position 处且初始速度为 1，请问选手可以刚好到其他哪些位置时速度依旧为 1。请以二维数组形式返回这些位置。若有多个位置则按行坐标升序排列，若有多个位置行坐标相同则按列坐标升序排列。

注意： 骑行过程中速度不能为零或负值

示例 1：

输入：position = [0,0], terrain = [[0,0],[0,0]], obstacle = [[0,0],[0,0]]

输出：[[0,1],[1,0],[1,1]]

解释：
由于当前场地属于平地，根据上面的规则，选手从[0,0]的位置出发都能刚好在其他处的位置速度为 1。

示例 2：

输入：position = [1,1], terrain = [[5,0],[0,6]], obstacle = [[0,6],[7,0]]

输出：[[0,1]]

解释：
选手从 [1,1] 处的位置出发，到 [0,1] 处的位置时恰好速度为 1。

提示：

n == terrain.length == obstacle.length
m == terrain[i].length == obstacle[i].length
1 <= n <= 100
1 <= m <= 100
0 <= terrain[i][j], obstacle[i][j] <= 100
position.length == 2
0 <= position[0] < n
0 <= position[1] < m

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kplEvH
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> bicycleYard(vector<int>& position, vector<vector<int>>& terrain, vector<vector<int>>& obstacle) {
        int n = terrain.size(), m = terrain[0].size(), maxSpeed = 101;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(maxSpeed + 1, false)));
        vector<vector<int>> ans;
        queue<int> bfs;
        bfs.push((position[0] << 16) | (position[1] << 8) | 1);
        visited[position[0]][position[1]][1] = true;

        while (!bfs.empty()) {
            int r = bfs.front() >> 16, c = (bfs.front() >> 8) & 0xff, speed = bfs.front() & 0xff;
            bfs.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                    continue;
                }

                int nspeed = speed + terrain[r][c] - terrain[nr][nc] - obstacle[nr][nc];
                if (nspeed > 0 && !visited[nr][nc][nspeed]) {
                    visited[nr][nc][nspeed] = true;
                    bfs.push((nr << 16) | (nc << 8) | nspeed);

                    if (nspeed == 1) {
                        ans.push_back({ nr, nc });
                    }
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> position = { 0,0 };
    vector<vector<int>> terrain = { {0,0},{0,0} };
    vector<vector<int>> obstacle = { {0,0},{0,0} };
    vector<vector<int>> actual = o.bicycleYard(position, terrain, obstacle);
    vector<vector<int>> expected = { {0,1},{1,0},{1,1} };
    check.checkIntVectorVector(expected, actual);

    position = { 1,1 };
    terrain = { {5,0},{0,6} };
    obstacle = { {0,6},{7,0} };
    actual = o.bicycleYard(position, terrain, obstacle);
    expected = { {0,1} };
    check.checkIntVectorVector(expected, actual);

    position = { 0,0 };
    terrain = { {5} };
    obstacle = { {0} };
    actual = o.bicycleYard(position, terrain, obstacle);
    expected = {  };
    check.checkIntVectorVector(expected, actual);
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
