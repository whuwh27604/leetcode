/* 翻转二叉树以匹配先序遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个有 N 个节点的二叉树，每个节点都有一个不同于其他节点且处于 {1, ..., N} 中的值。

通过交换节点的左子节点和右子节点，可以翻转该二叉树中的节点。

考虑从根节点开始的先序遍历报告的 N 值序列。将这一 N 值序列称为树的行程。

（回想一下，节点的先序遍历意味着我们报告当前节点的值，然后先序遍历左子节点，再先序遍历右子节点。）

我们的目标是翻转最少的树中节点，以便树的行程与给定的行程 voyage 相匹配。 

如果可以，则返回翻转的所有节点的值的列表。你可以按任何顺序返回答案。

如果不能，则返回列表 [-1]。

 

示例 1：



输入：root = [1,2], voyage = [2,1]
输出：[-1]
示例 2：



输入：root = [1,2,3], voyage = [1,3,2]
输出：[1]
示例 3：



输入：root = [1,2,3], voyage = [1,2,3]
输出：[]
 

提示：

1 <= N <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flip-binary-tree-to-match-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> flipNodes;
        int n = 0;
        DFS(root, voyage, n, flipNodes);

        return flipNodes;
    }

    void DFS(TreeNode* root, vector<int>& voyage, int& n, vector<int>& flipNodes) {
        if (root->val != voyage[n]) {
            flipNodes = { -1 };
            return;
        }

        if (root->left != NULL && root->right != NULL && root->right->val == voyage[n + 1]) {
            swap(root->left, root->right);
            flipNodes.push_back(root->val);
        }

        if (root->left != NULL) {
            DFS(root->left, voyage, ++n, flipNodes);
        }

        if (root->right != NULL) {
            DFS(root->right, voyage, ++n, flipNodes);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,2 };
    vector<int> voyage = { 2,1 };
    vector<int> actual = o.flipMatchVoyage(createTree(values), voyage);
    vector<int> expected = { -1 };
    check.checkIntVector(expected, actual);

    values = { 1,2,3 };
    voyage = { 1,3,2 };
    actual = o.flipMatchVoyage(createTree(values), voyage);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    values = { 1,2,3 };
    voyage = { 1,2,3 };
    actual = o.flipMatchVoyage(createTree(values), voyage);
    expected = {  };
    check.checkIntVector(expected, actual);

    values = { 1 };
    voyage = { 1 };
    actual = o.flipMatchVoyage(createTree(values), voyage);
    expected = {  };
    check.checkIntVector(expected, actual);

    values = { 1,2 };
    voyage = { 1,2 };
    actual = o.flipMatchVoyage(createTree(values), voyage);
    expected = {  };
    check.checkIntVector(expected, actual);

    values = { 1,INT_MIN,2 };
    voyage = { 1,2 };
    actual = o.flipMatchVoyage(createTree(values), voyage);
    expected = {  };
    check.checkIntVector(expected, actual);

    values = { 2,1,4,5,INT_MIN,3 };
    voyage = { 2,4,3,1,5 };
    actual = o.flipMatchVoyage(createTree(values), voyage);
    expected = { 2 };
    check.checkIntVector(expected, actual);
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
