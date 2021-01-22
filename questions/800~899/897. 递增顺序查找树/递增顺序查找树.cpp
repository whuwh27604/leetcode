/* 递增顺序查找树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个树，请你 按中序遍历 重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点。

 

示例 ：

输入：[5,3,6,2,4,null,8,1,null,null,null,7,9]

       5
      / \
    3    6
   / \    \
  2   4    8
 /        / \
1        7   9

输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
            \
             7
              \
               8
                \
                 9
 

提示：

给定树中的结点数介于 1 和 100 之间。
每个结点都有一个从 0 到 1000 范围内的唯一整数值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/increasing-order-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        TreeNode* newTreeRoot = NULL;
        TreeNode* newTreeLast = NULL;
        LDR(root, &newTreeRoot, &newTreeLast);

        return newTreeRoot;
    }

    void LDR(TreeNode* root, TreeNode** newTreeRoot, TreeNode** newTreeLast) {
        if (root->left != NULL) {
            LDR(root->left, newTreeRoot, newTreeLast);
        }

        TreeNode* node = new TreeNode(root->val);
        if (*newTreeRoot == NULL) {
            *newTreeRoot = node;
            *newTreeLast = node;
        }
        else {
            (*newTreeLast)->right = node;
            *newTreeLast = node;
        }

        if (root->right != NULL) {
            LDR(root->right, newTreeRoot, newTreeLast);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> valuesA = { 5,3,6,2,4,INT_MIN,8,1,INT_MIN,INT_MIN,INT_MIN,7,9 };
    vector<int> valuesE = { 1,INT_MIN,2,INT_MIN,3,INT_MIN,4,INT_MIN,5,INT_MIN,6,INT_MIN,7,INT_MIN,8,INT_MIN,9 };
    check.checkTree(createTree(valuesE), o.increasingBST(createTree(valuesA)));

    valuesA = { 2,1 };
    valuesE = { 1,INT_MIN,2 };
    check.checkTree(createTree(valuesE), o.increasingBST(createTree(valuesA)));

    valuesA = { 8,INT_MIN,9 };
    valuesE = { 8,INT_MIN,9 };
    check.checkTree(createTree(valuesE), o.increasingBST(createTree(valuesA)));

    valuesA = { 2 };
    valuesE = { 2 };
    check.checkTree(createTree(valuesE), o.increasingBST(createTree(valuesA)));
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
