/* 隔离病毒.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
病毒扩散得很快，现在你的任务是尽可能地通过安装防火墙来隔离病毒。

假设世界由 m x n 的二维矩阵 isInfected 组成， isInfected[i][j] == 0 表示该区域未感染病毒，而  isInfected[i][j] == 1 表示该区域已感染病毒。可以在任意 2 个相邻单元之间的共享边界上安装一个防火墙（并且只有一个防火墙）。

每天晚上，病毒会从被感染区域向相邻未感染区域扩散，除非被防火墙隔离。现由于资源有限，每天你只能安装一系列防火墙来隔离其中一个被病毒感染的区域（一个区域或连续的一片区域），且该感染区域对未感染区域的威胁最大且 保证唯一 。

你需要努力使得最后有部分区域不被病毒感染，如果可以成功，那么返回需要使用的防火墙个数; 如果无法实现，则返回在世界被病毒全部感染时已安装的防火墙个数。

 

示例 1：



输入: isInfected = [[0,1,0,0,0,0,0,1],[0,1,0,0,0,0,0,1],[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0]]
输出: 10
解释:一共有两块被病毒感染的区域。
在第一天，添加 5 墙隔离病毒区域的左侧。病毒传播后的状态是:

第二天，在右侧添加 5 个墙来隔离病毒区域。此时病毒已经被完全控制住了。

示例 2：



输入: isInfected = [[1,1,1],[1,0,1],[1,1,1]]
输出: 4
解释: 虽然只保存了一个小区域，但却有四面墙。
注意，防火墙只建立在两个不同区域的共享边界上。
示例 3:

输入: isInfected = [[1,1,1,0,0,0,0,0,0],[1,0,1,0,1,1,1,1,1],[1,1,1,0,0,0,0,0,0]]
输出: 13
解释: 在隔离右边感染区域后，隔离左边病毒区域只需要 2 个防火墙。
 

提示:

m == isInfected.length
n == isInfected[i].length
1 <= m, n <= 50
isInfected[i][j] is either 0 or 1
在整个描述的过程中，总有一个相邻的病毒区域，它将在下一轮 严格地感染更多未受污染的方块 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/contain-virus
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int containVirus(vector<vector<int>>& isInfected) {  // 0：未感染； 1：已感染； 2：被围起来的感染区
        int r, c, row = isInfected.size(), column = isInfected[0].size();
        vector<vector<bool>> visited(row, vector<bool>(column, false));
        int rRoot = -1, cRoot = -1, maxThreatenCells = 0;

        for (r = 0; r < row; ++r) {
            for (c = 0; c < column; ++c) {
                if (isInfected[r][c] == 1) {
                    unordered_set<int> threatenCells;
                    getMostThreaten(r, c, isInfected, visited, threatenCells);

                    if ((int)threatenCells.size() > maxThreatenCells) {
                        maxThreatenCells = threatenCells.size();
                        rRoot = r;
                        cRoot = c;
                    }
                }
            }
        }

        if (maxThreatenCells == 0) {
            return 0;
        }

        int walls = installWalls(rRoot, cRoot, isInfected);
        spread(isInfected);

        return walls + containVirus(isInfected);
    }

    void getMostThreaten(int r, int c, vector<vector<int>>& isInfected, vector<vector<bool>>& visited, unordered_set<int>& threatenCells) {
        int row = isInfected.size(), column = isInfected[0].size();
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        visited[r][c] = true;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];

            if (nr >= 0 && nr < row && nc >= 0 && nc < column) {
                if (isInfected[nr][nc] == 0) {
                    threatenCells.insert((nr << 8) | nc);
                }
                else if (isInfected[nr][nc] == 1 && !visited[nr][nc]) {
                    getMostThreaten(nr, nc, isInfected, visited, threatenCells);
                }
            }
        }
    }

    int installWalls(int r, int c, vector<vector<int>>& isInfected) {
        int row = isInfected.size(), column = isInfected[0].size(), walls = 0;
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        isInfected[r][c] = 2;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];

            if (nr >= 0 && nr < row && nc >= 0 && nc < column) {
                if (isInfected[nr][nc] == 0) {
                    ++walls;
                }
                else if (isInfected[nr][nc] == 1) {
                    walls += installWalls(nr, nc, isInfected);
                }
            }
        }

        return walls;
    }

    void spread(vector<vector<int>>& isInfected) {
        int r, c, row = isInfected.size(), column = isInfected[0].size();
        int dr[4] = { 0,1,0,-1 }, dc[4] = { 1,0,-1,0 };
        queue<pair<int, int>> q;

        for (r = 0; r < row; ++r) {
            for (c = 0; c < column; ++c) {
                if (isInfected[r][c] == 1) {
                    q.push({ r,c });
                }
            }
        }

        while (!q.empty()) {
            r = q.front().first, c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];

                if (nr >= 0 && nr < row && nc >= 0 && nc < column && isInfected[nr][nc] == 0) {
                    isInfected[nr][nc] = 1;
                }
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> isInfected = { {0,1,0,0,0,0,0,1},{0,1,0,0,0,0,0,1},{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0} };
    check.checkInt(10, o.containVirus(isInfected));

    isInfected = { {1,1,1},{1,0,1},{1,1,1} };
    check.checkInt(4, o.containVirus(isInfected));

    isInfected = { {1,1,1,0,0,0,0,0,0},{1,0,1,0,1,1,1,1,1},{1,1,1,0,0,0,0,0,0} };
    check.checkInt(13, o.containVirus(isInfected));

    isInfected = { {0,1,0,1,1,1,1,1,1,0},{0,0,0,1,0,0,0,0,0,0},{0,0,1,1,1,0,0,0,1,0},{0,0,0,1,1,0,0,1,1,0},{0,1,0,0,1,0,1,1,0,1},{0,0,0,1,0,1,0,1,1,1},{0,1,0,0,1,0,0,1,1,0},{0,1,0,1,0,0,0,1,1,0},{0,1,1,0,0,1,1,0,0,1},{1,0,1,1,0,1,0,1,0,1} };
    check.checkInt(38,o.containVirus(isInfected));
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
