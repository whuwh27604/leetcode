/* 省份数量.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。

给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。

返回矩阵中 省份 的数量。

 

示例 1：


输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
输出：2
示例 2：


输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
输出：3
 

提示：

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] 为 1 或 0
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-provinces
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class DSU {
public:
    DSU(int _size) {
        size = _size;
        parents = new int[size];

        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    ~DSU() {
        delete[] parents;
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

    int count() {
        int sets = 0;

        for (int i = 0; i < size; ++i) {
            if (find(i) == i) {
                ++sets;
            }
        }

        return sets;
    }

private:
    int* parents;
    int size;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int i, j, n = isConnected.size();
        DSU dsu(n);

        for (i = 0; i < n; ++i) {
            for (j = i + 1; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    dsu.merge(i, j);
                }
            }
        }

        return dsu.count();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> isConnected = { {1,1,0},{1,1,0},{0,0,1} };
    check.checkInt(2, o.findCircleNum(isConnected));

    isConnected = { {1,0,0},{0,1,0},{0,0,1} };
    check.checkInt(3, o.findCircleNum(isConnected));

    isConnected = { {1,1,0},{1,1,1},{0,1,1} };
    check.checkInt(1, o.findCircleNum(isConnected));

    isConnected = { {1} };
    check.checkInt(1, o.findCircleNum(isConnected));
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
