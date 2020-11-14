/* 二叉搜索树中的众数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。

假定 BST 有如下定义：

结点左子树中所含结点的值小于等于当前结点的值
结点右子树中所含结点的值大于等于当前结点的值
左子树和右子树都是二叉搜索树
例如：
给定 BST [1,null,2,2],

   1
    \
     2
    /
   2
返回[2].

提示：如果众数超过1个，不需考虑输出顺序

进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-mode-in-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        // BST的中序遍历是非递减序列
        int previous = INT_MAX, count = 1, maxCount = 0;
        vector<int> modes;

        if (root != NULL) {
            LDR(root, previous, count, maxCount, modes);
        }

        return modes;
    }

    void LDR(TreeNode* root, int& previous, int& count, int& maxCount, vector<int>& modes) {
        if ((root->left == NULL) && (root->right == NULL)) {
            process(root->val, previous, count, maxCount, modes);
            return;
        }

        if (root->left != NULL) {
            LDR(root->left, previous, count, maxCount, modes);
        }

        process(root->val, previous, count, maxCount, modes);

        if (root->right != NULL) {
            LDR(root->right, previous, count, maxCount, modes);
        }
    }

    void process(int current, int& previous, int& count, int& maxCount, vector<int>& modes) {
        if (current != previous) {
            count = 0;
        }

        count++;
        if (count == maxCount) {
            modes.push_back(current);
        }
        else if (count > maxCount) {
            maxCount = count;
            modes.clear();
            modes.push_back(current);
        }

        previous = current;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode node1(6);
    TreeNode node2(4);
    TreeNode node3(9);
    TreeNode node4(2);
    TreeNode node5(5);
    TreeNode node6(7);
    TreeNode node7(10);
    TreeNode node8(1);
    TreeNode node9(3);
    TreeNode node10(8);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    node4.left = &node8;
    node4.right = &node9;
    node6.right = &node10;
    vector<int> actual = o.findMode(&node1);
    vector<int> expected = { 1,2,3,4,5,6,7,8,9,10 };
    check.checkIntVector(expected, actual);

    node3.val = 10;
    actual = o.findMode(&node1);
    expected = { 10 };
    check.checkIntVector(expected, actual);

    node8.val = 1;
    node9.val = 1;
    node4.val = 1;
    node2.val = 2;
    node5.val = 2;
    node1.val = 6;
    node3.val = 10;
    node6.val = 10;
    node7.val = 11;
    node10.val = 10;
    actual = o.findMode(&node1);
    expected = { 1,10 };
    check.checkIntVector(expected, actual);

    node8.val = 1;
    node9.val = 1;
    node4.val = 1;
    node2.val = 2;
    node5.val = 2;
    node1.val = 6;
    node3.val = 10;
    node6.val = 10;
    node7.val = 10;
    node10.val = 10;
    actual = o.findMode(&node1);
    expected = { 10 };
    check.checkIntVector(expected, actual);

    node2.val = 2;
    node3.val = 2;
    node1.left = NULL;
    node1.right = &node2;
    node2.left = &node3;
    node2.right = NULL;
    node3.left = NULL;
    node3.right = NULL;
    actual = o.findMode(&node1);
    expected = { 2 };
    check.checkIntVector(expected, actual);

    node1.val = node2.val = node3.val = INT_MAX;
    actual = o.findMode(&node1);
    expected = { INT_MAX };
    check.checkIntVector(expected, actual);

    node1.val = INT_MAX;
    node1.left = node1.right = NULL;
    actual = o.findMode(&node1);
    expected = { INT_MAX };
    check.checkIntVector(expected, actual);

    node1.val = 5;
    node1.left = node1.right = NULL;
    actual = o.findMode(&node1);
    expected = { 5 };
    check.checkIntVector(expected, actual);

    actual = o.findMode(NULL);
    expected = {  };
    check.checkIntVector(expected, actual);
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
