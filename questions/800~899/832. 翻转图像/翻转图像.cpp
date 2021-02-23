/* 翻转图像.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二进制矩阵 A，我们想先水平翻转图像，然后反转图像并返回结果。

水平翻转图片就是将图片的每一行都进行翻转，即逆序。例如，水平翻转 [1, 1, 0] 的结果是 [0, 1, 1]。

反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。例如，反转 [0, 1, 1] 的结果是 [1, 0, 0]。

示例 1:

输入: [[1,1,0],[1,0,1],[0,0,0]]
输出: [[1,0,0],[0,1,0],[1,1,1]]
解释: 首先翻转每一行: [[0,1,1],[1,0,1],[0,0,0]]；
     然后反转图片: [[1,0,0],[0,1,0],[1,1,1]]
示例 2:

输入: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
输出: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
解释: 首先翻转每一行: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]]；
     然后反转图片: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
说明:

1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flipping-an-image
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int r, c1, c2, row = A.size(), column = A[0].size();

        for (r = 0; r < row; ++r) {
            for (c1 = 0, c2 = column - 1; c1 <= c2; ++c1, --c2) {
                if (A[r][c1] == A[r][c2]) {
                    A[r][c1] = A[r][c2] = (A[r][c1] ^ 1);
                }
            }
        }

        return A;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> A = { {1,1,0},{1,0,1},{0,0,0} };
    vector<vector<int>> actual = o.flipAndInvertImage(A);
    vector<vector<int>> expected = { {1,0,0},{0,1,0},{1,1,1} };
    check.checkIntDoubleVector(expected, actual);

    A = { {1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0} };
    actual = o.flipAndInvertImage(A);
    expected = { {1,1,0,0},{0,1,1,0},{0,0,0,1},{1,0,1,0} };
    check.checkIntDoubleVector(expected, actual);

    A = { {1} };
    actual = o.flipAndInvertImage(A);
    expected = { {0} };
    check.checkIntDoubleVector(expected, actual);
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
