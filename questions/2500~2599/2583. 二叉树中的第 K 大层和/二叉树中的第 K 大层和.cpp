/* 二叉树中的第 K 大层和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵二叉树的根节点 root 和一个正整数 k 。

树中的 层和 是指 同一层 上节点值的总和。

返回树中第 k 大的层和（不一定不同）。如果树少于 k 层，则返回 -1 。

注意，如果两个节点与根节点的距离相同，则认为它们在同一层。



示例 1：



输入：root = [5,8,9,2,1,3,7,4,6], k = 2
输出：13
解释：树中每一层的层和分别是：
- Level 1: 5
- Level 2: 8 + 9 = 17
- Level 3: 2 + 1 + 3 + 7 = 13
- Level 4: 4 + 6 = 10
第 2 大的层和等于 13 。
示例 2：



输入：root = [1,2,null,3], k = 1
输出：3
解释：最大的层和是 3 。


提示：

树中的节点数为 n
2 <= n <= 105
1 <= Node.val <= 106
1 <= k <= n
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"
#include "../header/TreeNode.h"

using namespace std;

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> sums;
        queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            int size = nodes.size();
            long long sum = 0;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = nodes.front();
                nodes.pop();
                sum += node->val;

                if (node->left != NULL) {
                    nodes.push(node->left);
                }
                if (node->right != NULL) {
                    nodes.push(node->right);
                }
            }

            sums.push(sum);
            if ((int)sums.size() > k) {
                sums.pop();
            }
        }

        return sums.size() == k ? sums.top() : -1;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 5,8,9,2,1,3,7,4,6 };
    check.checkLongLong(13, o.kthLargestLevelSum(createTree(values), 2));

    values = { 1,2,INT_MIN,3 };
    check.checkLongLong(3, o.kthLargestLevelSum(createTree(values), 1));
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
