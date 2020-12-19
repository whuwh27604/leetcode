/* 另一个树的子树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

示例 1:
给定的树 s:

     3
    / \
   4   5
  / \
 1   2
给定的树 t：

   4
  / \
 1   2
返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。

示例 2:
给定的树 s：

     3
    / \
   4   5
  / \
 1   2
    /
   0
给定的树 t：

   4
  / \
 1   2
返回 false。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subtree-of-another-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if ((s == NULL) || (t == NULL)) {
            return false;
        }

        string ss, tt;
        DLR(s, ss);  // 注意中序遍历有可能误判
        DLR(t, tt);
        return (ss.find(tt) != string::npos);
    }

    void DLR(TreeNode* root, string& tree2String) {
        tree2String += 's';  // 有必要加一个分隔符，否则root为2、12或者4、24之类的会产生误判
        tree2String += to_string(root->val);

        if (root->left != NULL) {
            DLR(root->left, tree2String);
        }
        else {
            tree2String += 'n';
        }

        if (root->right != NULL) {
            DLR(root->right, tree2String);
        }
        else {
            tree2String += 'n';
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 3,4,5,1,2 };
    TreeNode* s = createTree(values);
    values = { 4,1,2 };
    TreeNode* t = createTree(values);
    check.checkBool(true, o.isSubtree(s, t));

    values = { 3,24,5,1,2 };
    s = createTree(values);
    check.checkBool(false, o.isSubtree(s, t));

    check.checkBool(false, o.isSubtree(s, NULL));
    check.checkBool(false, o.isSubtree(NULL, t));
    check.checkBool(false, o.isSubtree(NULL, NULL));

    values = { 12 };
    s = createTree(values);
    values = { 2 };
    t = createTree(values);
    check.checkBool(false, o.isSubtree(s, t));
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
