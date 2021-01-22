/* 叶子相似的树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请考虑一颗二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。



举个例子，如上图所示，给定一颗叶值序列为 (6, 7, 4, 9, 8) 的树。

如果有两颗二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。

如果给定的两个头结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。

 

提示：

给定的两颗树可能会有 1 到 200 个结点。
给定的两颗树上的值介于 0 到 200 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/leaf-similar-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        DFS(root1, leaves1);
        DFS(root2, leaves2);

        return leaves1 == leaves2;
    }

    void DFS(TreeNode* root, vector<int>& leaves) {
        if (root == NULL) {
            return;
        }

        if ((root->left == NULL) && (root->right == NULL)) {
            leaves.push_back(root->val);
            return;
        }

        DFS(root->left, leaves);
        DFS(root->right, leaves);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values1 = { 3,5,1,6,2,9,8,INT_MIN,INT_MIN,7,4 };
    vector<int> values2 = { 3,5,1,6,7,4,2,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,9,8 };
    check.checkBool(true, o.leafSimilar(createTree(values1), createTree(values2)));

    values1 = { 1 };
    values2 = { 1 };
    check.checkBool(true, o.leafSimilar(createTree(values1), createTree(values2)));

    values1 = { 1 };
    values2 = { 2 };
    check.checkBool(false, o.leafSimilar(createTree(values1), createTree(values2)));

    values1 = { 1,2 };
    values2 = { 1,2 };
    check.checkBool(true, o.leafSimilar(createTree(values1), createTree(values2)));

    values1 = { 1,2,3 };
    values2 = { 2,3,2 };
    check.checkBool(false, o.leafSimilar(createTree(values1), createTree(values2)));
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
