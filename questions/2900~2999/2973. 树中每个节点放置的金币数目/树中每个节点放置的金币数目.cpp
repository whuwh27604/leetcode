/* 树中每个节点放置的金币数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵 n 个节点的 无向 树，节点编号为 0 到 n - 1 ，树的根节点在节点 0 处。同时给你一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间有一条边。

给你一个长度为 n 下标从 0 开始的整数数组 cost ，其中 cost[i] 是第 i 个节点的 开销 。

你需要在树中每个节点都放置金币，在节点 i 处的金币数目计算方法如下：

如果节点 i 对应的子树中的节点数目小于 3 ，那么放 1 个金币。
否则，计算节点 i 对应的子树内 3 个不同节点的开销乘积的 最大值 ，并在节点 i 处放置对应数目的金币。如果最大乘积是 负数 ，那么放置 0 个金币。
请你返回一个长度为 n 的数组 coin ，coin[i]是节点 i 处的金币数目。



示例 1：



输入：edges = [[0,1],[0,2],[0,3],[0,4],[0,5]], cost = [1,2,3,4,5,6]
输出：[120,1,1,1,1,1]
解释：在节点 0 处放置 6 * 5 * 4 = 120 个金币。所有其他节点都是叶子节点，子树中只有 1 个节点，所以其他每个节点都放 1 个金币。
示例 2：



输入：edges = [[0,1],[0,2],[1,3],[1,4],[1,5],[2,6],[2,7],[2,8]], cost = [1,4,2,3,5,7,8,-4,2]
输出：[280,140,32,1,1,1,1,1,1]
解释：每个节点放置的金币数分别为：
- 节点 0 处放置 8 * 7 * 5 = 280 个金币。
- 节点 1 处放置 7 * 5 * 4 = 140 个金币。
- 节点 2 处放置 8 * 2 * 2 = 32 个金币。
- 其他节点都是叶子节点，子树内节点数目为 1 ，所以其他每个节点都放 1 个金币。
示例 3：



输入：edges = [[0,1],[0,2]], cost = [1,2,-2]
输出：[0,1,1]
解释：节点 1 和 2 都是叶子节点，子树内节点数目为 1 ，各放置 1 个金币。节点 0 处唯一的开销乘积是 2 * 1 * -2 = -4 。所以在节点 0 处放置 0 个金币。


提示：

2 <= n <= 2 * 104
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
cost.length == n
1 <= |cost[i]| <= 104
edges 一定是一棵合法的树。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    vector<int> nums;

    Node(int num) {
        nums.push_back(num);
    }

    void merge(Node& o) {
        nums.insert(nums.end(), o.nums.begin(), o.nums.end());
        sort(nums.begin(), nums.end(), greater<int>());
        int size = nums.size();
        if (size > 5) {
            nums[3] = nums[size - 2];
            nums[4] = nums[size - 1];
            nums.resize(5);
        }
    }

    long long getMaxProduct() {
        int size = nums.size();

        return max({ (long long)0, (long long)nums[0] * nums[1] * nums[2], (long long)nums[0] * nums[size - 2] * nums[size - 1] });
    }
};

class Solution {
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        vector<vector<int>> adjs(n);
        vector<long long> ans(n);

        getAdjs(edges, adjs);
        (void)DFS(0, -1, adjs, cost, ans);

        return ans;
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            int x = edge[0], y = edge[1];
            adjs[x].push_back(y);
            adjs[y].push_back(x);
        }
    }

    Node DFS(int current, int parent, vector<vector<int>>& adjs, vector<int>& cost, vector<long long>& ans) {
        Node node(cost[current]);

        for (int next : adjs[current]) {
            if (next != parent) {
                Node tmp = DFS(next, current, adjs, cost, ans);
                node.merge(tmp);
            }
        }

        if (node.nums.size() < 3) {
            ans[current] = 1;
        }
        else {
            ans[current] = node.getMaxProduct();
        }

        return node;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edges = { {0,1},{0,2},{0,3},{0,4},{0,5} };
    vector<int> cost = { 1,2,3,4,5,6 };
    vector<long long> actual = o.placedCoins(edges, cost);
    vector<long long> expected = { 120,1,1,1,1,1 };
    check.checkLongLongVector(expected, actual);

    edges = { {0,1},{0,2},{1,3},{1,4},{1,5},{2,6},{2,7},{2,8} };
    cost = { 1,4,2,3,5,7,8,-4,2 };
    actual = o.placedCoins(edges, cost);
    expected = { 280,140,32,1,1,1,1,1,1 };
    check.checkLongLongVector(expected, actual);

    edges = { {0,1},{0,2} };
    cost = { 1,2,-2 };
    actual = o.placedCoins(edges, cost);
    expected = { 0,1,1 };
    check.checkLongLongVector(expected, actual);

    edges = { {0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,8},{0,9},{0,10},{0,11},{0,12},{0,13},{0,14},{0,15},{0,16},{0,17},{0,18},{0,19},{0,20},{0,21},{0,22},{0,23},{0,24},{0,25},{0,26},{0,27},{0,28},{0,29},{0,30},{0,31},{0,32},{0,33},{0,34},{0,35},{0,36},{0,37},{0,38},{0,39},{0,40},{0,41},{0,42},{0,43},{0,44},{0,45},{0,46},{0,47},{0,48},{0,49},{0,50},{0,51},{0,52},{0,53},{0,54},{0,55},{0,56},{0,57},{0,58},{0,59},{0,60},{0,61},{0,62},{0,63},{0,64},{0,65},{0,66},{0,67},{0,68},{0,69},{0,70},{0,71},{0,72},{0,73},{0,74},{0,75},{0,76},{0,77},{0,78},{0,79},{0,80},{0,81},{0,82},{0,83},{0,84},{0,85},{0,86},{0,87},{0,88},{0,89},{0,90},{0,91},{0,92},{0,93},{0,94},{0,95},{0,96},{0,97},{0,98},{0,99} };
    cost = { -5959,602,-6457,7055,-1462,6347,7226,-8422,-6088,2997,-7909,6433,5217,3294,-3792,7463,8538,-3811,5009,151,5659,4458,-1702,-1877,2799,9861,-9668,-1765,2181,-8128,7046,9529,6202,-8026,6464,1345,121,1922,7274,-1227,-9914,3025,1046,-9368,-7368,6205,-6342,8091,-6732,-7620,3276,5136,6871,4823,-1885,-4005,-3974,-2725,-3845,-8508,7201,-9566,-7236,-3386,4021,6793,-8759,5066,5879,-5171,1011,1242,8536,-8405,-9646,-214,2251,-9934,-8820,6206,1006,1318,-9712,7230,5608,-4601,9185,346,3056,8913,-2454,-3445,-4295,4802,-8852,-6121,-4538,-5580,-9246,-6462 };
    actual = o.placedCoins(edges, cost);
    expected = { 971167251036,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
    check.checkLongLongVector(expected, actual);
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
