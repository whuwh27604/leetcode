/* 排序链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

进阶：

你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 

示例 1：


输入：head = [4,2,1,3]
输出：[1,2,3,4]
示例 2：


输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]
示例 3：

输入：head = []
输出：[]
 

提示：

链表中节点的数目在范围 [0, 5 * 104] 内
-105 <= Node.val <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int count = countNodes(head);
        if (count == 0) {
            return NULL;
        }

        return mergeSort(head, count);
    }

    int countNodes(ListNode* head) {
        int count = 0;

        while (head != NULL) {
            ++count;
            head = head->next;
        }

        return count;
    }

    ListNode* mergeSort(ListNode* head, int num) {
        if (num == 1) {
            return head;
        }

        int firstHalf = num / 2, secondHalf = num - firstHalf;
        ListNode* node = head;
        ListNode* tail = node;

        for (int i = 0; i < firstHalf; ++i) {
            tail = node;
            node = node->next;
        }

        tail->next = NULL;
        ListNode* firstHead = mergeSort(head, firstHalf);
        ListNode* secondHead = mergeSort(node, secondHalf);
        
        return merge(firstHead, secondHead);
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
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
    CheckResult check;
    Solution o;

    vector<int> values = { 4,2,1,3 };
    vector<int> expValues = { 1,2,3,4 };
    check.checkSingleList(createList(expValues), o.sortList(createList(values)));

    values = { -1,5,3,4,0 };
    expValues = { -1,0,3,4,5 };
    check.checkSingleList(createList(expValues), o.sortList(createList(values)));

    values = {  };
    expValues = {  };
    check.checkSingleList(createList(expValues), o.sortList(createList(values)));

    values = { 1 };
    expValues = { 1 };
    check.checkSingleList(createList(expValues), o.sortList(createList(values)));
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
