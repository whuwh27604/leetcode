/* 课程安排 IV.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
你总共需要上 n 门课，课程编号依次为 0 到 n-1 。

有的课会有直接的先修课程，比如如果想上课程 0 ，你必须先上课程 1 ，那么会以 [1,0] 数对的形式给出先修课程数对。

给你课程总数 n 和一个直接先修课程数对列表 prerequisite 和一个查询对列表 queries 。

对于每个查询对 queries[i] ，请判断 queries[i][0] 是否是 queries[i][1] 的先修课程。

请返回一个布尔值列表，列表中每个元素依次分别对应 queries 每个查询对的判断结果。

注意：如果课程 a 是课程 b 的先修课程且课程 b 是课程 c 的先修课程，那么课程 a 也是课程 c 的先修课程。

 

示例 1：



输入：n = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
输出：[false,true]
解释：课程 0 不是课程 1 的先修课程，但课程 1 是课程 0 的先修课程。
示例 2：

输入：n = 2, prerequisites = [], queries = [[1,0],[0,1]]
输出：[false,false]
解释：没有先修课程对，所以每门课程之间是独立的。
示例 3：



输入：n = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
输出：[true,true]
示例 4：

输入：n = 3, prerequisites = [[1,0],[2,0]], queries = [[0,1],[2,0]]
输出：[false,true]
示例 5：

输入：n = 5, prerequisites = [[0,1],[1,2],[2,3],[3,4]], queries = [[0,4],[4,0],[1,3],[3,0]]
输出：[true,false,true,false]
 

提示：

2 <= n <= 100
0 <= prerequisite.length <= (n * (n - 1) / 2)
0 <= prerequisite[i][0], prerequisite[i][1] < n
prerequisite[i][0] != prerequisite[i][1]
先修课程图中没有环。
先修课程图中没有重复的边。
1 <= queries.length <= 10^4
queries[i][0] != queries[i][1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/course-schedule-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        vector<bool> ans(queries.size());

        init(prerequisites, dp);
        floyd(n, dp);
        checkIfPrereqs(queries, dp, ans);

        return ans;
    }

    void init(vector<vector<int>>& prerequisites, vector<vector<int>>& dp) {
        for (auto& prerequisite : prerequisites) {
            dp[prerequisite[0]][prerequisite[1]] = 1;
        }
    }

    void floyd(int n, vector<vector<int>>& dp) {  // Floyd插点法，dp[i][j]表示i到j之间的最短距离
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i != j && dp[i][k] != INT_MAX && dp[k][j] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                    }
                }
            }
        }
    }

    void checkIfPrereqs(vector<vector<int>>& queries, vector<vector<int>>& dp, vector<bool>& ans) {
        for (int i = 0; i < (int)ans.size(); ++i) {
            ans[i] = (dp[queries[i][0]][queries[i][1]] != INT_MAX);
        }
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> prerequisites = { {1,0} };
    vector<vector<int>> queries = { {0,1},{1,0} };
    vector<bool> actual = o.checkIfPrerequisite(2, prerequisites, queries);
    vector<bool> expected = { false, true };
    check.checkBoolVector(expected, actual);

    prerequisites = {  };
    queries = { {1,0},{0,1} };
    actual = o.checkIfPrerequisite(2, prerequisites, queries);
    expected = { false, false };
    check.checkBoolVector(expected, actual);

    prerequisites = { {1,2},{1,0},{2,0} };
    queries = { {1,0},{1,2} };
    actual = o.checkIfPrerequisite(3, prerequisites, queries);
    expected = { true,true };
    check.checkBoolVector(expected, actual);

    prerequisites = { {1,0},{2,0} };
    queries = { {0,1},{2,0} };
    actual = o.checkIfPrerequisite(3, prerequisites, queries);
    expected = { false,true };
    check.checkBoolVector(expected, actual);

    prerequisites = { {0,1},{1,2},{2,3},{3,4} };
    queries = { {0,4},{4,0},{1,3},{3,0} };
    actual = o.checkIfPrerequisite(5, prerequisites, queries);
    expected = { true,false,true,false };
    check.checkBoolVector(expected, actual);

    prerequisites = { {1,0},{2,0},{3,0},{4,3},{5,1},{5,2},{5,4} };
    queries = { {5,0},{5,3},{1,4},{4,1} };
    actual = o.checkIfPrerequisite(6, prerequisites, queries);
    expected = { true,true,false,false };
    check.checkBoolVector(expected, actual);

    prerequisites = { {2,1},{2,7},{2,0},{2,10},{2,11},{1,7},{1,0},{1,9},{1,4},{1,11},{7,3},{7,9},{7,4},{7,11},{7,8},{3,6},{3,12},{3,5},{6,10},{6,8},{0,4},{12,9},{12,8},{9,4},{9,11},{9,8},{9,5},{10,8},{4,8} };
    queries = { {12,11},{11,1},{10,12},{9,10},{10,11},{11,12},{2,7},{6,8},{3,2},{9,5},{8,7},{1,4},{3,12},{9,6},{4,3},{11,4},{5,7},{3,9},{3,1},{8,12},{5,12},{0,8},{10,5},{10,11},{12,11},{12,9},{5,4},{11,5},{12,10},{11,0},{6,10},{11,7},{8,10},{2,1},{3,4},{8,7},{11,6},{9,11},{1,4},{10,8},{7,1},{8,7},{9,7},{5,1},{8,10},{11,8},{8,12},{9,12},{12,11},{6,12},{12,11},{6,10},{9,12},{8,10},{8,11},{8,5},{7,9},{12,11},{11,12},{8,0},{12,11},{7,0},{8,7},{5,11},{11,8},{1,9},{4,10},{11,6},{10,12} };
    actual = o.checkIfPrerequisite(13, prerequisites, queries);
    expected = { true,false,false,false,false,false,true,true,false,true,false,true,true,false,false,false,false,true,false,false,false,true,false,false,true,true,false,false,false,false,true,false,false,true,true,false,false,true,true,true,false,false,false,false,false,false,false,false,true,false,true,true,false,false,false,false,true,true,false,false,true,false,false,false,false,true,false,false,false };
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
