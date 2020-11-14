/* 二叉树的右视图.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-right-side-view
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <list>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightNodes;
        if (root == NULL) {
            return rightNodes;
        }

        list<TreeNode*> nodes;
        nodes.push_back(root);

        while (!nodes.empty()) {
            rightNodes.push_back(nodes.back()->val);

            int size = nodes.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = nodes.front();
                nodes.pop_front();

                if (node->left != NULL) {
                    nodes.push_back(node->left);
                }
                if (node->right != NULL) {
                    nodes.push_back(node->right);
                }
            }
        }

        return rightNodes;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> actual = o.rightSideView(NULL);
    vector<int> expected = {};
    check.checkIntVector(expected, actual);

    TreeNode node1(1);
    actual = o.rightSideView(&node1);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    TreeNode node2(2);
    node1.left = &node2;
    actual = o.rightSideView(&node1);
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    TreeNode node3(3);
    node1.left = &node2;
    node1.right = &node3;
    actual = o.rightSideView(&node1);
    expected = { 1,3 };
    check.checkIntVector(expected, actual);

    TreeNode node4(4);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    actual = o.rightSideView(&node1);
    expected = { 1,3,4 };
    check.checkIntVector(expected, actual);

    TreeNode node5(5);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    actual = o.rightSideView(&node1);
    expected = { 1,3,5 };
    check.checkIntVector(expected, actual);

    node2.right = &node5;
    node3.right = &node4;
    actual = o.rightSideView(&node1);
    expected = { 1,3,4 };
    check.checkIntVector(expected, actual);

    node1.left = &node2;
    node1.right = NULL;
    node2.left = NULL;
    node2.right = &node3;
    node3.left = &node4;
    node3.right = NULL;
    node4.left = NULL;
    node4.right = &node5;
    node5.left = node5.right = NULL;
    actual = o.rightSideView(&node1);
    expected = { 1,2,3,4,5 };
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
