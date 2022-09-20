/* 反转二叉树的奇数层.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵 完美 二叉树的根节点 root ，请你反转这棵树中每个 奇数 层的节点值。

例如，假设第 3 层的节点值是 [2,1,3,4,7,11,29,18] ，那么反转后它应该变成 [18,29,11,7,4,3,1,2] 。
反转后，返回树的根节点。

完美 二叉树需满足：二叉树的所有父节点都有两个子节点，且所有叶子节点都在同一层。

节点的 层数 等于该节点到根节点之间的边数。

 

示例 1：


输入：root = [2,3,5,8,13,21,34]
输出：[2,5,3,8,13,21,34]
解释：
这棵树只有一个奇数层。
在第 1 层的节点分别是 3、5 ，反转后为 5、3 。
示例 2：


输入：root = [7,13,11]
输出：[7,11,13]
解释：
在第 1 层的节点分别是 13、11 ，反转后为 11、13 。
示例 3：

输入：root = [0,1,2,0,0,0,0,1,1,1,1,2,2,2,2]
输出：[0,2,1,0,0,0,0,2,2,2,2,1,1,1,1]
解释：奇数层由非零值组成。
在第 1 层的节点分别是 1、2 ，反转后为 2、1 。
在第 3 层的节点分别是 1、1、1、1、2、2、2、2 ，反转后为 2、2、2、2、1、1、1、1 。
 

提示：

树中的节点数目在范围 [1, 214] 内
0 <= Node.val <= 105
root 是一棵 完美 二叉树

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/reverse-odd-levels-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        DFS(root->left, root->right, true);

        return root;
    }

    void DFS(TreeNode* node1, TreeNode* node2, bool odd) {
        if (node1 == NULL) {
            return;
        }

        if (odd) {
            swap(node1->val, node2->val);
        }

        DFS(node1->left, node2->right, !odd);
        DFS(node1->right, node2->left, !odd);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 2,3,5,8,13,21,34 };
    TreeNode* actual = o.reverseOddLevels(createTree(values));
    values = { 2,5,3,8,13,21,34 };
    check.checkTree(createTree(values), actual);

    values = { 7,13,11 };
    actual = o.reverseOddLevels(createTree(values));
    values = { 7,11,13 };
    check.checkTree(createTree(values), actual);

    values = { 0,1,2,0,0,0,0,1,1,1,1,2,2,2,2 };
    actual = o.reverseOddLevels(createTree(values));
    values = { 0,2,1,0,0,0,0,2,2,2,2,1,1,1,1 };
    check.checkTree(createTree(values), actual);

    values = { 7 };
    actual = o.reverseOddLevels(createTree(values));
    values = { 7 };
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
