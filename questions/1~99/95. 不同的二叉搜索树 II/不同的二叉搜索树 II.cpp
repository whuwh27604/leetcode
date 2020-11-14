/* 不同的二叉搜索树 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

 

示例：

输入：3
输出：
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释：
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 

提示：

0 <= n <= 8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-binary-search-trees-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }

        vector<vector<TreeNode*>> trees(n + 1, vector<TreeNode*>());
        trees[0] = { NULL };

        TreeNode* root = new TreeNode(1);
        trees[1] = { root };

        for (int i = 2; i <= n; i++) {
            createTrees(trees, i);
        }

        return trees[n];
    }

    void createTrees(vector<vector<TreeNode*>>& trees, int n) {
        for (int rootValue = 1; rootValue <= n; rootValue++) {
            int leftNodesCount = rootValue - 1;
            int leftTreesCount = trees[leftNodesCount].size();
            vector<TreeNode*>& leftTrees = trees[leftNodesCount];

            int rightNodesCount = n - rootValue;
            int rightTreesCount = trees[rightNodesCount].size();
            vector<TreeNode*> rightTrees(rightTreesCount, NULL);
            for (int right = 0; right < rightTreesCount; right++) {
                rightTrees[right] = copyTree(trees[rightNodesCount][right], rootValue + 1);
            }

            for (int left = 0; left < leftTreesCount; left++) {
                for (int right = 0; right < rightTreesCount; right++) {
                    TreeNode* root = new TreeNode(rootValue);
                    root->left = leftTrees[left];
                    root->right = rightTrees[right];
                    trees[n].push_back(root);
                }
            }            
        }
    }

    TreeNode* copyTree(TreeNode* root, int baseValue) {
        if (root == NULL) {
            return NULL;
        }

        TreeNode* copyRoot = new TreeNode;
        DLR(root, copyRoot, baseValue);

        return copyRoot;
    }

    void DLR(TreeNode* root, TreeNode* copyRoot, int baseValue) {
        copyRoot->val = root->val + baseValue - 1;

        if (root->left) {
            TreeNode* copyLeft = new TreeNode;
            copyRoot->left = copyLeft;
            DLR(root->left, copyLeft, baseValue);
        }

        if (root->right) {
            TreeNode* copyRight = new TreeNode;
            copyRoot->right = copyRight;
            DLR(root->right, copyRight, baseValue);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkInt(0, o.generateTrees(0).size());
    check.checkInt(1, o.generateTrees(1).size());
    check.checkInt(2, o.generateTrees(2).size());
    check.checkInt(5, o.generateTrees(3).size());
    check.checkInt(14, o.generateTrees(4).size());
    check.checkInt(42, o.generateTrees(5).size());
    check.checkInt(132, o.generateTrees(6).size());
    check.checkInt(429, o.generateTrees(7).size());
    check.checkInt(1430, o.generateTrees(8).size());
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
