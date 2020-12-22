/* 二叉树的锯齿形层次遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzagValues;
        if (root == NULL) {
            return zigzagValues;
        }

        int i = 0, j, direction = 0;
        queue<TreeNode*> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            int size = bfs.size();
            zigzagValues.push_back(vector<int>(size, 0));

            for (j = 0; j < size; ++j) {
                TreeNode* node = bfs.front();
                bfs.pop();
                zigzagValues[i][j] = node->val;

                if (node->left != NULL) {
                    bfs.push(node->left);
                }
                if (node->right != NULL) {
                    bfs.push(node->right);
                }
            }

            if (direction == 1) {
                reverse(zigzagValues[i].begin(), zigzagValues[i].end());
            }

            ++i;
            direction ^= 1;
        }

        return zigzagValues;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 3,9,20,INT_MIN,INT_MIN,15,7 };
    vector<vector<int>> actual = o.zigzagLevelOrder(createTree(values));
    vector<vector<int>> expected = { {3},{20,9},{15,7} };
    check.checkIntVectorVector(expected, actual);

    actual = o.zigzagLevelOrder(NULL);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    values = { 3 };
    actual = o.zigzagLevelOrder(createTree(values));
    expected = { {3} };
    check.checkIntVectorVector(expected, actual);

    values = { 3,9,20 };
    actual = o.zigzagLevelOrder(createTree(values));
    expected = { {3},{20,9} };
    check.checkIntVectorVector(expected, actual);

    values = { 3,9,INT_MIN,20,INT_MIN,15 };
    actual = o.zigzagLevelOrder(createTree(values));
    expected = { {3},{9},{20},{15} };
    check.checkIntVectorVector(expected, actual);

    values = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    actual = o.zigzagLevelOrder(createTree(values));
    expected = { {1},{3,2},{4,5,6,7},{15,14,13,12,11,10,9,8} };
    check.checkIntVectorVector(expected, actual);
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
