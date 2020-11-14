/* 链表中的下一个更大节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出一个以头节点 head 作为第一个节点的链表。链表中的节点分别编号为：node_1, node_2, node_3, ... 。

每个节点都可能有下一个更大值（next larger value）：对于 node_i，如果其 next_larger(node_i) 是 node_j.val，那么就有 j > i 且  node_j.val > node_i.val，而 j 是可能的选项中最小的那个。如果不存在这样的 j，那么下一个更大值为 0 。

返回整数答案数组 answer，其中 answer[i] = next_larger(node_{i+1}) 。

注意：在下面的示例中，诸如 [2,1,5] 这样的输入（不是输出）是链表的序列化表示，其头节点的值为 2，第二个节点值为 1，第三个节点值为 5 。

 

示例 1：

输入：[2,1,5]
输出：[5,5,0]
示例 2：

输入：[2,7,4,3,5]
输出：[7,0,5,5,0]
示例 3：

输入：[1,7,5,1,9,2,5,1]
输出：[7,9,9,9,0,5,0,0]
 

提示：

对于链表中的每个节点，1 <= node.val <= 10^9
给定列表的长度在 [0, 10000] 范围内

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/next-greater-node-in-linked-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> largers(countNodes(head), 0);
        stack<pair<int, int>> lessNums;
        lessNums.push({ INT_MAX,0 });
        int index = 0;

        while (head != NULL) {
            while (head->val > lessNums.top().first) {
                largers[lessNums.top().second] = head->val;
                lessNums.pop();
            }

            lessNums.push({ head->val, index++ });
            head = head->next;
        }

        while (lessNums.top().first != INT_MAX) {
            largers[lessNums.top().second] = 0;
            lessNums.pop();
        }

        return largers;
    }

    int countNodes(ListNode* head) {
        int count = 0;

        while (head != NULL) {
            head = head->next;
            ++count;
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 2,1,5 };
    vector<int> actual = o.nextLargerNodes(createList(values));
    vector<int> expected = { 5,5,0 };
    check.checkIntVector(expected, actual);

    values = { 2,7,4,3,5 };
    actual = o.nextLargerNodes(createList(values));
    expected = { 7,0,5,5,0 };
    check.checkIntVector(expected, actual);

    values = { 1,7,5,1,9,2,5,1 };
    actual = o.nextLargerNodes(createList(values));
    expected = { 7,9,9,9,0,5,0,0 };
    check.checkIntVector(expected, actual);

    values = {  };
    actual = o.nextLargerNodes(createList(values));
    expected = {  };
    check.checkIntVector(expected, actual);

    values = { 5 };
    actual = o.nextLargerNodes(createList(values));
    expected = { 0 };
    check.checkIntVector(expected, actual);

    values = { 5,6 };
    actual = o.nextLargerNodes(createList(values));
    expected = { 6,0 };
    check.checkIntVector(expected, actual);

    values = { 6,5 };
    actual = o.nextLargerNodes(createList(values));
    expected = { 0,0 };
    check.checkIntVector(expected, actual);

    values = { 5,5 };
    actual = o.nextLargerNodes(createList(values));
    expected = { 0,0 };
    check.checkIntVector(expected, actual);
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
