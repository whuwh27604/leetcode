/* 二叉搜索子树的最大键值和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵以 root 为根的 二叉树 ，请你返回 任意 二叉搜索子树的最大键值和。

二叉搜索树的定义如下：

任意节点的左子树中的键值都 小于 此节点的键值。
任意节点的右子树中的键值都 大于 此节点的键值。
任意节点的左子树和右子树都是二叉搜索树。
 

示例 1：



输入：root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
输出：20
解释：键值为 3 的子树是和最大的二叉搜索树。
示例 2：



输入：root = [4,3,null,1,2]
输出：2
解释：键值为 2 的单节点子树是和最大的二叉搜索树。
示例 3：

输入：root = [-4,-2,-5]
输出：0
解释：所有节点键值都为负数，和最大的二叉搜索树为空。
示例 4：

输入：root = [2,1,3]
输出：6
示例 5：

输入：root = [5,4,8,3,null,6,3]
输出：7
 

提示：

每棵树有 1 到 40000 个节点。
每个节点的键值在 [-4 * 10^4 , 4 * 10^4] 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-sum-bst-in-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int maxValue;
    int minValue;
    int sum;
    bool isBST;

    Node(int maxValue_, int minValue_, int sum_, bool isBST_) : maxValue(maxValue_), minValue(minValue_), sum(sum_), isBST(isBST_) {}
};

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int maxSum = INT_MIN;

        (void)DFS(root, maxSum);

        return maxSum > 0 ? maxSum : 0;  // 子树可以为空，此时认为最小和是0
    }

    Node DFS(TreeNode* root, int& maxSum) {
        if (root == NULL) {
            return Node(INT_MIN, INT_MAX, 0, true);
        }

        Node left = DFS(root->left, maxSum);
        Node right = DFS(root->right, maxSum);
        int maximum = max({ left.maxValue, root->val, right.maxValue });
        int minimum = min({ left.minValue, root->val, right.minValue });
        int sum = root->val + left.sum + right.sum;
        bool check = left.isBST && right.isBST && root->val > left.maxValue && root->val < right.minValue;

        if (check) {
            maxSum = max(maxSum, sum);
        }

        return Node(maximum, minimum, sum, check);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,4,3,2,4,2,5,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,4,6 };
    check.checkInt(20, o.maxSumBST(createTree(values)));

    values = { 4,3,INT_MIN,1,2 };
    check.checkInt(2, o.maxSumBST(createTree(values)));

    values = { -4,-2,-5 };
    check.checkInt(0, o.maxSumBST(createTree(values)));

    values = { 2,1,3 };
    check.checkInt(6, o.maxSumBST(createTree(values)));

    values = { 5 };
    check.checkInt(5, o.maxSumBST(createTree(values)));

    values = { 5,4,8,3,INT_MIN,6,3 };
    check.checkInt(7, o.maxSumBST(createTree(values)));

    values = { 9,4,10,INT_MIN,INT_MIN,6,11 };
    check.checkInt(27, o.maxSumBST(createTree(values)));

    values = { 4,-3,6,-5,-2,5,9 };
    check.checkInt(20, o.maxSumBST(createTree(values)));

    values = { 8,9,8,INT_MIN,9,INT_MIN,1,INT_MIN,INT_MIN,-3,5,INT_MIN,-2,INT_MIN,6 };
    check.checkInt(11, o.maxSumBST(createTree(values)));

    values = { 1,INT_MIN,10,-5,20 };
    check.checkInt(25, o.maxSumBST(createTree(values)));

    values = { 18,7,20,3,20 };
    check.checkInt(30, o.maxSumBST(createTree(values)));
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
