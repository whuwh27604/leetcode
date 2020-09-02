/* 从前序与中序遍历序列构造二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i, len = inorder.size();
        if (len == 0) {
            return NULL;
        }

        unordered_map<int, int> preorderValueIndex, inorderValueIndex;
        for (i = 0; i < len; i++) {
            preorderValueIndex[preorder[i]] = i;
        }

        for (i = 0; i < len; i++) {
            inorderValueIndex[inorder[i]] = i;
        }

        return buildSubTree(preorder, inorder, preorderValueIndex, inorderValueIndex, preorder[0], 0, len - 1);
    }

    TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& preorderValueIndex,
        unordered_map<int, int>& inorderValueIndex, int rootValue, int left, int right) {
        TreeNode* root = new TreeNode(rootValue);
        if (left == right) {
            return root;
        }

        int rootIndexInInorder = inorderValueIndex[rootValue];
        int rootIndexInPreorder = preorderValueIndex[rootValue];
        if (rootIndexInInorder > left) {
            int leftRootValue = preorder[rootIndexInPreorder + 1];
            root->left = buildSubTree(preorder, inorder, preorderValueIndex, inorderValueIndex, leftRootValue, left, rootIndexInInorder - 1);
        }

        if (rootIndexInInorder < right) {
            int rightRootValue = preorder[rootIndexInPreorder + rootIndexInInorder - left + 1];
            root->right = buildSubTree(preorder, inorder, preorderValueIndex, inorderValueIndex, rightRootValue, rootIndexInInorder + 1, right);
        }

        return root;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> preorder = { 1,2,4,5,3,6,7 };
    vector<int> inorder = { 4,2,5,1,6,3,7 };
    TreeNode* actual = o.buildTree(preorder, inorder);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->left->val);
    check.checkInt(3, actual->right->val);
    check.checkInt(4, actual->left->left->val);
    check.checkInt(5, actual->left->right->val);
    check.checkInt(6, actual->right->left->val);
    check.checkInt(7, actual->right->right->val);
    check.checkPoint(NULL, actual->left->left->left);
    check.checkPoint(NULL, actual->left->left->right);
    check.checkPoint(NULL, actual->left->right->left);
    check.checkPoint(NULL, actual->left->right->right);
    check.checkPoint(NULL, actual->right->left->left);
    check.checkPoint(NULL, actual->right->left->right);
    check.checkPoint(NULL, actual->right->right->left);
    check.checkPoint(NULL, actual->right->right->right);

    preorder = {  };
    inorder = {  };
    actual = o.buildTree(preorder, inorder);
    check.checkPoint(NULL, actual);

    preorder = { 1 };
    inorder = { 1 };
    actual = o.buildTree(preorder, inorder);
    check.checkInt(1, actual->val);
    check.checkPoint(NULL, actual->left);
    check.checkPoint(NULL, actual->right);

    preorder = { 1,2 };
    inorder = { 2,1 };
    actual = o.buildTree(preorder, inorder);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->left->val);
    check.checkPoint(NULL, actual->right);
    check.checkPoint(NULL, actual->left->left);
    check.checkPoint(NULL, actual->left->right);

    preorder = { 1,2 };
    inorder = { 1,2 };
    actual = o.buildTree(preorder, inorder);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->right->val);
    check.checkPoint(NULL, actual->left);
    check.checkPoint(NULL, actual->right->left);
    check.checkPoint(NULL, actual->right->right);

    preorder = { 3,9,20,15,7 };
    inorder = { 9,3,15,20,7 };
    actual = o.buildTree(preorder, inorder);
    check.checkInt(3, actual->val);
    check.checkInt(9, actual->left->val);
    check.checkInt(20, actual->right->val);
    check.checkInt(15, actual->right->left->val);
    check.checkInt(7, actual->right->right->val);
    check.checkPoint(NULL, actual->left->left);
    check.checkPoint(NULL, actual->left->right);
    check.checkPoint(NULL, actual->right->left->left);
    check.checkPoint(NULL, actual->right->left->right);
    check.checkPoint(NULL, actual->right->right->left);
    check.checkPoint(NULL, actual->right->right->right);

    preorder = { 3,2,1,4 };
    inorder = { 1,2,3,4 };
    actual = o.buildTree(preorder, inorder);
    check.checkInt(3, actual->val);
    check.checkInt(2, actual->left->val);
    check.checkInt(4, actual->right->val);
    check.checkInt(1, actual->left->left->val);
    check.checkPoint(NULL, actual->right->left);
    check.checkPoint(NULL, actual->right->right);
    check.checkPoint(NULL, actual->left->left->left);
    check.checkPoint(NULL, actual->left->left->right);

    preorder = { 3,2,1,4 };
    inorder = { 2,1,3,4 };
    actual = o.buildTree(preorder, inorder);
    check.checkInt(3, actual->val);
    check.checkInt(2, actual->left->val);
    check.checkInt(4, actual->right->val);
    check.checkInt(1, actual->left->right->val);
    check.checkPoint(NULL, actual->right->left);
    check.checkPoint(NULL, actual->right->right);
    check.checkPoint(NULL, actual->left->right->left);
    check.checkPoint(NULL, actual->left->right->right);

    preorder = { 3,2,4,1 };
    inorder = { 2,3,4,1 };
    actual = o.buildTree(preorder, inorder);
    check.checkInt(3, actual->val);
    check.checkInt(2, actual->left->val);
    check.checkInt(4, actual->right->val);
    check.checkInt(1, actual->right->right->val);
    check.checkPoint(NULL, actual->left->left);
    check.checkPoint(NULL, actual->left->right);
    check.checkPoint(NULL, actual->right->right->left);
    check.checkPoint(NULL, actual->right->right->right);

    preorder = { 3,2,4,1 };
    inorder = { 2,3,1,4 };
    actual = o.buildTree(preorder, inorder);
    check.checkInt(3, actual->val);
    check.checkInt(2, actual->left->val);
    check.checkInt(4, actual->right->val);
    check.checkInt(1, actual->right->left->val);
    check.checkPoint(NULL, actual->left->left);
    check.checkPoint(NULL, actual->left->right);
    check.checkPoint(NULL, actual->right->left->left);
    check.checkPoint(NULL, actual->right->left->right);
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
