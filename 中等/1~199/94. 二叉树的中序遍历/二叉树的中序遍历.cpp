/* 二叉树的中序遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }

        stack<pair<TreeNode*, bool>> allNodes;
        allNodes.push({ root, false });

        while (!allNodes.empty()) {
            TreeNode* node = allNodes.top().first;
            bool output = allNodes.top().second;
            allNodes.pop();

            if (output) {
                ans.push_back(node->val);
            }
            else {
                if (node->right != NULL) {
                    allNodes.push({ node->right, false });
                }

                allNodes.push({ node,true });

                if (node->left != NULL) {
                    allNodes.push({ node->left, false });
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    TreeNode node7(7);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    vector<int> actual = o.inorderTraversal(&node1);
    vector<int> expected = { 4,2,5,1,6,3,7 };
    check.checkIntVector(expected, actual);

    actual = o.inorderTraversal(NULL);
    expected = {  };
    check.checkIntVector(expected, actual);

    node1.left = node1.right = NULL;
    actual = o.inorderTraversal(&node1);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    node1.left = NULL;
    node1.right = &node2;
    node2.left = &node3;
    node2.right = NULL;
    node3.left = node3.right = NULL;
    actual = o.inorderTraversal(&node1);
    expected = { 1,3,2 };
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
