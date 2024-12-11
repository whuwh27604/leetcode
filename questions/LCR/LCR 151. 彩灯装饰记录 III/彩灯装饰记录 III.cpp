/* 彩灯装饰记录 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一棵圣诞树记作根节点为 root 的二叉树，节点值为该位置装饰彩灯的颜色编号。请按照如下规则记录彩灯装饰结果：

第一层按照从左到右的顺序记录
除第一层外每一层的记录顺序均与上一层相反。即第一层为从左到右，第二层为从右到左。


示例 1：



输入：root = [8,17,21,18,null,null,6]
输出：[[8],[21,17],[18,6]]


提示：

节点总数 <= 1000
*/

#include <iostream>
#include <deque>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> decorateRecord(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }

        bool rev = true;
        deque<TreeNode*> nodes;
        nodes.push_back(root);

        while (!nodes.empty()) {
            int size = (int)nodes.size();
            rev = !rev;
            ans.push_back({});

            if (rev) {
                for (int i = 0; i < size; ++i) {
                    TreeNode* node = nodes.front();
                    nodes.pop_front();
                    ans.back().push_back(node->val);
                    if (node->right != NULL) {
                        nodes.push_back(node->right);
                    }
                    if (node->left != NULL) {
                        nodes.push_back(node->left);
                    }
                }
            }
            else {
                for (int i = 0; i < size; ++i) {
                    TreeNode* node = nodes.back();
                    nodes.pop_back();
                    ans.back().push_back(node->val);
                    if (node->left != NULL) {
                        nodes.push_front(node->left);
                    }
                    if (node->right != NULL) {
                        nodes.push_front(node->right);
                    }
                }
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
    vector<vector<int>> actual = o.decorateRecord(createTree(values));
    vector<vector<int>> expected = { {8},{21,17},{18,6} };
    check.checkIntVectorVector(expected, actual);

    values = {  };
    actual = o.decorateRecord(createTree(values));
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    values = { 1 };
    actual = o.decorateRecord(createTree(values));
    expected = { {1} };
    check.checkIntVectorVector(expected, actual);

    values = { 1,2,INT_MIN,3 };
    actual = o.decorateRecord(createTree(values));
    expected = { {1},{2},{3} };
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
