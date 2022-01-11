/* 检查是否每一行每一列都包含全部整数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
对一个大小为 n x n 的矩阵而言，如果其每一行和每一列都包含从 1 到 n 的 全部 整数（含 1 和 n），则认为该矩阵是一个 有效 矩阵。

给你一个大小为 n x n 的整数矩阵 matrix ，请你判断矩阵是否为一个有效矩阵：如果是，返回 true ；否则，返回 false 。

 

示例 1：



输入：matrix = [[1,2,3],[3,1,2],[2,3,1]]
输出：true
解释：在此例中，n = 3 ，每一行和每一列都包含数字 1、2、3 。
因此，返回 true 。
示例 2：



输入：matrix = [[1,1,1],[1,2,3],[1,2,3]]
输出：false
解释：在此例中，n = 3 ，但第一行和第一列不包含数字 2 和 3 。
因此，返回 false 。
 

提示：

n == matrix.length == matrix[i].length
1 <= n <= 100
1 <= matrix[i][j] <= n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-if-every-row-and-column-contains-all-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int i, j, n = matrix.size();

        for (i = 0; i < n; ++i) {
            vector<bool> exist(n + 1, false);

            for (j = 0; j < n; ++j) {
                if (exist[matrix[i][j]]) {
                    return false;
                }

                exist[matrix[i][j]] = true;
            }
        }

        for (j = 0; j < n; ++j) {
            vector<bool> exist(n + 1, false);

            for (i = 0; i < n; ++i) {
                if (exist[matrix[i][j]]) {
                    return false;
                }

                exist[matrix[i][j]] = true;
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> matrix = { {1,2,3},{3,1,2},{2,3,1} };
    check.checkBool(true, o.checkValid(matrix));

    matrix = {{1,1,1},{1,2,3},{1,2,3}};
    check.checkBool(false, o.checkValid(matrix));
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
