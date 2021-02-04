/* 从根到叶的二进制数之和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。

对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。

以 10^9 + 7 为模，返回这些数字之和。

 

示例：



输入：[1,0,1,0,1,0,1]
输出：22
解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 

提示：

树中的结点数介于 1 和 1000 之间。
node.val 为 0 或 1 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-root-to-leaf-binary-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        DLR(root, 0, sum);

        return sum;
    }

    void DLR(TreeNode* root, int num, int& sum) {
        num = (num * 2 + root->val) % 1000000007;
        if ((root->left == NULL) && (root->right == NULL)) {
            sum = (sum + num) % 1000000007;
        }

        if (root->left != NULL) {
            DLR(root->left, num, sum);
        }

        if (root->right != NULL) {
            DLR(root->right, num, sum);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 1,1,INT_MIN,1,0 };
    check.checkInt(13, o.sumRootToLeaf(createTree(values)));

    values = { 1,0,1,0,1,0,1 };
    check.checkInt(22, o.sumRootToLeaf(createTree(values)));

    values = { 0 };
    check.checkInt(0, o.sumRootToLeaf(createTree(values)));

    values = { 1 };
    check.checkInt(1, o.sumRootToLeaf(createTree(values)));

    values = { 1,1,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,
        INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,
        1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,
        1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1,1,INT_MIN,INT_MIN,1 };
    check.checkInt(73741815, o.sumRootToLeaf(createTree(values)));  // 0b11111111111111111111111111111 + 0b11111111111111111111111111111
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
