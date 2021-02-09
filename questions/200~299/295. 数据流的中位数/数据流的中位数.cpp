/* 数据流的中位数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例：

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3)
findMedian() -> 2
进阶:

如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-median-from-data-stream
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        median = data.end();
    }

    void addNum(int num) {
        int size = data.size();
        data.insert(num);

        if (size == 0) {
            median = data.begin();
        }
        else if ((size & 1) == 1) {
            if (num < *median) {
                --median;
            }
        }
        else {
            if (num >= *median) {  // 如果插入相同的数，会插在原来数的最后面
                ++median;
            }
        }
    }

    double findMedian() {
        if (data.empty()) {
            return 0;
        }

        if ((data.size() & 1) == 1) {
            return *median;
        }

        return ((double)(*median) + (*next(median))) / 2;
    }

private:
    multiset<int> data;
    multiset<int>::iterator median;
};

int main()
{
    CheckResult check;

    MedianFinder o1;
    o1.addNum(1);
    o1.addNum(2);
    check.checkDouble(1.5, o1.findMedian());
    o1.addNum(3);
    check.checkDouble(2, o1.findMedian());

    MedianFinder o2;
    check.checkDouble(0, o2.findMedian());
    o2.addNum(2);
    check.checkDouble(2, o2.findMedian());

    MedianFinder o3;
    o3.addNum(5);
    check.checkDouble(5, o3.findMedian());
    o3.addNum(4);
    check.checkDouble(4.5, o3.findMedian());
    o3.addNum(3);
    check.checkDouble(4, o3.findMedian());
    o3.addNum(2);
    check.checkDouble(3.5, o3.findMedian());
    o3.addNum(1);
    check.checkDouble(3, o3.findMedian());

    MedianFinder o4;
    o4.addNum(5);
    check.checkDouble(5, o4.findMedian());
    o4.addNum(5);
    check.checkDouble(5, o4.findMedian());
    o4.addNum(8);
    check.checkDouble(5, o4.findMedian());
    o4.addNum(8);
    check.checkDouble(6.5, o4.findMedian());
    o4.addNum(8);
    check.checkDouble(8, o4.findMedian());
    o4.addNum(8);
    check.checkDouble(8, o4.findMedian());
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
