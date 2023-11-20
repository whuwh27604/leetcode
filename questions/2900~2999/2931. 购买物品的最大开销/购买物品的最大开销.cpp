/* 购买物品的最大开销.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始大小为 m * n 的整数矩阵 values ，表示 m 个不同商店里 m * n 件不同的物品。每个商店有 n 件物品，第 i 个商店的第 j 件物品的价值为 values[i][j] 。除此以外，第 i 个商店的物品已经按照价值非递增排好序了，也就是说对于所有 0 <= j < n - 1 都有 values[i][j] >= values[i][j + 1] 。

每一天，你可以在一个商店里购买一件物品。具体来说，在第 d 天，你可以：

选择商店 i 。
购买数组中最右边的物品 j ，开销为 values[i][j] * d 。换句话说，选择该商店中还没购买过的物品中最大的下标 j ，并且花费 values[i][j] * d 去购买。
注意，所有物品都视为不同的物品。比方说如果你已经从商店 1 购买了物品 0 ，你还可以在别的商店里购买其他商店的物品 0 。

请你返回购买所有 m * n 件物品需要的 最大开销 。



示例 1：

输入：values = [[8,5,2],[6,4,1],[9,7,3]]
输出：285
解释：第一天，从商店 1 购买物品 2 ，开销为 values[1][2] * 1 = 1 。
第二天，从商店 0 购买物品 2 ，开销为 values[0][2] * 2 = 4 。
第三天，从商店 2 购买物品 2 ，开销为 values[2][2] * 3 = 9 。
第四天，从商店 1 购买物品 1 ，开销为 values[1][1] * 4 = 16 。
第五天，从商店 0 购买物品 1 ，开销为 values[0][1] * 5 = 25 。
第六天，从商店 1 购买物品 0 ，开销为 values[1][0] * 6 = 36 。
第七天，从商店 2 购买物品 1 ，开销为 values[2][1] * 7 = 49 。
第八天，从商店 0 购买物品 0 ，开销为 values[0][0] * 8 = 64 。
第九天，从商店 2 购买物品 0 ，开销为 values[2][0] * 9 = 81 。
所以总开销为 285 。
285 是购买所有 m * n 件物品的最大总开销。
示例 2：

输入：values = [[10,8,6,4,2],[9,7,5,3,2]]
输出：386
解释：第一天，从商店 0 购买物品 4 ，开销为 values[0][4] * 1 = 2 。
第二天，从商店 1 购买物品 4 ，开销为 values[1][4] * 2 = 4 。
第三天，从商店 1 购买物品 3 ，开销为 values[1][3] * 3 = 9 。
第四天，从商店 0 购买物品 3 ，开销为 values[0][3] * 4 = 16 。
第五天，从商店 1 购买物品 2 ，开销为 values[1][2] * 5 = 25 。
第六天，从商店 0 购买物品 2 ，开销为 values[0][2] * 6 = 36 。
第七天，从商店 1 购买物品 1 ，开销为 values[1][1] * 7 = 49 。
第八天，从商店 0 购买物品 1 ，开销为 values[0][1] * 8 = 64 。
第九天，从商店 1 购买物品 0 ，开销为 values[1][0] * 9 = 81 。
第十天，从商店 0 购买物品 0 ，开销为 values[0][0] * 10 = 100 。
所以总开销为 386 。
386 是购买所有 m * n 件物品的最大总开销。


提示：

1 <= m == values.length <= 10
1 <= n == values[i].length <= 104
1 <= values[i][j] <= 106
values[i] 按照非递增顺序排序。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int r;
    int c;
    int v;

    Node(int _r, int _c, int _v) : r(_r), c(_c), v(_v) {};

    bool operator<(const Node& o) const {
        return v > o.v;
    }
};

class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        priority_queue<Node> nodes;
        long long spending = 0, day = 1;
        int m = values.size(), n = values[0].size();

        for (int i = 0; i < m; ++i) {
            nodes.push(Node(i, n - 1, values[i][n - 1]));
        }

        while (!nodes.empty()) {
            Node node = nodes.top();
            nodes.pop();
            spending += (node.v * day++);

            if (node.c != 0) {
                nodes.push(Node(node.r, node.c - 1, values[node.r][node.c - 1]));
            }
        }

        return spending;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> values = { {8,5,2},{6,4,1},{9,7,3} };
    check.checkLongLong(285, o.maxSpending(values));

    values = { {10,8,6,4,2},{9,7,5,3,2} };
    check.checkLongLong(386, o.maxSpending(values));
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
