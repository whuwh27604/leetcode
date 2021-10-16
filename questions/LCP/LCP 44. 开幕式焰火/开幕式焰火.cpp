/* 开幕式焰火.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
「力扣挑战赛」开幕式开始了，空中绽放了一颗二叉树形的巨型焰火。
给定一棵二叉树 root 代表焰火，节点值表示巨型焰火这一位置的颜色种类。请帮小扣计算巨型焰火有多少种不同的颜色。

示例 1：

输入：root = [1,3,2,1,null,2]

输出：3

解释：焰火中有 3 个不同的颜色，值分别为 1、2、3

示例 2：

输入：root = [3,3,3]

输出：1

解释：焰火中仅出现 1 个颜色，值为 3

提示：

1 <= 节点个数 <= 1000
1 <= Node.val <= 1000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sZ59z6
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numColor(TreeNode* root) {
        int count = 0;
        vector<bool> colors(1001, false);

        DFS(root, colors);

        for (bool color : colors) {
            if (color) {
                ++count;
            }
        }

        return count;
    }

    void DFS(TreeNode* root, vector<bool>& colors) {
        if (root == NULL) {
            return;
        }

        colors[root->val] = true;
        DFS(root->left, colors);
        DFS(root->right, colors);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,3,2,1,INT_MIN,2 };
    check.checkInt(3, o.numColor(createTree(values)));

    values = { 3,3,3 };
    check.checkInt(1, o.numColor(createTree(values)));
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
