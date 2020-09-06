/* 二叉树的层次遍历 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> allNodes;
        if (root == NULL) {
            return allNodes;
        }

        queue<TreeNode*> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            int size = bfs.size();
            allNodes.push_back({});

            for (int i = 0; i < size; i++) {
                allNodes.back().push_back(bfs.front()->val);
                if (bfs.front()->left != NULL) {
                    bfs.push(bfs.front()->left);
                }
                if (bfs.front()->right != NULL) {
                    bfs.push(bfs.front()->right);
                }
                bfs.pop();
            }
        }

        reverse(allNodes.begin(), allNodes.end());
        return allNodes;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode node4(15);
    TreeNode node5(7);
    TreeNode node2(9);
    TreeNode node3(20);
    node3.left = &node4;
    node3.right = &node5;
    TreeNode node1(3);
    node1.left = &node2;
    node1.right = &node3;
    vector<vector<int>> actual = o.levelOrderBottom(&node1);
    vector<vector<int>> expected;
    vector<int> layerNums = { 15,7 };
    expected.push_back(layerNums);
    layerNums = { 9,20 };
    expected.push_back(layerNums);
    layerNums = { 3 };
    expected.push_back(layerNums);
    check.checkIntDoubleVector(expected, actual);

    node3.right = NULL;
    node4.right = &node5;
    actual = o.levelOrderBottom(&node1);
    expected.clear();
    layerNums = { 7 };
    expected.push_back(layerNums);
    layerNums = { 15 };
    expected.push_back(layerNums);
    layerNums = { 9,20 };
    expected.push_back(layerNums);
    layerNums = { 3 };
    expected.push_back(layerNums);
    check.checkIntDoubleVector(expected, actual);

    actual = o.levelOrderBottom(NULL);
    expected = {};
    check.checkIntDoubleVector(expected, actual);
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
