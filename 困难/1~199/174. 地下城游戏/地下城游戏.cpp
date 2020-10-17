/* 地下城游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N 个房间组成的二维网格。我们英勇的骑士（K）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。

骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。

有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。

为了尽快到达公主，骑士决定每次只向右或向下移动一步。

 

编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。

例如，考虑到如下布局的地下城，如果骑士遵循最佳路径 右 -> 右 -> 下 -> 下，则骑士的初始健康点数至少为 7。

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)
 

说明:

骑士的健康点数没有上限。

任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/dungeon-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon[0].empty()) {
            return 1;
        }

        /* 从右下往左上动态规划，令dp[i][j]为从dungeon[i][j]位置出发需要的最少点数，则dp[i][j]=min(dp[i+1][j],dp[i][j+1])-dungeon[i][j] */
        int i, j, M = dungeon.size(), N = dungeon[0].size();
        vector<vector<long long>> dp(M + 1, vector<long long>(N + 1, LLONG_MAX));  // 运算过程中有整型溢出风险，尽量抢救一下
        dp[M - 1][N] = dp[M][N - 1] = 1;

        for (i = M - 1; i >= 0; i--) {
            for (j = N - 1; j >= 0; j--) {
                long long minDp = min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(minDp - dungeon[i][j], (long long)1);
            }
        }

        return (int)dp[0][0];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> dungeon = { {-2,-3,3},{-5,-10,1},{10,30,-5} };
    check.checkInt(7, o.calculateMinimumHP(dungeon));

    dungeon = {  };
    check.checkInt(1, o.calculateMinimumHP(dungeon));

    dungeon = { {} };
    check.checkInt(1, o.calculateMinimumHP(dungeon));

    dungeon = { {-2147483647} };
    check.checkInt(2147483648, o.calculateMinimumHP(dungeon));

    dungeon = { {1,0},{0,-2147483647} };
    check.checkInt(2147483647, o.calculateMinimumHP(dungeon));
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
