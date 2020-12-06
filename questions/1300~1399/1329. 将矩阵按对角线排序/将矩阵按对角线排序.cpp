/* 将矩阵按对角线排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m * n 的整数矩阵 mat ，请你将同一条对角线上的元素（从左上到右下）按升序排序后，返回排好序的矩阵。

 

示例 1：



输入：mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
输出：[[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 

提示：

m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-the-matrix-diagonally
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int r, c, row = mat.size(), column = mat[0].size();

        for (c = column - 1; c >= 0; --c) {
            vector<int> nums;
            getNums(mat, 0, c, nums);
            sort(nums.begin(), nums.end());
            output(mat, nums, 0, c);
        }

        for (r = 1; r < row; ++r) {
            vector<int> nums;
            getNums(mat, r, 0, nums);
            sort(nums.begin(), nums.end());
            output(mat, nums, r, 0);
        }

        return mat;
    }

    void getNums(vector<vector<int>>& mat, int r, int c, vector<int>& nums) {
        int row = mat.size(), column = mat[0].size();

        while (r < row && c < column) {
            nums.push_back(mat[r++][c++]);
        }
    }

    void output(vector<vector<int>>& mat, vector<int>& nums, int r, int c) {
        int row = mat.size(), column = mat[0].size(), index = 0;

        while (r < row && c < column) {
            mat[r++][c++] = nums[index++];
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> mat = { {3,3,1,1},{2,2,1,2},{1,1,1,2} };
    vector<vector<int>> actual = o.diagonalSort(mat);
    vector<vector<int>> expected = { {1,1,1,1},{1,2,2,2},{1,2,3,3} };
    check.checkIntVectorVector(expected, actual);

    mat = { {3} };
    actual = o.diagonalSort(mat);
    expected = { {3} };
    check.checkIntVectorVector(expected, actual);

    mat = { {3,1,2} };
    actual = o.diagonalSort(mat);
    expected = { {3,1,2} };
    check.checkIntVectorVector(expected, actual);

    mat = { {3},{1},{2} };
    actual = o.diagonalSort(mat);
    expected = { {3},{1},{2} };
    check.checkIntVectorVector(expected, actual);
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
