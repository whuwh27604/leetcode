/* 全 O(1) 的数据结构.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请你实现一个数据结构支持以下操作：

Inc(key) - 插入一个新的值为 1 的 key。或者使一个存在的 key 增加一，保证 key 不为空字符串。
Dec(key) - 如果这个 key 的值是 1，那么把他从数据结构中移除掉。否则使一个存在的 key 值减一。如果这个 key 不存在，这个函数不做任何事情。key 保证不为空字符串。
GetMaxKey() - 返回 key 中值最大的任意一个。如果没有元素存在，返回一个空字符串"" 。
GetMinKey() - 返回 key 中值最小的任意一个。如果没有元素存在，返回一个空字符串""。
 

挑战：

你能够以 O(1) 的时间复杂度实现所有操作吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/all-oone-data-structure
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    string key;
    int value;
    Node* prev;
    Node* next;
    Node* up;
    Node* down;

    Node() : key(""), value(0), prev(NULL), next(NULL), up(NULL), down(NULL) {}
    Node(string& _key) : key(_key), value(1), prev(NULL), next(NULL), up(NULL), down(NULL) {}
};

class HList {
public:
    Node pseudoHead;
    Node pseudoTail;

    HList() {
        pseudoHead.next = &pseudoTail;
        pseudoTail.prev = &pseudoHead;
        pseudoTail.value = INT_MAX;
    }

    void insert(Node* prevNode, Node* node, Node* nextNode) {
        if (node->value == prevNode->value) {
            prevNode->prev->next = node;
            node->prev = prevNode->prev;
            node->next = nextNode;
            nextNode->prev = node;
            node->down = prevNode;
            prevNode->up = node;
            prevNode->prev = prevNode->next = NULL;
        }
        else if (node->value == nextNode->value) {  // 相同的要合并，放到当前节点下面
            prevNode->next = node;
            node->prev = prevNode;
            node->next = nextNode->next;
            nextNode->next->prev = node;
            node->down = nextNode;
            nextNode->up = node;
            nextNode->prev = nextNode->next = NULL;  // 纯纵向节点没有前后
        }
        else {
            prevNode->next = node;
            node->prev = prevNode;
            node->next = nextNode;
            nextNode->prev = node;
        }
    }

    void remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        if (node->down == NULL) {  // 这一列只剩这一个节点了，直接删除
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }
        else {  // 这一列还有其它节点，删了首节点第二个顶上来
            prevNode->next = node->down;
            node->down->prev = prevNode;
            node->down->next = nextNode;
            nextNode->prev = node->down;
        }
    }
};

class VList {
public:
    Node pseudoTop;
    Node pseudoBottom;
    int size;

    VList() {
        pseudoTop.down = &pseudoBottom;
        pseudoBottom.up = &pseudoTop;
        size = 0;
    }

    void insert(Node* node) {  // 只能插入在头部
        node->up = &pseudoTop;
        node->down = pseudoTop.down;
        pseudoTop.down->up = node;
        pseudoTop.down = node;
        ++size;
    }

    void remove(Node* node) {
        node->up->down = node->down;
        node->down->up = node->up;
        if (--size == 0) {
            node->up = node->down = NULL;  // 删光之后要置空，因为删除横向的时候会判断纵向还有没有节点
        }
    }
};

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (keyNodes.count(key) == 0) {
            Node* node = new Node(key);
            keyNodes[key] = node;
            insert(&hlist.pseudoHead, node, hlist.pseudoHead.next);  // 新的节点肯定插入在pseudoHead后面
        }
        else {
            Node* node = keyNodes[key];
            Node* prev = valueLists[node->value].pseudoTop.down->prev;
            Node* next = valueLists[node->value].pseudoTop.down->next;
            remove(node);  // 先删除这个节点
            ++node->value;
            if (node->down == NULL) {  // 原来那一列已经没有了
                insert(prev, node, next);
            }
            else {
                insert(valueLists[node->value - 1].pseudoTop.down, node, next);
            }
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (keyNodes.count(key) == 0) {
            return;
        }

        Node* node = keyNodes[key];
        Node* prev = valueLists[node->value].pseudoTop.down->prev;
        Node* next = valueLists[node->value].pseudoTop.down->next;
        remove(node);  // 先删除这个节点
        if (--node->value == 0) {  // 减为0了就彻底干掉
            keyNodes.erase(key);
            delete node;
        }
        else {  // 计数减1后再重新插入
            if (node->down == NULL) {  // 原来那一列已经没有了
                insert(prev, node, next);
            }
            else {
                insert(prev, node, valueLists[node->value + 1].pseudoTop.down);
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return hlist.pseudoHead.next == &hlist.pseudoTail ?  "" : hlist.pseudoTail.prev->key;
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return hlist.pseudoHead.next == &hlist.pseudoTail ? "" : hlist.pseudoHead.next->key;
    }

    void remove(Node* node) {
        VList& vlist = valueLists[node->value];
        vlist.remove(node);  // 先从纵向队列删除

        if (vlist.size == 0) {
            valueLists.erase(node->value);
        }

        if (node->prev != NULL) {
            hlist.remove(node);  // 再从横向队列删除
        }
    }

    void insert(Node* prev, Node* node, Node* next) {
        valueLists[node->value].insert(node);
        hlist.insert(prev, node, next);
    }

private:
    unordered_map<string, Node*> keyNodes;
    unordered_map<int, VList> valueLists;
    HList hlist;
};

int main()
{
    CheckResult check;

    AllOne o1;
    check.checkString("", o1.getMaxKey());
    check.checkString("", o1.getMinKey());
    o1.inc("a");
    check.checkString("a", o1.getMaxKey());
    check.checkString("a", o1.getMinKey());
    o1.inc("a");
    check.checkString("a", o1.getMaxKey());
    check.checkString("a", o1.getMinKey());
    o1.inc("b");
    check.checkString("a", o1.getMaxKey());
    check.checkString("b", o1.getMinKey());

    AllOne o2;
    o2.inc("a");
    o2.inc("b");
    o2.inc("b");
    o2.inc("c");
    o2.inc("c");
    o2.inc("c");
    o2.dec("b");
    o2.dec("b");
    check.checkString("a", o2.getMinKey());
    o2.dec("a");
    check.checkString("c", o2.getMaxKey());
    check.checkString("c", o2.getMinKey());
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
