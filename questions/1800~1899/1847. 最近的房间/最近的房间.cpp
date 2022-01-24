/* 最近的房间.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
一个酒店里有 n 个房间，这些房间用二维整数数组 rooms 表示，其中 rooms[i] = [roomIdi, sizei] 表示有一个房间号为 roomIdi 的房间且它的面积为 sizei 。每一个房间号 roomIdi 保证是 独一无二 的。

同时给你 k 个查询，用二维数组 queries 表示，其中 queries[j] = [preferredj, minSizej] 。第 j 个查询的答案是满足如下条件的房间 id ：

房间的面积 至少 为 minSizej ，且
abs(id - preferredj) 的值 最小 ，其中 abs(x) 是 x 的绝对值。
如果差的绝对值有 相等 的，选择 最小 的 id 。如果 没有满足条件的房间 ，答案为 -1 。

请你返回长度为 k 的数组 answer ，其中 answer[j] 为第 j 个查询的结果。

 

示例 1：

输入：rooms = [[2,2],[1,2],[3,2]], queries = [[3,1],[3,3],[5,2]]
输出：[3,-1,3]
解释：查询的答案如下：
查询 [3,1] ：房间 3 的面积为 2 ，大于等于 1 ，且号码是最接近 3 的，为 abs(3 - 3) = 0 ，所以答案为 3 。
查询 [3,3] ：没有房间的面积至少为 3 ，所以答案为 -1 。
查询 [5,2] ：房间 3 的面积为 2 ，大于等于 2 ，且号码是最接近 5 的，为 abs(3 - 5) = 2 ，所以答案为 3 。
示例 2：

输入：rooms = [[1,4],[2,3],[3,5],[4,1],[5,2]], queries = [[2,3],[2,4],[2,5]]
输出：[2,1,3]
解释：查询的答案如下：
查询 [2,3] ：房间 2 的面积为 3 ，大于等于 3 ，且号码是最接近的，为 abs(2 - 2) = 0 ，所以答案为 2 。
查询 [2,4] ：房间 1 和 3 的面积都至少为 4 ，答案为 1 因为它房间编号更小。
查询 [2,5] ：房间 3 是唯一面积大于等于 5 的，所以答案为 3 。
 

提示：

n == rooms.length
1 <= n <= 105
k == queries.length
1 <= k <= 104
1 <= roomIdi, preferredj <= 107
1 <= sizei, minSizej <= 107

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/closest-room
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

bool vectorCompare(const vector<int>& v1, const vector<int>& v2) {
    return v1[0] < v2[0];
}

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int size = queries.size();
        vector<int> leftGreater(size, -1), rightGreater(size, -1), closestRoomId(size, -1);
        vector<vector<int>> sortedQueries = queries;

        addIndex(sortedQueries);
        sort(rooms.begin(), rooms.end(), vectorCompare);
        sort(sortedQueries.begin(), sortedQueries.end(), vectorCompare);
        getLeftGreater(rooms, sortedQueries, leftGreater);
        getRightGreater(rooms, sortedQueries, rightGreater);
        getClosestRoomId(queries, leftGreater, rightGreater, closestRoomId);

        return closestRoomId;
    }

    void addIndex(vector<vector<int>>& sortedQueries) {
        int index = 0;

        for (auto& query : sortedQueries) {
            query.push_back(index++);
        }
    }

    void getLeftGreater(vector<vector<int>>& rooms, vector<vector<int>>& sortedQueries, vector<int>& leftGreater) {
        multimap<int, int> rightQueries;
        int j = sortedQueries.size() - 1;

        for (int i = rooms.size() - 1; i >= 0; --i) {
            while (j >= 0 && sortedQueries[j][0] >= rooms[i][0]) {
                rightQueries.insert({ sortedQueries[j][1],sortedQueries[j--][2] });
            }

            auto iter = rightQueries.begin();

            while (iter != rightQueries.end() && iter->first <= rooms[i][1]) {
                leftGreater[iter->second] = rooms[i][0];
                iter = rightQueries.erase(iter);
            }
        }
    }

    void getRightGreater(vector<vector<int>>& rooms, vector<vector<int>>& sortedQueries, vector<int>& rightGreater) {
        multimap<int, int> leftQueries;
        int j = 0, size = sortedQueries.size();

        for (int i = 0; i < (int)rooms.size(); ++i) {
            while (j < size && sortedQueries[j][0] <= rooms[i][0]) {
                leftQueries.insert({ sortedQueries[j][1],sortedQueries[j++][2] });
            }

            auto iter = leftQueries.begin();

            while (iter != leftQueries.end() && iter->first <= rooms[i][1]) {
                rightGreater[iter->second] = rooms[i][0];
                iter = leftQueries.erase(iter);
            }
        }
    }

    void getClosestRoomId(vector<vector<int>>& queries, vector<int>& leftGreater, vector<int>& rightGreater, vector<int>& closestRoomId) {
        for (int i = 0; i < (int)queries.size(); ++i) {
            int id = queries[i][0], left = leftGreater[i], right = rightGreater[i], closest = left;

            if ((left == -1 && right != -1) || (left != -1 && right != -1 && id - left > right - id)) {
                closest = right;
            }

            closestRoomId[i] = closest;
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> rooms = { {2,2},{1,2},{3,2} };
    vector<vector<int>> queries = { {3,1},{3,3},{5,2} };
    vector<int> actual = o.closestRoom(rooms, queries);
    vector<int> expected = { 3,-1,3 };
    check.checkIntVector(expected, actual);

    rooms = { {1,4},{2,3},{3,5},{4,1},{5,2} };
    queries = { {2,3},{2,4},{2,5} };
    actual = o.closestRoom(rooms, queries);
    expected = { 2,1,3 };
    check.checkIntVector(expected, actual);

    rooms = { {1,4} };
    queries = { {1,4} };
    actual = o.closestRoom(rooms, queries);
    expected = { 1 };
    check.checkIntVector(expected, actual);

    rooms = { {1,4} };
    queries = { {1,5} };
    actual = o.closestRoom(rooms, queries);
    expected = { -1 };
    check.checkIntVector(expected, actual);

    rooms = { {2,4},{3,10},{4,1},{5,9},{6,2},{7,7},{8,3},{9,5} };
    queries = { {1,1},{1,5},{1,11},{2,1},{2,8},{2,11},{5,1},{5,3},{5,11},{9,1},{9,6},{9,11},{10000000,1},{10000000,5},{10000000,11} };
    actual = o.closestRoom(rooms, queries);
    expected = { 2,3,-1,2,3,-1,5,5,-1,9,7,-1,9,9,-1 };
    check.checkIntVector(expected, actual);

    rooms = { {23,22},{6,20},{15,6},{22,19},{2,10},{21,4},{10,18},{16,1},{12,7},{5,22} };
    queries = { {12,5},{15,15},{21,6},{15,1},{23,4},{15,11},{1,24},{3,19},{25,8},{18,6} };
    actual = o.closestRoom(rooms, queries);
    expected = { 12,10,22,15,23,10,-1,5,23,15 };
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
