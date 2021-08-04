/* 最大兼容性评分和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
有一份由 n 个问题组成的调查问卷，每个问题的答案要么是 0（no，否），要么是 1（yes，是）。

这份调查问卷被分发给 m 名学生和 m 名导师，学生和导师的编号都是从 0 到 m - 1 。学生的答案用一个二维整数数组 students 表示，其中 students[i] 是一个整数数组，包含第 i 名学生对调查问卷给出的答案（下标从 0 开始）。导师的答案用一个二维整数数组 mentors 表示，其中 mentors[j] 是一个整数数组，包含第 j 名导师对调查问卷给出的答案（下标从 0 开始）。

每个学生都会被分配给 一名 导师，而每位导师也会分配到 一名 学生。配对的学生与导师之间的兼容性评分等于学生和导师答案相同的次数。

例如，学生答案为[1, 0, 1] 而导师答案为 [0, 0, 1] ，那么他们的兼容性评分为 2 ，因为只有第二个和第三个答案相同。
请你找出最优的学生与导师的配对方案，以 最大程度上 提高 兼容性评分和 。

给你 students 和 mentors ，返回可以得到的 最大兼容性评分和 。

 

示例 1：

输入：students = [[1,1,0],[1,0,1],[0,0,1]], mentors = [[1,0,0],[0,0,1],[1,1,0]]
输出：8
解释：按下述方式分配学生和导师：
- 学生 0 分配给导师 2 ，兼容性评分为 3 。
- 学生 1 分配给导师 0 ，兼容性评分为 2 。
- 学生 2 分配给导师 1 ，兼容性评分为 3 。
最大兼容性评分和为 3 + 2 + 3 = 8 。
示例 2：

输入：students = [[0,0],[0,0],[0,0]], mentors = [[1,1],[1,1],[1,1]]
输出：0
解释：任意学生与导师配对的兼容性评分都是 0 。
 

提示：

m == students.length == mentors.length
n == students[i].length == mentors[j].length
1 <= m, n <= 8
students[i][k] 为 0 或 1
mentors[j][k] 为 0 或 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-compatibility-score-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = mentors.size(), n = mentors[0].size();
        vector<int> visited(1 << (8 + m), -1);

        return DFS(students, mentors, (((1 << m) - 1) << 8) | ((1 << m) - 1), visited);
    }

    int DFS(vector<vector<int>>& students, vector<vector<int>>& mentors, int state, vector<int>& visited) {
        if (visited[state] != -1) {
            return visited[state];
        }

        if (state == 0) {
            return 0;
        }

        int i, j, bitS, bitM, m = mentors.size(), maxScore = 0;

        for (i = 0, bitS = (1 << 8); i < m; ++i, bitS <<= 1) {
            if ((bitS & state) != 0) {
                break;
            }
        }

        state ^= bitS;

        for (j = 0, bitM = 1; j < m; ++j, bitM <<= 1) {
            if ((bitM & state) != 0) {
                int score = getScore(students[i], mentors[j]);
                state ^= bitM;
                score += DFS(students, mentors, state, visited);
                maxScore = max(maxScore, score);
                state ^= bitM;
            }
        }

        visited[state] = maxScore;
        return maxScore;
    }

    int getScore(vector<int>& student, vector<int>& mentor) {
        int i, n = mentor.size(), score = 0;

        for (i = 0; i < n; ++i) {
            if (student[i] == mentor[i]) {
                ++score;
            }
        }

        return score;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> students = { {1,1,0},{1,0,1},{0,0,1} };
    vector<vector<int>> mentors = { {1,0,0},{0,0,1},{1,1,0} };
    check.checkInt(8, o.maxCompatibilitySum(students, mentors));

    students = { {0,0},{0,0},{0,0} };
    mentors = { {1,1},{1,1},{1,1} };
    check.checkInt(0, o.maxCompatibilitySum(students, mentors));

    students = { {1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1} };
    mentors = { {1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1} };
    check.checkInt(64, o.maxCompatibilitySum(students, mentors));
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
