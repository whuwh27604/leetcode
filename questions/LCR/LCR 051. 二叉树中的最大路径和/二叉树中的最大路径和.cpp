/* 二叉树中的最大路径和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给定一个二叉树的根节点 root ，返回其 最大路径和，即所有路径上节点值之和的最大值。



示例 1：



输入：root = [1,2,3]
输出：6
解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
示例 2：



输入：root = [-10,9,20,null,null,15,7]
输出：42
解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42


提示：

树中节点数目范围是 [1, 3 * 104]
-1000 <= Node.val <= 1000


注意：本题与主站 124 题相同： https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;

        (void)DFS(root, maxSum);

        return maxSum;
    }

    int DFS(TreeNode* root, int& maxSum) {
        if (root == NULL) {
            return 0;
        }

        int sum = root->val;
        int leftSum = DFS(root->left, maxSum);
        if (leftSum > 0) {
            sum += leftSum;
        }
        int rightSum = DFS(root->right, maxSum);
        if (rightSum > 0) {
            sum += rightSum;
        }

        maxSum = max(maxSum, sum);

        return max({ root->val, root->val + leftSum, root->val + rightSum });
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,2,3 };
    check.checkInt(6, o.maxPathSum(createTree(values)));

    values = { -10,9,20,INT_MIN,INT_MIN,15,7 };
    check.checkInt(42, o.maxPathSum(createTree(values)));

    values = { 9,6,-3,INT_MIN,INT_MIN,-6,2,INT_MIN,INT_MIN,2,INT_MIN,-6,-6,-6 };
    check.checkInt(16, o.maxPathSum(createTree(values)));
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
