/* LFU 缓存.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。

实现 LFUCache 类：

LFUCache(int capacity) - 用数据结构的容量 capacity 初始化对象
int get(int key) - 如果键存在于缓存中，则获取键的值，否则返回 -1。
void put(int key, int value) - 如果键已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量时，则应该在插入新项之前，使最不经常使用的项无效。在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除 最久未使用 的键。
注意「项的使用次数」就是自插入该项以来对其调用 get 和 put 函数的次数之和。使用次数会在对应项被移除后置为 0 。

为了确定最不常使用的键，可以为缓存中的每个键维护一个 使用计数器 。使用计数最小的键是最久未使用的键。

当一个键首次插入到缓存中时，它的使用计数器被设置为 1 (由于 put 操作)。对缓存中的键执行 get 或 put 操作，使用计数器的值将会递增。

 

示例：

输入：
["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
输出：
[null, null, null, 1, null, -1, 3, null, -1, 3, 4]

解释：
// cnt(x) = 键 x 的使用计数
// cache=[] 将显示最后一次使用的顺序（最左边的元素是最近的）
LFUCache lFUCache = new LFUCache(2);
lFUCache.put(1, 1);   // cache=[1,_], cnt(1)=1
lFUCache.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
lFUCache.get(1);      // 返回 1
                      // cache=[1,2], cnt(2)=1, cnt(1)=2
lFUCache.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
                      // cache=[3,1], cnt(3)=1, cnt(1)=2
lFUCache.get(2);      // 返回 -1（未找到）
lFUCache.get(3);      // 返回 3
                      // cache=[3,1], cnt(3)=2, cnt(1)=2
lFUCache.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
                      // cache=[4,3], cnt(4)=1, cnt(3)=2
lFUCache.get(1);      // 返回 -1（未找到）
lFUCache.get(3);      // 返回 3
                      // cache=[3,4], cnt(4)=1, cnt(3)=3
lFUCache.get(4);      // 返回 4
                      // cache=[3,4], cnt(4)=2, cnt(3)=3
 

提示：

0 <= capacity, key, value <= 104
最多调用 105 次 get 和 put 方法
 

进阶：你可以为这两种操作设计时间复杂度为 O(1) 的实现吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/lfu-cache
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int key;
    int value;
    int counter;
    Node* prev;
    Node* next;
    Node* up;
    Node* down;

    Node() : key(0), value(0), counter(0), prev(NULL), next(NULL), up(NULL), down(NULL) {}
    Node(int _key, int _val) : key(_key), value(_val), counter(1), prev(NULL), next(NULL), up(NULL), down(NULL) {}
};

class HList {
public:
    Node pseudoHead;
    Node pseudoTail;

    HList() {
        pseudoHead.next = &pseudoTail;
        pseudoTail.prev = &pseudoHead;
        pseudoTail.counter = INT_MAX;
    }
    
    void insert(Node* prevNode, Node* node, Node* nextNode) {
        prevNode->next = node;
        node->prev = prevNode;

        if (node->counter == nextNode->counter) {  // 相同的要合并，后面一列放到当前节点下面
            node->next = nextNode->next;
            nextNode->next->prev = node;
            node->down = nextNode;
            nextNode->up = node;
            nextNode->prev = nextNode->next = NULL;  // 纯纵向节点没有前后
        }
        else {
            node->next = nextNode;
            nextNode->prev = node;
        }
    }

    Node* remove(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        if (node->down == NULL) {  // 这一列只剩这一个节点了，直接删除
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            return prevNode;
        }
        else {  // 这一列还有其它节点，删了首节点第二个顶上来
            prevNode->next = node->down;
            node->down->prev = prevNode;
            node->down->next = nextNode;
            nextNode->prev = node->down;
            return node->down;
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

class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    int get(int key) {
        if (keyNodes.count(key) == 0) {
            return -1;
        }

        Node* node = keyNodes[key];
        Node* next = counterList[node->counter].pseudoTop.down->next;
        Node* prev = remove(node);  // 先删除这个节点
        ++node->counter;
        insert(prev, node, next);  // 计数加1后再重新插入

        return node->value;
    }

    void put(int key, int value) {
        if (cap == 0) {
            return;
        }

        if (keyNodes.count(key) != 0) {  // 已经存在的节点，更新value和counter
            Node* node = keyNodes[key];
            Node* next = counterList[node->counter].pseudoTop.down->next;
            Node* prev = remove(node);
            ++node->counter;
            node->value = value;
            insert(prev, node, next);
        }
        else {
            if (++size > cap) {  // 如果容量超限，先把最后一个干掉
                size = cap;
                Node* leastCounter = counterList[hlist.pseudoHead.next->counter].pseudoBottom.up;  // 链表第一个的最下面一个
                keyNodes.erase(leastCounter->key);
                (void)remove(leastCounter);
                delete leastCounter;
            }

            Node* node = new Node(key, value);
            keyNodes[key] = node;
            insert(&hlist.pseudoHead, node, hlist.pseudoHead.next);  // 新的节点肯定插入在pseudoHead后面
        }
    }

    Node* remove(Node* node) {
        VList& vlist = counterList[node->counter];
        vlist.remove(node);  // 先从纵向队列删除

        if (vlist.size == 0) {
            counterList.erase(node->counter);
        }

        if (node->prev != NULL) {
            return hlist.remove(node);  // 再从横向队列删除
        }

        return counterList[node->counter].pseudoTop.down;  // 如果仅仅只是纵向节点，返回这一列的第一个节点
    }

    void insert(Node* prev, Node* node, Node* next) {
        counterList[node->counter].insert(node);
        hlist.insert(prev, node, next);
    }

private:
    unordered_map<int, Node*> keyNodes;
    unordered_map<int, VList> counterList;
    HList hlist;
    int cap;
    int size;
};

int main()
{
    CheckResult check;

    LFUCache o1(2);
    o1.put(1, 1);
    o1.put(2, 2);
    check.checkInt(1, o1.get(1));
    o1.put(3, 3);
    check.checkInt(-1, o1.get(2));
    check.checkInt(3, o1.get(3));
    o1.put(4, 4);
    check.checkInt(-1, o1.get(1));
    check.checkInt(3, o1.get(3));
    check.checkInt(4, o1.get(4));

    LFUCache o2(2);
    o2.put(3, 1);
    o2.put(2, 1);
    o2.put(2, 2);
    o2.put(4, 4);
    check.checkInt(2, o2.get(2));

    LFUCache o3(0);
    o3.put(1, 1);
    check.checkInt(-1, o3.get(1));
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
