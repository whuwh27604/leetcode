/* 翻转等价二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们可以为二叉树 T 定义一个翻转操作，如下所示：选择任意节点，然后交换它的左子树和右子树。

只要经过一定次数的翻转操作后，能使 X 等于 Y，我们就称二叉树 X 翻转等价于二叉树 Y。

编写一个判断两个二叉树是否是翻转等价的函数。这些树由根节点 root1 和 root2 给出。

 

示例：

输入：root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
输出：true
解释：我们翻转值为 1，3 以及 5 的三个节点。

 

提示：

每棵树最多有 100 个节点。
每棵树中的每个值都是唯一的、在 [0, 99] 范围内的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flip-equivalent-binary-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if ((root1 == NULL) && (root2 == NULL)) {
            return true;
        }

        if ((root1 == NULL) || (root2 == NULL) || (root1->val != root2->val)) {
            return false;
        }

        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right))
            || (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,2,3,4,5,6,INT_MIN,INT_MIN,INT_MIN,7,8 };
    TreeNode* root1 = createTree(values);
    values = { 1,3,2,INT_MIN,6,4,5,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8,7 };
    TreeNode* root2 = createTree(values);
    check.checkBool(true, o.flipEquiv(root1, root2));

    check.checkBool(true, o.flipEquiv(NULL, NULL));
    check.checkBool(false, o.flipEquiv(root1, NULL));
    check.checkBool(false, o.flipEquiv(NULL, root2));

    values = { 1,3,2,INT_MIN,6,4,5,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8,9 };
    root2 = createTree(values);
    check.checkBool(false, o.flipEquiv(root1, root2));

    values = { 1 };
    root1 = createTree(values);
    root2 = createTree(values);
    check.checkBool(true, o.flipEquiv(root1, root2));

    values = { 1 };
    root1 = createTree(values);
    values = { 2 };
    root2 = createTree(values);
    check.checkBool(false, o.flipEquiv(root1, root2));

    values = { 1,2 };
    root1 = createTree(values);
    values = { 1,INT_MIN,2 };
    root2 = createTree(values);
    check.checkBool(true, o.flipEquiv(root1, root2));

    values = { 1,2 };
    root1 = createTree(values);
    values = { 1,INT_MIN,3 };
    root2 = createTree(values);
    check.checkBool(false, o.flipEquiv(root1, root2));
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
