/* 合并二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

示例 1:

输入:
	Tree 1                     Tree 2
		  1                         2
		 / \                       / \
		3   2                     1   3
	   /                           \   \
	  5                             4   7
输出:
合并后的树:
		 3
		/ \
	   4   5
	  / \   \
	 5   4   7
注意: 合并必须从两个树的根节点开始。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-binary-trees
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"
#include <stack>

using namespace std;

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == NULL) {
			return t2;
		}

		if (t2 == NULL) {
			return t1;
		}

		t1->val += t2->val;
		t1->left = mergeTrees(t1->left, t2->left);
		t1->right = mergeTrees(t1->right, t2->right);

		return t1;
	}
};

int main()
{
	Solution o;
	CheckResult check;

	TreeNode t11(1);
	TreeNode t12(3);
	TreeNode t13(2);
	TreeNode t14(5);
	t11.left = &t12;
	t11.right = &t13;
	t12.left = &t14;
	TreeNode t21(2);
	TreeNode t22(1);
	TreeNode t23(3);
	TreeNode t24(4);
	TreeNode t25(7);
	t21.left = &t22;
	t21.right = &t23;
	t22.right = &t24;
	t23.right = &t25;
	TreeNode* merged = o.mergeTrees(&t11, &t21);
	check.checkInt(3, merged->val);
	check.checkInt(4, merged->left->val);
	check.checkInt(5, merged->right->val);
	check.checkInt(5, merged->left->left->val);
	check.checkInt(4, merged->left->right->val);
	check.checkInt(7, merged->right->right->val);
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
