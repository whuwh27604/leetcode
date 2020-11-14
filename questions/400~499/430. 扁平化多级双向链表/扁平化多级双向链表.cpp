/* 扁平化多级双向链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

给你位于列表第一级的头节点，请你扁平化列表，使所有结点出现在单级双链表中。

 

示例 1：

输入：head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
输出：[1,2,3,7,8,11,12,9,10,4,5,6]
解释：

输入的多级列表如下图所示：



扁平化后的链表如下图：


示例 2：

输入：head = [1,2,null,3]
输出：[1,3,2]
解释：

输入的多级列表如下图所示：

  1---2---NULL
  |
  3---NULL
示例 3：

输入：head = []
输出：[]
 

如何表示测试用例中的多级链表？

以 示例 1 为例：

 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
序列化其中的每一级之后：

[1,2,3,4,5,6,null]
[7,8,9,10,null]
[11,12,null]
为了将每一级都序列化到一起，我们需要每一级中添加值为 null 的元素，以表示没有节点连接到上一级的上级节点。

[1,2,3,4,5,6,null]
[null,null,7,8,9,10,null]
[null,11,12,null]
合并所有序列化结果，并去除末尾的 null 。

[1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
 

提示：

节点数目不超过 1000
1 <= Node.val <= 10^5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/MultilevelDoublyLinkedList.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        (void)DLR(head);
        return head;
    }

    Node* DLR(Node* head) {
        Node* left = head->child;
        Node* right = head->next;
        Node* leftTail = NULL;

        if ((left == NULL) && (right == NULL)) {
            return head;
        }

        if (left != NULL) {
            leftTail = DLR(left);

            head->next = left;
            left->prev = head;
            leftTail->next = right;
            if (right != NULL) {
                right->prev = leftTail;
            }
            head->child = NULL;
        }

        if (right != NULL) {
            return DLR(right);
        }

        return leftTail;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    check.checkPoint(NULL, o.flatten(NULL));

    Node node1(1);
    Node* actual = o.flatten(&node1);
    check.checkPoint(&node1, actual);
    check.checkPoint(NULL, actual->next);
    check.checkPoint(NULL, actual->prev);
    check.checkPoint(NULL, actual->child);
    check.checkInt(1, actual->val);

    Node node2(2);
    node1.next = &node2;
    node2.prev = &node1;
    actual = o.flatten(&node1);
    check.checkPoint(&node1, actual);
    check.checkPoint(&node2, actual->next);
    check.checkPoint(NULL, actual->prev);
    check.checkPoint(NULL, actual->child);
    check.checkInt(1, actual->val);
    check.checkPoint(NULL, actual->next->next);
    check.checkPoint(actual, actual->next->prev);
    check.checkPoint(NULL, actual->next->child);
    check.checkInt(2, actual->next->val);

    node1.next = node1.prev = NULL;
    node1.child = &node2;
    node2.next = node2.prev = node2.child = NULL;
    actual = o.flatten(&node1);
    check.checkPoint(&node1, actual);
    check.checkPoint(&node2, actual->next);
    check.checkPoint(NULL, actual->prev);
    check.checkPoint(NULL, actual->child);
    check.checkInt(1, actual->val);
    check.checkPoint(NULL, actual->next->next);
    check.checkPoint(actual, actual->next->prev);
    check.checkPoint(NULL, actual->next->child);
    check.checkInt(2, actual->next->val);

    Node node3(3);
    node1.next = &node2;
    node1.child = &node3;
    node1.prev = NULL;
    node2.prev = &node1;
    node2.next = node2.child = NULL;
    actual = o.flatten(&node1);
    check.checkPoint(&node1, actual);
    check.checkPoint(&node3, actual->next);
    check.checkPoint(NULL, actual->prev);
    check.checkPoint(NULL, actual->child);
    check.checkInt(1, actual->val);
    check.checkPoint(&node2, actual->next->next);
    check.checkPoint(&node1, actual->next->prev);
    check.checkPoint(NULL, actual->next->child);
    check.checkInt(3, actual->next->val);
    check.checkPoint(NULL, actual->next->next->next);
    check.checkPoint(&node3, actual->next->next->prev);
    check.checkPoint(NULL, actual->next->next->child);
    check.checkInt(2, actual->next->next->val);

    Node node4(4);
    Node node5(5);
    Node node6(6);
    Node node7(7);
    Node node8(8);
    Node node9(9);
    Node node10(10);
    Node node11(11);
    Node node12(12);
    node1.next = &node2;
    node1.prev = NULL;
    node1.child = NULL;
    node2.next = &node3;
    node2.prev = &node1;
    node2.child = NULL;
    node3.next = &node4;
    node3.prev = &node2;
    node3.child = &node7;
    node4.next = &node5;
    node4.prev = &node3;
    node4.child = NULL;
    node5.next = &node6;
    node5.prev = &node4;
    node5.child = NULL;
    node6.next = NULL;
    node6.prev = &node5;
    node6.child = NULL;
    node7.next = &node8;
    node7.prev = NULL;
    node7.child = NULL;
    node8.next = &node9;
    node8.prev = &node7;
    node8.child = &node11;
    node9.next = &node10;
    node9.prev = &node8;
    node9.child = NULL;
    node10.next = NULL;
    node10.prev = &node9;
    node10.child = NULL;
    node11.next = &node12;
    node11.prev = NULL;
    node11.child = NULL;
    node12.next = NULL;
    node12.prev = &node11;
    node12.child = NULL;
    actual = o.flatten(&node1);
    check.checkPoint(&node1, actual);
    check.checkPoint(&node2, actual->next);
    check.checkPoint(NULL, actual->prev);
    check.checkPoint(NULL, actual->child);
    check.checkInt(1, actual->val);
    check.checkPoint(&node3, actual->next->next);
    check.checkPoint(&node1, actual->next->prev);
    check.checkPoint(NULL, actual->next->child);
    check.checkInt(2, actual->next->val);
    check.checkPoint(&node7, actual->next->next->next);
    check.checkPoint(&node2, actual->next->next->prev);
    check.checkPoint(NULL, actual->next->next->child);
    check.checkInt(3, actual->next->next->val);
    check.checkPoint(&node8, actual->next->next->next->next);
    check.checkPoint(&node3, actual->next->next->next->prev);
    check.checkPoint(NULL, actual->next->next->next->child);
    check.checkInt(7, actual->next->next->next->val);
    check.checkPoint(&node11, actual->next->next->next->next->next);
    check.checkPoint(&node7, actual->next->next->next->next->prev);
    check.checkPoint(NULL, actual->next->next->next->next->child);
    check.checkInt(8, actual->next->next->next->next->val);
    check.checkPoint(&node12, actual->next->next->next->next->next->next);
    check.checkPoint(&node8, actual->next->next->next->next->next->prev);
    check.checkPoint(NULL, actual->next->next->next->next->next->child);
    check.checkInt(11, actual->next->next->next->next->next->val);
    check.checkPoint(&node9, actual->next->next->next->next->next->next->next);
    check.checkPoint(&node11, actual->next->next->next->next->next->next->prev);
    check.checkPoint(NULL, actual->next->next->next->next->next->next->child);
    check.checkInt(12, actual->next->next->next->next->next->next->val);
    check.checkPoint(&node10, actual->next->next->next->next->next->next->next->next);
    check.checkPoint(&node12, actual->next->next->next->next->next->next->next->prev);
    check.checkPoint(NULL, actual->next->next->next->next->next->next->next->child);
    check.checkInt(9, actual->next->next->next->next->next->next->next->val);
    check.checkPoint(&node4, actual->next->next->next->next->next->next->next->next->next);
    check.checkPoint(&node9, actual->next->next->next->next->next->next->next->next->prev);
    check.checkPoint(NULL, actual->next->next->next->next->next->next->next->next->child);
    check.checkInt(10, actual->next->next->next->next->next->next->next->next->val);
    check.checkPoint(&node5, actual->next->next->next->next->next->next->next->next->next->next);
    check.checkPoint(&node10, actual->next->next->next->next->next->next->next->next->next->prev);
    check.checkPoint(NULL, actual->next->next->next->next->next->next->next->next->next->child);
    check.checkInt(4, actual->next->next->next->next->next->next->next->next->next->val);
    check.checkPoint(&node6, actual->next->next->next->next->next->next->next->next->next->next->next);
    check.checkPoint(&node4, actual->next->next->next->next->next->next->next->next->next->next->prev);
    check.checkPoint(NULL, actual->next->next->next->next->next->next->next->next->next->next->child);
    check.checkInt(5, actual->next->next->next->next->next->next->next->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next->next->next->next->next->next->next->next->next);
    check.checkPoint(&node5, actual->next->next->next->next->next->next->next->next->next->next->next->prev);
    check.checkPoint(NULL, actual->next->next->next->next->next->next->next->next->next->next->next->child);
    check.checkInt(6, actual->next->next->next->next->next->next->next->next->next->next->next->val);
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
