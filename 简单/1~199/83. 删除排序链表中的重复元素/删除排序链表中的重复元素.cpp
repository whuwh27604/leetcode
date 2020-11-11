/* 删除排序链表中的重复元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        while (current != NULL) {
            ListNode* next = current->next;
            if ((next != NULL) && (current->val == next->val)) {
                current->next = next->next;
                continue;
            }

            current = next;
        }

        return head;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 1,1,2 };
    ListNode* head = createList(values);
    values = { 1,2 };
    check.checkSingleList(createList(values), o.deleteDuplicates(head));

    values = { 1,1,2,3,3 };
    head = createList(values);
    values = { 1,2,3 };
    check.checkSingleList(createList(values), o.deleteDuplicates(head));

    values = { 1 };
    head = createList(values);
    values = { 1 };
    check.checkSingleList(createList(values), o.deleteDuplicates(head));

    values = { 1,2,3 };
    head = createList(values);
    values = { 1,2,3 };
    check.checkSingleList(createList(values), o.deleteDuplicates(head));

    values = { 1,1,1,2,2,2,3,3,3 };
    head = createList(values);
    values = { 1,2,3 };
    check.checkSingleList(createList(values), o.deleteDuplicates(head));
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
