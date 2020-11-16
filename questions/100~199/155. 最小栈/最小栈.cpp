/* 最小栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        topNode = NULL;
        minVal = INT_MAX;
    }

    ~MinStack() {
        while (topNode != NULL) {
            pop();
        }
    }

    void push(int x) {
        StackListNode* node;
        if (x <= minVal) {
            // 如果新进栈的数不大于当前最小值，先保存当前最小值
            node = new StackListNode(minVal);
            node->prev = topNode;
            topNode = node;
            minVal = x;
        }

        node = new StackListNode(x);
        node->prev = topNode;
        topNode = node;
    }

    void pop() {
        if (topNode == NULL) {
            return;
        }

        // 先删除栈顶
        StackListNode* node = topNode;
        int val = node->val;
        topNode = topNode->prev;
        delete node;

        // 如果最小值出栈了，恢复一个最小值出来
        if (val == minVal) {
            node = topNode;
            minVal = node->val;
            topNode = topNode->prev;
            delete node;
        }
    }

    int top() {
        if (topNode != NULL) {
            return topNode->val;
        }
        return INT_MIN;
    }

    int getMin() {
        if (topNode != NULL) {
            return minVal;
        }
        return INT_MIN;
    }

private:
    int minVal;
    struct StackListNode {
        int val;
        StackListNode* prev;
        StackListNode(int x) : val(x), prev(NULL) {}
    };
    StackListNode* topNode;
};

int main()
{
    MinStack myStack;
    CheckResult check;
    
    myStack.push(-2);
    myStack.push(0);
    myStack.push(-3);
    check.checkInt(-3, myStack.getMin());
    myStack.pop();
    myStack.top();
    check.checkInt(0, myStack.top());
    check.checkInt(-2, myStack.getMin());

    MinStack myStack1;
    myStack1.pop();
    check.checkInt(INT_MIN, myStack1.top());
    check.checkInt(INT_MIN, myStack1.getMin());
    
    MinStack myStack2;
    myStack2.push(8);
    check.checkInt(8, myStack2.top());
    check.checkInt(8, myStack2.getMin());
    myStack2.push(7);
    check.checkInt(7, myStack2.top());
    check.checkInt(7, myStack2.getMin());
    myStack2.push(6);
    check.checkInt(6, myStack2.top());
    check.checkInt(6, myStack2.getMin());
    myStack2.push(5);
    check.checkInt(5, myStack2.top());
    check.checkInt(5, myStack2.getMin());
    myStack2.push(1);
    check.checkInt(1, myStack2.top());
    check.checkInt(1, myStack2.getMin());
    myStack2.push(2);
    check.checkInt(2, myStack2.top());
    check.checkInt(1, myStack2.getMin());
    myStack2.push(3);
    check.checkInt(3, myStack2.top());
    check.checkInt(1, myStack2.getMin());
    myStack2.push(4);
    check.checkInt(4, myStack2.top());
    check.checkInt(1, myStack2.getMin());
    myStack2.pop();
    check.checkInt(3, myStack2.top());
    check.checkInt(1, myStack2.getMin());
    myStack2.pop();
    check.checkInt(2, myStack2.top());
    check.checkInt(1, myStack2.getMin());
    myStack2.pop();
    check.checkInt(1, myStack2.top());
    check.checkInt(1, myStack2.getMin());
    myStack2.pop();
    check.checkInt(5, myStack2.top());
    check.checkInt(5, myStack2.getMin());
    myStack2.pop();
    check.checkInt(6, myStack2.top());
    check.checkInt(6, myStack2.getMin());
    myStack2.pop();
    check.checkInt(7, myStack2.top());
    check.checkInt(7, myStack2.getMin());
    myStack2.pop();
    check.checkInt(8, myStack2.top());
    check.checkInt(8, myStack2.getMin());
    myStack2.pop();
    check.checkInt(INT_MIN, myStack2.top());
    check.checkInt(INT_MIN, myStack2.getMin());

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
