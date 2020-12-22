/* 二叉树的层平均值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.

示例 1:

输入:
    3
   / \
  9  20
    /  \
   15   7
输出: [3, 14.5, 11]
解释:
第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
注意：

节点值的范围在32位有符号整数范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/average-of-levels-in-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> averages;
        queue<TreeNode*> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            int i, size = bfs.size();
            double sum = 0;

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

            averages.push_back(sum / size);
        }

        return averages;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 3,9,20,INT_MIN,INT_MIN,15,7 };
    vector<double> actual = o.averageOfLevels(createTree(values));
    vector<double> expected = { 3, 14.5, 11 };
    check.checkDoubleVector(expected, actual);

    values = { 7 };
    actual = o.averageOfLevels(createTree(values));
    expected = { 7 };
    check.checkDoubleVector(expected, actual);
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
