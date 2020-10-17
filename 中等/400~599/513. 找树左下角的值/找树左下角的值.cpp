/* 找树左下角的值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，在树的最后一行找到最左边的值。

示例 1:

输入:

    2
   / \
  1   3

输出:
1
 

示例 2:

输入:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

输出:
7
 

注意: 您可以假设树（即给定的根节点）不为 NULL。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-bottom-left-tree-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <list>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int leftmost = 0;
        list<TreeNode*> bfs;
        bfs.push_front(root);

        while (!bfs.empty()) {
            int size = bfs.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = bfs.back();
                leftmost = node->val;
                bfs.pop_back();

                if (node->right != NULL) {
                    bfs.push_front(node->right);
                }
                if (node->left != NULL) {
                    bfs.push_front(node->left);
                }
            }
        }

        return leftmost;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 2,1,3 };
    check.checkInt(1, o.findBottomLeftValue(createTree(values)));

    values = { 1,2,3,4,INT_MIN,5,6,INT_MIN,INT_MIN,7 };
    check.checkInt(7, o.findBottomLeftValue(createTree(values)));

    values = { 1 };
    check.checkInt(1, o.findBottomLeftValue(createTree(values)));

    values = { 1,INT_MIN,2 };
    check.checkInt(2, o.findBottomLeftValue(createTree(values)));
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
