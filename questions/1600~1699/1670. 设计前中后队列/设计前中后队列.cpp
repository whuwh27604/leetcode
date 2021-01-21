/* 设计前中后队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
请你设计一个队列，支持在前，中，后三个位置的 push 和 pop 操作。

请你完成 FrontMiddleBack 类：

FrontMiddleBack() 初始化队列。
void pushFront(int val) 将 val 添加到队列的 最前面 。
void pushMiddle(int val) 将 val 添加到队列的 正中间 。
void pushBack(int val) 将 val 添加到队里的 最后面 。
int popFront() 将 最前面 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 -1 。
int popMiddle() 将 正中间 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 -1 。
int popBack() 将 最后面 的元素从队列中删除并返回值，如果删除之前队列为空，那么返回 -1 。
请注意当有 两个 中间位置的时候，选择靠前面的位置进行操作。比方说：

将 6 添加到 [1, 2, 3, 4, 5] 的中间位置，结果数组为 [1, 2, 6, 3, 4, 5] 。
从 [1, 2, 3, 4, 5, 6] 的中间位置弹出元素，返回 3 ，数组变为 [1, 2, 4, 5, 6] 。
 

示例 1：

输入：
["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle", "popMiddle", "popBack", "popFront"]
[[], [1], [2], [3], [4], [], [], [], [], []]
输出：
[null, null, null, null, null, 1, 3, 4, 2, -1]

解释：
FrontMiddleBackQueue q = new FrontMiddleBackQueue();
q.pushFront(1);   // [1]
q.pushBack(2);    // [1, 2]
q.pushMiddle(3);  // [1, 3, 2]
q.pushMiddle(4);  // [1, 4, 3, 2]
q.popFront();     // 返回 1 -> [4, 3, 2]
q.popMiddle();    // 返回 3 -> [4, 2]
q.popMiddle();    // 返回 4 -> [2]
q.popBack();      // 返回 2 -> []
q.popFront();     // 返回 -1 -> [] （队列为空）
 

提示：

1 <= val <= 109
最多调用 1000 次 pushFront， pushMiddle， pushBack， popFront， popMiddle 和 popBack 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/design-front-middle-back-queue
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <deque>
#include "../check/CheckResult.h"

using namespace std;

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {

    }

    void pushFront(int val) {
        half1.push_front(val);

        if (half1.size() > half2.size()) {
            half2.push_front(half1.back());
            half1.pop_back();
        }
    }

    void pushMiddle(int val) {
        if (half1.size() < half2.size()) {
            half1.push_back(val);
        }
        else {
            half2.push_front(val);
        }
    }

    void pushBack(int val) {
        half2.push_back(val);

        if (half2.size() > half1.size() + 1) {
            half1.push_back(half2.front());
            half2.pop_front();
        }
    }

    int popFront() {
        if (half1.empty() && half2.empty()) {
            return -1;
        }

        int val;

        if (!half1.empty()) {
            val = half1.front();
            half1.pop_front();
        }
        else {
            val = half2.front();
            half2.pop_front();
        }

        if (half2.size() > half1.size() + 1) {
            half1.push_back(half2.front());
            half2.pop_front();
        }

        return val;
    }

    int popMiddle() {
        if (half1.empty() && half2.empty()) {
            return -1;
        }

        int val;

        if (half1.size() < half2.size()) {
            val = half2.front();
            half2.pop_front();
        }
        else {
            val = half1.back();
            half1.pop_back();
        }

        return val;
    }

    int popBack() {
        if (half1.empty() && half2.empty()) {
            return -1;
        }

        int val = half2.back();
        half2.pop_back();

        if (half1.size() > half2.size()) {
            half2.push_front(half1.back());
            half1.pop_back();
        }

        return val;
    }

private:
    deque<int> half1;  // 始终保持half1.size==half2.size或者half1.size==half2.size-1
    deque<int> half2;
};

int main()
{
    CheckResult check;

    FrontMiddleBackQueue o1;
    o1.pushFront(1);
    o1.pushBack(2);
    o1.pushMiddle(3);
    o1.pushMiddle(4);
    check.checkInt(1, o1.popFront());
    check.checkInt(3, o1.popMiddle());
    check.checkInt(4, o1.popMiddle());
    check.checkInt(2, o1.popBack());
    check.checkInt(-1, o1.popFront());

    FrontMiddleBackQueue o2;
    o2.pushFront(1);
    check.checkInt(1, o2.popFront());
    o2.pushFront(2);
    check.checkInt(2, o2.popBack());
    o2.pushFront(3);
    check.checkInt(3, o2.popMiddle());
    check.checkInt(-1, o2.popFront());
    o2.pushBack(4);
    check.checkInt(4, o2.popFront());
    o2.pushBack(5);
    check.checkInt(5, o2.popBack());
    o2.pushBack(6);
    check.checkInt(6, o2.popMiddle());
    check.checkInt(-1, o2.popBack());
    o2.pushMiddle(7);
    check.checkInt(7, o2.popFront());
    o2.pushMiddle(8);
    check.checkInt(8, o2.popBack());
    o2.pushMiddle(9);
    check.checkInt(9, o2.popMiddle());
    check.checkInt(-1, o2.popMiddle());
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
