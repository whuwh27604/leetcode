/* 两个最好的不重叠活动.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的二维整数数组 events ，其中 events[i] = [startTimei, endTimei, valuei] 。第 i 个活动开始于 startTimei ，结束于 endTimei ，如果你参加这个活动，那么你可以得到价值 valuei 。你 最多 可以参加 两个时间不重叠 活动，使得它们的价值之和 最大 。

请你返回价值之和的 最大值 。

注意，活动的开始时间和结束时间是 包括 在活动时间内的，也就是说，你不能参加两个活动且它们之一的开始时间等于另一个活动的结束时间。更具体的，如果你参加一个活动，且结束时间为 t ，那么下一个活动必须在 t + 1 或之后的时间开始。

 

示例 1:



输入：events = [[1,3,2],[4,5,2],[2,4,3]]
输出：4
解释：选择绿色的活动 0 和 1 ，价值之和为 2 + 2 = 4 。
示例 2：



输入：events = [[1,3,2],[4,5,2],[1,5,5]]
输出：5
解释：选择活动 2 ，价值和为 5 。
示例 3：



输入：events = [[1,5,3],[1,5,1],[6,6,5]]
输出：8
解释：选择活动 0 和 2 ，价值之和为 3 + 5 = 8 。
 

提示：

2 <= events.length <= 105
events[i].length == 3
1 <= startTimei <= endTimei <= 109
1 <= valuei <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-best-non-overlapping-events
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] < v2[0];  // 按照start排序
}

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int i, size = events.size(), maxValue = 0, maxTwo = 0;
        vector<int> maxValues(size);

        sort(events.begin(), events.end(), vectorCompare);

        for (i = size - 1; i >= 0; --i) {
            maxValue = max(maxValue, events[i][2]);
            maxValues[i] = maxValue;
        }

        for (auto& event : events) {
            int one = event[2], end = event[1];
            vector<int> start = { end };
            auto iter = upper_bound(events.begin(), events.end(), start, vectorCompare);
            int two = (iter == events.end() ? 0 : maxValues[distance(events.begin(), iter)]);
            maxTwo = max(maxTwo, one + two);
        }

        return maxTwo;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> events = { {1,3,2},{4,5,2},{2,4,3} };
    check.checkInt(4, o.maxTwoEvents(events));

    events = { {1,3,2},{4,5,2},{1,5,5} };
    check.checkInt(5, o.maxTwoEvents(events));

    events = { {1,5,3},{1,5,1},{6,6,5} };
    check.checkInt(8, o.maxTwoEvents(events));
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
