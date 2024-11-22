/* 装饰树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
力扣嘉年华上的 DIY 手工展位准备了一棵缩小版的 二叉 装饰树 root 和灯饰，你需要将灯饰逐一插入装饰树中，要求如下：

完成装饰的二叉树根结点与 root 的根结点值相同
若一个节点拥有父节点，则在该节点和他的父节点之间插入一个灯饰（即插入一个值为 -1 的节点）。具体地：
在一个 父节点 x 与其左子节点 y 之间添加 -1 节点， 节点 -1、节点 y 为各自父节点的左子节点，
在一个 父节点 x 与其右子节点 y 之间添加 -1 节点， 节点 -1、节点 y 为各自父节点的右子节点，
现给定二叉树的根节点 root ，请返回完成装饰后的树的根节点。 示例 1：

输入： root = [7,5,6]

输出：[7,-1,-1,5,null,null,6]

解释：如下图所示，image.png

示例 2：

输入： root = [3,1,7,3,8,null,4]

输出：[3,-1,-1,1,null,null,7,-1,-1,null,-1,3,null,null,8,null,4]

解释：如下图所示image.png

提示：

0 <= root.Val <= 1000 root 节点数量范围为 [1, 10^5]
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* expandBinaryTree(TreeNode* root) {
        DFS(root, NULL, 0);

        return root;
    }

    void DFS(TreeNode* node, TreeNode* parent, int lr) {
        if (node == NULL) {
            return;
        }

        DFS(node->left, node, 0);
        DFS(node->right, node, 1);

        if (parent != NULL) {
            TreeNode* insert = new TreeNode(-1);
            if (lr == 0) {
                parent->left = insert;
                insert->left = node;
            }
            else {
                parent->right = insert;
                insert->right = node;
            }
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 7,5,6 };
    TreeNode* actual = o.expandBinaryTree(createTree(values));
    values = { 7,-1,-1,5,INT_MIN,INT_MIN,6 };
    check.checkTree(createTree(values), actual);

    values = { 3,1,7,3,8,INT_MIN,4 };
    actual = o.expandBinaryTree(createTree(values));
    values = { 3,-1,-1,1,INT_MIN,INT_MIN,7,-1,-1,INT_MIN,-1,3,INT_MIN,INT_MIN,8,INT_MIN,4 };
    check.checkTree(createTree(values), actual);
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
