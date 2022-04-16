/* 满足不等式的最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个数组 points 和一个整数 k 。数组中每个元素都表示二维平面上的点的坐标，并按照横坐标 x 的值从小到大排序。也就是说 points[i] = [xi, yi] ，并且在 1 <= i < j <= points.length 的前提下， xi < xj 总成立。

请你找出 yi + yj + |xi - xj| 的 最大值，其中 |xi - xj| <= k 且 1 <= i < j <= points.length。

题目测试数据保证至少存在一对能够满足 |xi - xj| <= k 的点。

 

示例 1：

输入：points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
输出：4
解释：前两个点满足 |xi - xj| <= 1 ，代入方程计算，则得到值 3 + 0 + |1 - 2| = 4 。第三个和第四个点也满足条件，得到值 10 + -10 + |5 - 6| = 1 。
没有其他满足条件的点，所以返回 4 和 1 中最大的那个。
示例 2：

输入：points = [[0,0],[3,0],[9,2]], k = 3
输出：3
解释：只有前两个点满足 |xi - xj| <= 3 ，代入方程后得到值 0 + 0 + |0 - 3| = 3 。
 

提示：

2 <= points.length <= 10^5
points[i].length == 2
-10^8 <= points[i][0], points[i][1] <= 10^8
0 <= k <= 2 * 10^8
对于所有的1 <= i < j <= points.length ，points[i][0] < points[j][0] 都成立。也就是说，xi 是严格递增的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-value-of-equation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <deque>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int maxValue = INT_MIN;  // 从左至右遍历j，要求Yj + Xj + Yi - Xi的最大值
        deque<pair<int, int>> nodes;  // { y - x, x } 单调队列按照y - x的值递减

        for (auto& point : points) {
            int x = point[0], y = point[1];

            while (!nodes.empty() && x - nodes.front().second > k) {  // 因为x是递增的，所以超过k范围的x可以直接丢弃，再也用不上它
                nodes.pop_front();
            }

            if (!nodes.empty()) {
                maxValue = max(maxValue, y + x + nodes.front().first);  // 队列头部是最大的y - x
            }
            
            while (!nodes.empty() && nodes.back().first <= y - x) {  // 将y - x加入队列，尾部小的可以直接丢弃了
                nodes.pop_back();
            }

            nodes.push_back({ y - x , x });
        }

        return maxValue;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> points = { {1,3},{2,0},{5,10},{6,-10} };
    check.checkInt(4, o.findMaxValueOfEquation(points, 1));

    points = { {0,0},{3,0},{9,2} };
    check.checkInt(3, o.findMaxValueOfEquation(points, 3));
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
