/* 找出临界点之间的最小和最大距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
链表中的 临界点 定义为一个 局部极大值点 或 局部极小值点 。

如果当前节点的值 严格大于 前一个节点和后一个节点，那么这个节点就是一个  局部极大值点 。

如果当前节点的值 严格小于 前一个节点和后一个节点，那么这个节点就是一个  局部极小值点 。

注意：节点只有在同时存在前一个节点和后一个节点的情况下，才能成为一个 局部极大值点 / 极小值点 。

给你一个链表 head ，返回一个长度为 2 的数组 [minDistance, maxDistance] ，其中 minDistance 是任意两个不同临界点之间的最小距离，maxDistance 是任意两个不同临界点之间的最大距离。如果临界点少于两个，则返回 [-1，-1] 。

 

示例 1：



输入：head = [3,1]
输出：[-1,-1]
解释：链表 [3,1] 中不存在临界点。
示例 2：



输入：head = [5,3,1,2,5,1,2]
输出：[1,3]
解释：存在三个临界点：
- [5,3,1,2,5,1,2]：第三个节点是一个局部极小值点，因为 1 比 3 和 2 小。
- [5,3,1,2,5,1,2]：第五个节点是一个局部极大值点，因为 5 比 2 和 1 大。
- [5,3,1,2,5,1,2]：第六个节点是一个局部极小值点，因为 1 比 5 和 2 小。
第五个节点和第六个节点之间距离最小。minDistance = 6 - 5 = 1 。
第三个节点和第六个节点之间距离最大。maxDistance = 6 - 3 = 3 。
示例 3：



输入：head = [1,3,2,2,3,2,2,2,7]
输出：[3,3]
解释：存在两个临界点：
- [1,3,2,2,3,2,2,2,7]：第二个节点是一个局部极大值点，因为 3 比 1 和 2 大。
- [1,3,2,2,3,2,2,2,7]：第五个节点是一个局部极大值点，因为 3 比 2 和 2 大。
最小和最大距离都存在于第二个节点和第五个节点之间。
因此，minDistance 和 maxDistance 是 5 - 2 = 3 。
注意，最后一个节点不算一个局部极大值点，因为它之后就没有节点了。
示例 4：



输入：head = [2,3,3,2]
输出：[-1,-1]
解释：链表 [2,3,3,2] 中不存在临界点。
 

提示：

链表中节点的数量在范围 [2, 105] 内
1 <= Node.val <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, last = -1, minDist = INT_MAX, index = 1;
        ListNode* prev = head;
        ListNode* current = head->next;

        while (current->next != NULL) {
            if ((current->val > prev->val && current->val > current->next->val)
                || (current->val < prev->val && current->val < current->next->val)) {
                if (first == -1) {
                    first = index;
                    last = index;
                }
                else {
                    minDist = min(minDist, index - last);
                    last = index;
                }
            }

            prev = current;
            current = current->next;
            ++index;
        }

        if (first == last) {
            return { -1,-1 };
        }
        else {
            return { minDist, last - first };
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> values = { 3,1 };
    vector<int> actual = o.nodesBetweenCriticalPoints(createList(values));
    vector<int> expected = { -1,-1 };
    check.checkIntVector(expected, actual);

    values = { 5,3,1,2,5,1,2 };
    actual = o.nodesBetweenCriticalPoints(createList(values));
    expected = { 1,3 };
    check.checkIntVector(expected, actual);

    values = { 1,3,2,2,3,2,2,2,7 };
    actual = o.nodesBetweenCriticalPoints(createList(values));
    expected = { 3,3 };
    check.checkIntVector(expected, actual);

    values = { 2,3,3,2 };
    actual = o.nodesBetweenCriticalPoints(createList(values));
    expected = { -1,-1 };
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
