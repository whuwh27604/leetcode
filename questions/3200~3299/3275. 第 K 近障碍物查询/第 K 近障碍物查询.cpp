/* 第 K 近障碍物查询.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一个无限大的二维平面。

给你一个正整数 k ，同时给你一个二维数组 queries ，包含一系列查询：

queries[i] = [x, y] ：在平面上坐标 (x, y) 处建一个障碍物，数据保证之前的查询 不会 在这个坐标处建立任何障碍物。
每次查询后，你需要找到离原点第 k 近 障碍物到原点的 距离 。

请你返回一个整数数组 results ，其中 results[i] 表示建立第 i 个障碍物以后，离原地第 k 近障碍物距离原点的距离。如果少于 k 个障碍物，results[i] == -1 。

注意，一开始 没有 任何障碍物。

坐标在 (x, y) 处的点距离原点的距离定义为 |x| + |y| 。



示例 1：

输入：queries = [[1,2],[3,4],[2,3],[-3,0]], k = 2

输出：[-1,7,5,3]

解释：

最初，不存在障碍物。

queries[0] 之后，少于 2 个障碍物。
queries[1] 之后， 两个障碍物距离原点的距离分别为 3 和 7 。
queries[2] 之后，障碍物距离原点的距离分别为 3 ，5 和 7 。
queries[3] 之后，障碍物距离原点的距离分别为 3，3，5 和 7 。
示例 2：

输入：queries = [[5,5],[4,4],[3,3]], k = 1

输出：[10,8,6]

解释：

queries[0] 之后，只有一个障碍物，距离原点距离为 10 。
queries[1] 之后，障碍物距离原点距离分别为 8 和 10 。
queries[2] 之后，障碍物距离原点的距离分别为 6， 8 和10 。


提示：

1 <= queries.length <= 2 * 105
所有 queries[i] 互不相同。
-109 <= queries[i][0], queries[i][1] <= 109
1 <= k <= 105
*/

#include <iostream>
#include <queue>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int size = (int)queries.size();
        priority_queue<int> kSmall;
        vector<int> ans(size, -1);

        for (int i = 0; i < size; ++i) {
            kSmall.push(abs(queries[i][0]) + abs(queries[i][1]));

            if (kSmall.size() > k) {
                kSmall.pop();
            }

            if (kSmall.size() == k) {
                ans[i] = kSmall.top();
            }
        }

        return ans;
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> queries = { {1,2},{3,4},{2,3},{-3,0} };
    vector<int> actual = o.resultsArray(queries, 2);
    vector<int> expected = { -1,7,5,3 };
    check.checkIntVector(expected, actual);

    queries = { {5,5},{4,4},{3,3} };
    actual = o.resultsArray(queries, 1);
    expected = { 10,8,6 };
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
