/* 在二叉树中增加一行.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，根节点为第1层，深度为 1。在其第 d 层追加一行值为 v 的节点。

添加规则：给定一个深度值 d （正整数），针对深度为 d-1 层的每一非空节点 N，为 N 创建两个值为 v 的左子树和右子树。

将 N 原先的左子树，连接为新节点 v 的左子树；将 N 原先的右子树，连接为新节点 v 的右子树。

如果 d 的值为 1，深度 d - 1 不存在，则创建一个新的根节点 v，原先的整棵树将作为 v 的左子树。

示例 1:

输入:
二叉树如下所示:
       4
     /   \
    2     6
   / \   /
  3   1 5

v = 1

d = 2

输出:
       4
      / \
     1   1
    /     \
   2       6
  / \     /
 3   1   5

示例 2:

输入:
二叉树如下所示:
      4
     /
    2
   / \
  3   1

v = 1

d = 3

输出:
      4
     /
    2
   / \
  1   1
 /     \
3       1
注意:

输入的深度值 d 的范围是：[1，二叉树最大深度 + 1]。
输入的二叉树至少有一个节点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-one-row-to-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;

            return newRoot;
        }

        DFS(root, 2, v, d);

        return root;
    }

    void DFS(TreeNode* root, int layer, int v, int d) {
        if (layer == d) {
            TreeNode* left = new TreeNode(v);
            TreeNode* right = new TreeNode(v);
            left->left = root->left;
            right->right = root->right;
            root->left = left;
            root->right = right;
            return;
        }

        if (root->left != NULL) {
            DFS(root->left, layer + 1, v, d);
        }

        if (root->right != NULL) {
            DFS(root->right, layer + 1, v, d);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode node1(1);
    TreeNode* actual = o.addOneRow(&node1, 2, 1);
    check.checkInt(2, actual->val);
    check.checkInt(1, actual->left->val);
    check.checkPoint(NULL, actual->right);
    check.checkPoint(NULL, actual->left->left);
    check.checkPoint(NULL, actual->left->right);

    TreeNode node2(2);
    TreeNode node3(6);
    TreeNode node4(3);
    TreeNode node5(1);
    TreeNode node6(5);
    node1.val = 4;
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    actual = o.addOneRow(&node1, 1, 2);
    check.checkInt(4, actual->val);
    check.checkInt(1, actual->left->val);
    check.checkInt(1, actual->right->val);
    check.checkInt(2, actual->left->left->val);
    check.checkInt(6, actual->right->right->val);
    check.checkInt(3, actual->left->left->left->val);
    check.checkInt(1, actual->left->left->right->val);
    check.checkInt(5, actual->right->right->left->val);

    node1.left = &node2;
    node1.right = NULL;
    node2.left = &node4;
    node2.right = &node5;
    actual = o.addOneRow(&node1, 1, 3);
    check.checkInt(4, actual->val);
    check.checkInt(2, actual->left->val);
    check.checkInt(1, actual->left->left->val);
    check.checkInt(1, actual->left->right->val);
    check.checkInt(3, actual->left->left->left->val);
    check.checkInt(1, actual->left->right->right->val);

    node1.left = &node2;
    node1.right = NULL;
    node2.left = &node4;
    node2.right = &node5;
    actual = o.addOneRow(&node1, 1, 4);
    check.checkInt(4, actual->val);
    check.checkInt(2, actual->left->val);
    check.checkInt(3, actual->left->left->val);
    check.checkInt(1, actual->left->right->val);
    check.checkInt(1, actual->left->left->left->val);
    check.checkInt(1, actual->left->left->right->val);
    check.checkInt(1, actual->left->right->left->val);
    check.checkInt(1, actual->left->right->right->val);

    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node4.val = 4;
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = NULL;
    node3.left = node3.right = NULL;
    node4.left = node4.right = NULL;
    actual = o.addOneRow(&node1, 5, 4);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->left->val);
    check.checkInt(3, actual->right->val);
    check.checkInt(4, actual->left->left->val);
    check.checkPoint(NULL, actual->left->right);
    check.checkInt(5, actual->left->left->left->val);
    check.checkInt(5, actual->left->left->right->val);
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
