﻿/* 查询树中环的长度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n ，表示你有一棵含有 2n - 1 个节点的 完全二叉树 。根节点的编号是 1 ，树中编号在[1, 2n - 1 - 1] 之间，编号为 val 的节点都有两个子节点，满足：

左子节点的编号为 2 * val
右子节点的编号为 2 * val + 1
给你一个长度为 m 的查询数组 queries ，它是一个二维整数数组，其中 queries[i] = [ai, bi] 。对于每个查询，求出以下问题的解：

在节点编号为 ai 和 bi 之间添加一条边。
求出图中环的长度。
删除节点编号为 ai 和 bi 之间新添加的边。
注意：

环 是开始和结束于同一节点的一条路径，路径中每条边都只会被访问一次。
环的长度是环中边的数目。
在树中添加额外的边后，两个点之间可能会有多条边。
请你返回一个长度为 m 的数组 answer ，其中 answer[i] 是第 i 个查询的结果。



示例 1：



输入：n = 3, queries = [[5,3],[4,7],[2,3]]
输出：[4,5,3]
解释：上图是一棵有 23 - 1 个节点的树。红色节点表示添加额外边后形成环的节点。
- 在节点 3 和节点 5 之间添加边后，环为 [5,2,1,3] ，所以第一个查询的结果是 4 。删掉添加的边后处理下一个查询。
- 在节点 4 和节点 7 之间添加边后，环为 [4,2,1,3,7] ，所以第二个查询的结果是 5 。删掉添加的边后处理下一个查询。
- 在节点 2 和节点 3 之间添加边后，环为 [2,1,3] ，所以第三个查询的结果是 3 。删掉添加的边。
示例 2：



输入：n = 2, queries = [[1,2]]
输出：[2]
解释：上图是一棵有 22 - 1 个节点的树。红色节点表示添加额外边后形成环的节点。
- 在节点 1 和节点 2 之间添加边后，环为 [2,1] ，所以第一个查询的结果是 2 。删掉添加的边。


提示：

2 <= n <= 30
m == queries.length
1 <= m <= 105
queries[i].length == 2
1 <= ai, bi <= 2n - 1
ai != bi
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        int size = queries.size(), index = 0;
        vector<int> ans(size);

        for (auto& query : queries) {
            ans[index++] = getCycle(query[0], query[1]);
        }

        return ans;
    }

    int getCycle(int x, int y) {
        int cycle = 1;

        while (x != y) {
            if (x > y) {
                x /= 2;
            }
            else {
                y /= 2;
            }
            ++cycle;
        }

        return cycle;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> queries = { {5,3},{4,7},{2,3} };
    vector<int> actual = o.cycleLengthQueries(3, queries);
    vector<int> expected = { 4,5,3 };
    check.checkIntVector(expected, actual);

    queries = { {1,2} };
    actual = o.cycleLengthQueries(2, queries);
    expected = { 2 };
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
