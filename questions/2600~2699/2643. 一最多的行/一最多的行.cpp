/* 一最多的行.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 m x n 的二进制矩阵 mat ，请你找出包含最多 1 的行的下标（从 0 开始）以及这一行中 1 的数目。

如果有多行包含最多的 1 ，只需要选择 行下标最小 的那一行。

返回一个由行下标和该行中 1 的数量组成的数组。



示例 1：

输入：mat = [[0,1],[1,0]]
输出：[0,1]
解释：两行中 1 的数量相同。所以返回下标最小的行，下标为 0 。该行 1 的数量为 1 。所以，答案为 [0,1] 。
示例 2：

输入：mat = [[0,0,0],[0,1,1]]
输出：[1,2]
解释：下标为 1 的行中 1 的数量最多。该行 1 的数量为 2 。所以，答案为 [1,2] 。
示例 3：

输入：mat = [[0,0],[1,1],[0,0]]
输出：[1,2]
解释：下标为 1 的行中 1 的数量最多。该行 1 的数量为 2 。所以，答案为 [1,2] 。


提示：

m == mat.length
n == mat[i].length
1 <= m, n <= 100
mat[i][j] 为 0 或 1
*/

#include <iostream>
#include <numeric>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans = { 0,0 };

        for (int i = 0; i < (int)mat.size(); ++i) {
            int sum = accumulate(mat[i].begin(), mat[i].end(), 0);
            if (sum > ans[1]) {
                ans = { i,sum };
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> mat = { {0,1},{1,0} };
    vector<int> actual = o.rowAndMaximumOnes(mat);
    vector<int> expected = { 0,1 };
    check.checkIntVector(expected, actual);

    mat = { {0,0,0},{0,1,1} };
    actual = o.rowAndMaximumOnes(mat);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    mat = { {0,0},{1,1},{0,0} };
    actual = o.rowAndMaximumOnes(mat);
    expected = { 1,2 };
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
