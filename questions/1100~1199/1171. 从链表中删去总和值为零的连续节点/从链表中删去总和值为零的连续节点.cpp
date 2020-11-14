/* 从链表中删去总和值为零的连续节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。

删除完毕后，请你返回最终结果链表的头节点。

 

你可以返回任何满足题目要求的答案。

（注意，下面示例中的所有序列，都是对 ListNode 对象序列化的表示。）

示例 1：

输入：head = [1,2,-3,3,1]
输出：[3,1]
提示：答案 [1,2,1] 也是正确的。
示例 2：

输入：head = [1,2,3,-3,4]
输出：[1,2,4]
示例 3：

输入：head = [1,2,3,-3,-2]
输出：[1]
 

提示：

给你的链表中可能有 1 到 1000 个节点。
对于链表中的每个节点，节点的值：-1000 <= node.val <= 1000.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode pseudoHead(0);
        pseudoHead.next = head;
        unordered_map<int, ListNode*> preSum = { {0,&pseudoHead} };
        int sum = 0;
        ListNode* node = head;

        while (node != NULL) {
            sum += node->val;

            if (preSum.count(sum) == 0) {
                preSum[sum] = node;
            }
            else {
                int tmpSum = sum;
                ListNode* deleteNode = preSum[sum]->next;

                while (deleteNode != node) {
                    tmpSum += deleteNode->val;
                    preSum.erase(tmpSum);
                    deleteNode = deleteNode->next;
                }

                preSum[sum]->next = node->next;
            }

            node = node->next;
        }

        return pseudoHead.next;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 1,2,-3,3,1 };
    ListNode* actual = o.removeZeroSumSublists(createList(values));
    values = { 3,1 };
    ListNode* expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 1,0,2 };
    actual = o.removeZeroSumSublists(createList(values));
    values = { 1,2 };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 1,2,3,-3,4 };
    actual = o.removeZeroSumSublists(createList(values));
    values = { 1,2,4 };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 1,2,3,-3,-2 };
    actual = o.removeZeroSumSublists(createList(values));
    values = { 1 };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 0 };
    actual = o.removeZeroSumSublists(createList(values));
    values = {  };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 0,0 };
    actual = o.removeZeroSumSublists(createList(values));
    values = {  };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 1,0 };
    actual = o.removeZeroSumSublists(createList(values));
    values = { 1 };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 0,2 };
    actual = o.removeZeroSumSublists(createList(values));
    values = { 2 };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 1,2,4,-6 };
    actual = o.removeZeroSumSublists(createList(values));
    values = { 1 };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 1,2,4,-7 };
    actual = o.removeZeroSumSublists(createList(values));
    values = {  };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 1,2,3,-1,-2,-3,3 };
    actual = o.removeZeroSumSublists(createList(values));
    values = { 3 };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 1 };
    actual = o.removeZeroSumSublists(createList(values));
    values = { 1 };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 1,2,1,-2,0,0 };
    actual = o.removeZeroSumSublists(createList(values));
    values = { 1,2,1,-2 };
    expected = createList(values);
    check.checkSingleList(expected, actual);

    values = { 5,-2,7,6,-7,6,-10,2,0,-1,10,-7,8,7,-8,-2,-10,-2,9,3,0,-1,2,2,-3,7,-7,-9,8,5,0,1,1,-3,-10,-3,6,-7,4,2,8 };
    actual = o.removeZeroSumSublists(createList(values));
    values = { 5,8,5,1,1,-3 };
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
