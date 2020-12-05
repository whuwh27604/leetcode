/* 删除给定值的叶子节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵以 root 为根的二叉树和一个整数 target ，请你删除所有值为 target 的 叶子节点 。

注意，一旦删除值为 target 的叶子节点，它的父节点就可能变成叶子节点；如果新叶子节点的值恰好也是 target ，那么这个节点也应该被删除。

也就是说，你需要重复此过程直到不能继续删除。

 

示例 1：



输入：root = [1,2,3,2,null,2,4], target = 2
输出：[1,null,3,null,4]
解释：
上面左边的图中，绿色节点为叶子节点，且它们的值与 target 相同（同为 2 ），它们会被删除，得到中间的图。
有一个新的节点变成了叶子节点且它的值与 target 相同，所以将再次进行删除，从而得到最右边的图。
示例 2：



输入：root = [1,3,3,3,2], target = 3
输出：[1,3,null,null,2]
示例 3：



输入：root = [1,2,null,2,null,2], target = 2
输出：[1]
解释：每一步都删除一个绿色的叶子节点（值为 2）。
示例 4：

输入：root = [1,1,1], target = 1
输出：[]
示例 5：

输入：root = [1,2,3], target = 1
输出：[1,2,3]
 

提示：

1 <= target <= 1000
每一棵树最多有 3000 个节点。
每一个节点值的范围是 [1, 1000] 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-leaves-with-a-given-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return DFS(root, target) ? NULL : root;
    }

    bool DFS(TreeNode* root, int target) {
        if (root == NULL) {
            return true;
        }

        if (DFS(root->left, target)) {
            root->left = NULL;
        }

        if (DFS(root->right, target)) {
            root->right = NULL;
        }

        return root->left == NULL && root->right == NULL && root->val == target;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,2,3,2,INT_MIN,2,4 };
    TreeNode* actual = o.removeLeafNodes(createTree(values), 2);
    values = { 1,INT_MIN,3,INT_MIN,4 };
    check.checkTree(createTree(values), actual);

    values = { 1,3,3,3,2 };
    actual = o.removeLeafNodes(createTree(values), 3);
    values = { 1,3,INT_MIN,INT_MIN,2 };
    check.checkTree(createTree(values), actual);

    values = { 1,2,INT_MIN,2,INT_MIN,2 };
    actual = o.removeLeafNodes(createTree(values), 2);
    values = { 1 };
    check.checkTree(createTree(values), actual);

    values = { 1,1,1 };
    actual = o.removeLeafNodes(createTree(values), 1);
    values = {  };
    check.checkTree(createTree(values), actual);

    values = { 1 };
    actual = o.removeLeafNodes(createTree(values), 1);
    values = {  };
    check.checkTree(createTree(values), actual);

    values = { 1 };
    actual = o.removeLeafNodes(createTree(values), 2);
    values = { 1 };
    check.checkTree(createTree(values), actual);

    values = { 1,2,3 };
    actual = o.removeLeafNodes(createTree(values), 1);
    values = { 1,2,3 };
    check.checkTree(createTree(values), actual);
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
