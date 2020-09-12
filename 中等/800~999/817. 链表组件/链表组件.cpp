/* 链表组件.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定链表头结点 head，该链表上的每个结点都有一个 唯一的整型值 。

同时给定列表 G，该列表是上述链表中整型值的一个子集。

返回列表 G 中组件的个数，这里对组件的定义为：链表中一段最长连续结点的值（该值必须在列表 G 中）构成的集合。

 

示例 1：

输入:
head: 0->1->2->3
G = [0, 1, 3]
输出: 2
解释:
链表中,0 和 1 是相连接的，且 G 中不包含 2，所以 [0, 1] 是 G 的一个组件，同理 [3] 也是一个组件，故返回 2。
示例 2：

输入:
head: 0->1->2->3->4
G = [0, 3, 1, 4]
输出: 2
解释:
链表中，0 和 1 是相连接的，3 和 4 是相连接的，所以 [0, 1] 和 [3, 4] 是两个组件，故返回 2。
 

提示：

如果 N 是给定链表 head 的长度，1 <= N <= 10000。
链表中每个结点的值所在范围为 [0, N - 1]。
1 <= G.length <= 10000
G 是链表中所有结点的值的一个子集.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-components
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_set>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> Gs;
        hashG(G, Gs);

        bool start = false;
        int components = 0;
        ListNode* node = head;

        while (node != NULL) {
            if (Gs.count(node->val) != 0) {
                start = true;
            }
            else {
                if (start == true) {
                    components++;
                }

                start = false;
            }

            node = node->next;
        }

        return start ? components + 1 : components;
    }

    void hashG(vector<int>& G, unordered_set<int>& Gs) {
        for (int num : G) {
            Gs.insert(num);
        }
    }
};

int main()
{
    Solution o;
    CheckResult check;

    ListNode node0(0);
    vector<int> G = { 0 };
    check.checkInt(1, o.numComponents(&node0, G));

    G = { 1 };
    check.checkInt(0, o.numComponents(&node0, G));

    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    node0.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    G = { 0,1,3 };
    check.checkInt(2, o.numComponents(&node1, G));

    ListNode node4(4);
    node3.next = &node4;
    G = { 0,3,1,4 };
    check.checkInt(2, o.numComponents(&node1, G));
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
