/* 二叉树的直径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

 

示例 :
给定二叉树

          1
         / \
        2   3
       / \
      4   5
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。

 

注意：两结点之间的路径长度是以它们之间边的数目表示。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diameter-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;

        if (root != NULL) {
            (void)depth(root, maxDiameter);
        }

        return maxDiameter;
    }

    int depth(TreeNode* root, int& maxDiameter) {
        int leftDepth, rightDepth;

        if (root->left == NULL) {
            leftDepth = 0;
        }
        else {
            leftDepth = depth(root->left, maxDiameter) + 1;
        }

        if (root->right == NULL) {
            rightDepth = 0;
        }
        else {
            rightDepth = depth(root->right, maxDiameter) + 1;
        }

        int diameter = leftDepth + rightDepth;
        maxDiameter = (diameter > maxDiameter) ? diameter : maxDiameter;

        return (leftDepth > rightDepth) ? leftDepth : rightDepth;
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
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    check.checkInt(3, o.diameterOfBinaryTree(&node1));

    check.checkInt(0, o.diameterOfBinaryTree(NULL));

    node1.left = NULL;
    node1.right = NULL;
    check.checkInt(0, o.diameterOfBinaryTree(&node1));

    node1.left = &node2;
    node1.right = NULL;
    node2.left = node2.right = NULL;
    check.checkInt(1, o.diameterOfBinaryTree(&node1));

    TreeNode node6(2);
    TreeNode node7(3);
    TreeNode node8(4);
    TreeNode node9(5);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node5.left = &node7;
    node5.right = &node6;
    node4.left = &node9;
    node7.left = &node8;
    node3.left = node3.right = NULL;
    check.checkInt(5, o.diameterOfBinaryTree(&node1));
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
