/* 对称二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/symmetric-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }

        stack<TreeNode*> saveNode;
        saveNode.push(root->left);
        saveNode.push(root->right);

        while (!saveNode.empty()) {
            TreeNode* rootQ = saveNode.top();
            saveNode.pop();
            TreeNode* rootP = saveNode.top();
            saveNode.pop();

            if ((rootQ == NULL) && (rootP == NULL)) {
                continue;
            }
            else if ((rootQ == NULL) || (rootP == NULL)) {
                return false;
            }
            else if (rootQ->val != rootP->val) {
                return false;
            }
            else {
                saveNode.push(rootP->left);
                saveNode.push(rootQ->right);
                saveNode.push(rootP->right);
                saveNode.push(rootQ->left);
            }
        }

        return true;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 1,2,2,3,4,4,3 };
    check.checkBool(true, o.isSymmetric(createTree(values)));

    values = { 1,2,2,INT_MIN,3,INT_MIN,3 };
    check.checkBool(false, o.isSymmetric(createTree(values)));

    values = { 1,INT_MIN,2,INT_MIN,3 };
    check.checkBool(false, o.isSymmetric(createTree(values)));

    values = { 1,2,2 };
    check.checkBool(true, o.isSymmetric(createTree(values)));

    values = { 1 };
    check.checkBool(true, o.isSymmetric(createTree(values)));
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
