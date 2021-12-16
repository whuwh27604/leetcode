/* 可见点的最大数目.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
给你一个点数组 points 和一个表示角度的整数 angle ，你的位置是 location ，其中 location = [posx, posy] 且 points[i] = [xi, yi] 都表示 X-Y 平面上的整数坐标。

最开始，你面向东方进行观测。你 不能 进行移动改变位置，但可以通过 自转 调整观测角度。换句话说，posx 和 posy 不能改变。你的视野范围的角度用 angle 表示， 这决定了你观测任意方向时可以多宽。设 d 为你逆时针自转旋转的度数，那么你的视野就是角度范围 [d - angle/2, d + angle/2] 所指示的那片区域。

对于每个点，如果由该点、你的位置以及从你的位置直接向东的方向形成的角度 位于你的视野中 ，那么你就可以看到它。

同一个坐标上可以有多个点。你所在的位置也可能存在一些点，但不管你的怎么旋转，总是可以看到这些点。同时，点不会阻碍你看到其他点。

返回你能看到的点的最大数目。

 

示例 1：



输入：points = [[2,1],[2,2],[3,3]], angle = 90, location = [1,1]
输出：3
解释：阴影区域代表你的视野。在你的视野中，所有的点都清晰可见，尽管 [2,2] 和 [3,3]在同一条直线上，你仍然可以看到 [3,3] 。
示例 2：

输入：points = [[2,1],[2,2],[3,4],[1,1]], angle = 90, location = [1,1]
输出：4
解释：在你的视野中，所有的点都清晰可见，包括你所在位置的那个点。
示例 3：



输入：points = [[1,0],[2,1]], angle = 13, location = [1,1]
输出：1
解释：如图所示，你只能看到两点之一。
 

提示：

1 <= points.length <= 105
points[i].length == 2
location.length == 2
0 <= angle < 360
0 <= posx, posy, xi, yi <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-visible-points
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> degrees;

        int sameLocation = getDegrees(points, location, degrees);
        sort(degrees.begin(), degrees.end());
        add2PI(degrees);

        return sameLocation + getVisiblePoints(degrees, angle);
    }

    int getDegrees(vector<vector<int>>& points, vector<int>& location, vector<double>& degrees) {
        int sameLocation = 0;

        for (auto& point : points) {
            if (point == location) {
                ++sameLocation;
            }
            else {
                degrees.push_back(atan2(point[1] - location[1], point[0] - location[0]));
            }
        }

        return sameLocation;
    }

    void add2PI(vector<double>& degrees) {
        int i, size = degrees.size();

        for (i = 0; i < size; ++i) {
            degrees.push_back(degrees[i] + 2 * PI);
        }
    }

    int getVisiblePoints(vector<double>& degrees, int angle) {
        int left, right = 0, size = degrees.size(), half = size / 2, maxCount = 0;
        double angleDegree = angle * PI / 180;

        for (left = 0; left < half; ++left) {
            while (right < size && degrees[right] <= degrees[left] + angleDegree) {
                ++right;
            }

            maxCount = max(maxCount, right - left);
        }

        return maxCount;
    }

    double PI = 3.14159265358979323846;
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> points = { {2,1},{2,2},{3,3} };
    vector<int> location = { 1,1 };
    check.checkInt(3, o.visiblePoints(points, 90, location));

    points = { {2,1},{2,2},{3,4},{1,1} };
    location = { 1,1 };
    check.checkInt(4, o.visiblePoints(points, 90, location));

    points = { {1,0},{2,1} };
    location = { 1,1 };
    check.checkInt(1, o.visiblePoints(points, 13, location));

    points = { {1,1},{1,1},{1,1} };
    location = { 1,1 };
    check.checkInt(3, o.visiblePoints(points, 0, location));
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
