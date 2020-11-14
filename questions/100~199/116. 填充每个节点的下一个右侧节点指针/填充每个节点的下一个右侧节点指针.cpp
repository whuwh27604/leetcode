/* 填充每个节点的下一个右侧节点指针.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。

 

示例：



输入：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":{"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":{"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}

输出：{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":{"$id":"6","left":null,"next":null,"right":null,"val":7},"right":null,"val":6},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"7","left":{"$ref":"5"},"next":null,"right":{"$ref":"6"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"7"},"val":1}

解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
 

提示：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/TreeNodeWithNext.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }

        Node* currentLayerFirst = root;
        while (currentLayerFirst->left != NULL) {
            Node* currentLayerNode = currentLayerFirst;
            while (currentLayerNode != NULL) {
                currentLayerNode->left->next = currentLayerNode->right;
                currentLayerNode->right->next = (currentLayerNode->next == NULL) ? NULL : currentLayerNode->next->left;
                currentLayerNode = currentLayerNode->next;
            }

            currentLayerFirst = currentLayerFirst->left;
        }

        return root;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkPoint(NULL, o.connect(NULL));

    Node node1(1);
    Node* actual = o.connect(&node1);
    check.checkInt(1, actual->val);
    check.checkPoint(NULL, actual->next);

    Node node2(2);
    Node node3(3);
    node1.left = &node2;
    node1.right = &node3;
    node1.next = NULL;
    node2.left = node2.right = node2.next = NULL;
    node3.left = node3.right = node3.next = NULL;
    actual = o.connect(&node1);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->left->val);
    check.checkInt(3, actual->left->next->val);
    check.checkPoint(NULL, actual->left->next->next);

    Node node4(4);
    Node node5(5);
    Node node6(6);
    Node node7(7);
    node1.left = &node2;
    node1.right = &node3;
    node1.next = NULL;
    node2.left = &node4;
    node2.right = &node5;
    node2.next = NULL;
    node3.left = &node6;
    node3.right = &node7;
    node3.next = NULL;
    node4.left = node4.right = node4.next = NULL;
    node5.left = node5.right = node5.next = NULL;
    node6.left = node6.right = node6.next = NULL;
    node7.left = node7.right = node7.next = NULL;
    actual = o.connect(&node1);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->left->val);
    check.checkInt(3, actual->left->next->val);
    check.checkInt(4, actual->left->left->val);
    check.checkInt(5, actual->left->left->next->val);
    check.checkInt(6, actual->left->left->next->next->val);
    check.checkInt(7, actual->left->left->next->next->next->val);
    check.checkPoint(NULL, actual->left->left->next->next->next->next);

    Node node8(8);
    Node node9(9);
    Node node10(10);
    Node node11(11);
    Node node12(12);
    Node node13(13);
    Node node14(14);
    Node node15(15);
    node1.left = &node2;
    node1.right = &node3;
    node1.next = NULL;
    node2.left = &node4;
    node2.right = &node5;
    node2.next = NULL;
    node3.left = &node6;
    node3.right = &node7;
    node3.next = NULL;
    node4.left = &node8;
    node4.right = &node9;
    node4.next = NULL;
    node5.left = &node10;
    node5.right = &node11;
    node5.next = NULL;
    node6.left = &node12;
    node6.right = &node13;
    node6.next = NULL;
    node7.left = &node14;
    node7.right = &node15;
    node7.next = NULL;
    node8.left = node8.right = node8.next = NULL;
    node9.left = node9.right = node9.next = NULL;
    node10.left = node10.right = node10.next = NULL;
    node11.left = node11.right = node11.next = NULL;
    node12.left = node12.right = node12.next = NULL;
    node13.left = node13.right = node13.next = NULL;
    node14.left = node14.right = node14.next = NULL;
    node15.left = node15.right = node15.next = NULL;
    actual = o.connect(&node1);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->left->val);
    check.checkInt(3, actual->left->next->val);
    check.checkInt(4, actual->left->left->val);
    check.checkInt(5, actual->left->left->next->val);
    check.checkInt(6, actual->left->left->next->next->val);
    check.checkInt(7, actual->left->left->next->next->next->val);
    check.checkInt(8, actual->left->left->left->val);
    check.checkInt(9, actual->left->left->left->next->val);
    check.checkInt(10, actual->left->left->left->next->next->val);
    check.checkInt(11, actual->left->left->left->next->next->next->val);
    check.checkInt(12, actual->left->left->left->next->next->next->next->val);
    check.checkInt(13, actual->left->left->left->next->next->next->next->next->val);
    check.checkInt(14, actual->left->left->left->next->next->next->next->next->next->val);
    check.checkInt(15, actual->left->left->left->next->next->next->next->next->next->next->val);
    check.checkPoint(NULL, actual->left->left->left->next->next->next->next->next->next->next->next);
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
