/* 二叉树中的最长交错路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵以 root 为根的二叉树，二叉树中的交错路径定义如下：

选择二叉树中 任意 节点和一个方向（左或者右）。
如果前进方向为右，那么移动到当前节点的的右子节点，否则移动到它的左子节点。
改变前进方向：左变右或者右变左。
重复第二步和第三步，直到你在树中无法继续移动。
交错路径的长度定义为：访问过的节点数目 - 1（单个节点的路径长度为 0 ）。

请你返回给定树中最长 交错路径 的长度。

 

示例 1：



输入：root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
输出：3
解释：蓝色节点为树中最长交错路径（右 -> 左 -> 右）。
示例 2：



输入：root = [1,1,1,null,1,null,null,1,1,null,1]
输出：4
解释：蓝色节点为树中最长交错路径（左 -> 右 -> 左 -> 右）。
示例 3：

输入：root = [1]
输出：0
 

提示：

每棵树最多有 50000 个节点。
每个节点的值在 [1, 100] 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-zigzag-path-in-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestZigZag(TreeNode* root) {
        if (root == NULL) {
            return 0;  // 题目未定义清楚
        }

        int longestPath = 0;
        (void)DFS(root, longestPath);

        return longestPath;
    }

    pair<int, int> DFS(TreeNode* root, int& longestPath) {
        pair<int, int> leftPathLen = { -1,-1 }, rightPathLen = { -1,-1 };

        if (root->left != NULL) {
            leftPathLen = DFS(root->left, longestPath);
        }

        if (root->right != NULL) {
            rightPathLen = DFS(root->right, longestPath);
        }

        longestPath = max({ longestPath, leftPathLen.second + 1, rightPathLen.first + 1 });
        return { leftPathLen.second + 1, rightPathLen.first + 1 };
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,INT_MIN,2,3,4,INT_MIN,INT_MIN,5,6,INT_MIN,7,INT_MIN,INT_MIN,INT_MIN,8,INT_MIN,9 };
    check.checkInt(3, o.longestZigZag(createTree(values)));

    values = { 1,1,1,INT_MIN,1,INT_MIN,INT_MIN,1,1,INT_MIN,1 };
    check.checkInt(4, o.longestZigZag(createTree(values)));

    values = { 1 };
    check.checkInt(0, o.longestZigZag(createTree(values)));

    values = { 1,1,1,INT_MIN,1,INT_MIN,INT_MIN,1,1,INT_MIN,1 };
    check.checkInt(4, o.longestZigZag(createTree(values)));
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
