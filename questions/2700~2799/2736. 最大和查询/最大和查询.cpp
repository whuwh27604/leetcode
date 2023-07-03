/* 最大和查询.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你两个长度为 n 、下标从 0 开始的整数数组 nums1 和 nums2 ，另给你一个下标从 1 开始的二维数组 queries ，其中 queries[i] = [xi, yi] 。

对于第 i 个查询，在所有满足 nums1[j] >= xi 且 nums2[j] >= yi 的下标 j (0 <= j < n) 中，找出 nums1[j] + nums2[j] 的 最大值 ，如果不存在满足条件的 j 则返回 -1 。

返回数组 answer ，其中 answer[i] 是第 i 个查询的答案。



示例 1：

输入：nums1 = [4,3,1,2], nums2 = [2,4,9,5], queries = [[4,1],[1,3],[2,5]]
输出：[6,10,7]
解释：
对于第 1 个查询：xi = 4 且 yi = 1 ，可以选择下标 j = 0 ，此时 nums1[j] >= 4 且 nums2[j] >= 1 。nums1[j] + nums2[j] 等于 6 ，可以证明 6 是可以获得的最大值。
对于第 2 个查询：xi = 1 且 yi = 3 ，可以选择下标 j = 2 ，此时 nums1[j] >= 1 且 nums2[j] >= 3 。nums1[j] + nums2[j] 等于 10 ，可以证明 10 是可以获得的最大值。
对于第 3 个查询：xi = 2 且 yi = 5 ，可以选择下标 j = 3 ，此时 nums1[j] >= 2 且 nums2[j] >= 5 。nums1[j] + nums2[j] 等于 7 ，可以证明 7 是可以获得的最大值。
因此，我们返回 [6,10,7] 。
示例 2：

输入：nums1 = [3,2,5], nums2 = [2,3,4], queries = [[4,4],[3,2],[1,1]]
输出：[9,9,9]
解释：对于这个示例，我们可以选择下标 j = 2 ，该下标可以满足每个查询的限制。
示例 3：

输入：nums1 = [2,1], nums2 = [2,3], queries = [[3,3]]
输出：[-1]
解释：示例中的查询 xi = 3 且 yi = 3 。对于每个下标 j ，都只满足 nums1[j] < xi 或者 nums2[j] < yi 。因此，不存在答案。


提示：

nums1.length == nums2.length
n == nums1.length
1 <= n <= 105
1 <= nums1[i], nums2[i] <= 109
1 <= queries.length <= 105
queries[i].length == 2
xi == queries[i][1]
yi == queries[i][2]
1 <= xi, yi <= 109
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Point {
public:
    int x;
    int y;

    Point() : x(0), y(0) {}
    Point(int x_, int y_) : x(x_), y(y_) {}

    bool operator<(const Point& p) const {
        return x == p.x ? y < p.y : x < p.x;
    }
};

class Solution {
public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n = nums1.size(), size = queries.size();
        vector<Point> points(n);
        vector<pair<Point, int>> queryIndices(size);
        vector<int> xys, ys;
        vector<int> ans(size);

        for (int i = 0; i < n; ++i) {
            points[i] = { nums1[i],nums2[i] };
        }

        sort(points.begin(), points.end());

        for (int i = 0; i < size; ++i) {
            queryIndices[i] = { Point(queries[i][0],queries[i][1]),i };
        }

        sort(queryIndices.begin(), queryIndices.end());

        int j = n - 1;
        for (int i = size - 1; i >= 0; --i) {
            int x = queryIndices[i].first.x, y = queryIndices[i].first.y, index = queryIndices[i].second;

            for (; j >= 0 && points[j].x >= x; --j) {  // 将所有大于x的点加入ys栈，并维护xy栈的单调递减
                int xy = points[j].x + points[j].y;

                while (!xys.empty() && xy >= xys.back()) {
                    xys.pop_back();  // x + y >= x' + y'，那么x' + y'永远不可能是答案
                    ys.pop_back();  // 因为x是递减处理的，而x + y >= x' + y'，所以y将是递增的
                }

                if (ys.empty() || points[j].y > ys.back()) {  // 确保ys是递增的
                    xys.push_back(xy);
                    ys.push_back(points[j].y);
                }
            }

            int idx = distance(ys.begin(), lower_bound(ys.begin(), ys.end(), y));  // 第一个大于y的点，同时满足p.x >= x, p.y >= y，并且p.x + p.y是相对最大的
            ans[index] = idx < (int)xys.size() ? xys[idx] : -1;
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> nums1 = { 4,3,1,2 };
    vector<int> nums2 = { 2,4,9,5 };
    vector<vector<int>> queries = { {4,1},{1,3},{2,5} };
    vector<int> actual = o.maximumSumQueries(nums1, nums2, queries);
    vector<int> expected = { 6,10,7 };
    check.checkIntVector(expected, actual);

    nums1 = { 3,2,5 };
    nums2 = { 2,3,4 };
    queries = { {4,4},{3,2},{1,1} };
    actual = o.maximumSumQueries(nums1, nums2, queries);
    expected = { 9,9,9 };
    check.checkIntVector(expected, actual);

    nums1 = { 2,1 };
    nums2 = { 2,3 };
    queries = { {3,3} };
    actual = o.maximumSumQueries(nums1, nums2, queries);
    expected = { -1 };
    check.checkIntVector(expected, actual);

    nums1 = { 89,85 };
    nums2 = { 53,32 };
    queries = { {75,48} };
    actual = o.maximumSumQueries(nums1, nums2, queries);
    expected = { 142 };
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
