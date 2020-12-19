/* 二叉树的坡度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，计算整个树的坡度。

一个树的节点的坡度定义即为，该节点左子树的结点之和和右子树结点之和的差的绝对值。空结点的的坡度是0。

整个树的坡度就是其所有节点的坡度之和。

示例:

输入:
         1
       /   \
      2     3
输出: 1
解释:
结点的坡度 2 : 0
结点的坡度 3 : 0
结点的坡度 1 : |2-3| = 1
树的坡度 : 0 + 0 + 1 = 1
注意:

任何子树的结点的和不会超过32位整数的范围。
坡度的值不会超过32位整数的范围。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-tilt
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findTilt(TreeNode* root) {
        int tiltSum = 0;

        if (root != NULL) {
            (void)sumTree(root, tiltSum);
        }

        return tiltSum;
    }

    int sumTree(TreeNode* root, int& tiltSum) {
        int leftSum = 0, rightSum = 0;

        if (root->left != NULL) {
            leftSum = sumTree(root->left, tiltSum);
        }

        if (root->right != NULL) {
            rightSum = sumTree(root->right, tiltSum);
        }

        tiltSum += abs(leftSum - rightSum);

        return leftSum + root->val + rightSum;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 6,4,9,2,5,7,10,1,3,INT_MIN,INT_MIN,INT_MIN,8 };
    check.checkInt(35, o.findTilt(createTree(values)));

    values = { 1,2,3 };
    check.checkInt(1, o.findTilt(createTree(values)));

    values = { 2 };
    check.checkInt(0, o.findTilt(createTree(values)));

    check.checkInt(0, o.findTilt(NULL));
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
