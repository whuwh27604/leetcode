/* 循环移位后的矩阵相似检查.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始且大小为 m x n 的整数矩阵 mat 和一个整数 k 。请你将矩阵中的 奇数 行循环 右 移 k 次，偶数 行循环 左 移 k 次。

如果初始矩阵和最终矩阵完全相同，则返回 true ，否则返回 false 。



示例 1：

输入：mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2
输出：true
解释：


初始矩阵如图一所示。
图二表示对奇数行右移一次且对偶数行左移一次后的矩阵状态。
图三是经过两次循环移位后的最终矩阵状态，与初始矩阵相同。
因此，返回 true 。
示例 2：

输入：mat = [[2,2],[2,2]], k = 3
输出：true
解释：由于矩阵中的所有值都相等，即使进行循环移位，矩阵仍然保持不变。因此，返回 true 。
示例 3：

输入：mat = [[1,2]], k = 1
输出：false
解释：循环移位一次后，mat = [[2,1]]，与初始矩阵不相等。因此，返回 false 。


提示：

1 <= mat.length <= 25
1 <= mat[i].length <= 25
1 <= mat[i][j] <= 25
1 <= k <= 50
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        k %= n;
        vector<vector<int>> matrix(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i & 1) == 0) {
                    matrix[i][j] = mat[i][(j + k) % n];
                }
                else {
                    matrix[i][j] = mat[i][(j + n - k) % n];
                }
            }
        }

        return mat == matrix;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> mat = {{1,2,1,2},{5,5,5,5},{6,3,6,3}};
    check.checkBool(true,o.areSimilar(mat,2));

    mat = {{2,2},{2,2}};
    check.checkBool(true,o.areSimilar(mat,3));

    mat = {{1,2}};
    check.checkBool(false, o.areSimilar(mat, 1));
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
