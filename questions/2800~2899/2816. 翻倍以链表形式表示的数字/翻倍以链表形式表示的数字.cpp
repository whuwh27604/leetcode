/* 翻倍以链表形式表示的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 非空 链表的头节点 head ，表示一个不含前导零的非负数整数。

将链表 翻倍 后，返回头节点 head 。



示例 1：


输入：head = [1,8,9]
输出：[3,7,8]
解释：上图中给出的链表，表示数字 189 。返回的链表表示数字 189 * 2 = 378 。
示例 2：


输入：head = [9,9,9]
输出：[1,9,9,8]
解释：上图中给出的链表，表示数字 999 。返回的链表表示数字 999 * 2 = 1998 。


提示：

链表中节点的数目在范围 [1, 104] 内
0 <= Node.val <= 9
生成的输入满足：链表表示一个不含前导零的数字，除了数字 0 本身。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {  // 因为只需要乘2，所以大于4时产生进位，小于等于4时不会进位
        ListNode* hd = NULL;
        if (head->val > 4) {
            hd = new ListNode(1);
            hd->next = head;
        }

        ListNode* cur = head;
        ListNode* next = cur->next;

        while (cur != NULL) {
            cur->val = cur->val * 2 % 10;
            if (next != NULL && next->val > 4) {
                cur->val += 1;
            }

            cur = next;
            if (cur != NULL) {
                next = cur->next;
            }
        }

        return hd == NULL ? head : hd;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,8,9 };
    ListNode* actual = o.doubleIt(createList(values));
    values = { 3,7,8 };
    check.checkSingleList(createList(values), actual);

    values = { 9,9,9 };
    actual = o.doubleIt(createList(values));
    values = { 1,9,9,8 };
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
