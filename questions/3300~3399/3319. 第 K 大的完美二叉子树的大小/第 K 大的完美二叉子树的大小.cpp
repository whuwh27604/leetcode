/* 第 K 大的完美二叉子树的大小.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵 二叉树 的根节点 root 和一个整数k。

返回第 k 大的 完美二叉
子树
的大小，如果不存在则返回 -1。

完美二叉树 是指所有叶子节点都在同一层级的树，且每个父节点恰有两个子节点。

子树 是指树中的某一个节点及其所有后代形成的树。



示例 1：

输入： root = [5,3,6,5,2,5,7,1,8,null,null,6,8], k = 2

输出： 3

解释：



完美二叉子树的根节点在图中以黑色突出显示。它们的大小按降序排列为 [3, 3, 1, 1, 1, 1, 1, 1]。
第 2 大的完美二叉子树的大小是 3。

示例 2：

输入： root = [1,2,3,4,5,6,7], k = 1

输出： 7

解释：



完美二叉子树的大小按降序排列为 [7, 3, 3, 1, 1, 1, 1]。最大的完美二叉子树的大小是 7。

示例 3：

输入： root = [1,2,3,null,4], k = 3

输出： -1

解释：



完美二叉子树的大小按降序排列为 [1, 1]。完美二叉子树的数量少于 3。



提示：

树中的节点数目在 [1, 2000] 范围内。
1 <= Node.val <= 2000
1 <= k <= 1024
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> count;

        countPerfect(root, count);
        sort(count.begin(), count.end());
        int size = (int)count.size();

        return size >= k ? count[size - k] : -1;
    }

    int countPerfect(TreeNode* node, vector<int>& count) {
        if (node == NULL) {
            return 0;
        }

        int left = countPerfect(node->left, count);
        int right = countPerfect(node->right, count);

        if (left == right && left != -1) {
            int cnt = left + right + 1;
            count.push_back(cnt);

            return cnt;
        }

        return -1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 5,3,6,5,2,5,7,1,8,INT_MIN,INT_MIN,6,8 };
    check.checkInt(3, o.kthLargestPerfectSubtree(createTree(values), 2));

    values = { 1,2,3,4,5,6,7 };
    check.checkInt(7, o.kthLargestPerfectSubtree(createTree(values), 1));

    values = { 1,2,3,INT_MIN,4 };
    check.checkInt(-1, o.kthLargestPerfectSubtree(createTree(values), 3));
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
