/* 二叉树最大宽度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，编写一个函数来获取这个树的最大宽度。树的宽度是所有层中的最大宽度。这个二叉树与满二叉树（full binary tree）结构相同，但一些节点为空。

每一层的宽度被定义为两个端点（该层最左和最右的非空节点，两端点间的null节点也计入长度）之间的长度。

示例 1:

输入:

           1
         /   \
        3     2
       / \     \
      5   3     9

输出: 4
解释: 最大值出现在树的第 3 层，宽度为 4 (5,3,null,9)。
示例 2:

输入:

          1
         /
        3
       / \
      5   3

输出: 2
解释: 最大值出现在树的第 3 层，宽度为 2 (5,3)。
示例 3:

输入:

          1
         / \
        3   2
       /
      5

输出: 2
解释: 最大值出现在树的第 2 层，宽度为 2 (3,2)。
示例 4:

输入:

          1
         / \
        3   2
       /     \
      5       9
     /         \
    6           7
输出: 8
解释: 最大值出现在树的第 4 层，宽度为 8 (6,null,null,null,null,null,null,7)。
注意: 答案在32位有符号整数的表示范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-width-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int maxWidth = 0;
        vector<unsigned long long> leftMostValues;
        DFS(root, 0, 1, leftMostValues, maxWidth);

        return maxWidth + 1;
    }

    void DFS(TreeNode* root, int layer, unsigned long long value, vector<unsigned long long>& leftMostValues, int& maxWidth) {
        if ((int)leftMostValues.size() <= layer) {
            leftMostValues.push_back(value);
        }
        else {
            int width = (int)(value - leftMostValues[layer]);
            maxWidth = max(maxWidth, width);
        }

        if (root->left != NULL) {
            DFS(root->left, layer + 1, 2 * value - 1, leftMostValues, maxWidth);
        }

        if (root->right != NULL) {
            DFS(root->right, layer + 1, 2 * value, leftMostValues, maxWidth);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.widthOfBinaryTree(NULL));

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
    node2.right = NULL;
    node3.left = NULL;
    node3.right = &node5;
    node4.left = &node6;
    node4.right = NULL;
    node5.left = NULL;
    node5.right = &node7;
    check.checkInt(8, o.widthOfBinaryTree(&node1));

    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = NULL;
    node3.left = node3.right = NULL;
    node4.left = node4.right = NULL;
    check.checkInt(2, o.widthOfBinaryTree(&node1));

    node1.left = &node2;
    node1.right = NULL;
    node2.left = &node3;
    node2.right = &node4;
    node3.left = node3.right = NULL;
    node4.left = node4.right = NULL;
    check.checkInt(2, o.widthOfBinaryTree(&node1));

    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = NULL;
    node3.right = &node6;
    node4.left = node4.right = NULL;
    node5.left = node5.right = NULL;
    node6.left = node6.right = NULL;
    check.checkInt(4, o.widthOfBinaryTree(&node1));

    node1.left = node1.right = NULL;
    check.checkInt(1, o.widthOfBinaryTree(&node1));

    node1.left = NULL;
    node1.right = &node2;
    node2.left = node2.right = NULL;
    check.checkInt(1, o.widthOfBinaryTree(&node1));
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
