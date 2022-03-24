/* 最大化网格幸福感.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你四个整数 m、n、introvertsCount 和 extrovertsCount 。有一个 m x n 网格，和两种类型的人：内向的人和外向的人。总共有 introvertsCount 个内向的人和 extrovertsCount 个外向的人。

请你决定网格中应当居住多少人，并为每个人分配一个网格单元。 注意，不必 让所有人都生活在网格中。

每个人的 幸福感 计算如下：

内向的人 开始 时有 120 个幸福感，但每存在一个邻居（内向的或外向的）他都会 失去  30 个幸福感。
外向的人 开始 时有 40 个幸福感，每存在一个邻居（内向的或外向的）他都会 得到  20 个幸福感。
邻居是指居住在一个人所在单元的上、下、左、右四个直接相邻的单元中的其他人。

网格幸福感 是每个人幸福感的 总和 。 返回 最大可能的网格幸福感 。

 

示例 1：


输入：m = 2, n = 3, introvertsCount = 1, extrovertsCount = 2
输出：240
解释：假设网格坐标 (row, column) 从 1 开始编号。
将内向的人放置在单元 (1,1) ，将外向的人放置在单元 (1,3) 和 (2,3) 。
- 位于 (1,1) 的内向的人的幸福感：120（初始幸福感）- (0 * 30)（0 位邻居）= 120
- 位于 (1,3) 的外向的人的幸福感：40（初始幸福感）+ (1 * 20)（1 位邻居）= 60
- 位于 (2,3) 的外向的人的幸福感：40（初始幸福感）+ (1 * 20)（1 位邻居）= 60
网格幸福感为：120 + 60 + 60 = 240
上图展示该示例对应网格中每个人的幸福感。内向的人在浅绿色单元中，而外向的人在浅紫色单元中。
示例 2：

输入：m = 3, n = 1, introvertsCount = 2, extrovertsCount = 1
输出：260
解释：将内向的人放置在单元 (1,1) 和 (3,1) ，将外向的人放置在单元 (2,1) 。
- 位于 (1,1) 的内向的人的幸福感：120（初始幸福感）- (1 * 30)（1 位邻居）= 90
- 位于 (2,1) 的外向的人的幸福感：40（初始幸福感）+ (2 * 20)（2 位邻居）= 80
- 位于 (3,1) 的内向的人的幸福感：120（初始幸福感）- (1 * 30)（1 位邻居）= 90
网格幸福感为 90 + 80 + 90 = 260
示例 3：

输入：m = 2, n = 2, introvertsCount = 4, extrovertsCount = 0
输出：240
 

提示：

1 <= m, n <= 5
0 <= introvertsCount, extrovertsCount <= min(m * n, 6)

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximize-grid-happiness
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        int maxMask = (int)pow(3, n);
        int happiess[3][3] = { {0,0,0},{0,-60,-10},{0,-10,40} };
        introvertsCount += 1, extrovertsCount += 1;

        // dp[grid][count][mask]表示从grid位置开始到末尾，有count个人，它前面（左侧、上面）n个位置的状态压缩为mask能够得到的最大分数。因为要执行dp[grid + 1]，所以grid多申请一个
        vector<vector<vector<int>>> dp(m * n + 1, vector<vector<int>>(introvertsCount * extrovertsCount, vector<int>(maxMask, 0)));

        for (int grid = m * n - 1; grid >= 0; --grid) {
            int column = grid % n;

            for (int count = 1; count < introvertsCount * extrovertsCount; ++count) {
                int introverts = count / extrovertsCount, extroverts = count % extrovertsCount;

                for (int mask = 0; mask < maxMask; ++mask) {  // grid - 1到grid - n连续n个位置的状态压缩为mask，grid - 1在最低位，grid - n在最高位
                    int state1 = mask % 3, stateN = mask * 3 / maxMask;  // state1是grid - 1位置的状态，它在grid左边；stateN是grid - n位置的状态，它在grid上面
                    int prevMask = mask * 3 % maxMask;  // grid + 1前面n个位置的mask，grid位置状态是0，表示没有人

                    dp[grid][count][mask] = dp[grid + 1][count][prevMask];  // grid位置不放人，那么grid + 1前面n个位置的mask就是prevMask

                    if (introverts > 0) {
                        // 放一个introvert可以得到120分，当他不在第0列时，和左边的人可以额外得到happiess[1][state1]分，和上面的人可以额外得到happiess[1][stateN]分
                        int diff = 120 + (column == 0 ? 0 : happiess[1][state1]) + happiess[1][stateN];
                        // grid位置放一个introvert，那么grid + 1前面n个位置的mask是prevMask + 1
                        dp[grid][count][mask] = max(dp[grid][count][mask], diff + dp[grid + 1][(introverts - 1) * extrovertsCount + extroverts][prevMask + 1]);
                    }

                    if (extroverts > 0) {
                        // 放一个extrovert可以得到40分，当他不在第0列时，和左边的人可以额外得到happiess[2][state1]分，和上面的人可以额外得到happiess[2][stateN]分
                        int diff = 40 + (column == 0 ? 0 : happiess[2][state1]) + happiess[2][stateN];
                        // grid位置放一个extrovert，那么grid + 1前面n个位置的mask是prevMask + 2
                        dp[grid][count][mask] = max(dp[grid][count][mask], diff + dp[grid + 1][count - 1][prevMask + 2]);
                    }
                }
            }
        }

        return dp[0][introvertsCount * extrovertsCount - 1][0];  // 在0位置，可以放introvertsCount + extrovertsCount个人，前面没有任何人可以得到的最大分数
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(240, o.getMaxGridHappiness(2, 3, 1, 2));
    check.checkInt(260, o.getMaxGridHappiness(3, 1, 2, 1));
    check.checkInt(240, o.getMaxGridHappiness(2, 2, 4, 0));
    check.checkInt(1240, o.getMaxGridHappiness(5, 5, 6, 6));
    check.checkInt(0, o.getMaxGridHappiness(1, 1, 0, 0));
    check.checkInt(120, o.getMaxGridHappiness(1, 1, 1, 1));
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
