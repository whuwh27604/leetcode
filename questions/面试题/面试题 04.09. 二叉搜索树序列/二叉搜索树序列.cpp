/* 二叉搜索树序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
从左向右遍历一个数组，通过不断将其中的元素插入树中可以逐步地生成一棵二叉搜索树。

给定一个由不同节点组成的二叉搜索树 root，输出所有可能生成此树的数组。



示例 1:

输入: root = [2,1,3]
输出: [[2,1,3],[2,3,1]]
解释: 数组 [2,1,3]、[2,3,1] 均可以通过从左向右遍历元素插入树中形成以下二叉搜索树
       2
      / \
     1   3
示例 2:

输入: root = [4,1,null,null,3,2]
输出: [[4,1,3,2]]


提示：

二叉搜索树中的节点数在 [0, 1000] 的范围内
1 <= 节点值 <= 10^6
用例保证符合要求的数组数量不超过 5000
*/

#include <iostream>
#include <deque>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> BSTSequences(TreeNode* root) {
        if (root == NULL) {
            return { {} };
        }

        vector<int> path;
        vector<vector<int>> paths;
        deque<TreeNode*> nodes;
        nodes.push_back(root);
        DFS(nodes, path, paths);

        return paths;
    }

    void DFS(deque<TreeNode*>& nodes, vector<int>& path, vector<vector<int>>& paths) {
        if (nodes.empty()) {
            paths.push_back(path);
            return;
        }

        int size = nodes.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = nodes.front();
            nodes.pop_front();

            path.push_back(node->val);

            if (node->left != NULL) {
                nodes.push_back(node->left);
            }
            if (node->right != NULL) {
                nodes.push_back(node->right);
            }

            DFS(nodes, path, paths);

            if (node->left != NULL) {
                nodes.pop_back();
            }
            if (node->right != NULL) {
                nodes.pop_back();
            }

            nodes.push_back(node);
            path.pop_back();
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 2,1,3 };
    vector<vector<int>> actual = o.BSTSequences(createTree(values));
    vector<vector<int>> expected = { {2,1,3},{2,3,1} };
    check.checkIntVectorRandomOrderVector(expected, actual);

    values = { 4,1,INT_MIN,INT_MIN,3,2 };
    actual = o.BSTSequences(createTree(values));
    expected = { {4,1,3,2} };
    check.checkIntVectorRandomOrderVector(expected, actual);

    values = {  };
    actual = o.BSTSequences(createTree(values));
    expected = { {} };
    check.checkIntVectorRandomOrderVector(expected, actual);
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
