/* 删除链表的节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。

注意：此题对比原题有改动

示例 1:

输入: head = [4,5,1,9], val = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
示例 2:

输入: head = [4,5,1,9], val = 1
输出: [4,5,9]
解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
 

说明：

题目保证链表中节点的值互不相同
若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode pseudoHead(0);
        pseudoHead.next = head;
        ListNode* node = &pseudoHead;

        while (node->next != NULL && node->next->val != val) {
            node = node->next;
        }

        if (node->next != NULL) {
            node->next = node->next->next;
        }

        return pseudoHead.next;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> actual = { 4,5,1,9 };
    vector<int> expected = { 4,1,9 };
    check.checkSingleList(createList(expected), o.deleteNode(createList(actual), 5));

    actual = { 4,5,1,9 };
    expected = { 4,5,9 };
    check.checkSingleList(createList(expected), o.deleteNode(createList(actual), 1));

    actual = { 4,5,1,9 };
    expected = { 5,1,9 };
    check.checkSingleList(createList(expected), o.deleteNode(createList(actual), 4));

    actual = { 4,5,1,9 };
    expected = { 4,5,1 };
    check.checkSingleList(createList(expected), o.deleteNode(createList(actual), 9));

    actual = { 4,5,1,9 };
    expected = { 4,5,1,9 };
    check.checkSingleList(createList(expected), o.deleteNode(createList(actual), 2));

    actual = {  };
    expected = {  };
    check.checkSingleList(createList(expected), o.deleteNode(createList(actual), 1));

    actual = { 4 };
    expected = {  };
    check.checkSingleList(createList(expected), o.deleteNode(createList(actual), 4));
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
