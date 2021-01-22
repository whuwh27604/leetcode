/* 链表的中间结点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个带有头结点 head 的非空单链表，返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。

 

示例 1：

输入：[1,2,3,4,5]
输出：此列表中的结点 3 (序列化形式：[3,4,5])
返回的结点值为 3 。 (测评系统对该结点序列化表述是 [3,4,5])。
注意，我们返回了一个 ListNode 类型的对象 ans，这样：
ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.
示例 2：

输入：[1,2,3,4,5,6]
输出：此列表中的结点 4 (序列化形式：[4,5,6])
由于该列表有两个中间结点，值分别为 3 和 4，我们返回第二个结点。
 

提示：

给定链表的结点数介于 1 和 100 之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/middle-of-the-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../header/ListNode.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head->next == NULL) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while ((fast->next != NULL) && (fast->next->next != NULL)) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow->next;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<int> values = { 1,2,3,4,5 };
    check.checkInt(3, o.middleNode(createList(values))->val);

    values = { 1,2,3,4,5,6 };
    check.checkInt(4, o.middleNode(createList(values))->val);

    values = { 1,2 };
    check.checkInt(2, o.middleNode(createList(values))->val);

    values = { 1,2,3 };
    check.checkInt(2, o.middleNode(createList(values))->val);
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
