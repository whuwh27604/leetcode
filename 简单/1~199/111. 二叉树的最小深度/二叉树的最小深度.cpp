/* 二叉树的最小深度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        if ((root->left != NULL) && (root->right != NULL)) {
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        }

        if ((root->left == NULL) && (root->right == NULL)) {
            return 1;
        }

        if (root->left == NULL) {
            return minDepth(root->right) + 1;
        }

        return minDepth(root->left) + 1;
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
    check.checkInt(2, o.minDepth(&node1));

    node1.left = node1.right = NULL;
    check.checkInt(1, o.minDepth(&node1));

    node1.left = &node2;
    check.checkInt(2, o.minDepth(&node1));

    TreeNode node6(25);
    node1.left = NULL;
    node1.right = &node2;
    node2.left = &node3;
    node2.right = &node4;
    node3.left = &node5;
    node3.right = NULL;
    node4.left = NULL;
    node4.right = &node6;
    node5.left = node5.right = NULL;
    check.checkInt(4, o.minDepth(&node1));

    check.checkInt(0, o.minDepth(NULL));
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
