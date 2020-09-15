/* 二叉搜索树中第K小的元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 3
进阶：
如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        stack<pair<TreeNode*, bool>> nodePairs;
        nodePairs.push({ root, false });

        while (!nodePairs.empty()) {
            pair<TreeNode*, bool> nodePair = nodePairs.top();
            nodePairs.pop();
            TreeNode* node = nodePair.first;

            if (nodePair.second) {
                count++;
                if (count == k) {
                    return node->val;
                }

                continue;
            }

            if (node->right != NULL) {
                nodePairs.push({ node->right, false });
            }

            nodePairs.push({ node, true });

            if (node->left != NULL) {
                nodePairs.push({ node->left, false });
            }
        }

        return 0;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode node1(3);
    TreeNode node2(1);
    TreeNode node3(4);
    TreeNode node4(2);
    node1.left = &node2;
    node1.right = &node3;
    node2.right = &node4;
    check.checkInt(1, o.kthSmallest(&node1, 1));
    check.checkInt(2, o.kthSmallest(&node1, 2));
    check.checkInt(3, o.kthSmallest(&node1, 3));
    check.checkInt(4, o.kthSmallest(&node1, 4));

    node1.val = 5;
    node2.val = 3;
    node3.val = 6;
    node4.val = 2;
    TreeNode node5(4);
    TreeNode node6(1);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node4.left = &node6;
    check.checkInt(1, o.kthSmallest(&node1, 1));
    check.checkInt(2, o.kthSmallest(&node1, 2));
    check.checkInt(3, o.kthSmallest(&node1, 3));
    check.checkInt(4, o.kthSmallest(&node1, 4));
    check.checkInt(5, o.kthSmallest(&node1, 5));
    check.checkInt(6, o.kthSmallest(&node1, 6));

    node1.val = 5;
    node1.left = node1.right = NULL;
    check.checkInt(5, o.kthSmallest(&node1, 1));

    node1.val = 5;
    node2.val = 3;
    node1.left = &node2;
    node1.right = NULL;
    node2.left = node2.right = NULL;
    check.checkInt(3, o.kthSmallest(&node1, 1));
    check.checkInt(5, o.kthSmallest(&node1, 2));

    node1.val = 5;
    node2.val = 3;
    node3.val = 6;
    node1.left = &node2;
    node1.right = &node3;
    node2.left = node2.right = NULL;
    node3.left = node3.right = NULL;
    check.checkInt(3, o.kthSmallest(&node1, 1));
    check.checkInt(5, o.kthSmallest(&node1, 2));
    check.checkInt(6, o.kthSmallest(&node1, 3));
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
