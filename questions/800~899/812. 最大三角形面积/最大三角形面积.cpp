/* 最大三角形面积.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定包含多个点的集合，从其中取三个点组成三角形，返回能组成的最大三角形的面积。

示例:
输入: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
输出: 2
解释:
这五个点如下图所示。组成的橙色三角形是最大的，面积为2。


注意:

3 <= points.length <= 50.
不存在重复的点。
 -50 <= points[i][j] <= 50.
结果误差值在 10^-6 以内都认为是正确答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-triangle-area
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int largestDoubleArea = 0;
        for (unsigned int i = 0; i < (points.size() - 2); i++) {
            for (unsigned int j = (i + 1); j < (points.size() - 1); j++) {
                for (unsigned int k = (j + 1); k < points.size(); k++) {
                    int doubleArea = triangleDoubleArea(points[i], points[j], points[k]);
                    if (doubleArea > largestDoubleArea) {
                        largestDoubleArea = doubleArea;
                    }
                }
            }
        }

        return (((double)largestDoubleArea) / 2);
    }

    int triangleDoubleArea(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
        // 鞋带公式求面积
        return abs(p1[0] * p2[1] + p2[0] * p3[1] + p3[0] * p1[1] - p1[1] * p2[0] - p2[1] * p3[0] - p3[1] * p1[0]);
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> points = { {0,0},{0,1},{1,0},{0,2},{2,0} };
    check.checkDouble(2, o.largestTriangleArea(points));

    points = { {0,0},{0,1},{1,0},{2,0},{3,0} };
    check.checkDouble(1.5, o.largestTriangleArea(points));
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
