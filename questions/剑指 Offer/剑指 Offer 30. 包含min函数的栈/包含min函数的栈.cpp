/* 包含min函数的栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

 

示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
 

提示：

各函数的调用总次数不超过 20000 次
 

注意：本题与主站 155 题相同：https://leetcode-cn.com/problems/min-stack/

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/bao-han-minhan-shu-de-zhan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        int minimum = valueMins.empty() ? x : std::min(x, valueMins.top().second);
        valueMins.push({ x,minimum });
    }

    void pop() {
        valueMins.pop();
    }

    int top() {
        return valueMins.top().first;
    }

    int min() {
        return valueMins.top().second;
    }

private:
    stack<pair<int, int>> valueMins;
};

int main()
{
    CheckResult check;
    
    MinStack myStack;
    myStack.push(-2);
    myStack.push(0);
    myStack.push(-3);
    check.checkInt(-3, myStack.min());
    myStack.pop();
    myStack.top();
    check.checkInt(0, myStack.top());
    check.checkInt(-2, myStack.min());

    MinStack myStack2;
    myStack2.push(8);
    check.checkInt(8, myStack2.top());
    check.checkInt(8, myStack2.min());
    myStack2.push(7);
    check.checkInt(7, myStack2.top());
    check.checkInt(7, myStack2.min());
    myStack2.push(6);
    check.checkInt(6, myStack2.top());
    check.checkInt(6, myStack2.min());
    myStack2.push(5);
    check.checkInt(5, myStack2.top());
    check.checkInt(5, myStack2.min());
    myStack2.push(1);
    check.checkInt(1, myStack2.top());
    check.checkInt(1, myStack2.min());
    myStack2.push(2);
    check.checkInt(2, myStack2.top());
    check.checkInt(1, myStack2.min());
    myStack2.push(3);
    check.checkInt(3, myStack2.top());
    check.checkInt(1, myStack2.min());
    myStack2.push(4);
    check.checkInt(4, myStack2.top());
    check.checkInt(1, myStack2.min());
    myStack2.pop();
    check.checkInt(3, myStack2.top());
    check.checkInt(1, myStack2.min());
    myStack2.pop();
    check.checkInt(2, myStack2.top());
    check.checkInt(1, myStack2.min());
    myStack2.pop();
    check.checkInt(1, myStack2.top());
    check.checkInt(1, myStack2.min());
    myStack2.pop();
    check.checkInt(5, myStack2.top());
    check.checkInt(5, myStack2.min());
    myStack2.pop();
    check.checkInt(6, myStack2.top());
    check.checkInt(6, myStack2.min());
    myStack2.pop();
    check.checkInt(7, myStack2.top());
    check.checkInt(7, myStack2.min());
    myStack2.pop();
    check.checkInt(8, myStack2.top());
    check.checkInt(8, myStack2.min());
    myStack2.pop();
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
