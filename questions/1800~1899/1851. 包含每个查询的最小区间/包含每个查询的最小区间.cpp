/* 包含每个查询的最小区间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维整数数组 intervals ，其中 intervals[i] = [lefti, righti] 表示第 i 个区间开始于 lefti 、结束于 righti（包含两侧取值，闭区间）。区间的 长度 定义为区间中包含的整数数目，更正式地表达是 righti - lefti + 1 。

再给你一个整数数组 queries 。第 j 个查询的答案是满足 lefti <= queries[j] <= righti 的 长度最小区间 i 的长度 。如果不存在这样的区间，那么答案是 -1 。

以数组形式返回对应查询的所有答案。

 

示例 1：

输入：intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
输出：[3,3,1,4]
解释：查询处理如下：
- Query = 2 ：区间 [2,4] 是包含 2 的最小区间，答案为 4 - 2 + 1 = 3 。
- Query = 3 ：区间 [2,4] 是包含 3 的最小区间，答案为 4 - 2 + 1 = 3 。
- Query = 4 ：区间 [4,4] 是包含 4 的最小区间，答案为 4 - 4 + 1 = 1 。
- Query = 5 ：区间 [3,6] 是包含 5 的最小区间，答案为 6 - 3 + 1 = 4 。
示例 2：

输入：intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
输出：[2,-1,4,6]
解释：查询处理如下：
- Query = 2 ：区间 [2,3] 是包含 2 的最小区间，答案为 3 - 2 + 1 = 2 。
- Query = 19：不存在包含 19 的区间，答案为 -1 。
- Query = 5 ：区间 [2,5] 是包含 5 的最小区间，答案为 5 - 2 + 1 = 4 。
- Query = 22：区间 [20,25] 是包含 22 的最小区间，答案为 25 - 20 + 1 = 6 。
 

提示：

1 <= intervals.length <= 105
1 <= queries.length <= 105
queries[i].length == 2
1 <= lefti <= righti <= 107
1 <= queries[j] <= 107

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-interval-to-include-each-query
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <set>
#include "../check/CheckResult.h"

using namespace std;

bool intervalCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[1] - v1[0] < v2[1] - v2[0];  // 按照interval的长短排序
}

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int size = queries.size();
        vector<int> responses(size);
        set<long long> queryIndices;

        sort(intervals.begin(), intervals.end(), intervalCompare);

        for (int i = 0; i < size; ++i) {
            queryIndices.insert(((long long)queries[i] << 32) | i);
        }

        for (auto& interval : intervals) {
            int len = interval[1] - interval[0] + 1;
            auto itStart = queryIndices.lower_bound((long long)interval[0] << 32);
            auto itEnd = queryIndices.lower_bound(((long long)interval[1] + 1) << 32);

            while (itStart != itEnd) {
                responses[(int)(*itStart)] = len;
                itStart = queryIndices.erase(itStart);
            }
        }

        for (auto iter = queryIndices.begin(); iter != queryIndices.end(); ++iter) {
            responses[(int)(*iter)] = -1;
        }

        return responses;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> intervals = { {1,4},{2,4},{3,6},{4,4} };
    vector<int> queries = { 2,3,4,5 };
    vector<int> actual = o.minInterval(intervals, queries);
    vector<int> expected = { 3,3,1,4 };
    check.checkIntVector(expected, actual);

    intervals = { {2,3},{2,5},{1,8},{20,25} };
    queries = { 2,19,5,22 };
    actual = o.minInterval(intervals, queries);
    expected = { 2,-1,4,6 };
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
