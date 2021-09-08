/* 旋转盒子.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的字符矩阵 box ，它表示一个箱子的侧视图。箱子的每一个格子可能为：

'#' 表示石头
'*' 表示固定的障碍物
'.' 表示空位置
这个箱子被 顺时针旋转 90 度 ，由于重力原因，部分石头的位置会发生改变。每个石头会垂直掉落，直到它遇到障碍物，另一个石头或者箱子的底部。重力 不会 影响障碍物的位置，同时箱子旋转不会产生惯性 ，也就是说石头的水平位置不会发生改变。

题目保证初始时 box 中的石头要么在一个障碍物上，要么在另一个石头上，要么在箱子的底部。

请你返回一个 n x m的矩阵，表示按照上述旋转后，箱子内的结果。

 

示例 1：



输入：box = [["#",".","#"]]
输出：[["."],
      ["#"],
      ["#"]]
示例 2：



输入：box = [["#",".","*","."],
            ["#","#","*","."]]
输出：[["#","."],
      ["#","#"],
      ["*","*"],
      [".","."]]
示例 3：



输入：box = [["#","#","*",".","*","."],
            ["#","#","#","*",".","."],
            ["#","#","#",".","#","."]]
输出：[[".","#","#"],
      [".","#","#"],
      ["#","#","*"],
      ["#","*","."],
      ["#",".","*"],
      ["#",".","."]]
 

提示：

m == box.length
n == box[i].length
1 <= m, n <= 500
box[i][j] 只可能是 '#' ，'*' 或者 '.' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotating-the-box
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> rotated(box[0].size(), vector<char>(box.size()));

        moveRight(box);
        rotate(box, rotated);

        return rotated;
    }

    void moveRight(vector<vector<char>>& box) {
        int i, j, row = box.size(), column = box[0].size();

        for (i = 0; i < row; ++i) {
            int obstacle = column, stones = 0;

            for (j = column - 1; j >= 0; --j) {
                if (box[i][j] == '*') {
                    obstacle = j;
                    stones = 0;
                }
                else if (box[i][j] == '#') {
                    box[i][j] = '.';
                    box[i][obstacle - 1 - stones] = '#';
                    ++stones;
                }
            }
        }
    }

    void rotate(vector<vector<char>>& box, vector<vector<char>>& rotated) {
        int i, j, row = rotated.size(), column = rotated[0].size();

        for (i = 0; i < row; ++i) {
            for (j = 0; j < column; ++j) {
                rotated[i][j] = box[box.size() - 1 - j][i];
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<char>> box = { {'#','.','#'} };
    vector<vector<char>> actual = o.rotateTheBox(box);
    vector<vector<char>> expected = { {'.'},
        {'#'},
        {'#'} };
    check.checkCharVectorVector(expected, actual);

    box = { {'#','.','*','.'},
        {'#','#','*','.'} };
    actual = o.rotateTheBox(box);
    expected = { {'#','.'},
        {'#','#'},
        {'*','*'},
        {'.','.'} };
    check.checkCharVectorVector(expected, actual);

    box = { {'#','#','*','.','*','.'},
        {'#','#','#','*','.','.'},
        {'#','#','#','.','#','.'} };
    actual = o.rotateTheBox(box);
    expected = { {'.','#','#'},
        {'.','#','#'},
        {'#','#','*'},
        {'#','*','.'},
        {'#','.','*'},
        {'#','.','.'} };
    check.checkCharVectorVector(expected, actual);
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
