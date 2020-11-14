/* 翻转二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1
备注:
这个问题是受到 Max Howell 的 原问题 启发的 ：

谷歌：我们90％的工程师使用您编写的软件(Homebrew)，但是您却无法在面试时在白板上写出翻转二叉树这道题，这太糟糕了。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/invert-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        stack<TreeNode*> toInvertNode;
        toInvertNode.push(root);

        while (!toInvertNode.empty()) {
            TreeNode* node = toInvertNode.top();
            toInvertNode.pop();

            if (node->left != NULL) {
                toInvertNode.push(node->left);
            }
            if (node->right != NULL) {
                toInvertNode.push(node->right);
            }

            swap(node->left, node->right);
        }

        return root;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode node1(4);
    TreeNode node2(2);
    TreeNode node3(7);
    TreeNode node4(1);
    TreeNode node5(3);
    TreeNode node6(6);
    TreeNode node7(9);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    TreeNode* actual = o.invertTree(&node1);
    check.checkInt(4, actual->val);
    check.checkInt(7, actual->left->val);
    check.checkInt(2, actual->right->val);
    check.checkInt(9, actual->left->left->val);
    check.checkInt(6, actual->left->right->val);
    check.checkInt(3, actual->right->left->val);
    check.checkInt(1, actual->right->right->val);

    check.checkInt(NULL, (int)o.invertTree(NULL));

    node1.left = NULL;
    node1.right = NULL;
    actual = o.invertTree(&node1);
    check.checkInt(4, actual->val);
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
