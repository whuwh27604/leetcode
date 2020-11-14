/* 根据前序和后序遍历构造二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
返回与给定的前序和后序遍历匹配的任何二叉树。

 pre 和 post 遍历中的值是不同的正整数。

 

示例：

输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
输出：[1,2,3,4,5,6,7]
 

提示：

1 <= pre.length == post.length <= 30
pre[] 和 post[] 都是 1, 2, ..., pre.length 的排列
每个输入保证至少有一个答案。如果有多个答案，可以返回其中一个。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        unordered_map<int, int> preIndices, postIndices;
        saveIndices(pre, preIndices, post, postIndices);
        
        return constructTree(pre, 0, pre.size() - 1, preIndices, post, 0, post.size() - 1, postIndices);
    }

    TreeNode* constructTree(vector<int>& pre, int preStart, int preEnd, unordered_map<int, int>& preIndices,
        vector<int>& post, int postStart, int postEnd, unordered_map<int, int>& postIndices) {
        TreeNode* root = new TreeNode(pre[preStart]);
        if (preStart == preEnd) {
            return root;
        }

        int leftRoot = pre[preStart + 1];
        int rightRoot = post[postEnd - 1];
        if (leftRoot == rightRoot) {  // left或right为NULL，固定选择right为NULL
            root->left = constructTree(pre, preStart + 1, preEnd, preIndices, post, postStart, postEnd - 1, postIndices);
            root->right = NULL;
        }
        else {
            root->left = constructTree(pre, preStart + 1, preIndices[rightRoot] - 1, preIndices, post, postStart, postIndices[leftRoot], postIndices);
            root->right = constructTree(pre, preIndices[rightRoot], preEnd, preIndices, post, postIndices[leftRoot] + 1, postEnd - 1, postIndices);
        }

        return root;
    }

    void saveIndices(vector<int>& pre, unordered_map<int, int>& preIndices, vector<int>& post, unordered_map<int, int>& postIndices) {
        for (int i = 0; i < (int)pre.size(); ++i) {
            preIndices[pre[i]] = i;
            postIndices[post[i]] = i;
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> pre = { 1 };
    vector<int> post = { 1 };
    TreeNode* actual = o.constructFromPrePost(pre, post);
    check.checkInt(1, actual->val);
    check.checkPoint(NULL, actual->left);
    check.checkPoint(NULL, actual->right);

    pre = { 1,2 };
    post = { 2,1 };
    actual = o.constructFromPrePost(pre, post);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->left->val);
    check.checkPoint(NULL, actual->right);
    check.checkPoint(NULL, actual->left->left);
    check.checkPoint(NULL, actual->left->right);

    pre = { 1,2,4,5,3,6,7 };
    post = { 4,5,2,6,7,3,1 };
    actual = o.constructFromPrePost(pre, post);
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
