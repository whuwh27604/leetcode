/* 查询后矩阵的和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n 和一个下标从 0 开始的 二维数组 queries ，其中 queries[i] = [typei, indexi, vali] 。

一开始，给你一个下标从 0 开始的 n x n 矩阵，所有元素均为 0 。每一个查询，你需要执行以下操作之一：

如果 typei == 0 ，将第 indexi 行的元素全部修改为 vali ，覆盖任何之前的值。
如果 typei == 1 ，将第 indexi 列的元素全部修改为 vali ，覆盖任何之前的值。
请你执行完所有查询以后，返回矩阵中所有整数的和。



示例 1：



输入：n = 3, queries = [[0,0,1],[1,2,2],[0,2,3],[1,0,4]]
输出：23
解释：上图展示了每个查询以后矩阵的值。所有操作执行完以后，矩阵元素之和为 23 。
示例 2：



输入：n = 3, queries = [[0,0,4],[0,1,2],[1,0,1],[0,2,3],[1,2,1]]
输出：17
解释：上图展示了每一个查询操作之后的矩阵。所有操作执行完以后，矩阵元素之和为 17 。


提示：

1 <= n <= 104
1 <= queries.length <= 5 * 104
queries[i].length == 3
0 <= typei <= 1
0 <= indexi < n
0 <= vali <= 105
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        long long sum = 0;
        int rCount = 0, cCount = 0;
        vector<bool> rVisited(n, false), cVisited(n, false);

        for (int i = (int)queries.size() - 1; i >= 0; --i) {
            int type = queries[i][0], index = queries[i][1], value = queries[i][2];
            if (type == 0) {
                if (!rVisited[index]) {
                    rVisited[index] = true;
                    ++rCount;
                    sum += ((long long)n - cCount) * value;
                }
            }
            else {
                if (!cVisited[index]) {
                    cVisited[index] = true;
                    ++cCount;
                    sum += ((long long)n - rCount) * value;
                }
            }
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> queries = { {0,0,1},{1,2,2},{0,2,3},{1,0,4} };
    check.checkLongLong(23, o.matrixSumQueries(3, queries));

    queries = { {0,0,4},{0,1,2},{1,0,1},{0,2,3},{1,2,1} };
    check.checkLongLong(17, o.matrixSumQueries(3, queries));
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
