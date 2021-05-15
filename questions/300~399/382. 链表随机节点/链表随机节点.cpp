/* 链表随机节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个单链表，随机选择链表的一个节点，并返回相应的节点值。保证每个节点被选的概率一样。

进阶:
如果链表十分大且长度未知，如何解决这个问题？你能否使用常数级空间复杂度实现？

示例:

// 初始化一个单链表 [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom()方法应随机返回1,2,3中的一个，保证每个元素被返回的概率相等。
solution.getRandom();

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-random-node
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <random>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        listHead = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode* node = listHead;
        int value = node->val;
        int count = 0;

        while (node != NULL) {
            if ((rd() % ++count) == 0) {
                value = node->val;
            }

            node = node->next;
        }

        return value;
    }

private:
    ListNode* listHead;
    random_device rd;
};

int main()
{
    //CheckResult check;

    vector<int> values = { 1,2,3,4,5,6,7,8,9,10 };
    Solution o1(createList(values));
    for (int i = 0; i < 100; ++i) {
        cout << o1.getRandom() << " ";
    }
    cout << endl << endl;

    values = { 5 };
    Solution o2(createList(values));
    for (int i = 0; i < 100; ++i) {
        cout << o2.getRandom() << " ";
    }
    cout << endl << endl;

    values = { 5,8 };
    Solution o3(createList(values));
    for (int i = 0; i < 100; ++i) {
        cout << o3.getRandom() << " ";
    }
    cout << endl << endl;
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
