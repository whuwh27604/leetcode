/* 重构一棵树的方案数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 pairs ，其中 pairs[i] = [xi, yi] ，并且满足：

pairs 中没有重复元素
xi < yi
令 ways 为满足下面条件的有根树的方案数：

树所包含的所有节点值都在 pairs 中。
一个数对 [xi, yi] 出现在 pairs 中 当且仅当 xi 是 yi 的祖先或者 yi 是 xi 的祖先。
注意：构造出来的树不一定是二叉树。
两棵树被视为不同的方案当存在至少一个节点在两棵树中有不同的父节点。

请你返回：

如果 ways == 0 ，返回 0 。
如果 ways == 1 ，返回 1 。
如果 ways > 1 ，返回 2 。
一棵 有根树 指的是只有一个根节点的树，所有边都是从根往外的方向。

我们称从根到一个节点路径上的任意一个节点（除去节点本身）都是该节点的 祖先 。根节点没有祖先。

 

示例 1：


输入：pairs = [[1,2],[2,3]]
输出：1
解释：如上图所示，有且只有一个符合规定的有根树。
示例 2：


输入：pairs = [[1,2],[2,3],[1,3]]
输出：2
解释：有多个符合规定的有根树，其中三个如上图所示。
示例 3：

输入：pairs = [[1,2],[2,3],[2,4],[1,5]]
输出：0
解释：没有符合规定的有根树。
 

提示：

1 <= pairs.length <= 105
1 <= xi < yi <= 500
pairs 中的元素互不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-ways-to-reconstruct-a-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> adjs;
        
        getAdjs(pairs, adjs);

        int root = getRoot(adjs);
        if (root == -1) {
            return 0;
        }

        int res = 1;  // 检测成功至少有一个解

        for (auto& adj : adjs) {
            if (adj.first == root) {
                continue;
            }

            int currDegree = adj.second.size(), parentDegree = INT_MAX;

            int parent = getParent(adjs, adj.first, adj.second, currDegree, parentDegree);
            if (parent == -1) {
                return 0;
            }

            if (!isSubset(adjs, parent, adj.second)) {
                return 0;
            }

            if (parentDegree == currDegree) {  // node和parent可以互换位置，有多个解
                res = 2;
            }
        }

        return res;
    }

    void getAdjs(vector<vector<int>>& pairs, unordered_map<int, unordered_set<int>>& adjs) {
        for (auto& p : pairs) {
            adjs[p[0]].emplace(p[1]);
            adjs[p[1]].emplace(p[0]);
        }
    }

    int getRoot(unordered_map<int, unordered_set<int>>& adjs) {
        for (auto& adj : adjs) {
            if (adj.second.size() == adjs.size() - 1) {
                return adj.first;
            }
        }

        return -1;
    }

    int getParent(unordered_map<int, unordered_set<int>>& adjs, int node, unordered_set<int>& neighbours, int currDegree, int& parentDegree) {
        int parent = -1;

        for (int neighbour : neighbours) {  // 根据 degree 的大小找到 node 的父节点 parent
            if ((int)adjs[neighbour].size() < parentDegree && (int)adjs[neighbour].size() >= currDegree) {
                parent = neighbour;
                parentDegree = adjs[neighbour].size();
            }
        }

        return parent;
    }

    bool isSubset(unordered_map<int, unordered_set<int>>& adjs, int parent, unordered_set<int>& neighbours) {
        for (int neighbour : neighbours) {  // 检测 node 的 neighbours 是否是 adjs[parent] 的子集
            if (neighbour != parent) {
                if (adjs[parent].count(neighbour) == 0) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> pairs = {{1,2},{2,3}};
    check.checkInt(1,o.checkWays(pairs));

    pairs = {{1,2},{2,3},{2,4},{1,5}};
    check.checkInt(0,o.checkWays(pairs));

    pairs = {{1,2},{2,3},{1,3}};
    check.checkInt(2,o.checkWays(pairs));

    pairs = {{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}};
    check.checkInt(2,o.checkWays(pairs));

    pairs = {{1,2},{1,3},{1,4},{2,3},{2,4}};
    check.checkInt(2,o.checkWays(pairs));

    pairs = {{3,5},{4,5},{2,5},{1,5},{1,4},{2,4}};
    check.checkInt(1, o.checkWays(pairs));
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
