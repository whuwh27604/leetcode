﻿/* 二叉树的前序遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,2,3]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> values;
        if (root == NULL) {
            return values;
        }

        stack<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            TreeNode* node = nodes.top();
            nodes.pop();

            values.push_back(node->val);

            if (node->right != NULL) {
                nodes.push(node->right);
            }
            if (node->left != NULL) {
                nodes.push(node->left);
            }
        }

        return values;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> actual = o.preorderTraversal(NULL);
    vector<int> expected = {};
    check.checkIntVector(expected, actual);

    TreeNode node1(1);
    actual = o.preorderTraversal(&node1);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    TreeNode node2(2);
    node1.left = &node2;
    actual = o.preorderTraversal(&node1);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    node1.left = NULL;
    node1.right = &node2;
    actual = o.preorderTraversal(&node1);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    TreeNode node3(3);
    node1.left = &node2;
    node1.right = &node3;
    actual = o.preorderTraversal(&node1);
    expected = { 1,2,3 };
    check.checkIntVector(expected, actual);

    TreeNode node4(4);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    actual = o.preorderTraversal(&node1);
    expected = { 1,2,4,3 };
    check.checkIntVector(expected, actual);

    node2.left = node2.right = NULL;
    node3.right = &node4;
    actual = o.preorderTraversal(&node1);
    expected = { 1,2,3,4 };
    check.checkIntVector(expected, actual);

    TreeNode node5(5);
    TreeNode node6(6);
    TreeNode node7(7);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    actual = o.preorderTraversal(&node1);
    expected = { 1,2,4,5,3,6,7 };
    check.checkIntVector(expected, actual);

    TreeNode node8(8);
    TreeNode node9(9);
    TreeNode node10(10);
    TreeNode node11(11);
    TreeNode node12(12);
    TreeNode node13(13);
    TreeNode node14(14);
    TreeNode node15(15);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    node4.left = &node8;
    node4.right = &node9;
    node5.left = &node10;
    node5.right = &node11;
    node6.left = &node12;
    node6.right = &node13;
    node7.left = &node14;
    node7.right = &node15;
    actual = o.preorderTraversal(&node1);
    expected = { 1,2,4,8,9,5,10,11,3,6,12,13,7,14,15 };
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
