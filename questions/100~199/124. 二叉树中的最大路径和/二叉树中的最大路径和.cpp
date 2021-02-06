/* 二叉树中的最大路径和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。

 

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

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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

        int leftMaxSum = DFS(root->left, maxSum);
        int rightMaxSum = DFS(root->right, maxSum);
        maxSum = (root->left == NULL && root->right == NULL) ? max(maxSum, root->val) : \
            root->left == NULL ? max({maxSum, root->val, rightMaxSum, root->val + rightMaxSum}) : \
            root->right == NULL ? max({maxSum, root->val, leftMaxSum, root->val + leftMaxSum}) : \
            max({ maxSum, leftMaxSum, root->val, rightMaxSum, leftMaxSum + root->val, root->val + rightMaxSum, leftMaxSum + root->val + rightMaxSum });

        return max({ root->val, root->val + leftMaxSum, root->val + rightMaxSum });
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,2,3 };
    check.checkInt(6, o.maxPathSum(createTree(values)));

    values = { 6 };
    check.checkInt(6, o.maxPathSum(createTree(values)));

    values = { -10,9,20,INT_MIN,INT_MIN,15,7 };
    check.checkInt(42, o.maxPathSum(createTree(values)));

    values = { 5,4,8,11,INT_MIN,13,4,7,2,INT_MIN,INT_MIN,INT_MIN,1 };
    check.checkInt(48, o.maxPathSum(createTree(values)));

    values = { -3 };
    check.checkInt(-3, o.maxPathSum(createTree(values)));

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
