/* 二叉搜索树的最近公共祖先.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]



 

示例 1:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6
解释: 节点 2 和节点 8 的最近公共祖先是 6。
示例 2:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
 

说明:

所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉搜索树中。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 注意二叉搜索树满足left<right
        while ((root->val != p->val) && (root->val != q->val)) {
            if (((root->val > p->val) && (root->val < q->val)) || ((root->val < p->val) && (root->val > q->val))) {
                return root;
            }

            if ((root->val > p->val) && (root->val > q->val)) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }

        return root;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode node0(0);
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    TreeNode node7(7);
    TreeNode node8(8);
    TreeNode node9(9);
    node6.left = &node2;
    node6.right = &node8;
    node2.left = &node0;
    node2.right = &node4;
    node4.left = &node3;
    node4.right = &node5;
    node8.left = &node7;
    node8.right = &node9;
    check.checkInt(6, o.lowestCommonAncestor(&node6, &node2, &node8)->val);
    check.checkInt(4, o.lowestCommonAncestor(&node6, &node3, &node5)->val);
    check.checkInt(2, o.lowestCommonAncestor(&node6, &node2, &node5)->val);
    check.checkInt(2, o.lowestCommonAncestor(&node6, &node5, &node2)->val);
    check.checkInt(2, o.lowestCommonAncestor(&node6, &node2, &node3)->val);
    check.checkInt(8, o.lowestCommonAncestor(&node6, &node7, &node9)->val);

    node2.left = &node1;
    node2.right = &node3;
    node1.left = node1.right = NULL;
    node3.left = node3.right = NULL;
    check.checkInt(2, o.lowestCommonAncestor(&node2, &node3, &node1)->val);
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
