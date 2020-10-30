/* 删点成林.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出二叉树的根节点 root，树上每个节点都有一个不同的值。

如果节点值在 to_delete 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。

返回森林中的每棵树。你可以按任意顺序组织答案。

 

示例：



输入：root = [1,2,3,4,5,6,7], to_delete = [3,5]
输出：[[1,2,null,4],[6],[7]]
 

提示：

树中的节点数最大为 1000。
每个节点都有一个介于 1 到 1000 之间的值，且各不相同。
to_delete.length <= 1000
to_delete 包含一些从 1 到 1000、各不相同的值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-nodes-and-return-forest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (root == NULL) {
            return {};
        }

        unordered_set<int> toDelete;
        hashToDeleteNodes(to_delete, toDelete);

        flagToDelete(root, toDelete);

        TreeNode pseudo(0);
        pseudo.left = root;

        vector<TreeNode*> forest;
        deleteNodes(root, &pseudo, 0, forest);

        if (pseudo.left != NULL) {
            forest.push_back(root);
        }

        return forest;
    }

    void hashToDeleteNodes(vector<int>& to_delete, unordered_set<int>& toDelete) {
        for (int value : to_delete) {
            toDelete.insert(value);
        }
    }

    void flagToDelete(TreeNode* root, unordered_set<int>& toDelete) {
        if (toDelete.count(root->val) != 0) {
            root->val = -root->val;
        }

        if (root->left != NULL) {
            flagToDelete(root->left, toDelete);
        }
        
        if (root->right != NULL) {
            flagToDelete(root->right, toDelete);
        }
    }

    void deleteNodes(TreeNode* root, TreeNode* parent, int leftRight, vector<TreeNode*>& forest) {
        if (root->left != NULL) {
            deleteNodes(root->left, root, 0, forest);
        }

        if (root->right != NULL) {
            deleteNodes(root->right, root, 1, forest);
        }

        if (root->val < 0) {
            if (root->left != NULL) {
                forest.push_back(root->left);
            }
            
            if (root->right != NULL) {
                forest.push_back(root->right);
            }

            if (leftRight == 0) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> to_delete = { 3,5 };
    vector<int> values = { 1,2,3,4,5,6,7 };
    TreeNode* root = createTree(values);
    vector<TreeNode*> forest = o.delNodes(root, to_delete);
    vector<int> actual;
    for (TreeNode* node : forest) {
        actual.push_back(node->val);
    }
    vector<int> expected = { 1,6,7 };
    check.checkIntVectorRandomOrder(expected, actual);
    check.checkPoint(NULL, root->right);
    check.checkPoint(NULL, root->left->right);

    forest = o.delNodes(NULL, to_delete);
    check.checkBool(true, forest.empty());

    to_delete = { 1 };
    values = { 1,2,3,4,5,6,7 };
    root = createTree(values);
    forest = o.delNodes(root, to_delete);
    actual.clear();
    for (TreeNode* node : forest) {
        actual.push_back(node->val);
    }
    expected = { 2,3 };
    check.checkIntVectorRandomOrder(expected, actual);

    to_delete = { 1,3,7 };
    values = { 1,2,3,4,5,6,7 };
    root = createTree(values);
    forest = o.delNodes(root, to_delete);
    actual.clear();
    for (TreeNode* node : forest) {
        actual.push_back(node->val);
    }
    expected = { 2,6 };
    check.checkIntVectorRandomOrder(expected, actual);
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
