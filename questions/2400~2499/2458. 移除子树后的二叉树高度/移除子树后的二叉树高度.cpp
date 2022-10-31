/* 移除子树后的二叉树高度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵 二叉树 的根节点 root ，树中有 n 个节点。每个节点都可以被分配一个从 1 到 n 且互不相同的值。另给你一个长度为 m 的数组 queries 。

你必须在树上执行 m 个 独立 的查询，其中第 i 个查询你需要执行以下操作：

从树中 移除 以 queries[i] 的值作为根节点的子树。题目所用测试用例保证 queries[i] 不 等于根节点的值。
返回一个长度为 m 的数组 answer ，其中 answer[i] 是执行第 i 个查询后树的高度。

注意：

查询之间是独立的，所以在每个查询执行后，树会回到其 初始 状态。
树的高度是从根到树中某个节点的 最长简单路径中的边数 。
 

示例 1：



输入：root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
输出：[2]
解释：上图展示了从树中移除以 4 为根节点的子树。
树的高度是 2（路径为 1 -> 3 -> 2）。
示例 2：



输入：root = [5,8,9,2,1,3,7,4,6], queries = [3,2,4,8]
输出：[3,2,3,2]
解释：执行下述查询：
- 移除以 3 为根节点的子树。树的高度变为 3（路径为 5 -> 8 -> 2 -> 4）。
- 移除以 2 为根节点的子树。树的高度变为 2（路径为 5 -> 8 -> 1）。
- 移除以 4 为根节点的子树。树的高度变为 3（路径为 5 -> 8 -> 2 -> 6）。
- 移除以 8 为根节点的子树。树的高度变为 2（路径为 5 -> 9 -> 3）。
 

提示：

树中节点的数目是 n
2 <= n <= 105
1 <= Node.val <= n
树中的所有值 互不相同
m == queries.length
1 <= m <= min(n, 104)
1 <= queries[i] <= n
queries[i] != root.val

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/height-of-binary-tree-after-subtree-removal-queries
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> ans(queries.size());
        unordered_map<int, int> nodeHeights, nodeLayers;
        unordered_map<int, int> layerHeight1, layerHeight2;

        int rootHeight = getHeights(root, nodeHeights);
        DFS(root, 0, nodeHeights, nodeLayers, layerHeight1, layerHeight2);
        getAnswer(rootHeight, nodeHeights, nodeLayers, layerHeight1, layerHeight2, queries, ans);

        return ans;
    }

    int getHeights(TreeNode* root, unordered_map<int, int>& nodeHeights) {
        if (root == NULL) {
            return -1;
        }

        return nodeHeights[root->val] = max(getHeights(root->left, nodeHeights), getHeights(root->right, nodeHeights)) + 1;
    }

    void DFS(TreeNode* root, int layer, unordered_map<int, int>& nodeHeights, unordered_map<int, int>& nodeLayers,
        unordered_map<int, int>& layerHeight1, unordered_map<int, int>& layerHeight2) {
        if (root != NULL) {
            if (layerHeight1.count(layer) == 0) {
                layerHeight1[layer] = root->val;
            }
            else {
                if (nodeHeights[root->val] >= nodeHeights[layerHeight1[layer]]) {
                    layerHeight2[layer] = layerHeight1[layer];
                    layerHeight1[layer] = root->val;
                }
                else {
                    if (layerHeight2.count(layer) == 0 || nodeHeights[root->val] > nodeHeights[layerHeight2[layer]]) {
                        layerHeight2[layer] = root->val;
                    }
                }
            }

            nodeLayers[root->val] = layer;
            DFS(root->left, layer + 1, nodeHeights, nodeLayers, layerHeight1, layerHeight2);
            DFS(root->right, layer + 1, nodeHeights, nodeLayers, layerHeight1, layerHeight2);
        }
    }

    void getAnswer(int rootHeight, unordered_map<int, int>& nodeHeights, unordered_map<int, int>& nodeLayers,
        unordered_map<int, int>& layerHeight1, unordered_map<int, int>& layerHeight2, vector<int>& queries, vector<int>& ans) {
        int index = 0;

        for (int node : queries) {
            int layer = nodeLayers[node];
            if (node != layerHeight1[layer]) {  // 如果不是删除这一层的第一高度，那么最终树的高度不会改变
                ans[index] = rootHeight;
            }
            else {  // 如果删除了这一层的第一高度，那么树的高度变为第二高度 + layer
                ans[index] = layer + (layerHeight2.count(layer) == 0 ? -1 : nodeHeights[layerHeight2[layer]]);
            }

            ++index;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,3,4,2,INT_MIN,6,5,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,7 };
    vector<int> queries = { 4 };
    vector<int> actual = o.treeQueries(createTree(values), queries);
    vector<int> expected = { 2 };
    check.checkIntVector(expected, actual);

    values = { 5,8,9,2,1,3,7,4,6 };
    queries = { 3,2,4,8 };
    actual = o.treeQueries(createTree(values), queries);
    expected = { 3,2,3,2 };
    check.checkIntVector(expected, actual);

    values = { 1,INT_MIN,5,3,INT_MIN,2,4 };
    queries = { 3,5,4,2,4 };
    actual = o.treeQueries(createTree(values), queries);
    expected = { 1,0,3,3,3 };
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
