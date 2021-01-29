/* 有效的回旋镖.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
回旋镖定义为一组三个点，这些点各不相同且不在一条直线上。

给出平面上三个点组成的列表，判断这些点是否可以构成回旋镖。

 

示例 1：

输入：[[1,1],[2,3],[3,2]]
输出：true
示例 2：

输入：[[1,1],[2,2],[3,3]]
输出：false
 

提示：

points.length == 3
points[i].length == 2
0 <= points[i][j] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-boomerang
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int x1 = points[0][0] - points[1][0];
        int y1 = points[0][1] - points[1][1];
        int x2 = points[0][0] - points[2][0];
        int y2 = points[0][1] - points[2][1];
        return ((x1 * y2) != (x2 * y1));
    }
};

int main()
{
    Solution o;
    CheckResult check;

    vector<vector<int>> points = { {1,1},{2,3},{3,2} };
    check.checkBool(true, o.isBoomerang(points));

    points = { {-3,-2},{2,3},{1,1} };
    check.checkBool(true, o.isBoomerang(points));

    points = { {3,2},{-1,-1},{2,3} };
    check.checkBool(true, o.isBoomerang(points));

    points = { {1,1},{2,2},{3,3} };
    check.checkBool(false, o.isBoomerang(points));

    points = { {1,1},{2,2},{-3,-3} };
    check.checkBool(false, o.isBoomerang(points));

    points = { {1,1},{2,2},{3,-3} };
    check.checkBool(true, o.isBoomerang(points));

    points = { {1,1},{1,1},{3,2} };
    check.checkBool(false, o.isBoomerang(points));

    points = { {1,1},{2,3},{1,1} };
    check.checkBool(false, o.isBoomerang(points));

    points = { {1,1},{2,3},{2,3} };
    check.checkBool(false, o.isBoomerang(points));
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
