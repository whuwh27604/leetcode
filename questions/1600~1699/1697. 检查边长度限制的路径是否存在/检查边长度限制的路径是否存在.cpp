/* 检查边长度限制的路径是否存在.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个 n 个点组成的无向图边集 edgeList ，其中 edgeList[i] = [ui, vi, disi] 表示点 ui 和点 vi 之间有一条长度为 disi 的边。请注意，两个点之间可能有 超过一条边 。

给你一个查询数组queries ，其中 queries[j] = [pj, qj, limitj] ，你的任务是对于每个查询 queries[j] ，判断是否存在从 pj 到 qj 的路径，且这条路径上的每一条边都 严格小于 limitj 。

请你返回一个 布尔数组 answer ，其中 answer.length == queries.length ，当 queries[j] 的查询结果为 true 时， answer 第 j 个值为 true ，否则为 false 。

 

示例 1：


输入：n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
输出：[false,true]
解释：上图为给定的输入数据。注意到 0 和 1 之间有两条重边，分别为 2 和 16 。
对于第一个查询，0 和 1 之间没有小于 2 的边，所以我们返回 false 。
对于第二个查询，有一条路径（0 -> 1 -> 2）两条边都小于 5 ，所以这个查询我们返回 true 。
示例 2：


输入：n = 5, edgeList = [[0,1,10],[1,2,5],[2,3,9],[3,4,13]], queries = [[0,4,14],[1,4,13]]
输出：[true,false]
解释：上图为给定数据。
 

提示：

2 <= n <= 105
1 <= edgeList.length, queries.length <= 105
edgeList[i].length == 3
queries[j].length == 3
0 <= ui, vi, pj, qj <= n - 1
ui != vi
pj != qj
1 <= disi, limitj <= 109
两个点之间可能有 多条 边。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/checking-existence-of-edge-length-limited-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[2] < v2[2];
}

class DSU {
public:
    DSU(int size) {
        parents.resize(size);

        for (int i = 0; i < size; ++i) {
            parents[i] = i;
        }
    }

    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }

        return parents[x];
    }

    void merge(int x, int y) {
        parents[find(x)] = find(y);
    }

private:
    vector<int> parents;
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int i, j = 0, edgeSize = edgeList.size(), querySize = queries.size();
        DSU dsu(n);
        vector<bool> ans(querySize);

        for (i = 0; i < querySize; ++i) {
            queries[i].push_back(i);
        }

        sort(edgeList.begin(), edgeList.end(), vectorCompare);
        sort(queries.begin(), queries.end(), vectorCompare);

        for (i = 0; i < querySize; ++i) {
            for (; j < edgeSize && edgeList[j][2] < queries[i][2]; ++j) {
                dsu.merge(edgeList[j][0], edgeList[j][1]);
            }

            ans[queries[i][3]] = dsu.find(queries[i][0]) == dsu.find(queries[i][1]);
        }

        return ans;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> edgeList = { {0,1,2},{1,2,4},{2,0,8},{1,0,16} };
    vector<vector<int>> queries = { {0,1,2},{0,2,5} };
    vector<bool> actual = o.distanceLimitedPathsExist(3, edgeList, queries);
    vector<bool> expected = { false,true };
    check.checkBoolVector(expected, actual);

    edgeList = { {0,1,10},{1,2,5},{2,3,9},{3,4,13} };
    queries = { {0,4,14},{1,4,13} };
    actual = o.distanceLimitedPathsExist(5, edgeList, queries);
    expected = { true,false };
    check.checkBoolVector(expected, actual);

    edgeList = { {9,1,53},{3,2,66},{12,5,99},{9,7,26},{1,4,78},{11,1,62},{3,10,50},{12,1,71},{12,6,63},{1,10,63},{9,10,88},{9,11,59},{1,4,37},{4,2,63},{0,2,26},{6,12,98},{9,11,99},{4,5,40},{2,8,25},{4,2,35},{8,10,9},{11,9,25},{10,11,11},{7,6,89},{2,4,99},{10,4,63} };
    queries = { {9,7,65},{9,6,1},{4,5,34},{10,8,43},{3,7,76},{4,2,15},{7,6,52},{2,0,50},{7,6,62},{1,0,81},{4,5,35},{0,11,86},{12,5,50},{11,2,2},{9,5,6},{12,0,95},{10,6,9},{9,4,73},{6,10,48},{12,0,91},{9,10,58},{9,8,73},{2,3,44},{7,11,83},{5,3,14},{6,2,33} };
    actual = o.distanceLimitedPathsExist(13, edgeList, queries);
    expected = { true,false,false,true,true,false,false,true,false,true,false,true,false,false,false,true,false,true,false,true,true,true,false,true,false,false };
    check.checkBoolVector(expected, actual);

    edgeList = { {0,1,10} };
    queries = { {0,1,11},{1,0,10} };
    actual = o.distanceLimitedPathsExist(2, edgeList, queries);
    expected = { true,false };
    check.checkBoolVector(expected, actual);
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
