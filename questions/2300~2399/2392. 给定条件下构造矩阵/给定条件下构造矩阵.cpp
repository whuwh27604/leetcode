/* 给定条件下构造矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 正 整数 k ，同时给你：

一个大小为 n 的二维整数数组 rowConditions ，其中 rowConditions[i] = [abovei, belowi] 和
一个大小为 m 的二维整数数组 colConditions ，其中 colConditions[i] = [lefti, righti] 。
两个数组里的整数都是 1 到 k 之间的数字。

你需要构造一个 k x k 的矩阵，1 到 k 每个数字需要 恰好出现一次 。剩余的数字都是 0 。

矩阵还需要满足以下条件：

对于所有 0 到 n - 1 之间的下标 i ，数字 abovei 所在的 行 必须在数字 belowi 所在行的上面。
对于所有 0 到 m - 1 之间的下标 i ，数字 lefti 所在的 列 必须在数字 righti 所在列的左边。
返回满足上述要求的 任意 矩阵。如果不存在答案，返回一个空的矩阵。

 

示例 1：



输入：k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
输出：[[3,0,0],[0,0,1],[0,2,0]]
解释：上图为一个符合所有条件的矩阵。
行要求如下：
- 数字 1 在第 1 行，数字 2 在第 2 行，1 在 2 的上面。
- 数字 3 在第 0 行，数字 2 在第 2 行，3 在 2 的上面。
列要求如下：
- 数字 2 在第 1 列，数字 1 在第 2 列，2 在 1 的左边。
- 数字 3 在第 0 列，数字 2 在第 1 列，3 在 2 的左边。
注意，可能有多种正确的答案。
示例 2：

输入：k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
输出：[]
解释：由前两个条件可以得到 3 在 1 的下面，但第三个条件是 3 在 1 的上面。
没有符合条件的矩阵存在，所以我们返回空矩阵。
 

提示：

2 <= k <= 400
1 <= rowConditions.length, colConditions.length <= 104
rowConditions[i].length == colConditions[i].length == 2
1 <= abovei, belowi, lefti, righti <= k
abovei != belowi
lefti != righti

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/build-a-matrix-with-conditions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> row(k), column(k);

        if (!topSort(k, rowConditions, row)) {
            return {};
        }

        if (!topSort(k, colConditions, column)) {
            return {};
        }

        return build(k, row, column);
    }

    bool topSort(int k, vector<vector<int>>& conditions, vector<int>& nums) {
        vector<int> degrees(k + 1, 0);
        vector<vector<int>> adjs(k + 1);
        queue<int> zeroDegrees;
        int index = 0;

        for (auto& condition : conditions) {
            ++degrees[condition[1]];
            adjs[condition[0]].push_back(condition[1]);
        }

        for (int i = 1; i <= k; ++i) {
            if (degrees[i] == 0) {
                zeroDegrees.push(i);
            }
        }

        while (!zeroDegrees.empty()) {
            int node = zeroDegrees.front();
            zeroDegrees.pop();
            nums[index++] = node;

            for (int next : adjs[node]) {
                if (--degrees[next] == 0) {
                    zeroDegrees.push(next);
                }
            }
        }

        return index == k;
    }

    vector<vector<int>> build(int k, vector<int>& row, vector<int>& column) {
        vector<int> colIndices(k + 1);
        vector<vector<int>> matrix(k, vector<int>(k, 0));

        for (int i = 0; i < k; ++i) {
            colIndices[column[i]] = i;
        }

        for (int i = 0; i < k; ++i) {
            matrix[i][colIndices[row[i]]] = row[i];
        }

        return matrix;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> rowConditions = { {1,2},{2,3},{3,1},{2,3} };
    vector<vector<int>> colConditions = { {2,1} };
    vector<vector<int>> actual = o.buildMatrix(3, rowConditions, colConditions);
    vector<vector<int>> expected = {};
    check.checkIntVectorVector(expected, actual);

    rowConditions = { {1,2},{3,2} };
    colConditions = { {2,1},{3,2} };
    actual = o.buildMatrix(3, rowConditions, colConditions);
    expected = { {0,0,1},{3,0,0},{0,2,0} };
    check.checkIntVectorVector(expected, actual);

    rowConditions = { {1,2},{7,3},{4,3},{5,8},{7,8},{8,2},{5,8},{3,2},{1,3},{7,6},{4,3},{7,4},{4,8},{7,3},{7,5} };
    colConditions = { {5,7},{2,7},{4,3},{6,7},{4,3},{2,3},{6,2} };
    actual = o.buildMatrix(8, rowConditions, colConditions);
    expected = { {1,0,0,0,0,0,0,0},{0,0,0,0,0,0,7,0},{0,0,0,6,0,0,0,0},{0,4,0,0,0,0,0,0},{0,0,5,0,0,0,0,0},{0,0,0,0,0,0,0,3},{0,0,0,0,8,0,0,0},{0,0,0,0,0,2,0,0} };
    check.checkIntVectorVector(expected, actual);

    rowConditions = { {2,4},{1,7},{1,4},{7,3},{3,4},{5,7},{3,4},{1,3},{5,7},{6,5},{7,3},{6,7},{2,4},{1,4},{2,7},{3,4},{2,7},{6,5},{2,7},{7,3} };
    colConditions = { {1,6},{1,6},{1,7},{4,7},{1,6},{7,6},{1,5},{5,2},{1,2},{3,2},{1,4} };
    actual = o.buildMatrix(7, rowConditions, colConditions);
    expected = { {1,0,0,0,0,0,0},{0,0,0,0,2,0,0},{0,0,0,0,0,0,6},{0,0,5,0,0,0,0},{0,0,0,0,0,7,0},{0,3,0,0,0,0,0},{0,0,0,4,0,0,0} };
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
