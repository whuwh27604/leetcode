/* 合并两个有序链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-two-sorted-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode pseudoHead(0);
        ListNode* tail = &pseudoHead;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }

            tail = tail->next;
        }

        if (l1 == NULL) {
            tail->next = l2;
        }
        else {
            tail->next = l1;
        }

        return pseudoHead.next;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 1,2,4 };
    ListNode* l1 = createList(values);
    values = { 1,3,4 };
    ListNode* l2 = createList(values);
    values = { 1,1,2,3,4,4 };
    check.checkSingleList(createList(values), o.mergeTwoLists(l1, l2));

    values = { 1 };
    l1 = createList(values);
    values = {  };
    l2 = createList(values);
    values = { 1 };
    check.checkSingleList(createList(values), o.mergeTwoLists(l1, l2));

    values = {  };
    l1 = createList(values);
    values = { 2 };
    l2 = createList(values);
    values = { 2 };
    check.checkSingleList(createList(values), o.mergeTwoLists(l1, l2));

    values = {  };
    l1 = createList(values);
    values = {  };
    l2 = createList(values);
    values = {  };
    check.checkSingleList(createList(values), o.mergeTwoLists(l1, l2));

    values = { 1,4,4 };
    l1 = createList(values);
    values = { 2,4,4 };
    l2 = createList(values);
    values = { 1,2,4,4,4,4 };
    check.checkSingleList(createList(values), o.mergeTwoLists(l1, l2));
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
