/* 分隔链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lessPseudo(0), nolessPseudo(0);
        ListNode* lessTail = &lessPseudo;
        ListNode* nolessTail = &nolessPseudo;

        while (head != NULL) {
            if (head->val < x) {
                lessTail->next = head;
                lessTail = head;
            }
            else {
                nolessTail->next = head;
                nolessTail = head;
            }

            head = head->next;
        }

        lessTail->next = nolessPseudo.next;
        nolessTail->next = NULL;

        return lessPseudo.next;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 1,4,3,2,5,2 };
    ListNode* actual = o.partition(createList(values), 3);
    values = { 1,2,2,4,3,5 };
    check.checkSingleList(createList(values), actual);

    values = {  };
    actual = o.partition(createList(values), 3);
    values = {  };
    check.checkSingleList(createList(values), actual);

    values = { 1 };
    actual = o.partition(createList(values), 3);
    values = { 1 };
    check.checkSingleList(createList(values), actual);

    values = { 3 };
    actual = o.partition(createList(values), 3);
    values = { 3 };
    check.checkSingleList(createList(values), actual);

    values = { 1,3 };
    actual = o.partition(createList(values), 3);
    values = { 1,3 };
    check.checkSingleList(createList(values), actual);

    values = { 3,1 };
    actual = o.partition(createList(values), 3);
    values = { 1,3 };
    check.checkSingleList(createList(values), actual);

    values = { 3,2,1 };
    actual = o.partition(createList(values), 3);
    values = { 2,1,3 };
    check.checkSingleList(createList(values), actual);

    values = { 1,4,3,2,5,2 };
    actual = o.partition(createList(values), 1);
    values = { 1,4,3,2,5,2 };
    check.checkSingleList(createList(values), actual);

    values = { 1,4,3,2,5,2 };
    actual = o.partition(createList(values), 2);
    values = { 1,4,3,2,5,2 };
    check.checkSingleList(createList(values), actual);

    values = { 1,4,3,2,5,2 };
    actual = o.partition(createList(values), 4);
    values = { 1,3,2,2,4,5 };
    check.checkSingleList(createList(values), actual);

    values = { 1,4,3,2,5,2 };
    actual = o.partition(createList(values), 5);
    values = { 1,4,3,2,2,5 };
    check.checkSingleList(createList(values), actual);
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
