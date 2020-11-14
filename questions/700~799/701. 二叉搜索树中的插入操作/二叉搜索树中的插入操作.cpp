/* 二叉搜索树中的插入操作.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 保证原始二叉搜索树中不存在新值。

注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果。

例如, 

给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和 插入的值: 5
你可以返回这个二叉搜索树:

         4
       /   \
      2     7
     / \   /
    1   3 5
或者这个树也是有效的:

         5
       /   \
      2     7
     / \
    1   3
         \
          4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-into-a-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }

        TreeNode* node = root;
        TreeNode* last = root;

        while (node != NULL) {
            last = node;
            node = (node->val > val) ? node->left : node->right;
        }

        node = new TreeNode(val);
        if (last->val > val) {
            last->left = node;
        }
        else {
            last->right = node;
        }

        return root;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode* actual = o.insertIntoBST(NULL, 5);
    check.checkInt(5, actual->val);

    TreeNode node1(7);
    TreeNode node2(3);
    TreeNode node3(9);
    TreeNode node4(1);
    TreeNode node5(5);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    actual = o.insertIntoBST(&node1, 0);
    check.checkInt(7, actual->val);
    check.checkInt(3, actual->left->val);
    check.checkInt(9, actual->right->val);
    check.checkInt(1, actual->left->left->val);
    check.checkInt(5, actual->left->right->val);
    check.checkInt(0, actual->left->left->left->val);
    actual = o.insertIntoBST(&node1, 2);
    check.checkInt(2, actual->left->left->right->val);
    actual = o.insertIntoBST(&node1, 4);
    check.checkInt(4, actual->left->right->left->val);
    actual = o.insertIntoBST(&node1, 6);
    check.checkInt(6, actual->left->right->right->val);
    actual = o.insertIntoBST(&node1, 8);
    check.checkInt(8, actual->right->left->val);
    actual = o.insertIntoBST(&node1, 10);
    check.checkInt(10, actual->right->right->val);

    node1.val = 3;
    node1.left = node1.right = NULL;
    actual = o.insertIntoBST(&node1, 2);
    check.checkInt(2, actual->left->val);
    actual = o.insertIntoBST(&node1, 4);
    check.checkInt(4, actual->right->val);
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
