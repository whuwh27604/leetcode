/* 将有序数组转换为二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return NULL;
        }
        return sortedArrayToBSTByIndex(nums, 0, nums.size() - 1);
    }

    TreeNode* sortedArrayToBSTByIndex(vector<int>& nums, int left, int right) {
        int middle = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[middle]);

        if (middle > left) {
            root->left = sortedArrayToBSTByIndex(nums, left, middle - 1);
        }

        if (middle < right) {
            root->right = sortedArrayToBSTByIndex(nums, middle + 1, right);
        }

        return root;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> nums = { -10,-3,0,5,9 };
    vector<int> values = {0,-10,5,INT_MIN,-3,INT_MIN,9};
    check.checkTree(createTree(values), o.sortedArrayToBST(nums));

    nums = { -10,-3,0,5,9,21,22,23,24,25,26,27,28,29,30,31 };
    values = { 23,5,27,-3,21,25,29,-10,0,9,22,24,26,28,30,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,31 };
    check.checkTree(createTree(values), o.sortedArrayToBST(nums));

    nums = { 5 };
    values = { 5 };
    check.checkTree(createTree(values), o.sortedArrayToBST(nums));

    nums = {  };
    values = {  };
    check.checkTree(createTree(values), o.sortedArrayToBST(nums));
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
