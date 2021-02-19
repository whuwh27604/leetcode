/* 方阵中战斗力最弱的 K 行.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个大小为 m * n 的方阵 mat，方阵由若干军人和平民组成，分别用 1 和 0 表示。

请你返回方阵中战斗力最弱的 k 行的索引，按从最弱到最强排序。

如果第 i 行的军人数量少于第 j 行，或者两行军人数量相同但 i 小于 j，那么我们认为第 i 行的战斗力比第 j 行弱。

军人 总是 排在一行中的靠前位置，也就是说 1 总是出现在 0 之前。

 

示例 1：

输入：mat =
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]],
k = 3
输出：[2,0,3]
解释：
每行中的军人数目：
行 0 -> 2
行 1 -> 4
行 2 -> 1
行 3 -> 2
行 4 -> 5
从最弱到最强对这些行排序后得到 [2,0,3,1,4]
示例 2：

输入：mat =
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]],
k = 2
输出：[0,2]
解释：
每行中的军人数目：
行 0 -> 1
行 1 -> 4
行 2 -> 1
行 3 -> 1
从最弱到最强对这些行排序后得到 [0,2,3,1]
 

提示：

m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] 不是 0 就是 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/the-k-weakest-rows-in-a-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int i, m = mat.size(), n = mat[0].size();
        vector<int> ans;
        ans.reserve(m);

        for (i = 0; i < m; i++) {
            int soldiers = binarySearchSoldiers(mat[i], 0, n - 1);
            ans.push_back((soldiers << 8) + i);
        }

        sort(ans.begin(), ans.end());
        
        for (i = 0; i < k; i++) {
            ans[i] &= 0xffff00ff;
        }

        for (i = k; i < m; i++) {
            ans.pop_back();
        }

        return ans;
    }

    int binarySearchSoldiers(vector<int>& row, int left, int right) {
        int middle = (left + right) / 2;
        if (row[middle] == 0) {
            if (middle == left) {
                return left;
            }
            else {
                if (row[middle - 1] == 1) {
                    return middle;
                }
                return binarySearchSoldiers(row, left, middle - 1);
            }
        }
        else {
            if (middle == right) {
                return right + 1;
            }
            else {
                if (row[middle + 1] == 0) {
                    return middle + 1;
                }
                return binarySearchSoldiers(row, middle + 1, right);
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;
    
    vector<int> row(100, 0);
    check.checkInt(0, o.binarySearchSoldiers(row, 0, 99));
    for (int i = 0; i < 100; i++) {
        row[i] = 1;
        check.checkInt(i + 1, o.binarySearchSoldiers(row, 0, 99));
    }

    vector<vector<int>> mat = { {1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1} };
    vector<int> actual = o.kWeakestRows(mat, 3);
    vector<int> expected = { 2,0,3 };
    check.checkIntVector(expected, actual);

    mat = { {1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1} };
    actual = o.kWeakestRows(mat, 1);
    expected = { 2 };
    check.checkIntVector(expected, actual);

    mat = { {1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1} };
    actual = o.kWeakestRows(mat, 5);
    expected = { 2,0,3,1,4 };
    check.checkIntVector(expected, actual);

    mat = { {1,0,0,0},{1,1,1,1},{1,0,0,0},{1,0,0,0} };
    actual = o.kWeakestRows(mat, 2);
    expected = { 0,2 };
    check.checkIntVector(expected, actual);

    mat = { {1,0,0,0},{1,1,1,1},{1,0,0,0},{1,0,0,0} };
    actual = o.kWeakestRows(mat, 1);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    mat = { {1,0,0,0},{1,1,1,1},{1,0,0,0},{1,0,0,0} };
    actual = o.kWeakestRows(mat, 4);
    expected = { 0,2,3,1 };
    check.checkIntVector(expected, actual);

    mat = { {0,0},{0,0} };
    actual = o.kWeakestRows(mat, 1);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    mat = { {0,0},{0,0} };
    actual = o.kWeakestRows(mat, 2);
    expected = { 0,1 };
    check.checkIntVector(expected, actual);

    mat = { {1,1},{1,1} };
    actual = o.kWeakestRows(mat, 1);
    expected = { 0 };
    check.checkIntVector(expected, actual);

    mat = { {1,1},{1,1} };
    actual = o.kWeakestRows(mat, 2);
    expected = { 0,1 };
    check.checkIntVector(expected, actual);

    mat = { {1,0},{0,0} };
    actual = o.kWeakestRows(mat, 1);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    mat = { {1,0},{0,0} };
    actual = o.kWeakestRows(mat, 2);
    expected = { 1,0 };
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
