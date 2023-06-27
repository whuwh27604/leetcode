/* 找到矩阵中的好子集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始大小为 m x n 的二进制矩阵 grid 。

从原矩阵中选出若干行构成一个行的 非空 子集，如果子集中任何一列的和至多为子集大小的一半，那么我们称这个子集是 好子集。

更正式的，如果选出来的行子集大小（即行的数量）为 k，那么每一列的和至多为 floor(k / 2) 。

请你返回一个整数数组，它包含好子集的行下标，请你将子集中的元素 升序 返回。

如果有多个好子集，你可以返回任意一个。如果没有好子集，请你返回一个空数组。

一个矩阵 grid 的行 子集 ，是删除 grid 中某些（也可能不删除）行后，剩余行构成的元素集合。



示例 1：

输入：grid = [[0,1,1,0],[0,0,0,1],[1,1,1,1]]
输出：[0,1]
解释：我们可以选择第 0 和第 1 行构成一个好子集。
选出来的子集大小为 2 。
- 第 0 列的和为 0 + 0 = 0 ，小于等于子集大小的一半。
- 第 1 列的和为 1 + 0 = 1 ，小于等于子集大小的一半。
- 第 2 列的和为 1 + 0 = 1 ，小于等于子集大小的一半。
- 第 3 列的和为 0 + 1 = 1 ，小于等于子集大小的一半。
示例 2：

输入：grid = [[0]]
输出：[0]
解释：我们可以选择第 0 行构成一个好子集。
选出来的子集大小为 1 。
- 第 0 列的和为 0 ，小于等于子集大小的一半。
示例 3：

输入：grid = [[1,1,1],[1,1,1]]
输出：[]
解释：没有办法得到一个好子集。


提示：

m == grid.length
n == grid[i].length
1 <= m <= 104
1 <= n <= 5
grid[i][j] 要么是 0 ，要么是 1 。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        /* 结论是最多只用选2行，2行选不出来更多行也不可能选出来了。
           1、如果只选1行，那么必须是全0
           2、如果选2行，那么与的结果为0
           3、如果是3以上的奇数行2n + 1，根据好子集的定义，那还不如选择2n行
           4、考虑4行。这意味着任意2行不满足要求，即任意2行与的结果，至少有一列为1。从4行中任取2行有6种选法，要让每一列和都小于2，就至少要6列。
              题目规定了最多5列，这就意味着至少有一列有3个以上的1，不满足好子集定义
           5、数学归纳法，4以上的偶数行都有相同的性质。所以最终答案最多选2行。 */
        int m = grid.size(), n = grid[0].size(), maxMask = (1 << n) - 1;
        vector<int> indices((1 << n), -1);

        for (int i = 0; i < m; ++i) {
            int num = getNum(grid[i]);
            if (num == 0) {
                return { i };
            }

            int index = match(num ^ maxMask, indices);
            if (index != -1) {
                return { index,i };
            }

            indices[num] = i;
        }

        return {};
    }

    int getNum(vector<int>& row) {
        int num = 0;

        for (int bit : row) {
            num = ((num << 1) | bit);
        }

        return num;
    }

    int match(int mask, vector<int>& indices) {
        for (int i = mask; i != 0; i = (i - 1) & mask) {  // 遍历mask的子集，mask和num与的结果为0，mask的任一子集和num与的结果也肯定为0
            if (indices[i] != -1) {
                return indices[i];
            }
        }

        return -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> grid = { {0,1,1,0},{0,0,0,1},{1,1,1,1} };
    vector<int> actual = o.goodSubsetofBinaryMatrix(grid);
    vector<int> expected = { 0,1 };
    check.checkIntVector(expected, actual);

    grid = { {0} };
    actual = o.goodSubsetofBinaryMatrix(grid);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    grid = { {1,1,1},{1,1,1} };
    actual = o.goodSubsetofBinaryMatrix(grid);
    expected = {  };
    check.checkIntVector(expected, actual);
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
