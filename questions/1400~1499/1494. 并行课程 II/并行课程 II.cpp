/* 并行课程 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个整数 n 表示某所大学里课程的数目，编号为 1 到 n ，数组 dependencies 中， dependencies[i] = [xi, yi]  表示一个先修课的关系，也就是课程 xi 必须在课程 yi 之前上。同时你还有一个整数 k 。

在一个学期中，你 最多 可以同时上 k 门课，前提是这些课的先修课在之前的学期里已经上过了。

请你返回上完所有课最少需要多少个学期。题目保证一定存在一种上完所有课的方式。

 

示例 1：



输入：n = 4, dependencies = [[2,1],[3,1],[1,4]], k = 2
输出：3
解释：上图展示了题目输入的图。在第一个学期中，我们可以上课程 2 和课程 3 。然后第二个学期上课程 1 ，第三个学期上课程 4 。
示例 2：



输入：n = 5, dependencies = [[2,1],[3,1],[4,1],[1,5]], k = 2
输出：4
解释：上图展示了题目输入的图。一个最优方案是：第一学期上课程 2 和 3，第二学期上课程 4 ，第三学期上课程 1 ，第四学期上课程 5 。
示例 3：

输入：n = 11, dependencies = [], k = 2
输出：6
 

提示：

1 <= n <= 15
1 <= k <= n
0 <= dependencies.length <= n * (n-1) / 2
dependencies[i].length == 2
1 <= xi, yi <= n
xi != yi
所有先修关系都是不同的，也就是说 dependencies[i] != dependencies[j] 。
题目输入的图是个有向无环图。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/parallel-courses-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        int maxMask = (1 << n), allMask = maxMask - 1;
        vector<int> dp(maxMask, INT_MAX);  // dp[mask]表示上完mask课程，最少需要的天数
        dp[0] = 0;
        vector<int> dependencies(n, 0);

        getDependencies(n, relations, dependencies);

        for (int mask = 1; mask < maxMask; ++mask) {
            int nonDependencies = 0;  // 在mask集合内，不依赖任何其它课程的课

            for (int node = 0, bit = 1; node < n; ++node, bit <<= 1) {
                if ((mask & bit) != 0 && (mask & dependencies[node]) == 0) {  // 1、要在mask集合内；2、它依赖的课程都不在mask集合内
                    nonDependencies |= bit;
                }
            }

            for (int subset = nonDependencies; subset != 0; subset = (subset - 1) & nonDependencies) {  // 枚举nonDependencies的所有子集
                if (__builtin_popcount(subset) <= k) {  // 该子集的课程可以安排在一天
                    dp[mask] = min(dp[mask], 1 + dp[mask ^ subset]);  // subset安排在一天，剩下的再看需要几天
                }
            }
        }

        return dp[allMask];
    }

    void getDependencies(int n, vector<vector<int>>& relations, vector<int>& dependencies) {
        vector<vector<int>> adjs(n);

        for (auto& relation : relations) {
            adjs[relation[1] - 1].push_back(relation[0] - 1);
        }

        for (int node = 0; node < n; ++node) {  // 找到每一门课它所依赖的所有课程
            DFS(node, adjs, dependencies[node]);
            dependencies[node] ^= (1 << node);  // 不包括自己
        }
    }

    void DFS(int node, vector<vector<int>>& adjs, int& dependency) {
        dependency |= (1 << node);

        for (int next : adjs[node]) {
            DFS(next, adjs, dependency);
        }
    }

    int __builtin_popcount(int num) {
        int count = 0;

        while (num != 0) {
            count += ((num & 1) == 1 ? 1 : 0);
            num >>= 1;
        }

        return count;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> relations = {{2,1},{3,1},{1,4}};
    check.checkInt(3,o.minNumberOfSemesters(4,relations,2));

    relations = {{2,1},{3,1},{4,1},{1,5}};
    check.checkInt(4, o.minNumberOfSemesters(5, relations, 2));

    relations = {};
    check.checkInt(6, o.minNumberOfSemesters(11, relations, 2));

    relations = {{1,5},{2,5},{3,4},{4,5}};
    check.checkInt(3,o.minNumberOfSemesters(5,relations,2));

    relations = {{1,4},{2,5},{3,5},{4,5}};
    check.checkInt(3,o.minNumberOfSemesters(5,relations,2));

    relations = {{1,6},{2,6},{3,4},{3,5},{3,6}};
    check.checkInt(3,o.minNumberOfSemesters(6,relations,2));

    relations = {{4,5}};
    check.checkInt(2,o.minNumberOfSemesters(5,relations,3));

    relations = {{1,4},{2,4},{2,5},{3,5},{4,5}};
    check.checkInt(3,o.minNumberOfSemesters(5,relations,2));

    relations = {{3,5},{4,5}};
    check.checkInt(2,o.minNumberOfSemesters(5,relations,3));

    relations = {{1,5},{2,5},{3,4},{3,5},{3,6},{4,5},{5,6}};
    check.checkInt(4,o.minNumberOfSemesters(6,relations,2));

    relations = {{1,4},{2,4},{2,6},{3,6},{4,5}};
    check.checkInt(3, o.minNumberOfSemesters(6, relations, 2));
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
