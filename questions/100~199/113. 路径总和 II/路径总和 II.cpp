﻿/* 路径总和 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。

说明: 叶子节点是指没有子节点的节点。

示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        if (root == NULL) {
            return paths;
        }

        vector<int> path;
        DFS(root, 0, sum, path, paths);

        return paths;
    }

    void DFS(TreeNode* root, int sum, int target, vector<int>& path, vector<vector<int>>& paths) {
        path.push_back(root->val);

        sum += root->val;
        if (sum == target && root->left == NULL && root->right == NULL) {
            paths.push_back(path);
        }

        if (root->left != NULL) {
            DFS(root->left, sum, target, path, paths);
        }

        if (root->right != NULL) {
            DFS(root->right, sum, target, path, paths);
        }

        path.pop_back();
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 5,4,8,11,INT_MIN,13,4,7,2,INT_MIN,INT_MIN,5,1 };
    vector<vector<int>> actual = o.pathSum(createTree(values), 22);
    vector<vector<int>> expected = { {5,4,11,2},{5,8,4,5} };
    check.checkIntVectorVector(expected, actual);

    actual = o.pathSum(NULL, 22);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    values = { 2 };
    actual = o.pathSum(createTree(values), 2);
    expected = { {2} };
    check.checkIntVectorVector(expected, actual);

    values = { 1,2 };
    actual = o.pathSum(createTree(values), 1);
    expected = {  };
    check.checkIntVectorVector(expected, actual);
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
