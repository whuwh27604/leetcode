/* 合并两个链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个链表 list1 和 list2 ，它们包含的元素分别为 n 个和 m 个。

请你将 list1 中第 a 个节点到第 b 个节点删除，并将list2 接在被删除节点的位置。

下图中蓝色边和节点展示了操作后的结果：


请你返回结果链表的头指针。

 

示例 1：



输入：list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
输出：[0,1,2,1000000,1000001,1000002,5]
解释：我们删除 list1 中第三和第四个节点，并将 list2 接在该位置。上图中蓝色的边和节点为答案链表。
示例 2：


输入：list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
输出：[0,1,1000000,1000001,1000002,1000003,1000004,6]
解释：上图中蓝色的边和节点为答案链表。
 

提示：

3 <= list1.length <= 104
1 <= a <= b < list1.length - 1
1 <= list2.length <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-in-between-linked-lists
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int num = 0;
        ListNode pseudoHead(0);
        pseudoHead.next = list1;
        ListNode* node = &pseudoHead;

        while (num < a) {
            ++num;
            node = node->next;
        }

        ListNode* tmp = node->next;
        node->next = list2;

        while (num <= b) {
            ++num;
            tmp = tmp->next;
        }

        ListNode* list2Tail = getTail(list2);
        list2Tail->next = tmp;

        return pseudoHead.next;
    }

    ListNode* getTail(ListNode* list) {
        ListNode* tail = list;

        while (tail->next != NULL) {
            tail = tail->next;
        }

        return tail;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values1 = { 0,1,2,3,4,5 };
    vector<int> values2 = { 1000000,1000001,1000002 };
    ListNode* actual = o.mergeInBetween(createList(values1), 3, 4, createList(values2));
    vector<int> value = { 0,1,2,1000000,1000001,1000002,5 };
    check.checkSingleList(createList(value), actual);

    values1 = { 0,1,2,3,4,5,6 };
    values2 = { 1000000,1000001,1000002,1000003,1000004 };
    actual = o.mergeInBetween(createList(values1), 2, 5, createList(values2));
    value = { 0,1,1000000,1000001,1000002,1000003,1000004,6 };
    check.checkSingleList(createList(value), actual);

    values1 = { 0,1,2,3,4,5,6 };
    values2 = { 1000000,1000001,1000002,1000003,1000004 };
    actual = o.mergeInBetween(createList(values1), 0, 6, createList(values2));
    value = { 1000000,1000001,1000002,1000003,1000004 };
    check.checkSingleList(createList(value), actual);

    values1 = { 6 };
    values2 = { 1000004 };
    actual = o.mergeInBetween(createList(values1), 0, 0, createList(values2));
    value = { 1000004 };
    check.checkSingleList(createList(value), actual);
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
