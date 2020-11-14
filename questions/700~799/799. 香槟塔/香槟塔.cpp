/* 香槟塔.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们把玻璃杯摆成金字塔的形状，其中第一层有1个玻璃杯，第二层有2个，依次类推到第100层，每个玻璃杯(250ml)将盛有香槟。

从顶层的第一个玻璃杯开始倾倒一些香槟，当顶层的杯子满了，任何溢出的香槟都会立刻等流量的流向左右两侧的玻璃杯。当左右两边的杯子也满了，就会等流量的流向它们左右两边的杯子，依次类推。（当最底层的玻璃杯满了，香槟会流到地板上）

例如，在倾倒一杯香槟后，最顶层的玻璃杯满了。倾倒了两杯香槟后，第二层的两个玻璃杯各自盛放一半的香槟。在倒三杯香槟后，第二层的香槟满了 - 此时总共有三个满的玻璃杯。在倒第四杯后，第三层中间的玻璃杯盛放了一半的香槟，他两边的玻璃杯各自盛放了四分之一的香槟，如下图所示。



现在当倾倒了非负整数杯香槟后，返回第 i 行 j 个玻璃杯所盛放的香槟占玻璃杯容积的比例（i 和 j都从0开始）。

 

示例 1:
输入: poured(倾倒香槟总杯数) = 1, query_glass(杯子的位置数) = 1, query_row(行数) = 1
输出: 0.0
解释: 我们在顶层（下标是（0，0））倒了一杯香槟后，没有溢出，因此所有在顶层以下的玻璃杯都是空的。

示例 2:
输入: poured(倾倒香槟总杯数) = 2, query_glass(杯子的位置数) = 1, query_row(行数) = 1
输出: 0.5
解释: 我们在顶层（下标是（0，0）倒了两杯香槟后，有一杯量的香槟将从顶层溢出，位于（1，0）的玻璃杯和（1，1）的玻璃杯平分了这一杯香槟，所以每个玻璃杯有一半的香槟。
注意:

poured 的范围[0, 10 ^ 9]。
query_glass 和query_row 的范围 [0, 99]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/champagne-tower
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        /* 令dp[i][j]表示倒入tower[i][j]杯子的酒，则上一行左右两边的杯子溢出的酒各有一半会倒入这一行中间的杯子，即：
           dp[i][j]=(dp[i-1][j-1]-1)/2+(dp[i-1][j]-1)/2 */
        vector<vector<double>> dp(query_row + 1, vector<double>(query_glass + 1, 0));
        dp[0][0] = poured;

        int i, j;
        for (i = 1; i <= query_row; i++) {
            dp[i][0] = (dp[i - 1][0] > 1) ? (dp[i - 1][0] - 1) / 2 : 0;

            for (j = 1; j <= min(i, query_glass); j++) {
                dp[i][j] = ((dp[i - 1][j - 1] > 1) ? (dp[i - 1][j - 1] - 1) / 2 : 0) + ((dp[i - 1][j] > 1) ? (dp[i - 1][j] - 1) / 2 : 0);
            }
        }

        return dp[query_row][query_glass] > 1 ? 1 : dp[query_row][query_glass];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkDouble(0, o.champagneTower(0, 0, 0));
    check.checkDouble(1, o.champagneTower(1, 0, 0));
    check.checkDouble(0, o.champagneTower(1, 1, 1));
    check.checkDouble(0.5, o.champagneTower(2, 1, 0));
    check.checkDouble(0.5, o.champagneTower(2, 1, 1));
    check.checkDouble(0, o.champagneTower(3, 2, 0));
    check.checkDouble(0.25, o.champagneTower(4, 2, 0));
    check.checkDouble(1, o.champagneTower(5, 2, 1));
    check.checkDouble(0.75, o.champagneTower(6, 2, 2));
    check.checkDouble(0.25, o.champagneTower(4, 2, 2));
    check.checkDouble(0.75, o.champagneTower(6, 2, 0));
    check.checkDouble(0.25, o.champagneTower(6, 3, 1));
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
