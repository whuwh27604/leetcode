/* 二叉树的锯齿形层次遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <list>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> allValues;
        if (root == NULL) {
            return allValues;
        }

        list<TreeNode*> currentLevel;
        currentLevel.push_back(root);

        int i = 0, j, direction = 1;
        TreeNode* node;
        while (!currentLevel.empty()) {
            int len = currentLevel.size();
            allValues.push_back(vector<int>(len, 0));

            for (j = 0; j < len; j++) {
                if (direction == 1) {
                    node = currentLevel.front();
                    currentLevel.pop_front();

                    if (node->left != NULL) {
                        currentLevel.push_back(node->left);
                    }
                    if (node->right != NULL) {
                        currentLevel.push_back(node->right);
                    }
                }
                else {
                    node = currentLevel.back();
                    currentLevel.pop_back();

                    if (node->right != NULL) {
                        currentLevel.push_front(node->right);
                    }
                    if (node->left != NULL) {
                        currentLevel.push_front(node->left);
                    }
                }

                allValues[i][j] = node->val;
            }

            i++;
            direction = 0 - direction;
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
    vector<vector<int>> actual = o.zigzagLevelOrder(&node1);
    vector<vector<int>> expected = { {3},{20,9},{15,7} };
    check.checkIntVectorVector(expected, actual);

    actual = o.zigzagLevelOrder(NULL);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    node1.left = node1.right = NULL;
    actual = o.zigzagLevelOrder(&node1);
    expected = { {3} };
    check.checkIntVectorVector(expected, actual);

    node1.left = &node2;
    node1.right = &node3;
    node2.left = node2.right = NULL;
    node3.left = node3.right = NULL;
    actual = o.zigzagLevelOrder(&node1);
    expected = { {3},{20,9} };
    check.checkIntVectorVector(expected, actual);

    node1.left = &node2;
    node1.right = NULL;
    node2.left = &node3;
    node2.right = NULL;
    node3.left = &node4;
    node3.right = NULL;
    node4.left = NULL;
    node4.right = NULL;
    actual = o.zigzagLevelOrder(&node1);
    expected = { {3},{9},{20},{15} };
    check.checkIntVectorVector(expected, actual);

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
    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node4.val = 4;
    node5.val = 5;
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
    actual = o.zigzagLevelOrder(&node1);
    expected = { {1},{3,2},{4,5,6,7},{15,14,13,12,11,10,9,8} };
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
