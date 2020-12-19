/* 路径总和 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二叉树，它的每个结点都存放着一个整数值。

找出路径和等于给定数值的路径总数。

路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。

示例：

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

返回 3。和等于 8 的路径有:

1.  5 -> 3
2.  5 -> 2 -> 1
3.  -3 -> 11

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return 0;
        }

        int preSum = 0, paths = 0;
        unordered_map<int, int> exist = { {0,1} };  // 预置一个0前缀和

        DFS(root, sum, preSum, exist, paths);

        return paths;
    }

    void DFS(TreeNode* root, int target, int& preSum, unordered_map<int, int>& exist, int& paths) {
        preSum += root->val;
        paths += exist[preSum - target];
        ++exist[preSum];

        if (root->left != NULL) {
            DFS(root->left, target, preSum, exist, paths);
        }

        if (root->right != NULL) {
            DFS(root->right, target, preSum, exist, paths);
        }

        --exist[preSum];
        preSum -= root->val;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 10,5,5,-5,INT_MIN,INT_MIN,-5,10,INT_MIN,INT_MIN,5,INT_MIN,INT_MIN,INT_MIN,-5 };
    check.checkInt(6, o.pathSum(createTree(values), 10));

    values = { 10,5,-3,3,2,INT_MIN,11,3,-2,INT_MIN,1 };
    check.checkInt(0, o.pathSum(createTree(values), 0));
    check.checkInt(2, o.pathSum(createTree(values), 1));
    check.checkInt(1, o.pathSum(createTree(values), 2));
    check.checkInt(3, o.pathSum(createTree(values), 3));
    check.checkInt(0, o.pathSum(createTree(values), 4));
    check.checkInt(1, o.pathSum(createTree(values), 5));
    check.checkInt(2, o.pathSum(createTree(values), 6));
    check.checkInt(2, o.pathSum(createTree(values), 7));
    check.checkInt(3, o.pathSum(createTree(values), 8));
    check.checkInt(0, o.pathSum(createTree(values), 9));
    check.checkInt(1, o.pathSum(createTree(values), 10));

    check.checkInt(0, o.pathSum(NULL, 1));

    values = { 10 };
    check.checkInt(1, o.pathSum(createTree(values), 10));
    check.checkInt(0, o.pathSum(createTree(values), 1));

    values = { 0,0,0,0,0,0,0 };
    check.checkInt(17, o.pathSum(createTree(values), 0));

    values = { 0,1,1 };
    check.checkInt(4, o.pathSum(createTree(values), 1));

    values = { 1,INT_MIN,2,INT_MIN,3,INT_MIN,4,INT_MIN,5 };
    check.checkInt(2, o.pathSum(createTree(values), 3));
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
