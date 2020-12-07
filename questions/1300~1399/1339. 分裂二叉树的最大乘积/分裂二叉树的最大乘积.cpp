/* 分裂二叉树的最大乘积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵二叉树，它的根为 root 。请你删除 1 条边，使二叉树分裂成两棵子树，且它们子树和的乘积尽可能大。

由于答案可能会很大，请你将结果对 10^9 + 7 取模后再返回。

 

示例 1：



输入：root = [1,2,3,4,5,6]
输出：110
解释：删除红色的边，得到 2 棵子树，和分别为 11 和 10 。它们的乘积是 110 （11*10）
示例 2：



输入：root = [1,null,2,3,4,null,null,5,6]
输出：90
解释：移除红色的边，得到 2 棵子树，和分别是 15 和 6 。它们的乘积为 90 （15*6）
示例 3：

输入：root = [2,3,9,10,7,8,6,5,4,11,1]
输出：1025
示例 4：

输入：root = [1,1]
输出：1
 

提示：

每棵树最多有 50000 个节点，且至少有 2 个节点。
每个节点的值在 [1, 10000] 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-product-of-splitted-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxProduct(TreeNode* root) {
        unordered_set<int> allSums;
        int sum = DFS4Sum(root, allSums);

        long long maximumProduct = 0;

        for (auto iter = allSums.begin(); iter != allSums.end(); ++iter) {
            long long product = (long long)(*iter) * ((long long)sum - *iter);
            maximumProduct = max(maximumProduct, product);
        }

        return (int)(maximumProduct % 1000000007);
    }

    int DFS4Sum(TreeNode* root, unordered_set<int>& allSums) {
        if (root == NULL) {
            return 0;
        }

        int sum = root->val;
        sum += DFS4Sum(root->left, allSums);
        sum += DFS4Sum(root->right, allSums);
        allSums.insert(sum);

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,2,3,4,5,6 };
    check.checkInt(110, o.maxProduct(createTree(values)));
    
    values = { 3,4 };
    check.checkInt(12, o.maxProduct(createTree(values)));

    values = { 1,INT_MIN,2,3,4,INT_MIN,INT_MIN,5,6 };
    check.checkInt(90, o.maxProduct(createTree(values)));

    values = { 2,3,9,10,7,8,6,5,4,11,1 };
    check.checkInt(1025, o.maxProduct(createTree(values)));

    values = { 1,1 };
    check.checkInt(1, o.maxProduct(createTree(values)));
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
