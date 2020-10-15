/* 在二叉树中分配硬币.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个有 N 个结点的二叉树的根结点 root，树中的每个结点上都对应有 node.val 枚硬币，并且总共有 N 枚硬币。

在一次移动中，我们可以选择两个相邻的结点，然后将一枚硬币从其中一个结点移动到另一个结点。(移动可以是从父结点到子结点，或者从子结点移动到父结点。)。

返回使每个结点上只有一枚硬币所需的移动次数。

 

示例 1：



输入：[3,0,0]
输出：2
解释：从树的根结点开始，我们将一枚硬币移到它的左子结点上，一枚硬币移到它的右子结点上。
示例 2：



输入：[0,3,0]
输出：3
解释：从根结点的左子结点开始，我们将两枚硬币移到根结点上 [移动两次]。然后，我们把一枚硬币从根结点移到右子结点上。
示例 3：



输入：[1,0,2]
输出：2
示例 4：



输入：[1,0,0,null,3]
输出：4
 

提示：

1<= N <= 100
0 <= node.val <= N

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/distribute-coins-in-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int nodes, coins, moves = 0;
        LRD(root, nodes, coins, moves);

        return moves;
    }

    void LRD(TreeNode* root, int& nodes, int& coins, int& moves) {
        int leftNodes = 0, leftCoins = 0, rightNodes = 0, rightCoins = 0;

        if (root->left != NULL) {
            LRD(root->left, leftNodes, leftCoins, moves);
        }

        if (root->right != NULL) {
            LRD(root->right, rightNodes, rightCoins, moves);
        }

        moves += abs(leftNodes - leftCoins);
        moves += abs(rightNodes - rightCoins);
        nodes = leftNodes + rightNodes + 1;
        coins = leftCoins + rightCoins + root->val;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 3,0,0 };
    check.checkInt(2, o.distributeCoins(createTree(values)));

    values = { 0,3,0 };
    check.checkInt(3, o.distributeCoins(createTree(values)));

    values = { 1,0,2 };
    check.checkInt(2, o.distributeCoins(createTree(values)));

    values = { 1,0,0,INT_MIN,3 };
    check.checkInt(4, o.distributeCoins(createTree(values)));
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
