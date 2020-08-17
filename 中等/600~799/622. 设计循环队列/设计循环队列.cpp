/* 设计循环队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：

MyCircularQueue(k): 构造器，设置队列长度为 k 。
Front: 从队首获取元素。如果队列为空，返回 -1 。
Rear: 获取队尾元素。如果队列为空，返回 -1 。
enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty(): 检查循环队列是否为空。
isFull(): 检查循环队列是否已满。
 

示例：

MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
circularQueue.enQueue(1);  // 返回 true
circularQueue.enQueue(2);  // 返回 true
circularQueue.enQueue(3);  // 返回 true
circularQueue.enQueue(4);  // 返回 false，队列已满
circularQueue.Rear();  // 返回 3
circularQueue.isFull();  // 返回 true
circularQueue.deQueue();  // 返回 true
circularQueue.enQueue(4);  // 返回 true
circularQueue.Rear();  // 返回 4
 

提示：

所有的值都在 0 至 1000 的范围内；
操作数将在 1 至 1000 的范围内；
请不要使用内置的队列库。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-circular-queue
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        data = new int[k];
        len = k;
        count = 0;
        head = 0;
        tail = -1;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (count == len) {
            return false;
        }

        tail = (tail + 1) % len;
        data[tail] = value;
        count++;

        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (count == 0) {
            return false;
        }

        head = (head + 1) % len;
        count--;

        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        return (count == 0) ? -1 : data[head];
    }

    /** Get the last item from the queue. */
    int Rear() {
        return (count == 0) ? -1 : data[tail];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return count == 0;
    }

    /** Checks whether the circular queue is full or not. */
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

    MyCircularQueue o1(3);
    check.checkBool(true, o1.isEmpty());
    check.checkBool(false, o1.isFull());
    check.checkInt(-1, o1.Front());
    check.checkInt(-1, o1.Rear());
    check.checkBool(false, o1.deQueue());
    check.checkBool(true, o1.enQueue(1));
    check.checkBool(false, o1.isEmpty());
    check.checkBool(false, o1.isFull());
    check.checkInt(1, o1.Front());
    check.checkInt(1, o1.Rear());
    check.checkBool(true, o1.enQueue(2));
    check.checkBool(false, o1.isEmpty());
    check.checkBool(false, o1.isFull());
    check.checkInt(1, o1.Front());
    check.checkInt(2, o1.Rear());
    check.checkBool(true, o1.enQueue(3));
    check.checkBool(false, o1.isEmpty());
    check.checkBool(true, o1.isFull());
    check.checkInt(1, o1.Front());
    check.checkInt(3, o1.Rear());
    check.checkBool(false, o1.enQueue(4));
    check.checkBool(true, o1.deQueue());
    check.checkBool(false, o1.isEmpty());
    check.checkBool(false, o1.isFull());
    check.checkInt(2, o1.Front());
    check.checkInt(3, o1.Rear());
    check.checkBool(true, o1.enQueue(4));
    check.checkBool(false, o1.isEmpty());
    check.checkBool(true, o1.isFull());
    check.checkInt(2, o1.Front());
    check.checkInt(4, o1.Rear());
    check.checkBool(true, o1.deQueue());
    check.checkBool(false, o1.isEmpty());
    check.checkBool(false, o1.isFull());
    check.checkInt(3, o1.Front());
    check.checkInt(4, o1.Rear());
    check.checkBool(true, o1.deQueue());
    check.checkBool(false, o1.isEmpty());
    check.checkBool(false, o1.isFull());
    check.checkInt(4, o1.Front());
    check.checkInt(4, o1.Rear());
    check.checkBool(true, o1.deQueue());
    check.checkBool(true, o1.isEmpty());
    check.checkBool(false, o1.isFull());
    check.checkInt(-1, o1.Front());
    check.checkInt(-1, o1.Rear());
    check.checkBool(false, o1.deQueue());
    check.checkBool(true, o1.enQueue(5));
    check.checkBool(false, o1.isEmpty());
    check.checkBool(false, o1.isFull());
    check.checkInt(5, o1.Front());
    check.checkInt(5, o1.Rear());
    check.checkBool(true, o1.deQueue());
    check.checkBool(true, o1.isEmpty());
    check.checkBool(false, o1.isFull());
    check.checkInt(-1, o1.Front());
    check.checkInt(-1, o1.Rear());
    check.checkBool(false, o1.deQueue());

    MyCircularQueue o2(0);
    check.checkBool(true, o2.isEmpty());
    check.checkBool(true, o2.isFull());
    check.checkInt(-1, o2.Front());
    check.checkInt(-1, o2.Rear());
    check.checkBool(false, o2.deQueue());
    check.checkBool(false, o2.enQueue(1));

    MyCircularQueue o3(1);
    check.checkBool(true, o3.isEmpty());
    check.checkBool(false, o3.isFull());
    check.checkInt(-1, o3.Front());
    check.checkInt(-1, o3.Rear());
    check.checkBool(false, o3.deQueue());
    check.checkBool(true, o3.enQueue(5));
    check.checkBool(false, o3.isEmpty());
    check.checkBool(true, o3.isFull());
    check.checkInt(5, o3.Front());
    check.checkInt(5, o3.Rear());
    check.checkBool(false, o3.enQueue(6));
    check.checkBool(true, o3.deQueue());
    check.checkBool(true, o3.isEmpty());
    check.checkBool(false, o3.isFull());
    check.checkInt(-1, o3.Front());
    check.checkInt(-1, o3.Rear());
    check.checkBool(true, o3.enQueue(6));
    check.checkBool(false, o3.isEmpty());
    check.checkBool(true, o3.isFull());
    check.checkInt(6, o3.Front());
    check.checkInt(6, o3.Rear());
    check.checkBool(true, o3.deQueue());
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
