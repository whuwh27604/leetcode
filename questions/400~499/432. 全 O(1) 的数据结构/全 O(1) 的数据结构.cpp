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
#include "../check/CheckResult.h"

using namespace std;

class CrossNode {
public:
    string key;
    int value;
    CrossNode* prev;
    CrossNode* next;
    CrossNode* up;
    CrossNode* down;

    CrossNode() : key(""), value(0), prev(NULL), next(NULL), up(NULL), down(NULL) {}
    CrossNode(string& _key) : key(_key), value(1), prev(NULL), next(NULL), up(NULL), down(NULL) {}

    bool isVNode() {
        return prev == NULL;
    }
};

class HList {
public:
    HList() {
        pseudoHead.next = &pseudoTail;
        pseudoTail.prev = &pseudoHead;
        pseudoHead.value = INT_MIN;
        pseudoTail.value = INT_MAX;
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
        return vlists[node->value].top()->prev;
    }

    CrossNode* next(CrossNode* node) {
        return vlists[node->value].top()->next;
    }

    void pushFront(CrossNode* node) {
        insertBefore(hlist.front(), node);  // 插入到首节点前面，因为它们的value有可能相等
    }

    void insertAfter(CrossNode* after, CrossNode* node) {
        if (after->value == node->value) {  // 如果插入的位置value相等，合并它们到纵向队列
            CrossNode* prev = after->prev;
            hlist.remove(after);  // 删除原来的十字节点
            hlist.insertAfter(prev, node);  // 新插入的节点做为新的十字节点
        }
        else {
            hlist.insertAfter(after, node);
        }

        vlists[node->value].pushTop(node);
    }

    void insertBefore(CrossNode* before, CrossNode* node) {
        if (before->value == node->value) {
            CrossNode* next = before->next;
            hlist.remove(before);
            hlist.insertBefore(next, node);
        }
        else {
            hlist.insertBefore(before, node);
        }

        vlists[node->value].pushTop(node);
    }

    void remove(CrossNode* node) {
        vlists[node->value].remove(node);  // 先删除纵向

        if (!node->isVNode()) {
            hlist.remove(node);  // 再删除横向

            if (!vlists[node->value].empty()) {  // 如果纵向不为空，下一个纵向节点顶上来作为新的十字节点
                hlist.insertAfter(node->prev, vlists[node->value].top());
            }
            else {
                vlists.erase(node->value);  // 已经为空了，删除该纵向队列的数据结构
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

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (keyNodes.count(key) == 0) {
            CrossNode* node = new CrossNode(key);
            keyNodes[key] = node;
            clist.pushFront(node);
        }
        else {
            CrossNode* node = keyNodes[key];
            CrossNode* next = clist.next(node);
            clist.remove(node);  // 先删除这个节点
            ++node->value;
            clist.insertBefore(next, node);
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (keyNodes.count(key) == 0) {
            return;
        }

        CrossNode* node = keyNodes[key];
        CrossNode* prev = clist.prev(node);
        clist.remove(node);  // 先删除这个节点
        if (--node->value == 0) {  // 减为0了就彻底干掉
            keyNodes.erase(key);
            delete node;
        }
        else {
            clist.insertAfter(prev, node);
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return clist.empty() ? "" : clist.back()->key;
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return clist.empty() ? "" : clist.front()->key;
    }

private:
    unordered_map<string, CrossNode*> keyNodes;
    CrossList clist;
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
