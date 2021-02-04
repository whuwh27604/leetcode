/* 把二叉搜索树转换为累加树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。

 

例如：

输入: 原始二叉搜索树:
              5
            /   \
           2     13

输出: 转换为累加树:
             18
            /   \
          20     13
 

注意：本题和 1038: https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/ 相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-bst-to-greater-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int previous = 0;

        if (root != NULL) {
            RDL(root, previous);
        }

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
    TreeNode* actual = o.convertBST(createTree(values));
    values = { 30,36,21,36,35,26,15,INT_MIN,INT_MIN,INT_MIN,33,INT_MIN,INT_MIN,INT_MIN,8 };
    check.checkTree(createTree(values), actual);

    values = { 0,INT_MIN,1 };
    actual = o.convertBST(createTree(values));
    values = { 1,INT_MIN,1 };
    check.checkTree(createTree(values), actual);

    values = { 1,0,2 };
    actual = o.convertBST(createTree(values));
    values = { 3,3,2 };
    check.checkTree(createTree(values), actual);

    values = { 3,2,4,1 };
    actual = o.convertBST(createTree(values));
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
