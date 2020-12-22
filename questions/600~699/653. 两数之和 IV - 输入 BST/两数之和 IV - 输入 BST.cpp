/* 两数之和 IV - 输入 BST.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

案例 1:

输入:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

输出: True
 

案例 2:

输入:
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

输出: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> values;
        LDR(root, values);

        int left = 0, right = values.size() - 1;

        while (left < right) {
            if (values[left] + values[right] == k) {
                return true;
            }
            else if (values[left] + values[right] > k) {
                --right;
            }
            else {
                ++left;
            }
        }

        return false;
    }

    void LDR(TreeNode* root, vector<int>& values) {
        if (root != NULL) {
            LDR(root->left, values);
            values.push_back(root->val);
            LDR(root->right, values);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 5,3,6,2,4,INT_MIN,7 };
    check.checkBool(true, o.findTarget(createTree(values), 9));
    check.checkBool(false, o.findTarget(createTree(values), 28));

    values = { 7 };
    check.checkBool(false, o.findTarget(createTree(values), 0));
    check.checkBool(false, o.findTarget(createTree(values), 7));
    check.checkBool(false, o.findTarget(createTree(values), 9));

    check.checkBool(false, o.findTarget(NULL, 9));

    values = { 0,-1,2,-3,INT_MIN,INT_MIN,4 };
    check.checkBool(true, o.findTarget(createTree(values), -4));

    values = { 1 };
    check.checkBool(false, o.findTarget(createTree(values), 2));
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
