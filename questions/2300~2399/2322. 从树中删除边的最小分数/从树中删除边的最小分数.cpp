/* 从树中删除边的最小分数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
存在一棵无向连通树，树中有编号从 0 到 n - 1 的 n 个节点， 以及 n - 1 条边。

给你一个下标从 0 开始的整数数组 nums ，长度为 n ，其中 nums[i] 表示第 i 个节点的值。另给你一个二维整数数组 edges ，长度为 n - 1 ，其中 edges[i] = [ai, bi] 表示树中存在一条位于节点 ai 和 bi 之间的边。

删除树中两条 不同 的边以形成三个连通组件。对于一种删除边方案，定义如下步骤以计算其分数：

分别获取三个组件 每个 组件中所有节点值的异或值。
最大 异或值和 最小 异或值的 差值 就是这一种删除边方案的分数。
例如，三个组件的节点值分别是：[4,5,7]、[1,9] 和 [3,3,3] 。三个异或值分别是 4 ^ 5 ^ 7 = 6、1 ^ 9 = 8 和 3 ^ 3 ^ 3 = 3 。最大异或值是 8 ，最小异或值是 3 ，分数是 8 - 3 = 5 。
返回在给定树上执行任意删除边方案可能的 最小 分数。

 

示例 1：


输入：nums = [1,5,5,4,11], edges = [[0,1],[1,2],[1,3],[3,4]]
输出：9
解释：上图展示了一种删除边方案。
- 第 1 个组件的节点是 [1,3,4] ，值是 [5,4,11] 。异或值是 5 ^ 4 ^ 11 = 10 。
- 第 2 个组件的节点是 [0] ，值是 [1] 。异或值是 1 = 1 。
- 第 3 个组件的节点是 [2] ，值是 [5] 。异或值是 5 = 5 。
分数是最大异或值和最小异或值的差值，10 - 1 = 9 。
可以证明不存在分数比 9 小的删除边方案。
示例 2：


输入：nums = [5,5,2,4,4,2], edges = [[0,1],[1,2],[5,2],[4,3],[1,3]]
输出：0
解释：上图展示了一种删除边方案。
- 第 1 个组件的节点是 [3,4] ，值是 [4,4] 。异或值是 4 ^ 4 = 0 。
- 第 2 个组件的节点是 [1,0] ，值是 [5,5] 。异或值是 5 ^ 5 = 0 。
- 第 3 个组件的节点是 [2,5] ，值是 [2,2] 。异或值是 2 ^ 2 = 0 。
分数是最大异或值和最小异或值的差值，0 - 0 = 0 。
无法获得比 0 更小的分数 0 。
 

提示：

n == nums.length
3 <= n <= 1000
1 <= nums[i] <= 108
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges 表示一棵有效的树

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-score-after-removals-on-a-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size(), minScore = INT_MAX, xorSum1, xorSum2, xorSum3;
        vector<int> xorSums(n);
        vector<vector<int>> adjs(n);
        vector<bool> visited(n, false);
        vector<int> path;
        vector<vector<bool>> allSubs(n, vector<bool>(n, false));

        getAdjs(edges, adjs);
        xorSums[0] = DFS(0, nums, adjs, visited, xorSums, path, allSubs);

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                if (i == j) {
                    continue;
                }

                if (!allSubs[i][j] && !allSubs[j][i]) {  // 两个不相关的子树
                    xorSum1 = xorSums[i], xorSum2 = xorSums[j], xorSum3 = xorSums[0] ^ xorSum1 ^ xorSum2;
                }
                else if (!allSubs[i][j] && allSubs[j][i]) {  // i是j的子树
                    xorSum1 = xorSums[i], xorSum2 = xorSums[j] ^ xorSums[i], xorSum3 = xorSums[0] ^ xorSums[j];
                }
                else {  // j是i的子树
                    xorSum1 = xorSums[j], xorSum2 = xorSums[i] ^ xorSums[j], xorSum3 = xorSums[0] ^ xorSums[i];
                }

                minScore = min(minScore, max({ xorSum1, xorSum2, xorSum3 }) - min({ xorSum1, xorSum2, xorSum3 }));
            }
        }

        return minScore;
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
    }

    int DFS(int root, vector<int>& nums, vector<vector<int>>& adjs, vector<bool>& visited, vector<int>& xorSums, vector<int>& path, vector<vector<bool>>& allSubs) {
        for (int node : path) {
            allSubs[node][root] = true;
        }

        visited[root] = true;
        path.push_back(root);
        int xorSum = nums[root];

        for (int next : adjs[root]) {
            if (!visited[next]) {
                xorSum ^= DFS(next, nums, adjs, visited, xorSums, path, allSubs);
            }
        }

        xorSums[root] = xorSum;
        path.pop_back();

        return xorSum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 1,5,5,4,11 };
    vector<vector<int>> edges = { {0,1},{1,2},{1,3},{3,4} };
    check.checkInt(9, o.minimumScore(nums, edges));

    nums = { 5,5,2,4,4,2 };
    edges = { {0,1},{1,2},{5,2},{4,3},{1,3} };
    check.checkInt(0, o.minimumScore(nums, edges));
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
