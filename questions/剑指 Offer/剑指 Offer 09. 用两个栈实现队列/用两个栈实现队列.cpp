/* 用两个栈实现队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

 

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include "../check/CheckResult.h"

using namespace std;

class CQueue {
public:
    CQueue() {

    }

    void appendTail(int value) {
        forwardList.push(value);
    }

    int deleteHead() {
        if (backwardList.empty()) {
            while (!forwardList.empty()) {
                backwardList.push(forwardList.top());
                forwardList.pop();
            }
        }

        if (backwardList.empty()) {
            return -1;
        }

        int head = backwardList.top();
        backwardList.pop();

        return head;
    }

    stack<int> forwardList;
    stack<int> backwardList;
};

int main()
{
    CheckResult check;

    CQueue o;
    check.checkInt(-1, o.deleteHead());
    o.appendTail(1);
    check.checkInt(1, o.deleteHead());
    check.checkInt(-1, o.deleteHead());
    o.appendTail(2);
    o.appendTail(3);
    check.checkInt(2, o.deleteHead());
    check.checkInt(3, o.deleteHead());
    check.checkInt(-1, o.deleteHead());
    o.appendTail(4);
    o.appendTail(5);
    o.appendTail(6);
    check.checkInt(4, o.deleteHead());
    check.checkInt(5, o.deleteHead());
    check.checkInt(6, o.deleteHead());
    check.checkInt(-1, o.deleteHead());
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
