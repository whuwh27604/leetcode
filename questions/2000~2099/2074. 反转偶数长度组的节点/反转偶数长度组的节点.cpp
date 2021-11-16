/* 反转偶数长度组的节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个链表的头节点 head 。

链表中的节点 按顺序 划分成若干 非空 组，这些非空组的长度构成一个自然数序列（1, 2, 3, 4, ...）。一个组的 长度 就是组中分配到的节点数目。换句话说：

节点 1 分配给第一组
节点 2 和 3 分配给第二组
节点 4、5 和 6 分配给第三组，以此类推
注意，最后一组的长度可能小于或者等于 1 + 倒数第二组的长度 。

反转 每个 偶数 长度组中的节点，并返回修改后链表的头节点 head 。

 

示例 1：



输入：head = [5,2,6,3,9,1,7,3,8,4]
输出：[5,6,2,3,9,1,4,8,3,7]
解释：
- 第一组长度为 1 ，奇数，没有发生反转。
- 第二组长度为 2 ，偶数，节点反转。
- 第三组长度为 3 ，奇数，没有发生反转。
- 最后一组长度为 4 ，偶数，节点反转。
示例 2：



输入：head = [1,1,0,6]
输出：[1,0,1,6]
解释：
- 第一组长度为 1 ，没有发生反转。
- 第二组长度为 2 ，节点反转。
- 最后一组长度为 1 ，没有发生反转。
示例 3：



输入：head = [2,1]
输出：[2,1]
解释：
- 第一组长度为 1 ，没有发生反转。
- 最后一组长度为 1 ，没有发生反转。
示例 4：

输入：head = [8]
输出：[8]
解释：只有一个长度为 1 的组，没有发生反转。
 

提示：

链表中节点数目范围是 [1, 105]
0 <= Node.val <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-nodes-in-even-length-groups
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../tools/TestData.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* current = head;
        vector<int> values;

        while (current != NULL) {
            values.push_back(current->val);
            current = current->next;
        }

        int i = 0, size = values.size(), group = 1;

        while (i < size) {
            int first = i, last = i + group - 1 < size ? i + group - 1 : size - 1;

            if (((last - first + 1) & 1) == 0) {
                while (first < last) {
                    swap(values[first++], values[last--]);
                }
            }

            i += group;
            ++group;
        }

        i = 0;
        current = head;

        while (current != NULL) {
            current->val = values[i++];
            current = current->next;
        }

        return head;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 5,2,6,3,9,1,7,3,8,4 };
    ListNode* actual = o.reverseEvenLengthGroups(createList(values));
    values = { 5,6,2,3,9,1,4,8,3,7 };
    check.checkSingleList(createList(values), actual);

    values = { 5,2,6 };
    actual = o.reverseEvenLengthGroups(createList(values));
    values = { 5,6,2 };
    check.checkSingleList(createList(values), actual);

    values = { 5,2,6,3 };
    actual = o.reverseEvenLengthGroups(createList(values));
    values = { 5,6,2,3 };
    check.checkSingleList(createList(values), actual);

    values = { 5,2,6,3,9 };
    actual = o.reverseEvenLengthGroups(createList(values));
    values = { 5,6,2,9,3 };
    check.checkSingleList(createList(values), actual);

    values = { 5,2,6,3,9,1 };
    actual = o.reverseEvenLengthGroups(createList(values));
    values = { 5,6,2,3,9,1 };
    check.checkSingleList(createList(values), actual);

    values = { 5,2,6,3,9,1,7 };
    actual = o.reverseEvenLengthGroups(createList(values));
    values = { 5,6,2,3,9,1,7 };
    check.checkSingleList(createList(values), actual);

    values = { 5,2,6,3,9,1,7,3 };
    actual = o.reverseEvenLengthGroups(createList(values));
    values = { 5,6,2,3,9,1,3,7 };
    check.checkSingleList(createList(values), actual);

    values = { 5,2,6,3,9,1,7,3,8 };
    actual = o.reverseEvenLengthGroups(createList(values));
    values = { 5,6,2,3,9,1,7,3,8 };
    check.checkSingleList(createList(values), actual);

    values = { 5,2,6,3,9,1,7,3,8,4,11 };
    actual = o.reverseEvenLengthGroups(createList(values));
    values = { 5,6,2,3,9,1,4,8,3,7,11 };
    check.checkSingleList(createList(values), actual);

    values = { 1,1,0,6 };
    actual = o.reverseEvenLengthGroups(createList(values));
    values = { 1,0,1,6 };
    check.checkSingleList(createList(values), actual);

    values = { 2,1 };
    actual = o.reverseEvenLengthGroups(createList(values));
    values = { 2,1 };
    check.checkSingleList(createList(values), actual);

    values = { 8 };
    actual = o.reverseEvenLengthGroups(createList(values));
    values = { 8 };
    check.checkSingleList(createList(values), actual);

    values = { 0,4,2,1,3 };
    actual = o.reverseEvenLengthGroups(createList(values));
    values = { 0,2,4,3,1 };
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
