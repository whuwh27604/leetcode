/* 最大二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：

二叉树的根是数组中的最大元素。
左子树是通过数组中最大值左边部分构造出的最大二叉树。
右子树是通过数组中最大值右边部分构造出的最大二叉树。
通过给定的数组构建最大二叉树，并且输出这个树的根节点。

 

示例 ：

输入：[3,2,1,6,0,5]
输出：返回下面这棵树的根节点：

      6
    /   \
   3     5
    \    /
     2  0
       \
        1
 

提示：

给定的数组的大小在 [1, 1000] 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }

    TreeNode* buildTree(vector<int>& nums, int from, int to) {
        int maximum = INT_MIN, maxIndex = from;

        for (int i = from; i <= to; i++) {
            if (nums[i] > maximum) {
                maximum = nums[i];
                maxIndex = i;
            }
        }

        TreeNode* root = new TreeNode(maximum);
        root->left = (maxIndex == from) ? NULL : buildTree(nums, from, maxIndex - 1);
        root->right = (maxIndex == to) ? NULL : buildTree(nums, maxIndex + 1, to);

        return root;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { 3,2,1,6,0,5 };
    TreeNode* actual = o.constructMaximumBinaryTree(nums);
    check.checkInt(6, actual->val);
    check.checkInt(3, actual->left->val);
    check.checkInt(5, actual->right->val);
    check.checkInt(2, actual->left->right->val);
    check.checkInt(1, actual->left->right->right->val);
    check.checkInt(0, actual->right->left->val);

    nums = { 5 };
    actual = o.constructMaximumBinaryTree(nums);
    check.checkInt(5, actual->val);

    nums = { 5,3 };
    actual = o.constructMaximumBinaryTree(nums);
    check.checkInt(5, actual->val);
    check.checkInt(3, actual->right->val);
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
