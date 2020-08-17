/* 有序链表转换二叉搜索树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        vector<int> values;
        list2Vector(head, values);

        return createBST(values, 0, values.size() - 1);
    }

    void list2Vector(ListNode* head, vector<int>& values) {
        while (head != NULL) {
            values.push_back(head->val);
            head = head->next;
        }
    }

    TreeNode* createBST(vector<int>& values, int left, int right) {
        int middle = (left + right) / 2;
        TreeNode* root = new TreeNode(values[middle]);

        if (middle > left) {
            root->left = createBST(values, left, middle - 1);
        }

        if (middle < right) {
            root->right = createBST(values, middle + 1, right);
        }

        return root;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    TreeNode* actual = o.sortedListToBST(NULL);
    check.checkPoint(NULL, actual);

    ListNode node1(1);
    actual = o.sortedListToBST(&node1);
    check.checkInt(1, actual->val);
    check.checkPoint(NULL, actual->left);
    check.checkPoint(NULL, actual->right);

    ListNode node2(2);
    node1.next = &node2;
    actual = o.sortedListToBST(&node1);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->right->val);
    check.checkPoint(NULL, actual->left);
    check.checkPoint(NULL, actual->right->left);
    check.checkPoint(NULL, actual->right->right);

    ListNode node3(3);
    node2.next = &node3;
    actual = o.sortedListToBST(&node1);
    check.checkInt(2, actual->val);
    check.checkInt(1, actual->left->val);
    check.checkInt(3, actual->right->val);
    check.checkPoint(NULL, actual->left->left);
    check.checkPoint(NULL, actual->left->right);
    check.checkPoint(NULL, actual->right->left);
    check.checkPoint(NULL, actual->right->right);

    ListNode node4(4);
    node3.next = &node4;
    actual = o.sortedListToBST(&node1);
    check.checkInt(2, actual->val);
    check.checkInt(1, actual->left->val);
    check.checkInt(3, actual->right->val);
    check.checkInt(4, actual->right->right->val);
    check.checkPoint(NULL, actual->left->left);
    check.checkPoint(NULL, actual->left->right);
    check.checkPoint(NULL, actual->right->left);
    check.checkPoint(NULL, actual->right->right->left);
    check.checkPoint(NULL, actual->right->right->right);

    ListNode node5(5);
    node4.next = &node5;
    actual = o.sortedListToBST(&node1);
    check.checkInt(3, actual->val);
    check.checkInt(1, actual->left->val);
    check.checkInt(4, actual->right->val);
    check.checkInt(2, actual->left->right->val);
    check.checkInt(5, actual->right->right->val);
    check.checkPoint(NULL, actual->left->left);
    check.checkPoint(NULL, actual->left->right->left);
    check.checkPoint(NULL, actual->left->right->right);
    check.checkPoint(NULL, actual->right->left);
    check.checkPoint(NULL, actual->right->right->left);
    check.checkPoint(NULL, actual->right->right->right);

    ListNode node6(6);
    node5.next = &node6;
    actual = o.sortedListToBST(&node1);
    check.checkInt(3, actual->val);
    check.checkInt(1, actual->left->val);
    check.checkInt(5, actual->right->val);
    check.checkInt(2, actual->left->right->val);
    check.checkInt(4, actual->right->left->val);
    check.checkInt(6, actual->right->right->val);
    check.checkPoint(NULL, actual->left->left);
    check.checkPoint(NULL, actual->left->right->left);
    check.checkPoint(NULL, actual->left->right->right);
    check.checkPoint(NULL, actual->right->left->left);
    check.checkPoint(NULL, actual->right->left->right);
    check.checkPoint(NULL, actual->right->right->left);
    check.checkPoint(NULL, actual->right->right->right);

    ListNode node7(7);
    node6.next = &node7;
    actual = o.sortedListToBST(&node1);
    check.checkInt(4, actual->val);
    check.checkInt(2, actual->left->val);
    check.checkInt(6, actual->right->val);
    check.checkInt(1, actual->left->left->val);
    check.checkInt(3, actual->left->right->val);
    check.checkInt(5, actual->right->left->val);
    check.checkInt(7, actual->right->right->val);
    check.checkPoint(NULL, actual->left->left->left);
    check.checkPoint(NULL, actual->left->left->right);
    check.checkPoint(NULL, actual->left->right->left);
    check.checkPoint(NULL, actual->left->right->right);
    check.checkPoint(NULL, actual->right->left->left);
    check.checkPoint(NULL, actual->right->left->right);
    check.checkPoint(NULL, actual->right->right->left);
    check.checkPoint(NULL, actual->right->right->right);

    node1.val = -10;
    node2.val = -3;
    node3.val = 0;
    node4.val = 5;
    node5.val = 9;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;
    actual = o.sortedListToBST(&node1);
    check.checkInt(0, actual->val);
    check.checkInt(-10, actual->left->val);
    check.checkInt(5, actual->right->val);
    check.checkInt(-3, actual->left->right->val);
    check.checkInt(9, actual->right->right->val);
    check.checkPoint(NULL, actual->left->left);
    check.checkPoint(NULL, actual->left->right->left);
    check.checkPoint(NULL, actual->left->right->right);
    check.checkPoint(NULL, actual->right->left);
    check.checkPoint(NULL, actual->right->right->left);
    check.checkPoint(NULL, actual->right->right->right);
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
