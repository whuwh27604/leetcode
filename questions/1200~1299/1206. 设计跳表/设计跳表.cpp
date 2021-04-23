/* 设计跳表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
不使用任何库函数，设计一个跳表。

跳表是在 O(log(n)) 时间内完成增加、删除、搜索操作的数据结构。跳表相比于树堆与红黑树，其功能与性能相当，并且跳表的代码长度相较下更短，其设计思想与链表相似。

例如，一个跳表包含 [30, 40, 50, 60, 70, 90]，然后增加 80、45 到跳表中，以下图的方式操作：


Artyom Kalinin [CC BY-SA 3.0], via Wikimedia Commons

跳表中有很多层，每一层是一个短的链表。在第一层的作用下，增加、删除和搜索操作的时间复杂度不超过 O(n)。跳表的每一个操作的平均时间复杂度是 O(log(n))，空间复杂度是 O(n)。

在本题中，你的设计应该要包含这些函数：

bool search(int target) : 返回target是否存在于跳表中。
void add(int num): 插入一个元素到跳表。
bool erase(int num): 在跳表中删除一个值，如果 num 不存在，直接返回false. 如果存在多个 num ，删除其中任意一个即可。
了解更多 : https://en.wikipedia.org/wiki/Skip_list

注意，跳表中可能存在多个相同的值，你的代码需要处理这种情况。

样例:

Skiplist skiplist = new Skiplist();

skiplist.add(1);
skiplist.add(2);
skiplist.add(3);
skiplist.search(0);   // 返回 false
skiplist.add(4);
skiplist.search(1);   // 返回 true
skiplist.erase(0);    // 返回 false，0 不在跳表中
skiplist.erase(1);    // 返回 true
skiplist.search(1);   // 返回 false，1 已被擦除
约束条件:

0 <= num, target <= 20000
最多调用 50000 次 search, add, 以及 erase操作。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-skiplist
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Skiplist {
public:
    Skiplist() {
        level = 0;
        maxLevel = 16;  // 大概在log(maxNum/probability)
        probability = RAND_MAX / 4;  // 概率选择0.25
        head = new Node(-1, maxLevel);
    }

    bool search(int num) {
        Node* node = head;

        for (int i = level - 1; i >= 0; --i) {
            while (node->nexts[i] != NULL && num > node->nexts[i]->val) {
                node = node->nexts[i];
            }

            if (node->nexts[i] != NULL && num == node->nexts[i]->val) {
                return true;
            }
        }

        return false;
    }

    void add(int num) {
        int rLevel = randomLevel();
        level = max(level, rLevel);
        Node* cur = new Node(num, rLevel);
        Node* node = head;

        for (int i = level - 1; i >= 0; --i) {
            while (node->nexts[i] != NULL && num > node->nexts[i]->val) {
                node = node->nexts[i];
            }

            if (i < rLevel) {
                Node* next = node->nexts[i];
                node->nexts[i] = cur;
                cur->nexts[i] = next;
            }
        }
    }

    bool erase(int num) {
        Node* node = head;

        for (int i = level - 1; i >= 0; --i) {
            while (node->nexts[i] != NULL && num > node->nexts[i]->val) {
                node = node->nexts[i];
            }

            if (node->nexts[i] != NULL && num == node->nexts[i]->val) {
                Node* del = node->nexts[i];

                for (; i >= 0; --i) {
                    while (node->nexts[i] != del) {
                        node = node->nexts[i];
                    }

                    node->nexts[i] = node->nexts[i]->nexts[i];

                    if (head->nexts[i] == NULL) {
                        level = i;
                    }
                }

                delete del;
                return true;
            }
        }

        return false;
    }

    int randomLevel() {
        int rLevel = 1;

        while (rand() < probability && rLevel < maxLevel) {
            ++rLevel;
        }

        return rLevel;
    }

private:
    struct Node {
        int val;
        vector<Node*> nexts;

        Node(int _val, int _size) : val(_val), nexts(_size) {}
    };

    Node* head;
    int level;
    int maxLevel;
    int probability;
};

int main()
{
    CheckResult check;

    Skiplist o1;
    o1.add(1);
    o1.add(2);
    o1.add(3);
    check.checkBool(false, o1.search(0));
    o1.add(4);
    check.checkBool(true, o1.search(1));
    check.checkBool(false, o1.erase(0));
    check.checkBool(true, o1.erase(1));
    check.checkBool(false, o1.search(1));

    Skiplist o2;
    o2.add(1);
    o2.add(1);
    check.checkBool(true, o2.erase(1));
    check.checkBool(true, o2.search(1));
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
