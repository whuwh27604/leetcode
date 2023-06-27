/* 统计没有收到请求的服务器数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n ，表示服务器的总数目，再给你一个下标从 0 开始的 二维 整数数组 logs ，其中 logs[i] = [server_id, time] 表示 id 为 server_id 的服务器在 time 时收到了一个请求。

同时给你一个整数 x 和一个下标从 0 开始的整数数组 queries  。

请你返回一个长度等于 queries.length 的数组 arr ，其中 arr[i] 表示在时间区间 [queries[i] - x, queries[i]] 内没有收到请求的服务器数目。

注意时间区间是个闭区间。



示例 1：

输入：n = 3, logs = [[1,3],[2,6],[1,5]], x = 5, queries = [10,11]
输出：[1,2]
解释：
对于 queries[0]：id 为 1 和 2 的服务器在区间 [5, 10] 内收到了请求，所以只有服务器 3 没有收到请求。
对于 queries[1]：id 为 2 的服务器在区间 [6,11] 内收到了请求，所以 id 为 1 和 3 的服务器在这个时间段内没有收到请求。
示例 2：

输入：n = 3, logs = [[2,4],[2,1],[1,2],[3,1]], x = 2, queries = [3,4]
输出：[0,1]
解释：
对于 queries[0]：区间 [1, 3] 内所有服务器都收到了请求。
对于 queries[1]：只有 id 为 3 的服务器在区间 [2,4] 内没有收到请求。


提示：

1 <= n <= 105
1 <= logs.length <= 105
1 <= queries.length <= 105
logs[i].length == 2
1 <= logs[i][0] <= n
1 <= logs[i][1] <= 106
1 <= x <= 105
x < queries[i] <= 106
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(vector<int>& v1, vector<int>& v2) {
    return v1[1] < v2[1];  // 按time排序
}

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int size = queries.size();
        vector<int> ans(size);
        vector<vector<int>> queryIndices(size);

        for (int i = 0; i < size; ++i) {
            queryIndices[i] = { queries[i],i };
        }

        sort(queryIndices.begin(), queryIndices.end());  // 按query的time排序
        sort(logs.begin(), logs.end(), vectorCompare);  // 按log的time排序

        int sizeLog = logs.size(), left = 0, right = 0;
        unordered_map<int, int> count;

        for (int i = 0; i < size; ++i) {
            while (right < sizeLog && logs[right][1] <= queryIndices[i][0]) {
                ++count[logs[right++][0]];  // 将所有小于等于query时间的id移入
            }

            while (left < sizeLog && logs[left][1] < queryIndices[i][0] - x) {
                int id = logs[left++][0];
                if (--count[id] == 0) {  // 将所有范围外的id移出
                    count.erase(id);
                }
            }

            ans[queryIndices[i][1]] = n - (int)count.size();
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> logs = { {1,3},{2,6},{1,5} };
    vector<int> queries = { 10,11 };
    vector<int> actual = o.countServers(3, logs, 5, queries);
    vector<int> expected = { 1,2 };
    check.checkIntVector(expected, actual);

    logs = { {2,4},{2,1},{1,2},{3,1} };
    queries = { 3,4 };
    actual = o.countServers(3, logs, 2, queries);
    expected = { 0,1 };
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
