/* 参加考试的最大学生数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m * n 的矩阵 seats 表示教室中的座位分布。如果座位是坏的（不可用），就用 '#' 表示；否则，用 '.' 表示。

学生可以看到左侧、右侧、左上、右上这四个方向上紧邻他的学生的答卷，但是看不到直接坐在他前面或者后面的学生的答卷。请你计算并返回该考场可以容纳的一起参加考试且无法作弊的最大学生人数。

学生必须坐在状况良好的座位上。

 

示例 1：



输入：seats = [["#",".","#","#",".","#"],
              [".","#","#","#","#","."],
              ["#",".","#","#",".","#"]]
输出：4
解释：教师可以让 4 个学生坐在可用的座位上，这样他们就无法在考试中作弊。
示例 2：

输入：seats = [[".","#"],
              ["#","#"],
              ["#","."],
              ["#","#"],
              [".","#"]]
输出：3
解释：让所有学生坐在可用的座位上。
示例 3：

输入：seats = [["#",".",".",".","#"],
              [".","#",".","#","."],
              [".",".","#",".","."],
              [".","#",".","#","."],
              ["#",".",".",".","#"]]
输出：10
解释：让学生坐在第 1、3 和 5 列的可用座位上。
 

提示：

seats 只包含字符 '.' 和'#'
m == seats.length
n == seats[i].length
1 <= m <= 8
1 <= n <= 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-students-taking-exam
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size(), maxMask = (1 << (n + 1)), allMask = maxMask - 1;
        int left = 1, leftup = (1 << n), rightup = (1 << (n - 2));
        int chosable = initChosable(seats, m, n);
        vector<vector<int>> dp(m * n + 1, vector<int>(maxMask, 0));

        for (int pos = m * n - 1; pos >= 0; --pos) {
            int r = pos / n, c = pos % n;
            chosable >>= 1;  // 将pos位置的椅子移出

            if (pos > n && seats[(pos - n - 1) / n][(pos - n - 1) % n] == '.') {  // pos - n - 1位置是好的椅子，移入可选范围
                chosable |= leftup;
            }

            dp[pos][0] = dp[pos + 1][0];  // 计算mask == 0的情况，pos位置不放人
            if (seats[r][c] == '.') {  // 该座位是好的，尝试放一个人
                dp[pos][0] = max(dp[pos][0], 1 + dp[pos + 1][1]);
            }

            for (int mask = chosable; mask != 0; mask = (mask - 1) & chosable) {  // 枚举chosable所有的子集
                dp[pos][mask] = dp[pos + 1][(mask << 1) & allMask];  // pos位置不放人

                if (seats[r][c] == '.'  // 该座位是好的
                    && (c == 0 || (mask & left) == 0)  // 左边没有人
                    && (c == 0 || (mask & leftup) == 0)  // 左上没有人
                    && (c == n - 1 || (mask & rightup) == 0)) {  // 右上没有人
                    dp[pos][mask] = max(dp[pos][mask], 1 + dp[pos + 1][((mask << 1) & allMask) | 1]);  // 可以选择在该位置放一个人，然后看剩下的位置还能放多少人
                }
            }
        }

        return dp[0][0];
    }

    int initChosable(vector<vector<char>>& seats, int m, int n) {  // seats[m - 1][n - 1]到seats[m - 2][n - 1]位置好的椅子
        int chosable = (m == 1 ? 0 : (seats[m - 2][n - 1] == '.' ? 1 : 0));

        for (int c = 0; c < n; ++c) {
            chosable = (chosable << 1) | (seats[m - 1][c] == '.' ? 1 : 0);
        }

        return chosable;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<char>> seats = { {'#','.','#','#','.','#'},
        {'.','#','#','#','#','.'},
        {'#','.','#','#','.','#'} };
    check.checkInt(4, o.maxStudents(seats));

    seats = { {'#','.','#'},
        {'.','#','#'},
        {'#','.','#'} };
    check.checkInt(2, o.maxStudents(seats));

    seats = { {'.','#'},
        {'#','#'},
        {'#','.'},
        {'#','#'},
        {'.','#'} };
    check.checkInt(3, o.maxStudents(seats));

    seats = { {'#','.','.','.','#'},
        {'.','#','.','#','.'},
        {'.','.','#','.','.'},
        {'.','#','.','#','.'},
        {'#','.','.','.','#'} };
    check.checkInt(10, o.maxStudents(seats));

    seats = { {'.'} };
    check.checkInt(1, o.maxStudents(seats));

    seats = { {'#'} };
    check.checkInt(0, o.maxStudents(seats));

    seats = { {'.','.','.'} };
    check.checkInt(2, o.maxStudents(seats));

    seats = { {'.'},{'.'},{'.'} };
    check.checkInt(3, o.maxStudents(seats));

    seats = { {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'} };
    check.checkInt(32, o.maxStudents(seats));
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
