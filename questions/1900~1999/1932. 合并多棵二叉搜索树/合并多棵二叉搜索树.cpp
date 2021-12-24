/* 合并多棵二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你 n 个 二叉搜索树的根节点 ，存储在数组 trees 中（下标从 0 开始），对应 n 棵不同的二叉搜索树。trees 中的每棵二叉搜索树 最多有 3 个节点 ，且不存在值相同的两个根节点。在一步操作中，将会完成下述步骤：

选择两个 不同的 下标 i 和 j ，要求满足在 trees[i] 中的某个 叶节点 的值等于 trees[j] 的 根节点的值 。
用 trees[j] 替换 trees[i] 中的那个叶节点。
从 trees 中移除 trees[j] 。
如果在执行 n - 1 次操作后，能形成一棵有效的二叉搜索树，则返回结果二叉树的 根节点 ；如果无法构造一棵有效的二叉搜索树，返回 null 。

二叉搜索树是一种二叉树，且树中每个节点均满足下述属性：

任意节点的左子树中的值都 严格小于 此节点的值。
任意节点的右子树中的值都 严格大于 此节点的值。
叶节点是不含子节点的节点。

 

示例 1：


输入：trees = [[2,1],[3,2,5],[5,4]]
输出：[3,2,5,1,null,4]
解释：
第一步操作中，选出 i=1 和 j=0 ，并将 trees[0] 合并到 trees[1] 中。
删除 trees[0] ，trees = [[3,2,5,1],[5,4]] 。

在第二步操作中，选出 i=0 和 j=1 ，将 trees[1] 合并到 trees[0] 中。
删除 trees[1] ，trees = [[3,2,5,1,null,4]] 。

结果树如上图所示，为一棵有效的二叉搜索树，所以返回该树的根节点。
示例 2：


输入：trees = [[5,3,8],[3,2,6]]
输出：[]
解释：
选出 i=0 和 j=1 ，然后将 trees[1] 合并到 trees[0] 中。
删除 trees[1] ，trees = [[5,3,8,2,6]] 。

结果树如上图所示。仅能执行一次有效的操作，但结果树不是一棵有效的二叉搜索树，所以返回 null 。
示例 3：


输入：trees = [[5,4],[3]]
输出：[]
解释：无法执行任何操作。
示例 4：


输入：trees = [[2,1,3]]
输出：[2,1,3]
解释：trees 中只有一棵树，且这棵树已经是一棵有效的二叉搜索树，所以返回该树的根节点。
 

提示：

n == trees.length
1 <= n <= 5 * 104
每棵树中节点数目在范围 [1, 3] 内。
输入数据的每个节点可能有子节点但不存在子节点的子节点
trees 中不存在两棵树根节点值相同的情况。
输入中的所有树都是 有效的二叉树搜索树 。
1 <= TreeNode.val <= 5 * 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-bsts-to-create-single-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode * canMerge(vector<TreeNode*> & trees) {
        unordered_map<int, TreeNode*> hashTrees;
        int minVal = INT_MAX, maxVal = 0;

        for (TreeNode* tree : trees) {
            hashTrees[tree->val] = tree;
        }

        for (auto iter = hashTrees.begin(); iter != hashTrees.end(); ++iter) {
            if (!DFS(iter->second->val, iter->second, hashTrees)) {
                return NULL;
            }
        }

        return (hashTrees.size() != 1 || !isBST(hashTrees.begin()->second, minVal, maxVal)) ? NULL : hashTrees.begin()->second;
    }

    bool DFS(int root, TreeNode * current, unordered_map<int, TreeNode*> & hashTrees) {
        if ((current->left != NULL && current->left->val == root) || (current->right != NULL && current->right->val == root)) {
            return false;  // 叶子节点指向了根节点，形成环路
        }

        if (current->left != NULL && hashTrees.count(current->left->val) != 0) {
            TreeNode* next = hashTrees[current->left->val];
            current->left = next;
            hashTrees.erase(next->val);

            if (!DFS(root, next, hashTrees)) {
                return false;
            }
        }

        if (current->right != NULL && hashTrees.count(current->right->val) != 0) {
            TreeNode* next = hashTrees[current->right->val];
            current->right = next;
            hashTrees.erase(next->val);

            if (!DFS(root, next, hashTrees)) {
                return false;
            }
        }

        return true;
    }

    bool isBST(TreeNode * root, int& minValue, int& maxValue) {
        if (root != NULL) {
            int minVal = INT_MAX, maxVal = 0;

            if (!isBST(root->left, minVal, maxVal) || maxVal >= root->val) {
                return false;
            }

            minValue = min(minVal, root->val);
            minVal = INT_MAX, maxVal = 0;

            if (!isBST(root->right, minVal, maxVal) || minVal <= root->val) {
                return false;
            }

            maxValue = max(maxVal, root->val);
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<TreeNode*> trees;
    vector<int> values = { 2,1 };
    trees.push_back(createTree(values));
    values = { 3,2,5 };
    trees.push_back(createTree(values));
    values = { 5,4 };
    trees.push_back(createTree(values));
    TreeNode* actual = o.canMerge(trees);
    values = { 3,2,5,1,INT_MIN,4 };
    TreeNode* expected = createTree(values);
    check.checkTree(expected, actual);

    trees.clear();
    values = { 5,3,8 };
    trees.push_back(createTree(values));
    values = { 3,2,6 };
    trees.push_back(createTree(values));
    actual = o.canMerge(trees);
    values = {  };
    expected = createTree(values);
    check.checkTree(expected, actual);

    trees.clear();
    values = { 5,3,8 };
    trees.push_back(createTree(values));
    values = { 8,2,9 };
    trees.push_back(createTree(values));
    actual = o.canMerge(trees);
    values = {  };
    expected = createTree(values);
    check.checkTree(expected, actual);

    trees.clear();
    values = { 5,4 };
    trees.push_back(createTree(values));
    values = { 3 };
    trees.push_back(createTree(values));
    actual = o.canMerge(trees);
    values = {  };
    expected = createTree(values);
    check.checkTree(expected, actual);

    trees.clear();
    values = { 2,1,3 };
    trees.push_back(createTree(values));
    actual = o.canMerge(trees);
    values = { 2,1,3 };
    expected = createTree(values);
    check.checkTree(expected, actual);

    trees.clear();
    values = { 1,INT_MIN,3 };
    trees.push_back(createTree(values));
    values = { 3,1 };
    trees.push_back(createTree(values));
    values = { 4,2 };
    trees.push_back(createTree(values));
    actual = o.canMerge(trees);
    values = {  };
    expected = createTree(values);
    check.checkTree(expected, actual);

    trees.clear();
    values = { 1,2 };
    trees.push_back(createTree(values));
    values = { 2,1 };
    trees.push_back(createTree(values));
    values = { 4,5 };
    trees.push_back(createTree(values));
    actual = o.canMerge(trees);
    values = {  };
    expected = createTree(values);
    check.checkTree(expected, actual);
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
