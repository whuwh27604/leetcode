/* 最少侧跳次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个长度为 n 的 3 跑道道路 ，它总共包含 n + 1 个 点 ，编号为 0 到 n 。一只青蛙从 0 号点第二条跑道 出发 ，它想要跳到点 n 处。然而道路上可能有一些障碍。

给你一个长度为 n + 1 的数组 obstacles ，其中 obstacles[i] （取值范围从 0 到 3）表示在点 i 处的 obstacles[i] 跑道上有一个障碍。如果 obstacles[i] == 0 ，那么点 i 处没有障碍。任何一个点的三条跑道中 最多有一个 障碍。

比方说，如果 obstacles[2] == 1 ，那么说明在点 2 处跑道 1 有障碍。
这只青蛙从点 i 跳到点 i + 1 且跑道不变的前提是点 i + 1 的同一跑道上没有障碍。为了躲避障碍，这只青蛙也可以在 同一个 点处 侧跳 到 另外一条 跑道（这两条跑道可以不相邻），但前提是跳过去的跑道该点处没有障碍。

比方说，这只青蛙可以从点 3 处的跑道 3 跳到点 3 处的跑道 1 。
这只青蛙从点 0 处跑道 2 出发，并想到达点 n 处的 任一跑道 ，请你返回 最少侧跳次数 。

注意：点 0 处和点 n 处的任一跑道都不会有障碍。

 

示例 1：


输入：obstacles = [0,1,2,3,0]
输出：2
解释：最优方案如上图箭头所示。总共有 2 次侧跳（红色箭头）。
注意，这只青蛙只有当侧跳时才可以跳过障碍（如上图点 2 处所示）。
示例 2：


输入：obstacles = [0,1,1,3,3,0]
输出：0
解释：跑道 2 没有任何障碍，所以不需要任何侧跳。
示例 3：


输入：obstacles = [0,2,1,0,3,0]
输出：2
解释：最优方案如上图所示。总共有 2 次侧跳。
 

提示：

obstacles.length == n + 1
1 <= n <= 5 * 105
0 <= obstacles[i] <= 3
obstacles[0] == obstacles[n] == 0

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-sideway-jumps
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size(), inf = 1000000000;
        int dp1 = 1, dp2 = 0, dp3 = 1;

        for (int i = 1; i < n; ++i) {
            int tmp1 = obstacles[i] == 1 ? inf : min({ dp1, obstacles[i] == 2 ? inf : dp2 + 1, obstacles[i] == 3 ? inf : dp3 + 1 });
            int tmp2 = obstacles[i] == 2 ? inf : min({ obstacles[i] == 1 ? inf : dp1 + 1, dp2, obstacles[i] == 3 ? inf : dp3 + 1 });
            int tmp3 = obstacles[i] == 3 ? inf : min({ obstacles[i] == 1 ? inf : dp1 + 1, obstacles[i] == 2 ? inf : dp2 + 1, dp3 });
            dp1 = tmp1, dp2 = tmp2, dp3 = tmp3;
        }

        return min({ dp1, dp2, dp3 });
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> obstacles = { 0,1,2,3,0 };
    check.checkInt(2, o.minSideJumps(obstacles));

    obstacles = { 0,1,1,3,3,0 };
    check.checkInt(0, o.minSideJumps(obstacles));

    obstacles = { 0,2,1,0,3,0 };
    check.checkInt(2, o.minSideJumps(obstacles));

    obstacles = { 0,0 };
    check.checkInt(0, o.minSideJumps(obstacles));

    obstacles = { 0,2,0 };
    check.checkInt(1, o.minSideJumps(obstacles));

    obstacles = { 0,2,1,0,3,1,2,3,3,2,1,2,1,3,2,3,1,1,3,2,3,1,2,0 };
    check.checkInt(11, o.minSideJumps(obstacles));

    obstacles = { 0,2,1,0,3,1,2,3,3,2,1,2,1,3,2,3,1,1,3,2,3,1,2,2,1,0,3,1,2,3,3,2,1,2,1,3,2,3,1,1,3,2,3,1,2,2,1,0,3,1,2,3,3,2,1,2,1,3,2,3,1,1,3,2,3,1,2,0 };
    check.checkInt(31, o.minSideJumps(obstacles));
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
