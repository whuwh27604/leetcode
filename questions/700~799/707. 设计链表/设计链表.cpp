/* 设计链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

在链表类中实现这些功能：

get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
 

示例：

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
linkedList.get(1);            //返回2
linkedList.deleteAtIndex(1);  //现在链表是1-> 3
linkedList.get(1);            //返回3
 

提示：

所有val值都在 [1, 1000] 之内。
操作次数将在  [1, 1000] 之内。
请不要使用内置的 LinkedList 库。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

struct MyListNode {
    int val;
    MyListNode* next;
    MyListNode* prev;
    MyListNode() : val(0), next(NULL), prev(NULL) {}
    MyListNode(int x) : val(x), next(NULL), prev(NULL) {}
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        pseudoHead.next = &pseudoTail;
        pseudoTail.prev = &pseudoHead;
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if ((index < 0) || (index >= size)) {
            return -1;
        }

        int count = 0;
        MyListNode* node = pseudoHead.next;

        while (count++ != index) {
            node = node->next;
        }

        return node->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyListNode* node = new MyListNode(val);
        node->prev = &pseudoHead;
        node->next = pseudoHead.next;
        pseudoHead.next->prev = node;
        pseudoHead.next = node;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        MyListNode* node = new MyListNode(val);
        node->prev = pseudoTail.prev;
        node->next = &pseudoTail;
        pseudoTail.prev->next = node;
        pseudoTail.prev = node;
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        if (index <= 0) {
            addAtHead(val);
            return;
        }

        int count = 0;
        MyListNode* node = new MyListNode(val);
        MyListNode* insertBefore = pseudoHead.next;

        while (count++ != index) {
            insertBefore = insertBefore->next;
        }

        node->prev = insertBefore->prev;
        node->next = insertBefore;
        insertBefore->prev->next = node;
        insertBefore->prev = node;
        size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if ((index < 0) || (index >= size)) {
            return;
        }

        int count = 0;
        MyListNode* deleteNode = pseudoHead.next;

        while (count++ != index) {
            deleteNode = deleteNode->next;
        }

        deleteNode->prev->next = deleteNode->next;
        deleteNode->next->prev = deleteNode->prev;
        delete deleteNode;
        size--;
    }

private:
    MyListNode pseudoHead;
    MyListNode pseudoTail;
    int size;
};

int main()
{
    CheckResult check;

    MyLinkedList o1;
    check.checkInt(-1, o1.get(0));
    o1.addAtIndex(1, 1);
    check.checkInt(-1, o1.get(0));
    o1.addAtHead(1);
    check.checkInt(1, o1.get(0));
    o1.addAtTail(3);
    check.checkInt(3, o1.get(1));
    o1.addAtIndex(1, 2);
    check.checkInt(1, o1.get(0));
    check.checkInt(2, o1.get(1));
    check.checkInt(3, o1.get(2));
    o1.deleteAtIndex(-1);
    check.checkInt(1, o1.get(0));
    check.checkInt(2, o1.get(1));
    check.checkInt(3, o1.get(2));
    o1.deleteAtIndex(3);
    check.checkInt(1, o1.get(0));
    check.checkInt(2, o1.get(1));
    check.checkInt(3, o1.get(2));
    o1.deleteAtIndex(2);
    check.checkInt(1, o1.get(0));
    check.checkInt(2, o1.get(1));
    check.checkInt(-1, o1.get(2));
    o1.deleteAtIndex(1);
    check.checkInt(1, o1.get(0));
    check.checkInt(-1, o1.get(1));
    check.checkInt(-1, o1.get(2));
    o1.deleteAtIndex(0);
    check.checkInt(-1, o1.get(0));
    check.checkInt(-1, o1.get(1));
    check.checkInt(-1, o1.get(2));

    MyLinkedList o2;
    check.checkInt(-1, o2.get(0));
    o2.addAtIndex(1, 1);
    check.checkInt(-1, o2.get(0));
    o2.addAtTail(1);
    check.checkInt(1, o2.get(0));
    check.checkInt(-1, o2.get(1));
    o2.deleteAtIndex(1);
    check.checkInt(1, o2.get(0));
    o2.deleteAtIndex(0);
    check.checkInt(-1, o2.get(0));
    o2.deleteAtIndex(1);
    check.checkInt(-1, o2.get(0));
    o2.deleteAtIndex(0);
    check.checkInt(-1, o2.get(0));
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
