/* 计算布尔二叉树的值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵 完整二叉树 的根，这棵树有以下特征：

叶子节点 要么值为 0 要么值为 1 ，其中 0 表示 False ，1 表示 True 。
非叶子节点 要么值为 2 要么值为 3 ，其中 2 表示逻辑或 OR ，3 表示逻辑与 AND 。
计算 一个节点的值方式如下：

如果节点是个叶子节点，那么节点的 值 为它本身，即 True 或者 False 。
否则，计算 两个孩子的节点值，然后将该节点的运算符对两个孩子值进行 运算 。
返回根节点 root 的布尔运算值。

完整二叉树 是每个节点有 0 个或者 2 个孩子的二叉树。

叶子节点 是没有孩子的节点。

 

示例 1：



输入：root = [2,1,3,null,null,0,1]
输出：true
解释：上图展示了计算过程。
AND 与运算节点的值为 False AND True = False 。
OR 运算节点的值为 True OR False = True 。
根节点的值为 True ，所以我们返回 true 。
示例 2：

输入：root = [0]
输出：false
解释：根节点是叶子节点，且值为 false，所以我们返回 false 。
 

提示：

树中节点数目在 [1, 1000] 之间。
0 <= Node.val <= 3
每个节点的孩子数为 0 或 2 。
叶子节点的值为 0 或 1 。
非叶子节点的值为 2 或 3 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/evaluate-boolean-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        return root->left == NULL ? root->val : root->val == 2 ? evaluateTree(root->left) || evaluateTree(root->right) : evaluateTree(root->left) && evaluateTree(root->right);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 2,1,3,INT_MIN,INT_MIN,0,1 };
    check.checkBool(true, o.evaluateTree(createTree(values)));

    values = { 0 };
    check.checkBool(false, o.evaluateTree(createTree(values)));
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
