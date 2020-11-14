/* 插入区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

 

示例 1：

输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
输出：[[1,5],[6,9]]
示例 2：

输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出：[[1,2],[3,10],[12,16]]
解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
 

注意：输入类型已在 2019 年 4 月 15 日更改。请重置为默认代码定义以获取新的方法签名。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-interval
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i, size = intervals.size();
        vector<vector<int>> ans;

        for (i = 0; i < size && intervals[i][1] < newInterval[0]; ++i) {
            ans.push_back(intervals[i]);
        }

        if (i == size) {
            ans.push_back(newInterval);
            return ans;
        }

        int start = min(newInterval[0], intervals[i][0]), end = newInterval[1];

        for (; i < size && intervals[i][0] <= newInterval[1]; ++i) {
            end = max(end, intervals[i][1]);
        }

        ans.push_back({ start, end });

        for (; i < size; ++i) {
            ans.push_back(intervals[i]);
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> intervals = { {1,3},{6,9} };
    vector<int> newInterval = { 2,5 };
    vector<vector<int>> actual = o.insert(intervals, newInterval);
    vector<vector<int>> expected = { {1,5},{6,9} };
    check.checkIntVectorVector(expected, actual);

    intervals = { {1,2},{3,5},{6,7},{8,10},{12,16} };
    newInterval = { 4,8 };
    actual = o.insert(intervals, newInterval);
    expected = { {1,2},{3,10},{12,16} };
    check.checkIntVectorVector(expected, actual);

    intervals = { {10,20},{30,50} };
    newInterval = { 3,8 };
    actual = o.insert(intervals, newInterval);
    expected = { {3,8},{10,20},{30,50} };
    check.checkIntVectorVector(expected, actual);

    intervals = { {10,20},{30,50} };
    newInterval = { 8,12 };
    actual = o.insert(intervals, newInterval);
    expected = { {8,20},{30,50} };
    check.checkIntVectorVector(expected, actual);

    intervals = { {10,20},{30,50} };
    newInterval = { 10,18 };
    actual = o.insert(intervals, newInterval);
    expected = { {10,20},{30,50} };
    check.checkIntVectorVector(expected, actual);

    intervals = { {10,20},{30,50} };
    newInterval = { 18,28 };
    actual = o.insert(intervals, newInterval);
    expected = { {10,28},{30,50} };
    check.checkIntVectorVector(expected, actual);

    intervals = { {10,20},{30,50} };
    newInterval = { 23,28 };
    actual = o.insert(intervals, newInterval);
    expected = { {10,20},{23,28},{30,50} };
    check.checkIntVectorVector(expected, actual);

    intervals = { {10,20},{30,50} };
    newInterval = { 23,38 };
    actual = o.insert(intervals, newInterval);
    expected = { {10,20},{23,50} };
    check.checkIntVectorVector(expected, actual);

    intervals = { {10,20},{30,50} };
    newInterval = { 38,39 };
    actual = o.insert(intervals, newInterval);
    expected = { {10,20},{30,50} };
    check.checkIntVectorVector(expected, actual);

    intervals = { {10,20},{30,50} };
    newInterval = { 33,58 };
    actual = o.insert(intervals, newInterval);
    expected = { {10,20},{30,58} };
    check.checkIntVectorVector(expected, actual);

    intervals = { {10,20},{30,50} };
    newInterval = { 51,58 };
    actual = o.insert(intervals, newInterval);
    expected = { {10,20},{30,50},{51,58} };
    check.checkIntVectorVector(expected, actual);

    intervals = { {10,20},{30,50} };
    newInterval = { 3,38 };
    actual = o.insert(intervals, newInterval);
    expected = { {3,50} };
    check.checkIntVectorVector(expected, actual);

    intervals = { {10,20},{30,50} };
    newInterval = { 13,58 };
    actual = o.insert(intervals, newInterval);
    expected = { {10,58} };
    check.checkIntVectorVector(expected, actual);

    intervals = { {10,20},{30,50} };
    newInterval = { 3,58 };
    actual = o.insert(intervals, newInterval);
    expected = { {3,58} };
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
