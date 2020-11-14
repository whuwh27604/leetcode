/* 最深叶节点的最近公共祖先.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个有根节点的二叉树，找到它最深的叶节点的最近公共祖先。

回想一下：

叶节点 是二叉树中没有子节点的节点
树的根节点的 深度 为 0，如果某一节点的深度为 d，那它的子节点的深度就是 d+1
如果我们假定 A 是一组节点 S 的 最近公共祖先，S 中的每个节点都在以 A 为根节点的子树中，且 A 的深度达到此条件下可能的最大值。
 

注意：本题与力扣 865 重复：https://leetcode-cn.com/problems/smallest-subtree-with-all-the-deepest-nodes/

 

示例 1：


输入：root = [3,5,1,6,2,0,8,null,null,7,4]
输出：[2,7,4]
解释：
我们返回值为 2 的节点，在图中用黄色标记。
在图中用蓝色标记的是树的最深的节点。
注意，节点 6、0 和 8 也是叶节点，但是它们的深度是 2 ，而节点 7 和 4 的深度是 3 。
示例 2：

输入：root = [1]
输出：[1]
解释：根节点是树中最深的节点，它是它本身的最近公共祖先。
示例 3：

输入：root = [0,1,3,null,2]
输出：[2]
解释：树中最深的叶节点是 2 ，最近公共祖先是它自己。
 

提示：

给你的树中将有 1 到 1000 个节点。
树中每个节点的值都在 1 到 1000 之间。
每个节点的值都是独一无二的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lowest-common-ancestor-of-deepest-leaves
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> path, deepestPath;
        TreeNode* lca = NULL;

        DFS(root, path, deepestPath, &lca);

        return lca;
    }

    void DFS(TreeNode* root, vector<TreeNode*>& path, vector<TreeNode*>& deepestPath, TreeNode** lca) {
        path.push_back(root);

        if (root->left == NULL && root->right == NULL) {
            if (path.size() > deepestPath.size()) {
                deepestPath = path;
                *lca = root;
            }
            else if (path.size() == deepestPath.size()) {
                for (unsigned int i = 0; i < path.size() && path[i] == deepestPath[i]; ++i) {
                    *lca = path[i];
                }
            }
        }
        else {
            if (root->left != NULL) {
                DFS(root->left, path, deepestPath, lca);
            }

            if (root->right != NULL) {
                DFS(root->right, path, deepestPath, lca);
            }
        }

        path.pop_back();
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 3,5,1,6,2,0,8,INT_MIN,INT_MIN,7,4 };
    check.checkInt(2, o.lcaDeepestLeaves(createTree(values))->val);

    values = { 3 };
    check.checkInt(3, o.lcaDeepestLeaves(createTree(values))->val);

    values = { 3,5 };
    check.checkInt(5, o.lcaDeepestLeaves(createTree(values))->val);

    values = { 1,2,3,4,5,6,7 };
    check.checkInt(1, o.lcaDeepestLeaves(createTree(values))->val);

    values = { 0,1,3,INT_MIN,2 };
    check.checkInt(2, o.lcaDeepestLeaves(createTree(values))->val);

    values = { 1,2,3,4 };
    check.checkInt(4, o.lcaDeepestLeaves(createTree(values))->val);
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
