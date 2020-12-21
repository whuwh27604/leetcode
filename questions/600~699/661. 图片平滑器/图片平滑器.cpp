/* 图片平滑器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
包含整数的二维矩阵 M 表示一个图片的灰度。你需要设计一个平滑器来让每一个单元的灰度成为平均灰度 (向下舍入) ，平均灰度的计算是周围的8个单元和它本身的值求平均，如果周围的单元格不足八个，则尽可能多的利用它们。

示例 1:

输入:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
输出:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
解释:
对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
注意:

给定矩阵中的整数范围为 [0, 255]。
矩阵的长和宽的范围均为 [1, 150]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/image-smoother
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> smoothMatrix(M.size(), vector<int>(M[0].size(), 0));

        for (unsigned int i = 0; i < M.size(); i++) {
            for (unsigned int j = 0; j < M[0].size(); j++) {
                smoothMatrix[i][j] = calcAverage(i, j, M.size(), M[0].size(), M);
            }
        }

        return smoothMatrix;
    }

    int calcAverage(int i, int j, int height, int width, vector<vector<int>>& M) {
        int sum = M[i][j], divisor = 1, isValid = 0;
        sum += up(i, j, M, isValid);
        divisor += isValid;
        sum += upRight(i, j, width, M, isValid);
        divisor += isValid;
        sum += right(i, j, width, M, isValid);
        divisor += isValid;
        sum += downRight(i, j, height, width, M, isValid);
        divisor += isValid;
        sum += down(i, j, height, M, isValid);
        divisor += isValid;
        sum += downLeft(i, j, height, M, isValid);
        divisor += isValid;
        sum += left(i, j, M, isValid);
        divisor += isValid;
        sum += upLeft(i, j, M, isValid);
        divisor += isValid;
        return (sum / divisor);
    }

    int up(int i, int j, vector<vector<int>>& M, int& isValid) {
        if (i == 0) {
            isValid = 0;
            return 0;
        }

        isValid = 1;
        return M[i - 1][j];
    }

    int upRight(int i, int j, int width, vector<vector<int>>& M, int& isValid) {
        if ((i == 0) || (j == (width - 1))) {
            isValid = 0;
            return 0;
        }

        isValid = 1;
        return M[i - 1][j + 1];
    }

    int right(int i, int j, int width, vector<vector<int>>& M, int& isValid) {
        if (j == (width - 1)) {
            isValid = 0;
            return 0;
        }

        isValid = 1;
        return M[i][j + 1];
    }

    int downRight(int i, int j, int height, int width, vector<vector<int>>& M, int& isValid) {
        if ((i == (height - 1)) || (j == (width - 1))) {
            isValid = 0;
            return 0;
        }

        isValid = 1;
        return M[i + 1][j + 1];
    }

    int down(int i, int j, int height, vector<vector<int>>& M, int& isValid) {
        if (i == (height - 1)) {
            isValid = 0;
            return 0;
        }

        isValid = 1;
        return M[i + 1][j];
    }



    int downLeft(int i, int j, int height, vector<vector<int>>& M, int& isValid) {
        if ((i == (height - 1)) || (j == 0)) {
            isValid = 0;
            return 0;
        }

        isValid = 1;
        return M[i + 1][j - 1];
    }

    int left(int i, int j, vector<vector<int>>& M, int& isValid) {
        if (j == 0) {
            isValid = 0;
            return 0;
        }

        isValid = 1;
        return M[i][j - 1];
    }

    int upLeft(int i, int j, vector<vector<int>>& M, int& isValid) {
        if ((i == 0) || (j == 0)) {
            isValid = 0;
            return 0;
        }

        isValid = 1;
        return M[i - 1][j - 1];
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> M = { {1,1,1},{1,0,1},{1,1,1} };
    vector<vector<int>> actual = o.imageSmoother(M);
    vector<vector<int>> expected = { {0,0,0},{0,0,0},{0,0,0} };
    check.checkIntDoubleVector(expected, actual);
    
    M = { {1,1,1},{1,1,1},{1,1,1} };
    actual = o.imageSmoother(M);
    expected = { {1,1,1},{1,1,1},{1,1,1} };
    check.checkIntDoubleVector(expected, actual);

    M = { {5} };
    actual = o.imageSmoother(M);
    expected = { {5} };
    check.checkIntDoubleVector(expected, actual);

    M = { {1,2,3} };
    actual = o.imageSmoother(M);
    expected = { {1,2,2} };
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
