/* 二叉树展开为链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，原地将它展开为一个单链表。

 

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        (void)flattenSubTree(root);
    }

    TreeNode* flattenSubTree(TreeNode* root) {
        TreeNode *leftHead = root->left, *leftTail = NULL, *rightHead = root->right, *rightTail = NULL, *tail = root;

        if (root->left != NULL) {
            leftTail = flattenSubTree(root->left);
        }

        if (root->right != NULL) {
            rightTail = flattenSubTree(root->right);
        }

        if (leftTail != NULL) {
            tail->right = leftHead;
            tail = leftTail;
        }

        if (rightTail != NULL) {
            tail->right = rightHead;
            tail = rightTail;
        }

        root->left = NULL;
        return tail;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode* root = NULL;
    o.flatten(root);
    check.checkPoint(NULL, root);

    TreeNode node1(1);
    o.flatten(&node1);
    check.checkInt(1, node1.val);
    check.checkPoint(NULL, node1.left);
    check.checkPoint(NULL, node1.right);

    TreeNode node2(2);
    node1.left = &node2;
    node1.right = NULL;
    node2.left = node2.right = NULL;
    o.flatten(&node1);
    check.checkInt(1, node1.val);
    check.checkInt(2, node1.right->val);
    check.checkPoint(NULL, node1.left);
    check.checkPoint(NULL, node2.left);
    check.checkPoint(NULL, node2.right);

    node1.left = NULL;
    node1.right = &node2;
    node2.left = node2.right = NULL;
    o.flatten(&node1);
    check.checkInt(1, node1.val);
    check.checkInt(2, node1.right->val);
    check.checkPoint(NULL, node1.left);
    check.checkPoint(NULL, node2.left);
    check.checkPoint(NULL, node2.right);

    TreeNode node3(3);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = node2.right = NULL;
    node3.left = node3.right = NULL;
    o.flatten(&node1);
    check.checkInt(1, node1.val);
    check.checkInt(2, node1.right->val);
    check.checkInt(3, node1.right->right->val);
    check.checkPoint(NULL, node1.left);
    check.checkPoint(NULL, node2.left);
    check.checkPoint(NULL, node3.left);
    check.checkPoint(NULL, node3.right);

    TreeNode node4(4);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = NULL;
    node3.left = node3.right = NULL;
    node4.left = node4.right = NULL;
    o.flatten(&node1);
    check.checkInt(1, node1.val);
    check.checkInt(2, node1.right->val);
    check.checkInt(4, node1.right->right->val);
    check.checkInt(3, node1.right->right->right->val);
    check.checkPoint(NULL, node1.left);
    check.checkPoint(NULL, node2.left);
    check.checkPoint(NULL, node4.left);
    check.checkPoint(NULL, node3.left);
    check.checkPoint(NULL, node3.right);

    node1.left = &node2;
    node1.right = &node3;
    node2.left = NULL;
    node2.right = &node4;
    node3.left = node3.right = NULL;
    node4.left = node4.right = NULL;
    o.flatten(&node1);
    check.checkInt(1, node1.val);
    check.checkInt(2, node1.right->val);
    check.checkInt(4, node1.right->right->val);
    check.checkInt(3, node1.right->right->right->val);
    check.checkPoint(NULL, node1.left);
    check.checkPoint(NULL, node2.left);
    check.checkPoint(NULL, node4.left);
    check.checkPoint(NULL, node3.left);
    check.checkPoint(NULL, node3.right);

    node1.left = &node2;
    node1.right = &node3;
    node2.left = node2.right = NULL;
    node3.left = &node4;
    node3.right = NULL;
    node4.left = node4.right = NULL;
    o.flatten(&node1);
    check.checkInt(1, node1.val);
    check.checkInt(2, node1.right->val);
    check.checkInt(3, node1.right->right->val);
    check.checkInt(4, node1.right->right->right->val);
    check.checkPoint(NULL, node1.left);
    check.checkPoint(NULL, node2.left);
    check.checkPoint(NULL, node3.left);
    check.checkPoint(NULL, node4.left);
    check.checkPoint(NULL, node4.right);

    node1.left = &node2;
    node1.right = &node3;
    node2.left = node2.right = NULL;
    node3.left = NULL;
    node3.right = &node4;
    node4.left = node4.right = NULL;
    o.flatten(&node1);
    check.checkInt(1, node1.val);
    check.checkInt(2, node1.right->val);
    check.checkInt(3, node1.right->right->val);
    check.checkInt(4, node1.right->right->right->val);
    check.checkPoint(NULL, node1.left);
    check.checkPoint(NULL, node2.left);
    check.checkPoint(NULL, node3.left);
    check.checkPoint(NULL, node4.left);
    check.checkPoint(NULL, node4.right);

    TreeNode node5(5);
    TreeNode node6(6);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = NULL;
    node3.right = &node6;
    node4.left = node4.right = NULL;
    node5.left = node5.right = NULL;
    node6.left = node6.right = NULL;
    o.flatten(&node1);
    check.checkInt(1, node1.val);
    check.checkInt(2, node1.right->val);
    check.checkInt(4, node1.right->right->val);
    check.checkInt(5, node1.right->right->right->val);
    check.checkInt(3, node1.right->right->right->right->val);
    check.checkInt(6, node1.right->right->right->right->right->val);
    check.checkPoint(NULL, node1.left);
    check.checkPoint(NULL, node2.left);
    check.checkPoint(NULL, node4.left);
    check.checkPoint(NULL, node5.left);
    check.checkPoint(NULL, node3.left);
    check.checkPoint(NULL, node6.left);
    check.checkPoint(NULL, node6.right);
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
