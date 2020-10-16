/* 寻找右区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一组区间，对于每一个区间 i，检查是否存在一个区间 j，它的起始点大于或等于区间 i 的终点，这可以称为 j 在 i 的“右侧”。

对于任何区间，你需要存储的满足条件的区间 j 的最小索引，这意味着区间 j 有最小的起始点可以使其成为“右侧”区间。如果区间 j 不存在，则将区间 i 存储为 -1。最后，你需要输出一个值为存储的区间值的数组。

注意:

你可以假设区间的终点总是大于它的起始点。
你可以假定这些区间都不具有相同的起始点。
示例 1:

输入: [ [1,2] ]
输出: [-1]

解释:集合中只有一个区间，所以输出-1。
示例 2:

输入: [ [3,4], [2,3], [1,2] ]
输出: [-1, 0, 1]

解释:对于[3,4]，没有满足条件的“右侧”区间。
对于[2,3]，区间[3,4]具有最小的“右”起点;
对于[1,2]，区间[2,3]具有最小的“右”起点。
示例 3:

输入: [ [1,4], [2,3], [3,4] ]
输出: [-1, 2, -1]

解释:对于区间[1,4]和[3,4]，没有满足条件的“右侧”区间。
对于[2,3]，区间[3,4]有最小的“右”起点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-right-interval
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

struct VectrorCompare {
    bool operator() (const vector<int>& v1, const vector<int>& v2) const {
        return v1[0] < v2[0];
    }
};

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<vector<int>, int, VectrorCompare> startSortedIntervals;
        int size = intervals.size();
        vector<int> rightIntervalIndexs(size, 0);

        for (int i = 0; i < size; i++) {
            startSortedIntervals[intervals[i]] = i;
        }

        for (auto iter = startSortedIntervals.begin(); iter != startSortedIntervals.end(); iter++) {
            auto itRight = startSortedIntervals.lower_bound({ iter->first[1] });
            int index = (itRight == startSortedIntervals.end()) ? -1 : itRight->second;
            rightIntervalIndexs[iter->second] = index;
        }

        return rightIntervalIndexs;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> intervals = { {1,2} };
    vector<int> actual = o.findRightInterval(intervals);
    vector<int> expected = { -1 };
    check.checkIntVector(expected, actual);

    intervals = { {1,4},{2,3},{3,4} };
    actual = o.findRightInterval(intervals);
    expected = { -1,2,-1 };
    check.checkIntVector(expected, actual);

    intervals = { {3,4},{2,3},{1,2} };
    actual = o.findRightInterval(intervals);
    expected = { -1,0,1 };
    check.checkIntVector(expected, actual);

    intervals = { {5,8},{1,9},{2,4} };
    actual = o.findRightInterval(intervals);
    expected = { -1,-1,0 };
    check.checkIntVector(expected, actual);

    intervals = { {2,8},{1,9},{3,7},{4,6} };
    actual = o.findRightInterval(intervals);
    expected = { -1,-1,-1,-1 };
    check.checkIntVector(expected, actual);

    intervals = {  };
    actual = o.findRightInterval(intervals);
    expected = {  };
    check.checkIntVector(expected, actual);

    intervals = { {2,8},{3,7},{5,9},{4,6},{1,6},{7,10},{6,11} };
    actual = o.findRightInterval(intervals);
    expected = { -1,5,-1,6,6,-1,-1 };
    check.checkIntVector(expected, actual);
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
