/* 求根到叶子节点数字之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。

例如，从根到叶子节点路径 1->2->3 代表数字 123。

计算从根到叶子节点生成的所有数字之和。

说明: 叶子节点是指没有子节点的节点。

示例 1:

输入: [1,2,3]
    1
   / \
  2   3
输出: 25
解释:
从根到叶子节点路径 1->2 代表数字 12.
从根到叶子节点路径 1->3 代表数字 13.
因此，数字总和 = 12 + 13 = 25.
示例 2:

输入: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
输出: 1026
解释:
从根到叶子节点路径 4->9->5 代表数字 495.
从根到叶子节点路径 4->9->1 代表数字 491.
从根到叶子节点路径 4->0 代表数字 40.
因此，数字总和 = 495 + 491 + 40 = 1026.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-root-to-leaf-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int num = 0, sum = 0;
        DLR(root, num, sum);

        return sum;
    }

    void DLR(TreeNode* root, int num, int& sum) {
        num = num * 10 + root->val;

        if ((root->left == NULL) && (root->right == NULL)) {
            sum += num;
            return;
        }

        if (root->left != NULL) {
            DLR(root->left, num, sum);
        }

        if (root->right != NULL) {
            DLR(root->right, num, sum);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.sumNumbers(NULL));

    TreeNode node1(5);
    check.checkInt(5, o.sumNumbers(&node1));

    TreeNode node2(3);
    node1.left = &node2;
    check.checkInt(53, o.sumNumbers(&node1));

    node2.val = 4;
    node1.left = NULL;
    node1.right = &node2;
    check.checkInt(54, o.sumNumbers(&node1));

    node2.val = 1;
    TreeNode node3(3);
    node1.left = &node2;
    node1.right = &node3;
    check.checkInt(104, o.sumNumbers(&node1));

    node1.val = 1;
    node2.val = 2;
    node3.val = 3;
    check.checkInt(25, o.sumNumbers(&node1));

    node1.val = 4;
    node2.val = 9;
    node3.val = 0;
    TreeNode node4(5);
    TreeNode node5(1);
    node2.left = &node4;
    node2.right = &node5;
    check.checkInt(1026, o.sumNumbers(&node1));

    node1.val = 0;
    check.checkInt(186, o.sumNumbers(&node1));
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
