/* 设计循环双端队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
设计实现双端队列。
你的实现需要支持以下操作：

MyCircularDeque(k)：构造函数,双端队列的大小为k。
insertFront()：将一个元素添加到双端队列头部。 如果操作成功返回 true。
insertLast()：将一个元素添加到双端队列尾部。如果操作成功返回 true。
deleteFront()：从双端队列头部删除一个元素。 如果操作成功返回 true。
deleteLast()：从双端队列尾部删除一个元素。如果操作成功返回 true。
getFront()：从双端队列头部获得一个元素。如果双端队列为空，返回 -1。
getRear()：获得双端队列的最后一个元素。 如果双端队列为空，返回 -1。
isEmpty()：检查双端队列是否为空。
isFull()：检查双端队列是否满了。
示例：

MyCircularDeque circularDeque = new MycircularDeque(3); // 设置容量大小为3
circularDeque.insertLast(1);			        // 返回 true
circularDeque.insertLast(2);			        // 返回 true
circularDeque.insertFront(3);			        // 返回 true
circularDeque.insertFront(4);			        // 已经满了，返回 false
circularDeque.getRear();  				// 返回 2
circularDeque.isFull();				        // 返回 true
circularDeque.deleteLast();			        // 返回 true
circularDeque.insertFront(4);			        // 返回 true
circularDeque.getFront();				// 返回 4
 
 

提示：

所有值的范围为 [1, 1000]
操作次数的范围为 [1, 1000]
请不要使用内置的双端队列库。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-circular-deque
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        data = new int[k];
        len = k;
        count = 0;
        head = 0;
        tail = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (count == len) {
            return false;
        }

        head = (head + len - 1) % len;
        data[head] = value;
        count++;
        if (count == 1) {
            tail = head;
        }

        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (count == len) {
            return false;
        }

        tail = (tail + 1) % len;
        data[tail] = value;
        count++;
        if (count == 1) {
            head = tail;
        }

        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (count == 0) {
            return false;
        }

        head = (head + 1) % len;
        count--;

        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (count == 0) {
            return false;
        }

        tail = (tail + len - 1) % len;
        count--;

        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        return (count == 0) ? -1 : data[head];
    }

    /** Get the last item from the deque. */
    int getRear() {
        return (count == 0) ? -1 : data[tail];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return count == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return count == len;
    }

private:
    int* data;
    int len;
    int count;
    int head;
    int tail;
};

int main()
{
    CheckResult check;

    MyCircularDeque o1(3);
    check.checkBool(true, o1.isEmpty());
    check.checkBool(false, o1.isFull());
    check.checkInt(-1, o1.getFront());
    check.checkInt(-1, o1.getRear());
    check.checkBool(false, o1.deleteFront());
    check.checkBool(false, o1.deleteLast());
    check.checkBool(true, o1.insertLast(1));
    check.checkInt(1, o1.getFront());
    check.checkInt(1, o1.getRear());
    check.checkBool(true, o1.insertLast(2));
    check.checkInt(1, o1.getFront());
    check.checkInt(2, o1.getRear());
    check.checkBool(true, o1.insertFront(3));
    check.checkInt(3, o1.getFront());
    check.checkInt(2, o1.getRear());
    check.checkBool(false, o1.insertFront(4));
    check.checkBool(false, o1.isEmpty());
    check.checkBool(true, o1.isFull());
    check.checkBool(true, o1.deleteLast());
    check.checkInt(3, o1.getFront());
    check.checkInt(1, o1.getRear());
    check.checkBool(true, o1.insertFront(4));
    check.checkInt(4, o1.getFront());
    check.checkInt(1, o1.getRear());
    check.checkBool(true, o1.deleteLast());
    check.checkBool(true, o1.deleteFront());
    check.checkBool(true, o1.deleteLast());
    check.checkBool(false, o1.deleteLast());
    check.checkBool(false, o1.deleteFront());
    check.checkBool(true, o1.insertFront(5));
    check.checkBool(true, o1.insertLast(6));
    check.checkBool(true, o1.insertFront(7));
    check.checkBool(false, o1.insertLast(8));
    check.checkInt(7, o1.getFront());
    check.checkInt(6, o1.getRear());

    MyCircularDeque o2(1);
    check.checkBool(true, o2.isEmpty());
    check.checkBool(false, o2.isFull());
    check.checkInt(-1, o2.getFront());
    check.checkInt(-1, o2.getRear());
    check.checkBool(false, o2.deleteFront());
    check.checkBool(false, o2.deleteLast());
    check.checkBool(true, o2.insertLast(1));
    check.checkInt(1, o2.getFront());
    check.checkInt(1, o2.getRear());
    check.checkBool(false, o2.insertLast(2));
    check.checkBool(true, o2.deleteFront());
    check.checkBool(true, o2.insertLast(2));
    check.checkInt(2, o2.getFront());
    check.checkInt(2, o2.getRear());
    check.checkBool(false, o2.insertFront(3));
    check.checkBool(true, o2.deleteLast());
    check.checkBool(true, o2.insertFront(3));
    check.checkInt(3, o2.getFront());
    check.checkInt(3, o2.getRear());
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
