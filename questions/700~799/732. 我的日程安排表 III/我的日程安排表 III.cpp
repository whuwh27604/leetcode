/* 我的日程安排表 III.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
当 k 个日程安排有一些时间上的交叉时（例如 k 个日程安排都在同一时间内），就会产生 k 次预订。

给你一些日程安排 [start, end) ，请你在每个日程安排添加后，返回一个整数 k ，表示所有先前日程安排会产生的最大 k 次预订。

实现一个 MyCalendarThree 类来存放你的日程安排，你可以一直添加新的日程安排。

MyCalendarThree() 初始化对象。
int book(int start, int end) 返回一个整数 k ，表示日历中存在的 k 次预订的最大值。
 

示例：

输入：
["MyCalendarThree", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
输出：
[null, 1, 1, 2, 3, 3, 3]

解释：
MyCalendarThree myCalendarThree = new MyCalendarThree();
myCalendarThree.book(10, 20); // 返回 1 ，第一个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
myCalendarThree.book(50, 60); // 返回 1 ，第二个日程安排可以预订并且不存在相交，所以最大 k 次预订是 1 次预订。
myCalendarThree.book(10, 40); // 返回 2 ，第三个日程安排 [10, 40) 与第一个日程安排相交，所以最大 k 次预订是 2 次预订。
myCalendarThree.book(5, 15); // 返回 3 ，剩下的日程安排的最大 k 次预订是 3 次预订。
myCalendarThree.book(5, 10); // 返回 3
myCalendarThree.book(25, 55); // 返回 3
 

提示：

0 <= start < end <= 109
每个测试用例，调用 book 函数最多不超过 400次

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/my-calendar-iii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class MyCalendarThree {
public:
    MyCalendarThree() {

    }

    void update(int start, int end, int left, int right, int idx) {
        if (right < start || end < left) {
            return;
        }
        if (start <= left && right <= end) {
            tree[idx].first++;
            tree[idx].second++;
        }
        else {
            int mid = (left + right) / 2;
            update(start, end, left, mid, 2 * idx);
            update(start, end, mid + 1, right, 2 * idx + 1);
            tree[idx].first = tree[idx].second + max(tree[2 * idx].first, tree[2 * idx + 1].first);
        }
    }

    int book(int start, int end) {
        update(start, end - 1, 0, 1000000000, 1);

        return tree[1].first;
    }

private:
    unordered_map<int, pair<int, int>> tree;
};

int main()
{
    CheckResult check;

    MyCalendarThree o1;
    check.checkInt(1, o1.book(10, 20));
    check.checkInt(1, o1.book(50, 60));
    check.checkInt(2, o1.book(10, 40));
    check.checkInt(3, o1.book(5, 15));
    check.checkInt(3, o1.book(5, 10));
    check.checkInt(3, o1.book(25, 55));

    MyCalendarThree o2;
    check.checkInt(1, o2.book(47, 50));
    check.checkInt(1, o2.book(1, 10));
    check.checkInt(1, o2.book(27, 36));
    check.checkInt(1, o2.book(40, 47));
    check.checkInt(1, o2.book(20, 27));
    check.checkInt(2, o2.book(15, 23));
    check.checkInt(2, o2.book(10, 18));
    check.checkInt(2, o2.book(27, 36));
    check.checkInt(3, o2.book(17, 25));
    check.checkInt(3, o2.book(8, 17));
    check.checkInt(3, o2.book(24, 33));
    check.checkInt(4, o2.book(23, 28));
    check.checkInt(5, o2.book(21, 27));
    check.checkInt(5, o2.book(47, 50));
    check.checkInt(5, o2.book(14, 21));
    check.checkInt(5, o2.book(26, 32));
    check.checkInt(5, o2.book(16, 21));
    check.checkInt(5, o2.book(2, 7));
    check.checkInt(6, o2.book(24, 33));
    check.checkInt(6, o2.book(6, 13));
    check.checkInt(6, o2.book(44, 50));
    check.checkInt(6, o2.book(33, 39));
    check.checkInt(6, o2.book(30, 36));
    check.checkInt(6, o2.book(6, 15));
    check.checkInt(7, o2.book(21, 27));
    check.checkInt(7, o2.book(49, 50));
    check.checkInt(7, o2.book(38, 45));
    check.checkInt(7, o2.book(4, 12));
    check.checkInt(7, o2.book(46, 50));
    check.checkInt(7, o2.book(13, 21));
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
