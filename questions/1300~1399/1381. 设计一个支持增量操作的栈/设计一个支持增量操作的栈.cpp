/* 设计一个支持增量操作的栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请你设计一个支持下述操作的栈。

实现自定义栈类 CustomStack ：

CustomStack(int maxSize)：用 maxSize 初始化对象，maxSize 是栈中最多能容纳的元素数量，栈在增长到 maxSize 之后则不支持 push 操作。
void push(int x)：如果栈还未增长到 maxSize ，就将 x 添加到栈顶。
int pop()：弹出栈顶元素，并返回栈顶的值，或栈为空时返回 -1 。
void inc(int k, int val)：栈底的 k 个元素的值都增加 val 。如果栈中元素总数小于 k ，则栈中的所有元素都增加 val 。
 

示例：

输入：
["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
[[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]
输出：
[null,null,null,2,null,null,null,null,null,103,202,201,-1]
解释：
CustomStack customStack = new CustomStack(3); // 栈是空的 []
customStack.push(1);                          // 栈变为 [1]
customStack.push(2);                          // 栈变为 [1, 2]
customStack.pop();                            // 返回 2 --> 返回栈顶值 2，栈变为 [1]
customStack.push(2);                          // 栈变为 [1, 2]
customStack.push(3);                          // 栈变为 [1, 2, 3]
customStack.push(4);                          // 栈仍然是 [1, 2, 3]，不能添加其他元素使栈大小变为 4
customStack.increment(5, 100);                // 栈变为 [101, 102, 103]
customStack.increment(2, 100);                // 栈变为 [201, 202, 103]
customStack.pop();                            // 返回 103 --> 返回栈顶值 103，栈变为 [201, 202]
customStack.pop();                            // 返回 202 --> 返回栈顶值 202，栈变为 [201]
customStack.pop();                            // 返回 201 --> 返回栈顶值 201，栈变为 []
customStack.pop();                            // 返回 -1 --> 栈为空，返回 -1
 

提示：

1 <= maxSize <= 1000
1 <= x <= 1000
1 <= k <= 1000
0 <= val <= 100
每种方法 increment，push 以及 pop 分别最多调用 1000 次

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-a-stack-with-increment-operation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class CustomStack {
public:
    CustomStack(int maxSize) {
        size = maxSize;
        dataTop = -1;
        data.resize(size);
        incrementData.resize(size);
    }

    void push(int x) {
        if (dataTop < size - 1) {
            data[++dataTop] = x;
        }
    }

    int pop() {
        if (dataTop == -1) {
            return -1;
        }

        int val = data[dataTop] + incrementData[dataTop];

        if (dataTop != 0) {
            incrementData[dataTop - 1] += incrementData[dataTop];
        }

        incrementData[dataTop--] = 0;
        return val;
    }

    void increment(int k, int val) {
        int incrementTop = min(k - 1, dataTop);

        if (incrementTop >= 0) {
            incrementData[incrementTop] += val;
        }
    }

private:
    vector<int> data;
    vector<int> incrementData;
    int size;
    int dataTop;
};

int main()
{
    CheckResult check;

    CustomStack o1(3);
    o1.push(1);
    o1.push(2);
    check.checkInt(2, o1.pop());
    o1.push(2);
    o1.push(3);
    o1.push(4);
    o1.increment(5, 100);
    o1.increment(2, 100);
    check.checkInt(103, o1.pop());
    check.checkInt(202, o1.pop());
    check.checkInt(201, o1.pop());
    check.checkInt(-1, o1.pop());

    CustomStack o2(3);
    check.checkInt(-1, o2.pop());
    o2.increment(2, 100);
    o2.push(3);
    o2.increment(2, 100);
    check.checkInt(103, o2.pop());
    check.checkInt(-1, o2.pop());
    o2.increment(2, 100);
    o2.push(4);
    o2.increment(1, 100);
    o2.increment(2, 100);
    o2.push(5);
    o2.increment(2, 100);
    check.checkInt(105, o2.pop());
    check.checkInt(304, o2.pop());
    check.checkInt(-1, o2.pop());
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
