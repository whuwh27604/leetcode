/* 左叶子之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
计算给定二叉树的所有左叶子之和。

示例：

    3
   / \
  9  20
    /  \
   15   7

在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-left-leaves
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"
#include "../header/TreeNode.h"

using namespace std;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int sum = 0;
        DFS4Sum(root, false, sum);

        return sum;
    }

    void DFS4Sum(TreeNode* root, bool isLeft, int& sum) {
        if (isLeft && root->left == NULL && root->right == NULL) {
            sum += root->val;
        }

        if (root->left != NULL) {
            DFS4Sum(root->left, true, sum);
        }

        if (root->right != NULL) {
            DFS4Sum(root->right, false, sum);
        }
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
    check.checkInt(24, o.sumOfLeftLeaves(&node1));
    check.checkInt(0, o.sumOfLeftLeaves(&node2));
    check.checkInt(15, o.sumOfLeftLeaves(&node3));
    check.checkInt(0, o.sumOfLeftLeaves(&node4));
    check.checkInt(0, o.sumOfLeftLeaves(&node5));
    check.checkInt(0, o.sumOfLeftLeaves(NULL));

    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    node4.val = 4;
    node5.val = 5;
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = node3.right = NULL;
    node4.left = node4.right = NULL;
    node5.left = node5.right = NULL;
    check.checkInt(4, o.sumOfLeftLeaves(&node1));
    check.checkInt(4, o.sumOfLeftLeaves(&node2));
    check.checkInt(0, o.sumOfLeftLeaves(&node3));
    check.checkInt(0, o.sumOfLeftLeaves(&node4));
    check.checkInt(0, o.sumOfLeftLeaves(&node5));
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
