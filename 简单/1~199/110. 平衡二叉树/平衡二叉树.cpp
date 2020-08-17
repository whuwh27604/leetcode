/* 平衡二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

示例 1:

给定二叉树 [3,9,20,null,null,15,7]

    3
   / \
  9  20
    /  \
   15   7
返回 true 。

示例 2:

给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/balanced-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        int height;
        return isHeightBalanced(root, height);
    }

    bool isHeightBalanced(TreeNode* root, int& height) {
        int leftHeight = 0, rightHeight = 0;
        bool leftBalanced = (root->left == NULL) ? true : isHeightBalanced(root->left, leftHeight);
        bool rightBalanced = (root->right == NULL) ? true : isHeightBalanced(root->right, rightHeight);
        height = max(leftHeight, rightHeight) + 1;

        return (leftBalanced && rightBalanced && (abs(leftHeight - rightHeight) <= 1));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode node4(15);
    TreeNode node5(7);
    TreeNode node2(9);
    TreeNode node3(20);
    node3.left = &node4;
    node3.right = &node5;
    TreeNode node1(3);
    node1.left = &node2;
    node1.right = &node3;
    check.checkBool(true, o.isBalanced(&node1));

    TreeNode node6(4);
    TreeNode node7(4);
    node4.val = 3;
    node4.left = &node6;
    node4.right = &node7;
    node5.left = node5.right = NULL;
    node2.val = 2;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = node3.right = NULL;
    node1.val = 1;
    check.checkBool(false, o.isBalanced(&node1));

    check.checkBool(true, o.isBalanced(NULL));
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
