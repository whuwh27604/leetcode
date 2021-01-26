/* 二叉搜索树的范围和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定二叉搜索树的根结点 root，返回 L 和 R（含）之间的所有结点的值的和。

二叉搜索树保证具有唯一的值。

 

示例 1：

输入：root = [10,5,15,3,7,null,18], L = 7, R = 15
输出：32
示例 2：

输入：root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
输出：23
 

提示：

树中的结点数量最多为 10000 个。
最终的答案保证小于 2^31。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/range-sum-of-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        if (root != NULL) {
            LDR(root, L, R, sum);
        }

        return sum;
    }

    void LDR(TreeNode* root, int L, int R, int& sum) {
        if (root->left != NULL) {
            LDR(root->left, L, R, sum);
        }

        if ((root->val >= L) && (root->val <= R)) {
            sum += root->val;
        }

        if (root->right != NULL) {
            LDR(root->right, L, R, sum);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 10,5,15,3,7,INT_MIN,18 };
    check.checkInt(32, o.rangeSumBST(createTree(values), 7, 15));
    check.checkInt(17, o.rangeSumBST(createTree(values), 6, 11));

    values = { 10,5,15,3,7,13,18,1,INT_MIN,6 };
    check.checkInt(23, o.rangeSumBST(createTree(values), 6, 10));
    check.checkInt(78, o.rangeSumBST(createTree(values), 0, 20));

    values = {  };
    check.checkInt(0, o.rangeSumBST(createTree(values), 7, 15));

    values = { 18 };
    check.checkInt(18, o.rangeSumBST(createTree(values), 7, 19));
    check.checkInt(18, o.rangeSumBST(createTree(values), 18, 18));
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
