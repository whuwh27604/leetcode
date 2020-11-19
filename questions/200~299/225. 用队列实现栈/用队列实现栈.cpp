/* 用队列实现栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
使用队列实现栈的下列操作：

push(x) --元素 x 入栈
pop() --移除栈顶元素
top() --获取栈顶元素
empty() --返回栈是否为空
注意 :

你只能使用队列的基本操作-- 也就是 push to back, peek / pop from front, size, 和 is empty 这些操作是合法的。
你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。

来源：力扣（LeetCode）
链接：https ://leetcode-cn.com/problems/implement-stack-using-queues
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"
#include <list>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        myList.push_back(x);
        int count = myList.size();
        while (count > 1) {
            int x = myList.front();
            myList.pop_front();
            myList.push_back(x);
            count--;
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = myList.front();
        myList.pop_front();
        return x;
    }

    /** Get the top element. */
    int top() {
        return myList.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return myList.empty();
    }

    list<int> myList;
};

int main()
{
    MyStack o;
    CheckResult check;

    check.checkBool(true, o.empty());
    o.push(1);
    check.checkBool(false, o.empty());
    check.checkInt(1, o.top());
    check.checkInt(1, o.pop());
    check.checkBool(true, o.empty());

    o.push(1);
    o.push(2);
    o.push(3);
    check.checkBool(false, o.empty());
    check.checkInt(3, o.top());
    check.checkInt(3, o.pop());
    check.checkInt(2, o.top());
    check.checkInt(2, o.pop());
    check.checkInt(1, o.top());
    check.checkInt(1, o.pop());
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
