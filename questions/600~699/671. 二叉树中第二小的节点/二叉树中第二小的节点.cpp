/* 二叉树中第二小的节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么这个节点的值不大于它的子节点的值。 

给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。

示例 1:

输入:
    2
   / \
  2   5
     / \
    5   7

输出: 5
说明: 最小的值是 2 ，第二小的值是 5 。
示例 2:

输入:
    2
   / \
  2   2

输出: -1
说明: 最小的值是 2, 但是不存在第二小的值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <list>
#include <algorithm>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int firstMin = root->val, secondMin = INT_MAX;
        bool find = false;
        list<TreeNode*> allNodes;
        allNodes.push_back(root);

        while (!allNodes.empty()) {
            int i, len = allNodes.size();
            for (i = 0; i < len; i++) {
                TreeNode* node = allNodes.front();
                allNodes.pop_front();

                if (node->val != firstMin) {
                    secondMin = min(secondMin, node->val);
                    find = true;
                }

                if (node->left != NULL) {
                    allNodes.push_back(node->left);
                    allNodes.push_back(node->right);
                }
            }
        }

        if (find) {
            return secondMin;
        }
        return -1;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 2,2,5,INT_MIN,INT_MIN,5,7 };
    check.checkInt(5, o.findSecondMinimumValue(createTree(values)));

    values = { 2,2,2 };
    check.checkInt(-1, o.findSecondMinimumValue(createTree(values)));

    values = { 2 };
    check.checkInt(-1, o.findSecondMinimumValue(createTree(values)));

    values = { 1,1,3,1,1,3,4,3,1,1,1,3,8,4,8,3,3,1,6,2,1 };
    check.checkInt(2, o.findSecondMinimumValue(createTree(values)));
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
