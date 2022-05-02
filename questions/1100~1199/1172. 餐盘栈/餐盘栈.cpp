/* 餐盘栈.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们把无限数量 ∞ 的栈排成一行，按从左到右的次序从 0 开始编号。每个栈的的最大容量 capacity 都相同。

实现一个叫「餐盘」的类 DinnerPlates：

DinnerPlates(int capacity) - 给出栈的最大容量 capacity。
void push(int val) - 将给出的正整数 val 推入 从左往右第一个 没有满的栈。
int pop() - 返回 从右往左第一个 非空栈顶部的值，并将其从栈中删除；如果所有的栈都是空的，请返回 -1。
int popAtStack(int index) - 返回编号 index 的栈顶部的值，并将其从栈中删除；如果编号 index 的栈是空的，请返回 -1。
 

示例：

输入：
["DinnerPlates","push","push","push","push","push","popAtStack","push","push","popAtStack","popAtStack","pop","pop","pop","pop","pop"]
[[2],[1],[2],[3],[4],[5],[0],[20],[21],[0],[2],[],[],[],[],[]]
输出：
[null,null,null,null,null,null,2,null,null,20,21,5,4,3,1,-1]

解释：
DinnerPlates D = DinnerPlates(2);  // 初始化，栈最大容量 capacity = 2
D.push(1);
D.push(2);
D.push(3);
D.push(4);
D.push(5);         // 栈的现状为：    2  4
                                    1  3  5
                                    ﹈ ﹈ ﹈
D.popAtStack(0);   // 返回 2。栈的现状为：      4
                                          1  3  5
                                          ﹈ ﹈ ﹈
D.push(20);        // 栈的现状为：  20  4
                                   1  3  5
                                   ﹈ ﹈ ﹈
D.push(21);        // 栈的现状为：  20  4 21
                                   1  3  5
                                   ﹈ ﹈ ﹈
D.popAtStack(0);   // 返回 20。栈的现状为：       4 21
                                            1  3  5
                                            ﹈ ﹈ ﹈
D.popAtStack(2);   // 返回 21。栈的现状为：       4
                                            1  3  5
                                            ﹈ ﹈ ﹈
D.pop()            // 返回 5。栈的现状为：        4
                                            1  3
                                            ﹈ ﹈
D.pop()            // 返回 4。栈的现状为：    1  3
                                           ﹈ ﹈
D.pop()            // 返回 3。栈的现状为：    1
                                           ﹈
D.pop()            // 返回 1。现在没有栈。
D.pop()            // 返回 -1。仍然没有栈。
 

提示：

1 <= capacity <= 20000
1 <= val <= 20000
0 <= index <= 100000
最多会对 push，pop，和 popAtStack 进行 200000 次调用。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/dinner-plate-stacks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class BIT {
public:
    BIT(int n) {
        size = n;
        tree.resize(n + 1, 0);  // BIT数组的0位置不使用，index从1开始
    }

    int lowbit(int index) {
        return index & (-index);  // 保留最低位的1
    }

    void update(int index, int value) {
        while (index <= size) {
            tree[index] += value;
            index += lowbit(index);
        }
    }

    int query(int index) {
        int value = 0;

        while (index != 0) {
            value += tree[index];
            index -= lowbit(index);
        }

        return value;
    }

private:
    int size;
    vector<int> tree;
};

class DinnerPlates {
public:
    DinnerPlates(int capacity) {
        cap = capacity;
        size = 200005;
        data.resize(size);
        bit = new BIT(size);
    }

    void push(int val) {
        int index = getFirstNonFull();
        data[index].push_back(val);
        bit->update(index + 1, 1);  // data[index]对应BIT的index + 1位置，新增一个元素
    }

    int pop() {
        int index = getlastNonEmpty();

        if (index == -1) {
            return -1;
        }

        int val = data[index].back();
        data[index].pop_back();
        bit->update(index + 1, -1);  // data[index]对应BIT的index + 1位置，减少一个元素

        return val;
    }

    int popAtStack(int index) {
        if (data[index].empty()) {
            return -1;
        }

        int val = data[index].back();
        data[index].pop_back();
        bit->update(index + 1, -1);  // data[index]对应BIT的index + 1位置，减少一个元素

        return val;
    }

    int getFirstNonFull() {
        int left = 1, right = size, index = 0;

        while (left <= right) {
            int middle = (left + right) / 2;
            int count = bit->query(middle);

            if (count < cap * middle) {  // 从1到middle位置，元素个数小于最大个数，说明有位置可以push进去
                index = middle;
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }

        return index - 1;
    }

    int getlastNonEmpty() {
        int left = 1, right = size, index = 0;

        while (left <= right) {
            int middle = (left + right) / 2;
            int count = bit->query(size) - bit->query(middle - 1);

            if (count == 0) {
                right = middle - 1;
            }
            else {  // 从middle到size位置，至少存在1个元素，说明有stack为非空
                index = middle;
                left = middle + 1;
            }
        }

        return index - 1;
    }

private:
    vector<vector<int>> data;
    BIT* bit;
    int size;
    int cap;
};

int main()
{
    CheckResult check;

    DinnerPlates o1(2);
    o1.push(1);
    o1.push(2);
    o1.push(3);
    o1.push(4);
    o1.push(5);
    check.checkInt(2, o1.popAtStack(0));
    o1.push(20);
    o1.push(21);
    check.checkInt(20, o1.popAtStack(0));
    check.checkInt(21, o1.popAtStack(2));
    check.checkInt(5, o1.pop());
    check.checkInt(4, o1.pop());
    check.checkInt(3, o1.pop());
    check.checkInt(1, o1.pop());
    check.checkInt(-1, o1.pop());

    DinnerPlates o2(2);
    o2.push(132);
    o2.push(417);
    o2.push(114);
    o2.push(340);
    o2.push(224);
    o2.push(401);
    o2.push(28);
    o2.push(267);
    check.checkInt(267, o2.popAtStack(3));
    check.checkInt(401, o2.popAtStack(2));
    o2.push(418);
    o2.push(80);
    o2.push(298);
    o2.push(39);
    o2.push(427);
    o2.push(273);
    o2.push(148);
    o2.push(362);
    check.checkInt(362, o2.pop());
    check.checkInt(148, o2.pop());
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
