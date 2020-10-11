/* 二叉搜索树节点最小距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉搜索树的根节点 root，返回树中任意两节点的差的最小值。

 

示例：

输入: root = [4,2,6,1,3,null,null]
输出: 1
解释:
注意，root是树节点对象(TreeNode object)，而不是数组。

给定的树 [4,2,6,1,3,null,null] 可表示为下图:

          4
        /   \
      2      6
     / \
    1   3

最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
 

注意：

二叉树的大小范围在 2 到 100。
二叉树总是有效的，每个节点的值都是整数，且不重复。
本题与 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/ 相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int prev = -1, minDiff = INT_MAX;
        DFS(root, prev, minDiff);

        return minDiff;
    }

    void DFS(TreeNode* root, int& prev, int& minDiff) {
        if (root->left != NULL) {
            DFS(root->left, prev, minDiff);
        }

        if (prev != -1) {
            minDiff = min(minDiff, root->val - prev);
        }
        prev = root->val;

        if (root->right != NULL) {
            DFS(root->right, prev, minDiff);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,INT_MIN,3,2 };
    check.checkInt(1, o.minDiffInBST(createTree(values)));

    values = { 3,INT_MIN,9 };
    check.checkInt(6, o.minDiffInBST(createTree(values)));

    values = { 9,3 };
    check.checkInt(6, o.minDiffInBST(createTree(values)));

    values = { 400,270,520,100,340,450,530,1,190,INT_MIN,INT_MIN,INT_MIN,490 };
    check.checkInt(10, o.minDiffInBST(createTree(values)));

    values = { 4,2,6,1,3 };
    check.checkInt(1, o.minDiffInBST(createTree(values)));
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
