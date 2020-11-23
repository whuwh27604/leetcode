/* 复制带随机指针的链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的 深拷贝。 

我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：

val：一个表示 Node.val 的整数。
random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
 

示例 1：



输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
示例 2：



输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]
示例 3：



输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]
示例 4：

输入：head = []
输出：[]
解释：给定的链表为空（空指针），因此返回 null。
 

提示：

-10000 <= Node.val <= 10000
Node.random 为空（null）或指向链表中的节点。
节点数目不超过 1000 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/copy-list-with-random-pointer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../header/ListNodeWithRandom.h"
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodePairs;
        Node pseudoHead(0);
        Node* tail = &pseudoHead;

        Node* node = head;
        while (node != NULL) {
            Node* newNode = new Node(node->val);
            tail->next = newNode;
            tail = newNode;
            nodePairs[node] = newNode;
            node = node->next;
        }

        node = head;
        while (node != NULL) {
            if (node->random != NULL) {
                nodePairs[node]->random = nodePairs[node->random];
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

    Node node11(7);
    Node node12(13);
    Node node13(11);
    Node node14(10);
    Node node15(1);
    node11.next = &node12;
    node12.next = &node13;
    node13.next = &node14;
    node14.next = &node15;
    node12.random = &node11;
    node13.random = &node15;
    node14.random = &node13;
    node15.random = &node11;
    Node* actual = o.copyRandomList(&node11);
    check.checkInt(7, actual->val);
    check.checkInt(13, actual->next->val);
    check.checkInt(11, actual->next->next->val);
    check.checkInt(10, actual->next->next->next->val);
    check.checkInt(1, actual->next->next->next->next->val);
    check.checkPoint(NULL, actual->next->next->next->next->next);
    check.checkPoint(NULL, actual->random);
    check.checkInt(7, actual->next->random->val);
    check.checkInt(1, actual->next->next->random->val);
    check.checkInt(11, actual->next->next->next->random->val);
    check.checkInt(7, actual->next->next->next->next->random->val);

    Node node21(1);
    Node node22(2);
    node21.next = &node22;
    node21.random = &node22;
    node22.random = &node22;
    actual = o.copyRandomList(&node21);
    check.checkInt(1, actual->val);
    check.checkInt(2, actual->next->val);
    check.checkPoint(NULL, actual->next->next);
    check.checkInt(2, actual->random->val);
    check.checkInt(2, actual->next->random->val);

    Node node31(3);
    Node node32(3);
    Node node33(3);
    node31.next = &node32;
    node32.next = &node33;
    node32.random = &node31;
    actual = o.copyRandomList(&node31);
    check.checkInt(3, actual->val);
    check.checkInt(3, actual->next->val);
    check.checkInt(3, actual->next->next->val);
    check.checkPoint(NULL, actual->next->next->next);
    check.checkInt(3, actual->next->random->val);

    actual = o.copyRandomList(NULL);
    check.checkPoint(NULL, actual);
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
