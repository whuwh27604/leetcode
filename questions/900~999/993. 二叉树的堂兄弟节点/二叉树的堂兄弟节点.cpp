/* 二叉树的堂兄弟节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。

如果二叉树的两个节点深度相同，但父节点不同，则它们是一对堂兄弟节点。

我们给出了具有唯一值的二叉树的根节点 root，以及树中两个不同节点的值 x 和 y。

只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true。否则，返回 false。

 

示例 1：


输入：root = [1,2,3,4], x = 4, y = 3
输出：false
示例 2：


输入：root = [1,2,3,null,4,null,5], x = 5, y = 4
输出：true
示例 3：



输入：root = [1,2,3,null,4], x = 2, y = 3
输出：false
 

提示：

二叉树的节点数介于 2 到 100 之间。
每个节点的值都是唯一的、范围为 1 到 100 的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/cousins-in-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            int i, size = bfs.size();
            bool findX = false, findY = false;

            for (i = 0; i < size; ++i) {
                TreeNode* node = bfs.front();
                bfs.pop();

                if (node->val == x) {
                    findX = true;
                }

                if (node->val == y) {
                    findY = true;
                }

                if (node->left != NULL) {
                    bfs.push(node->left);
                }

                if (node->right != NULL) {
                    bfs.push(node->right);
                }

                if (node->left != NULL && node->right != NULL && ((node->left->val == x && node->right->val == y) || (node->left->val == y && node->right->val == x))) {
                    return false;
                }
            }

            if (findX && findY) {
                return true;
            }

            if ((findX && !findY) || (!findX && findY)) {
                return false;
            }
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    check.checkBool(false, o.isCousins(createTree(values), 2, 3));
    check.checkBool(false, o.isCousins(createTree(values), 2, 1));
    check.checkBool(false, o.isCousins(createTree(values), 7, 3));
    check.checkBool(false, o.isCousins(createTree(values), 4, 5));
    check.checkBool(true, o.isCousins(createTree(values), 4, 7));
    check.checkBool(true, o.isCousins(createTree(values), 5, 6));
    check.checkBool(true, o.isCousins(createTree(values), 8, 15));
    check.checkBool(true, o.isCousins(createTree(values), 11, 12));
    check.checkBool(false, o.isCousins(createTree(values), 10, 11));
    check.checkBool(false, o.isCousins(createTree(values), 1, 111));

    values = { 1,2,3,4 };
    check.checkBool(false, o.isCousins(createTree(values), 4, 3));

    values = { 1,2,3,INT_MIN,4,INT_MIN,5 };
    check.checkBool(true, o.isCousins(createTree(values), 5, 4));

    values = { 1,2,3,INT_MIN,4 };
    check.checkBool(false, o.isCousins(createTree(values), 2, 3));
    check.checkBool(false, o.isCousins(createTree(values), 4, 3));

    values = { 1,2 };
    check.checkBool(false, o.isCousins(createTree(values), 2, 1));
    check.checkBool(false, o.isCousins(createTree(values), 1, 3));
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
