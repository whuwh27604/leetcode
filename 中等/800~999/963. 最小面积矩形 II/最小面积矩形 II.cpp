/* 最小面积矩形 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定在 xy 平面上的一组点，确定由这些点组成的任何矩形的最小面积，其中矩形的边不一定平行于 x 轴和 y 轴。

如果没有任何矩形，就返回 0。

 

示例 1：



输入：[[1,2],[2,1],[1,0],[0,1]]
输出：2.00000
解释：最小面积的矩形出现在 [1,2],[2,1],[1,0],[0,1] 处，面积为 2。
示例 2：



输入：[[0,1],[2,1],[1,1],[1,0],[2,0]]
输出：1.00000
解释：最小面积的矩形出现在 [1,0],[1,1],[2,1],[2,0] 处，面积为 1。
示例 3：



输入：[[0,3],[1,2],[3,1],[1,3],[2,1]]
输出：0
解释：没法从这些点中组成任何矩形。
示例 4：



输入：[[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]]
输出：2.00000
解释：最小面积的矩形出现在 [2,1],[2,3],[3,3],[3,1] 处，面积为 2。
 

提示：

1 <= points.length <= 50
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
所有的点都是不同的。
与真实值误差不超过 10^-5 的答案将视为正确结果。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-area-rectangle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_map<long long, vector<pair<pair<int, int>, pair<int, int>>>> sameLenLines;
        getSameLenLines(points, sameLenLines);

        double minArea = INT_MAX;
        for (auto iter = sameLenLines.begin(); iter != sameLenLines.end(); ++iter) {
            if (iter->second.size() > 1) {  // 至少要两个对角线才能构成一个矩形
                double area = getMinArea(iter->second);
                minArea = min(minArea, area);
            }
        }

        return (fabs(minArea - INT_MAX) < 1e-5) ? 0 : minArea;
    }

    void getSameLenLines(vector<vector<int>>& points, unordered_map<long long, vector<pair<pair<int, int>, pair<int, int>>>>& sameLenLines) {
        int i, j, size = points.size();

        for (i = 0; i < size - 1; ++i) {  // 枚举所有的线段作为对角线，长度一样的放在一起
            for (j = i + 1; j < size; ++j) {
                long long len = (long long)(pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2));
                if (sameLenLines.count(len) == 0) {
                    sameLenLines[len] = { {{points[i][0],points[i][1]},{points[j][0],points[j][1]}} };
                }
                else {
                    sameLenLines[len].push_back({ {points[i][0],points[i][1]},{points[j][0],points[j][1]} });
                }
            }
        }
    }

    double getMinArea(vector<pair<pair<int, int>, pair<int, int>>>& lines) {
        int i, j, size = lines.size();
        double minArea = INT_MAX;

        for (i = 0; i < size - 1; ++i) {
            for (j = i + 1; j < size; ++j) {
                if ((lines[i].first.first + lines[i].second.first == lines[j].first.first + lines[j].second.first)
                    && (lines[i].first.second + lines[i].second.second == lines[j].first.second + lines[j].second.second)) {  // 两条线段的中点重合则构成矩形
                    double area = calcArea(lines[i].first, lines[j].first, lines[j].second);
                    minArea = min(minArea, area);
                }
            }
        }

        return minArea;
    }

    double calcArea(pair<int, int>& a, pair<int, int>& b, pair<int, int>& c) {
        double length = sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
        double width = sqrt(pow((a.first - c.first), 2) + pow((a.second - c.second), 2));
        return length * width;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> points = { {1,2},{2,1},{1,0},{0,1} };
    check.checkDouble(2.0, o.minAreaFreeRect(points));

    points = { {0,1},{2,1},{1,1},{1,0},{2,0} };
    check.checkDouble(1.0, o.minAreaFreeRect(points));

    points = { {0,3},{1,2},{3,1},{1,3},{2,1} };
    check.checkDouble(0, o.minAreaFreeRect(points));

    points = { {3,1},{1,1},{0,1},{2,1},{3,3},{3,2},{0,2},{2,3} };
    check.checkDouble(2.0, o.minAreaFreeRect(points));
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
