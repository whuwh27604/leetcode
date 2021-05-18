/* 二指输入的的最小距离.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
二指输入法定制键盘在 XY 平面上的布局如上图所示，其中每个大写英文字母都位于某个坐标处，例如字母 A 位于坐标 (0,0)，字母 B 位于坐标 (0,1)，字母 P 位于坐标 (2,3) 且字母 Z 位于坐标 (4,1)。

给你一个待输入字符串 word，请你计算并返回在仅使用两根手指的情况下，键入该字符串需要的最小移动总距离。坐标 (x1,y1) 和 (x2,y2) 之间的距离是 |x1 - x2| + |y1 - y2|。 

注意，两根手指的起始位置是零代价的，不计入移动总距离。你的两根手指的起始位置也不必从首字母或者前两个字母开始。

 

示例 1：

输入：word = "CAKE"
输出：3
解释：
使用两根手指输入 "CAKE" 的最佳方案之一是：
手指 1 在字母 'C' 上 -> 移动距离 = 0
手指 1 在字母 'A' 上 -> 移动距离 = 从字母 'C' 到字母 'A' 的距离 = 2
手指 2 在字母 'K' 上 -> 移动距离 = 0
手指 2 在字母 'E' 上 -> 移动距离 = 从字母 'K' 到字母 'E' 的距离  = 1
总距离 = 3
示例 2：

输入：word = "HAPPY"
输出：6
解释：
使用两根手指输入 "HAPPY" 的最佳方案之一是：
手指 1 在字母 'H' 上 -> 移动距离 = 0
手指 1 在字母 'A' 上 -> 移动距离 = 从字母 'H' 到字母 'A' 的距离 = 2
手指 2 在字母 'P' 上 -> 移动距离 = 0
手指 2 在字母 'P' 上 -> 移动距离 = 从字母 'P' 到字母 'P' 的距离 = 0
手指 1 在字母 'Y' 上 -> 移动距离 = 从字母 'A' 到字母 'Y' 的距离 = 4
总距离 = 6
示例 3：

输入：word = "NEW"
输出：3
示例 4：

输入：word = "YEAR"
输出：7
 

提示：

2 <= word.length <= 300
每个 word[i] 都是一个大写英文字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-distance-to-type-a-word-using-two-fingers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int minimumDistance(string word) {
        vector<vector<int>> distances(27, vector<int>(27, 0));
        getDistances(distances);

        vector<vector<int>> dp(27, vector<int>(27, INT_MAX));
        dp[0][0] = 0;

        for (char c : word) {
            vector<vector<int>> tmp(27, vector<int>(27, INT_MAX));

            for (int i = 0; i < 27; ++i) {
                for (int j = 0; j < 27; ++j) {
                    if (dp[i][j] != INT_MAX) {
                        int index = c - 'A' + 1;
                        tmp[index][j] = min(tmp[index][j], dp[i][j] + distances[i][index]);
                        tmp[i][index] = min(tmp[i][index], dp[i][j] + distances[j][index]);
                    }
                }
            }

            dp = tmp;
        }

        return getMinDistance(dp);
    }

    void getDistances(vector<vector<int>>& distances) {
        vector<vector<int>> indices = { {0,0},
            {0,0},{0,1},{0,2},{0,3},{0,4},{0,5},
            {1,0},{1,1},{1,2},{1,3},{1,4},{1,5},
            {2,0},{2,1},{2,2},{2,3},{2,4},{2,5},
            {3,0},{3,1},{3,2},{3,3},{3,4},{3,5},
            {4,0},{4,1} };

        for (int i = 1; i < 27; ++i) {
            for (int j = 1; j < 27; ++j) {
                distances[i][j] = abs(indices[i][0] - indices[j][0]) + abs(indices[i][1] - indices[j][1]);
            }
        }
    }

    int getMinDistance(vector<vector<int>>& dp) {
        int i, j, minDistance = INT_MAX;

        for (i = 0; i < 27; ++i) {
            for (j = 0; j < 27; ++j) {
                minDistance = min(minDistance, dp[i][j]);
            }
        }

        return minDistance;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    check.checkInt(3, o.minimumDistance("CAKE"));
    check.checkInt(6, o.minimumDistance("HAPPY"));
    check.checkInt(3, o.minimumDistance("NEW"));
    check.checkInt(7, o.minimumDistance("YEAR"));
    check.checkInt(0, o.minimumDistance("AZ"));
    check.checkInt(0, o.minimumDistance("ZZZZZZZZZZZZZZZZZZZZZZ"));
    check.checkInt(70, o.minimumDistance("QIURQEURQSFDJAJFAZNZNVZNVNFJDJALJFQUERUQ"));
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
