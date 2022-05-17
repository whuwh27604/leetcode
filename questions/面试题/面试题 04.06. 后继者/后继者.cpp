/* 后继者.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。

如果指定节点没有对应的“下一个”节点，则返回null。

示例 1:

输入: root = [2,1,3], p = 1

  2
 / \
1   3

输出: 2
示例 2:

输入: root = [5,3,6,2,4,null,null,1], p = 6

      5
     / \
    3   6
   / \
  2   4
 /
1

输出: null

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/successor-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = NULL;
        TreeNode* node = root;

        if (p->right != NULL) {  // 如果有右子树，那么successor是右子树的最左节点
            successor = p->right;

            while (successor->left != NULL) {
                successor = successor->left;
            }

            return successor;
        }

        while (node != NULL) {
            if (p->val < node->val) {  // 如果p比node小，那么node可能是p的successor
                successor = node;
                node = node->left;
            }
            else {  // 如果p大于等于node，那么p的successor只可能在右子树
                node = node->right;
            }
        }

        return successor;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 2,1,3 };
    TreeNode* root = createTree(values);
    check.checkPoint(root, o.inorderSuccessor(root, root->left));

    values = { 5,3,6,2,4,INT_MIN,INT_MIN,1 };
    root = createTree(values);
    check.checkPoint(NULL, o.inorderSuccessor(root, root->right));
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
