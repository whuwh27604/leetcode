/* 单值二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。

只有给定的树是单值二叉树时，才返回 true；否则返回 false。

 

示例 1：



输入：[1,1,1,1,1,null,1]
输出：true
示例 2：



输入：[2,2,2,5,2]
输出：false
 

提示：

给定树的节点数范围是 [1, 100]。
每个节点的值都是整数，范围为 [0, 99] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/univalued-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        int univalue = root->val;
        return LDR(root, univalue);
    }

    bool LDR(TreeNode* root, int univalue) {
        if ((root->left != NULL) && !LDR(root->left, univalue)) {
            return false;
        }

        if ((root->right != NULL) && !LDR(root->right, univalue)) {
            return false;
        }

        return (root->val == univalue);
    }
};

using namespace std;

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 1,1,1,1,1,INT_MIN,1 };
    check.checkBool(true, o.isUnivalTree(createTree(values)));

    values = { 1,1,1,1,1,INT_MIN,2 };
    check.checkBool(false, o.isUnivalTree(createTree(values)));

    values = { 2,2,2,5,2,INT_MIN,2 };
    check.checkBool(false, o.isUnivalTree(createTree(values)));

    values = { 5 };
    check.checkBool(true, o.isUnivalTree(createTree(values)));

    values = { 2,2,2,2,2,INT_MIN,2 };
    check.checkBool(true, o.isUnivalTree(createTree(values)));
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
