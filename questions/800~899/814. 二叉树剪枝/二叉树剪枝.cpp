/* 二叉树剪枝.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定二叉树根结点 root ，此外树的每个结点的值要么是 0，要么是 1。

返回移除了所有不包含 1 的子树的原二叉树。

( 节点 X 的子树为 X 本身，以及所有 X 的后代。)

示例1:
输入: [1,null,0,0,1]
输出: [1,null,0,null,1]

解释:
只有红色节点满足条件“所有不包含 1 的子树”。
右图为返回的答案。


示例2:
输入: [1,0,1,0,0,0,1]
输出: [1,null,1,null,1]



示例3:
输入: [1,1,0,1,1,0,1,0]
输出: [1,1,0,1,1,null,1]



说明:

给定的二叉树最多有 100 个节点。
每个节点的值只会为 0 或 1 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-pruning
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        return ((root == NULL) || DFS(root)) ? root : NULL;
    }

    bool DFS(TreeNode* root) {
        bool containingOne = (root->val == 1);

        if (root->left != NULL) {
            if (!DFS(root->left)) {
                root->left = NULL;
            }
            else {
                containingOne = true;
            }
        }

        if (root->right != NULL) {
            if (!DFS(root->right)) {
                root->right = NULL;
            }
            else {
                containingOne = true;
            }
        }

        return containingOne;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkPoint(NULL, o.pruneTree(NULL));

    TreeNode node1(0);
    check.checkPoint(NULL, o.pruneTree(&node1));

    node1.val = 1;
    check.checkPoint(&node1, o.pruneTree(&node1));

    node1.val = 1;
    TreeNode node2(0);
    TreeNode node3(0);
    TreeNode node4(1);
    node1.left = NULL;
    node1.right = &node2;
    node2.left = &node3;
    node2.right = &node4;
    TreeNode* actual = o.pruneTree(&node1);
    check.checkPoint(&node1, actual);
    check.checkPoint(NULL, actual->left);
    check.checkPoint(&node2, actual->right);
    check.checkPoint(NULL, actual->right->left);
    check.checkPoint(&node4, actual->right->right);

    node1.val = 1;
    node2.val = 0;
    node3.val = 1;
    node4.val = 0;
    TreeNode node5(0);
    TreeNode node6(0);
    TreeNode node7(1);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    node4.left = node4.right = NULL;
    node5.left = node5.right = NULL;
    node6.left = node6.right = NULL;
    node7.left = node7.right = NULL;
    actual = o.pruneTree(&node1);
    check.checkPoint(&node1, actual);
    check.checkPoint(NULL, actual->left);
    check.checkPoint(&node3, actual->right);
    check.checkPoint(NULL, actual->right->left);
    check.checkPoint(&node7, actual->right->right);

    node1.val = 1;
    node2.val = 1;
    node3.val = 0;
    node4.val = 1;
    node5.val = 1;
    node6.val = 0;
    node7.val = 1;
    TreeNode node8(0);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    node4.left = &node8;
    node4.right = NULL;
    node5.left = node5.right = NULL;
    node6.left = node6.right = NULL;
    node7.left = node7.right = NULL;
    node8.left = node8.right = NULL;
    actual = o.pruneTree(&node1);
    check.checkPoint(&node1, actual);
    check.checkPoint(&node2, actual->left);
    check.checkPoint(&node3, actual->right);
    check.checkPoint(&node4, actual->left->left);
    check.checkPoint(&node5, actual->left->right);
    check.checkPoint(NULL, actual->right->left);
    check.checkPoint(&node7, actual->right->right);
    check.checkPoint(NULL, actual->left->left->left);
    check.checkPoint(NULL, actual->left->left->right);
    check.checkPoint(NULL, actual->left->right->left);
    check.checkPoint(NULL, actual->left->right->right);
    check.checkPoint(NULL, actual->right->right->left);
    check.checkPoint(NULL, actual->right->right->right);
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
