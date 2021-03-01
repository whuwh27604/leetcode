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

class CrossNode {
public:
    int key;
    int value;
    int counter;
    CrossNode* prev;
    CrossNode* next;
    CrossNode* up;
    CrossNode* down;

    CrossNode() : key(0), value(0), counter(0), prev(NULL), next(NULL), up(NULL), down(NULL) {}
    CrossNode(int _key, int _val) : key(_key), value(_val), counter(1), prev(NULL), next(NULL), up(NULL), down(NULL) {}

    bool isVNode() {
        return prev == NULL;
    }
};

class HList {
public:
    HList() {
        pseudoHead.next = &pseudoTail;
        pseudoTail.prev = &pseudoHead;
        pseudoHead.counter = INT_MIN;
        pseudoTail.counter = INT_MAX;
    }

    CrossNode* front() {
        return pseudoHead.next;
    }

    CrossNode* back() {
        return pseudoTail.prev;
    }

    void insertAfter(CrossNode* after, CrossNode* node) {
        node->prev = after;
        node->next = after->next;
        after->next->prev = node;
        after->next = node;
    }

    void insertBefore(CrossNode* before, CrossNode* node) {
        node->prev = before->prev;
        node->next = before;
        before->prev->next = node;
        before->prev = node;
    }

    void remove(CrossNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

private:
    CrossNode pseudoHead;
    CrossNode pseudoTail;
};

class VList {
public:
    VList() {
        pseudoTop.down = &pseudoBottom;
        pseudoBottom.up = &pseudoTop;
    }

    CrossNode* top() {
        return pseudoTop.down;
    }

    CrossNode* bottom() {
        return pseudoBottom.up;
    }

    void pushTop(CrossNode* node) {
        node->up = &pseudoTop;
        node->down = pseudoTop.down;
        pseudoTop.down->up = node;
        pseudoTop.down = node;
        node->down->prev = node->down->next = NULL;  // 插入新的top后，原来的top变为一个纵向节点，不再是十字节点
    }

    void remove(CrossNode* node) {
        node->up->down = node->down;
        node->down->up = node->up;
    }

    bool empty() {
        return pseudoTop.down == &pseudoBottom;
    }

private:
    CrossNode pseudoTop;
    CrossNode pseudoBottom;
};

class CrossList {
public:
    CrossNode* front() {
        return hlist.front();
    }

    CrossNode* back() {
        return hlist.back();
    }

    CrossNode* prev(CrossNode* node) {
        return vlists[node->counter].top()->prev;
    }

    CrossNode* next(CrossNode* node) {
        return vlists[node->counter].top()->next;
    }

    CrossNode* minCounter() {
        return vlists[hlist.front()->counter].bottom();  // 链表第一个的最下面一个
    }

    void pushFront(CrossNode* node) {
        insertBefore(hlist.front(), node);  // 插入到首节点前面，因为它们的counter有可能相等
    }

    void insertAfter(CrossNode* after, CrossNode* node) {
        if (after->counter == node->counter) {  // 如果插入的位置counter相等，合并它们到纵向队列
            CrossNode* prev = after->prev;
            hlist.remove(after);  // 删除原来的十字节点
            hlist.insertAfter(prev, node);  // 新插入的节点做为新的十字节点
        }
        else {
            hlist.insertAfter(after, node);
        }

        vlists[node->counter].pushTop(node);
    }

    void insertBefore(CrossNode* before, CrossNode* node) {
        if (before->counter == node->counter) {
            CrossNode* next = before->next;
            hlist.remove(before);
            hlist.insertBefore(next, node);
        }
        else {
            hlist.insertBefore(before, node);
        }

        vlists[node->counter].pushTop(node);
    }

    void remove(CrossNode* node) {
        vlists[node->counter].remove(node);  // 先删除纵向

        if (!node->isVNode()) {
            hlist.remove(node);  // 再删除横向

            if (!vlists[node->counter].empty()) {  // 如果纵向不为空，下一个纵向节点顶上来作为新的十字节点
                hlist.insertAfter(node->prev, vlists[node->counter].top());
            }
            else {
                vlists.erase(node->counter);  // 已经为空了，删除该纵向队列的数据结构
            }
        }
    }

    bool empty() {
        return vlists.empty();
    }

private:
    HList hlist;
    unordered_map<int, VList> vlists;
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

        CrossNode* node = keyNodes[key];
        CrossNode* next = clist.next(node);
        clist.remove(node);  // 先删除这个节点
        ++node->counter;
        clist.insertBefore(next, node);  // 计数加1后再重新插入

        return node->value;
    }

    void put(int key, int value) {
        if (cap == 0) {
            return;
        }

        if (keyNodes.count(key) != 0) {  // 已经存在的节点，更新value和counter
            CrossNode* node = keyNodes[key];
            CrossNode* next = clist.next(node);
            clist.remove(node);  // 先删除这个节点
            ++node->counter;
            node->value = value;
            clist.insertBefore(next, node);  // 计数加1后再重新插入
        }
        else {
            if (++size > cap) {  // 如果容量超限，先把最后一个干掉
                size = cap;
                CrossNode* minCounter = clist.minCounter();
                clist.remove(minCounter);
                keyNodes.erase(minCounter->key);
                delete minCounter;
            }

            CrossNode* node = new CrossNode(key, value);
            keyNodes[key] = node;
            clist.pushFront(node);
        }
    }

private:
    unordered_map<int, CrossNode*> keyNodes;
    CrossList clist;
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
