/* 修剪二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉搜索树，同时给定最小边界L 和最大边界 R。通过修剪二叉搜索树，使得所有节点的值在[L, R]中 (R>=L) 。你可能需要改变树的根节点，所以结果应当返回修剪好的二叉搜索树的新的根节点。

示例 1:

输入:
    1
   / \
  0   2

  L = 1
  R = 2

输出:
    1
      \
       2
示例 2:

输入:
    3
   / \
  0   4
   \
    2
   /
  1

  L = 1
  R = 3

输出:
      3
     /
   2
  /
 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trim-a-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root == NULL) {
            return NULL;
        }

        if (root->val < L) {
            return trimBST(root->right, L, R);
        }
        if (root->val > R) {
            return trimBST(root->left, L, R);
        }

        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);

        return root;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 1,0,2 };
    TreeNode* root = createTree(values);
    values = { 1,INT_MIN,2 };
    check.checkTree(createTree(values), o.trimBST(root, 1, 2));

    values = { 3,0,4,INT_MIN,2,INT_MIN,INT_MIN,1 };
    root = createTree(values);
    values = { 3,2,INT_MIN,1 };
    check.checkTree(createTree(values), o.trimBST(root, 1, 3));

    values = { 3,0,4,INT_MIN,2,INT_MIN,INT_MIN,1 };
    root = createTree(values);
    values = { 0,INT_MIN,2,1 };
    check.checkTree(createTree(values), o.trimBST(root, 0, 2));

    values = { 3,0,4,INT_MIN,2,INT_MIN,INT_MIN,1 };
    root = createTree(values);
    values = {  };
    check.checkTree(createTree(values), o.trimBST(root, 5, 6));

    values = { 3,0,4,INT_MIN,2,INT_MIN,INT_MIN,1 };
    root = createTree(values);
    values = {  };
    check.checkTree(createTree(values), o.trimBST(root, -2, -1));

    values = { 3,0,4,INT_MIN,2,INT_MIN,INT_MIN,1 };
    root = createTree(values);
    values = { 2 };
    check.checkTree(createTree(values), o.trimBST(root, 2, 2));

    values = {  };
    root = createTree(values);
    values = {  };
    check.checkTree(createTree(values), o.trimBST(root, 1, 3));
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
