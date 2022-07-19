/* 我的日程安排表 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
实现一个 MyCalendar 类来存放你的日程安排。如果要添加的时间内不会导致三重预订时，则可以存储这个新的日程安排。

MyCalendar 有一个 book(int start, int end)方法。它意味着在 start 到 end 时间内增加一个日程安排，注意，这里的时间是半开区间，即 [start, end), 实数 x 的范围为，  start <= x < end。

当三个日程安排有一些时间上的交叉时（例如三个日程安排都在同一时间内），就会产生三重预订。

每次调用 MyCalendar.book方法时，如果可以将日程安排成功添加到日历中而不会导致三重预订，返回 true。否则，返回 false 并且不要将该日程安排添加到日历中。

请按照以下步骤调用MyCalendar 类: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)

 

示例：

MyCalendar();
MyCalendar.book(10, 20); // returns true
MyCalendar.book(50, 60); // returns true
MyCalendar.book(10, 40); // returns true
MyCalendar.book(5, 15); // returns false
MyCalendar.book(5, 10); // returns true
MyCalendar.book(25, 55); // returns true
解释：
前两个日程安排可以添加至日历中。 第三个日程安排会导致双重预订，但可以添加至日历中。
第四个日程安排活动（5,15）不能添加至日历中，因为它会导致三重预订。
第五个日程安排（5,10）可以添加至日历中，因为它未使用已经双重预订的时间10。
第六个日程安排（25,55）可以添加至日历中，因为时间 [25,40] 将和第三个日程安排双重预订；
时间 [40,50] 将单独预订，时间 [50,55）将和第二个日程安排双重预订。
 

提示：

每个测试用例，调用 MyCalendar.book 函数最多不超过 1000次。
调用函数 MyCalendar.book(start, end)时， start 和 end 的取值范围为 [0, 10^9]。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/my-calendar-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Calendar {
public:
    int start;
    int end;

    Calendar(int s, int e) : start(s), end(e) {}

    bool operator<(const Calendar& c) const {
        return start == c.start ? end < c.end : start < c.start;
    }
};

class MyCalendarTwo {
public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        if (isTripleBooking(start, end)) {
            return false;
        }

        booking(start, end);

        return true;
    }

    bool isTripleBooking(int start, int end) {
        for (auto iter = overlaps.begin(); iter != overlaps.end() && iter->start < end; ++iter) {
            if (iter->start < end && iter->end > start) {
                return true;
            }
        }

        return false;
    }

    void booking(int start, int end) {
        for (auto iter = calendars.begin(); iter != calendars.end() && iter->start < end; ++iter) {
            if (iter->start < end && iter->end > start) {
                overlaps.insert(Calendar(max(start, iter->start), min(end, iter->end)));
            }
        }

        calendars.insert(Calendar(start, end));
    }

private:
    set<Calendar> calendars;
    set<Calendar> overlaps;
};

int main()
{
    CheckResult check;

    MyCalendarTwo o1;
    check.checkBool(true, o1.book(10, 20));
    check.checkBool(true, o1.book(50, 60));
    check.checkBool(true, o1.book(10, 40));
    check.checkBool(false, o1.book(5, 15));
    check.checkBool(true, o1.book(5, 10));
    check.checkBool(true, o1.book(25, 55));

    MyCalendarTwo o2;
    check.checkBool(true, o2.book(26, 35));
    check.checkBool(true, o2.book(26, 32));
    check.checkBool(false, o2.book(25, 32));
    check.checkBool(true, o2.book(18, 26));
    check.checkBool(true, o2.book(40, 45));
    check.checkBool(true, o2.book(19, 26));
    check.checkBool(true, o2.book(48, 50));
    check.checkBool(true, o2.book(1, 6));
    check.checkBool(true, o2.book(46, 50));
    check.checkBool(true, o2.book(11, 18));
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
