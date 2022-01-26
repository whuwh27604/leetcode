/* 最多可以参加的会议数目 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 events 数组，其中 events[i] = [startDayi, endDayi, valuei] ，表示第 i 个会议在 startDayi 天开始，第 endDayi 天结束，如果你参加这个会议，你能得到价值 valuei 。同时给你一个整数 k 表示你能参加的最多会议数目。

你同一时间只能参加一个会议。如果你选择参加某个会议，那么你必须 完整 地参加完这个会议。会议结束日期是包含在会议内的，也就是说你不能同时参加一个开始日期与另一个结束日期相同的两个会议。

请你返回能得到的会议价值 最大和 。

 

示例 1：



输入：events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
输出：7
解释：选择绿色的活动会议 0 和 1，得到总价值和为 4 + 3 = 7 。
示例 2：



输入：events = [[1,2,4],[3,4,3],[2,3,10]], k = 2
输出：10
解释：参加会议 2 ，得到价值和为 10 。
你没法再参加别的会议了，因为跟会议 2 有重叠。你 不 需要参加满 k 个会议。
示例 3：



输入：events = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]], k = 3
输出：9
解释：尽管会议互不重叠，你只能参加 3 个会议，所以选择价值最大的 3 个会议。
 

提示：

1 <= k <= events.length
1 <= k * events.length <= 106
1 <= startDayi <= endDayi <= 109
1 <= valuei <= 106

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] < v2[0];  // 按开始时间排序
}

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int i, j, size = events.size();
        vector<vector<int>> dp(size + 1, vector<int>(k + 1, 0));
        vector<int> next(size, size);

        sort(events.begin(), events.end(), vectorCompare);
        getNext(events, next);
        
        for (j = 1; j <= k; ++j) {
            dp[size - 1][j] = events[size - 1][2];  // 只有最后一个会议，选它肯定最优
        }
        
        for (i = size - 2; i >= 0; --i) {
            for (j = 1; j <= k; ++j) {
                dp[i][j] = max(dp[i + 1][j], dp[next[i]][j - 1] + events[i][2]);  // 两个选择：1、不选当前会议，从下一个开始选j个；2、选当前会议，从下一个可选会议开始选j - 1个
            }
        }

        return dp[0][k];
    }

    void getNext(vector<vector<int>>& events, vector<int>& next) {
        for (int i = 0; i < (int)next.size() - 1; ++i) {
            vector<int> end = { events[i][1] };
            next[i] = distance(events.begin(), upper_bound(events.begin(), events.end(), end, vectorCompare));
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> events = { {1,2,4},{3,4,3},{2,3,1} };
    check.checkInt(7, o.maxValue(events, 2));

    events = { {1,2,4},{3,4,3},{2,3,10} };
    check.checkInt(10, o.maxValue(events, 2));

    events = { {1,1,1},{2,2,2},{3,3,3},{4,4,4} };
    check.checkInt(9, o.maxValue(events, 3));

    events = { {1,1,1} };
    check.checkInt(1, o.maxValue(events, 1));
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
