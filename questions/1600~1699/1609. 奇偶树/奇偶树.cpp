/* 奇偶树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
如果一棵二叉树满足下述几个条件，则可以称为 奇偶树 ：

二叉树根节点所在层下标为 0 ，根的子节点所在层下标为 1 ，根的孙节点所在层下标为 2 ，依此类推。
偶数下标 层上的所有节点的值都是 奇 整数，从左到右按顺序 严格递增
奇数下标 层上的所有节点的值都是 偶 整数，从左到右按顺序 严格递减
给你二叉树的根节点，如果二叉树为 奇偶树 ，则返回 true ，否则返回 false 。

 

示例 1：



输入：root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
输出：true
解释：每一层的节点值分别是：
0 层：[1]
1 层：[10,4]
2 层：[3,7,9]
3 层：[12,8,6,2]
由于 0 层和 2 层上的节点值都是奇数且严格递增，而 1 层和 3 层上的节点值都是偶数且严格递减，因此这是一棵奇偶树。
示例 2：



输入：root = [5,4,2,3,3,7]
输出：false
解释：每一层的节点值分别是：
0 层：[5]
1 层：[4,2]
2 层：[3,3,7]
2 层上的节点值不满足严格递增的条件，所以这不是一棵奇偶树。
示例 3：



输入：root = [5,9,1,3,5,7]
输出：false
解释：1 层上的节点值应为偶数。
示例 4：

输入：root = [1]
输出：true
示例 5：

输入：root = [11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17]
输出：true
 

提示：

树中节点数在范围 [1, 105] 内
1 <= Node.val <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/even-odd-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        bool evenLevel = false;
        queue<TreeNode*> bfs;
        bfs.push(root);

        while (!bfs.empty()) {
            evenLevel = !evenLevel;
            int i, size = bfs.size(), prev = evenLevel ? INT_MIN : INT_MAX;

            for (i = 0; i < size; ++i) {
                TreeNode* node = bfs.front();
                bfs.pop();

                if ((evenLevel && ((node->val & 1) == 0 || node->val <= prev)) || (!evenLevel && ((node->val & 1) == 1 || node->val >= prev))) {
                    return false;
                }

                prev = node->val;

                if (node->left != NULL) {
                    bfs.push(node->left);
                }

                if (node->right != NULL) {
                    bfs.push(node->right);
                }
            }
        }

        return true;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,10,4,3,INT_MIN,7,9,12,8,6,INT_MIN,INT_MIN,2 };
    check.checkBool(true, o.isEvenOddTree(createTree(values)));

    values = { 5,4,2,3,3,7 };
    check.checkBool(false, o.isEvenOddTree(createTree(values)));

    values = { 5,9,1,3,5,7 };
    check.checkBool(false, o.isEvenOddTree(createTree(values)));

    values = { 1 };
    check.checkBool(true, o.isEvenOddTree(createTree(values)));

    values = { 11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17 };
    check.checkBool(true, o.isEvenOddTree(createTree(values)));

    values = { 11,18,14,3,7,INT_MIN,INT_MIN,INT_MIN,INT_MIN,18,INT_MIN,6 };
    check.checkBool(false, o.isEvenOddTree(createTree(values)));
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
