/* 子结构判断.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定两棵二叉树 tree1 和 tree2，判断 tree2 是否以 tree1 的某个节点为根的子树具有 相同的结构和节点值 。
注意，空树 不会是以 tree1 的某个节点为根的子树具有 相同的结构和节点值 。



示例 1：







输入：tree1 = [1,7,5], tree2 = [6,1]
输出：false
解释：tree2 与 tree1 的一个子树没有相同的结构和节点值。
示例 2：



输入：tree1 = [3,6,7,1,8], tree2 = [6,1]
输出：true
解释：tree2 与 tree1 的一个子树拥有相同的结构和节点值。即 6 - > 1。


提示：

0 <= 节点个数 <= 10000
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (B != NULL) && DFS(A, B);
    }

    bool DFS(TreeNode* A, TreeNode* B) {
        return isSub(A, B) || ((A != NULL) && (DFS(A->left, B) || DFS(A->right, B)));
    }

    bool isSub(TreeNode* A, TreeNode* B) {
        return (B == NULL) || (A != NULL && A->val == B->val && isSub(A->left, B->left) && isSub(A->right, B->right));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 1,7,5 };
    TreeNode* A = createTree(values);
    values = { 6,1 };
    TreeNode* B = createTree(values);
    check.checkBool(false, o.isSubStructure(A, B));

    values = { 3,6,7,1,8 };
    A = createTree(values);
    values = {  };
    B = createTree(values);
    check.checkBool(false, o.isSubStructure(A, B));

    values = {  };
    A = createTree(values);
    values = {  };
    B = createTree(values);
    check.checkBool(false, o.isSubStructure(A, B));

    values = {  };
    A = createTree(values);
    values = { 1 };
    B = createTree(values);
    check.checkBool(false, o.isSubStructure(A, B));

    values = { 1,0,1,-4,-3 };
    A = createTree(values);
    values = { 1,-4 };
    B = createTree(values);
    check.checkBool(false, o.isSubStructure(A, B));

    values = { 3,6,7,1,8 };
    A = createTree(values);
    values = { 6,1 };
    B = createTree(values);
    check.checkBool(true, o.isSubStructure(A, B));

    values = { 10,12,6,8,3,11 };
    A = createTree(values);
    values = { 10,12,6,8 };
    B = createTree(values);
    check.checkBool(true, o.isSubStructure(A, B));

    values = { 4,2,3,4,5,6,7,8,9 };
    A = createTree(values);
    values = { 4,8,9 };
    B = createTree(values);
    check.checkBool(true, o.isSubStructure(A, B));
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
