/* 路径总和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例: 
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }

        if ((root->left == NULL) && (root->right == NULL) && (root->val == sum)) {
            return true;
        }

        if ((root->left != NULL) && (hasPathSum(root->left, sum - root->val))) {
            return true;
        }

        if ((root->right != NULL) && (hasPathSum(root->right, sum - root->val))) {
            return true;
        }

        return false;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 5,4,8,11,INT_MIN,13,4,7,2,INT_MIN,INT_MIN,INT_MIN,1 };
    TreeNode* root = createTree(values);
    check.checkBool(true, o.hasPathSum(root, 27));
    check.checkBool(true, o.hasPathSum(root, 22));
    check.checkBool(true, o.hasPathSum(root, 26));
    check.checkBool(true, o.hasPathSum(root, 18));
    check.checkBool(false, o.hasPathSum(root, 100));
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
