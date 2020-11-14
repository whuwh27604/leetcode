/* 二叉树着色游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有两位极客玩家参与了一场「二叉树着色」的游戏。游戏中，给出二叉树的根节点 root，树上总共有 n 个节点，且 n 为奇数，其中每个节点上的值从 1 到 n 各不相同。

 

游戏从「一号」玩家开始（「一号」玩家为红色，「二号」玩家为蓝色），最开始时，

「一号」玩家从 [1, n] 中取一个值 x（1 <= x <= n）；

「二号」玩家也从 [1, n] 中取一个值 y（1 <= y <= n）且 y != x。

「一号」玩家给值为 x 的节点染上红色，而「二号」玩家给值为 y 的节点染上蓝色。

 

之后两位玩家轮流进行操作，每一回合，玩家选择一个他之前涂好颜色的节点，将所选节点一个 未着色 的邻节点（即左右子节点、或父节点）进行染色。

如果当前玩家无法找到这样的节点来染色时，他的回合就会被跳过。

若两个玩家都没有可以染色的节点时，游戏结束。着色节点最多的那位玩家获得胜利 ✌️。

 

现在，假设你是「二号」玩家，根据所给出的输入，假如存在一个 y 值可以确保你赢得这场游戏，则返回 true；若无法获胜，就请返回 false。

 

示例：



输入：root = [1,2,3,4,5,6,7,8,9,10,11], n = 11, x = 3
输出：True
解释：第二个玩家可以选择值为 2 的节点。
 

提示：

二叉树的根节点为 root，树上由 n 个节点，节点上的值从 1 到 n 各不相同。
n 为奇数。
1 <= x <= n <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-coloring-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        // 很明显的贪心策略，2号玩家应该紧挨着x选择y
        TreeNode* nodeX = findX(root, x);
        int leftChildren = countChildren(nodeX->left);
        int rightChildren = countChildren(nodeX->right);

        n /= 2;
        return (leftChildren > n) || (rightChildren > n) || (leftChildren + rightChildren + 1 <= n);
    }

    TreeNode* findX(TreeNode* root, int x) {
        if (root == NULL) {
            return NULL;
        }

        if (root->val == x) {
            return root;
        }

        TreeNode* nodeX = findX(root->left, x);
        if (nodeX != NULL) {
            return nodeX;
        }

        return findX(root->right, x);
    }

    int countChildren(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int count = 1;
        count += countChildren(root->left);
        count += countChildren(root->right);

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,2,3,4,5,6,7,8,9,10,11 };
    check.checkBool(true, o.btreeGameWinningMove(createTree(values), 11, 3));
    check.checkBool(true, o.btreeGameWinningMove(createTree(values), 11, 1));
    check.checkBool(false, o.btreeGameWinningMove(createTree(values), 11, 2));

    values = { 1 };
    check.checkBool(false, o.btreeGameWinningMove(createTree(values), 1, 1));
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
