/* 在每个树行中找最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
您需要在二叉树的每一行中找到最大的值。

示例：

输入:

          1
         / \
        3   2
       / \   \
      5   3   9

输出: [1, 3, 9]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == NULL) {
            return {};
        }

        vector<int> largestVals;
        queue<TreeNode*> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            int size = bfs.size();
            int maximum = INT_MIN;

            for (int i = 0; i < size; i++) {
                TreeNode* node = bfs.front();
                maximum = max(maximum, node->val);
                bfs.pop();

                if (node->left != NULL) {
                    bfs.push(node->left);
                }
                if (node->right != NULL) {
                    bfs.push(node->right);
                }
            }

            largestVals.push_back(maximum);
        }

        return largestVals;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> actual = o.largestValues(NULL);
    vector<int> expected = {};
    check.checkIntVector(expected, actual);

    vector<int> values = { 1 };
    actual = o.largestValues(createTree(values));
    expected = { 1 };
    check.checkIntVector(expected, actual);

    values = { 1,2 };
    actual = o.largestValues(createTree(values));
    expected = { 1,2 };
    check.checkIntVector(expected, actual);

    values = { 1,2,3 };
    actual = o.largestValues(createTree(values));
    expected = { 1,3 };
    check.checkIntVector(expected, actual);

    values = { 1,3,2,5,3,INT_MIN,9 };
    actual = o.largestValues(createTree(values));
    expected = { 1,3,9 };
    check.checkIntVector(expected, actual);
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
