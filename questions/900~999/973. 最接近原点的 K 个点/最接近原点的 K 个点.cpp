/* 最接近原点的 K 个点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。

（这里，平面上两点之间的距离是欧几里德距离。）

你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。

 

示例 1：

输入：points = [[1,3],[-2,2]], K = 1
输出：[[-2,2]]
解释：
(1, 3) 和原点之间的距离为 sqrt(10)，
(-2, 2) 和原点之间的距离为 sqrt(8)，
由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。
示例 2：

输入：points = [[3,3],[5,-1],[-2,4]], K = 2
输出：[[3,3],[-2,4]]
（答案 [[-2,4],[3,3]] 也会被接受。）
 

提示：

1 <= K <= points.length <= 10000
-10000 < points[i][0] < 10000
-10000 < points[i][1] < 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-closest-points-to-origin
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <map>
#include "../check/CheckResult.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        multimap<int, vector<int>> sortedPoints;
        vector<vector<int>> closestPoints;

        for (vector<int>& point : points) {
            sortedPoints.insert({ point[0] * point[0] + point[1] * point[1], point });
            if ((int)sortedPoints.size() > K) {
                sortedPoints.erase(--sortedPoints.end());
            }
        }

        for (auto iter = sortedPoints.begin(); iter != sortedPoints.end(); ++iter) {
            closestPoints.push_back(iter->second);
        }

        return closestPoints;
    }
};

int main()
{
    CheckResult check;
    Solution o;

    vector<vector<int>> points = { {1,3},{-2,2} };
    vector<vector<int>> actual = o.kClosest(points, 1);
    vector<vector<int>> expected = { {-2,2} };
    check.checkIntVectorVector(expected, actual);

    points = { {3,3},{5,-1},{-2,4} };
    actual = o.kClosest(points, 2);
    expected = { {3,3},{-2,4} };
    check.checkIntVectorVector(expected, actual);

    points = { {0,1},{1,0} };
    actual = o.kClosest(points, 2);
    expected = { {0,1},{1,0} };
    check.checkIntVectorVector(expected, actual);
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
