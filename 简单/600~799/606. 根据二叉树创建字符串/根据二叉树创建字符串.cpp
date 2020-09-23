/* 根据二叉树创建字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。

空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。

示例 1:

输入: 二叉树: [1,2,3,4]
       1
     /   \
    2     3
   /
  4

输出: "1(2(4))(3)"

解释: 原本将是“1(2(4)())(3())”，
在你省略所有不必要的空括号对之后，
它将是“1(2(4))(3)”。
示例 2:

输入: 二叉树: [1,2,3,null,4]
       1
     /   \
    2     3
     \
      4

输出: "1(2()(4))(3)"

解释: 和第一个示例相似，
除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-string-from-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    string tree2str(TreeNode* t) {
        string s;

        if (t != NULL) {
            DLR(t, s);
        }

        return s;
    }

    void DLR(TreeNode* t, string& s) {
        s += to_string(t->val);

        if ((t->left == NULL) && (t->right == NULL)) {
            return;
        }

        s += "(";
        if (t->left != NULL) {
            DLR(t->left, s);
        }
        s += ')';

        if (t->right != NULL) {
            s += '(';
            DLR(t->right, s);
            s += ')';
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    check.checkString("1(2(4))(3)", o.tree2str(&node1));

    node2.left = NULL;
    node2.right = &node4;
    check.checkString("1(2()(4))(3)", o.tree2str(&node1));

    node1.left = &node2;
    node1.right = NULL;
    node2.left = NULL;
    node2.right = &node3;
    node3.left = node3.right = NULL;
    check.checkString("1(2()(3))", o.tree2str(&node1));

    node1.left = NULL;
    node1.right = &node2;
    node2.left = &node3;
    node2.right = NULL;
    node3.left = node3.right = NULL;
    check.checkString("1()(2(3))", o.tree2str(&node1));

    check.checkString("4", o.tree2str(&node4));

    check.checkString("", o.tree2str(NULL));
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
