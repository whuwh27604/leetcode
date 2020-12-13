/* 找出克隆二叉树中的相同节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两棵二叉树，原始树 original 和克隆树 cloned，以及一个位于原始树 original 中的目标节点 target。

其中，克隆树 cloned 是原始树 original 的一个 副本 。

请找出在树 cloned 中，与 target 相同 的节点，并返回对该节点的引用（在 C/C++ 等有指针的语言中返回 节点指针，其他语言返回节点本身）。

 

注意：

你 不能 对两棵二叉树，以及 target 节点进行更改。
只能 返回对克隆树 cloned 中已有的节点的引用。
进阶：如果树中允许出现值相同的节点，你将如何解答？

 

示例 1:



输入: tree = [7,4,3,null,null,6,19], target = 3
输出: 3
解释: 上图画出了树 original 和 cloned。target 节点在树 original 中，用绿色标记。答案是树 cloned 中的黄颜色的节点（其他示例类似）。
示例 2:



输入: tree = [7], target =  7
输出: 7
示例 3:



输入: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
输出: 4
示例 4:



输入: tree = [1,2,3,4,5,6,7,8,9,10], target = 5
输出: 5
示例 5:



输入: tree = [1,2,null,3], target = 2
输出: 2
 

提示：

树中节点的数量范围为 [1, 10^4] 。
同一棵树中，没有值相同的节点。
target 节点是树 original 中的一个节点，并且不会是 null 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == target) {
            return cloned;
        }

        if (original == NULL) {
            return NULL;
        }

        TreeNode* clonedTarget = getTargetCopy(original->left, cloned->left, target);
        if (clonedTarget != NULL) {
            return clonedTarget;
        }

        return getTargetCopy(original->right, cloned->right, target);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 7,4,3,INT_MIN,INT_MIN,6,19 };
    TreeNode* original = createTree(values);
    TreeNode* cloned = createTree(values);
    check.checkPoint(cloned->right, o.getTargetCopy(original, cloned, original->right));

    values = { 7 };
    original = createTree(values);
    cloned = createTree(values);
    check.checkPoint(cloned, o.getTargetCopy(original, cloned, original));

    values = { 8,INT_MIN,6,INT_MIN,5,INT_MIN,4,INT_MIN,3,INT_MIN,2,INT_MIN,1 };
    original = createTree(values);
    cloned = createTree(values);
    check.checkPoint(cloned->right->right->right, o.getTargetCopy(original, cloned, original->right->right->right));

    values = { 1,2,3,4,5,6,7,8,9,10 };
    original = createTree(values);
    cloned = createTree(values);
    check.checkPoint(cloned->left->right, o.getTargetCopy(original, cloned, original->left->right));

    values = { 1,2,INT_MIN,3 };
    original = createTree(values);
    cloned = createTree(values);
    check.checkPoint(cloned->left, o.getTargetCopy(original, cloned, original->left));
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
