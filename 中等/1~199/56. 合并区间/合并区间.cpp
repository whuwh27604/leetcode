/* 合并区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool cmpFunction(vector<int>& i, vector<int>& j) {
    return (i[0] < j[0]);
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }

        sort(intervals.begin(), intervals.end(), cmpFunction);

        vector<vector<int>> merged;
        int i, len = intervals.size(), left = intervals[0][0], right = intervals[0][1];

        for (i = 1; i < len; i++) {
            if (intervals[i][0] <= right) {
                right = (right > intervals[i][1]) ? right : intervals[i][1];
            }
            else {
                merged.push_back({ left, right });
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }

        merged.push_back({ left, right });
        return merged;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> intervals = { {1,3},{2,6},{8,10},{15,18} };
    vector<vector<int>> actual = o.merge(intervals);
    vector<vector<int>> expected = { {1,6},{8,10},{15,18} };
    check.checkIntVectorVector(expected, actual);

    intervals = { {1,4},{4,5} };
    actual = o.merge(intervals);
    expected = { {1,5} };
    check.checkIntVectorVector(expected, actual);

    intervals = {  };
    actual = o.merge(intervals);
    expected = {  };
    check.checkIntVectorVector(expected, actual);

    intervals = { {1,2} };
    actual = o.merge(intervals);
    expected = { {1,2} };
    check.checkIntVectorVector(expected, actual);

    intervals = { {1,2},{2,3},{3,4} };
    actual = o.merge(intervals);
    expected = { {1,4} };
    check.checkIntVectorVector(expected, actual);

    intervals = { {1,2},{0,3} };
    actual = o.merge(intervals);
    expected = { {0,3} };
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
