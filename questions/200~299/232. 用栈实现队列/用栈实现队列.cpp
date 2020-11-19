/* 用栈实现队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
使用栈实现队列的下列操作：

push(x) -- 将一个元素放入队列的尾部。
pop() -- 从队列首部移除元素。
peek() -- 返回队列首部的元素。
empty() -- 返回队列是否为空。
示例:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);
queue.peek();  // 返回 1
queue.pop();   // 返回 1
queue.empty(); // 返回 false
说明:

你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-queue-using-stacks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        whereIsData = DataInPushStack;
    }

    /** Push element x to the back of queue. */
    void push(int x) {
        if (whereIsData == DataInPopStack) {
            pop2PushStack();
        }

        pushStack.push(x);
        whereIsData = DataInPushStack;
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (whereIsData == DataInPushStack) {
            push2PopStack();
        }

        int x = popStack.top();
        popStack.pop();
        whereIsData = DataInPopStack;
        return x;
    }

    /** Get the front element. */
    int peek() {
        if (whereIsData == DataInPushStack) {
            push2PopStack();
        }

        whereIsData = DataInPopStack;
        return popStack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        if (whereIsData == DataInPushStack) {
            return pushStack.empty();
        }
        return popStack.empty();
    }

    void push2PopStack() {
        while (!pushStack.empty()) {
            int x = pushStack.top();
            pushStack.pop();
            popStack.push(x);
        }
    }

    void pop2PushStack() {
        while (!popStack.empty()) {
            int x = popStack.top();
            popStack.pop();
            pushStack.push(x);
        }
    }

    stack<int> pushStack;
    stack<int> popStack;
    int whereIsData;
    const int DataInPushStack = 0;
    const int DataInPopStack = 1;
};

int main()
{
    MyQueue o;
    CheckResult check;

    check.checkBool(true, o.empty());
    o.push(1);
    check.checkBool(false, o.empty());
    check.checkInt(1, o.peek());
    check.checkInt(1, o.pop());
    check.checkBool(true, o.empty());

    o.push(1);
    o.push(2);
    o.push(3);
    check.checkBool(false, o.empty());
    check.checkInt(1, o.peek());
    check.checkInt(1, o.pop());
    check.checkBool(false, o.empty());
    check.checkInt(2, o.peek());
    check.checkInt(2, o.pop());
    check.checkBool(false, o.empty());
    check.checkInt(3, o.peek());
    check.checkInt(3, o.pop());
    check.checkBool(true, o.empty());
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
