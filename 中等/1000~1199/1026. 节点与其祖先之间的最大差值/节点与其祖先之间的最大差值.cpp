/* 节点与其祖先之间的最大差值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定二叉树的根节点 root，找出存在于不同节点 A 和 B 之间的最大值 V，其中 V = |A.val - B.val|，且 A 是 B 的祖先。

（如果 A 的任何子节点之一为 B，或者 A 的任何子节点是 B 的祖先，那么我们认为 A 是 B 的祖先）

 

示例：



输入：[8,3,10,1,6,null,14,null,null,4,7,13]
输出：7
解释：
我们有大量的节点与其祖先的差值，其中一些如下：
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
在所有可能的差值中，最大值 7 由 |8 - 1| = 7 得出。
 

提示：

树中的节点数在 2 到 5000 之间。
每个节点的值介于 0 到 100000 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-difference-between-node-and-ancestor
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = 0;

        DFS(root, root->val, root->val, maxDiff);

        return maxDiff;
    }

    void DFS(TreeNode* root, int maxAncestor, int minAncestor, int& maxDiff) {
        int diff = max(abs(root->val - maxAncestor), abs(root->val - minAncestor));
        maxDiff = max(maxDiff, diff);

        if (root->left != NULL) {
            DFS(root->left, max(maxAncestor, root->val), min(minAncestor, root->val), maxDiff);
        }

        if (root->right != NULL) {
            DFS(root->right, max(maxAncestor, root->val), min(minAncestor, root->val), maxDiff);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 8,3,10,1,6,INT_MIN,14,INT_MIN,INT_MIN,4,7,13 };
    check.checkInt(7, o.maxAncestorDiff(createTree(values)));

    values = { 8,3,2,1,6,INT_MIN,14,INT_MIN,INT_MIN,4,7,1300 };
    check.checkInt(1298, o.maxAncestorDiff(createTree(values)));
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
