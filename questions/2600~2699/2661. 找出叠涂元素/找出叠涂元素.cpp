/* 找出叠涂元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的整数数组 arr 和一个 m x n 的整数 矩阵 mat 。arr 和 mat 都包含范围 [1，m * n] 内的 所有 整数。

从下标 0 开始遍历 arr 中的每个下标 i ，并将包含整数 arr[i] 的 mat 单元格涂色。

请你找出 arr 中在 mat 的某一行或某一列上都被涂色且下标最小的元素，并返回其下标 i 。



示例 1：

image explanation for example 1
输入：arr = [1,3,4,2], mat = [[1,4],[2,3]]
输出：2
解释：遍历如上图所示，arr[2] 在矩阵中的第一行或第二列上都被涂色。
示例 2：

image explanation for example 2
输入：arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
输出：3
解释：遍历如上图所示，arr[3] 在矩阵中的第二列上都被涂色。


提示：

m == mat.length
n = mat[i].length
arr.length == m * n
1 <= m, n <= 105
1 <= m * n <= 105
1 <= arr[i], mat[r][c] <= m * n
arr 中的所有整数 互不相同
mat 中的所有整数 互不相同
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int size = arr.size(), row = mat.size(), column = mat[0].size();
        vector<int> rCount(row, 0), cCount(column, 0), rows(size + 1), columns(size + 1);

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                int num = mat[r][c];
                rows[num] = r;
                columns[num] = c;
            }
        }

        for (int i = 0; i < size; ++i) {
            if ((++rCount[rows[arr[i]]] == column) || (++cCount[columns[arr[i]]] == row)) {
                return i;
            }
        }

        return size;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> arr = { 1,3,4,2 };
    vector<vector<int>> mat = { {1,4},{2,3} };
    check.checkInt(2, o.firstCompleteIndex(arr, mat));

    arr = { 2,8,7,4,1,3,5,6,9 };
    mat = { {3,2,5},{1,4,6},{8,7,9} };
    check.checkInt(3, o.firstCompleteIndex(arr, mat));
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
