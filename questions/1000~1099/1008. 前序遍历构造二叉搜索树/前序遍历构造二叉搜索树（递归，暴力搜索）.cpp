/* 前序遍历构造二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
返回与给定前序遍历 preorder 相匹配的二叉搜索树（binary search tree）的根结点。

(回想一下，二叉搜索树是二叉树的一种，其每个节点都满足以下规则，对于 node.left 的任何后代，值总 < node.val，而 node.right 的任何后代，值总 > node.val。此外，前序遍历首先显示节点 node 的值，然后遍历 node.left，接着遍历 node.right。）

题目保证，对于给定的测试用例，总能找到满足要求的二叉搜索树。

 

示例：

输入：[8,5,1,7,10,12]
输出：[8,5,10,1,7,null,12]

 

提示：

1 <= preorder.length <= 100
1 <= preorder[i] <= 10^8
preorder 中的值互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-search-tree-from-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildTree(preorder, 0, preorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& preorder, int start, int end) {
        TreeNode* root = new TreeNode(preorder[start]);

        if (start == end) {
            return root;
        }

        if (preorder[start + 1] > preorder[start]) {
            root->right = buildTree(preorder, start + 1, end);
        }
        else {
            int leftStart = start + 1, rightStart = leftStart + 1;

            while (rightStart <= end && preorder[rightStart] < preorder[start]) {
                ++rightStart;
            }

            root->left = buildTree(preorder, leftStart, rightStart - 1);
            root->right = (rightStart <= end) ? buildTree(preorder, rightStart, end) : NULL;
        }

        return root;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> preorder = { 8,5,1,7,10,12 };
    TreeNode* actual = o.bstFromPreorder(preorder);
    vector<int> values = { 8,5,10,1,7,INT_MIN,12 };
    TreeNode* expected = createTree(values);
    check.checkTree(expected, actual);

    preorder = { 8 };
    actual = o.bstFromPreorder(preorder);
    values = { 8 };
    expected = createTree(values);
    check.checkTree(expected, actual);

    preorder = { 8,5 };
    actual = o.bstFromPreorder(preorder);
    values = { 8,5 };
    expected = createTree(values);
    check.checkTree(expected, actual);

    preorder = { 5,8 };
    actual = o.bstFromPreorder(preorder);
    values = { 5,INT_MIN,8 };
    expected = createTree(values);
    check.checkTree(expected, actual);

    preorder = { 8,5,1 };
    actual = o.bstFromPreorder(preorder);
    values = { 8,5,INT_MIN,1 };
    expected = createTree(values);
    check.checkTree(expected, actual);

    preorder = { 5,1,8 };
    actual = o.bstFromPreorder(preorder);
    values = { 5,1,8 };
    expected = createTree(values);
    check.checkTree(expected, actual);

    preorder = { 1,5,8 };
    actual = o.bstFromPreorder(preorder);
    values = { 1,INT_MIN,5,INT_MIN,8 };
    expected = createTree(values);
    check.checkTree(expected, actual);

    preorder = { 8,1,5 };
    actual = o.bstFromPreorder(preorder);
    values = { 8,1,INT_MIN,INT_MIN,5 };
    expected = createTree(values);
    check.checkTree(expected, actual);

    preorder = { 1,8,5 };
    actual = o.bstFromPreorder(preorder);
    values = { 1,INT_MIN,8,5 };
    expected = createTree(values);
    check.checkTree(expected, actual);

    preorder = { 100,50,10,1,15,70,60,80,150,120,110,130,170,160,180 };
    actual = o.bstFromPreorder(preorder);
    values = { 100,50,150,10,70,120,170,1,15,60,80,110,130,160,180 };
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
