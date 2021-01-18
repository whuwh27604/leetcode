/* 到家的最少跳跃次数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一只跳蚤的家在数轴上的位置 x 处。请你帮助它从位置 0 出发，到达它的家。

跳蚤跳跃的规则如下：

它可以 往前 跳恰好 a 个位置（即往右跳）。
它可以 往后 跳恰好 b 个位置（即往左跳）。
它不能 连续 往后跳 2 次。
它不能跳到任何 forbidden 数组中的位置。
跳蚤可以往前跳 超过 它的家的位置，但是它 不能跳到负整数 的位置。

给你一个整数数组 forbidden ，其中 forbidden[i] 是跳蚤不能跳到的位置，同时给你整数 a， b 和 x ，请你返回跳蚤到家的最少跳跃次数。如果没有恰好到达 x 的可行方案，请你返回 -1 。

 

示例 1：

输入：forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
输出：3
解释：往前跳 3 次（0 -> 3 -> 6 -> 9），跳蚤就到家了。
示例 2：

输入：forbidden = [8,3,16,6,12,20], a = 15, b = 13, x = 11
输出：-1
示例 3：

输入：forbidden = [1,6,2,14,5,17,4], a = 16, b = 9, x = 7
输出：2
解释：往前跳一次（0 -> 16），然后往回跳一次（16 -> 7），跳蚤就到家了。
 

提示：

1 <= forbidden.length <= 1000
1 <= a, b, forbidden[i] <= 2000
0 <= x <= 2000
forbidden 中所有位置互不相同。
位置 x 不在 forbidden 中。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-jumps-to-reach-home
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int rightmost = 6000;  // 准确的右边界是多少？要怎么证明？
        vector<int> visited(rightmost, 0);

        setForbidden(visited, forbidden);

        return bfs(a, b, x, rightmost, visited);
    }

    void setForbidden(vector<int>& visited, vector<int>& forbidden) {
        for (int positon : forbidden) {
            visited[positon] = 1;
        }
    }

    int bfs(int a, int b, int x, int rightmost, vector<int>& visited) {
        queue<int> positions;
        positions.push(0);
        visited[0] = 1;
        int jumps = -1;

        while (!positions.empty()) {
            int size = positions.size();
            ++jumps;

            for (int i = 0; i < size; ++i) {
                int position = positions.front();
                positions.pop();

                if (position == x) {
                    return jumps;
                }

                int next = position + a;
                if (next < rightmost && visited[next] != 1) {  // visited等于2的时候是可以访问的
                    visited[next] = 1;  // 前进到达某个点之后，就不能再访问这个点
                    positions.push(next);
                }

                if (visited[position] == 2) {  // 后退方向到的position，不能再后退了
                    continue;
                }

                next = position - b;
                if (next > 0 && visited[next] == 0) {
                    visited[next] = 2;  // 后退到达某个点之后，不能再后退访问它，但是可以前进访问它。
                    positions.push(next);
                }
            }
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> forbidden = { 14,4,18,1,15 };
    check.checkInt(3, o.minimumJumps(forbidden, 3, 15, 9));

    forbidden = { 8,3,16,6,12,20 };
    check.checkInt(-1, o.minimumJumps(forbidden, 15, 13, 11));

    forbidden = { 1,6,2,14,5,17,4 };
    check.checkInt(2, o.minimumJumps(forbidden, 16, 9, 7));

    forbidden = { 1,6,2,14,5,17,4 };
    check.checkInt(0, o.minimumJumps(forbidden, 16, 9, 0));

    forbidden = { 162,118,178,152,167,100,40,74,199,186,26,73,200,127,30,124,193,84,184,36,103,149,153,9,54,154,133,95,45,198,79,157,64,122,59,71,48,177,82,35,14,176,16,108,111,6,168,31,134,164,136,72,98 };
    check.checkInt(121, o.minimumJumps(forbidden, 29, 98, 80));

    forbidden = { 1437,756,1658,1632,675,1519,530,1699,1341,1310,555,1979,1040,1358,1628,609,968,1748,264,583,66,765,102,1061,518,1927,259,944,181,1205,1434,1032,172,1612,108,1803,1220,1573,1259,893,1374,691,1077,786,1288,1815,1996,297,485,197,616,421,1611,967,432,1347,671,209,416,928,1885,854,842,1407,962,153,506,1107,1750,1729,1372,789,350,117,230,1308,1934,311,1770,605,1369,719,1746,1798,568,1376,121,1924,1622,222,1789,1300,1906,1598,1719,1094,1269,443,532,319,1644,1731,407,328,127,1585,1843,701,1672,1594,404,228,990,1847,1807,1119,1681,86,396,642,810,1201,414,1140,1829,521,1029,923,342,1715,239,1034,1398,544,1630,1196,1130,1184,120,123,1674,1617,198,1481,137,1560,408,1851,770,752,1135,437,1597,1489,823,468,1721,727,1587,1816,1670,401,423,187,955,1458,1779,1321,1459,479,141,1849,1273,347,56,1067,1362,1873,133,1650,1821,1453,1147,632,812,1556,1443,1247,1679,1172,1689,1027,746,966,1769,440,884,1616,508,1387,1430,418,1758,203,1312,1947,1278,681,741,165 };
    check.checkInt(-1, o.minimumJumps(forbidden, 867, 553, 288));
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
