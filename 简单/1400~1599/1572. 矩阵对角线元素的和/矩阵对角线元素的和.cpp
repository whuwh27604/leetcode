/* 矩阵对角线元素的和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个正方形矩阵 mat，请你返回矩阵对角线元素的和。

请你返回在矩阵主对角线上的元素和副对角线上且不在主对角线上元素的和。

 

示例  1：



输入：mat = [[1,2,3],
            [4,5,6],
            [7,8,9]]
输出：25
解释：对角线的和为：1 + 5 + 9 + 3 + 7 = 25
请注意，元素 mat[1][1] = 5 只会被计算一次。
示例  2：

输入：mat = [[1,1,1,1],
            [1,1,1,1],
            [1,1,1,1],
            [1,1,1,1]]
输出：8
示例 3：

输入：mat = [[5]]
输出：5
 

提示：

n == mat.length == mat[i].length
1 <= n <= 100
1 <= mat[i][j] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/matrix-diagonal-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i, size = mat.size(), sum = 0;

        for (i = 0; i < size; ++i) {
            sum += mat[i][i];
            sum += mat[i][size - 1 - i];
        }

        return (size % 2 == 0) ? sum : sum - mat[size / 2][size / 2];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> mat = { {5} };
    check.checkInt(5, o.diagonalSum(mat));

    mat = { {5,6},{7,8} };
    check.checkInt(26, o.diagonalSum(mat));

    mat = { {1,2,3},{4,5,6},{7,8,9} };
    check.checkInt(25, o.diagonalSum(mat));

    mat = { {1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1} };
    check.checkInt(8, o.diagonalSum(mat));
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
