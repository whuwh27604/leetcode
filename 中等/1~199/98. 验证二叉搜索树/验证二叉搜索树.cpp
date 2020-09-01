/* 验证二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        previous = LLONG_MIN;
        return LDR(root);
    }

    bool LDR(TreeNode* root) {
        if (root->left != NULL) {
            if (!LDR(root->left)) {
                return false;
            }
        }

        if (root->val <= previous) {
            return false;
        }
        previous = root->val;

        if (root->right != NULL) {
            return LDR(root->right);
        }

        return true;
    }

    long long previous;
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode node1(5);
    TreeNode node2(1);
    TreeNode node3(4);
    TreeNode node4(3);
    TreeNode node5(6);
    node1.left = &node2;
    node1.right = &node3;
    node3.left = &node4;
    node3.right = &node5;
    check.checkBool(false, o.isValidBST(&node1));

    node1.val = 5;
    node2.val = 1;
    node3.val = 6;
    node4.val = 3;
    node5.val = 7;
    check.checkBool(false, o.isValidBST(&node1));

    node1.val = 5;
    node2.val = 1;
    node3.val = 7;
    node4.val = 6;
    node5.val = 8;
    check.checkBool(true, o.isValidBST(&node1));

    node1.val = 2;
    node2.val = 1;
    node3.val = 3;
    node1.left = &node2;
    node1.right = &node3;
    node2.left = node2.right = NULL;
    node3.left = node3.right = NULL;
    check.checkBool(true, o.isValidBST(&node1));

    node1.val = 2;
    node2.val = 1;
    node3.val = 2;
    node1.left = &node2;
    node1.right = &node3;
    node2.left = node2.right = NULL;
    node3.left = node3.right = NULL;
    check.checkBool(false, o.isValidBST(&node1));

    check.checkBool(true, o.isValidBST(NULL));

    node1.val = INT_MIN;
    node1.left = node1.right = NULL;
    check.checkBool(true, o.isValidBST(&node1));
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
