/* 链表中倒数第k个节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。

 

示例：

给定一个链表: 1->2->3->4->5, 和 k = 2.

返回链表 4->5.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* node = head;
        for (int i = 0; i < k; ++i) {
            node = node->next;
        }

        ListNode* nodeK = head;
        while (node != NULL) {
            node = node->next;
            nodeK = nodeK->next;
        }

        return nodeK;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,2,3,4,5 };
    vector<int> expected = { 4,5 };
    check.checkSingleList(createList(expected), o.getKthFromEnd(createList(values), 2));
    expected = { 5 };
    check.checkSingleList(createList(expected), o.getKthFromEnd(createList(values), 1));
    expected = { 1,2,3,4,5 };
    check.checkSingleList(createList(expected), o.getKthFromEnd(createList(values), 5));

    values = { 1 };
    expected = { 1 };
    check.checkSingleList(createList(expected), o.getKthFromEnd(createList(values), 1));
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
