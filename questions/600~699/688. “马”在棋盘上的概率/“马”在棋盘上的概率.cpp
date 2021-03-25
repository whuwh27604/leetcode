/* “马”在棋盘上的概率.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
已知一个 NxN 的国际象棋棋盘，棋盘的行号和列号都是从 0 开始。即最左上角的格子记为 (0, 0)，最右下角的记为 (N-1, N-1)。 

现有一个 “马”（也译作 “骑士”）位于 (r, c) ，并打算进行 K 次移动。 

如下图所示，国际象棋的 “马” 每一步先沿水平或垂直方向移动 2 个格子，然后向与之相垂直的方向再移动 1 个格子，共有 8 个可选的位置。

 



 

现在 “马” 每一步都从可选的位置（包括棋盘外部的）中独立随机地选择一个进行移动，直到移动了 K 次或跳到了棋盘外面。

求移动结束后，“马” 仍留在棋盘上的概率。

 

示例：

输入: 3, 2, 0, 0
输出: 0.0625
解释:
输入的数据依次为 N, K, r, c
第 1 步时，有且只有 2 种走法令 “马” 可以留在棋盘上（跳到（1,2）或（2,1））。对于以上的两种情况，各自在第2步均有且只有2种走法令 “马” 仍然留在棋盘上。
所以 “马” 在结束后仍在棋盘上的概率为 0.0625。
 

注意：

N 的取值范围为 [1, 25]
K 的取值范围为 [0, 100]
开始时，“马” 总是位于棋盘上

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/knight-probability-in-chessboard
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp(N, vector<double>(N, 0));
        dp[r][c] = 1;
        int dr[8] = { 2, 2, 1, 1, -1, -1, -2, -2 };
        int dc[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };
        double probability = 0.0;

        for (; K > 0; K--) {
            vector<vector<double>> dpTmp(N, vector<double>(N, 0));

            for (int row = 0; row < N; row++) {
                for (int column = 0; column < N; column++) {
                    for (int k = 0; k < 8; k++) {
                        int nr = row + dr[k];
                        int nc = column + dc[k];
                        if (0 <= nr && nr < N && 0 <= nc && nc < N) {
                            dpTmp[nr][nc] += dp[row][column] / 8.0;
                        }
                    }
                }
            }

            dp = dpTmp;
        }

        for (auto oneRow : dp) {
            for (double x : oneRow) {
                probability += x;
            }
        }

        return probability;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkDouble(0.0625, o.knightProbability(3, 2, 0, 0));
    check.checkDouble(1, o.knightProbability(1, 0, 0, 0));
    check.checkDouble(0.047429, o.knightProbability(25, 100, 12, 12));
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
