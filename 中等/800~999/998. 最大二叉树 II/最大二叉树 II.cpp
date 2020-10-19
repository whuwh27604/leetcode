/* 最大二叉树 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
最大树定义：一个树，其中每个节点的值都大于其子树中的任何其他值。

给出最大树的根节点 root。

就像之前的问题那样，给定的树是从表 A（root = Construct(A)）递归地使用下述 Construct(A) 例程构造的：

如果 A 为空，返回 null
否则，令 A[i] 作为 A 的最大元素。创建一个值为 A[i] 的根节点 root
root 的左子树将被构建为 Construct([A[0], A[1], ..., A[i-1]])
root 的右子树将被构建为 Construct([A[i+1], A[i+2], ..., A[A.length - 1]])
返回 root
请注意，我们没有直接给定 A，只有一个根节点 root = Construct(A).

假设 B 是 A 的副本，并附加值 val。保证 B 中的值是不同的。

返回 Construct(B)。

 

示例 1：



输入：root = [4,1,3,null,null,2], val = 5
输出：[5,4,null,1,3,null,null,2]
解释：A = [1,4,2,3], B = [1,4,2,3,5]
示例 2：


输入：root = [5,2,4,null,1], val = 3
输出：[5,2,4,null,1,null,3]
解释：A = [2,1,5,4], B = [2,1,5,4,3]
示例 3：


输入：root = [5,2,3,null,1], val = 4
输出：[5,2,4,null,1,3]
解释：A = [2,1,5,3], B = [2,1,5,3,4]
 

提示：

1 <= B.length <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-binary-tree-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* node = new TreeNode(val);
        if (root == NULL || root->val < val) {
            node->left = root;
            return node;
        }

        TreeNode* prev = root;
        while (prev->right != NULL && prev->right->val > val) {  // 只能插入到right，因为一旦插入到left，那么当前root就一定会在val右边，而事实上val已经是最右边一个数了
            prev = prev->right;
        }

        node->left = prev->right;
        prev->right = node;

        return root;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 4,1,3,INT_MIN,INT_MIN,2 };
    TreeNode* root = createTree(values);
    TreeNode* actual = o.insertIntoMaxTree(root, 5);
    check.checkInt(5, actual->val);
    check.checkPoint(root, actual->left);
    check.checkPoint(NULL, actual->right);

    values = { 5,2,4,INT_MIN,1 };
    root = createTree(values);
    actual = o.insertIntoMaxTree(root, 3);
    check.checkInt(5, actual->val);
    check.checkInt(2, actual->left->val);
    check.checkInt(4, actual->right->val);
    check.checkPoint(NULL, actual->left->left);
    check.checkInt(1, actual->left->right->val);
    check.checkPoint(NULL, actual->right->left);
    check.checkInt(3, actual->right->right->val);

    values = { 5,2,3,INT_MIN,1 };
    root = createTree(values);
    actual = o.insertIntoMaxTree(root, 4);
    check.checkInt(5, actual->val);
    check.checkInt(2, actual->left->val);
    check.checkInt(4, actual->right->val);
    check.checkPoint(NULL, actual->left->left);
    check.checkInt(1, actual->left->right->val);
    check.checkInt(3, actual->right->left->val);
    check.checkPoint(NULL, actual->right->right);
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
