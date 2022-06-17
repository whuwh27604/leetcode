/* 排序的循环链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定循环单调非递减列表中的一个点，写一个函数向这个列表中插入一个新元素 insertVal ，使这个列表仍然是循环升序的。

给定的可以是这个列表中任意一个顶点的指针，并不一定是这个列表中最小元素的指针。

如果有多个满足条件的插入位置，可以选择任意一个位置插入新的值，插入后整个列表仍然保持有序。

如果列表为空（给定的节点是 null），需要创建一个循环有序列表并返回这个节点。否则。请返回原先给定的节点。

 

示例 1：


 

输入：head = [3,4,1], insertVal = 2
输出：[3,4,1,2]
解释：在上图中，有一个包含三个元素的循环有序列表，你获得值为 3 的节点的指针，我们需要向表中插入元素 2 。新插入的节点应该在 1 和 3 之间，插入之后，整个列表如上图所示，最后返回节点 3 。


示例 2：

输入：head = [], insertVal = 1
输出：[1]
解释：列表为空（给定的节点是 null），创建一个循环有序列表并返回这个节点。
示例 3：

输入：head = [1], insertVal = 0
输出：[1,0]
 

提示：

0 <= Number of Nodes <= 5 * 10^4
-10^6 <= Node.val <= 10^6
-10^6 <= insertVal <= 10^6
 

注意：本题与主站 708 题相同： https://leetcode-cn.com/problems/insert-into-a-sorted-circular-linked-list/

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/4ueAj6
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* insert = new Node(insertVal);

        if (head == NULL) {
            insert->next = insert;
            return insert;
        }

        if (head->next == head) {
            head->next = insert;
            insert->next = head;
            return head;
        }

        Node* first = NULL;
        Node* last = NULL;
        Node* current = head;
        Node* next = head->next;

        do {
            if (insertVal >= current->val && insertVal <= next->val) {
                current->next = insert;
                insert->next = next;
                return head;
            }

            if (next->val < current->val) {
                first = next;
                last = current;
            }

            current = next;
            next = next->next;
        } while (current != head);

        if (first == NULL) {
            first = next;
            last = current;
        }

        last->next = insert;
        insert->next = first;

        return head;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    Node node11(3);
    Node node12(4);
    Node node13(1);
    node11.next = &node12;
    node12.next = &node13;
    node13.next = &node11;
    Node* head = o.insert(&node11, 2);
    check.checkInt(3, head->val);
    check.checkInt(4, head->next->val);
    check.checkInt(1, head->next->next->val);
    check.checkInt(2, head->next->next->next->val);
    check.checkInt(3, head->next->next->next->next->val);

    Node node21(3);
    Node node22(4);
    Node node23(1);
    node21.next = &node22;
    node22.next = &node23;
    node23.next = &node21;
    head = o.insert(&node21, 0);
    check.checkInt(3, head->val);
    check.checkInt(4, head->next->val);
    check.checkInt(0, head->next->next->val);
    check.checkInt(1, head->next->next->next->val);
    check.checkInt(3, head->next->next->next->next->val);

    Node node31(3);
    Node node32(4);
    Node node33(1);
    node31.next = &node32;
    node32.next = &node33;
    node33.next = &node31;
    head = o.insert(&node31, 7);
    check.checkInt(3, head->val);
    check.checkInt(4, head->next->val);
    check.checkInt(7, head->next->next->val);
    check.checkInt(1, head->next->next->next->val);
    check.checkInt(3, head->next->next->next->next->val);

    head = o.insert(NULL, 1);
    check.checkInt(1, head->val);
    check.checkInt(1, head->next->val);

    Node node41(1);
    node41.next = &node41;
    head = o.insert(&node41, 0);
    check.checkInt(1, head->val);
    check.checkInt(0, head->next->val);
    check.checkInt(1, head->next->next->val);

    Node node51(1);
    Node node52(1);
    node51.next = &node52;
    node52.next = &node51;
    head = o.insert(&node51, 2);
    check.checkInt(1, head->val);
    check.checkInt(2, head->next->val);
    check.checkInt(1, head->next->next->val);
    check.checkInt(1, head->next->next->next->val);
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
