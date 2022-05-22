/* 统计区间中的整数数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你区间的 空 集，请你设计并实现满足要求的数据结构：

新增：添加一个区间到这个区间集合中。
统计：计算出现在 至少一个 区间中的整数个数。
实现 CountIntervals 类：

CountIntervals() 使用区间的空集初始化对象
void add(int left, int right) 添加区间 [left, right] 到区间集合之中。
int count() 返回出现在 至少一个 区间中的整数个数。
注意：区间 [left, right] 表示满足 left <= x <= right 的所有整数 x 。

 

示例 1：

输入
["CountIntervals", "add", "add", "count", "add", "count"]
[[], [2, 3], [7, 10], [], [5, 8], []]
输出
[null, null, null, 6, null, 8]

解释
CountIntervals countIntervals = new CountIntervals(); // 用一个区间空集初始化对象
countIntervals.add(2, 3);  // 将 [2, 3] 添加到区间集合中
countIntervals.add(7, 10); // 将 [7, 10] 添加到区间集合中
countIntervals.count();    // 返回 6
                           // 整数 2 和 3 出现在区间 [2, 3] 中
                           // 整数 7、8、9、10 出现在区间 [7, 10] 中
countIntervals.add(5, 8);  // 将 [5, 8] 添加到区间集合中
countIntervals.count();    // 返回 8
                           // 整数 2 和 3 出现在区间 [2, 3] 中
                           // 整数 5 和 6 出现在区间 [5, 8] 中
                           // 整数 7 和 8 出现在区间 [5, 8] 和区间 [7, 10] 中
                           // 整数 9 和 10 出现在区间 [7, 10] 中
 

提示：

1 <= left <= right <= 109
最多调用  add 和 count 方法 总计 105 次
调用 count 方法至少一次

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-integers-in-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Interval {
public:
    int start;
    int end;

    Interval(int s, int e) : start(s), end(e) {}

    bool operator<(const Interval& o) const {
        return end < o.start;
    }
};

class CountIntervals {
public:
    CountIntervals() {
        nums = 0;
    }

    void add(int left, int right) {
        Interval interval(left, left);
        auto iter = intervals.lower_bound(interval);

        while (iter != intervals.end() && iter->start <= right) {
            left = min(left, iter->start);
            right = max(right, iter->end);
            nums -= (iter->end - iter->start + 1);
            iter = intervals.erase(iter);
        }

        nums += (right - left + 1);
        intervals.insert(Interval(left, right));
    }

    int count() {
        return nums;
    }

private:
    set<Interval> intervals;
    int nums;
};

int main()
{
    CheckResult check;

    CountIntervals o1;
    o1.add(2, 3);
    o1.add(7, 10);
    check.checkInt(6, o1.count());
    o1.add(5, 8);
    check.checkInt(8, o1.count());

    CountIntervals o2;
    check.checkInt(0, o2.count());
    o2.add(39, 44);
    o2.add(13, 49);
    check.checkInt(37, o2.count());
    check.checkInt(37, o2.count());
    o2.add(47, 50);

    CountIntervals o3;
    check.checkInt(0, o3.count());
    o3.add(8, 43);
    o3.add(13, 16);
    o3.add(26, 33);
    o3.add(28, 36);
    o3.add(29, 37);
    check.checkInt(36, o3.count());
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
