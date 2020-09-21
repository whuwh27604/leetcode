/* 二叉搜索树的最小绝对差.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。

 

示例：

输入：

   1
    \
     3
    /
   2

输出：
1

解释：
最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
 

提示：

树中至少有 2 个节点。
本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"


using namespace std;

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        // BST的中序遍历是递增序列，所以就是求相邻两个数的差的最小值
        TreeNode* first = root;
        while (first->left != NULL) {
            first = first->left;
        }

        int previous = first->val - INT_MAX, minDifference = INT_MAX;
        LDR(root, previous, minDifference);
        return minDifference;
    }

    void LDR(TreeNode* root, int& previous, int& minDifference) {
        if (root->left != NULL) {
            LDR(root->left, previous, minDifference);
        }

        minDifference = min(minDifference, root->val - previous);
        previous = root->val;

        if (root->right != NULL) {
            LDR(root->right, previous, minDifference);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode node1(1);
    TreeNode node2(3);
    TreeNode node3(2);
    node1.right = &node2;
    node2.left = &node3;
    check.checkInt(1, o.getMinimumDifference(&node1));

    node1.val = 3;
    node2.val = 9;
    node1.left = NULL;
    node1.right = &node2;
    node2.left = NULL;
    node2.right = NULL;
    check.checkInt(6, o.getMinimumDifference(&node1));

    node1.val = 9;
    node2.val = 3;
    node1.left = &node2;
    node1.right = NULL;
    node2.left = NULL;
    node2.right = NULL;
    check.checkInt(6, o.getMinimumDifference(&node1));

    node1.val = 400;
    node2.val = 270;
    node3.val = 520;
    TreeNode node4(100);
    TreeNode node5(340);
    TreeNode node6(450);
    TreeNode node7(530);
    TreeNode node8(1);
    TreeNode node9(190);
    TreeNode node10(490);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    node4.left = &node8;
    node4.right = &node9;
    node6.right = &node10;
    check.checkInt(10, o.getMinimumDifference(&node1));
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
