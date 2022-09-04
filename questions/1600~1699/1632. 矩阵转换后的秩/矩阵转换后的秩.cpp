/* 矩阵转换后的秩.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 m x n 的矩阵 matrix ，请你返回一个新的矩阵 answer ，其中 answer[row][col] 是 matrix[row][col] 的秩。

每个元素的 秩 是一个整数，表示这个元素相对于其他元素的大小关系，它按照如下规则计算：

秩是从 1 开始的一个整数。
如果两个元素 p 和 q 在 同一行 或者 同一列 ，那么：
如果 p < q ，那么 rank(p) < rank(q)
如果 p == q ，那么 rank(p) == rank(q)
如果 p > q ，那么 rank(p) > rank(q)
秩 需要越 小 越好。
题目保证按照上面规则 answer 数组是唯一的。

 

示例 1：


输入：matrix = [[1,2],[3,4]]
输出：[[1,2],[2,3]]
解释：
matrix[0][0] 的秩为 1 ，因为它是所在行和列的最小整数。
matrix[0][1] 的秩为 2 ，因为 matrix[0][1] > matrix[0][0] 且 matrix[0][0] 的秩为 1 。
matrix[1][0] 的秩为 2 ，因为 matrix[1][0] > matrix[0][0] 且 matrix[0][0] 的秩为 1 。
matrix[1][1] 的秩为 3 ，因为 matrix[1][1] > matrix[0][1]， matrix[1][1] > matrix[1][0] 且 matrix[0][1] 和 matrix[1][0] 的秩都为 2 。
示例 2：


输入：matrix = [[7,7],[7,7]]
输出：[[1,1],[1,1]]
示例 3：


输入：matrix = [[20,-21,14],[-19,4,19],[22,-47,24],[-19,4,19]]
输出：[[4,2,3],[1,3,4],[5,1,6],[1,3,4]]
示例 4：


输入：matrix = [[7,3,6],[1,4,5],[9,8,2]]
输出：[[5,1,4],[1,2,3],[6,3,1]]
 

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 500
-109 <= matrix[row][col] <= 109

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/rank-transform-of-a-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class DSU {
public:
    DSU(int size) {
        parents.resize(size);

        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    void merge(int x, int y) {
        parents[find(x)] = find(y);
    }

private:
    vector<int> parents;
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int row = matrix.size(), column = matrix[0].size(), size = row * column;
        DSU dsu(size);
        vector<vector<int>> adjs(size);
        vector<int> degrees(size, 0), ranks(size, 1);

        mergeRow(matrix, dsu);
        mergeColumn(matrix, dsu);
        buildRowAdjs(matrix, dsu, adjs, degrees);
        buildColumnAdjs(matrix, dsu, adjs, degrees);
        topSort(size, dsu, adjs, degrees, ranks);

        return getRankMatrix(row, column, dsu, ranks);
    }

    void mergeRow(vector<vector<int>>& matrix, DSU& dsu) {
        int row = matrix.size(), column = matrix[0].size();

        for (int r = 0; r < row; ++r) {
            unordered_map<int, vector<int>> numIndices;

            for (int c = 0; c < column; ++c) {
                numIndices[matrix[r][c]].push_back((r * column) + c);
            }

            for (auto& numIndex : numIndices) {
                for (int i = 1; i < (int)numIndex.second.size(); ++i) {
                    dsu.merge(numIndex.second[0], numIndex.second[i]);
                }
            }
        }
    }

    void mergeColumn(vector<vector<int>>& matrix, DSU& dsu) {
        int row = matrix.size(), column = matrix[0].size();

        for (int c = 0; c < column; ++c) {
            unordered_map<int, vector<int>> numIndices;

            for (int r = 0; r < row; ++r) {
                numIndices[matrix[r][c]].push_back((r * column) + c);
            }

            for (auto& numIndex : numIndices) {
                for (int i = 1; i < (int)numIndex.second.size(); ++i) {
                    dsu.merge(numIndex.second[0], numIndex.second[i]);
                }
            }
        }
    }

    void buildRowAdjs(vector<vector<int>>& matrix, DSU& dsu, vector<vector<int>>& adjs, vector<int>& degrees) {
        int row = matrix.size(), column = matrix[0].size();

        for (int r = 0; r < row; ++r) {
            vector<pair<int, int>> nodes(column);

            for (int c = 0; c < column; ++c) {
                nodes[c] = { matrix[r][c],c };
            }

            sort(nodes.begin(), nodes.end());

            for (int c = 1; c < column; ++c) {
                if (nodes[c - 1].first != nodes[c].first) {
                    int from = dsu.find(r * column + nodes[c - 1].second);
                    int to = dsu.find(r * column + nodes[c].second);
                    adjs[from].push_back(to);
                    ++degrees[to];
                }
            }
        }
    }

    void buildColumnAdjs(vector<vector<int>>& matrix, DSU& dsu, vector<vector<int>>& adjs, vector<int>& degrees) {
        int row = matrix.size(), column = matrix[0].size();

        for (int c = 0; c < column; ++c) {
            vector<pair<int, int>> nodes(row);

            for (int r = 0; r < row; ++r) {
                nodes[r] = { matrix[r][c],r };
            }

            sort(nodes.begin(), nodes.end());

            for (int r = 1; r < row; ++r) {
                if (nodes[r - 1].first != nodes[r].first) {
                    int from = dsu.find(nodes[r - 1].second * column + c);
                    int to = dsu.find(nodes[r].second * column + c);
                    adjs[from].push_back(to);
                    ++degrees[to];
                }
            }
        }
    }

    void topSort(int size, DSU& dsu, vector<vector<int>>& adjs, vector<int>& degrees, vector<int>& ranks) {
        queue<int> zeroDegrees;

        for (int node = 0; node < size; ++node) {
            if (degrees[node] == 0 && dsu.find(node) == node) {
                zeroDegrees.push(node);
            }
        }

        while (!zeroDegrees.empty()) {
            int node = zeroDegrees.front();
            zeroDegrees.pop();

            for (int next : adjs[node]) {
                ranks[next] = max(ranks[next], ranks[node] + 1);

                if (--degrees[next] == 0 && dsu.find(next) == next) {
                    zeroDegrees.push(next);
                }
            }
        }
    }

    vector<vector<int>> getRankMatrix(int row, int column, DSU& dsu, vector<int>& ranks) {
        vector<vector<int>> rankMatrix(row, vector<int>(column));

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < column; ++c) {
                rankMatrix[r][c] = ranks[dsu.find(r * column + c)];
            }
        }

        return rankMatrix;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> matrix = { {1,2},{3,4} };
    vector<vector<int>> actual = o.matrixRankTransform(matrix);
    vector<vector<int>> expected = { {1,2},{2,3} };
    check.checkIntVectorVector(expected, actual);

    matrix = { {7,7},{7,7} };
    actual = o.matrixRankTransform(matrix);
    expected = { {1,1},{1,1} };
    check.checkIntVectorVector(expected, actual);

    matrix = { {2,1},{1,1} };
    actual = o.matrixRankTransform(matrix);
    expected = { {2,1},{1,1} };
    check.checkIntVectorVector(expected, actual);

    matrix = { {20,-21,14},{-19,4,19},{22,-47,24},{-19,4,19} };
    actual = o.matrixRankTransform(matrix);
    expected = { {4,2,3},{1,3,4},{5,1,6},{1,3,4} };
    check.checkIntVectorVector(expected, actual);

    matrix = { {7,3,6},{1,4,5},{9,8,2} };
    actual = o.matrixRankTransform(matrix);
    expected = { {5,1,4},{1,2,3},{6,3,1} };
    check.checkIntVectorVector(expected, actual);

    matrix = { {-37,-50,-3,44},{-37,46,13,-32},{47,-42,-3,-40},{-17,-22,-39,24} };
    actual = o.matrixRankTransform(matrix);
    expected = { {2,1,4,6},{2,6,5,4},{5,2,4,3},{4,3,1,5} };
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
