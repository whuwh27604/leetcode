/* 直线上最多的点数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。

示例 1:

输入: [[1,1],[2,2],[3,3]]
输出: 3
解释:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4
示例 2:

输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
输出: 4
解释:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-points-on-a-line
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int i, j, size = points.size(), maximum = 0;
        if (size <= 2) {
            return size;
        }

        for (i = 0; i < size - 1; ++i) {
            unordered_map<string, int> oneLinePoints;
            int duplicate = 0, tmpMax = 1;

            for (j = i + 1; j < size; ++j) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++duplicate;
                    continue;
                }

                string slope = getSlope(points[i], points[j]);
                if (oneLinePoints.count(slope) == 0) {
                    oneLinePoints[slope] = 2;
                }
                else {
                    ++oneLinePoints[slope];
                }

                tmpMax = max(tmpMax, oneLinePoints[slope]);
            }

            maximum = max(maximum, tmpMax + duplicate);
        }

        return maximum;
    }

    string getSlope(vector<int>& p1, vector<int>& p2) {
        long long x = p2[0] - p1[0], y = p2[1] - p1[1];
        if (x == 0) {
            return "y1x0";
        }

        bool negative = (x < 0 && y > 0) || (x > 0 && y < 0);
        x = abs(x), y = abs(y);
        long long factor = gcd(x, y);
        x /= factor;
        y /= factor;

        string slope = negative ? "-y" : "y";
        return slope + to_string(y) + 'x' + to_string(x);
    }

    long long gcd(long long x, long long y) {
        return (y == 0) ? x : gcd(y, x % y);
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> points = { {1,1},{2,2},{3,3} };
    check.checkInt(3, o.maxPoints(points));

    points = { {1,1},{3,2},{5,3},{4,1},{2,3},{1,4} };
    check.checkInt(4, o.maxPoints(points));

    points = { {1,1},{1,1},{1,1} };
    check.checkInt(3, o.maxPoints(points));

    points = { {1,1},{0,0},{1,1} };
    check.checkInt(3, o.maxPoints(points));

    points = { {1,1},{0,0},{1,1},{0,0},{2,3} };
    check.checkInt(4, o.maxPoints(points));

    points = { {2,3},{3,3},{-5,3},{2,1} };
    check.checkInt(3, o.maxPoints(points));

    points = { {3,-1},{3,2},{3,1},{2,1} };
    check.checkInt(3, o.maxPoints(points));

    points = { {84,250},{0,0},{1,0},{0,-70},{0,-70},{1,-1},{21,10},{42,90},{-42,-230} };
    check.checkInt(6, o.maxPoints(points));

    points = { {94911152,94911151},{0,0},{94911151,94911150} };
    check.checkInt(2, o.maxPoints(points));

    points = { {1,0},{0,0},{0,1} };
    check.checkInt(2, o.maxPoints(points));

    points = { {1,1} };
    check.checkInt(1, o.maxPoints(points));

    points = {  };
    check.checkInt(0, o.maxPoints(points));

    points = { {1,1},{2,1},{2,2},{1,4},{3,3} };
    check.checkInt(3, o.maxPoints(points));

    points = { {15,12},{9,10},{-16,3},{-15,15},{11,-10},{-5,20},{-3,-15},{-11,-8},{-8,-3},{3,6},{15,-14},{-16,-18},{-6,-8},{14,9},{-1,-7},{-1,-2},{3,11},{6,20},{10,-7},{0,14},{19,-18},{-10,-15},{-17,-1},{8,7},{20,-18},{-4,-9},{-9,16},{10,14},{-14,-15},{-2,-10},{-18,9},{7,-5},{-12,11},{-17,-6},{5,-17},{-2,-20},{15,-2},{-5,-16},{1,-20},{19,-12},{-14,-1},{18,10},{1,-20},{-15,19},{-18,13},{13,-3},{-16,-17},{1,0},{20,-18},{7,19},{1,-6},{-7,-11},{7,1},{-15,12},{-1,7},{-3,-13},{-11,2},{-17,-5},{-12,-14},{15,-3},{15,-11},{7,3},{19,7},{-15,19},{10,-14},{-14,5},{0,-1},{-12,-4},{4,18},{7,-3},{-5,-3},{1,-11},{1,-1},{2,16},{6,-6},{-17,9},{14,3},{-13,8},{-9,14},{-5,-1},{-18,-17},{9,-10},{19,19},{16,7},{3,7},{-18,-12},{-11,12},{-15,20},{-3,4},{-18,1},{13,17},{-16,-15},{-9,-9},{15,8},{19,-9},{9,-17} };
    check.checkInt(6, o.maxPoints(points));
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
