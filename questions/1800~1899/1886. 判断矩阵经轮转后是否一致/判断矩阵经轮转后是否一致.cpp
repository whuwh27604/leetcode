/* 判断矩阵经轮转后是否一致.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个大小为 n x n 的二进制矩阵 mat 和 target 。现 以 90 度顺时针轮转 矩阵 mat 中的元素 若干次 ，如果能够使 mat 与 target 一致，返回 true ；否则，返回 false 。

 

示例 1：


输入：mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
输出：true
解释：顺时针轮转 90 度一次可以使 mat 和 target 一致。
示例 2：


输入：mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
输出：false
解释：无法通过轮转矩阵中的元素使 equal 与 target 一致。
示例 3：


输入：mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
输出：true
解释：顺时针轮转 90 度两次可以使 mat 和 target 一致。
 

提示：

n == mat.length == target.length
n == mat[i].length == target[i].length
1 <= n <= 10
mat[i][j] 和 target[i][j] 不是 0 就是 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/determine-whether-matrix-can-be-obtained-by-rotation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int times = 0;

        do {
            if (mat == target) {
                return true;
            }

            rotate(mat);
            ++times;
        } while (times < 4);

        return false;
    }

    void rotate(vector<vector<int>>& mat) {
        int i, j, n = mat.size();
        vector<vector<int>> tmp(n, vector<int>(n));

        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                tmp[i][j] = mat[n - 1 - j][i];
            }
        }

        mat = tmp;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> mat = { {0,1},{1,0} };
    vector<vector<int>> target = { {1,0},{0,1} };
    check.checkBool(true, o.findRotation(mat, target));

    mat = { {0,1},{1,1} };
    target = { {1,0},{0,1} };
    check.checkBool(false, o.findRotation(mat, target));

    mat = { {0,0,0},{0,1,0},{1,1,1} };
    target = { {1,1,1},{0,1,0},{0,0,0} };
    check.checkBool(true, o.findRotation(mat, target));
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
