/* 连通两组点的最小成本.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两组点，其中第一组中有 size1 个点，第二组中有 size2 个点，且 size1 >= size2 。

任意两点间的连接成本 cost 由大小为 size1 x size2 矩阵给出，其中 cost[i][j] 是第一组中的点 i 和第二组中的点 j 的连接成本。如果两个组中的每个点都与另一组中的一个或多个点连接，则称这两组点是连通的。换言之，第一组中的每个点必须至少与第二组中的一个点连接，且第二组中的每个点必须至少与第一组中的一个点连接。

返回连通两组点所需的最小成本。

 

示例 1：



输入：cost = [[15, 96], [36, 2]]
输出：17
解释：连通两组点的最佳方法是：
1--A
2--B
总成本为 17 。
示例 2：



输入：cost = [[1, 3, 5], [4, 1, 1], [1, 5, 3]]
输出：4
解释：连通两组点的最佳方法是：
1--A
2--B
2--C
3--A
最小成本为 4 。
请注意，虽然有多个点连接到第一组中的点 2 和第二组中的点 A ，但由于题目并不限制连接点的数目，所以只需要关心最低总成本。
示例 3：

输入：cost = [[2, 5, 1], [3, 4, 7], [8, 1, 2], [6, 2, 4], [3, 8, 8]]
输出：10
 

提示：

size1 == cost.length
size2 == cost[i].length
1 <= size1, size2 <= 12
size1 >= size2
0 <= cost[i][j] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-cost-to-connect-two-groups-of-points
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int i, j, bit, mask, size1 = cost.size(), size2 = cost[0].size(), maxMask = (1 << size2);
        vector<vector<int>> dp(size1, vector<int>(maxMask, INT_MAX));  // dp[i][mask]表示nums1[0,i]和nums2[mask]连通的最小花费

        for (mask = 1; mask < maxMask; ++mask) {
            dp[0][mask] = 0;

            for (j = 0, bit = 1; j < size2; ++j, bit <<= 1) {
                if ((mask & bit) != 0) {
                    dp[0][mask] += cost[0][j];
                }
            }
        }

        for (i = 1; i < size1; ++i) {
            for (mask = 1; mask < maxMask; ++mask) {
                for (j = 0, bit = 1; j < size2; ++j, bit <<= 1) {
                    if ((mask & bit) == 0) {
                        continue;
                    }

                    if ((mask ^ bit) == 0) {
                        dp[i][mask] = dp[i - 1][mask] + cost[i][j];
                    }
                    else {
                        dp[i][mask] = min({ dp[i][mask], dp[i - 1][mask] + cost[i][j], dp[i][mask ^ bit] + cost[i][j], dp[i - 1][mask ^ bit] + cost[i][j] });
                    }
                }
            }
        }

        return dp[size1 - 1][maxMask - 1];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> cost = { {15,96},{36,2} };
    check.checkInt(17, o.connectTwoGroups(cost));

    cost = { {1,3,5},{4,1,1},{1,5,3} };
    check.checkInt(4, o.connectTwoGroups(cost));

    cost = { {2,5,1},{3,4,7},{8,1,2},{6,2,4},{3,8,8} };
    check.checkInt(10, o.connectTwoGroups(cost));

    cost = { {5} };
    check.checkInt(5, o.connectTwoGroups(cost));
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
