/* 二叉树的最大深度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
        int depth = 0;

        while (!bfsQueue.empty()) {
            depth++;
            int size = bfsQueue.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = bfsQueue.front();
                bfsQueue.pop();

                if (node->left != NULL) {
                    bfsQueue.push(node->left);
                }
                if (node->right != NULL) {
                    bfsQueue.push(node->right);
                }
            }
        }

        return depth;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 3,9,20,INT_MIN,INT_MIN,15,7 };
    check.checkInt(3, o.maxDepth(createTree(values)));

    values = { 3,9,20,INT_MIN,INT_MIN,15,INT_MIN,7 };
    check.checkInt(4, o.maxDepth(createTree(values)));

    values = { 3 };
    check.checkInt(1, o.maxDepth(createTree(values)));

    values = {  };
    check.checkInt(0, o.maxDepth(createTree(values)));

    values = { 3,9,INT_MIN,20,INT_MIN,15,INT_MIN,7 };
    check.checkInt(5, o.maxDepth(createTree(values)));
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
