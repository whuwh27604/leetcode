/* 考场就座.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
在考场里，一排有 N 个座位，分别编号为 0, 1, 2, ..., N-1 。

当学生进入考场后，他必须坐在能够使他与离他最近的人之间的距离达到最大化的座位上。如果有多个这样的座位，他会坐在编号最小的座位上。(另外，如果考场里没有人，那么学生就坐在 0 号座位上。)

返回 ExamRoom(int N) 类，它有两个公开的函数：其中，函数 ExamRoom.seat() 会返回一个 int （整型数据），代表学生坐的位置；函数 ExamRoom.leave(int p) 代表坐在座位 p 上的学生现在离开了考场。每次调用 ExamRoom.leave(p) 时都保证有学生坐在座位 p 上。

 

示例：

输入：["ExamRoom","seat","seat","seat","seat","leave","seat"], [[10],[],[],[],[],[4],[]]
输出：[null,0,9,4,2,null,5]
解释：
ExamRoom(10) -> null
seat() -> 0，没有人在考场里，那么学生坐在 0 号座位上。
seat() -> 9，学生最后坐在 9 号座位上。
seat() -> 4，学生最后坐在 4 号座位上。
seat() -> 2，学生最后坐在 2 号座位上。
leave(4) -> null
seat() -> 5，学生最后坐在 5 号座位上。
 

提示：

1 <= N <= 10^9
在所有的测试样例中 ExamRoom.seat() 和 ExamRoom.leave() 最多被调用 10^4 次。
保证在调用 ExamRoom.leave(p) 时有学生正坐在座位 p 上。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/exam-room
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Segment {
public:
    int left;
    int right;
    int n;
    
    Segment() : left(0), right(0), n(0) {}
    Segment(int _l, int _r, int _n) : left(_l), right(_r), n(_n) {}

    bool operator() (const Segment& v1, const Segment& v2) const {
        int space1 = (v1.left == -1) ? (v1.right - 1) : ((v1.right == v1.n) ? (v1.n - v1.left - 2) : ((v1.right - v1.left == 1) ? -1 : (v1.right - v1.left) / 2 - 1));
        int space2 = (v2.left == -1) ? (v2.right - 1) : ((v2.right == v2.n) ? (v2.n - v2.left - 2) : ((v2.right - v2.left == 1) ? -1 : (v2.right - v2.left) / 2 - 1));

        if (space1 == space2) {
            return v1.left < v2.left;
        }

        return space1 > space2;
    }
};

class ExamRoom {
public:
    ExamRoom(int N) {
        n = N;
        Segment s(-1, n, n);
        segments.insert(s);
        seatLR[-1] = { -1,n };
        seatLR[n] = { -1,n };
    }

    int seat() {
        Segment s = *segments.begin();
        int chosenSeat = (s.left + s.right) / 2;
        if (s.left == -1) {
            chosenSeat = 0;
        }
        else if (s.right == n) {
            chosenSeat = n - 1;
        }
        segments.erase(segments.begin());
        Segment s1(s.left, chosenSeat, n);
        segments.insert(s1);
        Segment s2(chosenSeat, s.right, n);
        segments.insert(s2);
        seatLR[s.left].second = chosenSeat;
        seatLR[s.right].first = chosenSeat;
        seatLR[chosenSeat] = { s.left, s.right };

        return chosenSeat;
    }

    void leave(int p) {
        Segment s1(seatLR[p].first, p, n);
        segments.erase(s1);
        Segment s2(p, seatLR[p].second, n);
        segments.erase(s2);
        Segment s(seatLR[p].first, seatLR[p].second, n);
        segments.insert(s);
        seatLR[seatLR[p].first].second = seatLR[p].second;
        seatLR[seatLR[p].second].first = seatLR[p].first;
        seatLR.erase(p);
    }

private:
    int n;
    unordered_map<int, pair<int, int>> seatLR;
    set<Segment, Segment> segments;
};

int main()
{
    CheckResult check;

    ExamRoom o1(10);
    check.checkInt(0, o1.seat());
    check.checkInt(9, o1.seat());
    check.checkInt(4, o1.seat());
    check.checkInt(2, o1.seat());
    o1.leave(0);
    o1.leave(9);
    o1.leave(4);
    o1.leave(2);
    check.checkInt(0, o1.seat());
    check.checkInt(9, o1.seat());
    check.checkInt(4, o1.seat());
    check.checkInt(2, o1.seat());

    ExamRoom o2(4);
    check.checkInt(0, o2.seat());
    check.checkInt(3, o2.seat());
    check.checkInt(1, o2.seat());
    check.checkInt(2, o2.seat());
    o2.leave(1);
    o2.leave(3);
    check.checkInt(1, o2.seat());

    ExamRoom o3(10);
    check.checkInt(0, o3.seat());
    check.checkInt(9, o3.seat());
    check.checkInt(4, o3.seat());
    o3.leave(0);
    o3.leave(4);
    check.checkInt(0, o3.seat());
    check.checkInt(4, o3.seat());
    check.checkInt(2, o3.seat());
    check.checkInt(6, o3.seat());
    check.checkInt(1, o3.seat());
    check.checkInt(3, o3.seat());
    check.checkInt(5, o3.seat());
    check.checkInt(7, o3.seat());
    check.checkInt(8, o3.seat());
    o3.leave(3);

    ExamRoom o4(8);
    check.checkInt(0, o4.seat());
    check.checkInt(7, o4.seat());
    check.checkInt(3, o4.seat());
    o4.leave(0);
    o4.leave(7);
    check.checkInt(7, o4.seat());
    check.checkInt(0, o4.seat());
    check.checkInt(5, o4.seat());
    check.checkInt(1, o4.seat());
    check.checkInt(2, o4.seat());
    check.checkInt(4, o4.seat());
    check.checkInt(6, o4.seat());
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
