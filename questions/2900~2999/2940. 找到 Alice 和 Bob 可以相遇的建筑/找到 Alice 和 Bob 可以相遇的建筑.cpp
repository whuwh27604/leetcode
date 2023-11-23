/* 找到 Alice 和 Bob 可以相遇的建筑.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个下标从 0 开始的正整数数组 heights ，其中 heights[i] 表示第 i 栋建筑的高度。

如果一个人在建筑 i ，且存在 i < j 的建筑 j 满足 heights[i] < heights[j] ，那么这个人可以移动到建筑 j 。

给你另外一个数组 queries ，其中 queries[i] = [ai, bi] 。第 i 个查询中，Alice 在建筑 ai ，Bob 在建筑 bi 。

请你能返回一个数组 ans ，其中 ans[i] 是第 i 个查询中，Alice 和 Bob 可以相遇的 最左边的建筑 。如果对于查询 i ，Alice 和 Bob 不能相遇，令 ans[i] 为 -1 。



示例 1：

输入：heights = [6,4,8,5,2,7], queries = [[0,1],[0,3],[2,4],[3,4],[2,2]]
输出：[2,5,-1,5,2]
解释：第一个查询中，Alice 和 Bob 可以移动到建筑 2 ，因为 heights[0] < heights[2] 且 heights[1] < heights[2] 。
第二个查询中，Alice 和 Bob 可以移动到建筑 5 ，因为 heights[0] < heights[5] 且 heights[3] < heights[5] 。
第三个查询中，Alice 无法与 Bob 相遇，因为 Alice 不能移动到任何其他建筑。
第四个查询中，Alice 和 Bob 可以移动到建筑 5 ，因为 heights[3] < heights[5] 且 heights[4] < heights[5] 。
第五个查询中，Alice 和 Bob 已经在同一栋建筑中。
对于 ans[i] != -1 ，ans[i] 是 Alice 和 Bob 可以相遇的建筑中最左边建筑的下标。
对于 ans[i] == -1 ，不存在 Alice 和 Bob 可以相遇的建筑。
示例 2：

输入：heights = [5,3,8,2,6,1,4,6], queries = [[0,7],[3,5],[5,2],[3,0],[1,6]]
输出：[7,6,-1,4,6]
解释：第一个查询中，Alice 可以直接移动到 Bob 的建筑，因为 heights[0] < heights[7] 。
第二个查询中，Alice 和 Bob 可以移动到建筑 6 ，因为 heights[3] < heights[6] 且 heights[5] < heights[6] 。
第三个查询中，Alice 无法与 Bob 相遇，因为 Bob 不能移动到任何其他建筑。
第四个查询中，Alice 和 Bob 可以移动到建筑 4 ，因为 heights[3] < heights[4] 且 heights[0] < heights[4] 。
第五个查询中，Alice 可以直接移动到 Bob 的建筑，因为 heights[1] < heights[6] 。
对于 ans[i] != -1 ，ans[i] 是 Alice 和 Bob 可以相遇的建筑中最左边建筑的下标。
对于 ans[i] == -1 ，不存在 Alice 和 Bob 可以相遇的建筑。


提示：

1 <= heights.length <= 5 * 104
1 <= heights[i] <= 109
1 <= queries.length <= 5 * 104
queries[i] = [ai, bi]
0 <= ai, bi <= heights.length - 1
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Node {
public:
    int a;
    int b;
    int index;

    Node() : a(0), b(0), index(0) {}
    Node(int x, int y, int idx) : a(x), b(y), index(idx) {}

    bool operator<(const Node& node) const {
        return b < node.b;
    }
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int size = queries.size();
        vector<int> ans(size);
        vector<Node> nodes(size);
        vector<pair<int, int>> heightIndices;

        for (int i = 0; i < size; ++i) {
            int a = queries[i][0], b = queries[i][1];
            if (a > b) {
                swap(a, b);
            }
            nodes[i] = Node(a,b,i);
        }

        sort(nodes.begin(), nodes.end());  // 离线查询，按照查询的 b 从大到小的顺利处理

        int j = heights.size() - 1;
        for (int i = size - 1; i >= 0; --i) {
            int a = nodes[i].a, b = nodes[i].b, index = nodes[i].index;

            while (j >= b) {  // 每一次，将所有 b 大于当前查询 b 的heights加入heightIndices
                int height = heights[j];
                while (!heightIndices.empty() && heightIndices.back().first <= height) {
                    heightIndices.pop_back();  // 维护heightIndices的单调递减性，小于当前height的heights没有必要继续保留，因为它们在当前height的右边，不可能跳到
                }

                heightIndices.push_back({ height,j });
                --j;
            }

            if (a == b || heights[a] < heights[b]) {  // a直接跳到b即可
                ans[index] = b;
            }
            else {
                ans[index] = getFirstGreater(heightIndices, heights[a]);  // 二分找第一个大于heights[a]的位置
            }
        }

        return ans;
    }

    int getFirstGreater(vector<pair<int, int>>& heightIndices, int height) {
        int low = 0, high = heightIndices.size() - 1, ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (heightIndices[mid].first > height) {
                ans = heightIndices[mid].second;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<int> heights = { 6,4,8,5,2,7 };
    vector<vector<int>> queries = { {0,1},{0,3},{2,4},{3,4},{2,2} };
    vector<int> actual = o.leftmostBuildingQueries(heights, queries);
    vector<int> expected = { 2,5,-1,5,2 };
    check.checkIntVector(expected, actual);

    heights = { 5,3,8,2,6,1,4,6 };
    queries = { {0,7},{3,5},{5,2},{3,0},{1,6} };
    actual = o.leftmostBuildingQueries(heights, queries);
    expected = { 7,6,-1,4,6 };
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
