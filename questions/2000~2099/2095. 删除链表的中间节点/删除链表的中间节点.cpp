/* 删除链表的中间节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个链表的头节点 head 。删除 链表的 中间节点 ，并返回修改后的链表的头节点 head 。

长度为 n 链表的中间节点是从头数起第 ⌊n / 2⌋ 个节点（下标从 0 开始），其中 ⌊x⌋ 表示小于或等于 x 的最大整数。

对于 n = 1、2、3、4 和 5 的情况，中间节点的下标分别是 0、1、1、2 和 2 。
 

示例 1：



输入：head = [1,3,4,7,1,2,6]
输出：[1,3,4,1,2,6]
解释：
上图表示给出的链表。节点的下标分别标注在每个节点的下方。
由于 n = 7 ，值为 7 的节点 3 是中间节点，用红色标注。
返回结果为移除节点后的新链表。
示例 2：



输入：head = [1,2,3,4]
输出：[1,2,4]
解释：
上图表示给出的链表。
对于 n = 4 ，值为 3 的节点 2 是中间节点，用红色标注。
示例 3：



输入：head = [2,1]
输出：[2]
解释：
上图表示给出的链表。
对于 n = 2 ，值为 1 的节点 1 是中间节点，用红色标注。
值为 2 的节点 0 是移除节点 1 后剩下的唯一一个节点。
 

提示：

链表中节点的数目在范围 [1, 105] 内
1 <= Node.val <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-the-middle-node-of-a-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int count = 1;
        ListNode* fast = head->next;
        ListNode* slow = head;
        ListNode* prev = NULL;

        while (fast != NULL) {
            fast = fast->next;
            ++count;

            if (fast != NULL) {
                fast = fast->next;
                ++count;
                prev = slow;
                slow = slow->next;
            }
        }

        if ((count & 1) == 0) {
            slow->next = slow->next->next;  // 偶数个，slow在中间节点的前一个位置
        }
        else {  // 奇数个，slow就是中间节点
            if (prev == NULL) {  // 只有一个节点，删除后变空链表
                head = NULL;
            }
            else {
                prev->next = slow->next;
            }
        }

        return head;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,3,4,7,1,2,6 };
    ListNode* actual = o.deleteMiddle(createList(values));
    values = { 1,3,4,1,2,6 };
    ListNode* expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 1 };
    actual = o.deleteMiddle(createList(values));
    values = {  };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 1,2 };
    actual = o.deleteMiddle(createList(values));
    values = { 1 };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 1,2,3 };
    actual = o.deleteMiddle(createList(values));
    values = { 1,3 };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 1,2,3,4 };
    actual = o.deleteMiddle(createList(values));
    values = { 1,2,4 };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 1,2,3,4,5 };
    actual = o.deleteMiddle(createList(values));
    values = { 1,2,4,5 };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 1,2,3,4,5,6 };
    actual = o.deleteMiddle(createList(values));
    values = { 1,2,3,5,6 };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 1,2,3,4,5,6,7 };
    actual = o.deleteMiddle(createList(values));
    values = { 1,2,3,5,6,7 };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 1,2,3,4,5,6,7,8 };
    actual = o.deleteMiddle(createList(values));
    values = { 1,2,3,4,6,7,8 };
    expected = createList(values);
    check.checkSingleList(expected, actual);
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
