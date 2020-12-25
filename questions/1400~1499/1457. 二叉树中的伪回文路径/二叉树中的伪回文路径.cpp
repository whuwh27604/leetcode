/* 二叉树中的伪回文路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵二叉树，每个节点的值为 1 到 9 。我们称二叉树中的一条路径是 「伪回文」的，当它满足：路径经过的所有节点值的排列中，存在一个回文序列。

请你返回从根到叶子节点的所有路径中 伪回文 路径的数目。

 

示例 1：



输入：root = [2,3,1,3,1,null,1]
输出：2
解释：上图为给定的二叉树。总共有 3 条从根到叶子的路径：红色路径 [2,3,3] ，绿色路径 [2,1,1] 和路径 [2,3,1] 。
     在这些路径中，只有红色和绿色的路径是伪回文路径，因为红色路径 [2,3,3] 存在回文排列 [3,2,3] ，绿色路径 [2,1,1] 存在回文排列 [1,2,1] 。
示例 2：



输入：root = [2,1,1,1,3,null,null,null,null,null,1]
输出：1
解释：上图为给定二叉树。总共有 3 条从根到叶子的路径：绿色路径 [2,1,1] ，路径 [2,1,3,1] 和路径 [2,1] 。
     这些路径中只有绿色路径是伪回文路径，因为 [2,1,1] 存在回文排列 [1,2,1] 。
示例 3：

输入：root = [9]
输出：1
 

提示：

给定二叉树的节点数目在 1 到 10^5 之间。
节点值在 1 到 9 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/pseudo-palindromic-paths-in-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> numsCount(10, 0);
        int pseudoPalindromes = 0;

        DFS(root, numsCount, pseudoPalindromes);

        return pseudoPalindromes;
    }

    void DFS(TreeNode* root, vector<int>& numsCount, int& pseudoPalindromes) {
        if (root == NULL) {
            return;
        }

        ++numsCount[root->val];

        if (root->left == NULL && root->right == NULL) {
            int odd = 0;

            for (int i = 1; i < 10; ++i) {
                if ((numsCount[i] & 1) == 1) {
                    if (++odd > 1) {
                        break;
                    }
                }
            }

            if (odd <= 1) {
                ++pseudoPalindromes;
            }
        }

        DFS(root->left, numsCount, pseudoPalindromes);
        DFS(root->right, numsCount, pseudoPalindromes);
        --numsCount[root->val];
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 2,3,1,3,1,INT_MIN,1 };
    check.checkInt(2, o.pseudoPalindromicPaths(createTree(values)));

    values = { 2,1,1,1,3,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,1 };
    check.checkInt(1, o.pseudoPalindromicPaths(createTree(values)));

    values = { 9 };
    check.checkInt(1, o.pseudoPalindromicPaths(createTree(values)));
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
