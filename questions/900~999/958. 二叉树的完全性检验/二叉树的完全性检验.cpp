/* 二叉树的完全性检验.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，确定它是否是一个完全二叉树。

百度百科中对完全二叉树的定义如下：

若设二叉树的深度为 h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，第 h 层所有的结点都连续集中在最左边，这就是完全二叉树。（注：第 h 层可能包含 1~ 2h 个节点。）

 

示例 1：



输入：[1,2,3,4,5,6]
输出：true
解释：最后一层前的每一层都是满的（即，结点值为 {1} 和 {2,3} 的两层），且最后一层中的所有结点（{4,5,6}）都尽可能地向左。
示例 2：



输入：[1,2,3,4,5,null,7]
输出：false
解释：值为 7 的结点没有尽可能靠向左侧。
 

提示：

树中将会有 1 到 100 个结点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/check-completeness-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        bool completed = false;

        while (!bfs.empty()) {
            TreeNode* node = bfs.front();
            bfs.pop();

            if (completed) {
                if (node->left != NULL || node->right != NULL) {
                    return false;
                }
            }
            else {
                if (node->left != NULL) {
                    bfs.push(node->left);
                }
                else {
                    completed = true;
                }

                if (node->right != NULL) {
                    if (completed) {
                        return false;
                    }
                    else {
                        bfs.push(node->right);
                    }
                }
                else {
                    completed = true;
                }
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,2,3,4,5,6 };
    check.checkBool(true, o.isCompleteTree(createTree(values)));

    values = { 1,2,3,4,5,INT_MIN,7 };
    check.checkBool(false, o.isCompleteTree(createTree(values)));

    values = { 6 };
    check.checkBool(true, o.isCompleteTree(createTree(values)));

    values = { 1,2 };
    check.checkBool(true, o.isCompleteTree(createTree(values)));

    values = { 1,INT_MIN,7 };
    check.checkBool(false, o.isCompleteTree(createTree(values)));

    values = { 1,2,INT_MIN,3 };
    check.checkBool(false, o.isCompleteTree(createTree(values)));

    values = { 1,2,3,INT_MIN,INT_MIN,4,5 };
    check.checkBool(false, o.isCompleteTree(createTree(values)));
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
