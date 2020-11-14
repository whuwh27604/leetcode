/* N皇后 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。



上图为 8 皇后问题的一种解法。

给定一个整数 n，返回 n 皇后不同的解决方案的数量。

示例:

输入: 4
输出: 2
解释: 4 皇后问题存在如下两个不同的解法。
[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
 

提示：

皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一或 N-1 步，可进可退。（引用自 百度百科 - 皇后 ）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/n-queens-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        if (n == 0) {
            return 0;
        }

        int solutions = 0;
        vector<int> queens(n, 0);  // queen's column index

        place(n, 0, queens, 0, 0, 0, solutions);
        return solutions;
    }

    void place(int n, int row, vector<int>& queens, int columns, int diagonals1, int diagonals2, int& solutions) {
        if (row == n) {
            solutions++;
            if ((n % 2 == 0) || (queens[0] != n / 2)) {  // queens[0]在奇数的中间位置时不要镜像，因为镜像的2个结果都会被正常流程搜出来
                solutions++;
            }
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

    check.checkInt(0, o.totalNQueens(0));
    check.checkInt(1, o.totalNQueens(1));
    check.checkInt(0, o.totalNQueens(2));
    check.checkInt(0, o.totalNQueens(3));
    check.checkInt(2, o.totalNQueens(4));
    check.checkInt(10, o.totalNQueens(5));
    check.checkInt(4, o.totalNQueens(6));
    check.checkInt(40, o.totalNQueens(7));
    check.checkInt(92, o.totalNQueens(8));
    check.checkInt(352, o.totalNQueens(9));
    check.checkInt(724, o.totalNQueens(10));
    check.checkInt(2680, o.totalNQueens(11));
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
