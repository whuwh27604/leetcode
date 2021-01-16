/* 两点之间不包含任何点的最宽垂直面积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你 n 个二维平面上的点 points ，其中 points[i] = [xi, yi] ，请你返回两点之间内部不包含任何点的 最宽垂直面积 的宽度。

垂直面积 的定义是固定宽度，而 y 轴上无限延伸的一块区域（也就是高度为无穷大）。 最宽垂直面积 为宽度最大的一个垂直面积。

请注意，垂直区域 边上 的点 不在 区域内。

 

示例 1：

​
输入：points = [[8,7],[9,9],[7,4],[9,7]]
输出：1
解释：红色区域和蓝色区域都是最优区域。
示例 2：

输入：points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
输出：3
 

提示：

n == points.length
2 <= n <= 105
points[i].length == 2
0 <= xi, yi <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/widest-vertical-area-between-two-points-containing-no-points
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
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), vectorCompare);

        int i, size = points.size(), maxWidth = 0;

        for (i = 1; i < size; ++i) {
            maxWidth = max(maxWidth, points[i][0] - points[i - 1][0]);
        }

        return maxWidth;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> points = { {8,7},{9,9},{7,4},{9,7} };
    check.checkInt(1, o.maxWidthOfVerticalArea(points));

    points = { {3,1},{9,0},{1,0},{1,4},{5,3},{8,8} };
    check.checkInt(3, o.maxWidthOfVerticalArea(points));

    points = { {3,1},{9,0} };
    check.checkInt(6, o.maxWidthOfVerticalArea(points));
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
