/* 按列翻转得到最大值等行数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定由若干 0 和 1 组成的矩阵 matrix，从中选出任意数量的列并翻转其上的 每个 单元格。翻转后，单元格的值从 0 变成 1，或者从 1 变为 0 。

返回经过一些翻转后，行上所有值都相等的最大行数。

 

示例 1：

输入：[[0,1],[1,1]]
输出：1
解释：不进行翻转，有 1 行所有值都相等。
示例 2：

输入：[[0,1],[1,0]]
输出：2
解释：翻转第一列的值之后，这两行都由相等的值组成。
示例 3：

输入：[[0,0,0],[0,0,1],[1,1,0]]
输出：2
解释：翻转前两列的值之后，后两行由相等的值组成。
 

提示：

1 <= matrix.length <= 300
1 <= matrix[i].length <= 300
所有 matrix[i].length 都相等
matrix[i][j] 为 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flip-columns-for-maximum-number-of-equal-rows
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> rows;
        int maxEqualRows = 0;

        for (vector<int>& nums : matrix) {
            string row;
            row2String(nums, row);

            if (rows.count(row) == 0) {
                rows[row] = 1;
            }
            else {
                ++rows[row];
            }
        }

        for (auto iter = rows.begin(); iter != rows.end(); ++iter) {
            maxEqualRows = max(maxEqualRows, iter->second);
        }

        return maxEqualRows;
    }

    void row2String(vector<int>& nums, string& s) {
        bool needFlip = (nums[0] == 0);

        for (int num : nums) {
            if (needFlip) {
                num ^= 1;
            }

            s += ('0' + num);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> matrix = { {0,1},{1,1} };
    check.checkInt(1, o.maxEqualRowsAfterFlips(matrix));

    matrix = { {0,1},{1,0} };
    check.checkInt(2, o.maxEqualRowsAfterFlips(matrix));

    matrix = { {0,0,0},{0,0,1},{1,1,0} };
    check.checkInt(2, o.maxEqualRowsAfterFlips(matrix));

    matrix = { {0},{1},{0},{1} };
    check.checkInt(4, o.maxEqualRowsAfterFlips(matrix));

    matrix = { {0,1,1,1},{1,0,0,0},{0,1,1,1},{1,1,1,0},{1,0,0,0} };
    check.checkInt(4, o.maxEqualRowsAfterFlips(matrix));
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
