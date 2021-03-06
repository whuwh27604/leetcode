﻿/* 二叉树的层序遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

 

示例：
二叉树：[3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <list>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> allValues;
        if (root == NULL) {
            return allValues;
        }

        list<TreeNode*> allNodes;
        allNodes.push_back(root);

        int i = 0, j;
        while (!allNodes.empty()) {
            int len = allNodes.size();
            allValues.push_back(vector<int>(len, 0));

            for (j = 0; j < len; j++) {
                TreeNode* node = allNodes.front();
                allNodes.pop_front();
                allValues[i][j] = node->val;

                if (node->left != NULL) {
                    allNodes.push_back(node->left);
                }
                if (node->right != NULL) {
                    allNodes.push_back(node->right);
                }
            }

            i++;
        }

        return allValues;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode node1(3);
    TreeNode node2(9);
    TreeNode node3(20);
    TreeNode node4(15);
    TreeNode node5(7);
    node1.left = &node2;
    node1.right = &node3;
    node3.left = &node4;
    node3.right = &node5;
    vector<vector<int>> actual = o.levelOrder(&node1);
    vector<vector<int>> expected = { {3},{9,20},{15,7} };
    check.checkIntVectorVector(expected, actual);

    actual = o.levelOrder(NULL);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    node1.left = node1.right = NULL;
    actual = o.levelOrder(&node1);
    expected = { {3} };
    check.checkIntVectorVector(expected, actual);

    node1.left = &node2;
    node1.right = &node3;
    node2.left = node2.right = NULL;
    node3.left = node3.right = NULL;
    actual = o.levelOrder(&node1);
    expected = { {3},{9,20} };
    check.checkIntVectorVector(expected, actual);

    node1.left = &node2;
    node1.right = NULL;
    node2.left = &node3;
    node2.right = NULL;
    node3.left = &node4;
    node3.right = NULL;
    node4.left = NULL;
    node4.right = NULL;
    actual = o.levelOrder(&node1);
    expected = { {3},{9},{20},{15} };
    check.checkIntVectorVector(expected, actual);
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
