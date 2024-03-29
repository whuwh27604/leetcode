﻿/* 统计最高分的节点数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵根节点为 0 的 二叉树 ，它总共有 n 个节点，节点编号为 0 到 n - 1 。同时给你一个下标从 0 开始的整数数组 parents 表示这棵树，其中 parents[i] 是节点 i 的父节点。由于节点 0 是根，所以 parents[0] == -1 。

一个子树的 大小 为这个子树内节点的数目。每个节点都有一个与之关联的 分数 。求出某个节点分数的方法是，将这个节点和与它相连的边全部 删除 ，剩余部分是若干个 非空 子树，这个节点的 分数 为所有这些子树 大小的乘积 。

请你返回有 最高得分 节点的 数目 。

 

示例 1:



输入：parents = [-1,2,0,2,0]
输出：3
解释：
- 节点 0 的分数为：3 * 1 = 3
- 节点 1 的分数为：4 = 4
- 节点 2 的分数为：1 * 1 * 2 = 2
- 节点 3 的分数为：4 = 4
- 节点 4 的分数为：4 = 4
最高得分为 4 ，有三个节点得分为 4 （分别是节点 1，3 和 4 ）。
示例 2：



输入：parents = [-1,2,0]
输出：2
解释：
- 节点 0 的分数为：2 = 2
- 节点 1 的分数为：2 = 2
- 节点 2 的分数为：1 * 1 = 1
最高分数为 2 ，有两个节点分数为 2 （分别为节点 0 和 1 ）。
 

提示：

n == parents.length
2 <= n <= 105
parents[0] == -1
对于 i != 0 ，有 0 <= parents[i] <= n - 1
parents 表示一棵二叉树。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-nodes-with-the-highest-score
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        vector<int> left(n, -1), right(n, -1), nodes(n, 0);
        vector<long long> scores(n, 0);

        buildTree(parents, n, left, right);
        DFS(0, n, parents, left, right, nodes, scores);

        return countHighestScore(scores);
    }

    void buildTree(vector<int>& parents, int n, vector<int>& left, vector<int>& right) {
        for (int node = 1; node < n; ++node) {
            int parent = parents[node];
            left[parent] == -1 ? left[parent] = node : right[parent] = node;
        }
    }

    void DFS(int node, int n, vector<int>& parents, vector<int>& left, vector<int>& right, vector<int>& nodes, vector<long long>& scores) {
        if (left[node] != -1) {
            DFS(left[node], n, parents, left, right, nodes, scores);
        }

        if (right[node] != -1) {
            DFS(right[node], n, parents, left, right, nodes, scores);
        }

        nodes[node] = (left[node] == -1 ? 0 : nodes[left[node]]) + (right[node] == -1 ? 0 : nodes[right[node]]) + 1;
        scores[node] = (long long)(left[node] == -1 ? 1 : nodes[left[node]]) * (right[node] == -1 ? 1 : nodes[right[node]]);
        scores[node] *= (node == 0 ? 1 : (n - nodes[node]));
    }

    int countHighestScore(vector<long long>& scores) {
        int count = 0;
        long long highest = 0;

        for (long long score : scores) {
            if (score > highest) {
                highest = score;
                count = 1;
            }
            else if (score == highest) {
                ++count;
            }
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> parents = { -1,2,0,2,0 };
    check.checkInt(3, o.countHighestScoreNodes(parents));

    parents = { -1,2,0 };
    check.checkInt(2, o.countHighestScoreNodes(parents));

    parents = { -1,0 };
    check.checkInt(2, o.countHighestScoreNodes(parents));

    parents = { -1,0,0,1,1,2,2,3,3,4,4,5,5,6,6 };
    check.checkInt(2, o.countHighestScoreNodes(parents));
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
