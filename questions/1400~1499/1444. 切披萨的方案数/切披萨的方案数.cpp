/* 切披萨的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 rows x cols 大小的矩形披萨和一个整数 k ，矩形包含两种字符： 'A' （表示苹果）和 '.' （表示空白格子）。你需要切披萨 k-1 次，得到 k 块披萨并送给别人。

切披萨的每一刀，先要选择是向垂直还是水平方向切，再在矩形的边界上选一个切的位置，将披萨一分为二。如果垂直地切披萨，那么需要把左边的部分送给一个人，如果水平地切，那么需要把上面的部分送给一个人。在切完最后一刀后，需要把剩下来的一块送给最后一个人。

请你返回确保每一块披萨包含 至少 一个苹果的切披萨方案数。由于答案可能是个很大的数字，请你返回它对 10^9 + 7 取余的结果。

 

示例 1：



输入：pizza = ["A..","AAA","..."], k = 3
输出：3
解释：上图展示了三种切披萨的方案。注意每一块披萨都至少包含一个苹果。
示例 2：

输入：pizza = ["A..","AA.","..."], k = 3
输出：1
示例 3：

输入：pizza = ["A..","A..","..."], k = 1
输出：1
 

提示：

1 <= rows, cols <= 50
rows == pizza.length
cols == pizza[i].length
1 <= k <= 10
pizza 只包含字符 'A' 和 '.' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-ways-of-cutting-a-pizza
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int r, c, cuts, cut, row = pizza.size(), column = pizza[0].size(), base = column * k, mod = 1000000007;
        vector<int> dp(row * column * k, 0);  // dp[r][c][cuts]表示将submatrix[r,c,row-1,column-1]切cuts刀的方法数

        vector<vector<bool>> hasAppleEachRow(row, vector<bool>(column, false)), hasAppleEachColumn(row, vector<bool>(column, false));
        hasAppleEachRC(pizza, hasAppleEachRow, hasAppleEachColumn);

        for (r = row - 1; r >= 0; --r) {
            bool hasAppleSubMatrix = false;

            for (c = column - 1; c >= 0; --c) {
                hasAppleSubMatrix |= hasAppleEachColumn[r][c];
                if (!hasAppleSubMatrix) {  // submatrix里面没有apple，任何切割方法数都为0
                    continue;
                }

                dp[r * base + c * k] = 1;  // dp[r][c][0]，一刀都不切的方法数视为1

                for (cuts = 1; cuts < k; ++cuts) {
                    bool hasApple = false;

                    for (cut = r; cut < row - 1; ++cut) {  // 遍历横向切一刀的位置
                        hasApple |= hasAppleEachRow[cut][c];

                        if (hasApple) {  // 要保证切完后上半部分有apple
                            // dp[r][c][cuts] = (dp[r][c][cuts] + dp[cut + 1][c][cuts - 1]) % mod;  // 切完后剩下部分还需要切cuts-1刀
                            dp[r * base + c * k + cuts] = (dp[r * base + c * k + cuts] + dp[(cut + 1) * base + c * k + cuts - 1]) % mod;
                        }
                    }

                    hasApple = false;

                    for (cut = c; cut < column - 1; ++cut) {  // 遍历纵向切一刀的位置
                        hasApple |= hasAppleEachColumn[r][cut];

                        if (hasApple) {  // 要保证切完后左半部分有apple
                            // dp[r][c][cuts] = (dp[r][c][cuts] + dp[r][cut + 1][cuts - 1]) % mod;  // 切完后剩下部分还需要切cuts-1刀
                            dp[r * base + c * k + cuts] = (dp[r * base + c * k + cuts] + dp[r * base + (cut + 1) * k + cuts - 1]) % mod;
                        }
                    }
                }
            }
        }

        return dp[k - 1];
    }

    void hasAppleEachRC(vector<string>& pizza, vector<vector<bool>>& hasAppleEachRow, vector<vector<bool>>& hasAppleEachColumn) {
        int r, c, row = pizza.size(), column = pizza[0].size();

        for (r = row - 1; r >= 0; --r) {
            hasAppleEachRow[r][column - 1] = pizza[r][column - 1] == 'A';

            for (c = column - 2; c >= 0; --c) {
                hasAppleEachRow[r][c] = pizza[r][c] == 'A' || hasAppleEachRow[r][c + 1];  // 从[r,c]位置到[r,column)位置是否有apple
            }
        }

        for (c = column - 1; c >= 0; --c) {
            hasAppleEachColumn[row - 1][c] = pizza[row - 1][c] == 'A';

            for (r = row - 2; r >= 0; --r) {
                hasAppleEachColumn[r][c] = pizza[r][c] == 'A' || hasAppleEachColumn[r + 1][c];  // 从[r,c]位置到(row,c]位置是否有apple
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<string> pizza = { "A..","AAA","..." };
    check.checkInt(3, o.ways(pizza, 3));

    pizza = { "A..","AA.","..." };
    check.checkInt(1, o.ways(pizza, 3));

    pizza = { "A..","A..","..." };
    check.checkInt(1, o.ways(pizza, 1));

    pizza = { "A.A.A.A.A.",".A.A.A.A.A","A.A.A.A.A.",".A.A.A.A.A","A.A.A.A.A.",".A.A.A.A.A","A.A.A.A.A.",".A.A.A.A.A","A.A.A.A.A.",".A.A.A.A.A" };
    check.checkInt(4112216, o.ways(pizza, 10));

    pizza = { "AAAAA","AAAAA","AAAAA" };
    check.checkInt(69, o.ways(pizza, 5));

    pizza = { ".....",".....","....." };
    check.checkInt(0, o.ways(pizza, 1));
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
