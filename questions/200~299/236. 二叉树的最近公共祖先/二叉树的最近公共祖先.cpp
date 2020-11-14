/* 二叉树的最近公共祖先.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]



 

示例 1:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
输出: 3
解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
示例 2:

输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
输出: 5
解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 

说明:

所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉树中。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode*, int>> nodePairs, path1, path2;
        nodePairs.push({ root, 0 });

        while (!nodePairs.empty()) {
            TreeNode* node = nodePairs.top().first;
            int& direction = nodePairs.top().second;

            if ((node == p) && (path1.empty())) {
                path1 = nodePairs;
            }
            if ((node == q) && (path2.empty())) {
                path2 = nodePairs;
            }
            if (!path1.empty() && !path2.empty()) {
                break;
            }

            // 以下深度优先遍历
            if (((node->left == NULL) && (node->right == NULL)) || (direction == 2)) {
                nodePairs.pop();
                continue;
            }

            if (direction == 0) {
                if (node->left != NULL) {
                    direction = 1;
                    nodePairs.push({ node->left, 0 });
                }
                else {
                    direction = 2;
                    nodePairs.push({ node->right, 0 });
                }
            }
            else if (direction == 1) {
                if (node->right != NULL) {
                    direction = 2;
                    nodePairs.push({ node->right, 0 });
                }
                else {
                    nodePairs.pop();
                }
            }
        }

        return findCommonAncester(path1, path2);

    }

    TreeNode* findCommonAncester(stack<pair<TreeNode*, int>>& path1, stack<pair<TreeNode*, int>>& path2) {
        stack<TreeNode*> p1, p2;

        while (!path1.empty()) {
            p1.push(path1.top().first);
            path1.pop();
        }

        while (!path2.empty()) {
            p2.push(path2.top().first);
            path2.pop();
        }

        TreeNode* ancester = NULL;
        while (p1.top() == p2.top()) {
            ancester = p1.top();
            p1.pop();
            p2.pop();
            if (p1.empty() || p2.empty()) {
                break;
            }
        }

        return ancester;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode node1(3);
    TreeNode node2(5);
    TreeNode node3(1);
    TreeNode node4(6);
    TreeNode node5(2);
    TreeNode node6(0);
    TreeNode node7(8);
    TreeNode node8(7);
    TreeNode node9(4);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    node5.left = &node8;
    node5.right = &node9;
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node2, &node3));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node1, &node2));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node1, &node3));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node1, &node4));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node1, &node5));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node1, &node6));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node1, &node7));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node1, &node8));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node1, &node9));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node2, &node1));
    check.checkPoint(&node2, o.lowestCommonAncestor(&node1, &node2, &node4));
    check.checkPoint(&node2, o.lowestCommonAncestor(&node1, &node2, &node5));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node2, &node6));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node2, &node7));
    check.checkPoint(&node2, o.lowestCommonAncestor(&node1, &node2, &node8));
    check.checkPoint(&node2, o.lowestCommonAncestor(&node1, &node2, &node9));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node3, &node1));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node3, &node2));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node3, &node4));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node3, &node5));
    check.checkPoint(&node3, o.lowestCommonAncestor(&node1, &node3, &node6));
    check.checkPoint(&node3, o.lowestCommonAncestor(&node1, &node3, &node7));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node3, &node8));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node3, &node9));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node7, &node1));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node7, &node2));
    check.checkPoint(&node3, o.lowestCommonAncestor(&node1, &node7, &node3));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node7, &node4));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node7, &node5));
    check.checkPoint(&node3, o.lowestCommonAncestor(&node1, &node7, &node6));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node7, &node8));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node7, &node9));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node8, &node1));
    check.checkPoint(&node2, o.lowestCommonAncestor(&node1, &node8, &node2));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node8, &node3));
    check.checkPoint(&node2, o.lowestCommonAncestor(&node1, &node8, &node4));
    check.checkPoint(&node5, o.lowestCommonAncestor(&node1, &node8, &node5));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node8, &node6));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node8, &node7));
    check.checkPoint(&node5, o.lowestCommonAncestor(&node1, &node8, &node9));

    node1.right = NULL;
    node2.left = node2.right = NULL;
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node1, &node2));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node2, &node1));

    node1.right = &node3;
    node2.left = node2.right = NULL;
    node3.left = node3.right = NULL;
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node1, &node2));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node1, &node3));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node3, &node2));

    node1.right = &node3;
    node2.left = NULL;
    node2.right = &node4;
    node3.left = &node5;
    node3.right = NULL;
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node1, &node2));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node1, &node3));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node3, &node2));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node4, &node5));
    check.checkPoint(&node2, o.lowestCommonAncestor(&node1, &node4, &node2));
    check.checkPoint(&node3, o.lowestCommonAncestor(&node1, &node3, &node5));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node5, &node2));
    check.checkPoint(&node1, o.lowestCommonAncestor(&node1, &node3, &node4));
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
