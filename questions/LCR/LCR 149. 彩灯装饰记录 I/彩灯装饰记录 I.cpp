/* 彩灯装饰记录 I.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一棵圣诞树记作根节点为 root 的二叉树，节点值为该位置装饰彩灯的颜色编号。请按照从 左 到 右 的顺序返回每一层彩灯编号。



示例 1：



输入：root = [8,17,21,18,null,null,6]
输出：[8,17,21,18,6]


提示：

节点总数 <= 1000
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> decorateRecord(TreeNode* root) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        vector<int> ans;

        while (!nodes.empty()) {
            TreeNode* node = nodes.front();
            nodes.pop();

            if (node != NULL) {
                ans.push_back(node->val);
                nodes.push(node->left);
                nodes.push(node->right);
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 8,17,21,18,INT_MIN,INT_MIN,6 };
    vector<int> actual = o.decorateRecord(createTree(values));
    vector<int> expected = { 8,17,21,18,6 };
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
