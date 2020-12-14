/* 将二叉搜索树变平衡.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵二叉搜索树，请你返回一棵 平衡后 的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。

如果一棵二叉搜索树中，每个节点的两棵子树高度差不超过 1 ，我们就称这棵二叉搜索树是 平衡的 。

如果有多种构造方法，请你返回任意一种。

 

示例：



输入：root = [1,null,2,null,3,null,4,null,null]
输出：[2,1,3,null,null,null,4]
解释：这不是唯一的正确答案，[3,1,4,null,2,null,null] 也是一个可行的构造方案。
 

提示：

树节点的数目在 1 到 10^4 之间。
树节点的值互不相同，且在 1 到 10^5 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/balance-a-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        LDR(root, values);

        return createTree(values, 0, values.size() - 1);
    }

    void LDR(TreeNode* root, vector<int>& values) {
        if (root == NULL) {
            return;
        }

        LDR(root->left, values);
        values.push_back(root->val);
        LDR(root->right, values);
    }

    TreeNode* createTree(vector<int>& values, int start, int end) {
        if (start == end) {
            return new TreeNode(values[start]);
        }

        int middle = (start + end) / 2;
        TreeNode* root = new TreeNode(values[middle]);
        root->left = (start == middle ? NULL : createTree(values, start, middle - 1));
        root->right = createTree(values, middle + 1, end);

        return root;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,INT_MIN,2,INT_MIN,3,INT_MIN,4 };
    TreeNode* actual = o.balanceBST(createTree(values));
    values = { 2,1,3,INT_MIN,INT_MIN,INT_MIN,4 };
    TreeNode* expected = createTree(values);
    check.checkTree(expected, actual);

    values = { 14,9,16,2,13 };
    actual = o.balanceBST(createTree(values));
    values = { 13,2,14,INT_MIN,9,INT_MIN,16 };
    expected = createTree(values);
    check.checkTree(expected, actual);

    values = { 1,INT_MIN,15,14,17,7,INT_MIN,INT_MIN,INT_MIN,2,12,INT_MIN,3,9,INT_MIN,INT_MIN,INT_MIN,INT_MIN,11 };
    actual = o.balanceBST(createTree(values));
    values = { 9,2,14,1,3,11,15,INT_MIN,INT_MIN,INT_MIN,7,INT_MIN,12,INT_MIN,17 };
    expected = createTree(values);
    check.checkTree(expected, actual);

    values = { 1 };
    actual = o.balanceBST(createTree(values));
    values = { 1 };
    expected = createTree(values);
    check.checkTree(expected, actual);
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
