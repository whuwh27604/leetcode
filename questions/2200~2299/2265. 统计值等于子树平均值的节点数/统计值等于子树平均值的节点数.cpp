/* 统计值等于子树平均值的节点数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵二叉树的根节点 root ，找出并返回满足要求的节点数，要求节点的值等于其 子树 中值的 平均值 。

注意：

n 个元素的平均值可以由 n 个元素 求和 然后再除以 n ，并 向下舍入 到最近的整数。
root 的 子树 由 root 和它的所有后代组成。
 

示例 1：


输入：root = [4,8,5,0,1,null,6]
输出：5
解释：
对值为 4 的节点：子树的平均值 (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4 。
对值为 5 的节点：子树的平均值 (5 + 6) / 2 = 11 / 2 = 5 。
对值为 0 的节点：子树的平均值 0 / 1 = 0 。
对值为 1 的节点：子树的平均值 1 / 1 = 1 。
对值为 6 的节点：子树的平均值 6 / 1 = 6 。
示例 2：


输入：root = [1]
输出：1
解释：对值为 1 的节点：子树的平均值 1 / 1 = 1。
 

提示：

树中节点数目在范围 [1, 1000] 内
0 <= Node.val <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-nodes-equal-to-average-of-subtree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int count = 0;

        (void)DFS(root, count);

        return count;
    }

    pair<int,int> DFS(TreeNode* root, int& count) {
        if (root == NULL) {
            return { 0, 0 };
        }

        pair<int, int> left = DFS(root->left, count);
        pair<int, int> right = DFS(root->right, count);
        int sum = left.first + right.first + root->val;
        int nodes = left.second + right.second + 1;

        if (sum / nodes == root->val) {
            ++count;
        }

        return { sum, nodes };
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 4,8,5,0,1,INT_MIN,6 };
    check.checkInt(5, o.averageOfSubtree(createTree(values)));

    values = { 1 };
    check.checkInt(1, o.averageOfSubtree(createTree(values)));
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
