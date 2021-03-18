/* 最大频率栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
实现 FreqStack，模拟类似栈的数据结构的操作的一个类。

FreqStack 有两个函数：

push(int x)，将整数 x 推入栈中。
pop()，它移除并返回栈中出现最频繁的元素。
如果最频繁的元素不只一个，则移除并返回最接近栈顶的元素。
 

示例：

输入：
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
输出：[null,null,null,null,null,null,null,5,7,5,4]
解释：
执行六次 .push 操作后，栈自底向上为 [5,7,5,7,4,5]。然后：

pop() -> 返回 5，因为 5 是出现频率最高的。
栈变成 [5,7,5,7,4]。

pop() -> 返回 7，因为 5 和 7 都是频率最高的，但 7 最接近栈顶。
栈变成 [5,7,5,4]。

pop() -> 返回 5 。
栈变成 [5,7,4]。

pop() -> 返回 4 。
栈变成 [5,7]。
 

提示：

对 FreqStack.push(int x) 的调用中 0 <= x <= 10^9。
如果栈的元素数目为零，则保证不会调用  FreqStack.pop()。
单个测试样例中，对 FreqStack.push 的总调用次数不会超过 10000。
单个测试样例中，对 FreqStack.pop 的总调用次数不会超过 10000。
所有测试样例中，对 FreqStack.push 和 FreqStack.pop 的总调用次数不会超过 150000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-frequency-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class FreqStack {
public:
    FreqStack() {
        maxFreq = 0;
    }

    void push(int val) {
        int freq = ++valueFreqs[val];
        freqValues[freq].push(val);
        maxFreq = max(maxFreq, freq);
    }

    int pop() {
        int value = freqValues[maxFreq].top();
        freqValues[maxFreq].pop();

        if (freqValues[maxFreq].empty()) {
            freqValues.erase(maxFreq);
            --maxFreq;
        }

        if (--valueFreqs[value] == 0) {
            valueFreqs.erase(value);
        }

        return value;
    }

private:
    unordered_map<int, int> valueFreqs;
    unordered_map<int, stack<int>> freqValues;
    int maxFreq;
};

int main()
{
    CheckResult check;

    FreqStack o1;
    o1.push(5);
    o1.push(7);
    o1.push(5);
    o1.push(7);
    o1.push(4);
    o1.push(5);
    check.checkInt(5, o1.pop());
    check.checkInt(7, o1.pop());
    check.checkInt(5, o1.pop());
    check.checkInt(4, o1.pop());

    FreqStack o2;
    o2.push(1);
    o2.push(2);
    o2.push(2);
    o2.push(1);
    o2.push(1);
    o2.push(2);
    o2.push(2);
    check.checkInt(2, o2.pop());
    check.checkInt(2, o2.pop());
    check.checkInt(1, o2.pop());
    check.checkInt(1, o2.pop());
    check.checkInt(2, o2.pop());
    check.checkInt(2, o2.pop());
    check.checkInt(1, o2.pop());
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
