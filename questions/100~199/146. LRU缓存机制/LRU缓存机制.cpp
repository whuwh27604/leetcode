/* LRU缓存机制.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。

获取数据 get(key) - 如果关键字 (key) 存在于缓存中，则获取关键字的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字/值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

 

进阶:

你是否可以在 O(1) 时间复杂度内完成这两种操作？

 

示例:

LRUCache cache = new LRUCache( 2 /* 缓存容量 * / );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得关键字 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得关键字 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/lru-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int _key, int _val) : key(_key), val(_val), prev(NULL), next(NULL) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        pseudoHead = new Node(0, 0);
        pseudoTail = new Node(0, 0);
        pseudoHead->next = pseudoTail;
        pseudoTail->prev = pseudoHead;
    }

    ~LRUCache() {
        while (pseudoHead != NULL) {
            Node* tmp = pseudoHead;
            pseudoHead = pseudoHead->next;
            delete tmp;
        }
    }

    int get(int key) {
        auto iter = data.find(key);
        if (iter == data.end()) {
            return -1;
        }

        Node* node = iter->second;
        removeNode(node);
        insertHead(node);

        return node->val;
    }

    void put(int key, int value) {
        auto iter = data.find(key);
        if (iter == data.end()) {
            Node* node = new Node(key, value);
            insertHead(node);
            data[key] = node;

            if ((int)data.size() > cap) {
                deleteTail();
            }
        }
        else {
            Node* node = iter->second;
            node->val = value;
            removeNode(node);
            insertHead(node);
        }
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertHead(Node* head) {
        head->prev = pseudoHead;
        head->next = pseudoHead->next;
        pseudoHead->next->prev = head;
        pseudoHead->next = head;
    }

    void deleteTail() {
        Node* tail = pseudoTail->prev;
        data.erase(tail->key);
        removeNode(tail);
        delete tail;
    }

    unordered_map<int, Node*> data;
    Node* pseudoHead;
    Node* pseudoTail;
    int cap;
};

int main()
{
    LRUCache o(2);
    CheckResult check;

    check.checkInt(-1, o.get(0));
    o.put(1, 1);
    o.put(2, 2);
    check.checkInt(1, o.get(1));
    o.put(3, 3);
    check.checkInt(3, o.get(3));
    check.checkInt(-1, o.get(2));
    o.put(4, 4);
    check.checkInt(-1, o.get(1));
    check.checkInt(3, o.get(3));
    check.checkInt(4, o.get(4));
    o.put(4, -4);
    check.checkInt(-4, o.get(4));

    LRUCache o1(0);
    check.checkInt(-1, o1.get(0));
    o1.put(1, 1);
    check.checkInt(-1, o1.get(1));
    o1.put(2, 2);
    o1.put(3, 3);
    check.checkInt(-1, o1.get(2));
    check.checkInt(-1, o1.get(3));

    LRUCache o2(1);
    check.checkInt(-1, o2.get(0));
    o2.put(1, 1);
    check.checkInt(1, o2.get(1));
    check.checkInt(1, o2.get(1));
    o2.put(2, 2);
    check.checkInt(-1, o2.get(1));
    check.checkInt(2, o2.get(2));
    o2.put(3, 3);
    check.checkInt(-1, o2.get(2));
    check.checkInt(3, o2.get(3));
    o2.put(3, 4);
    check.checkInt(-1, o2.get(1));
    check.checkInt(-1, o2.get(2));
    check.checkInt(4, o2.get(3));
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
