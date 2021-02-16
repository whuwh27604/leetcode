/* 将数据流变为多个不相交区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个非负整数的数据流输入 a1，a2，…，an，…，将到目前为止看到的数字总结为不相交的区间列表。

例如，假设数据流中的整数为 1，3，7，2，6，…，每次的总结为：

[1, 1]
[1, 1], [3, 3]
[1, 1], [3, 3], [7, 7]
[1, 3], [7, 7]
[1, 3], [6, 7]
 

进阶：
如果有很多合并，并且与数据流的大小相比，不相交区间的数量很小，该怎么办?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/data-stream-as-disjoint-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {

    }

    void addNum(int val) {
        nums.insert(val);
    }

    vector<vector<int>> getIntervals() {
        if (nums.empty()) {
            return {};
        }

        vector<vector<int>> intervals;
        auto iter = nums.begin();
        int start = *iter, end = *iter;
        
        while (++iter != nums.end()) {
            if (*iter == end + 1) {
                ++end;
            }
            else {
                intervals.push_back({ start, end });
                start = end = *iter;
            }
        }

        intervals.push_back({ start, end });

        return intervals;
    }

private:
    set<int> nums;
};

int main()
{
    CheckResult check;

    SummaryRanges o1;
    vector<vector<int>> actual = o1.getIntervals();
    vector<vector<int>> expected = {};
    check.checkIntVectorVector(expected, actual);
    o1.addNum(5);
    actual = o1.getIntervals();
    expected = { {5,5} };
    check.checkIntVectorVector(expected, actual);

    SummaryRanges o2;
    o2.addNum(1);
    o2.addNum(2);
    o2.addNum(1);
    actual = o2.getIntervals();
    expected = { {1,2} };
    check.checkIntVectorVector(expected, actual);

    SummaryRanges o3;
    o3.addNum(1);
    actual = o3.getIntervals();
    expected = { {1,1} };
    check.checkIntVectorVector(expected, actual);
    o3.addNum(3);
    actual = o3.getIntervals();
    expected = { {1,1},{3,3} };
    check.checkIntVectorVector(expected, actual);
    o3.addNum(7);
    actual = o3.getIntervals();
    expected = { {1,1},{3,3},{7,7} };
    check.checkIntVectorVector(expected, actual);
    o3.addNum(2);
    actual = o3.getIntervals();
    expected = { {1,3},{7,7} };
    check.checkIntVectorVector(expected, actual);
    o3.addNum(6);
    actual = o3.getIntervals();
    expected = { {1,3},{6,7} };
    check.checkIntVectorVector(expected, actual);
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
