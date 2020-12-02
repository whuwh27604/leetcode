/* 层数最深叶子节点的和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一棵二叉树，请你返回层数最深的叶子节点的和。

 

示例：



输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
输出：15
 

提示：

树中节点数目在 1 到 10^4 之间。
每个节点的值在 1 到 100 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/deepest-leaves-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> bfs;
        bfs.push(root);
        int sum = 0;

        while (!bfs.empty()) {
            int i, size = bfs.size();
            sum = 0;

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
        }

        return sum;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,2,3,4,5,INT_MIN,6,7,INT_MIN,INT_MIN,INT_MIN,INT_MIN,8 };
    check.checkInt(15, o.deepestLeavesSum(createTree(values)));

    values = { 5 };
    check.checkInt(5, o.deepestLeavesSum(createTree(values)));

    values = { 5,10 };
    check.checkInt(10, o.deepestLeavesSum(createTree(values)));

    values = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    check.checkInt(92, o.deepestLeavesSum(createTree(values)));
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
