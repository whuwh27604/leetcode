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
        int m = seats.size(), n = seats[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(1 << n, 0));

        for (int i = 1; i <= m; ++i) {
            dp[i][0] = *max_element(dp[i - 1].begin(), dp[i - 1].end());  // 本行不坐人，那么可以坐到上一行的最大值

            int state = initRowState(seats, i - 1);

            for (int seated = state; seated != 0; seated = (seated - 1) & state) {  // 遍历所有可选座位的子集
                if (((seated & (seated << 1)) != 0) || ((seated & (seated >> 1)) != 0)) {  // 有两个挨着的座位，不合法
                    continue;
                }

                for (int upSeated = 0; upSeated < (1 << n); ++upSeated) {
                    if (((seated & (upSeated << 1)) == 0) && ((seated & (upSeated >> 1)) == 0)) {  // 和上一行不冲突
                        dp[i][seated] = max(dp[i][seated], getStudents(seated) + dp[i - 1][upSeated]);
                    }
                }
            }
        }

        return *max_element(dp.back().begin(), dp.back().end());
    }

    int initRowState(vector<vector<char>>& seats, int row) {
        int state = 0;

        for (char c : seats[row]) {
            state <<= 1;

            if (c == '.') {
                state |= 1;
            }
        }

        return state;
    }

    int getStudents(int seated) {
        int students = 0;

        while (seated != 0) {
            seated &= (seated - 1);
            ++students;
        }

        return students;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<char>> seats = {{'#','.','#','#','.','#'},
        {'.','#','#','#','#','.'},
        {'#','.','#','#','.','#'}};
    check.checkInt(4,o.maxStudents(seats));

    seats = { {'#','.','#'},
        {'.','#','#'},
        {'#','.','#'} };
    check.checkInt(2, o.maxStudents(seats));

    seats = {{'.','#'},
        {'#','#'},
        {'#','.'},
        {'#','#'},
        {'.','#'}};
    check.checkInt(3,o.maxStudents(seats));

    seats = {{'#','.','.','.','#'},
        {'.','#','.','#','.'},
        {'.','.','#','.','.'},
        {'.','#','.','#','.'},
        {'#','.','.','.','#'}};
    check.checkInt(10,o.maxStudents(seats));

    seats = { {'.'} };
    check.checkInt(1, o.maxStudents(seats));

    seats = { {'#'} };
    check.checkInt(0, o.maxStudents(seats));

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
