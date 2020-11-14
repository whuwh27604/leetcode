/* 根到叶路径上的不足节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一棵二叉树的根 root，请你考虑它所有 从根到叶的路径：从根到任何叶的路径。（所谓一个叶子节点，就是一个没有子节点的节点）

假如通过节点 node 的每种可能的 “根-叶” 路径上值的总和全都小于给定的 limit，则该节点被称之为「不足节点」，需要被删除。

请你删除所有不足节点，并返回生成的二叉树的根。

 

示例 1：


输入：root = [1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14], limit = 1

输出：[1,2,3,4,null,null,7,8,9,null,14]
示例 2：


输入：root = [5,4,8,11,null,17,4,7,1,null,null,5,3], limit = 22

输出：[5,4,8,11,null,17,4,7,null,null,null,5]
示例 3：


输入：root = [5,-6,-6], limit = 0
输出：[]
 

提示：

给定的树有 1 到 5000 个节点
-10^5 <= node.val <= 10^5
-10^9 <= limit <= 10^9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insufficient-nodes-in-root-to-leaf-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return DFS(root, 0, limit) ? NULL : root;
    }

    bool DFS(TreeNode* root, int sum, int limit) {
        bool leftResult = true, rightResult = true;

        sum += root->val;

        if (root->left == NULL && root->right == NULL) {
            return sum < limit;
        }

        if (root->left != NULL && (leftResult = DFS(root->left, sum, limit))) {
            root->left = NULL;
        }

        if (root->right != NULL && (rightResult = DFS(root->right, sum, limit))) {
            root->right = NULL;
        }

        return leftResult && rightResult;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,2,3,4,-99,-99,7,8,9,-99,-99,12,13,-99,14 };
    TreeNode* actual = o.sufficientSubset(createTree(values), 1);
    values = { 1,2,3,4,INT_MIN,INT_MIN,7,8,9,INT_MIN,14 };
    check.checkTree(createTree(values), actual);

    values = { 5,4,8,11,INT_MIN,17,4,7,1,INT_MIN,INT_MIN,5,3 };
    actual = o.sufficientSubset(createTree(values), 22);
    values = { 5,4,8,11,INT_MIN,17,4,7,INT_MIN,INT_MIN,INT_MIN,5 };
    check.checkTree(createTree(values), actual);

    values = { 5,-6,-6 };
    actual = o.sufficientSubset(createTree(values), 22);
    values = {  };
    check.checkTree(createTree(values), actual);

    values = { 5 };
    actual = o.sufficientSubset(createTree(values), 5);
    values = { 5 };
    check.checkTree(createTree(values), actual);

    values = { 5 };
    actual = o.sufficientSubset(createTree(values), 6);
    values = {  };
    check.checkTree(createTree(values), actual);

    values = { 1,2,-3,-5,INT_MIN,4 };
    actual = o.sufficientSubset(createTree(values), -1);
    values = { 1,INT_MIN,-3,4 };
    check.checkTree(createTree(values), actual);
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
