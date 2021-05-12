/* 删除二叉搜索树中的节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。
说明： 要求算法时间复杂度为 O(h)，h 为树的高度。

示例:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。

一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。

    5
   / \
  4   6
 /     \
2       7

另一个正确答案是 [5,2,6,null,4,null,7]。

    5
   / \
  2   6
   \   \
    4   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-node-in-a-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* target = NULL;
        TreeNode* targetParent = NULL;
        int leftOrRight = 0;

        if (!findTarget(root, key, &target, &targetParent, leftOrRight)) {
            return root;  // target不存在，直接返回root
        }

        if (target->left == NULL) {  // 没有左子树，那么直接用右节点代替target
            return deleteNodeWithNoLeft(root, target, targetParent, leftOrRight);
        }

        return deleteNodeWithLeft(root, target, targetParent, leftOrRight);  // 有左子树，左子树的最大值代替被删的节点
    }

    TreeNode* deleteNodeWithNoLeft(TreeNode* root, TreeNode* target, TreeNode* targetParent, int leftOrRight) {
        if (targetParent == NULL) {  // 删除的是根节点，那么返回它的右节点
            return target->right;
        }
        else {
            leftOrRight == 0 ? targetParent->left = target->right : targetParent->right = target->right;
            return root;
        }
    }

    TreeNode* deleteNodeWithLeft(TreeNode* root, TreeNode* target, TreeNode* targetParent, int leftOrRight) {
        TreeNode* rightmost = target->left;
        TreeNode* rightmostParent = NULL;

        while (rightmost->right != NULL) {
            rightmostParent = rightmost;
            rightmost = rightmost->right;
        }

        if (rightmostParent != NULL) {  // 左子树的最右节点上升为target，它的父节点的右节点指向它的左节点
            rightmostParent->right = rightmost->left;
            rightmost->left = target->left;
            rightmost->right = target->right;
        }
        else {  // 左子树没有右子树，那么左子树的root上升为target
            rightmost->right = target->right;
        }

        if (targetParent == NULL) {  // 删除的是根节点
            rightmost->right = root->right;
            return rightmost;
        }
        else {
            leftOrRight == 0 ? targetParent->left = rightmost : targetParent->right = rightmost;
            return root;
        }
    }

    bool findTarget(TreeNode* root, int key, TreeNode** target, TreeNode** parent, int& leftOrRight) {
        while (root != NULL && root->val != key) {
            if (root->val > key) {
                *parent = root;
                root = root->left;
                leftOrRight = 0;
            }
            else {
                *parent = root;
                root = root->right;
                leftOrRight = 1;
            }
        }

        if (root == NULL) {
            return false;
        }

        *target = root;
        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 5,3,6,2,4,INT_MIN,7 };
    vector<int> expected = { 5,2,6,INT_MIN,4,INT_MIN,7 };
    check.checkTree(createTree(expected), o.deleteNode(createTree(values), 3));

    values = {  };
    expected = {  };
    check.checkTree(createTree(expected), o.deleteNode(createTree(values), 3));

    values = { 3 };
    expected = {  };
    check.checkTree(createTree(expected), o.deleteNode(createTree(values), 3));

    values = { 1 };
    expected = { 1 };
    check.checkTree(createTree(expected), o.deleteNode(createTree(values), 3));

    values = { 6,4,7,3,5,INT_MIN,INT_MIN,1,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2 };
    expected = { 6,4,7,3,5,INT_MIN,INT_MIN,1 };
    check.checkTree(createTree(expected), o.deleteNode(createTree(values), 2));

    values = { 6,4,7,3,5,INT_MIN,INT_MIN,1,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2 };
    expected = { 6,4,7,3,5,INT_MIN,INT_MIN,2 };
    check.checkTree(createTree(expected), o.deleteNode(createTree(values), 1));

    values = { 6,4,7,3,5,INT_MIN,INT_MIN,1,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2 };
    expected = { 6,4,7,2,5,INT_MIN,INT_MIN,1 };
    check.checkTree(createTree(expected), o.deleteNode(createTree(values), 3));

    values = { 6,4,7,3,5,INT_MIN,INT_MIN,1,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2 };
    expected = { 6,3,7,1,5,INT_MIN,INT_MIN,INT_MIN,2 };
    check.checkTree(createTree(expected), o.deleteNode(createTree(values), 4));

    values = { 6,4,7,3,5,INT_MIN,INT_MIN,1,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2 };
    expected = { 5,4,7,3,INT_MIN,INT_MIN,INT_MIN,1,INT_MIN,INT_MIN,2 };
    check.checkTree(createTree(expected), o.deleteNode(createTree(values), 6));

    values = { 6,4,7,3,5,INT_MIN,INT_MIN,1,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2 };
    expected = { 6,4,INT_MIN,3,5,1,INT_MIN,INT_MIN,INT_MIN,INT_MIN,2 };
    check.checkTree(createTree(expected), o.deleteNode(createTree(values), 7));

    values = { 1,INT_MIN,5,3,7,2,4,6,8 };
    expected = { 5,3,7,2,4,6,8 };
    check.checkTree(createTree(expected), o.deleteNode(createTree(values), 1));

    values = { 1,INT_MIN,5,3,7,2,4,6,8 };
    expected = { 1,INT_MIN,4,3,7,2,INT_MIN,6,8 };
    check.checkTree(createTree(expected), o.deleteNode(createTree(values), 5));

    values = { 1,INT_MIN,5,3,7,2,4,6,8 };
    expected = { 1,INT_MIN,5,2,7,INT_MIN,4,6,8 };
    check.checkTree(createTree(expected), o.deleteNode(createTree(values), 3));

    values = { 1,INT_MIN,5,3,7,2,4,6,8 };
    expected = { 1,INT_MIN,5,3,7,2,INT_MIN,6,8 };
    check.checkTree(createTree(expected), o.deleteNode(createTree(values), 4));

    values = { 1,INT_MIN,5,3,7,2,4,6,8 };
    expected = { 1,INT_MIN,5,3,6,2,4,INT_MIN,8 };
    check.checkTree(createTree(expected), o.deleteNode(createTree(values), 7));

    values = { 1,INT_MIN,5,3,7,2,4,6,8 };
    expected = { 1,INT_MIN,5,3,7,2,4,INT_MIN,8 };
    check.checkTree(createTree(expected), o.deleteNode(createTree(values), 6));

    values = { 1,0,15,INT_MIN,INT_MIN,4,35,3,8,25,49,2,INT_MIN,5,12,22,27,47,INT_MIN,INT_MIN,INT_MIN,INT_MIN,7,11,13,19,24,26,31,40,48,6,INT_MIN,9,INT_MIN,INT_MIN,14,17,21,23,INT_MIN,INT_MIN,INT_MIN,30,33,39,42,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,10,INT_MIN,INT_MIN,16,18,20,INT_MIN,INT_MIN,INT_MIN,28,INT_MIN,32,34,36,INT_MIN,41,44,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,29,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,37,INT_MIN,INT_MIN,43,46,INT_MIN,INT_MIN,INT_MIN,38,INT_MIN,INT_MIN,45 };
    expected = { 1,0,15,INT_MIN,INT_MIN,4,35,3,8,25,49,2,INT_MIN,5,12,21,27,47,INT_MIN,INT_MIN,INT_MIN,INT_MIN,7,11,13,19,24,26,31,40,48,6,INT_MIN,9,INT_MIN,INT_MIN,14,17,20,23,INT_MIN,INT_MIN,INT_MIN,30,33,39,42,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,10,INT_MIN,INT_MIN,16,18,INT_MIN,INT_MIN,INT_MIN,INT_MIN,28,INT_MIN,32,34,36,INT_MIN,41,44,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,29,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,37,INT_MIN,INT_MIN,43,46,INT_MIN,INT_MIN,INT_MIN,38,INT_MIN,INT_MIN,45 };
    check.checkTree(createTree(expected), o.deleteNode(createTree(values), 22));
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
