/* 无重叠区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
示例 1:

输入: [ [1,2], [2,3], [3,4], [1,3] ]

输出: 1

解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:

输入: [ [1,2], [1,2], [1,2] ]

输出: 2

解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
示例 3:

输入: [ [1,2], [2,3] ]

输出: 0

解释: 你不需要移除任何区间，因为它们已经是无重叠的了。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/non-overlapping-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int> v1, const vector<int> v2) {
    return v1[1] < v2[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        // 按照结束点贪心选择，就是最后正确的答案。记住这个结论吧，暂未想到简单有效的证明方法。
        sort(intervals.begin(), intervals.end(), vectorCompare);

        int count = 0, currentEnd = intervals[0][1];  // 选中第一个结束点

        for (unsigned int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < currentEnd) {
                count++;  // 重叠，这个区段要删除
            }
            else {
                currentEnd = intervals[i][1];  // 不重叠，更新结束点
            }
        }

        return count;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> intervals = { {1,2},{2,3},{3,4},{1,3} };
    check.checkInt(1, o.eraseOverlapIntervals(intervals));

    intervals = { {1,2},{1,2},{1,2} };
    check.checkInt(2, o.eraseOverlapIntervals(intervals));

    intervals = { {1,2},{2,3} };
    check.checkInt(0, o.eraseOverlapIntervals(intervals));

    intervals = { {1,100},{11,22},{1,11},{2,12} };
    check.checkInt(2, o.eraseOverlapIntervals(intervals));

    intervals = { {1,10},{2,4},{7,9},{3,5},{6,8},{4,7} };
    check.checkInt(3, o.eraseOverlapIntervals(intervals));

    intervals = {  };
    check.checkInt(0, o.eraseOverlapIntervals(intervals));

    intervals = { {1,2} };
    check.checkInt(0, o.eraseOverlapIntervals(intervals));
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
