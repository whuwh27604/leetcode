/* 二叉树的后序遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，返回它的 后序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;
        if (root == NULL) {
            return post;
        }

        stack<pair<TreeNode*, bool>> nodes;
        nodes.push({ root, false });

        while (!nodes.empty()) {
            TreeNode* node = nodes.top().first;
            bool output = nodes.top().second;
            nodes.pop();

            if (output) {
                post.push_back(node->val);
            }
            else {
                nodes.push({ node, true });

                if (node->right != NULL) {
                    nodes.push({ node->right, false });
                }

                if (node->left != NULL) {
                    nodes.push({ node->left, false });
                }
            }
        }

        return post;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,INT_MIN,2,3 };
    vector<int> actual = o.postorderTraversal(createTree(values));
    vector<int> expected = { 3,2,1 };
    check.checkIntVector(expected, actual);

    values = { 1 };
    actual = o.postorderTraversal(createTree(values));
    expected = { 1 };
    check.checkIntVector(expected, actual);

    values = { 1,2 };
    actual = o.postorderTraversal(createTree(values));
    expected = { 2,1 };
    check.checkIntVector(expected, actual);

    values = { 1,2,3 };
    actual = o.postorderTraversal(createTree(values));
    expected = { 2,3,1 };
    check.checkIntVector(expected, actual);

    values = { 1,2,3,4,5,6,7 };
    actual = o.postorderTraversal(createTree(values));
    expected = { 4,5,2,6,7,3,1 };
    check.checkIntVector(expected, actual);

    values = { 1,2,INT_MIN,3,INT_MIN,4,INT_MIN,5 };
    actual = o.postorderTraversal(createTree(values));
    expected = { 5,4,3,2,1 };
    check.checkIntVector(expected, actual);

    actual = o.postorderTraversal(NULL);
    expected = {  };
    check.checkIntVector(expected, actual);
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
