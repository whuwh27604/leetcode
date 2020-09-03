/* N 皇后.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。



上图为 8 皇后问题的一种解法。

给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

 

示例：

输入：4
输出：[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
 

提示：

皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-queens
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <limits>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<int> queens(n, 0);  // queen's column index

        place(n, 0, queens, 0, 0, 0, solutions);
        return solutions;
    }

    void place(int n, int row, vector<int>& queens, int columns, int diagonals1, int diagonals2, vector<vector<string>>& solutions) {
        if (row == n) {
            createSolution(n, queens, solutions);
            return;
        }

        // 解具有对称性，第一行尝试一半就可以了
        int availablePositions = (row == 0) ? (1 << ((n + 1) / 2)) - 1 : ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));

        while (availablePositions != 0) {
            int position = availablePositions & (-availablePositions);  // 保留最后一个1
            int column = ctz(position);  // vs2019没找到__builtin_ctz函数，先自己实现一个代替用着
            queens[row] = column; // 把queen放在第column列
            // 第row行放置好了，进入row+1行
            place(n, row + 1, queens, columns | position, (diagonals1 | position) >> 1, (diagonals2 | position) << 1, solutions);

            // 执行完place以后，第row行放在column位置，第row+1到第n行所有的可能已经遍历完成，回退第row行，准备尝试第row行的下一个位置
            availablePositions &= (availablePositions - 1);  // 最后一个1清零，表示这个位置已经尝试过了，接下来尝试前面一个1的位置
        }
    }

    void createSolution(int n, vector<int>& queens, vector<vector<string>>& solutions) {
        vector<string> solution(n, string(n, '.'));
        for (int i = 0; i < n; i++) {
            solution[i][queens[i]] = 'Q';
        }
        solutions.push_back(solution);

        if ((n % 2 == 0) || (queens[0] != n / 2)) {  // queens[0]在奇数的中间位置时不要镜像，因为镜像的2个结果都会被正常流程搜出来
            vector<string> mirror(n, string(n, '.'));
            for (int i = 0; i < n; i++) {
                mirror[i][n - 1 - queens[i]] = 'Q';
            }
            solutions.push_back(mirror);
        }
    }

    int ctz(int n) {  // n只有一个1
        int count = 0;
        while (n != 1) {
            n >>= 1;
            count++;
        }
        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<string>> actual = o.solveNQueens(1);
    vector<vector<string>> expected = { {"Q"} };
    check.checkStringVectorVector(expected, actual);

    actual = o.solveNQueens(2);
    expected = {  };
    check.checkStringVectorVector(expected, actual);

    actual = o.solveNQueens(3);
    expected = {  };
    check.checkStringVectorVector(expected, actual);

    actual = o.solveNQueens(4);
    expected = { {".Q..","...Q","Q...","..Q."},{"..Q.","Q...","...Q",".Q.."} };
    check.checkStringVectorVector(expected, actual);

    actual = o.solveNQueens(5);
    expected = { {"Q....","..Q..","....Q",".Q...","...Q."},{"....Q","..Q..","Q....","...Q.",".Q..."},{"Q....","...Q.",".Q...","....Q","..Q.."},
        {"....Q",".Q...","...Q.","Q....","..Q.."},{".Q...","...Q.","Q....","..Q..","....Q"},{"...Q.",".Q...","....Q","..Q..","Q...."},
        {".Q...","....Q","..Q..","Q....","...Q."},{"...Q.","Q....","..Q..","....Q",".Q..."},{"..Q..","Q....","...Q.",".Q...","....Q"},{"..Q..","....Q",".Q...","...Q.","Q...."} };
    check.checkStringVectorVector(expected, actual);
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
