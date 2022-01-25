/* 互质树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 n 个节点的树（也就是一个无环连通无向图），节点编号从 0 到 n - 1 ，且恰好有 n - 1 条边，每个节点有一个值。树的 根节点 为 0 号点。

给你一个整数数组 nums 和一个二维数组 edges 来表示这棵树。nums[i] 表示第 i 个点的值，edges[j] = [uj, vj] 表示节点 uj 和节点 vj 在树中有一条边。

当 gcd(x, y) == 1 ，我们称两个数 x 和 y 是 互质的 ，其中 gcd(x, y) 是 x 和 y 的 最大公约数 。

从节点 i 到 根 最短路径上的点都是节点 i 的祖先节点。一个节点 不是 它自己的祖先节点。

请你返回一个大小为 n 的数组 ans ，其中 ans[i]是离节点 i 最近的祖先节点且满足 nums[i] 和 nums[ans[i]] 是 互质的 ，如果不存在这样的祖先节点，ans[i] 为 -1 。

 

示例 1：



输入：nums = [2,3,3,2], edges = [[0,1],[1,2],[1,3]]
输出：[-1,0,0,1]
解释：上图中，每个节点的值在括号中表示。
- 节点 0 没有互质祖先。
- 节点 1 只有一个祖先节点 0 。它们的值是互质的（gcd(2,3) == 1）。
- 节点 2 有两个祖先节点，分别是节点 1 和节点 0 。节点 1 的值与它的值不是互质的（gcd(3,3) == 3）但节点 0 的值是互质的(gcd(2,3) == 1)，所以节点 0 是最近的符合要求的祖先节点。
- 节点 3 有两个祖先节点，分别是节点 1 和节点 0 。它与节点 1 互质（gcd(3,2) == 1），所以节点 1 是离它最近的符合要求的祖先节点。
示例 2：



输入：nums = [5,6,10,2,3,6,15], edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]
输出：[-1,0,-1,0,0,0,-1]
 

提示：

nums.length == n
1 <= nums[i] <= 50
1 <= n <= 105
edges.length == n - 1
edges[j].length == 2
0 <= uj, vj < n
uj != vj

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/tree-of-coprimes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> coprimes(51);
        vector<vector<int>> adjs(n);
        vector<stack<pair<int, int>>> indexNodes(51);
        vector<int> ans(n);

        getAllCoprimes(coprimes);
        getAdjs(edges, adjs);
        DFS(0, -1, 0, nums, adjs, coprimes, indexNodes, ans);

        return ans;
    }

    void getAllCoprimes(vector<vector<int>>& coprimes) {
        for (int i = 1; i <= 50; ++i) {
            for (int j = 1; j <= 50; ++j) {
                if (gcd(i, j) == 1) {
                    coprimes[i].push_back(j);
                }
            }
        }
    }

    void getAdjs(vector<vector<int>>& edges, vector<vector<int>>& adjs) {
        for (auto& edge : edges) {
            adjs[edge[0]].push_back(edge[1]);
            adjs[edge[1]].push_back(edge[0]);
        }
    }

    void DFS(int root, int parent, int index, vector<int>& nums, vector<vector<int>>& adjs,
        vector<vector<int>>& coprimes, vector<stack<pair<int, int>>>& indexNodes, vector<int>& ans) {
        int num = nums[root];
        ans[root] = getAnswer(num, coprimes, indexNodes);

        indexNodes[num].push({ index, root });

        for (int node : adjs[root]) {
            if (node != parent) {
                DFS(node, root, index + 1, nums, adjs, coprimes, indexNodes, ans);
            }
        }

        indexNodes[num].pop();
    }

    int getAnswer(int num, vector<vector<int>>& coprimes, vector<stack<pair<int, int>>>& indexNodes) {
        int maxIndex = -1, node = -1;

        for (int coprime : coprimes[num]) {
            if (!indexNodes[coprime].empty() && indexNodes[coprime].top().first > maxIndex) {
                maxIndex = indexNodes[coprime].top().first;
                node = indexNodes[coprime].top().second;
            }
        }

        return node;
    }

    int gcd(int x, int y) {
        return (y == 0) ? x : gcd(y, x % y);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums = { 5,6,10,2,3,6,15 };
    vector<vector<int>> edges = { {0,1},{0,2},{1,3},{1,4},{2,5},{2,6} };
    vector<int> actual = o.getCoprimes(nums, edges);
    vector<int> expected = { -1,0,-1,0,0,0,-1 };
    check.checkIntVector(expected, actual);

    nums = { 2,3,3,2 };
    edges = { {0,1},{1,2},{1,3} };
    actual = o.getCoprimes(nums, edges);
    expected = { -1,0,0,1 };
    check.checkIntVector(expected, actual);

    nums = { 2 };
    edges = {  };
    actual = o.getCoprimes(nums, edges);
    expected = { -1 };
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
