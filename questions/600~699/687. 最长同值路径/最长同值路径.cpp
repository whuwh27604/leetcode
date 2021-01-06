/* 最长同值路径.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。

注意：两个节点之间的路径长度由它们之间的边数表示。

示例 1:

输入:

              5
             / \
            4   5
           / \   \
          1   1   5
输出:

2
示例 2:

输入:

              1
             / \
            4   5
           / \   \
          4   4   5
输出:

2
注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-univalue-path
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int leftLongest = 0;

        if (root != NULL) {
            (void)oneWayLongestPath(root, leftLongest);
        }

        return leftLongest;
    }

    int oneWayLongestPath(TreeNode* root, int& totalLongest) {
        int leftLen = 0, rightLen = 0;  // 子节点为空，或者子节点和root值不一样，都会导致路径长度为0
        if (root->left != NULL) {
            leftLen = oneWayLongestPath(root->left, totalLongest);
            if (root->left->val == root->val) {
                leftLen++;
            }
            else {
                leftLen = 0;
            }
        }

        if (root->right != NULL) {
            rightLen = oneWayLongestPath(root->right, totalLongest);
            if (root->right->val == root->val) {
                rightLen++;
            }
            else {
                rightLen = 0;
            }
        }

        totalLongest = max(totalLongest, leftLen + rightLen);  // leftLen、rightLen要么有一个为0，要么就是两边连起来的情况
        return max(leftLen, rightLen);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 5,4,5,1,1,INT_MIN,5 };
    check.checkInt(2, o.longestUnivaluePath(createTree(values)));

    values = { 1,4,5,4,4,INT_MIN,5 };
    check.checkInt(2, o.longestUnivaluePath(createTree(values)));

    values = { 1,1,1,2,INT_MIN,INT_MIN,2,3,INT_MIN,INT_MIN,4,3,INT_MIN,INT_MIN,4,3,INT_MIN,INT_MIN,4,INT_MIN,INT_MIN,INT_MIN,4 };
    check.checkInt(3, o.longestUnivaluePath(createTree(values)));

    values = { 1 };
    check.checkInt(0, o.longestUnivaluePath(createTree(values)));

    values = {  };
    check.checkInt(0, o.longestUnivaluePath(createTree(values)));
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
