/* 恢复二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。

进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？

 

示例 1：


输入：root = [1,3,null,null,2]
输出：[3,1,null,null,2]
解释：3 不能是 1 左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
示例 2：


输入：root = [3,1,4,null,null,2]
输出：[2,1,4,null,null,3]
解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。
 

提示：

树上节点的数目在范围 [2, 1000] 内
-231 <= Node.val <= 231 - 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/recover-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* swapA = NULL;
        TreeNode* swapB = NULL;
        TreeNode* prev = NULL;
        TreeNode* current = root;
        
        while (current != NULL) {
            if (current->left != NULL) {
                TreeNode* rightmost = current->left;
                while (rightmost->right != NULL && rightmost->right != current) {  // 找到左节点的最右节点
                    rightmost = rightmost->right;
                }

                if (rightmost->right == NULL) {
                    rightmost->right = current;  // 最右节点的右节点为空，说明还没有访问，让它的右节点指向current
                    current = current->left;  // 然后就可以访问左节点了
                }
                else {
                    rightmost->right = NULL;  // 最右节点指向了自己，说明左子树已经访问完毕，恢复最右节点的right为空
                    getSwapNode(prev, current, &swapA, &swapB);  // 每次访问数据时，比较一下大小，看是否需要交换
                    prev = current;
                    current = current->right;  // current处理完毕，进入右节点
                }
            }
            else {
                getSwapNode(prev, current, &swapA, &swapB);  // 每次访问数据时，比较一下大小，看是否需要交换
                prev = current;
                current = current->right;  // 左节点为空，直接进入右节点
            }
        }

        if (swapA != NULL) {
            swap(swapA->val, swapB->val);
        }
    }

    void getSwapNode(TreeNode* prev, TreeNode* current, TreeNode** swapA, TreeNode** swapB) {
        if (prev != NULL && prev->val > current->val) {
            if (*swapA == NULL) {  // 第一次降序时，大的那个一定是交换节点，小的那个可能是交换节点
                *swapA = prev;
                *swapB = current;
            }
            else {
                *swapB = current;  // 第二次降序时，小的那个一定是交换节点
            }
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,3,INT_MIN,INT_MIN,2 };
    TreeNode* root = createTree(values);
    o.recoverTree(root);
    values = { 3,1,INT_MIN,INT_MIN,2 };
    check.checkTree(createTree(values), root);

    values = { 3,1,4,INT_MIN,INT_MIN,2 };
    root = createTree(values);
    o.recoverTree(root);
    values = { 2,1,4,INT_MIN,INT_MIN,3 };
    check.checkTree(createTree(values), root);

    values = { 146,71,-13,55,INT_MIN,231,399,321,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,-33 };
    root = createTree(values);
    o.recoverTree(root);
    values = { 146,71,321,55,INT_MIN,231,399,-13,INT_MIN,INT_MIN,INT_MIN,INT_MIN,INT_MIN,-33 };
    check.checkTree(createTree(values), root);

    values = { 3,1 };
    root = createTree(values);
    o.recoverTree(root);
    values = { 3,1 };
    check.checkTree(createTree(values), root);

    values = { 3,INT_MIN,2 };
    root = createTree(values);
    o.recoverTree(root);
    values = { 2,INT_MIN,3 };
    check.checkTree(createTree(values), root);
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
