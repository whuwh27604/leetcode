/* 最小栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:

MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。
 

示例 1:

输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
 

提示：

-231 <= val <= 231 - 1
pop、top 和 getMin 操作总是在 非空栈 上调用
push, pop, top, and getMin最多被调用 3 * 104 次

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/min-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        int minimum = valueMins.empty() ? val : min(val, valueMins.top().second);
        valueMins.push({ val,minimum });
    }

    void pop() {
        valueMins.pop();
    }

    int top() {
        return valueMins.top().first;
    }

    int getMin() {
        return valueMins.top().second;
    }

private:
    stack<pair<int, int>> valueMins;
};

int main()
{
    CheckResult check;

    MinStack o1;
    o1.push(-2);
    o1.push(0);
    o1.push(-3);
    check.checkInt(-3, o1.getMin());
    o1.pop();
    o1.top();
    check.checkInt(0, o1.top());
    check.checkInt(-2, o1.getMin());

    MinStack o2;
    o2.push(8);
    check.checkInt(8, o2.top());
    check.checkInt(8, o2.getMin());
    o2.push(7);
    check.checkInt(7, o2.top());
    check.checkInt(7, o2.getMin());
    o2.push(6);
    check.checkInt(6, o2.top());
    check.checkInt(6, o2.getMin());
    o2.push(5);
    check.checkInt(5, o2.top());
    check.checkInt(5, o2.getMin());
    o2.push(1);
    check.checkInt(1, o2.top());
    check.checkInt(1, o2.getMin());
    o2.push(2);
    check.checkInt(2, o2.top());
    check.checkInt(1, o2.getMin());
    o2.push(3);
    check.checkInt(3, o2.top());
    check.checkInt(1, o2.getMin());
    o2.push(4);
    check.checkInt(4, o2.top());
    check.checkInt(1, o2.getMin());
    o2.pop();
    check.checkInt(3, o2.top());
    check.checkInt(1, o2.getMin());
    o2.pop();
    check.checkInt(2, o2.top());
    check.checkInt(1, o2.getMin());
    o2.pop();
    check.checkInt(1, o2.top());
    check.checkInt(1, o2.getMin());
    o2.pop();
    check.checkInt(5, o2.top());
    check.checkInt(5, o2.getMin());
    o2.pop();
    check.checkInt(6, o2.top());
    check.checkInt(6, o2.getMin());
    o2.pop();
    check.checkInt(7, o2.top());
    check.checkInt(7, o2.getMin());
    o2.pop();
    check.checkInt(8, o2.top());
    check.checkInt(8, o2.getMin());
    o2.pop();
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
