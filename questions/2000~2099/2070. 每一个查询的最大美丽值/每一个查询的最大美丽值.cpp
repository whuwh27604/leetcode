/* 每一个查询的最大美丽值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个二维整数数组 items ，其中 items[i] = [pricei, beautyi] 分别表示每一个物品的 价格 和 美丽值 。

同时给你一个下标从 0 开始的整数数组 queries 。对于每个查询 queries[j] ，你想求出价格小于等于 queries[j] 的物品中，最大的美丽值 是多少。如果不存在符合条件的物品，那么查询的结果为 0 。

请你返回一个长度与 queries 相同的数组 answer，其中 answer[j]是第 j 个查询的答案。

 

示例 1：

输入：items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
输出：[2,4,5,5,6,6]
解释：
- queries[0]=1 ，[1,2] 是唯一价格 <= 1 的物品。所以这个查询的答案为 2 。
- queries[1]=2 ，符合条件的物品有 [1,2] 和 [2,4] 。
  它们中的最大美丽值为 4 。
- queries[2]=3 和 queries[3]=4 ，符合条件的物品都为 [1,2] ，[3,2] ，[2,4] 和 [3,5] 。
  它们中的最大美丽值为 5 。
- queries[4]=5 和 queries[5]=6 ，所有物品都符合条件。
  所以，答案为所有物品中的最大美丽值，为 6 。
示例 2：

输入：items = [[1,2],[1,2],[1,3],[1,4]], queries = [1]
输出：[4]
解释：
每个物品的价格均为 1 ，所以我们选择最大美丽值 4 。
注意，多个物品可能有相同的价格和美丽值。
示例 3：

输入：items = [[10,1000]], queries = [5]
输出：[0]
解释：
没有物品的价格小于等于 5 ，所以没有物品可以选择。
因此，查询的结果为 0 。
 

提示：

1 <= items.length, queries.length <= 105
items[i].length == 2
1 <= pricei, beautyi, queries[j] <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/most-beautiful-item-for-each-query
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] < v2[0];
}

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int maxBeauty = 0, i, size = queries.size();
        vector<int> maxBeauties(size);

        sort(items.begin(), items.end(), vectorCompare);

        for (auto& item : items) {
            maxBeauty = max(maxBeauty, item[1]);
            item[1] = maxBeauty;
        }

        for (i = 0; i < size; ++i) {
            vector<int> tmp = { queries[i] };
            auto iter = upper_bound(items.begin(), items.end(), tmp, vectorCompare);
            maxBeauties[i] = (iter == items.begin() ? 0 : (*--iter)[1]);
        }

        return maxBeauties;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> items = { {1,2},{3,2},{2,4},{5,6},{3,5} };
    vector<int> queries = { 1,2,3,4,5,6 };
    vector<int> actual = o.maximumBeauty(items, queries);
    vector<int> expected = { 2,4,5,5,6,6 };
    check.checkIntVector(expected, actual);

    items = { {1,2},{1,2},{1,3},{1,4} };
    queries = { 1 };
    actual = o.maximumBeauty(items, queries);
    expected = { 4 };
    check.checkIntVector(expected, actual);

    items = { {10,1000} };
    queries = { 5 };
    actual = o.maximumBeauty(items, queries);
    expected = { 0 };
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
