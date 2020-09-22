/* 具有所有最深结点的最小子树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个根为 root 的二叉树，每个结点的深度是它到根的最短距离。

如果一个结点在整个树的任意结点之间具有最大的深度，则该结点是最深的。

一个结点的子树是该结点加上它的所有后代的集合。

返回能满足“以该结点为根的子树中包含所有最深的结点”这一条件的具有最大深度的结点。

 

示例：

输入：[3,5,1,6,2,0,8,null,null,7,4]
输出：[2,7,4]
解释：

我们返回值为 2 的结点，在图中用黄色标记。
在图中用蓝色标记的是树的最深的结点。
输入 "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" 是对给定的树的序列化表述。
输出 "[2, 7, 4]" 是对根结点的值为 2 的子树的序列化表述。
输入和输出都具有 TreeNode 类型。
 

提示：

树中结点的数量介于 1 和 500 之间。
每个结点的值都是独一无二的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-subtree-with-all-the-deepest-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxDepth = 0;
        vector<TreeNode*> path;
        vector<vector<TreeNode*>> deepestPaths;

        DFS(root, maxDepth, path, deepestPaths);

        int i, j, row = deepestPaths.size(), column = deepestPaths[0].size();

        for (j = column - 1; j >= 0; --j) {
            for (i = 1; i < row; ++i) {
                if (deepestPaths[i][j] != deepestPaths[0][j]) {
                    break;
                }
            }

            if (i == row) {
                break;
            }
        }

        return deepestPaths[0][j];
    }

    void DFS(TreeNode* root, int& maxDepth, vector<TreeNode*>& path, vector<vector<TreeNode*>>& deepestPaths) {
        path.push_back(root);

        if ((root->left == NULL) && (root->right == NULL)) {
            int depth = path.size();
            if (depth > maxDepth) {
                maxDepth = depth;
                deepestPaths.clear();
                deepestPaths.push_back(path);
            }
            else if (depth == maxDepth) {
                deepestPaths.push_back(path);
            }
        }
        else {
            if (root->left != NULL) {
                DFS(root->left, maxDepth, path, deepestPaths);
            }

            if (root->right != NULL) {
                DFS(root->right, maxDepth, path, deepestPaths);
            }
        }

        path.pop_back();
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
    TreeNode* actual = o.subtreeWithAllDeepest(&node1);
    TreeNode* expected = &node5;
    check.checkPoint(expected, actual);

    node1.left = node1.right = NULL;
    actual = o.subtreeWithAllDeepest(&node1);
    expected = &node1;
    check.checkPoint(expected, actual);

    node1.left = &node2;
    node1.right = NULL;
    node2.left = node2.right = NULL;
    actual = o.subtreeWithAllDeepest(&node1);
    expected = &node2;
    check.checkPoint(expected, actual);

    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    node4.left = node4.right = NULL;
    node5.left = node5.right = NULL;
    node6.left = node6.right = NULL;
    node7.left = node7.right = NULL;
    actual = o.subtreeWithAllDeepest(&node1);
    expected = &node1;
    check.checkPoint(expected, actual);
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
