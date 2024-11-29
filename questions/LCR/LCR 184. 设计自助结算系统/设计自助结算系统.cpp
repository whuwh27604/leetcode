/* 设计自助结算系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请设计一个自助结账系统，该系统需要通过一个队列来模拟顾客通过购物车的结算过程，需要实现的功能有：

get_max()：获取结算商品中的最高价格，如果队列为空，则返回 -1
add(value)：将价格为 value 的商品加入待结算商品队列的尾部
remove()：移除第一个待结算的商品价格，如果队列为空，则返回 -1
注意，为保证该系统运转高效性，以上函数的均摊时间复杂度均为 O(1)



示例 1：

输入:
["Checkout","add","add","get_max","remove","get_max"]
[[],[4],[7],[],[],[]]

输出: [null,null,null,7,4,7]
示例 2：

输入:
["Checkout","remove","get_max"]
[[],[],[]]

输出: [null,-1,-1]


提示：

1 <= get_max, add, remove 的总操作数 <= 10000
1 <= value <= 10^5
*/

#include <iostream>
#include <deque>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Checkout {
public:
    Checkout() {

    }

    int get_max() {
        return dq.empty() ? -1 : dq.front();
    }

    void add(int value) {
        while (!dq.empty() && dq.back() < value) {
            dq.pop_back();
        }

        dq.push_back(value);
        q.push(value);
    }

    int remove() {
        if (q.empty()) {
            return -1;
        }

        int value = q.front();
        q.pop();

        if (dq.front() == value) {
            dq.pop_front();
        }

        return value;
    }

    queue<int> q;
    deque<int> dq;
};

int main()
{
    CheckResult check;

    Checkout o1;
    o1.add(4);
    o1.add(7);
    check.checkInt(7, o1.get_max());
    check.checkInt(4, o1.remove());
    check.checkInt(7, o1.get_max());

    Checkout o2;
    check.checkInt(-1, o2.remove());
    check.checkInt(-1, o2.get_max());
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
