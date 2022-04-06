/* 覆盖.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你有一块棋盘，棋盘上有一些格子已经坏掉了。你还有无穷块大小为1 * 2的多米诺骨牌，你想把这些骨牌不重叠地覆盖在完好的格子上，请找出你最多能在棋盘上放多少块骨牌？这些骨牌可以横着或者竖着放。

 

输入：n, m代表棋盘的大小；broken是一个b * 2的二维数组，其中每个元素代表棋盘上每一个坏掉的格子的位置。

输出：一个整数，代表最多能在棋盘上放的骨牌数。

 

示例 1：

输入：n = 2, m = 3, broken = [[1, 0], [1, 1]]
输出：2
解释：我们最多可以放两块骨牌：[[0, 0], [0, 1]]以及[[0, 2], [1, 2]]。（见下图）


 

示例 2：

输入：n = 3, m = 3, broken = []
输出：4
解释：下图是其中一种可行的摆放方式


 

限制：

1 <= n <= 8
1 <= m <= 8
0 <= b <= n * m

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/broken-board-dominoes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int domino(int n, int m, vector<vector<int>>& broken) {
        vector<vector<int>> unavailable(n, vector<int>(m, 0));
        int maxMask = (1 << m), allMask = maxMask - 1, left = 1, up = (1 << (m - 1));
        vector<vector<int>> dp(n * m + 1, vector<int>(maxMask, 0));

        getUnavailable(broken, unavailable);
        int chosable = initChosable(unavailable, n, m);

        for (int pos = n * m - 1; pos >= 0; --pos) {
            int r = pos / m, c = pos % m;
            chosable >>= 1;  // 将pos位置移出

            if (pos >= m && unavailable[(pos - m) / m][(pos - m) % m] == 0) {  // pos - n位置可选，移入chosable
                chosable |= up;
            }

            for (int mask = chosable; mask != 0; mask = (mask - 1) & chosable) {  // 枚举chosable所有的子集
                dp[pos][mask] = dp[pos + 1][(mask << 1) & allMask];  // pos位置不放骨牌

                if (c != m - 1 && unavailable[r][c] == 0 && unavailable[r][c + 1] == 0) {  // 横着放一个骨牌，占pos、pos + 1位置
                    dp[pos][mask] = max(dp[pos][mask], 1 + dp[pos + 2][((mask << 2) & allMask) | 0b11]);
                }

                if ((mask & up) == 0 && r > 0 && unavailable[r][c] == 0 && unavailable[r - 1][c] == 0) {  // up位置没占用，竖着放一个骨牌，占pos、pos - n位置
                    dp[pos][mask] = max(dp[pos][mask], 1 + dp[pos + 1][((mask << 1) & allMask) | 1]);
                }
            }

            dp[pos][0] = dp[pos + 1][0];

            if (c != m - 1 && unavailable[r][c] == 0 && unavailable[r][c + 1] == 0) {
                dp[pos][0] = max(dp[pos][0], 1 + dp[pos + 2][0b11]);
            }

            if (r > 0 && unavailable[r][c] == 0 && unavailable[r - 1][c] == 0) {
                dp[pos][0] = max(dp[pos][0], 1 + dp[pos + 1][1]);
            }
        }

        return dp[0][0];
    }

    void getUnavailable(vector<vector<int>>& broken, vector<vector<int>>& unavailable) {
        for (auto& pos : broken) {
            unavailable[pos[0]][pos[1]] = 1;
        }
    }

    int initChosable(vector<vector<int>>& unavailable, int n, int m) {  // board[n - 1][m - 1]到board[n - 1][0]可选的位置
        int chosable = 0;

        for (int c = 0; c < m; ++c) {
            chosable = (chosable << 1) | (unavailable[n - 1][c] == 1 ? 0 : 1);
        }

        return chosable;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> broken = { {1,0},{1,1} };
    check.checkInt(2, o.domino(2, 3, broken));

    broken = {};
    check.checkInt(4, o.domino(3, 3, broken));
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
