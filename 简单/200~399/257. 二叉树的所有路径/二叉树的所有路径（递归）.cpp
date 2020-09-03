/* 二叉树的所有路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

示例:

输入:

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]

解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> allPaths;
        if (root == NULL) {
            return allPaths;
        }

        DLR(root, "", allPaths);
        return allPaths;
    }

    void DLR(TreeNode* root, string path, vector<string>& paths) {
        if (!path.empty()) {
            path += "->";
        }
        path += to_string(root->val);

        if ((root->left == NULL) && (root->right == NULL)) {
            paths.push_back(path);
            return;
        }

        if (root->left != NULL) {
            DLR(root->left, path, paths);
        }

        if (root->right != NULL) {
            DLR(root->right, path, paths);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<string> actual = o.binaryTreePaths(NULL);
    vector<string> expected = {};
    check.checkStringVector(expected, actual);

    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node5(5);
    node1.left = &node2;
    node1.right = &node3;
    node2.right = &node5;
    actual = o.binaryTreePaths(&node1);
    expected = { "1->2->5","1->3" };
    check.checkStringVector(expected, actual);

    node1.left = node1.right = NULL;
    actual = o.binaryTreePaths(&node1);
    expected = { "1" };
    check.checkStringVector(expected, actual);

    node1.left = NULL;
    node1.right = &node3;
    node3.left = node3.right = NULL;
    actual = o.binaryTreePaths(&node1);
    expected = { "1->3" };
    check.checkStringVector(expected, actual);

    TreeNode node4(4);
    TreeNode node6(6);
    TreeNode node7(7);
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
    actual = o.binaryTreePaths(&node1);
    expected = { "1->2->4->8","1->2->4->9","1->2->5->10","1->2->5->11","1->3->6->12","1->3->6->13","1->3->7->14","1->3->7->15" };
    check.checkStringVector(expected, actual);
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
