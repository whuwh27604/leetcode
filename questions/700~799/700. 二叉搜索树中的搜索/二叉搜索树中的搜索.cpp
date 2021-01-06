/* 二叉搜索树中的搜索.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。

例如，

给定二叉搜索树:

        4
       / \
      2   7
     / \
    1   3

和值: 2
你应该返回如下子树:

      2
     / \
    1   3
在上述示例中，如果要找的值是 5，但因为没有节点值为 5，我们应该返回 NULL。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/search-in-a-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != NULL) {
            if (root->val == val) {
                return root;
            }

            if (root->val > val) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }

        return NULL;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 4,2,7,1,3 };
    TreeNode* root = createTree(values);
    values = { 4,2,7,1,3 };
    check.checkTree(createTree(values), o.searchBST(root, 4));
    values = { 2,1,3 };
    check.checkTree(createTree(values), o.searchBST(root, 2));
    values = { 7 };
    check.checkTree(createTree(values), o.searchBST(root, 7));
    values = { 1 };
    check.checkTree(createTree(values), o.searchBST(root, 1));
    values = { 3 };
    check.checkTree(createTree(values), o.searchBST(root, 3));
    values = {  };
    check.checkTree(createTree(values), o.searchBST(root, 0));
    values = {  };
    check.checkTree(createTree(values), o.searchBST(root, 5));
    values = {  };
    check.checkTree(createTree(values), o.searchBST(root, 8));

    values = {  };
    root = createTree(values);
    values = {  };
    check.checkTree(createTree(values), o.searchBST(root, 0));
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
