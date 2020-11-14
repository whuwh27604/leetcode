/* 完全二叉树的节点个数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出一个完全二叉树，求出该树的节点个数。

说明：

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

示例:

输入:
    1
   / \
  2   3
 / \  /
4  5 6

输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-complete-tree-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int countNodes(TreeNode* root) {
        int layer = 0;
        TreeNode* tmp = root;
        while (tmp != NULL) {
            tmp = tmp->left;
            layer++;
        }

        if (layer == 0) {
            return 0;
        }
        else if (layer == 1) {
            return 1;
        }
        else {
            int fullLayer = layer - 1;
            return (int)pow(2, fullLayer) - 1 + binarySearchLastLayer(root, fullLayer);
        }
    }

    int binarySearchLastLayer(TreeNode* root, int fullLayer) {
        if (fullLayer == 1) {
            int count = 0;
            if (root->left != NULL) {
                count++;
            }
            if (root->right != NULL) {
                count++;
            }
            return count;
        }

        TreeNode* node = root->left;
        int currentLayer = 2;
        while (currentLayer < fullLayer) {
            node = node->right;
            currentLayer++;
        }

        if (node->right == NULL) {
            return binarySearchLastLayer(root->left, fullLayer - 1);
        }

        return (int)pow(2, fullLayer - 1) + binarySearchLastLayer(root->right, fullLayer - 1);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.countNodes(NULL));

    TreeNode node1(1);
    check.checkInt(1, o.countNodes(&node1));

    TreeNode node2(2);
    node1.left = &node2;
    check.checkInt(2, o.countNodes(&node1));

    TreeNode node3(3);
    node1.right = &node3;
    check.checkInt(3, o.countNodes(&node1));

    TreeNode node4(4);
    node2.left = &node4;
    check.checkInt(4, o.countNodes(&node1));

    TreeNode node5(5);
    node2.right = &node5;
    check.checkInt(5, o.countNodes(&node1));

    TreeNode node6(6);
    node3.left = &node6;
    check.checkInt(6, o.countNodes(&node1));

    TreeNode node7(7);
    node3.right = &node7;
    check.checkInt(7, o.countNodes(&node1));

    TreeNode node8(8);
    node4.left = &node8;
    check.checkInt(8, o.countNodes(&node1));

    TreeNode node9(9);
    node4.right = &node9;
    check.checkInt(9, o.countNodes(&node1));

    TreeNode node10(10);
    node5.left = &node10;
    check.checkInt(10, o.countNodes(&node1));

    TreeNode node11(11);
    node5.right = &node11;
    check.checkInt(11, o.countNodes(&node1));

    TreeNode node12(12);
    node6.left = &node12;
    check.checkInt(12, o.countNodes(&node1));

    TreeNode node13(13);
    node6.right = &node13;
    check.checkInt(13, o.countNodes(&node1));

    TreeNode node14(14);
    node7.left = &node14;
    check.checkInt(14, o.countNodes(&node1));

    TreeNode node15(15);
    node7.right = &node15;
    check.checkInt(15, o.countNodes(&node1));

    TreeNode node16(16);
    node8.left = &node16;
    check.checkInt(16, o.countNodes(&node1));

    TreeNode node17(17);
    node8.right = &node17;
    check.checkInt(17, o.countNodes(&node1));

    TreeNode node18(18);
    node9.left = &node18;
    check.checkInt(18, o.countNodes(&node1));
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
