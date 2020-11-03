/* 最大层内元素和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二叉树的根节点 root。设根节点位于二叉树的第 1 层，而根节点的子节点位于第 2 层，依此类推。

请你找出层内元素之和 最大 的那几层（可能只有一层）的层号，并返回其中 最小 的那个。

 

示例 1：



输入：root = [1,7,0,7,-8,null,null]
输出：2
解释：
第 1 层各元素之和为 1，
第 2 层各元素之和为 7 + 0 = 7，
第 3 层各元素之和为 7 + -8 = -1，
所以我们返回第 2 层的层号，它的层内元素之和最大。
示例 2：

输入：root = [989,null,10250,98693,-89388,null,null,null,-32127]
输出：2
 

提示：

树中的节点数介于 1 和 10^4 之间
-10^5 <= node.val <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-level-sum-of-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        int maxSum = INT_MIN, layer = 0, maxSumLayer = 0;

        while (!bfs.empty()) {
            int i, size = bfs.size(), sum = 0;
            ++layer;

            for (i = 0; i < size; ++i) {
                TreeNode* node = bfs.front();
                bfs.pop();

                sum += node->val;

                if (node->left != NULL) {
                    bfs.push(node->left);
                }
                if (node->right != NULL) {
                    bfs.push(node->right);
                }
            }

            if (sum > maxSum) {
                maxSum = sum;
                maxSumLayer = layer;
            }
        }

        return maxSumLayer;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1 };
    check.checkInt(1, o.maxLevelSum(createTree(values)));

    values = { 1,2 };
    check.checkInt(2, o.maxLevelSum(createTree(values)));

    values = { 1,7,0,7,-8 };
    check.checkInt(2, o.maxLevelSum(createTree(values)));

    values = { 989,INT_MIN,10250,98693,-89388,INT_MIN,INT_MIN,INT_MIN,-32127 };
    check.checkInt(2, o.maxLevelSum(createTree(values)));

    values = { -1,-1,-1,-1,-1 };
    check.checkInt(1, o.maxLevelSum(createTree(values)));
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
