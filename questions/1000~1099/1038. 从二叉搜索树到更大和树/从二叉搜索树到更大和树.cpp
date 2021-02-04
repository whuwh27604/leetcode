/* 从二叉搜索树到更大和树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出二叉 搜索 树的根节点，该二叉树的节点值各不相同，修改二叉树，使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

提醒一下，二叉搜索树满足下列约束条件：

节点的左子树仅包含键 小于 节点键的节点。
节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。
 

示例：



输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
 

提示：

树中的节点数介于 1 和 100 之间。
每个节点的值介于 0 和 100 之间。
给定的树为二叉搜索树。
 

注意：该题目与 538: https://leetcode-cn.com/problems/convert-bst-to-greater-tree/  相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int previous = 0;
        RDL(root, previous);
        return root;
    }

    void RDL(TreeNode* root, int& previous) {
        if (root->right != NULL) {
            RDL(root->right, previous);
        }

        root->val += previous;
        previous = root->val;

        if (root->left != NULL) {
            RDL(root->left, previous);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 4,1,6,0,2,5,7,INT_MIN,INT_MIN,INT_MIN,3,INT_MIN,INT_MIN,INT_MIN,8 };
    TreeNode* actual = o.bstToGst(createTree(values));
    values = { 30,36,21,36,35,26,15,INT_MIN,INT_MIN,INT_MIN,33,INT_MIN,INT_MIN,INT_MIN,8 };
    check.checkTree(createTree(values), actual);

    values = { 0,INT_MIN,1 };
    actual = o.bstToGst(createTree(values));
    values = { 1,INT_MIN,1 };
    check.checkTree(createTree(values), actual);

    values = { 1,0,2 };
    actual = o.bstToGst(createTree(values));
    values = { 3,3,2 };
    check.checkTree(createTree(values), actual);

    values = { 3,2,4,1 };
    actual = o.bstToGst(createTree(values));
    values = { 7,9,4,10 };
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
