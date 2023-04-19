/* 二叉树的堂兄弟节点 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵二叉树的根 root ，请你将每个节点的值替换成该节点的所有 堂兄弟节点值的和 。

如果两个节点在树中有相同的深度且它们的父节点不同，那么它们互为 堂兄弟 。

请你返回修改值之后，树的根 root 。

注意，一个节点的深度指的是从树根节点到这个节点经过的边数。



示例 1：



输入：root = [5,4,9,1,10,null,7]
输出：[0,0,0,7,7,null,11]
解释：上图展示了初始的二叉树和修改每个节点的值之后的二叉树。
- 值为 5 的节点没有堂兄弟，所以值修改为 0 。
- 值为 4 的节点没有堂兄弟，所以值修改为 0 。
- 值为 9 的节点没有堂兄弟，所以值修改为 0 。
- 值为 1 的节点有一个堂兄弟，值为 7 ，所以值修改为 7 。
- 值为 10 的节点有一个堂兄弟，值为 7 ，所以值修改为 7 。
- 值为 7 的节点有两个堂兄弟，值分别为 1 和 10 ，所以值修改为 11 。
示例 2：



输入：root = [3,1,2]
输出：[0,0,0]
解释：上图展示了初始的二叉树和修改每个节点的值之后的二叉树。
- 值为 3 的节点没有堂兄弟，所以值修改为 0 。
- 值为 1 的节点没有堂兄弟，所以值修改为 0 。
- 值为 2 的节点没有堂兄弟，所以值修改为 0 。


提示：

树中节点数目的范围是 [1, 105] 。
1 <= Node.val <= 104
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> sums;

        BFS(root, sums);
        DFS(root, sums, 0, root->val);

        return root;
    }

    void BFS(TreeNode* root, vector<int>& sums) {
        queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            int sum = 0, size = nodes.size();

            for (int i = 0; i < size; ++i) {
                TreeNode* node = nodes.front();
                nodes.pop();
                sum += node->val;

                if (node->left != NULL) {
                    nodes.push(node->left);
                }
                if (node->right != NULL) {
                    nodes.push(node->right);
                }
            }

            sums.push_back(sum);
        }
    }

    void DFS(TreeNode* root, vector<int>& sums, int index, int except) {
        root->val = sums[index] - except;
        except = (root->left == NULL ? 0 : root->left->val) + (root->right == NULL ? 0 : root->right->val);

        if (root->left != NULL) {
            DFS(root->left, sums, index + 1, except);
        }

        if (root->right != NULL) {
            DFS(root->right, sums, index + 1, except);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 5,4,9,1,10,INT_MIN,7 };
    TreeNode* actual = o.replaceValueInTree(createTree(values));
    values = { 0,0,0,7,7,INT_MIN,11 };
    check.checkTree(createTree(values), actual);

    values = { 3,1,2 };
    actual = o.replaceValueInTree(createTree(values));
    values = { 0,0,0 };
    check.checkTree(createTree(values), actual);
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
