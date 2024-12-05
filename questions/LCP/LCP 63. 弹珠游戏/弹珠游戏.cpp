/* 弹珠游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
欢迎各位来到「力扣嘉年华」，接下来将为各位介绍在活动中广受好评的弹珠游戏。

N*M 大小的弹珠盘的初始状态信息记录于一维字符串型数组 plate 中，数组中的每个元素为仅由 "O"、"W"、"E"、"." 组成的字符串。其中：

"O" 表示弹珠洞（弹珠到达后会落入洞中，并停止前进）；
"W" 表示逆时针转向器（弹珠经过时方向将逆时针旋转 90 度）；
"E" 表示顺时针转向器（弹珠经过时方向将顺时针旋转 90 度）；
"." 表示空白区域（弹珠可通行）。
游戏规则要求仅能在边缘位置的 空白区域 处（弹珠盘的四角除外）沿 与边缘垂直 的方向打入弹珠，并且打入后的每颗弹珠最多能 前进 num 步。请返回符合上述要求且可以使弹珠最终入洞的所有打入位置。你可以 按任意顺序 返回答案。

注意：

若弹珠已到达弹珠盘边缘并且仍沿着出界方向继续前进，则将直接出界。
示例 1：

输入： num = 4 plate = ["..E.",".EOW","..W."]

输出：[[2,1]]

解释： 在 [2,1] 处打入弹珠，弹珠前进 1 步后遇到转向器，前进方向顺时针旋转 90 度，再前进 1 步进入洞中。b054955158a99167b8d51da0e22a54da.gif

示例 2：

输入： num = 5 plate = [".....","..E..",".WO..","....."]

输出：[[0,1],[1,0],[2,4],[3,2]]

解释： 在 [0,1] 处打入弹珠，弹珠前进 2 步，遇到转向器后前进方向逆时针旋转 90 度，再前进 1 步进入洞中。 在 [1,0] 处打入弹珠，弹珠前进 2 步，遇到转向器后前进方向顺时针旋转 90 度，再前进 1 步进入洞中。 在 [2,4] 处打入弹珠，弹珠前进 2 步后进入洞中。 在 [3,2] 处打入弹珠，弹珠前进 1 步后进入洞中。b44e9963239ae368badf3d00b7563087.gif

示例 3：

输入： num = 3 plate = [".....","....O","....O","....."]

输出：[]

解释： 由于弹珠被击中后只能前进 3 步，且不能在弹珠洞和弹珠盘四角打入弹珠，故不存在能让弹珠入洞的打入位置。

提示：

1 <= num <= 10^6
1 <= plate.length, plate[i].length <= 1000
plate[i][j] 仅包含 "O"、"W"、"E"、"."
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> ballGame(int num, vector<string>& plate) {
        int row = (int)plate.size(), column = (int)plate[0].size();
        vector<vector<int>> ans;

        for (int r = 1; r < row - 1; ++r) {
            if (plate[r][0] == '.' && reachable(plate, num, r, 0, 0)) {
                ans.push_back({ r,0 });
            }
            if (plate[r][column - 1] == '.' && reachable(plate, num, r, column - 1, 2)) {
                ans.push_back({ r,column - 1 });
            }
        }

        for (int c = 1; c < column - 1; ++c) {
            if (plate[0][c] == '.' && reachable(plate, num, 0, c, 1)) {
                ans.push_back({ 0,c });
            }
            if (plate[row - 1][c] == '.' && reachable(plate, num, row - 1, c, 3)) {
                ans.push_back({ row - 1,c });
            }
        }

        return ans;
    }

    bool reachable(vector<string>& plate, int num, int r, int c, int dir) {
        int row = (int)plate.size(), column = (int)plate[0].size();
        int dr[4] = { 0, 1, 0, -1 }, dc[4] = { 1, 0, -1, 0 };

        for (int step = 0; step <= num && r >= 0 && r < row && c >= 0 && c < column; ++step) {
            if (plate[r][c] == 'O') {
                return true;
            }

            if (plate[r][c] == 'E') {
                dir = (dir + 1) % 4;
            }
            else if (plate[r][c] == 'W') {
                dir = (dir + 3) % 4;              
            }

            r += dr[dir];
            c += dc[dir];
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> plate = { "E...W..WW",".E...O...","...WO...W","..OWW.O..",".W.WO.W.E","O..O.W...",".OO...W..","..EW.WEE." };
    vector<vector<int>> actual = o.ballGame(50, plate);
    vector<vector<int>> expected = { {0,2},{0,3},{0,5},{0,6},{1,0},{1,8},{3,0},{3,8},{4,0},{6,0},{7,1},{7,4} };
    check.checkIntVectorRandomOrderVector(expected, actual);

    plate = { ".....","..O..","....." };
    actual = o.ballGame(1, plate);
    expected = { {0,2},{2,2} };
    check.checkIntVectorRandomOrderVector(expected, actual);

    plate = { "....",".EE.","O.E.","...." };
    actual = o.ballGame(6, plate);
    expected = { {3,1} };
    check.checkIntVectorRandomOrderVector(expected, actual);

    plate = { "..E.",".EOW","..W." };
    actual = o.ballGame(4, plate);
    expected = { {2,1} };
    check.checkIntVectorRandomOrderVector(expected, actual);

    plate = { ".....","..E..",".WO..","....." };
    actual = o.ballGame(5, plate);
    expected = { {0,1},{1,0},{2,4},{3,2} };
    check.checkIntVectorRandomOrderVector(expected, actual);

    plate = { ".....","....O","....O","....." };
    actual = o.ballGame(3, plate);
    expected = {};
    check.checkIntVectorRandomOrderVector(expected, actual);

    plate = { ".O." };
    actual = o.ballGame(1, plate);
    expected = {};
    check.checkIntVectorRandomOrderVector(expected, actual);

    plate = { "...",".O.","..." };
    actual = o.ballGame(1, plate);
    expected = { {0,1},{1,0},{1,2},{2,1} };
    check.checkIntVectorRandomOrderVector(expected, actual);

    plate = { "....",".O..","....","...." };
    actual = o.ballGame(1, plate);
    expected = { {0,1},{1,0} };
    check.checkIntVectorRandomOrderVector(expected, actual);
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
